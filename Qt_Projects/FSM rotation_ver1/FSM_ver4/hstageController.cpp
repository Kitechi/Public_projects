#include "hstageController.h"

hstageController::hstageController()
{
    targetPos = 0;

    bool openSuccess=false;
    HMODULE hPmacLib = 0;
    char buf[255];

    hPmacLib = LoadLibrary(DRIVERNAME);
    DeviceOpen = (OPENPMACDEVICE)GetProcAddress(hPmacLib,"OpenPmacDevice");
    DeviceSelect = (SELECTPMACDEVICE)GetProcAddress(hPmacLib,"PmacSelect");
    DeviceClose = (CLOSEPMACDEVICE)GetProcAddress(hPmacLib,"ClosePmacDevice");
    DeviceGetResponse = (GETRESPONSEA)GetProcAddress(hPmacLib,"PmacGetResponseA");
    DeviceGetControlResponse = (GETCONTROLRESPONSEA)GetProcAddress(hPmacLib,"PmacGetControlResponseA");

    //dwDevice = DeviceSelect(NULL);
    dwDevice = 0;
    openSuccess = DeviceOpen(dwDevice);

    //if (openSuccess==false)
    //{
    //    QMessageBox msgBox(QMessageBox::Critical, tr("hStage Error"),tr("hStage not found."), 0);
    //    msgBox.exec();
    //}

    DeviceGetControlResponse(dwDevice,buf,255,24); //send CTRL_X -> clear the comm buffs
}

hstageController::~hstageController()
{
    DeviceClose(dwDevice);
}

void hstageController::kill()
{
    char buf[255];
    DeviceGetControlResponse(dwDevice,buf,255,11); //ctrl k
}

void hstageController::stop()
{
    char buf[255];
    DeviceGetControlResponse(dwDevice,buf,255,1); //ctrl a
    float test = this->getPos();
}

void hstageController::home()
{

    LPSTR buf = new char[255];
    char cmdChar[10] = "P1000=1";
    char cmdChar1[10] = "P1001=1";
    LPSTR cmd = cmdChar;
    LPSTR cmd1 = cmdChar1;
    DeviceGetResponse(dwDevice,buf,255,cmd); //start home search
    DeviceGetResponse(dwDevice,buf,255,cmd1); //kindda reset if the last home search didnt go as planned
}

void hstageController::jogPlus()
{
    LPSTR buf = new char[255];
    char cmdChar[10] = "#1J+";
    LPSTR cmd = &cmdChar[0];
    DeviceGetResponse(dwDevice,buf,255,cmd);
}

void hstageController::jogMinus()
{
    LPSTR buf = new char[255];
    char cmdChar[10] = "#1J-";
    LPSTR cmd = &cmdChar[0];
    DeviceGetResponse(dwDevice,buf,255,cmd);
}

bool hstageController::setPosAbs(float posNum, bool isPosCheck, int setPosAttempt )
{
    char buf[255];
    QString cmd;
    float curPos=0;
    bool retVal = true;

    targetPos = roundf(posNum*100)/100; // store the rounded value for easy comparison
    cmd = "J="+QString::number(posNum*819.2);
    DeviceGetResponse(dwDevice,buf,255,cmd.toLocal8Bit().data());

    if (isPosCheck)
    {
        delay(1000);
        curPos = getPos();
        qDebug()<<"hstageController::setPosAbs() - targetPos"<<targetPos<<"curPos"<<curPos<<"setPosAttempt"<<setPosAttempt;

        if ((targetPos!=curPos && setPosAttempt++ < STAGESETPOSMAXTRIALS ))
            retVal = setPosAbs(targetPos,true,setPosAttempt);
        else if (targetPos==curPos)
            retVal = true;
        else
            retVal = false;
    }

    return retVal;
}

void hstageController::setPosRel(float posNum)
{
    char buf[255];
    QString cmd;
    int i =0;

    posNum = posNum*819.2;
    cmd = "J^"+QString::number(posNum);
    DeviceGetResponse(dwDevice,buf,255,cmd.toLocal8Bit().data());
}

//Returns Position in mm
float hstageController::getPos()
{
    char buf[255];
    QString strRsp;
    int i =0;

    double returnValFlt,returnValFlt4Disp;
    QString returnValString;
    char cmdChar[10] = "P";
    LPSTR cmd = cmdChar;
    DeviceGetResponse(dwDevice,buf,255,cmd);

    while (buf[i]!='\r')
        strRsp.append(buf[i++]);

    returnValFlt = strRsp.toFloat()/819.2;

    returnValFlt4Disp = roundf(returnValFlt*100)/100;
    returnValString = QString::number(returnValFlt4Disp,'f',2);
    emit curPos(returnValString);

    return(returnValFlt4Disp);
}

void hstageController::delay(int delayTimeMs)
{
    QTime dieTime= QTime::currentTime().addMSecs(delayTimeMs);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
