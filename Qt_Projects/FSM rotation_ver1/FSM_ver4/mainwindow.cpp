#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    pnaProc = NULL;

    ui->setupUi(this);

    this->setWindowTitle(QStringLiteral("Scanning Free-Space Measurement System"));
    // hide the features not required
    ui->groupBoxFilter->hide();
    ui->groupBoxVtwam->hide();
    ui->pushButtonEnlarge->hide();
    ui->pushButtonEnlarge->hide();
    ui->groupBox_1->setVisible(false);

    //progress bar
    ui->statusBar->addPermanentWidget(ui->progressBar,0);
    ui->progressBar->hide();
    ui->progressBar->setTextVisible(false);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);

    //hide&seek
    ui->menuBar->hide();
    progDataPath = "C:\\FSM_Data";
    //Combo boxes
    LoadComboBoxLists();

    InitSettingPars(); // The init settings should be loaded from the last settings used.
#ifdef ACTUALSYSTEM
    //Isntantiate different controllers
    //stage
    stageProc = new stageController((structSetting *)&settingInfo);
    connect(ui->pushButtonServoStop, SIGNAL(pressed()),stageProc->hstageProc,SLOT(stop()));
    connect(ui->pushButtonServoStop, SIGNAL(pressed()),stageProc->vstageProc,SLOT(stop()));
    connect(ui->pushButtonServoStop, SIGNAL(pressed()),stageProc,SLOT(stopScan()));

    connect(ui->pushButtonServoStop2, SIGNAL(pressed()),stageProc->hstageProc,SLOT(stop()));
    connect(ui->pushButtonServoStop2, SIGNAL(pressed()),stageProc->vstageProc,SLOT(stop()));
    connect(ui->pushButtonServoStop2, SIGNAL(pressed()),stageProc,SLOT(stopScan()));

    connect(ui->pushButtonServoKill, SIGNAL(pressed()),stageProc->hstageProc,SLOT(kill()));

    connect(ui->pushButtonOrigin, SIGNAL(pressed()),stageProc->hstageProc,SLOT(home()));
    connect(ui->pushButtonOrigin, SIGNAL(pressed()),stageProc->vstageProc,SLOT(home()));

    //horizontal Jog connection
    connect(ui->pushButtonJogxp, SIGNAL(pressed()),stageProc->hstageProc,SLOT(jogPlus()));
    connect(ui->pushButtonJogxn, SIGNAL(pressed()),stageProc->hstageProc,SLOT(jogMinus()));
    connect(ui->pushButtonJogxp, SIGNAL(released()),stageProc->hstageProc,SLOT(stop()));
    connect(ui->pushButtonJogxn, SIGNAL(released()),stageProc->hstageProc,SLOT(stop()));

    //Vert Jog connection
    connect(ui->pushButtonJogyp, SIGNAL(pressed()),stageProc->vstageProc,SLOT(jogPlus()));
    connect(ui->pushButtonJogyn, SIGNAL(pressed()),stageProc->vstageProc,SLOT(jogMinus()));
    connect(ui->pushButtonJogyp, SIGNAL(released()),stageProc->vstageProc,SLOT(stop()));
    connect(ui->pushButtonJogyn, SIGNAL(released()),stageProc->vstageProc,SLOT(stop()));

    connect(ui->pushButtonGetpos, SIGNAL(clicked(bool)),stageProc->vstageProc,SLOT(getPos()));
    connect(ui->pushButtonGetpos, SIGNAL(clicked(bool)),stageProc->hstageProc,SLOT(getPos()));

    connect(stageProc->hstageProc,SIGNAL(curPos(QString)),ui->lcdNumberXpos,SLOT(display(QString)));
    connect(stageProc->vstageProc,SIGNAL(curPos(QString)),ui->lcdNumberYpos,SLOT(display(QString)));
    stageProc->hstageProc->getPos();
    stageProc->vstageProc->getPos();

    //pna
    pnaProc = new pnaController((structSetting *)&settingInfo);

