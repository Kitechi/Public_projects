#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    pnaProc = NULL;

    ui->setupUi(this);

    MainWindow::makePlot(0);
    this->setWindowTitle(QStringLiteral("Robotics Scanning Free-Space Measurement System"));
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
    //Isntantiate different stage controllers
    stageProc = new stageController((structSetting *)&settingInfo);
    robot       = new robotController((structScan *)&scanInfo);

    //Robot navigator
        connect(ui->pushButtonJogzp,SIGNAL(pressed()),robot, SLOT(Jogzp()));
        connect(ui->pushButtonJogzn,SIGNAL(pressed()),robot, SLOT(Jogzn()));
        connect(ui->pushButtonJogxp,SIGNAL(pressed()),robot, SLOT(Jogxp()));
        connect(ui->pushButtonJogxn,SIGNAL(pressed()),robot, SLOT(Jogxn()));
        connect(ui->pushButtonJogyp,SIGNAL(pressed()),robot, SLOT(Jogyp()));
        connect(ui->pushButtonJogyn,SIGNAL(pressed()),robot, SLOT(Jogyn()));

        connect(ui->pushButtonJogzp,SIGNAL(released()),robot, SLOT(jogStop()));
        connect(ui->pushButtonJogzn,SIGNAL(released()),robot, SLOT(jogStop()));
        connect(ui->pushButtonJogxp,SIGNAL(released()),robot, SLOT(jogStop()));
        connect(ui->pushButtonJogxn,SIGNAL(released()),robot, SLOT(jogStop()));
        connect(ui->pushButtonJogyp,SIGNAL(released()),robot, SLOT(jogStop()));
        connect(ui->pushButtonJogyn,SIGNAL(released()),robot, SLOT(jogStop()));

 //       connect(ui->pushButtonUploadScanGrid,SIGNAL(pressed()),robot, SLOT(uploadScanGrid()));

        connect(ui->pushButtonOrigin,SIGNAL(clicked(bool)),robot, SLOT(home()));
        connect(ui->pushButtonServoStop,SIGNAL(pressed()),this, SLOT(Stop()));
        connect(ui->pushButtonServoStop2,SIGNAL(pressed()),this, SLOT(Stop()));
        connect(ui->pushButtonQuit,SIGNAL(pressed()),this, SLOT(Stop()));
        connect(ui->pushButtonGetpos,SIGNAL(pressed()),robot, SLOT(getPos()));

        connect(robot,SIGNAL(Xpos(QString)),ui->lcdNumberXpos, SLOT(display(QString)));
        connect(robot,SIGNAL(Ypos(QString)),ui->lcdNumberYpos, SLOT(display(QString)));
        connect(robot,SIGNAL(Zpos(QString)),ui->lcdNumberZpos, SLOT(display(QString)));

 //       connect(ui->pushButtonLoadMountPos,SIGNAL(clicked(bool)),robot, SLOT(loadMountPos()));
 //       connect(ui->pushButtonBracketAttachPos,SIGNAL(clicked(bool)),robot, SLOT(bracketAttachPos()));
  //      connect(ui->pushButtonTurnOffPos,SIGNAL(clicked(bool)),robot, SLOT(turnOffPos()));
        connect(ui->checkBoxRobotControllerSelect,SIGNAL(toggled(bool)),robot, SLOT(setIsVcCont(bool)));

    //pna
    pnaProc = new pnaController((structSetting *)&settingInfo);

