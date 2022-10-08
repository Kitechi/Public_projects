#ifndef STAGECONTROLLER_H
#define STAGECONTROLLER_H

#include <QObject>
#include <QCoreApplication>
#include <QtConcurrent/qtconcurrentrun.h>
#include <QThread>
#include "structDef.h"
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QTcpSocket>


class stageController : public QObject
{
    Q_OBJECT
public:
    explicit stageController(structSetting * settingInfoPtrArg);
    ~stageController();
    unsigned int scanStartPosX, scanStartPosZ;
    bool isFirstTime;

private:
    structSetting * settingInfoPtr;
    QTimer *updateTimer;
    bool writePlcMem(short address, unsigned short value);
    bool writePlcMem32(short address, unsigned int value);
    bool readPlcMem(short address, unsigned short *returnVal);
    bool readPlcMem32(short address, unsigned int *returnVal);
    unsigned int IntitialXpos, IntitialZpos;


signals:
    void updateProgressBar_stageControllerSignal(int Percentage);
    void updateStatusBar_stageControllerSignal(QString StatusTip);

    void Xpos(QString);
    void Zpos(QString);

public slots:
    void JogzpStop();
    void JogznStop();
    void JogxpStop();
    void JogxnStop();

    void JogzpStart();
    void JogznStart();
    void JogxpStart();
    void JogxnStart();

    void Jogzp(bool enableJog);
    void Jogzn(bool enableJog);
    void Jogxp(bool enableJog);
    void Jogxn(bool enableJog);

    void originSet(void);
    void originReset(void);

    unsigned int getPosZ();
    unsigned int getPosX();

    void setPosZ(unsigned int, bool relToScanStart=false);
    void setPosX(unsigned int, bool relToScanStart=false);

    bool MoveAbsPosZ(unsigned int);
    bool MoveAbsPosX(unsigned int);

    void MoveToScanPoint(int xPos,int zPos);

    void updatePos();
    void clearErrorReset(void);
    void setErrorReset(void);

    void setMovetoX();
    void setMovetoZ();

    void resetMovetoX();
    void resetMovetoZ();

    void setServoStop(void);
    void clearServoStop(void);

};


class scanner : public QObject
{
    Q_OBJECT
public:
    scanner(structSetting *settingInfoPtrArg);
    ~scanner();

public slots:
    void scan();
    void setStopScan();
    void setMeasDone();

private:
    structSetting *settingInfoPt;
    stageController *stageProc;
    bool stopScan;
    uint currScanPt;
    bool measDone;

signals:
    void finished(uint);
    void atNewPoint(uint);
};


class setupController : public QObject
{
    Q_OBJECT
public:
    explicit setupController(structSetting * settingInfoPtrArg,QObject *parent = 0);
    ~setupController();
    stageController* stageProcA;
    float scanStartPosX,scanStartPosZ;

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
