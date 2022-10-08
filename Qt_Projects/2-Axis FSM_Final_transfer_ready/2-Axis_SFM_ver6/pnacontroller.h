#ifndef PNACONTROLLER_H
#define PNACONTROLLER_H

#include <QtCore>
#include <QTcpSocket>
#include <QtGlobal>
#include <QtGui>
#include <QDebug>
#include "structDef.h"
#include <QAxObject>
#include <QUuid>
#include <QFileDialog>
#include <fstream>
#include <sstream>
#include <QMessageBox>

#import "C:\\MaterialsMeas.tlb" no_namespace, named_guids

//#define XFRDATAMAXRES

#ifdef XFRDATAMAXRES
#define XFRDATATYPE double
const QString dataSettingSCPI = "format:data real,64;";
#endif

#ifndef XFRDATAMAXRES
#define XFRDATATYPE float
const QString dataSettingSCPI = "format:data real,32;";
#endif
using namespace std;

class pnaController : public QObject
{
    Q_OBJECT
public:
    explicit pnaController(structSetting * settingInfoPtrArg=NULL);
    ~pnaController();

public slots:
    void doS11MeasSCPI(uint waveformNumber=0);
    void configS11MeasSCPI(bool isImmediateMeasArg=true);
    void doMeasureN1500A(uint curScanPt=0, bool isScanInProgress=false);
    void configN1500A(bool isImmediateMeasArg=true);
    void selectMeasN1500A(int selectMeas = 0);
    void show();
    void hide();
    void savePointData(void);

private:
    QTcpSocket* tcpSocketMain;
    QTcpSocket* tcpSocketControl;
    QByteArray id;
    QElapsedTimer eTimer;
    int controlPortNum;
    XFRDATATYPE *dataMeasMem; // for PNA access via SCPI
    structSetting * settingInfoPtr;
    QTimer *mainTimer;
    bool isImmediateMeas;
    QAxObject *comObjectTransLine;
    ITransmissionLine *pITransLine;
    structMeas *pMeas;
    float *slectedMeas;
    bool data1DSaved;

    void initSetupSCPI();
    void setupTriggerSCPI(bool ExtTrg=true);
    void setupMeasrementsSCPI();
    void initN1500A();



    QByteArray pnaResponseSCPI(QTcpSocket *tcpSocket=NULL);
    QByteArray sendSCPItoPna(QString cmdStr, QTcpSocket *tcpSocket=NULL);
    QByteArray readDataSCPI(QTcpSocket* tcpSocket, XFRDATATYPE *data=NULL);

signals:
    void updateProgressBar_pnaControllerSignal(int Percentage);
    void updateStatusBar_pnaControllerSignal(QString StatusTip);
    void newWfmReadyForCopy(structMeas *pMeas,int curScanPt);
    void scanFinished(int);
    void updatePlotOsci(float *,QString, float *);
};

#endif // PNACONTROLLER_H
