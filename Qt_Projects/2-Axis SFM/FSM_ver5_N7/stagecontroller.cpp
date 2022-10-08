#include "stagecontroller.h"

//#define DEBUGLOGS_STAGE
#define HOSTPORT        32769//9000//
const QString HOSTIP = "192.168.1.5";

stageController::stageController(structSetting *settingInfoPtrArg)
{
    updateTimer = new QTimer(this);
    unsigned int returnVal;
    if (readPlcMem32(302,&returnVal) != false) // so PLC is working so lets start the update timer
    {
        //updateTimer->start(500);
    }

    scanStartPosX = 0.0;
    scanStartPosZ = 0.0;
    settingInfoPtr = settingInfoPtrArg;

    writePlcMem32(226,5000); //X-axis Jog speed
    writePlcMem32(228,5000); //Z-axis Jog speed

    writePlcMem32(254,20000); //acc distance
}

stageController::~stageController()
{
    delete updateTimer;
}

bool stageController::writePlcMem(short address, unsigned short value)
{
    QByteArray cmd;
    QByteArray rsp("No Response");
    QString addStrStart = "00"+QString::number(address);
    QString addStrEnd = "00"+QString::number(address);
    unsigned short valueBigEndian = qToBigEndian(value);
    QString hexValue = (QString("%1").arg(valueBigEndian,4,16,QLatin1Char('0'))).toUpper();
    QString cmdStr = "%01#WDD"+addStrStart+addStrEnd+hexValue+"**\r";
    cmd = cmdStr.toLocal8Bit();
    bool writeSuccess = false;
    QTcpSocket tcpSocket;


    //if (tcpSocket.isOpen()==false || tcpSocket.isValid() ==false)
        tcpSocket.connectToHost(HOSTIP, HOSTPORT);
    tcpSocket.write(cmd);

    tcpSocket.waitForReadyRead(500);
    rsp = tcpSocket.readAll();

    if (rsp.size()>0)
    {
        if (rsp.at(3)=='$')
            writeSuccess = true;
    }

    #ifdef DEBUGLOGS_STAGE
        qDebug()<<"writePlcMem cmdStr: "<<cmdStr<<"  rsp:"<<rsp<<"writeSuccess"<<writeSuccess;
    #endif

    return writeSuccess;
}

bool stageController::writePlcMem32(short address, unsigned int intValue)
{
    QByteArray cmd;
    QByteArray rsp("No Response");
    QString addStrStart = "00"+QString::number(address);
    QString addStrEnd = "00"+QString::number(address+1);
    unsigned short valueL = (intValue)&0xffff;
    unsigned short valueH = (intValue>>16)&0xffff;
    unsigned short valueLBigEndian = qToBigEndian(valueL);
    unsigned short valueHBigEndian = qToBigEndian(valueH);

    QString hexValueL = (QString("%1").arg(valueLBigEndian,4,16,QLatin1Char('0'))).toUpper();
    QString hexValueH = (QString("%1").arg(valueHBigEndian,4,16,QLatin1Char('0'))).toUpper();;


    QString cmdStr = "%01#WDD"+addStrStart+addStrEnd+hexValueL+hexValueH+"**\r";

    cmd = cmdStr.toLocal8Bit();
    bool writeSuccess = false;
    QTcpSocket tcpSocket;

    //if (tcpSocket.isOpen()==false || tcpSocket.isValid() ==false || tcpSocket.isWritable() == false)
        tcpSocket.connectToHost(HOSTIP, HOSTPORT);
    tcpSocket.write(cmd);

    tcpSocket.waitForReadyRead(500);

    rsp = tcpSocket.readAll();
    if (rsp.size()>0)
    {
        if (rsp.at(3)=='$')
            writeSuccess = true;
    }

#ifdef DEBUGLOGS_STAGE
    qDebug()<<"writePlcMem32 cmdStr: "<<cmdStr<<"  rsp:"<<rsp<<"writeSuccess"<<writeSuccess;
#endif

    return writeSuccess;
}

