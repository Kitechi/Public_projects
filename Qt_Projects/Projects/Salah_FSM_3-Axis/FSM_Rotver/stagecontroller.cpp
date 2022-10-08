#include "stagecontroller.h"


stageController::stageController(structSetting *settingInfoPtrArg, QObject *parent) : QObject(parent)
{
    settingInfoPtr  = settingInfoPtrArg;
    vstageProc      = new vstageController();
    hstageProc      = new hstageController();
    rotStageProc    = new rotStageController((structSetting *)&settingInfoPtrArg);
    scannerObj      = NULL;
    scannerThread   = NULL;

    //scan();
    //t1.waitForFinished();
}

stageController::~stageController()
{

}

void stageController::startScan()
{
        scannerObj = new scanner(this->hstageProc,this->vstageProc,this->rotStageProc, this->settingInfoPtr);
        scannerThread = new QThread;
        scannerObj->moveToThread(scannerThread);

        //connect(scannerObj, SIGNAL(errorSignal(QString)), this, SLOT(errorHandler(QString)));
        connect(scannerObj, SIGNAL(atNewPoint(uint)), this, SLOT(atNewPt_slot(uint)));
        connect(scannerObj, SIGNAL(finished(uint)), this, SLOT(scanFinished(uint)));

        connect(scannerObj, SIGNAL(finished(uint)), scannerThread, SLOT(quit()));
        connect(scannerObj, SIGNAL(finished(uint)), scannerObj, SLOT(deleteLater()));
        connect(scannerThread, SIGNAL(finished()), scannerThread, SLOT(deleteLater()));

        if(settingInfoPtr->Materialshape == "Rectangular")
        {
            connect(scannerThread, SIGNAL(started()), scannerObj, SLOT(scan()));

        }
        else if (settingInfoPtr->Materialshape == "Circular_Horizontal")
        {
            connect(scannerThread, SIGNAL(started()), scannerObj, SLOT(RHscan()));
        }
        else if (settingInfoPtr->Materialshape == "Circular_Vertical")
        {
            connect(scannerThread, SIGNAL(started()), scannerObj, SLOT(RVscan()));
        }
        else if (settingInfoPtr->Materialshape == "Leading Edge Specimen")
        {
            connect(scannerThread, SIGNAL(started()), scannerObj, SLOT(LESscan()));
        }
        else if (settingInfoPtr->Materialshape == "Zero Incident Angle")
        {
            connect(scannerThread, SIGNAL(started()), scannerObj, SLOT(Zeroscan()));
        };

        scannerThread->start();
}
void stageController::stopScan()
{
    if(this->scannerObj!=NULL)
        this->scannerObj->setStopScan();
}

//slots connected to signals of the scanner thread
void stageController::atNewPt_slot(uint pt)
{
    emit this->atNewPointInScan(pt,true);
}

void stageController::setMeasDone_slot()
{
    scannerObj->setMeasDone();
}

void stageController::scanFinished(uint pt)
{
    this->scannerObj=NULL;
    emit scanFinished();
}

scanner::scanner(hstageController *hstageProcArg,  vstageController *vstageProcArg,rotStageController *rotStageProcArg,  structSetting *settingInfoPtrArg)
{
    hstageProc      = hstageProcArg;
    vstageProc      = vstageProcArg;
    rotStageProc    = rotStageProcArg;
    settingInfoPt       = settingInfoPtrArg;
    stopScan            = false;
    currScanPt          = 0;
}

scanner::~scanner()
{

}

void scanner::setStopScan()
{
    stopScan = true;
}

void scanner::setMeasDone()
{
    this->measDone = true;
}

