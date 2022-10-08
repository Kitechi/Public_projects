#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "structDef.h"
#include "dataProcessor.h"
#include "plot.h"
#include "spectrogram.h"
#include "qtextedit.h"
#include "dialogenlarge.h"
#include <QScrollArea>
#include <QShortcut>
#include "vfw.h"
#include "pnacontroller.h"
#include "stagecontroller.h"

class MySlider: public QSlider
{
    Q_OBJECT
public:
    int xAtpress;
    QFrame *line;
    MySlider(QWidget *parent = 0);
    void mouseReleaseEvent ( QMouseEvent * event );
    void mousePressEvent ( QMouseEvent * event );

signals:
    void mouseMidButton(bool press,int currentVal); // press == 0 ->released
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//Combo Box Dbs
QStringList comboMeasType(QStringList MeasType)
{
    MeasType.append("E_real");
    MeasType.append("E_imag");
    MeasType.append("U_real");
    MeasType.append("U_imag");
    MeasType.append("S11");
    MeasType.append("S21");

    return MeasType;
}

QStringList comboPlaySpeed(QStringList PlaySpeed)
{
    PlaySpeed.append("x1");
    PlaySpeed.append("x2");
    PlaySpeed.append("x4");
    PlaySpeed.append("x8");
    PlaySpeed.append("x16");
    PlaySpeed.append("x32");

    return PlaySpeed;
}

private slots:
    void updateProgressBar_mainwindowSlot(int);

    void endProgressBar_mainwindowSlot();

    void updateStatusBar_mainwindowSlot(QString);

    void playPauseResult(bool play);

    void incrSlider();

    void on_enumPlaySpeed_currentIndexChanged(int index);

    void on_pushButtonProcessFilter_clicked();

//    void updateVtwamInputs(bool press, int frValue);

//    void on_pushButtonProcessVtwam_clicked();

//    void on_groupBoxFilterStep2_toggled(bool arg1);

//    void on_groupBoxFilterStep1_toggled(bool arg1);

    void on_pushButtonCapture_clicked();

    void on_actionAbout_triggered();

    void on_pushButtonEnlarge_clicked();

    void resizeToNormal();

    void printDataSpec();

    void InitAtLoad();

    void on_pushButtonStart_clicked();

    void on_pushButtonSetpos_released();

    void on_enumPnaSweepPoints_currentIndexChanged(int index);

    void scanFinished_main();

    void configN1500A();

    void UpdateSettingParStruct();
    void UpdateMeasType();

    void on_pushButton_set_clicked();

    void on_pushButton_ySet_clicked();

    void on_pushButton_ySet_result_clicked();

    void on_pushButtonScanPause_clicked();

    void on_pushButtonScanPlay_clicked();

private:
    Ui::MainWindow *ui;

    dataProcessor *dataProc;
    Plot *qwtPlotResult,*qwtPlotOsc;
    spectrogram *qwtSpectrogram,*qwtSpectrogram2;

    structSetting settingInfo;
    structResult resultInfo;

    QTimer *mainTimer;
    QString progDataPath;

    DialogEnlarge *enlargeResultDlgn;
    QShortcut *shortcut;

    pnaController* pnaProc;

    stageController* stage;
    setupController* setup;

    short sliderIncVal;

    short scansDone;

    void InitSettingPars();
    void LoadComboBoxLists();
    void updateResultParStruct();



    signals:
    void postProcessingFilteringRequired();
    void postProcessingVtwamRequired(QString);
};

#endif // MAINWINDOW_H
