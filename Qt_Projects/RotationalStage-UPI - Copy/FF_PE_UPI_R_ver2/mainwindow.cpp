#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    scanInfo.enableTT           = false; // true for tt and false for pe-upi
    setSettingStruct();
    ui->setupUi(this);

    this->setWindowTitle(QStringLiteral("Full Field Pulse Echo Ultrasonic Propogation Imaging System "));

    //progress bar
    ui->statusBar->addPermanentWidget(ui->progressBar,0);
    ui->progressBar->hide();
    ui->progressBar->setTextVisible(false);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);

    //hide&seek
    ui->mainToolBar->hide();
    subbandWidget = ui->tabWidget->widget(1);
    ui->lineEditDaqTrigDelay->hide();
    ui->labelTrigDelay->hide();
    ui->labelRefWarning->hide();
    //ui->checkBoxRealTimeMedian->hide();
    ui->lineEditDaqVoltage->hide();
    ui->pushButtonDaqConfig->hide();
    ui->labelScanHeight_2->hide();
    ui->pushButtonLdvAutoFocus_2->hide();

    //Tabwidget
    this->setCentralWidget(ui->tabWidget);

    //ui->tabWidget->removeTab(1); // remove the sub-band tab

    progDataPath = "C:\\FF_PE_UPI_Data";
    //Combo boxes
    LoadComboBoxLists();

    //Isntantiate different controllers
    laser       = new laserController((structScan *)&scanInfo);
    ldv         = new ldvController((structDaq *)&daqInfo);
    daq         = new daqController((structDaq *)&daqInfo,(structScan *)&scanInfo);
    stage       = new stageController((structScan *)&scanInfo);
    rotStage    = new rotStageController((structScan *)&scanInfo);
    filter      = new bandpassController();

    //plots
    qwtPlotOsc = new Plot(ui->widgetOscilloscope,false,"Oscilloscope",(structDaq *)&daqInfo);
    qwtPlotOsc->setObjectName(QStringLiteral("qwtPlotOsc"));
    qwtPlotOsc->setGeometry(QRect(0, 0, 1100, 300));

    qwtPlotResult = new Plot(ui->widgetResultTime,true,NULL,(structDaq *)&daqInfo);
    qwtPlotResult->setObjectName(QStringLiteral("qwtPlotResult"));
    qwtPlotResult->setGeometry(QRect(0, 0, 1300, 210));
    qwtPlotResult->updateGeometry();

    //spects
    qwtSpectrogram = new spectrogram(ui->widgettResultSpect,(structScan *)&scanInfo,0, 0, SPECTBASESIZE+150, SPECTBASESIZE,NULL,1,650,1500);
    qwtSpectrogram->setObjectName(QStringLiteral("ResultSpectrogram"));


    qwtSpectrogram2 = new spectrogram(ui->widgettResultSpect,(structScan *)&scanInfo,0, 0, SPECTBASESIZE+150, SPECTBASESIZE,NULL,0);
    qwtSpectrogram2->setObjectName(QStringLiteral("ScreenShotSpectrogram"));

    for (int i=0;i<NUMOFBANDS;i++)
    {
        /*
        int left = 0,top = 0;
        if (i == 1)
        {
            left = SPECTBASESIZE+150+80;
            top = 0;
        }
        if (i == 2)
        {
            left = 0;
            top = SPECTBASESIZE+50;
        }
        */
        QString name = "Sub-band  " + QString::number(i+1);

        qwtSpectrogramSubband[i] = new spectrogram(ui->widgetSubbandSpect,(structScan *)&scanInfo,
                                                   0,0,SPECTBASESIZE+150,SPECTBASESIZE,name, NUMOFBANDS-1-i,860,1920);

        qwtSpectrogramSubband[i]->setObjectName(name);
        connect(ui->dial_intensity_Subband,SIGNAL(valueChanged(int)),qwtSpectrogramSubband[i],SLOT(setIntensity(int)));
    }

    for (int i=0;i<(NUMOFBANDS-1);i++)
        connect(qwtSpectrogramSubband[i],SIGNAL(placeSlave(int,int,int,int,bool)),qwtSpectrogramSubband[i+1],SLOT(placeSlaveslot(int,int,int,int,bool)));

    dataProc    = new dataProcessor((structDaq *)&daqInfo,(structScan *)&scanInfo, (structResult *) &resultInfo,
                                    qwtSpectrogram,qwtSpectrogram2,progDataPath,qwtSpectrogramSubband,NULL);
    //timers
    mainTimer = new QTimer(this);
    connect(mainTimer, SIGNAL(timeout()), this, SLOT(incrSlider()));

    mainTimerSubband = new QTimer(this);
    connect(mainTimerSubband, SIGNAL(timeout()), this, SLOT(incrSliderSubband()));

    //connections

    //laser
    connect(laser,SIGNAL(updateProgressBar_laserControllerSignal(int)),this,SLOT(updateProgressBar_mainwindowSlot(int)));
    connect(laser,SIGNAL(updateStatusBar_laserControllerSignal(QString)),this,SLOT(updateStatusBar_mainwindowSlot(QString)));

    //dataproc Incoming Signals
    //controllers
    connect(this,SIGNAL(postProcessingVtwamRequired(QString)),dataProc,SLOT(postProcessingVtwamRequested(QString)));
    connect(this,SIGNAL(postProcessingFilteringRequired()),dataProc,SLOT(postProcessingFilteringRequested()));
    connect(daq,SIGNAL(scanFinished(int)),dataProc,SLOT(scanFinished(int)));
    connect(daq,SIGNAL(newWfmReadyForCopy(short *,int)),dataProc,SLOT(newWfmCopyToArray_slot(short *,int)));
    connect(qwtSpectrogram,SIGNAL(pointToPlot(int)),dataProc,SLOT(plotResultTime(int)));

    //dataproc Outgoing Signals
    connect(dataProc,SIGNAL(updateProgressBar_dataProcessorSignal(int)),this,SLOT(updateProgressBar_mainwindowSlot(int)));
    connect(dataProc,SIGNAL(updateStatusBar_dataProcessorSignal(QString)),this,SLOT(updateStatusBar_mainwindowSlot(QString)));
    connect(dataProc,SIGNAL(updateResultTimePlot(short *, QString)),qwtPlotResult,SLOT(UpdateCurve(short *, QString)));
    connect(dataProc,SIGNAL(wfmCopyDone_sig(int)),daq,SLOT(wfmCopyDone(int)));

    //gui controls
    connect(ui->pushButtonLoadData,SIGNAL(clicked(bool)),this,SLOT(loadDataMain(bool)));
    connect(ui->pushButtonSaveData,SIGNAL(clicked(bool)),dataProc,SLOT(saveData(bool)));

    connect(ui->groupBoxFilter,SIGNAL(toggled(bool)),dataProc,SLOT(selectDisplayBuffer(bool)));
    connect(ui->groupBoxFilter,SIGNAL(toggled(bool)),ui->groupBoxFilterStep1,SLOT(setChecked(bool)));

    connect(ui->horizontalSliderFrame,SIGNAL(valueChanged(int)),dataProc, SLOT(setframeNum(int)));
    //connect(ui->pushButtonCapture, SIGNAL(clicked()),dataProc,SLOT(saveScreenshot()));
    //connect(ui->pushButtonCapture, SIGNAL(clicked()),ui->dial_intensity_2,SLOT(hide()));
    connect(ui->pushButtonSaveMovie, SIGNAL(clicked()),dataProc,SLOT(saveMovie()));


    //daq
    connect(daq,SIGNAL(updateProgressBar_daqControllerSignal(int)),this,SLOT(updateProgressBar_mainwindowSlot(int)));
    //connect(daq,SIGNAL(updateStatusBar_daqControllerSignal(QString)),this,SLOT(updateStatusBar_mainwindowSlot(QString)));
    connect(daq,SIGNAL(scanFinished(int )),this,SLOT(scanFinished_main()));
    connect(daq,SIGNAL(updatePlotOsci(short*)),qwtPlotOsc,SLOT(UpdateCurve(short*)));

    //navigator
    connect(ui->pushButtonJogzp,SIGNAL(pressed()),stage, SLOT(JogzpStart()));
    connect(ui->pushButtonJogzn,SIGNAL(pressed()),stage, SLOT(JogznStart()));
    connect(ui->pushButtonJogxp,SIGNAL(pressed()),stage, SLOT(JogxpStart()));
    connect(ui->pushButtonJogxn,SIGNAL(pressed()),stage, SLOT(JogxnStart()));
    connect(ui->pushButtonJogzp,SIGNAL(released()),stage, SLOT(JogzpStop()));
    connect(ui->pushButtonJogzn,SIGNAL(released()),stage, SLOT(JogznStop()));
    connect(ui->pushButtonJogxp,SIGNAL(released()),stage, SLOT(JogxpStop()));
    connect(ui->pushButtonJogxn,SIGNAL(released()),stage, SLOT(JogxnStop()));

    connect(ui->pushButtonOrigin,SIGNAL(clicked(bool)),stage, SLOT(originSet()));
    connect(ui->pushButtonServoStop,SIGNAL(pressed()),this, SLOT(Stop()));
    connect(ui->pushButtonServoStop2,SIGNAL(pressed()),this, SLOT(Stop()));
    connect(ui->pushButtonServoStop3,SIGNAL(pressed()),this, SLOT(Stop()));
    connect(ui->pushButtonGetpos,SIGNAL(pressed()),stage, SLOT(getPosX()));
    connect(ui->pushButtonGetpos,SIGNAL(pressed()),stage, SLOT(getPosZ()));

    connect(ui->pushButtonOriginRot,SIGNAL(clicked(bool)),rotStage, SLOT(home()));
    connect(ui->pushButtonSpinClockWise,SIGNAL(pressed()),rotStage, SLOT(spinClockWise()));
    connect(ui->pushButtonSpinAClockWise,SIGNAL(pressed()),rotStage, SLOT(spinAntiClockWise()));
    connect(ui->pushButtonSpinClockWise,SIGNAL(released()),rotStage, SLOT(stop()));
    connect(ui->pushButtonSpinAClockWise,SIGNAL(released()),rotStage, SLOT(stop()));

    connect(ui->pushButtonRotGetPos,SIGNAL(pressed()),rotStage, SLOT(getPos()));


    connect(stage,SIGNAL(Xpos(QString)),ui->lcdNumberXpos, SLOT(display(QString)));
    connect(stage,SIGNAL(Zpos(QString)),ui->lcdNumberZpos, SLOT(display(QString)));
    connect(rotStage,SIGNAL(pos(QString)),ui->lcdNumberRotPos, SLOT(display(QString)));

    //scan
    connect(ui->lineEditScanRadius,SIGNAL(editingFinished()),this, SLOT(calcPossibleTrigPerRev()));
    connect(ui->enumScanScanSpeedDegPerSec,SIGNAL(currentIndexChanged(int)),this, SLOT(calcScanPars(int)));
    connect(ui->enumScanTrigPerRev,SIGNAL(currentIndexChanged(int)),this, SLOT(calcScanPars(int)));
    connect(rotStage,SIGNAL(revDone(int)),stage,SLOT(moveVerticalStage(int)));
    connect(rotStage,SIGNAL(updateStatusBar_rotStageControllerSignal(QString)),this,SLOT(updateStatusBar_mainwindowSlot(QString)));

    //result tab
    connect(ui->dial_intensity,SIGNAL(valueChanged(int)),qwtSpectrogram,SLOT(setIntensity(int)));
    //connect(ui->horizontalSliderFrame,SIGNAL(valueChanged(int)),ui->labelFrame, SLOT(setNum(int)));
    connect(ui->horizontalSliderFrame,SIGNAL(valueChanged(int)),this, SLOT(setlabelFrame(int)));
    connect(ui->horizontalSliderFrame,SIGNAL(valueChanged(int)),qwtPlotResult, SLOT(updateVertMarker(int)));
    connect(ui->horizontalSliderFrame,SIGNAL(mouseMidButton(bool,int)),this, SLOT(updateVtwamInputs(bool,int)));
    //connect(ui->dial_intensity_2,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
    ui->dial_intensity_2->hide();
    ui->labelVtwamRangeTitle->hide();
    connect(ui->dial_intensity,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
    connect(ui->pushButtonPlayPause,SIGNAL(toggled(bool)),this, SLOT(playPauseResult(bool)));
    connect(qwtSpectrogram,SIGNAL(placeSlave(int,int,int,int,bool)),qwtSpectrogram2,SLOT(placeSlaveslot(int,int,int,int,bool)));

    //subband tab
    connect(ui->horizontalSliderSubband,SIGNAL(valueChanged(int)),dataProc, SLOT(setframeNumSubband(int)));
    connect(ui->horizontalSliderSubband,SIGNAL(valueChanged(int)),this, SLOT(setlabelFrameSubband(int)));
    connect(ui->pushButtonPlayPauseSubband,SIGNAL(toggled(bool)),this, SLOT(playPauseResultSubband(bool)));

    connect(ui->pushButtonCaptureVtwam,SIGNAL(clicked(bool)),dataProc, SLOT(saveScreenshotVtwam()));
    connect(ui->pushButtonCaptureXcor,SIGNAL(clicked(bool)),dataProc, SLOT(saveScreenshotXcor()));

    connect(ui->pushButtonSaveSettings,SIGNAL(pressed()),this,SLOT(saveSetting()));
    connect(ui->pushButtonLoadSettings,SIGNAL(pressed()),this,SLOT(loadSetting()));
    connect(ui->checkBoxGreyscale,SIGNAL(toggled(bool)),this->qwtSpectrogram,SLOT(toggleUWPIGreyScale(bool)));
    connect(ui->checkBoxGreyscale,SIGNAL(toggled(bool)),this->qwtSpectrogram2,SLOT(toggleUWPIGreyScale(bool)));

    connect(dataProc,SIGNAL(setStagePosX(uint,bool)),stage,SLOT(setPosX(uint,bool)));
    connect(dataProc,SIGNAL(setStagePosZ(uint,bool)),stage,SLOT(setPosZ(uint,bool)));

    connect(ldv,SIGNAL(ldvSignalLevel(int)),ui->ldvSignalLevel,SLOT(setValue(int)));

    //connect(ui->enumScanInterval,SIGNAL(currentIndexChanged(int)),this,SLOT(populatePrfList(int)));

    enlargeResultDlgn = new DialogEnlarge(this);
    connect(this->enlargeResultDlgn,SIGNAL(finished(int)),this,SLOT(resizeToNormal()));

    connect(enlargeResultDlgn->giveSlider(),SIGNAL(valueChanged(int)),this->qwtSpectrogram,SLOT(updateAxisXY(int)));
    connect(ui->checkBoxRealTimeMedian,SIGNAL(toggled(bool)),this->dataProc,SLOT(setRlTmMdFlt(bool)));
    connect(this,SIGNAL(destroyed(QObject*)),this->enlargeResultDlgn,SLOT(close()));
    connect(ui->checkBoxBoostSpeed,SIGNAL(toggled(bool)),dataProc,SLOT(setBoostSpeedEn(bool)));
    connect(ui->enumOsciChannel,SIGNAL(currentIndexChanged(int)),this,SLOT(UpdateDaqParStruct()));

    connect(dataProc,SIGNAL(setStagePosRot(float)),rotStage,SLOT(setPos(float)));

    InitSettingPars(); // The init settings should be loaded from the last settings used.
    //update the x-axis of the plots
    UpdateSettingsStruct();
    qwtPlotOsc->updateAxisScale();
    qwtPlotResult->updateAxisScale();
    qwtSpectrogram->updateAxisXY();

    qwtSpectrogramSubband[0]->updateAxisXY();
    /*
    for (int i=0;i<NUMOFBANDS;i++)
    {
        if ((i%2)==0) //only call for Master
            qwtSpectrogramSubband[i]->updateAxisXY();
    }
    */

    isHighRange = false;

#if ACTUALSYSTEM
    QTimer::singleShot(50,this,SLOT(deviceConnect()));
    //Stop();
    stage->resetMovetoX();
    stage->resetMovetoZ();
    stage->clearErrorReset();
    stage->clearServoStop();

    on_pushButtonFilterConfig_pressed();
#endif
}