void scanner::scan()
{
    int i;
    currScanPt = 0;
    //store the current position and move back to the that position at the end of the scan.
    float vstagePos,hstagePos,vstageTargetPos,hstageTargetPos;
    bool vStageSuccess = true;
    bool hStageSuccess = true;

   while((vstagePos = vstageProc->getPos())< 0)
        QThread::msleep(500);

    hstagePos = hstageProc->getPos();

    vstageTargetPos   = vstagePos;
    hstageTargetPos   = hstagePos;


    qDebug()<<hstagePos<<vstagePos;



    while (currScanPt < settingInfoPt->ScanPoints &&
           stopScan == false &&
           hStageSuccess &&
           vStageSuccess )
    {
        //record signal
        qDebug()<<"Current Point" <<currScanPt;
        vstageProc->getPos();
        hstageProc->getPos();

        measDone = false;
        emit atNewPoint(currScanPt);

        //wait
        while(!measDone);
        //stage movment
        vStageSuccess = true;
        hStageSuccess = true;
        if (((currScanPt+1)%(settingInfoPt->xLength)) == 0)
        {
            //Salah
            vstageTargetPos -= settingInfoPt->scanInterval;
            vStageSuccess = vstageProc->setPosAbs(vstageTargetPos);
        }
        else
        {
            //horizontal
            if ((currScanPt/(settingInfoPt->xLength))%2 == 0 ) // even row
            {
                hstageTargetPos -= settingInfoPt->scanInterval;
                hStageSuccess = hstageProc->setPosAbs(hstageTargetPos);
            }
            else //if ((ptsDone/settingInfoPt->xLength)%2 == 1 ) // oddrow
            {
                hstageTargetPos += settingInfoPt->scanInterval;
                hStageSuccess = hstageProc->setPosAbs(hstageTargetPos);
            }
        }

        //stage movement finish wait
        //the acknowledgment of move finish should be done in the controller.
        //for now just waiting an aprox time.
        //QThread::msleep(300);

        currScanPt++;
    }


    vstageProc->setPosAbs(vstagePos);
    hstageProc->setPosAbs(hstagePos);

    emit finished(i);
}
void scanner::RHscan()
{
    int i;
    currScanPt = 0;
    //store the current position and move back to the that position at the end of the scan.
    float hstagePos,rotstagePos,hstageTargetPos,rotstageTargetPos;
    bool hStageSuccess = true;
    bool rotStageSuccess = true;

//    while((rotstagePos = rotStageProc->getPos()) == 99.125)
//        QThread::msleep(500);

    hstagePos = hstageProc->getPos();
    rotstagePos = rotStageProc->getPos();

    hstageTargetPos   = hstagePos;
    rotstageTargetPos = rotstagePos;

    qDebug()<<hstagePos<<rotstagePos;

    while (currScanPt < settingInfoPt->ScanPoints &&
               stopScan == false &&
               hStageSuccess &&
                rotStageSuccess)
    {
        //record signal
        qDebug()<<"Current Point" <<currScanPt;
        hstageProc->getPos();
        rotStageProc->getPos();
        measDone = false;
        emit atNewPoint(currScanPt);


        while(!measDone); //wait

        //stage movment
        //rotational
        hStageSuccess = true;
        rotStageSuccess = true;
        if (((currScanPt+1)%(settingInfoPt->xLength)) == 0)
        {
            rotstageTargetPos += settingInfoPt->DegreeInterval;
            rotStageSuccess = rotStageProc->setPosAbs(rotstageTargetPos);
        }
        else
        {
            //horizontal
            if ((currScanPt/(settingInfoPt->xLength))%2 == 0 ) // even row
            {
                hstageTargetPos -= settingInfoPt->scanInterval;
                hStageSuccess = hstageProc->setPosAbs(hstageTargetPos);
            }
            else //if ((ptsDone/settingInfoPt->xLength)%2 == 1 ) // oddrow
            {
                hstageTargetPos += settingInfoPt->scanInterval;
                hStageSuccess = hstageProc->setPosAbs(hstageTargetPos);
            }
        }

        //stage movement finish wait
        //the acknowledgment of move finish should be done in the controller.
        //for now just waiting an aprox time.
        //QThread::msleep(300);

        currScanPt++;
    }

    rotStageProc->home();
    hstageProc->setPosAbs(hstagePos);


    emit finished(i);
}
void scanner::RVscan()
{
    int i;
    currScanPt = 0;
    //store the current position and move bac to the that position at the end of the scan.
    float vstagePos,rotstagePos,vstageTargetPos, rotstageTargetPos;
    bool vStageSuccess = true;
    bool rotStageSuccess = true;
    while((vstagePos = vstageProc->getPos())< 0)
        //QThread::msleep(500);

    vstagePos = vstageProc->getPos();
    rotstagePos = rotStageProc->getPos();
    vstageTargetPos = vstagePos;
    rotstageTargetPos = rotstagePos;

    qDebug()<<rotstagePos<<vstagePos;


    while (currScanPt < settingInfoPt->ScanPoints &&
           stopScan == false &&
           rotStageSuccess &&
           vStageSuccess)
    {
        //record signal
        qDebug()<<"Current Point" <<currScanPt;
        vstageProc->getPos();
        rotStageProc->getPos();
        measDone = false;
        emit atNewPoint(currScanPt);
        while(!measDone); //wait
        //stage movment
        vStageSuccess = true;
        rotStageSuccess = true;
        if (((currScanPt+1)%(settingInfoPt->xLength)) == 0)
        {
            vstageTargetPos -= settingInfoPt->scanInterval;
            vStageSuccess = vstageProc->setPosAbs(vstageTargetPos);
        }
        else
        {
            //Vertical
            if ((currScanPt/(settingInfoPt->xLength))%2 == 0 ) // even row
            {
                rotstageTargetPos += settingInfoPt->DegreeInterval;
                rotStageSuccess = rotStageProc->setPosAbs(rotstageTargetPos);
            }
            else //if ((ptsDone/settingInfoPt->xLength)%2 == 1 ) // oddrow
            {
                rotstageTargetPos -= settingInfoPt->DegreeInterval;
                rotStageSuccess = rotStageProc->setPosAbs(rotstageTargetPos);
            }
        }

        //stage movement finish wait
        //the acknowledgment of move finish should be done in the controller.
        //for now just waiting an aprox time.
        //QThread::msleep(300);

        currScanPt++;
    }
    rotStageProc->setPosAbs(rotstagePos);
    vstageProc->setPosAbs(vstagePos);
    emit finished(i);
}
void scanner::LESscan()
{
    int i;
    currScanPt = 0;
    //store the current position and move bac to the that position at the end of the scan.
    float vstagePos,hstagePos,rotstagePos,vstageTargetPos,hstageTargetPos, rotstageTargetPos;
    bool vStageSuccess = true;
    bool hStageSuccess = true;
    bool rotStageSuccess = true;
    int Xpoint = 0, Zpoint = 0;
    while((vstagePos = vstageProc->getPos())< 0)
        QThread::msleep(500);

    vstagePos = vstageProc->getPos();
    hstagePos = hstageProc->getPos();
    rotstagePos = rotStageProc->getPos();

    vstageTargetPos = vstagePos;
    hstageTargetPos = hstagePos;
    rotstageTargetPos = rotstagePos;

    qDebug()<<rotstagePos<<vstagePos<<hstagePos;

    while (currScanPt < settingInfoPt->ScanPoints &&
           stopScan == false &&
           rotStageSuccess &&
           vStageSuccess && hStageSuccess)
    {
        //record signal
        qDebug()<<"Current Point" <<currScanPt;
        vstageProc->getPos();
        hstageProc->getPos();
        rotStageProc->getPos();
        measDone = false;
        emit atNewPoint(currScanPt);
        while(!measDone);        //wait

        //stage movment
        vStageSuccess = true;
        hStageSuccess = true;
        rotStageSuccess = true;

        if (((currScanPt+1)%(settingInfoPt->xLength)) == 0)
        {
            qDebug()<<"Current X Point" <<Xpoint;
            vstageTargetPos -= settingInfoPt->scanInterval;
            vStageSuccess = vstageProc->setPosAbs(vstageTargetPos);
            if (settingInfoPt->ZPoints==1)
                Zpoint = 0;
            else
                Zpoint++;

        }
        else
        {
            //Rotational & Horizontal Stages
            if (((currScanPt)/(settingInfoPt->xLength))%2 == 0 ) // even row
            {
                Xpoint++;
                if(Xpoint==settingInfoPt->xLength)
                {
                    if(settingInfoPt->LinearIntervalV[Zpoint][Xpoint]==0)
                    {

                        rotstageTargetPos += settingInfoPt->DegreeIntervalV[Zpoint][0];
                        rotStageSuccess = rotStageProc->setPosAbs(rotstageTargetPos);
                        //Xpoint++;
                    }
                    else
                    {

                        hstageTargetPos -= settingInfoPt->LinearIntervalV[Zpoint][0];
                        hStageSuccess = hstageProc->setPosAbs(hstageTargetPos);
                        //Xpoint++;
                    }
                }
                else
                {
                    if(settingInfoPt->LinearIntervalV[Zpoint][Xpoint]==0)
                    {
                        //Xpoint++;
                        rotstageTargetPos += settingInfoPt->DegreeIntervalV[Zpoint][Xpoint];
                        rotStageSuccess = rotStageProc->setPosAbs(rotstageTargetPos);

                    }
                    else
                    {
                        //Xpoint++;
                        hstageTargetPos -= settingInfoPt->LinearIntervalV[Zpoint][Xpoint];
                        hStageSuccess = hstageProc->setPosAbs(hstageTargetPos);

                    }
                }

            }
            else  // oddrow
            {
                if(settingInfoPt->LinearIntervalV[Zpoint][Xpoint]==0)
                {

                    rotstageTargetPos -= settingInfoPt->DegreeIntervalV[Zpoint][Xpoint];
                    rotStageSuccess = rotStageProc->setPosAbs(rotstageTargetPos);
                    Xpoint--;
                }
                else
                {
                    //Xpoint--;
                    hstageTargetPos += settingInfoPt->LinearIntervalV[Zpoint][Xpoint];
                    hStageSuccess = hstageProc->setPosAbs(hstageTargetPos);
                    Xpoint--;
                }
            }
        }

        //stage movement finish wait
        //the acknowledgment of move finish should be done in the controller.
        //for now just waiting an aprox time.
        //QThread::msleep(300);

        currScanPt++;
    }

    rotStageProc->setPosAbs(rotstagePos);
    vstageProc->setPosAbs(vstagePos);
    hstageProc->setPosAbs(hstagePos);
    emit finished(i);
}

