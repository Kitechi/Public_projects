#include "stagecontroller.h"

stageController::stageController(structSetting *settingInfoPtrArg, QObject *parent) : QObject(parent)
{
    settingInfoPtr  = settingInfoPtrArg;
    vstageProc      = new vstageController();
    hstageProc      = new hstageController();
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
    scannerObj = new scanner(this->hstageProc,this->vstageProc,this->settingInfoPtr);
    scannerThread = new QThread;
    scannerObj->moveToThread(scannerThread);

    //connect(scannerObj, SIGNAL(errorSignal(QString)), this, SLOT(errorHandler(QString)));
    connect(scannerObj, SIGNAL(atNewPoint(uint)), this, SLOT(atNewPt_slot(uint)));
    connect(scannerObj, SIGNAL(finished(uint)), this, SLOT(scanFinished(uint)));

    connect(scannerObj, SIGNAL(finished(uint)), scannerThread, SLOT(quit()));
    connect(scannerObj, SIGNAL(finished(uint)), scannerObj, SLOT(deleteLater()));
    connect(scannerThread, SIGNAL(finished()), scannerThread, SLOT(deleteLater()));

    connect(scannerThread, SIGNAL(started()), scannerObj, SLOT(scan()));

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

scanner::scanner(hstageController *hstageProcArg, vstageController *vstageProcArg, structSetting *settingInfoPtrArg)
{
    hstageProc      = hstageProcArg;
    vstageProc      = vstageProcArg;

    //hstageProc      = new hstageController();
    //vstageProc      = new vstageController();

    settingInfoPt       = settingInfoPtrArg ;
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
    //store the current position and move bac to the that position at the end of the scan.
    float vstagePos,hstagePos,vstageTargetPos,hstageTargetPos;
    bool vStageSuccess = true;
    bool hStageSuccess = true;
    while((vstagePos = vstageProc->getPos())< 0)
        QThread::msleep(500);

    hstagePos = hstageProc->getPos();

    vstageTargetPos = vstagePos;
    hstageTargetPos = hstagePos;

    qDebug()<<hstagePos<<vstagePos;

    while (currScanPt < settingInfoPt->ScanPoints &&
           stopScan == false &&
           hStageSuccess &&
           vStageSuccess)
    {
        //record signal
        qDebug()<<"Current Point" <<currScanPt;
        vstageProc->getPos();
        hstageProc->getPos();
        measDone = false;
        emit atNewPoint(currScanPt);

        //wait
        while(!measDone);
        //QThread::msleep(3000);
        //QThread::msleep(50);

        //stage movment
        //verticle
        vStageSuccess = true;
        hStageSuccess = true;
        if (((currScanPt+1)%settingInfoPt->xLength) == 0)
        {
            //vstageProc->setPosRel(settingInfoPt->scanInterval);
            //vstageTargetPos += settingInfoPt->scanInterval;
            vstageTargetPos -= settingInfoPt->scanInterval;
            vStageSuccess = vstageProc->setPosAbs(vstageTargetPos);
        }
        else
        {
            //horizontal
            if ((currScanPt/settingInfoPt->xLength)%2 == 0 ) // even row
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

void scanner::RVscan()
{
    int i;
    currScanPt = 0;
    //store the current position and move bac to the that position at the end of the scan.
    float vstagePos,rotstagePos,vstageTargetPos,rotstageTargetPos;
    bool vStageSuccess = true;
    bool rotStageSuccess = true;
    while((vstagePos = vstageProc->getPos())< 0)
        QThread::msleep(500);

    vstagePos = vstageProc->getPos();

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

        //wait
        while(!measDone);
        //QThread::msleep(3000);
        //QThread::msleep(50);

        //stage movment
        //verticle
        vStageSuccess = true;
        rotStageSuccess = true;
        if (((currScanPt+1)%settingInfoPt->xLength) == 0)
        {

            rotstageTargetPos += settingInfoPt->DegreeInterval;
            rotStageSuccess = rotStageProc->setPosAbs(rotstageTargetPos);
        }
        else
        {
            //horizontal
            if ((currScanPt/settingInfoPt->xLength)%2 == 0 ) // even row
            {
                vstageTargetPos += settingInfoPt->scanInterval;
                vStageSuccess = vstageProc->setPosAbs(vstageTargetPos);
            }
            else //if ((ptsDone/settingInfoPt->xLength)%2 == 1 ) // oddrow
            {
                vstageTargetPos -= settingInfoPt->scanInterval;
                vStageSuccess = vstageProc->setPosAbs(vstageTargetPos);
            }
        }

        //stage movement finish wait
        //the acknowledgment of move finish should be done in the controller.
        //for now just waiting an aprox time.
        //QThread::msleep(300);

        currScanPt++;
    }

    vstageProc->setPosAbs(vstagePos);
    rotStageProc->setPosAbs(rotstagePos);

    emit finished(i);
}