bool stageController::readPlcMem(short address,unsigned short * returnVal)
{
    QByteArray cmd;
    QByteArray rsp("No Response");
    QString addStrStart = "00"+QString::number(address);
    QString addStrEnd = "00"+QString::number(address);
    QString cmdStr = "%01#RDD"+addStrStart+addStrEnd+"**\r";
    cmd = cmdStr.toLocal8Bit();
    bool writeSuccess = false;
    unsigned short returnValBig=0;
    QTcpSocket tcpSocket;

    //if (tcpSocket.isOpen()==false || tcpSocket.isValid() ==false || tcpSocket.isWritable() == false)
        tcpSocket.connectToHost(HOSTIP, HOSTPORT);
    tcpSocket.write(cmd);

    tcpSocket.waitForReadyRead(500);

    rsp = tcpSocket.readAll();
    if (rsp.size()>0)
    {
        if (rsp.at(3)=='$')
        {
            writeSuccess = true;
            returnValBig = rsp.mid(6,4).toUShort(0,16);
            *returnVal = qFromBigEndian(returnValBig);
        }
    }
#ifdef DEBUGLOGS_STAGE
    qDebug()<<"readPlcMem cmdStr: "<<cmdStr<<"  rsp:"<<rsp<<"writeSuccess"<<writeSuccess<<"ReturnVal"<<*returnVal;
#endif
    return writeSuccess;
}

bool stageController::readPlcMem32(short address, unsigned int * returnVal)
{
    QByteArray cmd;
    QByteArray rsp("No Response");
    QString addStrStart = "00"+QString::number(address);
    QString addStrEnd = "00"+QString::number(address+1);

    QString cmdStr = "%01#RDD"+addStrStart+addStrEnd+"**\r";
    cmd = cmdStr.toLocal8Bit();
    bool writeSuccess = false;
    unsigned short returnValBigshortL=0,returnValshortL=0;
    unsigned short returnValBigshortH=0,returnValshortH=0;
    QString returnValBigshortLstring,returnValBigshortHstring;
    QTcpSocket tcpSocket;

    //if (tcpSocket.isOpen()==false || tcpSocket.isValid() ==false || tcpSocket.isWritable() == false)
        tcpSocket.connectToHost(HOSTIP, HOSTPORT);
    tcpSocket.write(cmd);

    tcpSocket.waitForReadyRead(500);

    rsp = tcpSocket.readAll();
    if (rsp.size()>0)
    {
        if (rsp.at(3)=='$')
        {
            writeSuccess = true;

            returnValBigshortL = rsp.mid(6,4).toUShort(0,16);
            returnValBigshortH = rsp.mid(10,4).toUShort(0,16);

            returnValshortL = qFromBigEndian(returnValBigshortL);
            returnValshortH = qFromBigEndian(returnValBigshortH);

            *returnVal = returnValshortL | (returnValshortH<<16);
        }
    }
#ifdef DEBUGLOGS_STAGE
    qDebug()<<"readPlcMem32 cmdStr: "<<cmdStr<<"  rsp:"<<rsp<<"writeSuccess"<<writeSuccess<<"ReturnVal"<<*returnVal;
#endif
    return writeSuccess;
}

void stageController::setErrorReset(void)
{
    writePlcMem(215,true); //x-origin
    QTimer::singleShot( 1000, this, SLOT(clearErrorReset() ));
}

void stageController::clearErrorReset(void)
{
    writePlcMem(215,false); //x-origin
}

void stageController::setServoStop(void)
{
    writePlcMem(216,true); //servo-stop
    QTimer::singleShot( 100, this, SLOT(clearServoStop() ));
}

void stageController::clearServoStop(void)
{
    writePlcMem(216,false); //servo-stop
}

void stageController::originSet(void)
{
    writePlcMem(221,true); //x-origin
    writePlcMem(222,true); //z-origin

    QTimer::singleShot( 1000, this, SLOT(originReset() ));
}

void stageController::originReset(void)
{
    writePlcMem(221,false); //x-origin
    writePlcMem(222,false); //z-origin
}

void stageController::updatePos()
{
    getPosX();
    getPosZ();
}

void stageController::JogzpStop()
{
    Jogzp(false);
}

void stageController::JogznStop()
{
    Jogzn(false);
}
void stageController::JogxpStop()
{
    Jogxp(false);
}

void stageController::JogxnStop()
{
    Jogxn(false);
}

void stageController::JogzpStart()
{
    Jogzp(true);
}