MainWindow::~MainWindow()
{
#if ACTUALSYSTEM
    //Stop();
#endif

    //wait for more than a second shoulkd servo stop can be reset in the stage
    //Sleep(3000);

    //delete enlargeResultDlgn;
    delete mainTimer;
    delete mainTimerSubband;
    delete laser;
    delete ldv;
    delete daq;
    delete dataProc;
    delete qwtPlotOsc;
    delete qwtSpectrogram;
    delete ui;
}

void MainWindow::setSettingStruct()
{
    settingNumber = 0;

    //0-Broadband
    settingArr[0].ldvRange              = 50;
    settingArr[0].samplingFreq          = 20;
    settingArr[0].chNum                 = 3;
    settingArr[0].trigDelay             = 176;
    settingArr[0].daqVoltage            = 500;

    settingArr[0].filtPar[1].hiPassCut   = 50;
    settingArr[0].filtPar[1].lowPassCut  = 250;
    settingArr[0].filtPar[1].gain        = 25;

    settingArr[0].filtPar[2].hiPassCut   = 250;
    settingArr[0].filtPar[2].lowPassCut  = 1000;
    settingArr[0].filtPar[2].gain        = 25;

    settingArr[0].filtPar[3].hiPassCut   = 1000;
    settingArr[0].filtPar[3].lowPassCut  = 1500;
    settingArr[0].filtPar[3].gain        = 28;


    //1-Narrowband - 1
    settingArr[1].ldvRange              = 10;
    settingArr[1].samplingFreq          = 20;
    settingArr[1].chNum                 = 1;
    settingArr[1].trigDelay             = 304;
    settingArr[1].daqVoltage            = 200;

    settingArr[1].filtPar[1].hiPassCut   = 50;
    settingArr[1].filtPar[1].lowPassCut  = 250;
    settingArr[1].filtPar[1].gain        = 18;

    //2-Narrowband - 2
    settingArr[2].ldvRange              = 20;
    settingArr[2].samplingFreq          = 60;
    settingArr[2].chNum                 = 3;
    settingArr[2].trigDelay             = 560;
    settingArr[2].daqVoltage            = 200;

    settingArr[2].filtPar[1].hiPassCut   = 250;
    settingArr[2].filtPar[1].lowPassCut  = 500;
    settingArr[2].filtPar[1].gain        = 18;

    settingArr[2].filtPar[2].hiPassCut   = 500;
    settingArr[2].filtPar[2].lowPassCut  = 750;
    settingArr[2].filtPar[2].gain        = 18;

    settingArr[2].filtPar[3].hiPassCut   = 750;
    settingArr[2].filtPar[3].lowPassCut  = 1000;
    settingArr[2].filtPar[3].gain        = 18;

    //3-Narrowband - 3
    settingArr[3].ldvRange              = 50;
    settingArr[3].samplingFreq          = 60;
    settingArr[3].chNum                 = 3;
    settingArr[3].trigDelay             = 520;
    settingArr[3].daqVoltage            = 200;

    settingArr[3].filtPar[1].hiPassCut   = 1000;
    settingArr[3].filtPar[1].lowPassCut  = 1160;
    settingArr[3].filtPar[1].gain        = 25;

    settingArr[3].filtPar[2].hiPassCut   = 1160;
    settingArr[3].filtPar[2].lowPassCut  = 1320;
    settingArr[3].filtPar[2].gain        = 25;

    settingArr[3].filtPar[3].hiPassCut   = 1320;
    settingArr[3].filtPar[3].lowPassCut  = 1500;
    settingArr[3].filtPar[3].gain        = 25;

    //4- HighFreq
    settingArr[4].ldvRange              = 200;
    settingArr[4].samplingFreq          = 60;
    settingArr[4].chNum                 = 1;
    settingArr[4].trigDelay             = 264;
    settingArr[4].daqVoltage            = 200;

    settingArr[4].filtPar[1].hiPassCut   = 1500;
    settingArr[4].filtPar[1].lowPassCut  = 2000;
    settingArr[4].filtPar[1].gain        = 22;

    //5-SingleChan-0
    settingArr[5].ldvRange              = 10;
    settingArr[5].samplingFreq          = 20;
    settingArr[5].chNum                 = 1;
    settingArr[5].trigDelay             = 304;
    settingArr[5].daqVoltage            = 500;

    settingArr[5].filtPar[1].hiPassCut   = 50;
    settingArr[5].filtPar[1].lowPassCut  = 250;
    settingArr[5].filtPar[1].gain        = 18;

    //6-SingleChan-1
    settingArr[6].ldvRange              = 20;
    settingArr[6].samplingFreq          = 60;
    settingArr[6].chNum                 = 1;
    settingArr[6].trigDelay             = 576;
    settingArr[6].daqVoltage            = 500;

    settingArr[6].filtPar[1].hiPassCut   = 250;
    settingArr[6].filtPar[1].lowPassCut  = 500;
    settingArr[6].filtPar[1].gain        = 18;

    //7-SingleChan-2
    settingArr[7].ldvRange              = 20;
    settingArr[7].samplingFreq          = 60;
    settingArr[7].chNum                 = 1;
    settingArr[7].trigDelay             = 568;
    settingArr[7].daqVoltage            = 200;

    settingArr[7].filtPar[1].hiPassCut   = 500;
    settingArr[7].filtPar[1].lowPassCut  = 750;
    settingArr[7].filtPar[1].gain        = 18;

    //8-SingleChan-3
    settingArr[8].ldvRange              = 20;
    settingArr[8].samplingFreq          = 60;
    settingArr[8].chNum                 = 1;
    settingArr[8].trigDelay             = 560;
    settingArr[8].daqVoltage            = 500;

    settingArr[8].filtPar[1].hiPassCut   = 750;
    settingArr[8].filtPar[1].lowPassCut  = 1000;
    settingArr[8].filtPar[1].gain        = 18;

    //9-SingleChan-4
    settingArr[9].ldvRange               = 50;
    settingArr[9].samplingFreq           = 60;
    settingArr[9].chNum                  = 1;
    settingArr[9].trigDelay             = 536;
    settingArr[9].daqVoltage            = 200;

    settingArr[9].filtPar[1].hiPassCut   = 1000;
    settingArr[9].filtPar[1].lowPassCut  = 1166;
    settingArr[9].filtPar[1].gain        = 25;

    //10-SingleChan-5
    settingArr[10].ldvRange               = 50;
    settingArr[10].samplingFreq           = 60;
    settingArr[10].chNum                  = 1;
    settingArr[10].trigDelay             = 528;
    settingArr[10].daqVoltage            = 200;

    settingArr[10].filtPar[1].hiPassCut   = 1166;
    settingArr[10].filtPar[1].lowPassCut  = 1332;
    settingArr[10].filtPar[1].gain        = 25;

    //11-SingleChan-6
    settingArr[11].ldvRange               = 50;
    settingArr[11].samplingFreq           = 60;
    settingArr[11].chNum                  = 1;
    settingArr[11].trigDelay             = 520;
    settingArr[11].daqVoltage            = 200;

    settingArr[11].filtPar[1].hiPassCut   = 1332;
    settingArr[11].filtPar[1].lowPassCut  = 1500;
    settingArr[11].filtPar[1].gain        = 25;    
}
void MainWindow::calcPossibleTrigPerRev()
{
    //Calc Possible Scan parameters
    //rotational stage possible intervals according to resolution anf generating integer number of triggers per revolution.
    float resolution = 0.001;
    int resolutionInt = resolution * 1000; // to make the float an int;
    int possibleIntervalDegInt = 0;
    float possibleIntervalDegFloat = 0;
    posRotIntervalArrSz = 0;
    do
    {
        possibleIntervalDegInt +=  resolutionInt;
        if ((360000%possibleIntervalDegInt) == 0) //#define DEGREEINAREV 360 x 1000
        {
            possibleIntervalDegFloat = (float)possibleIntervalDegInt/1000;
            qDebug()<<posRotIntervalArrSz<< possibleIntervalDegFloat;
            posRotIntervalArr[posRotIntervalArrSz++] = possibleIntervalDegFloat;
        }
    }while(possibleIntervalDegInt<100000);

    qDebug()<<"rot stage possible val array initialized"<<posRotIntervalArrSz;

    //try to ascertain the degInterval values resulting as close as possible to the following linear intervals
    float reqLinInterval[NUMOFINTERVALS] = {0.1,0.25,0.5,1,1.5,2.0,5.0,7.5,10.0,20.0,40.0,80.0};
    int radius = ui->lineEditScanRadius->text().toInt();
    float reqRotInterval;
    int i,reqIntervalIndex;
    int minValIndex=0;
    float minDiff = 99999;
    float curDiff=0;
    // change required linear interval to the rotational interval
    //choose the closest values from the possible rotational intervals
    for (reqIntervalIndex = 0; reqIntervalIndex<NUMOFINTERVALS; reqIntervalIndex++)
    {
        reqRotInterval = ((reqLinInterval[reqIntervalIndex] * 360) / (2*M_PI*radius));
        minValIndex = 0;
        minDiff = 99999;
        for (i=0;i<posRotIntervalArrSz;i++)
        {
            curDiff = qFabs(reqRotInterval - (posRotIntervalArr[i]));
            if (minDiff > curDiff)
            {
                minValIndex = i;
                minDiff = curDiff;
            }
        }

        chosenRotInterval[reqIntervalIndex] = posRotIntervalArr[minValIndex];
        chosenTrigPerRev[reqIntervalIndex] = 360/chosenRotInterval[reqIntervalIndex];
        qDebug()<<"chosen rot interval: "<<chosenRotInterval[reqIntervalIndex]<<
                  "chosenTrigPerRev"<<chosenTrigPerRev[reqIntervalIndex];
    }

    ui->enumScanTrigPerRev->clear();

    for (i=0;i<NUMOFINTERVALS;i++)
        ui->enumScanTrigPerRev->addItem(QString::number(chosenTrigPerRev[i]));

    ui->enumScanTrigPerRev->setCurrentIndex(2);

    calcScanPars();
}
void MainWindow::calcScanPars(int trigsPerRevIndex)
{
    QString temp;
    qDebug()<<"MainWindow::calcScanPars";

    int Radius = ui->lineEditScanRadius->text().toInt();
    rotInterval = chosenRotInterval[ui->enumScanTrigPerRev->currentIndex()];

    linInterval  = 2*M_PI*Radius*rotInterval/360;
    linSpeed     = Radius*ui->enumScanScanSpeedDegPerSec->currentText().toInt()*M_PI/180;

    float PRF = linSpeed/linInterval;
    float timePeriod = 1/PRF;
    float pulseWidth = (float)(PULSEWIDTH + 4)/float(1000000) ;// additional pulse due to AC coupling delay of inverter
    int revsInScan = (ui->lineEditScanHeight->text().toFloat()/linInterval)+1;
    float minPerScan = (float)revsInScan * (float)6/ui->enumScanScanSpeedDegPerSec->currentText().toFloat();

    temp  ="Linear Width    : "+QString::number(2*M_PI*Radius)+"mm\n";
    temp +="Linear Interval : "+QString::number(linInterval)+" mm\n";
    temp +="Linear Speed    : "+QString::number(linSpeed)+" mm/sec\n";
    temp +="Rot Interval    : "+QString::number(chosenRotInterval[ui->enumScanTrigPerRev->currentIndex()])+" deg\n";
    temp +="Pulse Rep Freq  : "+QString::number(PRF)+" Hz\n";
    temp +="Trig Duty Cycle : "+QString::number(pulseWidth/timePeriod * (float)100)+" %\n";
    temp +="Time Per Scan   : "+QString::number(minPerScan)+" min";

    ui->labelScanPars->setText(temp);

    /*
    //just to be sure that width/height will be correct
    double width         = 2*M_PI*Radius;
    double x_length      = width/linInterval;

    double height = ui->lineEditScanHeight->text().toFloat();
    double y_length = height/linInterval+1;

    qDebug("Width: %f, x_length: %f,scanInfoPtr->xLengthPreCalc: %d, scanInfoPtr->yLengthPreCalc: %f, scanInfoPtr->yLengthPreCalc: %d",width,scanInfoPtr->xLengthPreCalc, (int)scanInfoPtr->xLengthPreCalc,scanInfoPtr->yLengthPreCalc,(int)scanInfoPtr->yLengthPreCalc);
    */
}

