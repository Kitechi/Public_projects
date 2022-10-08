#include "pnacontroller.h"

const QString HOSTIP = "192.168.1.2";
#define HOSTPORTNUM        5025

pnaController::pnaController(structSetting * settingInfoPtrArg)
{
    settingInfoPtr = settingInfoPtrArg;
    tcpSocketMain = new QTcpSocket();
    tcpSocketMain->connectToHost(HOSTIP, HOSTPORTNUM);
    tcpSocketControl = NULL;

    initSetup();

    configS11MeasTrig();
    //configS11Meas();
}

pnaController::~pnaController()
{
    //sendSCPItoPna("SYSTem:PRESet");
    //sendSCPItoPna("DISPLAY:ENABLE ON");//Display OFF
    //sendSCPItoPna("*CLS");

    tcpSocketMain->close();
    if(tcpSocketControl!=NULL)
        tcpSocketControl->close();

    delete tcpSocketMain,tcpSocketControl;
}


void pnaController::initSetup()
{
    id = sendSCPItoPna("*IDN?");
    sendSCPItoPna("SYSTem:FPRESet");
    sendSCPItoPna("*CLS");
    sendSCPItoPna("DISPLAY:ENABLE OFF");// Endianness adjustment
}

void pnaController::setupMeasDoneSrq()
{
    // Enable for the OPC bit (bit 0, which has weight 1) in the instrument's
    // Event Status Register, so that when that bit's value transitions from 0 to 1
    // then the Event Status Register bit in the Status Byte (bit 5 of that byte)
    // will become set.
    //sendSCPItoPna("*ESE 1");

    // Enable for bit 5 (which has weight 32) in the Status Byte to generate an
    // SRQ when that bit's value transitions from 0 to 1.
    //sendSCPItoPna("*SRE 32")

    sendSCPItoPna("STAT:OPER:DEV:ENAB 16");
    sendSCPItoPna("STAT:OPER:ENAB 1024");
    sendSCPItoPna("*SRE 128");

    // Ask the instrument for the number of a port on which a 'control'
    // socket connection can be opened.
    QByteArray controlPortNumStr = sendSCPItoPna("SYSTem:COMMunicate:TCPip:CONTrol?");
    controlPortNum = controlPortNumStr.toInt();

    tcpSocketControl = new QTcpSocket();
    tcpSocketControl->connectToHost(HOSTIP, controlPortNum);
    connect(tcpSocketControl,SIGNAL(readyRead()),this,SLOT(controlSocketSRQ()));
}

void pnaController::setupMeasrements()
{
    QByteArray opc;
    QString cmd;

    // Create S11 measurement
    sendSCPItoPna("CALCulate1:PARameter:DEFine:EXT 'Ha_S11',S11");

    // Turn on Window #1
    //sendSCPItoPna("DISPlay:WINDow1:STATe ON");

    // Put a trace (Trace #1) into Window #1 and 'feed' it from the measurement
    //sendSCPItoPna("DISPlay:WINDow1:TRACe1:FEED 'Ha_S11'");

    //All measurements in the channel made per trigger.
    sendSCPItoPna("SENSe1:SWEep:TRIGger:POINt OFF");

    //sendSCPItoPna("SENSe1:SWEep:POINts 51");
    cmd = "SENSe1:SWEep:POINts " + QString::number(settingInfoPtr->PnaSweepPoints);
    sendSCPItoPna(cmd);

    //sendSCPItoPna("SENSe1:FREQuency:STARt 8200000000");
    cmd = "SENSe1:FREQuency:STARt " + QString::number(settingInfoPtr->PnaStartFreq*1000000000);
    sendSCPItoPna(cmd);

    //sendSCPItoPna("SENSe1:FREQuency:STOP  12400000000");
    cmd = "SENSe1:FREQuency:STOP " + QString::number(settingInfoPtr->PnaStopFreq*1000000000);
    sendSCPItoPna(cmd);

    //Set the Power Mode
    //sendSCPItoPna("SOUR:POW:MODE AUTO");//ON , AUTO

    //Endianness adjustment
    sendSCPItoPna("FORM:BORD SWAP");

    //Averaging
//    sendSCPItoPna("sense1:average:count 5");
//    sendSCPItoPna("sense1:average:mode sweep");
//    sendSCPItoPna("sense1:average:state on");

}