#endif
    //plots
    qwtPlotOsc = new Plot(ui->widgetOscilloscope,false,"Measurement Trace",(structSetting *)&settingInfo);
    qwtPlotOsc->setObjectName(QStringLiteral("qwtPlotOsc"));
    qwtPlotOsc->setGeometry(QRect(0, 0, 1000, 370));

    qwtPlotResult = new Plot(ui->widgetResultTime,true,"NULL",(structSetting *)&settingInfo);
    qwtPlotResult->setObjectName(QStringLiteral("qwtPlotResult"));
    qwtPlotResult->setGeometry(QRect(0, 0, 1300, 210));
    qwtPlotResult->updateGeometry();

    //spects
    qwtSpectrogram = new spectrogram(ui->widgettResultSpect,(structSetting *)&settingInfo,0, 0, SPECTBASESIZE+150, SPECTBASESIZE,NULL,1);
    qwtSpectrogram->setObjectName(QStringLiteral("ResultSpectrogram"));

    qwtSpectrogram2 = new spectrogram(ui->widgettResultSpect,(structSetting *)&settingInfo,0, 0, SPECTBASESIZE+150, SPECTBASESIZE,NULL,0);
    qwtSpectrogram2->setObjectName(QStringLiteral("ScreenShotSpectrogram"));

    dataProc    = new dataProcessor((structSetting *)&settingInfo, (structResult *) &resultInfo,
                                    qwtSpectrogram,qwtSpectrogram2,progDataPath,ui->horizontalSliderFrame,ui->labelFrame);
    //timers
    mainTimer = new QTimer(this);
    connect(mainTimer, SIGNAL(timeout()), this, SLOT(incrSlider()));

    //connections
    //pnaProc outgoing Signals
    connect(pnaProc,SIGNAL(updatePlotOsci(float*,QString,float*)),qwtPlotOsc,SLOT(UpdateCurve(float*,QString,float*)));
    connect(pnaProc,SIGNAL(updateProgressBar_pnaControllerSignal(int)),this,SLOT(updateProgressBar_mainwindowSlot(int)));
    connect(pnaProc,SIGNAL(updateStatusBar_pnaControllerSignal(QString)),this,SLOT(updateStatusBar_mainwindowSlot(QString)));
    connect(stageProc,SIGNAL(scanFinished()),this,SLOT(scanFinished_main()));


    //pnaProc Incoming Signals
    connect(ui->pushButtonPnaConfig,SIGNAL(pressed()),this,SLOT(configN1500A()));
    connect(ui->pushButtonPnaMeasure,SIGNAL(pressed()),pnaProc,SLOT(doMeasureN1500A()));

    connect(stageProc,SIGNAL(atNewPointInScan(uint,bool)),pnaProc,SLOT(doMeasureN1500A(uint,bool)));

    //dataproc Incoming Signals
    //controllers
    connect(this,SIGNAL(postProcessingVtwamRequired(QString)),dataProc,SLOT(postProcessingVtwamRequested(QString)));
    connect(this,SIGNAL(postProcessingFilteringRequired()),dataProc,SLOT(postProcessingFilteringRequested()));
    connect(pnaProc,SIGNAL(scanFinished(int)),dataProc,SLOT(scanFinished(int)));
    connect(pnaProc,SIGNAL(newWfmReadyForCopy(structMeas *,int)),dataProc,SLOT(newWfmCopyToArray_slot(structMeas *,int)));
    connect(qwtSpectrogram,SIGNAL(pointToPlot(int)),dataProc,SLOT(plotResultTime(int)));

    //dataproc Outgoing Signals
    connect(dataProc,SIGNAL(updateProgressBar_dataProcessorSignal(int)),this,SLOT(updateProgressBar_mainwindowSlot(int)));
    connect(dataProc,SIGNAL(updateStatusBar_dataProcessorSignal(QString)),this,SLOT(updateStatusBar_mainwindowSlot(QString)));
    connect(dataProc,SIGNAL(updateResultTimePlot(float*, QString,float*)),qwtPlotResult,SLOT(UpdateCurve(float*, QString,float*)));
    connect(dataProc,SIGNAL(measDone()),stageProc,SLOT(setMeasDone_slot()));
    //gui controls
    connect(ui->pushButtonLoadData,SIGNAL(clicked(bool)),dataProc,SLOT(loadData(bool)));
    connect(ui->pushButtonLoadData,SIGNAL(clicked(bool)),this,SLOT(InitAtLoad()));
    connect(ui->pushButtonSaveData,SIGNAL(clicked(bool)),dataProc,SLOT(saveData(bool)));
    connect(ui->pushButtonSaveDataCurrent,SIGNAL(clicked(bool)),dataProc,SLOT(saveDataCur(bool)));


    connect(ui->groupBoxFilter,SIGNAL(toggled(bool)),ui->groupBoxFilterStep1,SLOT(setChecked(bool)));

    connect(ui->horizontalSliderFrame,SIGNAL(valueChanged(int)),dataProc, SLOT(setframeNum(int)));
    //connect(ui->pushButtonCapture, SIGNAL(clicked()),dataProc,SLOT(saveScreenshot()));
    //connect(ui->pushButtonCapture, SIGNAL(clicked()),ui->dial_intensity_2,SLOT(hide()));
    connect(ui->pushButtonSaveMovie, SIGNAL(clicked()),dataProc,SLOT(saveMovie()));

    //result tab
    connect(ui->dial_intensity,SIGNAL(valueChanged(int)),qwtSpectrogram,SLOT(setIntensity(int)));
    connect(ui->horizontalSliderFrame,SIGNAL(valueChanged(int)),qwtPlotResult, SLOT(updateVertMarker(int)));
    connect(ui->horizontalSliderFrame,SIGNAL(mouseMidButton(bool,int)),this, SLOT(updateVtwamInputs(bool,int)));
    ui->dial_intensity_2->hide();
    connect(ui->dial_intensity,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
    connect(ui->pushButtonPlayPause,SIGNAL(toggled(bool)),this, SLOT(playPauseResult(bool)));
    connect(qwtSpectrogram,SIGNAL(placeSlave(int,int)),qwtSpectrogram2,SLOT(placeSlaveslot(int,int)));

    connect(ui->checkBoxGreyscale,SIGNAL(toggled(bool)),this->qwtSpectrogram,SLOT(toggleUWPIGreyScale(bool)));
    connect(ui->checkBoxGreyscale,SIGNAL(toggled(bool)),this->qwtSpectrogram2,SLOT(toggleUWPIGreyScale(bool)));

    enlargeResultDlgn = new DialogEnlarge(this);
    connect(this->enlargeResultDlgn,SIGNAL(finished(int)),this,SLOT(resizeToNormal()));

    connect(enlargeResultDlgn->giveSlider(),SIGNAL(valueChanged(int)),this->qwtSpectrogram,SLOT(updateAxisXY(int)));
    connect(this,SIGNAL(destroyed(QObject*)),this->enlargeResultDlgn,SLOT(close()));
    connect(ui->checkBoxBoostSpeed,SIGNAL(toggled(bool)),dataProc,SLOT(setBoostSpeedEn(bool)));

    connect(dataProc,SIGNAL(declarePlotMemory_sig()),qwtPlotResult,SLOT(decalreMemory()));

    connect(dataProc,SIGNAL(loadDataDone()),SLOT(printDataSpec()));
    connect(ui->enumMeasType,SIGNAL(currentIndexChanged(int)),this,SLOT(UpdateMeasType()));
    connect(ui->enumMeasType,SIGNAL(currentIndexChanged(int)),ui->enumMeasType_2,SLOT(setCurrentIndex(int)));
    connect(ui->enumMeasType,SIGNAL(currentIndexChanged(int)),pnaProc,SLOT(selectMeasN1500A(int)));

    connect(ui->enumMeasType_2,SIGNAL(currentIndexChanged(int)),ui->enumMeasType,SLOT(setCurrentIndex(int)));
    connect(ui->enumMeasType_2,SIGNAL(currentIndexChanged(int)),dataProc,SLOT(selectDisplayBuffer(int)));

    InitSettingPars(); // The init settings should be loaded from the last settings used.
    //update the x-axis of the plots

    qwtPlotResult->updateAxisScale();
    qwtSpectrogram->updateAxisXY();

    #ifdef ACTUALSYSTEM
    pnaProc->configN1500A();
    #endif

    QPalette* palRedText = new QPalette();
    palRedText->setColor(QPalette::ButtonText, Qt::red);
    ui->pushButtonServoStop->setPalette(*palRedText);
    ui->pushButtonServoStop2->setPalette(*palRedText);
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
    delete dataProc;
    delete qwtSpectrogram;
    delete ui;
}

