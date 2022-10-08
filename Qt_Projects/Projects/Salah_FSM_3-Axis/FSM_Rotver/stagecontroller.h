#ifndef STAGECONTROLLER_H
#define STAGECONTROLLER_H

#include <QObject>
#include <QCoreApplication>
#include <QtConcurrent/qtconcurrentrun.h>
#include <QThread>
#include "vstageController.h"
#include "hstageController.h"
#include "rotStageController.h"
#include "structDef.h"


class scanner : public QObject
{
    Q_OBJECT
public:
    scanner(hstageController *hstageProcArg,   vstageController *vstageProcArg,rotStageController *rotStageProcArg, structSetting *settingInfoPtrArg);
    ~scanner();

public slots:
    void scan();
    void RHscan();
    void RVscan();
    void LESscan();
    void Zeroscan();
    void setStopScan();
    void setMeasDone();
private:
    hstageController *hstageProc;
    vstageController *vstageProc;
    rotStageController *rotStageProc;
    structSetting *settingInfoPt;
    bool stopScan;
    uint currScanPt;
    bool measDone;

signals:
    void finished(uint);
    void atNewPoint(uint);
};


class stageController : public QObject
{
    Q_OBJECT
public:
    explicit stageController(structSetting * settingInfoPtrArg,QObject *parent = 0);
    ~stageController();
    vstageController* vstageProc;
    rotStageController* rotStageProc;
    hstageController* hstageProc;


private:
    scanner *scannerObj;
    QThread* scannerThread ;
    structSetting * settingInfoPtr;

signals:
    void atNewPointInScan(uint,bool);
    void scanFinished();

public slots:
    void startScan();
    void stopScan();
    void scanFinished(uint pt);
    void atNewPt_slot(uint pt);
    void setMeasDone_slot();
};

#endif // STAGECONTROLLER_H