void pnaController::setupTrigger(bool ExtTrg)
{
    if (ExtTrg)
    {
        //sendSCPItoPna("TRIG:SOUR MANual");

    //    'If using an External trigger source that is capable of
    //    'sending SINGLE trigger signals, then uncomment the following.
    //    'This command automatically sets trigger source to External

        sendSCPItoPna("TRIG:SOUR EXT");
        sendSCPItoPna("TRIG:TYPE EDGE");

        sendSCPItoPna("TRIG:READ:POL LOW");
        QThread::msleep(500);

        sendSCPItoPna("TRIG:READ:POL HIGH");

    //    'Set Global triggering (Default)
        sendSCPItoPna("TRIG:SCOPe ALL");

    //    'Set Channel Settings
    //    'The channels respond to UNLIMITED trigger signals (Default)
        sendSCPItoPna("SENS1:SWE:MODE CONTINUOUS");
        //sendSCPItoPna("CALCulate1:PARameter:SELect 'Ha_S11'");
        sendSCPItoPna("CALCulate1:PARameter:SELect 'Ha_S11',fast");
    }
    else
    {
        // Setup the channel for single sweep trigger
        QByteArray opc = sendSCPItoPna("INITiate1:CONTinuous OFF;*OPC?"); // send the trigger from S/W
    }
}

void pnaController::configS11MeasTrig()
{
    setupMeasDoneSrq();
    setupMeasrements();
    setupTrigger();
}

void pnaController::configS11Meas()
{
    setupMeasrements();
    setupTrigger(false);
}

void pnaController::doS11Meas()
{
    while (1)
    {
        eTimer.start();
        QByteArray opc;
        //opc = sendSCPItoPna("INITiate1;*OPC?");
        opc = sendSCPItoPna("ABORT;:INITIATE:IMMEDIATE;*OPC?");
        //opc = sendSCPItoPna("INITIATE:IMMEDIATE;*OPC?");
        qDebug()<<eTimer.elapsed();
        //sendSCPItoPna("CALCulate1:PARameter:SELect 'Ha_S11',fast"); // no display update
        sendSCPItoPna("CALCulate1:PARameter:SELect 'Ha_S11'");

        readData(tcpSocketMain,&dataTemp[0]);
    }
}

QByteArray pnaController::sendSCPItoPna(QString cmdStr, QTcpSocket* tcpSocket)
{
    if (tcpSocket ==  NULL)
        tcpSocket = this->tcpSocketMain;
    qDebug().noquote()<<"Sent<<"<<cmdStr;

    QByteArray cmdChar;
//append
    cmdStr = cmdStr + "\n";
    cmdChar = cmdStr.toLocal8Bit();

    tcpSocket->write(cmdChar);

    //if (cmdStr.contains("*OPC"))
        //eTimer.start();

    if ((cmdStr.indexOf("?")    >= 0 && cmdStr.contains("DATA?",Qt::CaseInsensitive)==false)  ||
        cmdStr.indexOf("DCL")   >=0
            )
        return pnaResponse(tcpSocket);

        return "";
}

QByteArray pnaController::pnaResponse(QTcpSocket* tcpSocket)
{
    QByteArray rsp = "NoResponse";

    tcpSocket->waitForReadyRead(500);
    rsp = tcpSocket->readAll();

    rsp.chop(1); // drop the last line feed char
    qDebug().noquote()<<"Rcvd>> "<<rsp;

    return rsp;
}

QByteArray pnaController::readData(QTcpSocket* tcpSocket,XFRDATATYPE * data)
{
    QByteArray rsp = "NoResponse";
    char charData;
    int numDigits,byteCount, bytesDone;

    sendSCPItoPna(dataSettingSCPI);
    sendSCPItoPna("CALCulate1:DATA? FDATA;");

    tcpSocket->waitForReadyRead(500);
    tcpSocket->read(&charData,1);
    if (charData == (char)'#')
    {
        tcpSocket->read(&charData,1);
        numDigits = atoi(&charData);

        rsp = tcpSocket->read(numDigits);
        byteCount = atoi(rsp);

        tcpSocket->waitForReadyRead(1);// just in case the buffer is not completly reported
        bytesDone = tcpSocket->read((char*)data,byteCount);
        if(bytesDone != byteCount)
            qDebug()<<"**Warning!!! bytesDone"<<bytesDone<<"is not euqal to byteCount"<<byteCount;

        qDebug()<<"Rcvd(data)>> numDigits:"<<numDigits<<
                  "byteCount:"<<byteCount<<
                  "data[0]:"<<data[0]<<
                  "data[1]:"<<data[1]<<
                  "data[2]:"<<data[2]<<
                  "data[3]:"<<data[3]<<
                  "data[3]:"<<data[4]<<
                  "Elapsed Time"<<eTimer.elapsed();

    }

    rsp = tcpSocket->readAll(); //flush all the reaming values.
    if (rsp.contains('\n')==false)
    {
        qDebug()<<"No end of line so reading some more";
                  tcpSocket->waitForReadyRead(500);
                  rsp = tcpSocket->readAll(); //flush all the reaming values.
    }
   // qDebug()<<rsp;
    return rsp;
}