void MainWindow::saveSetting(bool defaultFile)
{
    QFile myfileout;

    QString captureStoragePath = progDataPath + "\\Setting\\";
    QString captureFileName;

    if (defaultFile)
    {
        captureFileName = "LastSettingRotational.bin";
    }
    else
    {
        QDateTime now = QDateTime::currentDateTime();
        captureFileName = "Setting"+now.toString("ddMMyy_hhmmss")+".bin";
    }

    if( QDir(captureStoragePath).exists() == false)
        QDir().mkpath(captureStoragePath);

    myfileout.setFileName(captureStoragePath+captureFileName);

    if(!myfileout.open(QIODevice::WriteOnly))
    {
        QMessageBox errBox;
        errBox.setText("Could not open file for writing.");
        errBox.exec();
        return;
    }
    QDataStream out(&myfileout);
    out.setByteOrder(QDataStream::LittleEndian);

    //Inspection Settings
    out<<ui->checkBoxEnableMultiBand->isChecked();
    out<<ui->enumMultiBandSettingLev1->currentIndex();
    out<<ui->enumMultiBandSettingLev2->currentIndex();

    //Scan
    out<<ui->lineEditScanRadius->text();
    out<<ui->lineEditScanHeight->text();
    out<<ui->enumScanTrigPerRev->currentIndex();
    out<<ui->enumScanScanSpeedDegPerSec->currentIndex();
    out<<ui->enumTotalScans->currentIndex();

    //out<<ui->enumPRF->currentIndex();
    out<<ui->enumCurrent->currentIndex();


    //Navigator
    //press the get pos button
    ui->pushButtonGetpos->pressed();
    out<<QString::number(ui->lcdNumberXpos->value());
    out<<QString::number(ui->lcdNumberZpos->value());
    out<<daqInfo.daqTrigDelay;
/*
    out<<stage->scanStartPosX;
    out<<stage->scanStartPosZ;
*/
    //Data Acquisition
    //out<<ui->radioButtonLowFreq->isChecked();
    //out<<ui->radioButtonMidFreq->isChecked();
    //out<<ui->radioButtonHighFreq->isChecked();

    myfileout.close();

    if (defaultFile == false)
    {
        QMessageBox msgBox(QMessageBox::Information, tr("Scan Setting"),tr("Successfully saved settings in \n")+captureStoragePath+captureFileName, 0, this);
        msgBox.exec();
        return;
    }
}

