#ifndef HSTAGECONTROLLER_H
#define HSTAGECONTROLLER_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QTcpSocket>
#include <QMessageBox>
#include "structDef.h"

#define DRIVERNAME          TEXT("Pcomm64.dll")
typedef BOOL( CALLBACK *OPENPMACDEVICE ) ( DWORD dwDevice );
typedef BOOL (CALLBACK *CLOSEPMACDEVICE) ( DWORD dwDevice );
typedef long (CALLBACK * SELECTPMACDEVICE) ( HWND hwnd );
typedef int (CALLBACK *GETRESPONSEA) ( DWORD dwDevice, LPSTR s, UINT maxchar, LPSTR outstr );
typedef int (CALLBACK *GETCONTROLRESPONSEA) ( DWORD dwDevice, LPSTR s, UINT maxchar, CHAR outchar );



class hstageController : public QObject
{
    Q_OBJECT
public:
    explicit hstageController();
    ~hstageController();
    OPENPMACDEVICE DeviceOpen;
    SELECTPMACDEVICE DeviceSelect;
    CLOSEPMACDEVICE DeviceClose;
    GETRESPONSEA DeviceGetResponse;
    GETCONTROLRESPONSEA DeviceGetControlResponse;

public slots:
    void home();
    void stop();
    void kill();
    void jogMinus();
    void jogPlus();
    bool setPosAbs(float posNum, bool isPosCheck=true, int setPosAttempt = 0);
    void setPosRel(float posNum);
    //void ver();
    float getPos();

private:
    void delay(int delayTimeMs);
    unsigned long dwDevice;
    float targetPos;

signals:
    void curPos(QString);
    void updateProgressBar_hstageControllerSignal(int Percentage);
    void updateStatusBar_hstageControllerSignal(QString StatusTip);

};

#endif // STAGECONTROLLER_H