void stageController::JogznStart()
{
    Jogzn(true);
}
void stageController::JogxpStart()
{
    Jogxp(true);
}

void stageController::JogxnStart()
{
    Jogxn(true);
}

void stageController::Jogxp(bool enableJog)
{
    setErrorReset();
    if (writePlcMem(217,enableJog) == true && updateTimer->isActive()==false)
        updateTimer->start(500);
/*
    if (enableJog)
        updateTimer->start(100);
    else
    {
        updatePos();
        updateTimer->stop();
    }
*/
}

void stageController::Jogxn(bool enableJog)
{
    setErrorReset();
    if (writePlcMem(218,enableJog) == true && updateTimer->isActive()==false)
    updateTimer->start(500);

/*
    if (enableJog)
        updateTimer->start(100);
    else
    {
        updatePos();
        updateTimer->stop();
    }
    */
}

void stageController::Jogzp(bool enableJog)
{
    setErrorReset();
    if (writePlcMem(219,enableJog) == true && updateTimer->isActive()==false)
    updateTimer->start(500);
/*
    if (enableJog)
        updateTimer->start(100);
    else
    {
        updatePos();
        updateTimer->stop();
    }
*/
}

void stageController::Jogzn(bool enableJog)
{
    setErrorReset();
    if (writePlcMem(220,enableJog) == true && updateTimer->isActive()==false)
    updateTimer->start(500);
/*
    if (enableJog)
        updateTimer->start(100);
    else
    {
        updatePos();
        updateTimer->stop();
    }
*/
}

void stageController::setPosZ(unsigned int pos,bool relToScanStart)
{
    if (relToScanStart && this->scanStartPosZ > 0 )
        pos = pos + this->scanStartPosZ;
    writePlcMem32(230,pos);
    setMovetoZ();
}

void stageController::setMovetoZ()
{
    setErrorReset();
    writePlcMem(234,true);
    QTimer::singleShot( 1000, this, SLOT(resetMovetoZ() ));
}

void stageController::resetMovetoZ()
{
    writePlcMem(234,false);
}

void stageController::setPosX(unsigned int pos, bool relToScanStart)
{
    if (relToScanStart && this->scanStartPosX > 0 )
        pos = pos + this->scanStartPosX;

    writePlcMem32(232,pos);
    setMovetoX();
}

void stageController::setMovetoX()
{
    setErrorReset();
    writePlcMem(235,true);
    QTimer::singleShot( 1000, this, SLOT(resetMovetoX() ));
}

void stageController::resetMovetoX()
{
    writePlcMem(235,false);
}

bool stageController::MoveAbsPosZ(unsigned int pos)
{

    bool successWrite = false;
    if (writePlcMem32(230,pos) )
    {
        setErrorReset();
        successWrite = writePlcMem(234,true);
    }
    if (successWrite)
    {
        successWrite = writePlcMem(234,false);
    }
    return successWrite;
}

bool stageController::MoveAbsPosX(unsigned int pos)
{
    QCoreApplication::processEvents();
    bool successWrite = false;
    if (writePlcMem32(232,pos) )
    {
        setErrorReset();
        successWrite = writePlcMem(235,true);
    }
    if (successWrite)
    {
        successWrite = writePlcMem(235,false);
    }
    return successWrite;
}

unsigned int stageController::getPosZ()
{
    unsigned int returnVal;
    double returnValdouble;
    QString returnValString;

    if (readPlcMem32(302,&returnVal) == false)
        returnVal = 0;

    returnValdouble = (double)returnVal/1000;
    returnValdouble = round(returnValdouble*100)/100;
    returnValString = QString::number(returnValdouble,'f',2);

    //returnValString = QString::number(123.5,'f',2);

    emit Zpos(returnValString);
    return (returnVal);
}

unsigned int stageController::getPosX()
{
    unsigned int returnVal;
    double returnValdouble;
    QString returnValString;

    if (readPlcMem32(304,&returnVal) == false)
        returnVal = 0;

    returnValdouble = (double)returnVal/1000;
    returnValdouble = round(returnValdouble*100)/100;

    returnValString = QString::number(returnValdouble,'f',2);
    emit Xpos(returnValString);
    return (returnVal);
}