bool MainWindow::loadSetting(bool defaultFile)
{
    QString FileName;
    QFile myfilein;
    int intTemp;
    float floatTemp;
    bool boolTemp;
    QString stringTemp;

    if (defaultFile)
    {
        FileName = progDataPath + "\\Setting\\LastSettingRotational.bin";
    }
    else
    {
        QFileDialog *fd = new QFileDialog;
        //QTreeView *tree = fd->findChild <QTreeView*>();
        //tree->setRootIsDecorated(true);
        //tree->setItemsExpandable(true);
        fd->setFileMode(QFileDialog::ExistingFile);
        fd->setViewMode(QFileDialog::Detail);
        fd->setDirectory(progDataPath+"\\Setting");
        if (fd->exec())
        {
            FileName = fd->selectedFiles()[0];
            qDebug()<<FileName;
        }
        else
        {
            qDebug()<<"Can't open the Setting file.";
            return false;
        }
    }

    myfilein.setFileName(FileName);

    if(!myfilein.open(QIODevice::ReadOnly))
    {
        //QMessageBox msgBox(QMessageBox::Critical, tr("File Error"),tr("Could'nt open parameter file for data."), 0);
        //msgBox.exec();
        qDebug()<<"Can't open the Setting file.";
        return false;
    }
    QDataStream in(&myfilein);
    in.setByteOrder(QDataStream::LittleEndian);

    // Inspection Settings
    in>>boolTemp;
    ui->checkBoxEnableMultiBand->setChecked(boolTemp);

    in>>intTemp;
    ui->enumMultiBandSettingLev1->setCurrentIndex(intTemp);

    in>>intTemp;
    ui->enumMultiBandSettingLev2->setCurrentIndex(intTemp);

    //Scan
    in>>stringTemp;
    ui->lineEditScanRadius->setText(stringTemp);
    in>>stringTemp;
    ui->lineEditScanHeight->setText(stringTemp);
    in>>intTemp;
    ui->enumScanTrigPerRev->setCurrentIndex(intTemp);
    in>>intTemp;
    ui->enumScanScanSpeedDegPerSec->setCurrentIndex(intTemp);
    in>>intTemp;
    ui->enumTotalScans->setCurrentIndex(intTemp);

   // in>>intTemp;
   // ui->enumPRF->setCurrentIndex(intTemp);
    in>>intTemp;
    ui->enumCurrent->setCurrentIndex(intTemp);

    //Navigator
    //press the get pos button
    //ui->pushButtonGetpos->pressed();


    in>>stringTemp;
    ui->lineEditXpos->setText(stringTemp);
    in>>stringTemp;
    ui->lineEditZPos->setText(stringTemp);

    in>>intTemp;
    ui->lineEditDaqTrigDelay->setText(QString::number(intTemp));

    /*
    in>>floatTemp;
    ui->lineEditXpos->setText(QString::number(floatTemp/1000));
    in>>floatTemp;
    ui->lineEditZPos->setText(QString::number(floatTemp/1000));
    */

    //Data Acquisition
    //in>>boolTemp;
    //ui->radioButtonLowFreq->setChecked(boolTemp);
    //in>>boolTemp;
    //ui->radioButtonMidFreq->setChecked(boolTemp);
    //in>>boolTemp;
    //ui->radioButtonHighFreq->setChecked(boolTemp);

    myfilein.close();

    if (defaultFile == false)
    {
        QMessageBox msgBox(QMessageBox::Information, tr("Scan Setting"),tr("Successfully loaded settings from \n ")+FileName, 0, this);
        msgBox.exec();
    }
    return true;
}

void MainWindow::setlabelFrame(int frameNumber)
{

    QString microSec = " \xC2\xB5s";
    QString labelString = "0"+microSec;
    if (daqInfo.SamplingFreq != 0)
        labelString = QString::number(((double)frameNumber/daqInfo.SamplingFreq) ,'g',3)+microSec;
    ui->labelFrame->setText(labelString);
}

void MainWindow::setlabelFrameSubband(int frameNumber)
{
    QString microSec = " \xC2\xB5s";
    QString labelString = "0"+microSec;
    if (daqInfo.SamplingFreq != 0)
        labelString = QString::number(((double)frameNumber/daqInfo.SamplingFreq) ,'g',3)+microSec;
    ui->labelFrameSubband->setText(labelString);
}
void MainWindow::deviceConnect()
{
    QString ldvPortName;
    QString laserComPort;
    QList<QSerialPortInfo> serialPortInfo = QSerialPortInfo::availablePorts();
    int comPortNum;
    if ((comPortNum = serialPortInfo.size()) > 4)
    {
        QMessageBox msgBox(QMessageBox::Critical, tr("Error 03-Connection Error"),tr("More than expected COM ports. Please only connect LDV and laser controller."), 0, this);
        msgBox.exec();
        return;
    }

    laser->srchPortandConnect("COM6",&laserComPort);
    ldv->connectLdv("COM18");

    return;

#if 0
    if (laser->srchPortandConnect("COM8",&laserComPort) == true)
    {
        /*
        foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        {
            if (info.portName() != "COM1" && info.portName() != laserComPort )
            {
                ldvPortName = info.portName();
                if (ldv->connectLdv(ldvPortName) == false)
                {//make an error
                    QMessageBox msgBox(QMessageBox::Critical, tr("Error 03-Connection Error"),tr("LDV not found. Please reconnect and try again."), 0, this);
                    msgBox.exec();
                    return;
                }
                else
                {
                    return;
                }
            }
        }
        */
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Critical, tr("Error 03-Connection Error"),tr("Laser Controller not found. Please reconnect and try again."), 0, this);
        msgBox.exec();
        if (ldv->connectLdv("COM18") == false)
        {
            QMessageBox msgBox(QMessageBox::Critical, tr("Error 03-Connection Error"),tr("LDV not found.Please reconnect and try again."), 0, this);
            msgBox.exec();
        }
        return;
    }
#endif

}

void MainWindow::updateStatusBar_mainwindowSlot(QString StatusTip)
{
    ui->statusBar->showMessage(StatusTip);
}

void MainWindow::updateProgressBar_mainwindowSlot(int Progress)
{
    ui->progressBar->show();
    ui->progressBar->setValue(Progress);
    if (Progress == 100)
    {
        QTimer::singleShot( 500, this, SLOT(endProgressBar_mainwindowSlot() ));
    }
}

void MainWindow::endProgressBar_mainwindowSlot()
{
    ui->progressBar->hide();
}

void MainWindow::populatePrfList(int intervalIndex)
{/*
    ui->enumPRF->clear();
    if (intervalIndex == 0) //0.10
    {
        ui->enumPRF->addItem("1000");
        ui->enumPRF->addItem("1500");
        ui->enumPRF->addItem("2500");
        maxScanRangemm = 300;
    }
    else if (intervalIndex == 1) //0.25
    {
        ui->enumPRF->addItem("400");
        ui->enumPRF->addItem("600");
        ui->enumPRF->addItem("1000");
        ui->enumPRF->addItem("1400");
        ui->enumPRF->addItem("1600");
        maxScanRangemm = 500;
    }
    else if(intervalIndex == 2) //0.50
    {
        ui->enumPRF->addItem("200");
        ui->enumPRF->addItem("300");
        ui->enumPRF->addItem("500");
        ui->enumPRF->addItem("700");
        ui->enumPRF->addItem("800");
        maxScanRangemm = 500;
    }
    else if (intervalIndex == 3) //1.00
    {
        ui->enumPRF->addItem("100");
        ui->enumPRF->addItem("150");
        ui->enumPRF->addItem("350");
        ui->enumPRF->addItem("400");
        maxScanRangemm = 500;
    }

    ui->enumPRF->setCurrentIndex(0);
    on_lineEditScanHeight_editingFinished();
    */
}

void MainWindow::LoadComboBoxLists()
{
    QStringList listScanInterval,listLaserPRF,listLaserCurrent,listPlaySpeed,listMaterials,
            listTotalScans,listRef;
    //scan
    //ui->enumScanInterval->addItems(comboScanInterval(listScanInterval));

    //laser
    ui->enumCurrent->addItems(comboLaserCurrent(listLaserCurrent));
    ui->enumPlaySpeed->addItems(comboPlaySpeed(listPlaySpeed));

    ui->enumImageFilterIterations->addItem("1");
    ui->enumImageFilterIterations->addItem("2");

    ui->enumImageFilterType->addItem("Median");
    ui->enumImageFilterType->addItem("Spatial Avg");

    ui->enumImageFilterSize->addItem("3x3");
    ui->enumImageFilterSize->addItem("5x5");
    ui->enumImageFilterSize->addItem("7x7");

    ui->enumImageFilterIterations_2->addItem("1");
    ui->enumImageFilterIterations_2->addItem("2");

    ui->enumImageFilterType_2->addItem("Median");
    ui->enumImageFilterType_2->addItem("Spatial Avg");

    ui->enumImageFilterSize_2->addItem("3x3");
    ui->enumImageFilterSize_2->addItem("5x5");
    ui->enumImageFilterSize_2->addItem("7x7");

    ui->enumPlaySpeedSubband->addItems(comboPlaySpeed(listPlaySpeed));
    ui->enumTotalScans->addItems(comboTotalScans(listTotalScans));

    //populatePrfList(ui->enumScanInterval->currentIndex());

    ui->enumMultiBandSettingLev2->addItem("Sub-band 1");
    ui->enumMultiBandSettingLev2->addItem("Sub-band 2");
    ui->enumMultiBandSettingLev2->addItem("Sub-band 3");

    ui->enumOsciChannel->addItem("Sub-band 1");
    ui->enumOsciChannel->addItem("Sub-band 2");
    ui->enumOsciChannel->addItem("Sub-band 3");

    for (int i = 5;i<=80;i=i+5)
        ui->enumScanScanSpeedDegPerSec->addItem(QString::number(i));
}

