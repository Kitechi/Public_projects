#include "rotStageController.h"


#define DEBUGLOGS_ROTSTAGE
#define MAXDEG 3600000
#define HOSTPORT        5001
const QString HOSTIP = "192.168.254.254";

rotStageController::rotStageController(structScan * scanInfoPtr_arg)
{
    scanInfoPtr = scanInfoPtr_arg;
    numOfRev = 0;
    revCounter = 0;

    tcpSocketXps = new QTcpSocket();
    tcpSocketXps->connectToHost(HOSTIP, HOSTPORT);
    bool connected = tcpSocketXps->waitForConnected(3000);
    // return connteced
    // -------- bool connect() function part end ------

    // connected has value that it is connected
    if (!connected)
    {
        qWarning() << "Connection to rotation stage failed.";

        QMessageBox msgBox(QMessageBox::Critical, tr("Error 06-Connection Error"),tr("Connection to rotation stage failed."), 0);
        msgBox.exec();
    }
    else
    {
        SendAndReceive((char *)"FirmwareVersionGet (char *)");
    }

    //make telnet connection
    connect(&telnet, SIGNAL(newData(const char*,int)), this, SLOT(showTelnetMsgs(const char*,int)) );
    //connect( &telnet, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onStateChanged(QAbstractSocket::SocketState)) );
    //connect( ui->cbCmd, SIGNAL(command(QString)), this, SLOT(onCommand(QString)));

    telnet.connectToHost(HOSTIP,23);
    telnet.waitForConnected(3000);
}

rotStageController::~rotStageController()
{
    if (telnet.isConnected())
        telnet.disconnectFromHost();
}

void rotStageController::showTelnetMsgs(const char *msg, int count)
{
    QByteArray b = QByteArray(msg, count);
    QByteArray result;
    static int prevEvent = 0;
    char cmdString[100];
    //Problem in telnet server. Strip the data if needed.
    char c = b.at(0);
    if (c == '\0' )
    {
        b = b.right(b.length()-2);
    }
    QString strMsg;
    strMsg = QString::fromLatin1(b);

    qDebug()<<"vertSync::showTelnetMsgs"<<strMsg;
    getPos();

    if (strMsg.indexOf("login") == 0)
    {
        QString cmd = "Administrator";
        telnet.sendData(cmd.toLatin1()); //user name
        telnet.sendData("\n");
    }
    else if (strMsg.indexOf("Password") != -1)
    {
        QString cmd = "Administrator";
        telnet.sendData(cmd.toLatin1()); //password
        telnet.sendData("\n");
    }
    else if (/*strMsg.indexOf("Start") == 0||*/
             strMsg.indexOf("TCL_API_drivers") == 0) //if (revCounter < numOfRev)
    {
        revCounter++;
        QString StatusTip = (QString::number(revCounter) + "/" + QString::number(numOfRev));
        updateStatusBar_rotStageControllerSignal(StatusTip);

        if (revCounter<numOfRev)
        {

            //qDebug("Emit vertical Stage Move Signal - revCounter:%d",revCounter);

            revDone(revCounter);

            /*
            if(isClockWise)
                //sprintf(cmdString, "EventExtendedConfigurationTriggerSet(SP.pos.WaitForPositionToggled,%d,0,0,0)",360*(revCounter+1) + 1);
            else
                sprintf(cmdString, "EventExtendedConfigurationTriggerSet(SP.pos.WaitForPositionToggled,%d,0,0,0)",MAXDEG-(360*(revCounter+1)));
            */


            //SendAndReceive((char *)"EventExtendedConfigurationTriggerSet (Timer1.Timer, 0, 0, 0, 0)");
            //SendAndReceive((char *)cmdString); // start position, end position, interval
            //SendAndReceive((char *)"EventExtendedConfigurationActionSet(ExecuteTCLScript,MoveVert.tcl,1,ttyp0,0)");
            result = SendAndReceive((char *)"EventExtendedStart(int *)");

/*
            int firstComa = result.indexOf(",",1);
            int secComa = result.indexOf(",",2);
            QByteArray returnCode = result.mid(firstComa+1,secComa-firstComa-1);
            prevEvent = returnCode.toInt();
            qDebug()<<"vertSync::showTelnetMsgs - prevEvent code"<<prevEvent;

            if (prevEvent>1)
            {
                sprintf(cmdString, "EventExtendedRemove(%d)",prevEvent-1);
                SendAndReceive((char *)cmdString); // start position, end position, interval
            }
*/

            /*
            while (retCodeInt != 0)
            {
                qDebug()<<"vertSync::showTelnetMsgs - Failure Code"<<retCodeInt;
                result = SendAndReceive((char *)"EventExtendedStart(int *)");
            }

            //parse result to check success. resend in case of failure.
*/


        }
        else
        {
            stop();
        }
    }
}

#if 0 // timer trigger cant start TCL script
        if (revCounter == 1)
        {
            sprintf(cmdString, "TimerSet(Timer1,%d);",72000);
            SendAndReceive((char *)cmdString); // start position, end position, interval

            SendAndReceive((char *)"EventExtendedConfigurationTriggerSet (Timer1, 0, 0, 0, 0)");
            SendAndReceive((char *)cmdString); // start position, end position, interval
            SendAndReceive((char *)"EventExtendedConfigurationActionSet(ExecuteTCLScript,MoveVert.tcl,1,ttyp0,0)");
            result = SendAndReceive((char *)"EventExtendedStart(int *)");
        }
        if (revCounter == numOfRev)
            stop();
