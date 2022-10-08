#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    pnaProc = NULL;

    ui->setupUi(this);

//    QPixmap pix("C:/Qt/Projects/2-Axis FSM_Final_transfer_ready/2-Axis_SFM_ver6/resources/OERL_k.png");
//    pix.scaled(160,840);
//    ui->label_logo->setPixmap(pix);



    this->setWindowTitle(QStringLiteral("2-Axis Scanning Free-Space Measurement System"));
    // hide the features not required
    ui->pushButtonEnlarge->hide();
    ui->pushButtonEnlarge->hide();

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
    //stage controller
    stage = new stageController((structSetting *)&settingInfo);
    //setup controller
    setup = new setupController((structSetting *)&settingInfo);
    //pna controller
    pnaProc = new pnaController((structSetting *)&settingInfo);


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

    connect(ui->pushButtonServoKill,SIGNAL(pressed()),stage, SLOT(setServoStop()));
    connect(ui->pushButtonServoStop,SIGNAL(pressed()),stage, SLOT(setServoStop()));
    connect(ui->pushButtonServoStop2,SIGNAL(pressed()),stage, SLOT(setServoStop()));

    connect(ui->pushButtonServoKill,SIGNAL(pressed()),setup,SLOT(stopScan()));
    connect(ui->pushButtonServoStop, SIGNAL(pressed()),setup,SLOT(stopScan()));
    connect(ui->pushButtonServoStop2, SIGNAL(pressed()),setup,SLOT(stopScan()));

    connect(ui->pushButtonGetpos,SIGNAL(pressed()),stage, SLOT(getPosX()));
    connect(ui->pushButtonGetpos,SIGNAL(pressed()),stage, SLOT(getPosZ()));

    connect(stage,SIGNAL(Xpos(QString)),ui->lcdNumberXpos, SLOT(display(QString)));
    connect(stage,SIGNAL(Zpos(QString)),ui->lcdNumberZpos, SLOT(display(QString)));

#endif
    //plots
    qwtPlotOsc = new Plot(ui->widgetOscilloscope,false,"Measurement Trace",(structSetting *)&settingInfo);
    qwtPlotOsc->setObjectName(QStringLiteral("qwtPlotOsc"));
    qwtPlotOsc->setGeometry(QRect(0, 0, 750, 400));


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
    connect(setup,SIGNAL(scanFinished()),this,SLOT(scanFinished_main()));

    //pnaProc Incoming Signals
    connect(ui->pushButtonPnaConfig,SIGNAL(pressed()),this,SLOT(configN1500A()));
    connect(ui->pushButtonPnaMeasure,SIGNAL(pressed()),pnaProc,SLOT(doMeasureN1500A()));

    connect(setup,SIGNAL(atNewPointInScan(uint,bool)),pnaProc,SLOT(doMeasureN1500A(uint,bool)));

    //dataproc Incoming Signals
    //controllers
    connect(this,SIGNAL(postProcessingVtwamRequired(QString)),dataProc,SLOT(postProcessingVtwamRequested(QString)));
    connect(this,SIGNAL(postProcessingFilteringRequired()),dataProc,SLOT(postProcessingFilteringRequested()));
    connect(pnaProc,SIGNAL(scanFinished(int)),dataProc,SLOT(scanFinished(int)));
    connect(pnaProc,SIGNAL(newWfmReadyForCopy(structMeas *,int)),dataProc,SLOT(newWfmCopyToArray_slot(structMeas *,int)));
    connect(qwtSpectrogram,SIGNAL(pointToPlot(int)),dataProc,SLOT(plotResultTime(int)));
    connect(qwtSpectrogram,SIGNAL(pointToMove(int, int)),stage,SLOT(MoveToScanPoint(int,int)));

    //dataproc Outgoing Signals
    connect(dataProc,SIGNAL(updateProgressBar_dataProcessorSignal(int)),this,SLOT(updateProgressBar_mainwindowSlot(int)));
    connect(dataProc,SIGNAL(updateStatusBar_dataProcessorSignal(QString)),this,SLOT(updateStatusBar_mainwindowSlot(QString)));
    connect(dataProc,SIGNAL(updateResultTimePlot(float*, QString,float*)),qwtPlotResult,SLOT(UpdateCurve(float*, QString,float*)));
    connect(dataProc,SIGNAL(measDone()),setup,SLOT(setMeasDone_slot()));
    //gui controls
    connect(ui->pushButtonLoadData,SIGNAL(clicked(bool)),dataProc,SLOT(loadData(bool)));
    connect(ui->pushButtonLoadData,SIGNAL(clicked(bool)),this,SLOT(InitAtLoad()));
    connect(ui->pushButtonSaveData,SIGNAL(clicked(bool)),dataProc,SLOT(saveData(bool)));
    connect(ui->pushButtonSaveDataCurrent,SIGNAL(clicked(bool)),dataProc,SLOT(saveDataCur(bool)));
    connect(ui->pushButtonSavePointData,SIGNAL(clicked(bool)),pnaProc,SLOT(savePointData(void)));