void MainWindow::InitSettingPars()
{
    //toggle to load all the enums
    ui->checkBoxEnableMultiBand->setChecked(0);
    ui->checkBoxEnableMultiBand->setChecked(1);

    //laser
    if (loadSetting(true)==false)
    { //file for the last setting does not exist so set to default initial values
        //ui->enumPRF->setCurrentIndex(6);
        ui->enumCurrent->setCurrentIndex(14);
        //ui->lineEditScanWidth->setText("50");
        ui->lineEditScanHeight->setText("50");
        //ui->enumScanInterval->setCurrentIndex(2);
        ui->lineEditDaqTrigDelay->setText("864");
    }

    ui->labelLaserStatus->setText("Laser Beam: OFF");
    ui->pushButtonLaserControl->setEnabled(false);
    ui->pushButtonLaserControl->setText("Activate");
    ui->pushButtonLaserControl->setStatusTip("Turn-on the laser beam.");

    ui->dial_intensity_2->setMinimum(1000);
    ui->dial_intensity_2->setMaximum((1<<20)-1);
    ui->dial_intensity_2->setValue(140000);

    ui->dial_intensity->setMinimum(1000);
    ui->dial_intensity->setMaximum((1<<15)-1);
    ui->dial_intensity->setValue(5000);

    ui->horizontalSliderFrame->setMinimum(0);
    ui->horizontalSliderFrame->setMaximum(SAMPLESPERPOINT-1);
    ui->horizontalSliderFrame->setValue(0);

    ui->enumPlaySpeed->setCurrentIndex(1);

    ui->groupBoxFilter->setChecked(false);
    ui->lineEditVtwamStart->setText("0");
    ui->lineEditVtwamEnd->setText("0");

    ui->dial_intensity_Subband->setMinimum(1000);
    ui->dial_intensity_Subband->setMaximum(32768);
    ui->dial_intensity_Subband->setValue(5000);

    ui->horizontalSliderSubband->setMinimum(0);
    ui->horizontalSliderSubband->setMaximum(SAMPLESPERPOINT-1);
    ui->horizontalSliderSubband->setValue(0);

    ui->enumPlaySpeedSubband->setCurrentIndex(1);
    //make sure to toggle to hit the toggle slot
    //ui->radioButtonLowFreq->setChecked(true);
    //ui->radioButtonHighFreq->setChecked(false);
    //ui->groupBoxFilter->setChecked(true);

    ui->groupBoxFilterStep1->setChecked(false);
    ui->groupBoxFilterStep2->setChecked(false);

    QPalette* palRedText = new QPalette();
    palRedText->setColor(QPalette::ButtonText, Qt::red);

    ui->pushButtonServoStop->setPalette(*palRedText);
    ui->pushButtonServoStop2->setPalette(*palRedText);
    ui->pushButtonServoStop3->setPalette(*palRedText);

    ui->pushButtonDaqSet->setEnabled(true);

    ui->lineEditDaqVoltage->setText("500");

    UpdateSettingsStruct();

    ui->labelVtwamStart->setText(" \xC2\xB5s");
    ui->labelVtwamEnd->setText(" \xC2\xB5s");

    resultInfo.vtwamRangeNo = -1;

    ui->checkBoxRealTimeMedian->setChecked(true);
    ui->checkBoxRealTimeMedian->setChecked(false);

    maxScanRangemm = 500;
    calcPossibleTrigPerRev();
    stage->setScanStartPos(ui->lineEditXpos->text().toDouble()*1000,ui->lineEditZPos->text().toDouble()*1000);
}

void MainWindow::updateResultParStruct()
{
    resultInfo.filtPass1en          = ui->groupBoxFilterStep1->isChecked();
    resultInfo.filterType           = ui->enumImageFilterType->currentIndex()+1;
    resultInfo.filterRadius         = ui->enumImageFilterSize->currentIndex()+1;
    resultInfo.filterItr            = ui->enumImageFilterIterations->currentIndex()+1;

    resultInfo.filtPass2en           = ui->groupBoxFilterStep2->isChecked();
    resultInfo.filterType2           = ui->enumImageFilterType_2->currentIndex()+1;
    resultInfo.filterRadius2         = ui->enumImageFilterSize_2->currentIndex()+1;
    resultInfo.filterItr2            = ui->enumImageFilterIterations_2->currentIndex()+1;

    //resultInfo.vtwamStartFr          = ui->lineEditVtwamStart->text().toInt();
    //resultInfo.vtwamEndFr            = ui->lineEditVtwamEnd->text().toInt();

    if(resultInfo.vtwamRangeNo > -1)
    {
        resultInfo.vtwamStartFr[resultInfo.vtwamRangeNo]          = qRound(daqInfo.SamplingFreq * ui->lineEditVtwamStart->text().toFloat());
        resultInfo.vtwamEndFr[resultInfo.vtwamRangeNo]            = qRound(daqInfo.SamplingFreq * ui->lineEditVtwamEnd->text().toFloat());
    }
}

void MainWindow::UpdateScanParStruct()
{
    scanInfo.scanHeight         = ui->lineEditScanHeight->text().toFloat();
    scanInfo.scanWidth          = 2*M_PI*ui->lineEditScanRadius->text().toInt();
    scanInfo.scanInterval       = linInterval;
    scanInfo.xLengthPreCalc     = ui->enumScanTrigPerRev->currentText().toInt();
    scanInfo.yLengthPreCalc     = (scanInfo.scanHeight/linInterval)+1;
    //scanInfo.scanWidth        = ui->lineEditScanWidth->text().toFloat();
    //scanInfo.scanInterval     = ui->enumScanInterval->currentText().toFloat();
    scanInfo.Current            = ui->enumCurrent->currentText();
    //scanInfo.PRF                = ui->enumPRF->currentText();
    scanInfo.scansPerInspection = ui->enumTotalScans->currentText().toInt();
    scanInfo.useCurrentResults  = ui->checkBox_useCurrentResults->isChecked();
    //scanInfo.enableTT           = true; //ui->checkBoxTT->isChecked();
}

void MainWindow::UpdateDaqParStruct()
{
    daqInfo.freqMode = 0;
    daqInfo.SamplingFreq    = settingArr[settingNumber].samplingFreq;
    daqInfo.Range           = settingArr[settingNumber].ldvRange;

    //daqInfo.ScanPoints              = ((scanInfo.scanHeight/scanInfo.scanInterval)+1)*((scanInfo.scanWidth/scanInfo.scanInterval)+1);
    daqInfo.ScanPoints              = scanInfo.xLengthPreCalc * scanInfo.yLengthPreCalc;
    daqInfo.subbandDecomp           = settingArr[settingNumber].chNum > 1 ? true: false ; //( ui->checkBoxEnableMultiBand->isChecked() && ;
    daqInfo.totalNumOfScans         = (ui->enumTotalScans->currentText()).toInt();
    if (daqInfo.subbandDecomp)
        daqInfo.chMap                   = 15; // 4 channels
    else
        daqInfo.chMap                   = 1;

    //daqInfo.daqTrigDelay    = ui->lineEditDaqTrigDelay->text().toInt();
    daqInfo.daqTrigDelay    =   settingArr[settingNumber].trigDelay;
    daqInfo.daqVoltage      = settingArr[settingNumber].daqVoltage;
    daqInfo.osciChan        = ui->enumOsciChannel->currentIndex();

    qwtPlotOsc->updateAxisScale();
    qwtPlotResult->updateAxisScale();
    qwtSpectrogram->updateAxisXY();
}

void MainWindow::UpdateSettingsStruct()
{
    UpdateScanParStruct();
    UpdateDaqParStruct();
}

void MainWindow::on_pushButtonLaserControl_toggled(bool checked)
{
    if (checked)
    {
        //ui->statusBar->showMessage("Activating Laser.");
        if(laser->onSHT())
        {
            QString sCurrent;
            QString outText;
            laser->getCurrent(&sCurrent);
            float numberFloat = sCurrent.toFloat()/10;

            ui->pushButtonLaserControl->setText("Deactivate");
            ui->pushButtonLaserControl->setStatusTip("Deactivate the laser beam.");
            outText = "Laser Beam: ON (" + QString::number(numberFloat) + "A)";
            ui->labelLaserStatus->setText(outText );
        }
        else
        {
            laserError();
        }
    }
    else
    {
        //ui->statusBar->showMessage("Deactivating Laser.");
        if(laser->offSHT() )
        {
            ui->labelLaserStatus->setText("Laser Beam: OFF");
            ui->pushButtonLaserControl->setText("Activate");
            ui->pushButtonLaserControl->setStatusTip("Activate the laser beam.");
        }
        else
        {
            laserError();
        }
    }
}

void MainWindow::hiLaserPwrWarning()
{
    QString sCurrent;
    laser->getCurrent(&sCurrent);

    sCurrent.toFloat()/10;
    if ((sCurrent.toFloat()/10)>26.5)
    {
        QMessageBox msgBox(QMessageBox::Warning, tr("Laser Power Warning"),tr("High laser power!!!"), 0, this);
        msgBox.exec();
    }
}

void MainWindow::on_pushButtonLaserConfigPrfCurr_clicked()
{
    UpdateScanParStruct();
    if (laser->initLaserControllerDone == false)
    {// if init was not done then paras will be set as part of init.
        ui->statusBar->showMessage("Initializing the laser and setting parameters.");
        if(laser->initLaserController() == false)
        {
            laserError();
        }
        else
        {
            ui->statusBar->showMessage("Laser has been configured.");
            ui->pushButtonLaserControl->setEnabled(true);
            hiLaserPwrWarning();
        }
    }
    else
    {//set current and PRF separately.
        ui->statusBar->showMessage("Setting laser parameters.");
        if(!( laser->setPRF() && laser->setCurrent() ))
        {
            laserError();
        }
        else
        {
            ui->statusBar->showMessage("Laser has been configured.");
            ui->pushButtonLaserControl->setEnabled(true);
            hiLaserPwrWarning();
        }
    }
}