void MainWindow::configN1500A()
{
    UpdateSettingParStruct();
    pnaProc->configN1500A();
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

void MainWindow::InitAtLoad()
{
    connect(ui->dial_intensity,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
    disconnect(ui->dial_intensity_2,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
    ui->dial_intensity_2->hide();
    emit ui->dial_intensity->valueChanged(ui->dial_intensity->value()+1);
    emit ui->dial_intensity->valueChanged(ui->dial_intensity->value()-1);

    ui->enumPlaySpeed->setCurrentIndex(1);
    ui->groupBoxFilter->setChecked(false);
    ui->groupBoxFilterStep1->setChecked(false);
    ui->groupBoxFilterStep2->setChecked(false);
    ui->enumImageFilterIterations->setCurrentIndex(0);
    ui->enumImageFilterIterations_2->setCurrentIndex(0);
    ui->enumImageFilterSize->setCurrentIndex(0);
    ui->enumImageFilterSize_2->setCurrentIndex(0);
    ui->enumImageFilterType->setCurrentIndex(0);
    ui->enumImageFilterType_2->setCurrentIndex(0);
    ui->checkBoxBoostSpeed->setChecked(true);

    ui->checkBoxGreyscale->setChecked(false);

    ui->lineEditVtwamStart->setText("0");
    ui->lineEditVtwamEnd->setText("0");

    // reset the result - time - plot
    this->qwtPlotResult->initPlot();
    this->ui->horizontalSliderFrame->setValue(0);
}

void MainWindow::LoadComboBoxLists()
{
    QStringList listPlaySpeed,listMeasType;

    ui->enumScanInterval->addItem("5");
    ui->enumScanInterval->addItem("10");
    ui->enumScanInterval->addItem("15");
    ui->enumScanInterval->addItem("20");
    ui->enumScanInterval->addItem("25");
    ui->enumScanInterval->addItem("30");
    ui->enumScanInterval->addItem("50");
    ui->enumScanInterval->addItem("60");

    ui->enumMaterials->addItem("Rectangular");
    ui->enumMaterials->addItem("Circular");
    ui->enumMaterials->addItem("Complex");

    ui->enumPnaSweepPoints->addItem("51");
    ui->enumPnaSweepPoints->addItem("201");
    ui->enumPnaSweepPoints->addItem("401");
    ui->enumPnaSweepPoints->addItem("801");

    ui->enumMeasType->addItems(comboMeasType(listMeasType));
    ui->enumMeasType_2->addItems(comboMeasType(listMeasType));


    //result tab
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

}

void MainWindow::InitSettingPars()
{
    ui->dial_intensity_2->setMinimum(1000);
    ui->dial_intensity_2->setMaximum((1<<20)-1);
    ui->dial_intensity_2->setValue(140000);

    ui->dial_intensity->setMinimum(1);
    ui->dial_intensity->setMaximum(200);
    ui->dial_intensity->setValue(50);

    ui->horizontalSliderFrame->setMinimum(0);
    ui->horizontalSliderFrame->setMaximum(settingInfo.PnaSweepPoints-1);
    ui->horizontalSliderFrame->setValue(0);

    ui->enumPlaySpeed->setCurrentIndex(1);

    ui->groupBoxFilter->setChecked(false);
    ui->lineEditVtwamStart->setText("0");
    ui->lineEditVtwamEnd->setText("0");

    ui->groupBoxFilterStep1->setChecked(false);
    ui->groupBoxFilterStep2->setChecked(false);

    ui->labelVtwamStart->setText(" \xC2\xB5s");
    ui->labelVtwamEnd->setText(" \xC2\xB5s");

    ui->lineEditScanHeight->setText("100");
    ui->lineEditScanWidth->setText("100");
    ui->enumScanInterval->setCurrentIndex(0);

    ui->lineEditPnaStartFreq->setText("8.2");
    ui->lineEditPnaStopFreq->setText("12.4");
    ui->enumPnaSweepPoints->setCurrentIndex(3);

    ui->lineEditPnaIFBW->setText("1000");
    ui->lineEditPnaPower->setText("0");

    ui->lineEditPnametalPlateThickness->setText("4");
    ui->lineEditPnasampleThickness->setText("3");
    ui->lineEditPnadistToSample->setText("0");

    UpdateSettingParStruct();

    emit ui->enumMeasType->currentIndexChanged(1);
}

void MainWindow::UpdateMeasType()
{
    settingInfo.selectedMeas            = ui->enumMeasType->currentIndex();
}
void MainWindow::UpdateSettingParStruct()
{
    if(ui->enumMaterials->currentText()== 'Rectangular')
    {
        settingInfo.scanHeight         = ui->lineEditScanHeight->text().toInt();
        settingInfo.scanWidth          = ui->lineEditScanWidth->text().toInt();
        settingInfo.scanInterval       = ui->enumScanInterval->currentText().toFloat();
        settingInfo.xLength            = (settingInfo.scanWidth/settingInfo.scanInterval)+1;
        settingInfo.yLength            = (settingInfo.scanHeight/settingInfo.scanInterval)+1;
        settingInfo.rLength            = 1;
        settingInfo.ScanPoints         = settingInfo.xLength * settingInfo.yLength * settingInfo.rLength ;

        settingInfo.PnaStartFreq       = ui->lineEditPnaStartFreq->text().toFloat() ;
        settingInfo.PnaStopFreq        = ui->lineEditPnaStopFreq->text().toFloat() ;
        settingInfo.PnaSweepPoints     = ui->enumPnaSweepPoints->currentText().toInt() ;

        settingInfo.PnaFreqStepSize    =  (settingInfo.PnaStopFreq  - settingInfo.PnaStartFreq)/settingInfo.PnaSweepPoints;

        settingInfo.PnaIFBW                 = ui->lineEditPnaIFBW->text().toFloat();
        settingInfo.PnaPower                = ui->lineEditPnaPower->text().toFloat();
        settingInfo.PnametalPlateThickness  = ui->lineEditPnametalPlateThickness->text().toFloat();
        settingInfo.PnadistToSample         = ui->lineEditPnadistToSample->text().toFloat();
        settingInfo.PnasampleThickness      = ui->lineEditPnasampleThickness->text().toFloat();
        settingInfo.selectedMeas            = ui->enumMeasType->currentIndex();
    }

    else if (ui->enumMaterials->currentText()== 'Circular')
    {
        settingInfo.Radius             = ui->lineEditRadius->text().toInt();
        settingInfo.ArcLength          = ui->lineEditArcLength->tex().toFloat();
        settingInfo.ScanDegree         = (settingInfo.ArcLength/settingInfo.Radius)*57.30;
        settingInfo.scanWidth          = ui->lineEditScanWidth->text().toInt();
        settingInfo.scanInterval       = ui->enumScanInterval->currentText().toFloat();
        settingInfo.xLength            = (settingInfo.scanWidth/settingInfo.scanInterval)+1;
        settingInfo.yLength            = 1;
        settingInfo.rLength            = (settingInfo.ArcLength/settingInfo.scanInterval)+1;
        settingInfo.ScanPoints         = settingInfo.xLength * settingInfo.yLength * settingInfo.rLength ;
        settingInfo.DegreeInterval     = (settingInfo.ScanDegree/(settingInfo.rLength-1));

        settingInfo.PnaStartFreq       = ui->lineEditPnaStartFreq->text().toFloat() ;
        settingInfo.PnaStopFreq        = ui->lineEditPnaStopFreq->text().toFloat() ;
        settingInfo.PnaSweepPoints     = ui->enumPnaSweepPoints->currentText().toInt() ;

        settingInfo.PnaFreqStepSize    =  (settingInfo.PnaStopFreq  - settingInfo.PnaStartFreq)/settingInfo.PnaSweepPoints;

        settingInfo.PnaIFBW                 = ui->lineEditPnaIFBW->text().toFloat();
        settingInfo.PnaPower                = ui->lineEditPnaPower->text().toFloat();
        settingInfo.PnametalPlateThickness  = ui->lineEditPnametalPlateThickness->text().toFloat();
        settingInfo.PnadistToSample         = ui->lineEditPnadistToSample->text().toFloat();
        settingInfo.PnasampleThickness      = ui->lineEditPnasampleThickness->text().toFloat();
        settingInfo.selectedMeas            = ui->enumMeasType->currentIndex();
    }
    else if (ui->enumMaterials->currentText()== 'Complex')
    {
        settingInfo.Radius             = ui->lineEditRadius->text().toInt();
        settingInfo.ArcLength          = ui->lineEditArcLength->tex().toFloat();
        settingInfo.ScanDegree         = (settingInfo.ArcLength/settingInfo.Radius)*57.30;
        settingInfo.scanHeight         = ui->lineEditScanHeight->text().toInt();
        settingInfo.scanWidth          = ui->lineEditScanWidth->text().toInt();
        settingInfo.scanInterval       = ui->enumScanInterval->currentText().toFloat();
        settingInfo.xLength            = (settingInfo.scanWidth/settingInfo.scanInterval)+1;
        settingInfo.yLength            = (settingInfo.scanHeight/settingInfo.scanInterval)+1;
        settingInfo.rLength            = (settingInfo.ArcLength/settingInfo.scanInterval)+1;
        settingInfo.DegreeInterval     = (settingInfo.ScanDegree/(settingInfo.rLength-1));
        settingInfo.ScanPoints         = settingInfo.xLength * settingInfo.yLength * settingInfo.rLength;

        settingInfo.PnaStartFreq       = ui->lineEditPnaStartFreq->text().toFloat() ;
        settingInfo.PnaStopFreq        = ui->lineEditPnaStopFreq->text().toFloat() ;
        settingInfo.PnaSweepPoints     = ui->enumPnaSweepPoints->currentText().toInt() ;

        settingInfo.PnaFreqStepSize    =  (settingInfo.PnaStopFreq  - settingInfo.PnaStartFreq)/settingInfo.PnaSweepPoints;

        settingInfo.PnaIFBW                 = ui->lineEditPnaIFBW->text().toFloat();
        settingInfo.PnaPower                = ui->lineEditPnaPower->text().toFloat();
        settingInfo.PnametalPlateThickness  = ui->lineEditPnametalPlateThickness->text().toFloat();
        settingInfo.PnadistToSample         = ui->lineEditPnadistToSample->text().toFloat();
        settingInfo.PnasampleThickness      = ui->lineEditPnasampleThickness->text().toFloat();
        settingInfo.selectedMeas            = ui->enumMeasType->currentIndex();
    }
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

    resultInfo.vtwamStartFr          = ui->lineEditVtwamStart->text().toInt();
    resultInfo.vtwamEndFr            = ui->lineEditVtwamEnd->text().toInt();

    //resultInfo.vtwamStartFr          = settingInfo.SamplingFreq * ui->lineEditVtwamStart->text().toFloat();
    //resultInfo.vtwamEndFr            = settingInfo.SamplingFreq * ui->lineEditVtwamEnd->text().toFloat();

    //settingInfo.PnaStartFreq+ (double)frameNum_arg/settingInfoPtr->PnaFreqStepSize
}

void MainWindow::on_actionAbout_triggered()
{
    //QMessageBox msgBox(QMessageBox::about, tr("Memory Error"),tr("dataProcessor::scanFinished - wfmPtr = NULL"));
    QMessageBox::about(this, trUtf8("About"), trUtf8("Full Field Pulse Echo Ultrasonic Propogation Imaging Data Viwer (ver1.0) \n "
                                                     "by Opto-Electro-Structural-Lab KAIST"));
    //msgBox.exec();
    return;
}

void MainWindow::printDataSpec()
{
    QString label;
    label.sprintf("Height = %d mm, Width = %d mm, Interval = %0.2f mm, Length = %d Samples",
                  settingInfo.scanHeight,settingInfo.scanWidth,settingInfo.scanInterval,settingInfo.PnaSweepPoints);
    ui->labelCurrentDataSpec->setText(label);
    qwtPlotResult->updateAxisScale();
}

void MainWindow::on_pushButtonStart_clicked()
{
    UpdateSettingParStruct();

    if(dataProc->allocateMem())
    {
        stageProc->startScan();
        pnaProc->hide();
        ui->tabWidget->setCurrentIndex(1);
    }
}
void MainWindow::scanFinished_main()
{
    //stageProc->hstageProc->kill();
    pnaProc->show();
}

void MainWindow::on_enumPnaSweepPoints_currentIndexChanged(int index)
{
   UpdateSettingParStruct();
   //if (pnaProc!=NULL)
    //pnaProc->configS11Meas();
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
    if (curVal >= settingInfo.PnaSweepPoints)
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
    connect(ui->dial_intensity,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
    disconnect(ui->dial_intensity_2,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
    ui->dial_intensity_2->hide();
    dataProc->saveScreenshot();
    emit ui->dial_intensity->valueChanged(ui->dial_intensity->value()+1);
    emit ui->dial_intensity->valueChanged(ui->dial_intensity->value()-1);
}

void MainWindow::on_pushButtonProcessVtwam_clicked()
{
    QString VTWAMtitle = "VTWAM Result("+ui->lineEditVtwamStart->text()+"\xC2\xB5s ~ "+ui->lineEditVtwamEnd->text()+"\xC2\xB5s )";
    this->updateResultParStruct();
   //show the second knob and allocate proper scale
   disconnect(ui->dial_intensity,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
   connect(ui->dial_intensity_2,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensity(int)));
   ui->dial_intensity_2->show();
   emit ui->dial_intensity_2->valueChanged(ui->dial_intensity_2->value()+1);
   emit ui->dial_intensity_2->valueChanged(ui->dial_intensity_2->value()-1);
   emit postProcessingVtwamRequired(VTWAMtitle);
}

void MainWindow::updateVtwamInputs(bool press, int frValue)
{
    //QString timeVal = QString::number(((double)frValue/settingInfo.SamplingFreq) ,'g',3);

    if (press)
    {
        ui->lineEditVtwamStart->setText(QString::number(frValue));
        //ui->lineEditVtwamStart->setText(timeVal);
    }
    else
    {
        ui->lineEditVtwamEnd->setText(QString::number(frValue));
        //ui->lineEditVtwamEnd->setText(timeVal);
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

void MainWindow::on_pushButtonSetpos_released()
{
    bool vretVal = false;
    bool hretVal = false;
    vretVal = stageProc->vstageProc->setPosAbs(ui->lineEditYPos->text().toDouble(),false);
    hretVal = stageProc->hstageProc->setPosAbs(ui->lineEditXPos->text().toDouble(),false);

    if (!vretVal)
    {
        QMessageBox msgBox(QMessageBox::Critical, tr("vStage Error"),tr("Position not set. Please 'origin' and try again."), 0);
        msgBox.exec();
    }
    if (!hretVal)
    {
        QMessageBox msgBox(QMessageBox::Critical, tr("hStage Error"),tr("Position not set. Please 'origin' and try again."), 0);
        msgBox.exec();
    }
}

