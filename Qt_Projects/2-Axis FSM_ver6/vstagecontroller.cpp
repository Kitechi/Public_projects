#include "vstageController.h"
#define ECHO_WAIT   100

vstageController::vstageController()
{
    vStageComPort   = "COM8";
    this->ver();
    targetPos = 0;
}
vstageController::~vstageController()
{

}

bool vstageController::ver()
{
    //QByteArray contNameCmd = "SCI 9600,8,2,2\r";
    QByteArray contNameCmd = "IDC X\r";
    rwSerialPort(vStageComPort,contNameCmd,ECHO_WAIT);
    contNameCmd = "INR X\r";
    rwSerialPort(vStageComPort,contNameCmd,ECHO_WAIT);
    contNameCmd = "SCI\r";
    return(rwSerialPort(vStageComPort,contNameCmd,ECHO_WAIT));
}
bool vstageController::home()
{
    QByteArray contNameCmd = "HOM X\r";
    return(rwSerialPort(vStageComPort,contNameCmd,0));
}
bool vstageController::stop()
{
    QByteArray contNameCmd = "STO X\r";
    bool success = rwSerialPort(vStageComPort,contNameCmd,0);
    float test = getPos();
    return success;
}

bool vstageController::jogPlus()
{
    QByteArray contNameCmd = "JOG +X\r";
    return(rwSerialPort(vStageComPort,contNameCmd,0));
}

bool vstageController::jogMinus()
{
    QByteArray contNameCmd = "JOG -X\r";
    return(rwSerialPort(vStageComPort,contNameCmd,0));
}



bool vstageController::setPosAbs(int posNum,bool isPosCheck,int setPosAttempt)
{
    QByteArray cmdByteArr;
    QString cmdStr = "PAB "+QString::number(posNum*1000)+"\r";
    bool comSuccess = false;
    bool retVal = true;
    float curPos = 0;

    cmdByteArr = cmdStr.toLocal8Bit();
    targetPos = posNum;
    comSuccess = rwSerialPort(vStageComPort,cmdByteArr,0);

    if (isPosCheck)
    {
        delay(1000);
        curPos = getPos();
        qDebug()<<"vstageController::setPosAbs() - targetPos"<<targetPos<<"curPos"<<curPos<<"setPosAttempt"<<setPosAttempt;

        if ((targetPos!=curPos && setPosAttempt++ < STAGESETPOSMAXTRIALS && comSuccess))
            retVal = setPosAbs(targetPos,true,setPosAttempt);
        else if (targetPos==curPos)
            retVal = true;
        else
            retVal = false;
    }
    return retVal;
}

bool vstageController::setPosRel(float posNum)
{
    QByteArray cmdByteArr;
    QString pos = QString::number(posNum*1000);
    QString cmdStr = "PIC "+pos+"\r";
    cmdByteArr = cmdStr.toLocal8Bit();
    return(rwSerialPort(vStageComPort,cmdByteArr,0));
}

float vstageController::getPos()
{
    QByteArray contNameCmd = "POS\r";
    QString posStr;
    bool success;
    float returnValFlt,returnValFlt4Disp;
    QString returnValString;

    if(success = rwSerialPort(vStageComPort,contNameCmd,ECHO_WAIT,&posStr))
    {
        posStr = posStr.mid(4,8);
        returnValFlt = posStr.toUInt(&success,16)/1000;
    }
    else
    {
        returnValFlt = -1;
    }

    returnValFlt4Disp = round(returnValFlt*100)/100;
    returnValString = QString::number(returnValFlt4Disp,'f',2);
    emit curPos(returnValString);

    return(returnValFlt);
}

void vstageController::initSerialPort(QSerialPort *serial,QString portName)
{
    serial->setPortName(portName);
    serial->setBaudRate(9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
}
bool vstageController::rwSerialPort(QString portName, QByteArray data, int waitForEcho, QString* strRsp,bool verbose )
{
    bool SerialPortOpen;
    qint64 WrittenBytes,numRead;
    char response[200] ={'\0'} ;
    int ReadIndex = 0;

    QSerialPort *serial;
    serial          = new QSerialPort();

    initSerialPort(serial,portName);
    if(SerialPortOpen = serial->open(QIODevice::ReadWrite))
    {
        WrittenBytes = serial->write(data);

        QTime myTimer;
        myTimer.start();
        //read response
        ReadIndex = 0;
        for (int j = 0; j<20; j ++) response[j] ='\0';
        do
        {
            serial->waitForReadyRead(waitForEcho);
            numRead  = serial->read(&response[ReadIndex], 20);
            ReadIndex += numRead;
        }
        while((waitForEcho!=0) && (response[(ReadIndex-1)]!='\r') && numRead!=0 );

        data.chop(1);

        if( (waitForEcho!=0) && (ReadIndex == 0) )
        {
          // no response from port somethings wrong, quit further commands and try manual command exec
          if (verbose)
          {
              qDebug().nospace()<<"Command: "<<data<<
                        "       "<<
                        "No Echo from Serial Port" << portName;
          }
          serial->close();
          return false;
        }
        else
        {
            if( (waitForEcho!=0) )
            {
                if (response[ReadIndex-2] == '\n' || response[ReadIndex-2] == '\r')
                    response[ReadIndex-2] = '\0';
                if (response[ReadIndex-1] == '\n' || response[ReadIndex-1] == '\r')
                    response[ReadIndex-1] = '\0';
            }
            if (verbose)
            {
                qDebug().nospace()<<"Command: "<<data<<"       "<<"\t\t-Response: "<<response<<"\t-Response Time(ms): "<<myTimer.elapsed();
            }
        }
    }
    else
    {
        qDebug()<<"Could not open PortNumber:"<<portName<<"SerialPortOpen: "<<SerialPortOpen;
        serial->close();
        return false;
    }
    serial->close();
    if (strRsp != NULL)
    {
        strRsp->append(response);
    }

    delete serial;

    return true;
}

void vstageController::delay(int delayTimeMs)
{
    QTime dieTime= QTime::currentTime().addMSecs(delayTimeMs);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
