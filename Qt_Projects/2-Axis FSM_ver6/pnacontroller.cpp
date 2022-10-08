#include "pnacontroller.h"

const QString HOSTIP = "192.168.1.2";
#define HOSTPORTNUM        5025
#define INTERMEASTIME      10000

#define MAG(r,i) 20*log10(pow((r*r)+(i*i),0.5))

pnaController::pnaController(structSetting * settingInfoPtrArg)
{
    settingInfoPtr      = settingInfoPtrArg;
    tcpSocketControl    = NULL;
    dataMeasMem         = NULL;
    isImmediateMeas     = true;
    pMeas               = NULL;

    initN1500A();
}
pnaController::~pnaController()
{
    tcpSocketMain->close();
    if(tcpSocketControl!=NULL)
        tcpSocketControl->close();

    delete tcpSocketMain,tcpSocketControl;
}

void pnaController::hide()
{
    pITransLine->Hide();
}

void pnaController::show()
{
    pITransLine->Show();
}

void pnaController::initN1500A()
{
    HRESULT hr;
    QUuid objGUID(CLSID_TransmissionLine);
    QUuid intfGUID(IID_ITransmissionLine);

    comObjectTransLine = new QAxObject();
    comObjectTransLine->setControl(objGUID.toString());
    comObjectTransLine->queryInterface(intfGUID, (void**)&pITransLine);

    pITransLine->Init();
    this->configN1500A();

}
void pnaController::configN1500A(bool isImmediateMeasArg)
{
    //configuration tasks
    pITransLine->SetMeasurement(GHz(settingInfoPtr->PnaStartFreq),
                                GHz(settingInfoPtr->PnaStopFreq),
                                 settingInfoPtr->PnaSweepPoints,
                                 MaterialCodes(LINEAR_SWEEP));

    pITransLine->SetIFBW(settingInfoPtr->PnaIFBW);
    pITransLine->SetModel(0);
    pITransLine->SetPower(settingInfoPtr->PnaPower);

    pITransLine->SetSampleHolder(settingInfoPtr->PnametalPlateThickness,
                                 settingInfoPtr->PnadistToSample,
                                 settingInfoPtr->PnasampleThickness,
                                 MaterialCodes(MM),
                                 MaterialCodes(FREESPACE),
                                 0);

    //if (this->isImmediateMeas = isImmediateMeasArg)
        //mainTimer->start(INTERMEASTIME);

    allocMemToMeasStruct(&pMeas,settingInfoPtr->PnaSweepPoints);
}