void scanner::Zeroscan()
{
    int i;
    currScanPt = 0;
    //store the current position and move bac to the that position at the end of the scan.
    float vstagePos,hstagePos,rotstagePos,vstageTargetPos,hstageTargetPos, rotstageTargetPos;
    bool vStageSuccess = true;
    bool hStageSuccess = true;
    bool rotStageSuccess = true;
    int Xpoint = 0, Zpoint = 0;
    while((vstagePos = vstageProc->getPos())< 0)
        QThread::msleep(500);

    vstagePos = vstageProc->getPos();
    hstagePos = hstageProc->getPos();
    rotstagePos = rotStageProc->getPos();

    vstageTargetPos = vstagePos;
    hstageTargetPos = hstagePos;
    rotstageTargetPos = rotstagePos;

    qDebug()<<rotstagePos<<vstagePos<<hstagePos;

    rotstageTargetPos += settingInfoPt->DegreeIntervalV[Zpoint][Xpoint];
    rotStageSuccess = rotStageProc->setPosAbs(rotstageTargetPos);
    hstageTargetPos += settingInfoPt->LinearIntervalV[Zpoint][Xpoint];
    hStageSuccess = hstageProc->setPosAbs(hstageTargetPos);

    while (currScanPt < settingInfoPt->ScanPoints &&
           stopScan == false &&
           rotStageSuccess &&
           vStageSuccess && hStageSuccess)
    {
        //record signal
        qDebug()<<"Current Point" <<currScanPt;
        vstageProc->getPos();
        hstageProc->getPos();
        rotStageProc->getPos();

        measDone = false;
        emit atNewPoint(currScanPt);
        while(!measDone);        //wait

        //stage movment
        vStageSuccess = true;
        hStageSuccess = true;
        rotStageSuccess = true;




        if (((currScanPt+1)%(settingInfoPt->xLength)) == 0)
        {
            qDebug()<<"Current X Point" <<Xpoint;
            settingInfoPt->LinearIntervalV[0][0]=settingInfoPt->InitialStep;
            vstageTargetPos -= settingInfoPt->scanInterval;
            vStageSuccess = vstageProc->setPosAbs(vstageTargetPos);
            if (settingInfoPt->ZPoints==1)
                Zpoint = 0;
            else
                Zpoint++;

        }
        else
        {
            //Rotational & Horizontal Stages
            if (((currScanPt)/(settingInfoPt->xLength))%2 == 0 ) // even row
            {
                Xpoint++;
                rotstageTargetPos += settingInfoPt->DegreeIntervalV[Zpoint][Xpoint];
                rotStageSuccess = rotStageProc->setPosAbs(rotstageTargetPos);
                hstageTargetPos += settingInfoPt->LinearIntervalV[Zpoint][Xpoint];
                hStageSuccess = hstageProc->setPosAbs(hstageTargetPos);
            }
            else  // oddrow
            {
                rotstageTargetPos -= settingInfoPt->DegreeIntervalV[Zpoint][Xpoint];
                rotStageSuccess = rotStageProc->setPosAbs(rotstageTargetPos);
                hstageTargetPos -= settingInfoPt->LinearIntervalV[Zpoint][Xpoint];
                hStageSuccess = hstageProc->setPosAbs(hstageTargetPos);
                Xpoint--;

            }
        }

        //stage movement finish wait
        //the acknowledgment of move finish should be done in the controller.
        //for now just waiting an aprox time.
        //QThread::msleep(300);

        currScanPt++;
    }

    rotStageProc->setPosAbs(rotstagePos);
    vstageProc->setPosAbs(vstagePos);
    hstageProc->setPosAbs(hstagePos);
    emit finished(i);
}
