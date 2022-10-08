#ifndef VSTAGECONTROLLER_H
#define VSTAGECONTROLLER_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QtSerialPort/QSerialPort>

class vstageController : public QObject
{
    Q_OBJECT
public:
    explicit vstageController();
    ~vstageController();

public slots:
    bool home();
    bool stop();
    bool jogMinus();
    bool jogPlus();
    bool setPosAbs(int posNum, bool isPosCheck = true, int setPosAttempt=0);
    bool setPosRel(float posNum);
    bool ver();
    float getPos();

private:
    void initSerialPort(QSerialPort *serial,QString portName);
    bool rwSerialPort(QString portName, QByteArray data, int waitForEcho, QString *strRsp=NULL, bool verbose=false);
    void delay(int delayTimeMs);
    QString vStageComPort;
    float targetPos;
    QTimer *mainTimer;

signals:
    void curPos(QString);
};

#endif // VSTAGECONTROLLER_H