#endif
    //plots
    qwtPlotOsc = new Plot(ui->widgetOscilloscope,false,"Measurement Trace",(structSetting *)&settingInfo);
    qwtPlotOsc->setObjectName(QStringLiteral("qwtPlotOsc"));
    qwtPlotOsc->setGeometry(QRect(0, 0, 800, 370));

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

    //Load Coordinates and Graphs
    connect(ui->pushButton_LoadCoordinates,SIGNAL(clicked(bool)),this,SLOT(UpdateSettingParStruct()));
    connect(ui->pushButton_LoadCoordinates,SIGNAL(clicked(bool)),dataProc,SLOT(loadCoordinates(bool)));
    connect(dataProc,SIGNAL(loadCoordinatesDone()),SLOT(printCoorSpec()));
    connect(dataProc,SIGNAL(CalcParametersDone()),SLOT(printCenter()));
    //Coordinates Graph Connections
    connect(ui->enumGraphType,SIGNAL(currentIndexChanged(int)),this,SLOT(makePlot(int)));
    connect(ui->checkBoxIA,SIGNAL(toggled(bool)),this,SLOT(AchieveLowIA(bool)));

    //Salah ends

    InitSettingPars(); // The init settings should be loaded from the last settings used.
    //update the x-axis of the plots

    qwtPlotResult->updateAxisScale();
    qwtSpectrogram->updateAxisXY();

    #ifdef ACTUALSYSTEM
    pnaProc->configN1500A();
    #endif

    QPalette* palRedText = new QPalette();
    palRedText->setColor(QPalette::ButtonText, Qt::red);
    ui->pushButtonQuit->setPalette(*palRedText);
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
    ui->checkBoxIA->setChecked(false);

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

    ui->enumMaterialShape->addItem("Rectangular");
    ui->enumMaterialShape->addItem("Cylindrical");
    ui->enumMaterialShape->addItem("Coordinate Based Measurement");

    ui->enumGraphType->addItem("Select_Graph_Type");
    ui->enumGraphType->addItem("Specimen_Coordinates");
    ui->enumGraphType->addItem("Specimen_with_center");
    ui->enumGraphType->addItem("Radius");
    ui->enumGraphType->addItem("Final_IA_overall");
    ui->enumGraphType->addItem("Caliberation_Points");

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

    ui->lineEditScanHeight->setText("200");
    ui->lineEditScanWidth->setText("200");
    ui->lineEditArclength->setText("250");
    ui->lineEditRadius->setText("100");

    ui->enumGraphType->setCurrentIndex(0);
    ui->enumScanInterval->setCurrentIndex(1);
    ui->enumMaterialShape->setCurrentIndex(2);
    if (ui->enumMaterialShape->currentIndex()== 2)
            {
                ui->labelRadius->setText("Radius (mm):");
                ui->labelHeightCoordinates->setText("Z-axis Coordinates");
                ui->lineEditHeightCoordinates->setText("1");
                ui->lineEditRadius->setText("100");
            };

    ui->lineEditPnaStartFreq->setText("8.2");
    ui->lineEditPnaStopFreq->setText("12.4");
    ui->enumPnaSweepPoints->setCurrentIndex(1);

    ui->lineEditPnaIFBW->setText("1000");
    ui->lineEditPnaPower->setText("0");

    ui->lineEditPnametalPlateThickness->setText("4");
    ui->lineEditPnasampleThickness->setText("3");
    ui->lineEditPnadistToSample->setText("0");

    UpdateSettingParStruct();

    emit ui->enumMeasType->currentIndexChanged(1);
    emit ui->enumGraphType->currentIndexChanged(1);

    ui->checkBoxRobotControllerSelect->setChecked(true);
    ui->checkBoxRobotControllerSelect->setChecked(false);
}