void MainWindow::laserError()
{
    QMessageBox msgBox(QMessageBox::Critical, tr("Error 03-Connection Error"),tr("Laser controller not found.Please reconnect and try again."), 0, this);
    //msgBox.exec();

    //The laser may have been turned off so make sure to initialize again next time.
    laser->initLaserControllerDone = true;
    ui->pushButtonLaserControl->setEnabled(false);

    ui->labelLaserStatus->setText("Laser Beam: OFF");
    ui->pushButtonLaserControl->setText("Activate");
    ui->pushButtonLaserControl->setStatusTip("Activate the laser beam.");
}

void MainWindow::on_pushButtonLdvAutoFocus_clicked()
{
    if ( ! (ldv->setAutoFocus()) )
    {
        QMessageBox msgBox(QMessageBox::Critical, tr("Error 03-Connection Error"),tr("LDV not found.Please reconnect and try again."), 0, this);
        msgBox.exec();
    }
    else
    {
        ui->statusBar->showMessage("Ldv has been configured.");
    }
}

void MainWindow::setLdvRange()
{
    bool success;
    success = ldv->setRange();

    if ( !(success) )
    {
    //    QMessageBox msgBox(QMessageBox::Critical, tr("Connection Error"),tr("LDV not found.Please reconnect and try again."), 0, this);
      //  msgBox.exec();
    }
    else
    {
        ui->statusBar->showMessage("Ldv has been configured.");
    }
}

void MainWindow::on_lineEditScanHeight_editingFinished()
{
    //ui->lineEditScanHeight->setText(QString::number(boundScanPars(ui->lineEditScanHeight->text().toInt())));
}

float MainWindow::boundScanPars(int enteredPar)
{
    int validPar;

    if(enteredPar >= 10)
    {
        if(enteredPar <= maxScanRangemm)
        {
            if (enteredPar%10 == 0)
                validPar = enteredPar;
            else
                validPar = (10-enteredPar%10) +  enteredPar;
        }
        else
           validPar = maxScanRangemm;
    }
    else
        validPar = 10;

    return validPar;
}


void MainWindow::on_pushButtonSetpos_released()
{
    stage->setPosX(ui->lineEditXpos->text().toDouble()*1000);
    stage->setPosZ(ui->lineEditZPos->text().toDouble()*1000);
}

void MainWindow::on_pushButtonRotSetpos_released()
{
    rotStage->setPos(ui->lineEditRotPos->text().toFloat());
}
void MainWindow::on_lineEditXpos_editingFinished()
{
    double val;
    val = ui->lineEditXpos->text().toDouble();
    ui->lineEditXpos->setText(QString::number(val,'f',2));
}

void MainWindow::on_lineEditZPos_editingFinished()
{
    double val;
    val = ui->lineEditZPos->text().toDouble();
    ui->lineEditZPos->setText(QString::number(val,'f',2));
}


void MainWindow::on_pushButtonInit_clicked()
{
    //stage->originSet();
    on_pushButtonLdvAutoFocus_clicked();
    ui->statusBar->showMessage("Initializing the laser and setting parameters.");
    if(laser->initLaserController() == false)
    {
        laserError();
        return;
    }
    else
    {
        ui->statusBar->showMessage("Laser has been configured.");
        ui->pushButtonLaserControl->setEnabled(true);
    }

    setLdvRange();//ldv->setRange();
    //on_pushButtonLaserConfigPrfCurr_clicked(); // this will automatically initilize the laser if not done so far.

    ui->pushButtonDaqSet->setEnabled(true);
    QTimer::singleShot(6500, this, SLOT(initDoneMsgBox()));

    hiLaserPwrWarning();
}

void MainWindow::initDoneMsgBox()
{
    QMessageBox msgBox(QMessageBox::Information, tr("Scan initialization"),tr("Scan initialization done."), 0, this);
    msgBox.exec();
}

void MainWindow::on_pushButtonLdvAutoFocus_2_clicked()
{
    UpdateSettingsStruct();
    //intentionally switched Height/Width
    stage->markScanArea((unsigned int)scanInfo.scanWidth,(unsigned int)scanInfo.scanHeight,(float)scanInfo.scanInterval);
}
void MainWindow::Stop()
{
    stopPressed = true;
    rotStage->stop();
    stage->setServoStop();
    if (daq->OsciModeEn==false)
        daq->StopAcquisition();
    dataProc->stop();

    on_pushButtonLaserControl_toggled(false);//turn on SHT
    laser->offEXT();

    connect(dataProc,SIGNAL(setStagePosX(uint,bool)),stage,SLOT(setPosX(uint,bool)));
    connect(dataProc,SIGNAL(setStagePosZ(uint,bool)),stage,SLOT(setPosZ(uint,bool)));
#ifdef ACTUALSYSTEM
    daq->Configure(true);//goto oscilo mode
#endif

}