void pnaController::doMeasureN1500A(uint curScanPt, bool isScanInProgress)
{
    HRESULT hrMeas,hrS;
    int smplNum;
    float s12r,s12i,s22r,s22i;
    eTimer.start();//debug
    pITransLine->TriggerMeasurement();


    for(smplNum = 0;smplNum<settingInfoPtr->PnaSweepPoints;smplNum++)
    {
        hrMeas = pITransLine->GetMeasurement(smplNum,
                                    &pMeas->f[smplNum],
                                    &pMeas->e.real[smplNum],
                                    &pMeas->e.imag[smplNum],
                                    &pMeas->u.real[smplNum],
                                    &pMeas->u.imag[smplNum]);

        hrS = pITransLine->GetRotatedSparameters(smplNum,
                                    &pMeas->f[smplNum],
                                    &pMeas->s11.real[smplNum],
                                    &pMeas->s11.imag[smplNum],
                                    &pMeas->s21.real[smplNum],
                                    &pMeas->s21.imag[smplNum],
                                    &s12r,&s12i,&s22r,&s22i); //These values will not be used.

        pMeas->f[smplNum] = pMeas->f[smplNum]/1000000000;
        pMeas->s11.mag[smplNum] = MAG(pMeas->s11.real[smplNum],pMeas->s11.imag[smplNum]);
        pMeas->s21.mag[smplNum] = MAG(pMeas->s21.real[smplNum],pMeas->s21.imag[smplNum]);

        if (FAILED(hrMeas) || FAILED(hrS))
        {
            qWarning()<< "Problem in reading the measurement from N1500A. Quiting....";
            break;
        }
    }

    qDebug()<<"pnaController::doMeasureN1500A Time Elapsed in measurement:"<<eTimer.elapsed();
    //debug

/*
    qDebug()<<"num"<<"\t"<<"f"<<"\t\t"<<"e.real"<<"\t"<<"e.imag"<<"\t"<<"u.real"<<"\t"<<"u.imag"<<
              "\t"<<"s11.mag"<<"s11.real"<<"\t"<<"s11.imag"<<"\t"<<"s21.mag"<<"s21.real"<<"\t"<<"s21.imag";
    for (int i=0; i<10;i++)
    {
        qDebug()<<i<<"\t"<<pMeas->f[i]<<"\t"<<pMeas->e.real[i]<<"\t"<<pMeas->e.imag[i]<<"\t"<<pMeas->u.real[i]<<"\t"<<pMeas->u.imag[i]<<
        "\t"<<pMeas->s11.mag<<"\t"<<pMeas->s11.real[i]<<"\t"<<pMeas->s11.imag[i]<<"\t"<<pMeas->s21.mag<<"\t"<<pMeas->s21.real[i]<<"\t"<<pMeas->s21.imag[i];
    }
*/
    qDebug()<<"num"<<"\t"<<"f"<<"\t"<<"e.real"<<
              "\t"<<"s11.mag"<<"\t"<<"s11.real"<<"\t"<<"s11.imag"<<"\t"<<"s21.mag"<<"\t"<<"s21.real"<<"\t"<<"s21.imag";
    for (int i=0; i<10;i++)
    {
        qDebug()<<i<<"\t"<<pMeas->f[i]<<"\t"<<pMeas->e.real[i]<<
        "\t"<<pMeas->s11.mag[i]<<"\t"<<pMeas->s11.real[i]<<"\t"<<pMeas->s11.imag[i]<<"\t"<<pMeas->s21.mag[i]<<"\t"<<pMeas->s21.real[i]<<"\t"<<pMeas->s21.imag[i];
    }

    if(isScanInProgress)
    {
        emit newWfmReadyForCopy(pMeas,curScanPt);
        emit updateProgressBar_pnaControllerSignal(((double)(curScanPt+1)/settingInfoPtr->ScanPoints)*100);
        QString StatusTip = (QString::number(curScanPt+1) + "/" + QString::number(settingInfoPtr->ScanPoints));
        emit updateStatusBar_pnaControllerSignal(StatusTip);
    }

    selectMeasN1500A(settingInfoPtr->selectedMeas);
}

void pnaController::selectMeasN1500A(int selectMeas)
{
    QString title;
    switch (selectMeas)
    {
    case measType::er:
        this->slectedMeas = pMeas->e.real;
        break;

    case measType::ei:
        this->slectedMeas = pMeas->e.imag;

        break;

    case measType::ur:
        this->slectedMeas = pMeas->u.real;
        break;

    case measType::ui:
        this->slectedMeas = pMeas->u.imag;
        break;

    case measType::s11Mag:
        this->slectedMeas =pMeas->s11.mag;
        break;
    case measType::s21Mag:
        this->slectedMeas =pMeas->s21.mag;
        break;

    default:
        qDebug()<<"Impossible!!!!";
        break;
    }

    emit updatePlotOsci(slectedMeas,measName(selectMeas),pMeas->f);
}