void MainWindow::UpdateMeasType()
{
    settingInfo.selectedMeas            = ui->enumMeasType->currentIndex();
}
void MainWindow::UpdateGraphType()
{
    settingInfo.selectedGraph            = ui->enumGraphType->currentIndex();
}
void MainWindow::UpdateSettingParStruct()
{
        settingInfo.scanInterval       = ui->enumScanInterval->currentText().toFloat();
        if(ui->enumMaterialShape->currentIndex() == 0)
        {
            settingInfo.scanWidth          = ui->lineEditScanWidth->text().toInt();
            settingInfo.scanHeight         = ui->lineEditScanHeight->text().toInt();
            settingInfo.yLength            = (settingInfo.scanHeight/settingInfo.scanInterval)+1;
            settingInfo.xLength            = (settingInfo.scanWidth/settingInfo.scanInterval)+1;
            settingInfo.Materialshape      = "Rectangular";

        }
        else if (ui->enumMaterialShape->currentIndex()== 1)
        {
            settingInfo.Radius             = ui->lineEditRadius->text().toInt();
            settingInfo.ArcLength          = ui->lineEditArclength->text().toFloat();
            settingInfo.scanHeight         = ui->lineEditScanHeight->text().toInt();
            settingInfo.scanWidth          = ui->lineEditArclength->text().toInt();
            settingInfo.yLength            = (settingInfo.scanHeight/settingInfo.scanInterval)+1;
            settingInfo.xLength            = (settingInfo.scanWidth/settingInfo.scanInterval)+1;
            settingInfo.ScanDegree         = (settingInfo.ArcLength/settingInfo.Radius)*57.30;
            settingInfo.DegreeInterval     = (settingInfo.ScanDegree/(settingInfo.xLength-1));
            settingInfo.Materialshape      = "Cylindrical";

        }
        else if (ui->enumMaterialShape->currentIndex()== 2)
        {
            settingInfo.ZPoints            = ui->lineEditHeightCoordinates->text().toFloat();
            settingInfo.ArcLength          = ui->lineEditArclength->text().toFloat();
            settingInfo.scanHeight         = ui->lineEditScanHeight->text().toInt();
            settingInfo.scanWidth          = ui->lineEditArclength->text().toInt();
            if (settingInfo.scanHeight%settingInfo.scanInterval==0)
            {
                settingInfo.yLength            = (settingInfo.scanHeight/settingInfo.scanInterval)+1;
            }
            else
            {
                settingInfo.yLength            = (settingInfo.scanHeight/settingInfo.scanInterval)+2;
            }
            if(settingInfo.scanWidth%settingInfo.scanInterval==0)
            {
                settingInfo.xLength            = (settingInfo.scanWidth/settingInfo.scanInterval)+1;
            }
            else
            {
                settingInfo.xLength            = (settingInfo.scanWidth/settingInfo.scanInterval)+2;
            }

            //settingInfo.Materialshape       = "Leading Edge Specimen";
        };

        settingInfo.ScanPoints         = (settingInfo.xLength) * (settingInfo.yLength) ;

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
        settingInfo.selectedGraph           = ui->enumGraphType->currentIndex();


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
void MainWindow::printCoorSpec()
{
    QString label;
    label.sprintf("Height = %d mm, Arc Length = %d mm, ZPoints = %0.2f mm, Length = %d Samples",
                  settingInfo.scanHeight,settingInfo.scanWidth,settingInfo.ZPoints,settingInfo.PnaSweepPoints);
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
void MainWindow::on_enumMaterialShape_currentIndexChanged(int index)
{
    if (ui->enumMaterialShape->currentIndex()== 3)
            {
                ui->labelHeightCoordinates->setText("Z-axis Coordinates");
                ui->lineEditHeightCoordinates->setText("1");
                ui->lineEditRadius->setText("100");
            }
    else
    {
        ui->labelHeightCoordinates->setText("Z-axis Coordinates");
        ui->lineEditHeightCoordinates->setText("1");
    };
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
    structRobTarget target;

       /* target.trans.x = ui->lineEditXpos->text().toDouble();
        target.trans.y = ui->lineEditYPos->text().toDouble();
        target.trans.z = ui->lineEditZPos->text().toDouble();

        //if (ui->lineEditRobAngleTheta->text().toInt() != 0 || ui->lineEditRobAngleTheta->text().toInt() != 0) // some angle needs to be given
        {
            target.transAfterAngle = target.trans;
            specImageProc->eulerToQuaternion(ui->lineEditRobAngleTheta->text().toInt(),ui->lineEditRobAnglePhi->text().toInt(),target.rot);
        }

        robot->moveToTarget(target,(ui->lineEditRobAngleTheta->text().toInt() != 0 || ui->lineEditRobAnglePhi->text().toInt() != 0));*/
}

QString MainWindow::GetFileName()
{
    QString filter = "All File (*.*);; Text File (*.txt);; XML File (*.xml);; STL File (*.stl);; BIN File (*.bin)";
    return QFileDialog::getOpenFileName(this,"open a file","C://",filter);
}

void MainWindow::on_pushButton_CalaculateParameters_clicked()
{
    if(dataProc->loadCoordinatesDone )
    {
        //ui->textBrowserCoor->setText(dataProc->text);
        dataProc->CalculateParameters();
    }
    else
    {
        qWarning() << "Coordinates are not loaded";

        QMessageBox msgBox(QMessageBox::Critical, tr("Error 06-Connection Error"),tr("First load Coordinates"), 0);
        msgBox.exec();
    }
}
void MainWindow::printCenter()
{
    QString X,Y,Center;
    X = QString::number(settingInfo.CenterOfRotation[0],'f',2);
    Y = QString::number(settingInfo.CenterOfRotation[1],'f',2);
    Center = "("+X+","+Y+")";
    ui->label_XValue->setText(Center);
}
void MainWindow::AchieveLowIA(bool check)
{
    settingInfo.AchieveLowIA = check;
}

void MainWindow::makePlot(int x)
{
    // add two new graphs and set their look:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
    ui->customPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->customPlot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    ui->customPlot->addGraph();
    ui->customPlot->graph(2)->setPen(QPen(Qt::red)); // line color red for second graph
    ui->customPlot->graph(2)->setLineStyle(QCPGraph::lsNone);
    ui->customPlot->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    // generate some points of data (y0 for first, y1 for second graph):
    QVector<double> xo(251), yo(251), y1(251);
    for (int i=0; i<251; ++i)
    {
      xo[i] = i;
      yo[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
      y1[i] = qExp(-i/150.0);              // exponential envelope
    }

    // configure right and top axis to show ticks but no labels:
    // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
    ui->customPlot->xAxis2->setVisible(true);
    ui->customPlot->xAxis2->setTickLabels(false);
    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->yAxis2->setTickLabels(false);
    // make left and bottom axes always transfer their ranges to right and top axes:
    //connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    //connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
    // pass data points to graphs:
    if(x==0)
    {

        ui->customPlot->graph(0)->setData(xo, yo);
        ui->customPlot->graph(1)->setData(xo, y1);
        ui->customPlot->xAxis->setLabel("X-Axis [mm]");
        ui->customPlot->yAxis->setLabel("Y-Axis [mm]");
        // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
        ui->customPlot->graph(0)->rescaleAxes();
        // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
        ui->customPlot->graph(1)->rescaleAxes(true);
    }
    else if (x == 1)
    {
        QVector<double> x(settingInfo.xLength), y(settingInfo.xLength),x1(1),y1(1);
        for (int i=0; i<settingInfo.xLength; ++i)
        {
          x[i] = dataProc->Coordinates[0][0][i];
          y[i] = dataProc->Coordinates[0][1][i];
        }
        x1[0]=0;
        y1[0]=0;
        ui->customPlot->graph(0)->setData(x,y);
        ui->customPlot->graph(1)->setData(x1, y1);
        ui->customPlot->xAxis->setLabel("X-Axis [mm]");
        ui->customPlot->yAxis->setLabel("Y-Axis [mm]");
        // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
        ui->customPlot->graph(0)->rescaleAxes();
        // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
        ui->customPlot->graph(1)->rescaleAxes(true);
    }
    else if (x == 2)
    {
        QVector<double> x(settingInfo.xLength), y(settingInfo.xLength),x1(201), y1(201), x2(1),y2(1);
        for (int i=0; i<settingInfo.xLength; ++i)
        {
          x[i] = dataProc->Coordinates[0][0][i];
          y[i] = dataProc->Coordinates[0][1][i];
        }
        x1[0]= settingInfo.CenterOfRotation[0];
        y1[0]= settingInfo.CenterOfRotation[1];
        float a=0,b=0,R=0,theta=0;
        a = settingInfo.CenterOfRotation[0];
        b = settingInfo.CenterOfRotation[1];
        R = dataProc->Coordinates[0][1][dataProc->CentralValue_X]-dataProc->Coordinates[0][1][dataProc->CentralValue_Y];

        for(int i = 0;i<201;i++)
        {
            x1 [i] = R*cos(theta)+a;
            y1 [i] = R*sin(theta)+b;
            theta=theta+M_PI/100;
        }
        x2[0]=a;
        y2[0]=b;

        ui->customPlot->graph(0)->setData(x, y);
        ui->customPlot->graph(1)->setData(x1, y1);
        ui->customPlot->graph(2)->setData(x2, y2);
        ui->customPlot->xAxis->setLabel("X-Axis [mm]");
        ui->customPlot->yAxis->setLabel("Y-Axis [mm]");
        // let the ranges scale themselves so graph 0 fits perfectly in the vis???ible area:
        ui->customPlot->graph(0)->rescaleAxes();
        // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
        ui->customPlot->graph(1)->rescaleAxes(true);
    }
    else if (x == 3)
    {
        QVector<double> x(settingInfo.xLength), y(settingInfo.xLength),x1(1),y1(1);
        for (int i=0; i<settingInfo.xLength; ++i)
        {
          x[i] = i;
          y[i] = dataProc->Radius[0][i];
        }
        x1[0]=0;
        y1[0]=0;
        ui->customPlot->graph(0)->setData(x, y);
        ui->customPlot->graph(1)->setData(x1, y1);
        ui->customPlot->xAxis->setLabel("Number of Points");
        ui->customPlot->yAxis->setLabel("Radius of Curvature [mm]");
        // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
        ui->customPlot->graph(0)->rescaleAxes();
        // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
        ui->customPlot->graph(1)->rescaleAxes(true);
    }
    else if (x == 4)
    {
        QVector<double> x(settingInfo.xLength), y(settingInfo.xLength),x1(1),y1(1);
        for (int i=0; i<settingInfo.xLength; ++i)
        {
          x[i] = i;
          y[i] = dataProc->Final_IA[0][i];
        }
        x1[0]=0;
        y1[0]=0;
        ui->customPlot->graph(0)->setData(x, y);
        ui->customPlot->graph(1)->setData(x1, y1);
        ui->customPlot->xAxis->setLabel("Number of Points");
        ui->customPlot->yAxis->setLabel("Incident Angle [Degree]");
        // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
        ui->customPlot->graph(0)->rescaleAxes();
        // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
        ui->customPlot->graph(1)->rescaleAxes(true);
    }
    else if (x == 5)
    {
        QVector<double> x(settingInfo.xLength), y(settingInfo.xLength),x1(settingInfo.xLength),y1(settingInfo.xLength);
        for (int i=0; i<settingInfo.xLength; ++i)
        {
          x[i] = i;
          y[i] = dataProc->referencePoint[0][i];
          x1[i]=i;
          y1[i]=430;
        }

        ui->customPlot->graph(0)->setData(x, y);
        ui->customPlot->graph(1)->setData(x1, y1);
        ui->customPlot->xAxis->setLabel("Number of Points");
        ui->customPlot->yAxis->setLabel("Distance of scan point from antenna [mm]");
        // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
        ui->customPlot->graph(0)->rescaleAxes();
        // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
        ui->customPlot->graph(1)->rescaleAxes(true);
    }


    // Note: we could have also just called customPlot->rescaleAxes(); instead
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->customPlot->replot();
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

    /*stage->clearServoStop();

    //stage->setPosX(250000);
    //stage->setPosZ(500000);
    stage->setPosX(0);
    stage->setPosZ(0);


    //stage->clearServoStop();
    //2-take stage to desired position.


    //3-set laser all off.
    laser->offDIO();
    laser->offQS();*/
#endif

    QCoreApplication::quit();
}

void MainWindow::Stop()
{
    stopPressed = true;
    robot->stop();
  /*  if (daq->OsciModeEn==false)
        daq->StopAcquisition();
    dataProc->stop();

    on_pushButtonLaserControl_toggled(false);//turn on SHT
    laser->offEXT();

    connect(dataProc,SIGNAL(setStagePosX(uint,bool)),stage,SLOT(setPosX(uint,bool)));
    connect(dataProc,SIGNAL(setStagePosZ(uint,bool)),stage,SLOT(setPosZ(uint,bool)));
#ifdef ACTUALSYSTEM
    daq->Configure(true);//goto oscilo mode
#endif */
    scanInfo.NumOfGenTrig = 10;
    robot->genTrig();
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