//    connect(ui->groupBoxFilter,SIGNAL(toggled(bool)),ui->groupBoxFilterStep1,SLOT(setChecked(bool)));

    connect(ui->horizontalSliderFrame,SIGNAL(valueChanged(int)),dataProc, SLOT(setframeNum(int)));
    //connect(ui->pushButtonCapture, SIGNAL(clicked()),dataProc,SLOT(saveScreenshot()));
    //connect(ui->pushButtonCapture, SIGNAL(clicked()),ui->dial_intensity_2,SLOT(hide()));
    connect(ui->pushButtonSaveMovie, SIGNAL(clicked()),dataProc,SLOT(saveMovie()));

    //result tab
    connect(ui->dial_intensity,SIGNAL(valueChanged(int)),qwtSpectrogram,SLOT(setIntensityDial(int)));
    connect(ui->horizontalSliderFrame,SIGNAL(valueChanged(int)),qwtPlotResult, SLOT(updateVertMarker(int)));
    connect(ui->horizontalSliderFrame,SIGNAL(mouseMidButton(bool,int)),this, SLOT(updateVtwamInputs(bool,int)));
    ui->dial_intensity_2->hide();
//    connect(ui->dial_intensity,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensityDial(int)));
    connect(ui->pushButtonPlayPause,SIGNAL(toggled(bool)),this, SLOT(playPauseResult(bool)));
    connect(qwtSpectrogram,SIGNAL(placeSlave(int,int)),qwtSpectrogram2,SLOT(placeSlaveslot(int,int)));

    connect(ui->checkBoxGreyscale,SIGNAL(toggled(bool)),this->qwtSpectrogram,SLOT(toggleUWPIGreyScale(bool)));
    connect(ui->checkBoxGreyscale,SIGNAL(toggled(bool)),this->qwtSpectrogram2,SLOT(toggleUWPIGreyScale(bool)));

    enlargeResultDlgn = new DialogEnlarge(this);
    connect(this->enlargeResultDlgn,SIGNAL(finished(int)),this,SLOT(resizeToNormal()));

    connect(enlargeResultDlgn->giveSlider(),SIGNAL(valueChanged(int)),this->qwtSpectrogram,SLOT(updateAxisXY(int)));
    connect(this,SIGNAL(destroyed(QObject*)),this->enlargeResultDlgn,SLOT(close()));
//    connect(ui->checkBoxBoostSpeed,SIGNAL(toggled(bool)),dataProc,SLOT(setBoostSpeedEn(bool)));

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
    //connect(ui->dial_intensity,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensityDial(int)));
    disconnect(ui->dial_intensity_2,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensityDial(int)));
    ui->dial_intensity_2->hide();
    emit ui->dial_intensity->valueChanged(ui->dial_intensity->value()+1);
    emit ui->dial_intensity->valueChanged(ui->dial_intensity->value()-1);


    ui->checkBoxGreyscale->setChecked(false);

    // reset the result - time - plot
    this->qwtPlotResult->initPlot();
    this->ui->horizontalSliderFrame->setValue(0);
    stage->isFirstTime = true;
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

    ui->enumPnaSweepPoints->addItem("51");
    ui->enumPnaSweepPoints->addItem("201");
    ui->enumPnaSweepPoints->addItem("401");
    ui->enumPnaSweepPoints->addItem("801");

    ui->enumMeasType->addItems(comboMeasType(listMeasType));
    ui->enumMeasType_2->addItems(comboMeasType(listMeasType));


    //result tab
    ui->enumPlaySpeed->addItems(comboPlaySpeed(listPlaySpeed));

}

void MainWindow::InitSettingPars()
{
    ui->dial_intensity_2->setMinimum(1000);
    ui->dial_intensity_2->setMaximum((1<<20)-1);
    ui->dial_intensity_2->setValue(140000);

    ui->dial_intensity->setMinimum(1);
    ui->dial_intensity->setMaximum(200);
    ui->dial_intensity->setValue(50);

    ui->lineEdit_lowerLimit->setText("0");
    ui->lineEdit_upperLimit->setText("100");

    ui->horizontalSliderFrame->setMinimum(0);
    ui->horizontalSliderFrame->setMaximum(settingInfo.PnaSweepPoints-1);
    ui->horizontalSliderFrame->setValue(0);

    ui->enumPlaySpeed->setCurrentIndex(1);

    ui->lineEditScanHeight->setText("100");
    ui->lineEditScanWidth->setText("100");
    ui->enumScanInterval->setCurrentIndex(1);

    ui->lineEditPnaStartFreq->setText("8.2");
    ui->lineEditPnaStopFreq->setText("12.4");
    ui->enumPnaSweepPoints->setCurrentIndex(1);

    ui->lineEditPnaIFBW->setText("1000");
    ui->lineEditPnaPower->setText("0");

    ui->lineEditPnametalPlateThickness->setText("3");
    ui->lineEditPnasampleThickness->setText("3");
    ui->lineEditPnadistToSample->setText("0");
    settingInfo.scanstart = false;

    UpdateSettingParStruct();

    emit ui->enumMeasType->currentIndexChanged(0);
}