//**************************************************SCPI part
void pnaController::initSetupSCPI()
{
    tcpSocketMain       = new QTcpSocket();
    tcpSocketMain->connectToHost(HOSTIP, HOSTPORTNUM);

    id = sendSCPItoPna("*IDN?");
    //sendSCPItoPna("SYSTem:FPRESet");
    //sendSCPItoPna("*CLS");
    //sendSCPItoPna("DISPLAY:ENABLE OFF");

    //timer for doing the immediate (osci) measurements
    mainTimer = new QTimer(this);
    connect(mainTimer, SIGNAL(timeout()), this, SLOT(doS11MeasSCPI()));
}
void pnaController::configS11MeasSCPI(bool isImmediateMeasArg)
{
    if (mainTimer->isActive())
        mainTimer->stop();

    setupMeasrementsSCPI();
    setupTriggerSCPI(false);

    if (this->isImmediateMeas = isImmediateMeasArg)
        mainTimer->start(INTERMEASTIME);
}

void pnaController::setupMeasrementsSCPI()
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

    //declare the memory for single buffer
    if (dataMeasMem!=NULL)
        delete dataMeasMem;

    dataMeasMem = (XFRDATATYPE *)new XFRDATATYPE[settingInfoPtr->PnaSweepPoints];
}

void pnaController::setupTriggerSCPI(bool ExtTrg)
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

void pnaController::doS11MeasSCPI(uint waveformNumber)
{
    eTimer.start();
    QByteArray opc;
    //opc = sendSCPItoPna("INITiate1;*OPC?");
    opc = sendSCPItoPna("ABORT;:INITIATE:IMMEDIATE;*OPC?");
    //opc = sendSCPItoPna("INITIATE:IMMEDIATE;*OPC?");
    qDebug()<<eTimer.elapsed();
    //sendSCPItoPna("CALCulate1:PARameter:SELect 'Ha_S11',fast"); // no display update
    sendSCPItoPna("CALCulate1:PARameter:SELect 'Ha_S11'");

    readDataSCPI(tcpSocketMain,dataMeasMem);

    //plot it here
    if (this->isImmediateMeas)
        emit updatePlotOsci(dataMeasMem,NULL,NULL);
    else
    {
        //emit newWfmReadyForCopy(dataMeasMem,curScanPt);
        emit updateProgressBar_pnaControllerSignal(((double)(waveformNumber+1)/settingInfoPtr->ScanPoints)*100);
        QString StatusTip = (QString::number(waveformNumber+1) + "/" + QString::number(settingInfoPtr->ScanPoints));
        emit updateStatusBar_pnaControllerSignal(StatusTip);
    }

    // and in case of scan send it to the data base
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
        return pnaResponseSCPI(tcpSocket);

        return "";
}

QByteArray pnaController::pnaResponseSCPI(QTcpSocket* tcpSocket)
{
    QByteArray rsp = "NoResponse";

    tcpSocket->waitForReadyRead(500);
    rsp = tcpSocket->readAll();

    rsp.chop(1); // drop the last line feed char
    qDebug().noquote()<<"Rcvd>> "<<rsp;

    return rsp;
}

QByteArray pnaController::readDataSCPI(QTcpSocket* tcpSocket,XFRDATATYPE * data)
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

        for (int i=0;i<settingInfoPtr->PnaSweepPoints;i++)
            data[i]=fmod((i),100)-50;

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

// A correct technical note is worth a thousand anxious moments of debugging.

/*
TransmissionLine GUID -> {467C0D4A-CDFE-48CC-95F3-1BB2455C5502}

Using a 32bit COM object in a 64bit environment
Registry hacking is needed

1.Locate your COM object GUID under the HKey_Classes_Root\Wow6432Node\CLSID\[GUID]

2.Once located add a new REG_SZ (string) Value. Name should be AppID and data should be the
same COM object GUID you have just searched for

3.Add a new key under HKey_Classes_Root\Wow6432Node\AppID\
 The new key should be called the same as the com object GUID

4.Under the new key you just added, add a new REG_SZ (string) Value, and call it
DllSurrogate. Leave the value empty

5.Create a new Key under HKey_Local_Machine\Software\Classes\AppID\
 Again the new key should be called the same as the COM object’s GUID. No values are
necessary to be added under this key.

That’s it, 32-bit COM Object should now be accessible from a 64bit environment and can be
used like a regular COM Object.
*/