void pnaController::controlSocketSRQ()
{
    sendSCPItoPna("*CLS");
    //QByteArray rsp = "NoResponse";
    //rsp = tcpSocketControl->readAll();

    //rsp.chop(1); // drop the last line feed char

    qDebug().noquote()<<QTime::currentTime()<<"Rcvd(ctrl)>> "//<<rsp<<
                        "elapsedTimer"<<eTimer.elapsed();

    eTimer.start();
    readData(tcpSocketMain,&dataTemp[0]);


    //if (rsp.indexOf("SRQ")  >= 0 )
    //sendSCPItoPna("DCL",tcpSocketControl);
}


//*********************************************wcollector of lost souls********************
void pnaController::configS11MeasTrigOld()
{

    QByteArray opc;
    sendSCPItoPna("SYSTem:FPRESet");

    // Create S11 measurement
    sendSCPItoPna("CALCulate1:PARameter:DEFine:EXT 'Ha_S11',S11");

    // Turn on Window #1
    sendSCPItoPna("DISPlay:WINDow1:STATe ON");

    // Put a trace (Trace #1) into Window #1 and 'feed' it from the measurement
    sendSCPItoPna("DISPlay:WINDow1:TRACe1:FEED 'Ha_S11'");

    //All measurements in the channel made per trigger.
    sendSCPItoPna("SENSe1:SWEep:TRIGger:POINt OFF");
    sendSCPItoPna("SENSe1:SWEep:POINts 401");
    sendSCPItoPna("SENSe1:FREQuency:STARt 8200000000");
    sendSCPItoPna("SENSe1:FREQuency:STOP  12400000000");

    //Set to Auto Mode
    sendSCPItoPna("SOUR:POW:MODE AUTO");//ON , AUTO

    sendSCPItoPna("FORM:BORD SWAP");// Endianness adjustment

    sendSCPItoPna("DISPLAY:ENABLE OFF");//Display OFF

    //sendSCPItoPna("TRIG:SOUR MANual");


//    'If using an External trigger source that is capable of
//    'sending SINGLE trigger signals, then uncomment the following.
//    'This command automatically sets trigger source to External

    sendSCPItoPna("TRIG:SOUR EXT");
    sendSCPItoPna("TRIG:TYPE EDGE");

    sendSCPItoPna("TRIG:READ:POL LOW");
    QThread::msleep(2000);

    sendSCPItoPna("TRIG:READ:POL HIGH");


//    'Set Global triggering (Default)
    sendSCPItoPna("TRIG:SCOPe ALL");

//    'Set Channel Settings
//    'The channels respond to UNLIMITED trigger signals (Default)

    sendSCPItoPna("SENS1:SWE:MODE CONTINUOUS");

    sendSCPItoPna("CALCulate1:PARameter:SELect 'Ha_S11'");
}

void pnaController::configS11MeasOld()
{
    QByteArray opc;
    sendSCPItoPna("SYSTem:FPRESet");

    // Create S11 measurement
    sendSCPItoPna("CALCulate1:PARameter:DEFine:EXT 'Ha_S11',S11");

    // Turn on Window #1
    sendSCPItoPna("DISPlay:WINDow1:STATe ON");

    // Put a trace (Trace #1) into Window #1 and 'feed' it from the measurement
    sendSCPItoPna("DISPlay:WINDow1:TRACe1:FEED 'Ha_S11'");

    // Setup the channel for single sweep trigger
    opc = sendSCPItoPna("INITiate1:CONTinuous OFF;*OPC?"); // send the trigger from S/W

    //Setup the channel for manual trigger
    //opc = sendSCPItoPna("trigger:sequence:source manual;*OPC?");

    //All measurements in the channel made per trigger.
    sendSCPItoPna("SENSe1:SWEep:TRIGger:POINt OFF");
    sendSCPItoPna("SENSe1:SWEep:POINts 51");
    sendSCPItoPna("SENSe1:FREQuency:STARt 8200000000");
    sendSCPItoPna("SENSe1:FREQuency:STOP  12400000000");

    //Set to Auto Mode
    sendSCPItoPna("SOUR:POW:MODE AUTO");//ON , AUTO

    sendSCPItoPna("FORM:BORD SWAP");// Endianness adjustment

    sendSCPItoPna("DISPLAY:ENABLE OFF");// Endianness adjustment
}
