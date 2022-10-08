#ifndef ROTSTAGECONTROLLER_H
#define ROTSTAGECONTROLLER_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QTcpSocket>
#include "structDef.h"
#include "QTelnet.h"
#include <QMessageBox>

class rotStageController : public QObject
{
    Q_OBJECT
public:
    explicit rotStageController(structScan * scanInfoPtr_arg);
    ~rotStageController();

    //float scanStartPosX,scanStartPosZ;
public slots:
    void stop();
    void spinClockWise();
    void spinAntiClockWise();

    void home();
    float getPos();
    void setPos(float position);
    bool startScan(float intervalDeg, int speedDeg, int numOfRevArg, bool isClockWise);
    //bool isReadyForRptScan();
    QByteArray SendAndReceive(char *sendString);
    void showTelnetMsgs(const char *msg, int count);

private:
    structScan * scanInfoPtr;
    QTcpSocket *tcpSocketXps;
    QThread* vertSyncThread ;
    QTelnet telnet;
    int numOfRev;
    int revCounter;
    int revCompletionAngle;
    bool isClockWise;

signals:
    void updateProgressBar_stageControllerSignal(int Percentage);
    void updateStatusBar_stageControllerSignal(QString StatusTip);
    void pos(QString);
    void revDone(int);
    void updateStatusBar_rotStageControllerSignal(QString);
};

#endif // ROTSTAGECONTROLLER_H