#endif
QByteArray rotStageController::SendAndReceive(char *sendString)
{
    QByteArray array;
    int cnt = 0;

    if (tcpSocketXps->state() == QAbstractSocket::ConnectedState)
    {
        // Socket Write
        tcpSocketXps->write(sendString);

        // Sockt Read
        while (!array.contains("EndOfAPI") && cnt < 1000) {
            tcpSocketXps->waitForReadyRead();
            array += tcpSocketXps->readAll();
            cnt += 1;
        }
#ifdef DEBUGLOGS_ROTSTAGE
        // Debug Log
        qDebug()<<"";
        qDebug() << "Cmd:" + QString(sendString);
        qDebug() << "Rsp: " + array;
#endif
        return array;
    }
}

void rotStageController::stop()
{
    numOfRev = 0;
    revCounter = 0;
    getPos();
    SendAndReceive((char *)"GroupSpinModeStop (SP,50)");

}

void rotStageController::spinClockWise()
{
    SendAndReceive((char *)"GroupSpinParametersSet (SP.pos,30,50)");
}

void rotStageController::spinAntiClockWise()
{
    SendAndReceive((char *)"GroupSpinParametersSet (SP.pos,-30,50)");
}

void rotStageController::home()
{
    SendAndReceive((char *)"GroupKill (SP)");
    SendAndReceive((char *)"GroupInitialize (SP)");
    SendAndReceive((char *)"GroupHomeSearch (SP)");
    SendAndReceive((char *)"GroupStatusGet(SP,int *)");
}

float rotStageController::getPos()
{
    QByteArray result;
    QByteArray bytePos;
    QString strPos;
    int startIndex,stopIndex;
    result = SendAndReceive((char *)"GroupPositionCurrentGet(SP.pos,double *)");

    //traverse the response to get the position
    startIndex = result.indexOf(",",1);
    stopIndex = result.indexOf(",",2);
    bytePos = result.mid(startIndex,stopIndex-startIndex);
    strPos = QString::fromLatin1(bytePos.data());

    emit pos(strPos);

    return 99.125;//strPos.toFloat();

    //QString s_data = QString::fromAscii(data.data());
}

void rotStageController::setPos(float position)
{
    qDebug()<<"rotStageController::setPos: "<<position;
    char cmdString[100];
    sprintf(cmdString, "GroupMoveAbsolute(SP.pos,%.3f)", position);

    SendAndReceive((char *)"PositionerSGammaParametersSet(SP.pos,50,50,0.005,0.05)");
    SendAndReceive((char *)cmdString);
}

bool rotStageController::startScan(float intervalDeg, int speedDeg, int numOfRevArg, bool isClockWiseArg)
{
    QByteArray result;
    char cmdString[500];
    qDebug("rotStageController::startScan --  intervalDeg: %f , speedDeg: %d, numOfRev: %d,  isClockWise: %d",
           intervalDeg , speedDeg, numOfRevArg,  isClockWiseArg);

    home();
    //initial offset to ensure trigger @0 degree
    if (isClockWise == true)
    {
        //spinAntiClockWise();
        //QThread::msleep(200);
        //stop();
        //setPos(360-20);
    }
    else
    {
        //setPos(20);
    }

    numOfRev    = numOfRevArg;
    isClockWise = isClockWiseArg;

    //MAXDEG

    //Set PCO
    if (isClockWise == true)
        sprintf(cmdString, "PositionerPositionCompareSet (SP.pos,%f,%d,%f)",intervalDeg, numOfRev*360,intervalDeg);
    else
    {
        float minWin = MAXDEG - numOfRev*360;
        float maxWin = MAXDEG - intervalDeg;
        QString cmdQstring;
        cmdQstring = "PositionerPositionCompareSet (SP.pos," + QString::number(minWin,'f',6) +
                ","+ QString::number(maxWin,'f',6) +
                "," + QString::number(intervalDeg,'f',6)+
                ")";

        for (int i =0;i<cmdQstring.length();i++)
        {
            cmdString[i] = cmdQstring[i].toLatin1();
        }
        //sprintf(cmdString, "PositionerPositionCompareSet (SP.pos,%lf,%d,%lf)",MAXDEG - numOfRev*360,MAXDEG - intervalDeg,intervalDeg);
    }

    result = SendAndReceive((char *)cmdString); // start position, end position, interval
    result = SendAndReceive((char *)"PositionerPositionCompareEnable (SP.pos)");
    result = SendAndReceive((char *)"PositionerPositionCompareGet(SP.pos,double *,double *,double *,bool *)");

    sprintf(cmdString, "PositionerPositionComparePulseParametersSet (SP.pos,%d,0)",PULSEWIDTH); //constant acceleration
    result = SendAndReceive((char *)cmdString);

    //set event/action to tell about position for moving the vertical stage
    result = SendAndReceive((char *)"EventExtendedConfigurationTriggerSet(SP.pos.WaitForPositionToggled,359,0,0,0)");
    result = SendAndReceive((char *)"EventExtendedConfigurationActionSet(ExecuteTCLScript,MoveVert.tcl,1,ttyp0,0)");
    result = SendAndReceive((char *)"EventExtendedStart(int *)");

    revCounter = 0;

    //should be in separate thread!!!
    //-configure rev complete event tcl
    //-open a telnet connection
    //-after recieving an event, configure the next one.

    //configVertSyncThread(numOfRev);
    //QThread::msleep(10000);
    //set speed and direction
    sprintf(cmdString, "GroupSpinParametersSet (SP.pos,%d ,200)", isClockWise? speedDeg:-speedDeg); //constant acceleration
    result = SendAndReceive((char *)cmdString); // start position, end position, interval

    return true;
}
