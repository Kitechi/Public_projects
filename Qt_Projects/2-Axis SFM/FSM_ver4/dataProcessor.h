#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#define DATABUFFNUM 4
//for processor thread
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define SORT(a,b) { if ((a)>(b)) SWAP((a),(b)); }
#define SWAP(a,b) { short temp=(a);(a)=(b);(b)=temp; }

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QMessageBox>
#include "structDef.h"
#include "spectrogram.h"
#include <QFileDialog>
#include <QTreeView>
#include <QLabel>
// AVI utilities -- for creating avi files
#include <windows.h>
#include <Vfw.h>
#define WIN32_LEAN_AND_MEAN
#include <pshpack1.h>
#include <poppack.h>

class coreProcessor : public QObject
{
    Q_OBJECT

public:
    coreProcessor(char filtType = 1, char krnlRadius = 1, short **Input = NULL,
                  short **Output = NULL, int x_length = 50, int y_length = 50, int startFrame=0,
                  int endFrame=MAXSAMPLESPERPOINT, unsigned int buffScanPoints = 0, unsigned int * vtwamResult = NULL);
    ~coreProcessor();
    short filtType;
    short krnlRadius;
    int startFrame;
    int endFrame;
    int wvfrmAcquired;
    bool abortThread;

public slots:
    void process();
    void processVtwam();
    void processParallel();
    void updateRowColNumAcquired(int wvfrmAcquiredArg);
    void setAbortThread();

signals:
    void updateProgress(int curFrame,short FilterRadius, short filterType);
    //void errorSignal(QString err);
    void finished();

private:

    short **input;
    short **output;
    int x_length;
    int y_length;
    unsigned int buffScanPoints;
    unsigned int *vtwamResult;

    inline short optMed9(short *p);
    inline short optMed25(short *p);
    inline short optMed49(short *p);

};

class dataProcessor : public QObject
{
    Q_OBJECT
public:
    explicit dataProcessor(structSetting *settingInfoArg, structResult *resultInfoArg,
                           spectrogram* qwtSpectrogramArg, spectrogram* qwtSpectrogram2Arg, QString progDataPathArg,
                           QSlider* sliderFrameArg,QLabel* labelFrameArg);
    ~dataProcessor();
    bool allocateMem();


    //The processing that is applied to the data present in dataBundleProcessed
    bool filtPass1en;
    short filterType;
    short filterRadius;
    short filterItr;
    bool filtPass2en;
    short filterType2;
    short filterRadius2;
    short filterItr2;
    unsigned int buffScanPoints;


public slots:
    void setframeNum(int frameNum_arg);
    void selectDisplayBuffer(int measIndex);
    void postProcessingFilteringRequested();
    void postProcessingVtwamRequested(QString VtwamTitleArg);
    void updateProcProgress(int curframeNum, short FilterRadius=1, short filterType=1);
    void procFinished();
    void saveData(bool status);
    void saveDataCur(bool status);
    void loadData(bool status);
    void plotResultTime(int pointToPlot);
    void saveScreenshot();
    bool isMemValid(float*** dataBundle, int dispBuffIndex, int frameNum , const char* callername,bool isSilent=false);
    void saveMovie();
    void updateResultSpect();
    void parallelprocFinished();
    void saveScreenshotVtwam();
    void stop();
    void procFinishedGather();
    void setBoostSpeedEn(bool val);
    void saveDataSetting();
    void newWfmCopyToArray_slot(structMeas *pMeas, int curScanPt);


private:
    structSetting *settingInfoPtr;
    structResult *resultInfoPtr;
    float*** dataBundle;
    unsigned int* vtwamResult;
    float* screenShotResult;
    //short** dataBundleProcessed;
    short dispBuffIndex;
    bool dataBundleSaved;
    float* resultTimeSig;
    float* f;
    //short** displayFrame; // no memory assigned to this just a pointer

    int frameNum;
    coreProcessor *coreProcObj;
    QThread* procThread ;

    coreProcessor ** coreProcObjArr;
    QThread** procThreadArr ;

    QElapsedTimer timer;
    spectrogram *qwtSpectrogram,*qwtSpectrogram2;

    int buffScanWidth;
    int buffScanHeight;
    float buffScanInterval;
    QString progDataPath;
    bool VtwamProcessing;
    QWidget *screenshotPlace;
    QWidget *VtwamPlace;
    short bufToProcess;
    int threadFinishedCount;
    int totalThreads;
    bool boostSpeedEn;
    bool postProcDone;
    QString VTWAMTitle;
    int PnaSweepPoints;
    QSlider *sliderFramePtr;
    QLabel *labelFramePtr;

    bool alloc2dArray(int rows, int columns, bool allocRptScanBuffOnly=false);
    bool clear2dArray(int rows,int columns,bool clearRptScanBuffOnly=false);
    void startProcThread(short filtType ,short krnlRadius,
                                        short **Input,short **Output,int x_length,int y_length);
    void startVtwamThread(short **Input, unsigned int* result, unsigned int buffScanPoints,int startFrame, int endFrame);

signals:
    void updateProgressBar_dataProcessorSignal(int Percentage);
    void updateStatusBar_dataProcessorSignal(QString StatusTip);
    void updateResultTimePlot(float * y_pt, QString title,float * x_pt);
    void updateRowColNumAcquired_sig(int);
    void abortThread_sig();
    void declarePlotMemory_sig();
    void loadDataDone();
    void measDone();
};

DECLARE_HANDLE(HAVI);
// An HAVI identifies an avi file that is being created
HAVI CreateAvi(const char *fn, int frameperiod, const WAVEFORMATEX *wfx);
HRESULT AddAviFrame(HAVI avi, HBITMAP hbm);
HRESULT CloseAvi(HAVI avi);


#endif // DATAPROCESSOR_H