void MainWindow::UpdateMeasType()
{
    settingInfo.selectedMeas            = ui->enumMeasType->currentIndex();
}
void MainWindow::UpdateSettingParStruct()
{
    settingInfo.scanHeight         = ui->lineEditScanHeight->text().toInt();
    settingInfo.scanWidth          = ui->lineEditScanWidth->text().toInt();
    settingInfo.scanInterval       = ui->enumScanInterval->currentText().toFloat();
    settingInfo.xLength            = (settingInfo.scanWidth/settingInfo.scanInterval)+1;
    settingInfo.yLength            = (settingInfo.scanHeight/settingInfo.scanInterval)+1;
    settingInfo.ScanPoints         = settingInfo.xLength * settingInfo.yLength ;

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

void MainWindow::updateResultParStruct()
{

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
    label.sprintf(" Start frequency = %0.2f Ghz,   Stop frequency = %0.2f Ghz,   Sweep Points = %d Samples \n\n Width = %d mm,      Height = %d mm,       Interval = %0.2f mm ",
                  settingInfo.PnaStartFreq, settingInfo.PnaStopFreq,settingInfo.PnaSweepPoints, settingInfo.scanWidth, settingInfo.scanHeight,settingInfo.scanInterval);
    ui->labelCurrentDataSpec->setText(label);
    qwtPlotResult->updateAxisScale();
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


void MainWindow::on_pushButtonProcessFilter_clicked()
{
    //ui->pushButton->setEnabled(false);
    this->updateResultParStruct();
    emit postProcessingFilteringRequired();
}


void MainWindow::on_pushButtonCapture_clicked()
{
//    connect(ui->dial_intensity,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensityDial(int)));
    disconnect(ui->dial_intensity_2,SIGNAL(valueChanged(int)),qwtSpectrogram2,SLOT(setIntensityDial(int)));
    ui->dial_intensity_2->hide();
    qwtSpectrogram2->setIntensity(qwtSpectrogram->data->intensitymin,qwtSpectrogram->data->intensitymax);
    dataProc->takeScreenshot();
//    emit ui->dial_intensity->valueChanged(ui->dial_intensity->value()+1);
//    emit ui->dial_intensity->valueChanged(ui->dial_intensity->value()-1);
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
    double x = 0, y = 0;
    x = ui->lineEditXPos->text().toDouble();
    y = ui->lineEditZPos->text().toDouble();
    if (x >= 0 && x <= 1010)
    stage->setPosX(x*1000,false);
    if (y >= 0 && y <= 1010)
    stage->setPosZ(y*1000,false);
}

void MainWindow::on_pushButtonStart_clicked()
{
    UpdateSettingParStruct();
    settingInfo.scanstart = true;
    settingInfo.playScan = true;
    if(dataProc->allocateMem())
    {
        setup->startScan();
        pnaProc->hide();
        ui->tabWidget->setCurrentIndex(1);
    }
}
void MainWindow::scanFinished_main()
{
//    stage->setPosZ(stage->scanStartPosZ,false);
//    stage->setPosX(stage->scanStartPosX,false);
    //stage->setServoStop();
    pnaProc->show();
}


void MainWindow::on_pushButton_set_clicked()
{
    int Intensitymax = ui->lineEdit_upperLimit->text().toFloat();
    int Intensitymin = ui->lineEdit_lowerLimit->text().toFloat();
    qwtSpectrogram->setIntensity(Intensitymin,Intensitymax);
    //qwtSpectrogram2->setIntensity(Intensitymin,Intensitymax);
}

void MainWindow::on_pushButton_ySet_clicked()
{
    float yMin = ui->lineEdit_yLowerLimit->text().toFloat();
    float yMax = ui->lineEdit_yUpperLimit->text().toFloat();
    qwtPlotOsc->setAxisScale(QwtPlot::yLeft, yMin, yMax);
    qwtPlotOsc->replot();
}

void MainWindow::on_pushButton_ySet_result_clicked()
{
    float yMin = ui->lineEdit_yLowerLimit_result->text().toFloat();
    float yMax = ui->lineEdit_yUpperLimit_result->text().toFloat();
    qwtPlotResult->setAxisScale(QwtPlot::yLeft, yMin, yMax);
    qwtPlotResult->replot();
}

void MainWindow::on_pushButtonScanPause_clicked()
{
    if (settingInfo.playScan == true)
    {
        settingInfo.playScan = false;
        while (settingInfo.playScan ==false)
        {
            QCoreApplication::processEvents();
        }
    }

}

void MainWindow::on_pushButtonScanPlay_clicked()
{
    settingInfo.playScan = true;
}