//*********************************Scaning Start********************************************//
setupController::setupController(structSetting *settingInfoPtrArg, QObject *parent) : QObject(parent)
{
    settingInfoPtr  = settingInfoPtrArg;
    scannerObj      = NULL;
    scannerThread   = NULL;

    //scan();
    //t1.waitForFinished();
}

setupController::~setupController()
{

}

void setupController::startScan()
{
    scannerObj = new scanner(this->settingInfoPtr);
    scannerThread = new QThread;
    scannerObj->moveToThread(scannerThread);

    //connect(scannerObj, SIGNAL(errorSignal(QString)), this, SLOT(errorHandler(QString)));
    connect(scannerObj, SIGNAL(atNewPoint(uint)), this, SLOT(atNewPt_slot(uint))); //for measurening new point

    connect(scannerObj, SIGNAL(finished(uint)), this, SLOT(scanFinished(uint))); //scan finished now show pna app
    connect(scannerObj, SIGNAL(finished(uint)), scannerThread, SLOT(quit()));
    connect(scannerObj, SIGNAL(finished(uint)), scannerObj, SLOT(deleteLater()));

    connect(scannerThread, SIGNAL(finished()), scannerThread, SLOT(deleteLater()));

    connect(scannerThread, SIGNAL(started()), scannerObj, SLOT(scan()));

    scannerThread->start();
}

void setupController::stopScan()
{
    if(this->scannerObj!=NULL)
        this->scannerObj->setStopScan();
}

//slots connected to signals of the scanner thread
void setupController::atNewPt_slot(uint pt)
{
    emit this->atNewPointInScan(pt,true);
}

void setupController::setMeasDone_slot()
{
    scannerObj->setMeasDone();
}

void setupController::scanFinished(uint pt)
{
    this->scannerObj=NULL;
    emit scanFinished();
}


//************************Scanner functions*******************************************************//

scanner::scanner( structSetting *settingInfoPtrArg)
{
    settingInfoPt       = settingInfoPtrArg ;
    stopScan            = false;
    currScanPt          = 0;
    stageProc           = NULL;
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
    double vstageTargetPos,hstageTargetPos;
    bool vStageSuccess = true;
    bool hStageSuccess = true;

    stageProc = new stageController (this->settingInfoPt);
    stageProc->scanStartPosX = stageProc->getPosX();
    stageProc->scanStartPosZ = stageProc->getPosZ();

    vstageTargetPos = 0;
    hstageTargetPos = 0;

    qDebug()<<stageProc->scanStartPosX<<stageProc->scanStartPosZ;

    while (currScanPt < settingInfoPt->ScanPoints && stopScan == false && hStageSuccess && vStageSuccess)
    {
        //record signal
        qDebug()<<"Current Point" <<currScanPt;
        stageProc->getPosX();
        stageProc->getPosZ();

        measDone = false;
        Sleep(500);
        emit atNewPoint(currScanPt);
        while(!measDone)
        {
            QCoreApplication::processEvents();
        }

        //stage movment        
        vStageSuccess = true;
        hStageSuccess = true;
        //verticle Stage Movement
        if (((currScanPt+1)%settingInfoPt->xLength) == 0)
        {
            vstageTargetPos += (settingInfoPt->scanInterval*1000);
            stageProc->setPosZ(vstageTargetPos,true);
            QCoreApplication::processEvents();

        }
        //horizontal Stage Movement
        else
        {
            if ((currScanPt/settingInfoPt->xLength)%2 == 0 ) // even row
            {
                hstageTargetPos -= (settingInfoPt->scanInterval*1000);
//                hStageSuccess = stageProc->MoveAbsPosX(hstageTargetPos);
                stageProc->setPosX(hstageTargetPos,true);
                QCoreApplication::processEvents();

            }
            else //if ((ptsDone/settingInfoPt->xLength)%2 == 1 ) // oddrow
            {
                hstageTargetPos += (settingInfoPt->scanInterval*1000);
//                hStageSuccess = stageProc->MoveAbsPosX(hstageTargetPos);
                stageProc->setPosX(hstageTargetPos,true);
                QCoreApplication::processEvents();

            }
        }
        //stage movement finish wait
        currScanPt++;
    }

    //Move stages to initial position of scan
    stageProc->setPosX(0,true);
    stageProc->setPosZ(0,true);

    emit finished(i);
}

