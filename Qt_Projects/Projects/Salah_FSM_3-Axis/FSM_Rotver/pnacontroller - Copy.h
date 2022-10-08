#ifndef PNACONTROLLER_H
#define PNACONTROLLER_H

#include <QtCore>
#include <QTcpSocket>
#include <QtGlobal>
#include "structDef.h"

#define XFRDATAMAXRES

#ifdef XFRDATAMAXRES
#define XFRDATATYPE double
const QString dataSettingSCPI = "format:data real,64;";
#endif

#ifndef XFRDATAMAXRES
#define XFRDATATYPE float
const QString dataSettingSCPI = "format:data real,32;";
#endif

class pnaController : public QObject
{
    Q_OBJECT
public:
    explicit pnaController(structSetting * settingInfoPtrArg);
    ~pnaController();

public slots:
    void controlSocketSRQ();
    void doS11Meas();


private:
    QTcpSocket* tcpSocketMain;
    QTcpSocket* tcpSocketControl;
    QByteArray id;
    QElapsedTimer eTimer;

    int controlPortNum;
    XFRDATATYPE dataTemp[6401];

    structSetting * settingInfoPtr;

    void initSetup();
    void setupMeasDoneSrq();
    void setupMeasrements();
    void setupTrigger(bool ExtTrg=true);
    void configS11Meas();
    void configS11MeasTrig();
    void configS11MeasTrigOld();
    void configS11MeasOld();

    QByteArray pnaResponse(QTcpSocket *tcpSocket=NULL);
    QByteArray sendSCPItoPna(QString cmdStr, QTcpSocket *tcpSocket=NULL);
    QByteArray readData(QTcpSocket* tcpSocket, XFRDATATYPE *data=NULL);

signals:

};

#endif // PNACONTROLLER_H