void MainWindow::settingBeforeNewScan()
{
    connect(ui->dial_intensity,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
    disconnect(ui->dial_intensity_2,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
    ui->dial_intensity_2->hide();
    emit ui->dial_intensity->valueChanged(ui->dial_intensity->value()+1);
    emit ui->dial_intensity->valueChanged(ui->dial_intensity->value()-1);

    // reset the result - filter - group box
    ui->enumImageFilterIterations->setCurrentIndex(0);
    ui->enumImageFilterType->setCurrentIndex(0);
    ui->enumImageFilterSize->setCurrentIndex(0);

    ui->enumImageFilterIterations_2->setCurrentIndex(0);
    ui->enumImageFilterType_2->setCurrentIndex(0);
    ui->enumImageFilterSize_2->setCurrentIndex(0);

    ui->groupBoxFilterStep1->setChecked(false);
    ui->groupBoxFilterStep2->setChecked(false);

    ui->groupBoxFilter->setChecked(false);


    // reset the result - time - plot
    this->qwtPlotResult->initPlot();
    this->ui->horizontalSliderFrame->setValue(0);
    this->ui->horizontalSliderSubband->setValue(0);
}

void MainWindow::on_pushButtonDaqSet_clicked()
{
    if (ui->checkBox_useCurrentResults->isChecked())
    {//load all the pars of last scan from file to make sure these settings are all same

    }
    qDebug()<<"\nMainWindow::on_pushButtonDaqSet_clicked *******Starting a new inspection********";
    on_lineEditScanHeight_editingFinished();
    //on_lineEditScanWidth_editingFinished();
    UpdateSettingsStruct();
    scansDone = 0;
    stopPressed = false;

    //on_pushButtonFilterConfig_pressed();
    if(dataProc->allocateMem()) // MEDIANDEBUG
    {
        settingBeforeNewScan();
        saveSetting(true);
#if ACTUALSYSTEM
        disconnect(dataProc,SIGNAL(setStagePosX(uint,bool)),stage,SLOT(setPosX(uint,bool)));
        disconnect(dataProc,SIGNAL(setStagePosZ(uint,bool)),stage,SLOT(setPosZ(uint,bool)));

        if (ui->checkBox_useCurrentResults->isChecked() == true)
        {
            stage->gotoScanStart();
            while(stage->isReadyForRptScan() == false)
                QCoreApplication::processEvents();
        }
        laser->onEXT();
        setLdvRange();//ldv->setRange();
        daq->Configure(false);
        on_pushButtonLaserControl_toggled(true);//turn on SHT
        rotStage->startScan(chosenRotInterval[ui->enumScanTrigPerRev->currentIndex()],
                            ui->enumScanScanSpeedDegPerSec->currentText().toInt(),
                            (scanInfo.scanHeight/linInterval)+1,
                            TRUE);
                                                                                                                                                                                                                               //QThread::msleep(2000);

        /*
         * stage->startScan((float)scanInfo.scanWidth,
                         (float)scanInfo.scanHeight,
                         (float )scanInfo.PRF.toFloat(),
                         (float)scanInfo.scanInterval);
         */
#else
        //daq->Configure(false);
        /*
       //dataProc->scanFinished(100);
       //emit daq->scanFinished(0);
       //dataProc->setframeNum(0);
       */
        rotStage->startScan(chosenRotInterval[ui->enumScanTrigPerRev->currentIndex()],
                            ui->enumScanScanSpeedDegPerSec->currentText().toInt(),
                            (scanInfo.scanHeight/linInterval)+1,
                            TRUE);
#endif
        ui->tabWidget->setCurrentIndex(1);
        printDataSpec();
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Critical, tr("Error 04-Out Of Memory"),tr("Reduce the number of scan points and try again."), 0, this);
        msgBox.exec();
    }
}

void MainWindow::scanFinished_main()
{
    qDebug()<<"MainWindow::scanFinished_main *******Scan finished********\n";
    //go to start position again
    //laser->offSHT();
    ui->checkBox_useCurrentResults->setEnabled(true);
    scansDone++;
#if ACTUALSYSTEM
    on_pushButtonLaserControl_toggled(false);//turn on SHT
    laser->offEXT();  
#endif

    if (scanInfo.scansPerInspection == 1)
        daq->Configure(true);//goto oscilo mode

    // more scans needed
     if (scanInfo.scansPerInspection > 1 && stopPressed == false )
     {
         if (scansDone < scanInfo.scansPerInspection)
         {
             qDebug()<<"MainWindow::on_pushButtonDaqSet_clicked *******Starting a new scan. scansDone:"<<scansDone<<
                       "scanInfo.scansPerInspection"<<scanInfo.scansPerInspection;
             //issue another scan
             //wait for 5 seconds in between the respective scans to allow for stage to return to original position
             /*
             {
                 QElapsedTimer timer;
                 timer.start();
                 while(timer.elapsed()<15000)
                     QCoreApplication::processEvents();
            }*/

             rotStage->home();
             while(stage->isReadyForRptScan() == false)
                 QCoreApplication::processEvents();

            #if ACTUALSYSTEM
                    laser->onEXT();
                    daq->Configure(false);
                    setLdvRange();//ldv->setRange();
                    on_pushButtonLaserControl_toggled(true);//turn on SHT
                    /*
                    stage->startScan((unsigned int)scanInfo.scanWidth,
                                     (unsigned int)scanInfo.scanHeight,
                                     (unsigned int )scanInfo.PRF.toUInt(),
                                     (float)scanInfo.scanInterval,
                                     false);
                    */
                    rotStage->startScan(chosenRotInterval[ui->enumScanTrigPerRev->currentIndex()],
                                        ui->enumScanScanSpeedDegPerSec->currentText().toInt(),
                                        (scanInfo.scanHeight/linInterval)+1,
                                        TRUE);

                    ui->tabWidget->setCurrentIndex(1);
            #else
                    //emit daq->scanFinished(0);

                    //daq->Configure(false);
            #endif

         }
         else
         {
             // trigger rpt scan finished in data processor.
             dataProc->rptScanFinished();
             daq->Configure(true);//goto oscilo mode
             connect(dataProc,SIGNAL(setStagePosX(uint,bool)),stage,SLOT(setPosX(uint,bool)));
             connect(dataProc,SIGNAL(setStagePosZ(uint,bool)),stage,SLOT(setPosZ(uint,bool)));
         }
     }
     else if (scanInfo.useCurrentResults)
     {
         dataProc->rptScanFinished();
         daq->Configure(true);//goto oscilo mode
         connect(dataProc,SIGNAL(setStagePosX(uint,bool)),stage,SLOT(setPosX(uint,bool)));
         connect(dataProc,SIGNAL(setStagePosZ(uint,bool)),stage,SLOT(setPosZ(uint,bool)));
     }
     else
     {
         connect(dataProc,SIGNAL(setStagePosX(uint,bool)),stage,SLOT(setPosX(uint,bool)));
         connect(dataProc,SIGNAL(setStagePosZ(uint,bool)),stage,SLOT(setPosZ(uint,bool)));
     }
}

void MainWindow::on_pushButtonQuit_clicked()
{
    int result;
    QMessageBox msgBox(QMessageBox::Question, tr("Exit"),tr("Do you want to end this session ?"),
                       QMessageBox::Yes|QMessageBox::No);
    result = msgBox.exec();

    if (result ==QMessageBox::No)
    return;

    qDebug()<<"Now turnoff everything.";
    updateStatusBar_mainwindowSlot("Preparing for system turn-off.");

#ifdef ACTUALSYSTEM
    //1-stop the stage.
    Stop();

    {
        QElapsedTimer timer;
        timer.start();
        while(timer.elapsed()<100)
            QCoreApplication::processEvents();
   }

    stage->clearServoStop();

    //stage->setPosX(250000);
    //stage->setPosZ(500000);
    stage->setPosX(0);
    stage->setPosZ(0);


    //stage->clearServoStop();
    //2-take stage to desired position.


    //3-set laser all off.
    laser->offDIO();
    laser->offQS();
#endif

    QCoreApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    //QMessageBox msgBox(QMessageBox::about, tr("Memory Error"),tr("dataProcessor::scanFinished - wfmPtr = NULL"));
    QMessageBox::about(this, trUtf8("About"), trUtf8("Full Field Pulse Echo Ultrasonic Propogation Imaging System (ver2.0) \n "
                                                     "by XNDT"));
    //msgBox.exec();
    return;
}

void MainWindow::on_actionBand_Divider_Scenario_triggered()
{
    QLabel* help=new QLabel();
    help->setWindowTitle("Band Divider Scenario");
    help->setWindowFlags(Qt::Tool); //or Qt::Tool, Qt::Dialog if you like
    help->setPixmap(QPixmap("://images/BandDividerScenario.GIF"));
    help->setScaledContents(true);
    help->show();
}

void MainWindow::on_actionPulse_Energy_Table_triggered()
{
    QLabel* help=new QLabel();
    help->setWindowTitle("Pulse Energy Table");
    help->setWindowFlags(Qt::Tool); //or Qt::Tool, Qt::Dialog if you like
    help->setPixmap(QPixmap("://images/PulseEnergyTableV4.gif"));
    help->show();
}

void MainWindow::on_pushButtonDaqConfig_pressed()
{
    UpdateDaqParStruct();
    daq->Configure(true);
}

void MainWindow::on_checkBoxEnableMultiBand_toggled(bool checked)
{
    ui->enumMultiBandSettingLev1->clear();
    ui->checkBox_useCurrentResults->setChecked(false);
    ui->enumTotalScans->setCurrentIndex(0);
    if (checked == true)
    {
        ui->enumMultiBandSettingLev1->addItem("Broadband");
        ui->enumMultiBandSettingLev1->addItem("Narrowband");
        ui->enumMultiBandSettingLev1->addItem("Highfreq");

        windowLayOutUpdate(true);
    }
    else
    {
        ui->enumMultiBandSettingLev1->addItem("050-250 kHz");
        ui->enumMultiBandSettingLev1->addItem("250-500 kHz");
        ui->enumMultiBandSettingLev1->addItem("500-750 kHz");
        ui->enumMultiBandSettingLev1->addItem("750-1000 kHz");
        ui->enumMultiBandSettingLev1->addItem("1000-1160 kHz");
        ui->enumMultiBandSettingLev1->addItem("1160-1320 kHz");
        ui->enumMultiBandSettingLev1->addItem("1320-1500 kHz");

        windowLayOutUpdate(false);
    }
}

void MainWindow::windowLayOutUpdate(bool isMultiCh)
{
    if (isMultiCh)
    {
        ui->groupBoxMultiScan->hide();
        if (ui->tabWidget->tabText(1) != "Sub-band decomposition")
            ui->tabWidget->insertTab(1,subbandWidget,"Sub-band decomposition");
        ui->enumOsciChannel->clear();
        ui->enumOsciChannel->addItem("Sub-band 1");
        ui->enumOsciChannel->addItem("Sub-band 2");
        ui->enumOsciChannel->addItem("Sub-band 3");
        ui->enumOsciChannel->setCurrentIndex(0);
    }
    else
    {
        ui->groupBoxMultiScan->show();
        if (ui->tabWidget->tabText(1) == "Sub-band decomposition")
            ui->tabWidget->removeTab(1); // remove the sub-band tab
        ui->enumOsciChannel->clear();
        ui->enumOsciChannel->addItem("Sub-band 1");
        ui->enumOsciChannel->setCurrentIndex(0);
    }
}
void MainWindow::on_enumMultiBandSettingLev1_currentIndexChanged(int index)
{
    if (index == 1 && ui->checkBoxEnableMultiBand->isChecked() == true)
       ui->enumMultiBandSettingLev2->show();
    else
       ui->enumMultiBandSettingLev2->hide();
}

void MainWindow::on_pushButtonFilterConfig_pressed()
{
    //ascertain the setting number to use
    if (ui->checkBoxEnableMultiBand->isChecked() == true)
    {
        //the broadBand
        settingNumber = ui->enumMultiBandSettingLev1->currentIndex();

        if (ui->enumMultiBandSettingLev1->currentIndex() == 1)//narrow
            settingNumber = ui->enumMultiBandSettingLev2->currentIndex()+1;

        else if (ui->enumMultiBandSettingLev1->currentIndex() == 2)//hi
            settingNumber = 4;
    }
    else
    {
        settingNumber = ui->enumMultiBandSettingLev1->currentIndex()+5;
    }

    UpdateDaqParStruct();

    windowLayOutUpdate(settingArr[settingNumber].chNum > 1);

    /*
    daqInfo.settingStr = "Number of Bands = "+ QString::number(settingArr[settingNumber].chNum)+
            ", Sample Freq = "+ QString::number(settingArr[settingNumber].samplingFreq)+" MHz"
            ", LDV Range = "+ QString::number(settingArr[settingNumber].ldvRange)+" mm/s/V";
    */
    daqInfo.settingStr.clear();
    for (int chNumber = 1; chNumber<=settingArr[settingNumber].chNum; chNumber++ )
    {
        filter->config(chNumber,settingArr[settingNumber].filtPar[chNumber].gain,
                       settingArr[settingNumber].filtPar[chNumber].hiPassCut,
                       settingArr[settingNumber].filtPar[chNumber].lowPassCut);

        daqInfo.settingStr += "Sub-band " + QString::number(chNumber) +
                " : "+ QString::number(settingArr[settingNumber].filtPar[chNumber].hiPassCut)+" KHz"
                " ~ "+ QString::number(settingArr[settingNumber].filtPar[chNumber].lowPassCut)+" KHz\n";
    }

    setLdvRange();//ldv->setRange();
    daq->Configure(true);

    qDebug()<<daqInfo.settingStr;
    this->ui->labelConfigSetting->setText(daqInfo.settingStr);
    this->ui->labelConfigSettingSubBand->setText(daqInfo.settingStr);
}

void MainWindow::loadDataMain(bool click)
{
    ui->checkBoxEnableMultiBand->setChecked(false);
    //on_pushButtonFilterConfig_pressed();
    dataProc->loadData(click);
    printDataSpec();
    qwtPlotOsc->updateAxisScale();
    qwtPlotResult->updateAxisScale();
}

void MainWindow::printDataSpec()
{
    QString label;
    label.sprintf("Inspection Settings : Height = %0.2f mm, Width = %0.2f mm, Interval = %0.2f mm, Sampling Frequency = %d MHz",
                  scanInfo.scanHeight,scanInfo.scanWidth,scanInfo.scanInterval,daqInfo.SamplingFreq);
    ui->labelCurrentDataSpec->setText(label);
    //qwtPlotResult->updateAxisScale();
}

//-------------------------------------------------Result tab----------------------------------------
#define SPEEDX1INTERVALMS 100
//Spectrogram takes 23~25ms to render. Using fastes 30ms per update to give breathing room to worker threads
//x1->100ms+10ms(overhead)
//x2->50+10ms(overhead)
//x4->25+10ms(overhead)
//anything beyond this will just choke up the timer thread Q since the processing is bottlenecked by the spectrogram update
void MainWindow::playPauseResult(bool play)
{
    sliderIncVal = 1;
    if (play)
    {
       incrSlider();
       if (ui->enumPlaySpeed->currentIndex()<4) // only speed up till X4
       {
           mainTimer->start(SPEEDX1INTERVALMS /(1 << ui->enumPlaySpeed->currentIndex()) );
           sliderIncVal = 1;
       }
       else
       {
           mainTimer->start(SPEEDX1INTERVALMS/4 );
           sliderIncVal = ui->enumPlaySpeed->currentIndex() - 3;
       }


       ui->pushButtonPlayPause->setText("Pause");
       ui->pushButtonPlayPause->setStatusTip("Pause the automatic display of data.");
       ui->pushButtonPlayPause->setChecked(true);
    }
    else
    {
        mainTimer->stop();
        ui->pushButtonPlayPause->setText("Play");
        ui->pushButtonPlayPause->setChecked(false);
        ui->pushButtonPlayPause->setStatusTip("Automatically traverse the data in a frame-wise fashion. ");
    }
}

void MainWindow::incrSlider()
{
    int curVal = ui->horizontalSliderFrame->value();
    curVal += sliderIncVal;
    if (curVal >= SAMPLESPERPOINT)
    {
        //playPauseResult(false);
        curVal = 0;
    }

    ui->horizontalSliderFrame->setValue(curVal);
    /*
    {
        static QElapsedTimer t;
        qDebug()<<"incrSlider: curVal" << curVal <<"sliderIncVal"<<sliderIncVal: <<"Inter increment time: "<<t.elapsed();
        t.start();
    }
    */
}

void MainWindow::on_enumPlaySpeed_currentIndexChanged(int index)
{
    if(ui->pushButtonPlayPause->isChecked()== TRUE)
    {

        playPauseResult(false);
        playPauseResult(true);
/*
        mainTimer->stop();

        mainTimer->start(100/(1 << index ));
*/
    }
}

void MainWindow::on_groupBoxFilterStep1_toggled(bool arg1)
{
    if (arg1==false)
        ui->groupBoxFilterStep1->setChecked(false);//must always have a step 1`
}

void MainWindow::on_groupBoxFilterStep2_toggled(bool arg1)
{
    if (arg1==true)
        ui->groupBoxFilterStep1->setChecked(true);//must always have a step 1`
}

void MainWindow::on_pushButtonProcessFilter_clicked()
{
    //ui->pushButton->setEnabled(false);
    this->updateResultParStruct();
    emit postProcessingFilteringRequired();
}


void MainWindow::on_pushButtonCapture_clicked()
{
    ui->labelVtwamRangeTitle->hide();
    connect(ui->dial_intensity,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
    disconnect(ui->dial_intensity_2,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
    ui->dial_intensity_2->hide();
    dataProc->saveScreenshot();
    emit ui->dial_intensity->valueChanged(ui->dial_intensity->value()+1);
    emit ui->dial_intensity->valueChanged(ui->dial_intensity->value()-1);
}

void MainWindow::on_pushButtonProcessXCor_clicked()
{
    QString tempStr;
    int index = 0;

    ui->labelVtwamRangeTitle->hide();
   //this->updateResultParStruct();
   //show the second knob and allocate proper scale
   disconnect(ui->dial_intensity,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
   connect(ui->dial_intensity_2,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
   ui->dial_intensity_2->show();
   emit ui->dial_intensity_2->valueChanged(ui->dial_intensity_2->value()+1);
   emit ui->dial_intensity_2->valueChanged(ui->dial_intensity_2->value()-1);
   emit ui->dial_intensity_2->setValue(1<<19);
   dataProc->postProcessingXCorRequested();
}

void MainWindow::on_pushButtonProcessVtwam_clicked()
{
    QString VTWAMtitle;
    QString tempStr;
    int index = 0;

    if(resultInfo.vtwamRangeNo == -1)
    {
        //on_pushButtonVtwamAddRange_clicked();
        return;
    }

    VTWAMtitle = "VTWAM Result(";
    do
    {
        if (index>0)
            VTWAMtitle +=",";

        double startTime = (double)resultInfo.vtwamStartFr[index]/(double)daqInfo.SamplingFreq;
        double endTime =   (double)resultInfo.vtwamEndFr[index]/(double)daqInfo.SamplingFreq;

        tempStr.sprintf("%.3f \xC2\xB5s ~ %.3f \xC2\xB5s",startTime,endTime);

        VTWAMtitle += tempStr;
        index++;

    }while(index<=resultInfo.vtwamRangeNo);

    VTWAMtitle +=")";

   //this->updateResultParStruct();
   //show the second knob and allocate proper scale
   disconnect(ui->dial_intensity,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
   connect(ui->dial_intensity_2,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
   ui->dial_intensity_2->show();
   emit ui->dial_intensity_2->valueChanged(ui->dial_intensity_2->value()+1);
   emit ui->dial_intensity_2->valueChanged(ui->dial_intensity_2->value()-1);
   emit postProcessingVtwamRequired(VTWAMtitle);
}

void MainWindow::on_pushButtonVtwamAddRange_clicked()
{
    resultInfo.vtwamRangeNo = (resultInfo.vtwamRangeNo + 1) % MAXVTWAMRANGES;
    this->updateResultParStruct();
    printVtwamInfo();
}

void MainWindow::on_pushButtonVtwamClearRanges_clicked()
{
    resultInfo.vtwamRangeNo = -1;
    ui->labelVtwamInfo->setText("");
    ui->labelVtwamRangeTitle->hide();
}

void MainWindow::printVtwamInfo()
{
    QString label,tempStr;
    double startTime = (double)resultInfo.vtwamStartFr[resultInfo.vtwamRangeNo]/(double)daqInfo.SamplingFreq;
    double endTime = (double)resultInfo.vtwamEndFr[resultInfo.vtwamRangeNo]/(double)daqInfo.SamplingFreq;

    tempStr.sprintf("%.3f \xC2\xB5s ~ %.3f \xC2\xB5s",startTime,endTime);

    if (resultInfo.vtwamRangeNo>0)
        label = ui->labelVtwamInfo->text() + ", " + tempStr + ",";

    else
        label = tempStr;

    ui->labelVtwamInfo->setText(label);
    ui->labelVtwamRangeTitle->show();

    //qwtPlotResult->updateAxisScale();
}

void MainWindow::updateVtwamInputs(bool press, int frValue)
{
    QString timeVal;// = QString::number(((double)frValue/daqInfo.SamplingFreq) ,'g',3);

    timeVal.sprintf("%.3f",((double)frValue/daqInfo.SamplingFreq));

    if (press)
    {
        //ui->lineEditVtwamStart->setText(QString::number(value));
        ui->lineEditVtwamStart->setText(timeVal);
    }
    else
    {
        //ui->lineEditVtwamEnd->setText(QString::number(value));
        ui->lineEditVtwamEnd->setText(timeVal);
    }
}

void MainWindow::on_pushButtonEnlarge_clicked()
{
    enlargeResultDlgn->attachSpect(qwtSpectrogram);

    ui->groupBoxResultControl->setParent(enlargeResultDlgn);
    ui->groupBoxResultControl->move(0,0);
    ui->groupBoxResultControl->showMaximized();

    qwtSpectrogram->enlargeEnabled = TRUE;
    qwtSpectrogram->updateAxisXY(enlargeResultDlgn->giveSlider()->value());
}

void MainWindow::resizeToNormal()
{
    qwtSpectrogram->setParent(ui->widgettResultSpect);
    qwtSpectrogram->enlargeEnabled = FALSE;
    qwtSpectrogram->updateAxisXY();
    qwtSpectrogram->show();

    ui->groupBoxResultControl->setParent(this->ui->widgetResultControl);
    ui->groupBoxResultControl->move(-5,10);
    ui->groupBoxResultControl->show();
}

//-------------------------------------------------Subband tab----------------------------------------
void MainWindow::playPauseResultSubband(bool play)
{
    if (play)
    {
       incrSliderSubband();
       mainTimerSubband->start(50 /(1 << ui->enumPlaySpeed->currentIndex()) );
       ui->pushButtonPlayPauseSubband->setText("Pause");
       ui->pushButtonPlayPauseSubband->setStatusTip("Pause the automatic display of data.");
       ui->pushButtonPlayPauseSubband->setChecked(true);
    }
    else
    {
        mainTimerSubband->stop();
        ui->pushButtonPlayPauseSubband->setText("Play");
        ui->pushButtonPlayPauseSubband->setChecked(false);
        ui->pushButtonPlayPauseSubband->setStatusTip("Automatically traverse the data in a frame-wise fashion. ");
    }
}

void MainWindow::incrSliderSubband()
{
    int curVal = ui->horizontalSliderSubband->value();
    ui->horizontalSliderSubband->setValue(++curVal);
    if (curVal == SAMPLESPERPOINT)
        playPauseResultSubband(false);
}

void MainWindow::on_enumPlaySpeedSubband_currentIndexChanged(int index)
{
    if(ui->pushButtonPlayPauseSubband->isChecked()== TRUE)
    {
        mainTimerSubband->stop();
        mainTimerSubband->start(50/(1 << index ));
    }
}

void MainWindow::on_radioButtonSubband1_toggled(bool checked)
{
    if(checked)
        dataProc->chooseSubband(0);

    //ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_radioButtonSubband2_toggled(bool checked)
{
    if(checked)
        dataProc->chooseSubband(1);

    //ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_radioButtonSubband3_toggled(bool checked)
{
    if(checked)
        dataProc->chooseSubband(2);

    //ui->tabWidget->setCurrentIndex(2);
}
//-------------------------------------------------------------------------------- slider
MySlider::MySlider(QWidget *parent):
QSlider(parent)
{
/* // line beneath the scaleDraw
    line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Raised);
    line->setVisible(false); //not working
*/
}

void MySlider::mousePressEvent ( QMouseEvent * event )
{
    if (event->button() == Qt::MiddleButton)
    {
        qDebug()<<"middle button pressed"<<event->pos().x()<<event->pos().y();
        xAtpress = event->pos().x();

        emit mouseMidButton(1,this->value());
    }
  QSlider::mousePressEvent(event);

}
void MySlider::mouseReleaseEvent ( QMouseEvent * event )
{
    if (event->button() == Qt::MiddleButton)
    {
        qDebug()<<"middle button released"<<event->pos().x()<<event->pos().y();
/*
        //line->setGeometry(QRect(xAtpress, (this->pos().y()), event->pos().x(), (this->pos().y())+5));
        this->line->setGeometry(QRect(xAtpress, 13, event->pos().x(), 13));
        //line->setGeometry(this->rect());
        this->line->setFrameShape(QFrame::HLine);
        this->line->setFrameShadow(QFrame::Sunken);
*/

        emit mouseMidButton(0,this->value());
    }
  QSlider::mouseReleaseEvent(event);
}
