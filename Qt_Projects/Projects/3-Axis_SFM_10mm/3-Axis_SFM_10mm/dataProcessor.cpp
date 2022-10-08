#include "dataProcessor.h"
#include <QtWinExtras\QtWin>

dataProcessor::dataProcessor(structSetting * settingInfoArg, structResult *resultInfoArg,
                             spectrogram* qwtSpectrogramArg, spectrogram *qwtSpectrogram2Arg, QString progDataPathArg,
                             QSlider * sliderFrameArg, QLabel* labelFrameArg
                             )
{
    settingInfoPtr          = settingInfoArg;
    resultInfoPtr           = resultInfoArg;
    dataBundle              = NULL;
    resultTimeSig           = NULL;
    vtwamResult             = NULL;
    screenShotResult        = NULL;
    buffScanPoints          = 0;
    frameNum                = 0;
    runtimeNo               = 0;
    dispBuffIndex           = 0;
    dispGraphIndex          = 0;
    qwtSpectrogram          = qwtSpectrogramArg;
    qwtSpectrogram2         = qwtSpectrogram2Arg;
    dataBundleSaved         = false;
    progDataPath            = progDataPathArg;
    VtwamProcessing         = false;
    bufToProcess            = 1;
    boostSpeedEn            = true;
    postProcDone            = false;
    VTWAMTitle              = "VTWAM Result";
    loadCoordinatesDone     = false;
    PnaSweepPoints          = 512;
    sliderFramePtr          = sliderFrameArg;
    labelFramePtr           = labelFrameArg;
    f                       = NULL;
    resultTimeSig           = NULL;
}

dataProcessor::~dataProcessor()
{
    if (clear2dArray(PnaSweepPoints,buffScanPoints))
    {
         qDebug("dataProcessor::~dataProcessor() - dataBundle cleared - buffScanPoints : %d", buffScanPoints);
    }
    else
    {
         qDebug("Error: dataProcessor::~dataProcessor() - cant clear dataBundle - buffScanPoints : %d", buffScanPoints);
    }

    //delete this->filterTabDataBase;
}

bool dataProcessor::allocateMem()
{
    bool allocSuccess = true;
    //This can be called from the mainwindow or called when we recieve the 1st waveform from daq.
    MEMORYSTATUSEX memory_status;
    ZeroMemory(&memory_status, sizeof(MEMORYSTATUSEX));
    memory_status.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memory_status);
    qint64 sysPhyMem = memory_status.ullTotalPhys >> 20;

    //number of frames* (1d pointer size + actual data for each frame) conversion to MB
    qint64 MemoryNeeded = (PnaSweepPoints*(sizeof(short*) + (qint64)settingInfoPtr->ScanPoints*sizeof(short)))>>20;
    qint64 MemoryNeededforDataBuffs = MemoryNeeded<<1; //2 x data buffer
    qint64 MemoryforSigLengthFifo = 256;
    qint64 totalMemReq = MemoryNeededforDataBuffs + MemoryforSigLengthFifo;

    qDebug()<<"dataProcessor::allocateMem - settingInfoPtr->ScanPoints: "<< settingInfoPtr->ScanPoints
           <<"\nSize per buff(MB):" <<MemoryNeeded
           <<"\nTotal Size buffs(MB):"<<MemoryNeededforDataBuffs
           <<"\nSig lenght FIFO(MB):" << MemoryforSigLengthFifo
           <<"\nTotal Mem Requirement:" << totalMemReq
           <<"\nSystem physical memory(MB):"<< sysPhyMem;

    if ((totalMemReq + 3000) > sysPhyMem)
    {
        QMessageBox msgBox(QMessageBox::Critical, tr("Insufficient Memory"),tr("Required memory: ") + QString::number(totalMemReq) + tr("\n System Memory: ") + QString::number(sysPhyMem), 0);
        msgBox.exec();
        return 0;
    }

    if (dataBundle == NULL) // allocate if not done already.
    {
        //declare 2D array via pointer.
        if (allocSuccess = alloc2dArray(settingInfoPtr->PnaSweepPoints,settingInfoPtr->ScanPoints))
        {
            buffScanPoints = settingInfoPtr->ScanPoints; // this will be used in clearing up the memory if the scan pars are changed next time.
            buffScanWidth  = settingInfoPtr->scanWidth;
            buffScanHeight  = settingInfoPtr->scanHeight;
            buffScanInterval  = settingInfoPtr->scanInterval;           
            PnaSweepPoints = settingInfoPtr->PnaSweepPoints;
            sliderFramePtr->setMaximum(PnaSweepPoints-1);
        }
        else
        {
            //clear any allocated mem
            clear2dArray(settingInfoPtr->PnaSweepPoints,buffScanPoints);
            qDebug("Error: dataProcessor::allocateMem() - cant declare dataBundle - settingInfoPtr->ScanPoints : %d", settingInfoPtr->ScanPoints);
        }
    }
    //else if (settingInfoPtr->ScanPoints != buffScanPoints) // allocate if the size has changed
    else
    {
        //clear previous before allocating new.
        if (allocSuccess = clear2dArray(PnaSweepPoints,buffScanPoints))
        {
            if (allocSuccess = alloc2dArray(settingInfoPtr->PnaSweepPoints,settingInfoPtr->ScanPoints))
            {
                buffScanPoints = settingInfoPtr->ScanPoints; // this will be used in clearing up the memory if the scan pars are changed next time.
                buffScanWidth  = settingInfoPtr->scanWidth;
                buffScanHeight  = settingInfoPtr->scanHeight;
                buffScanInterval  = settingInfoPtr->scanInterval;
                PnaSweepPoints = settingInfoPtr->PnaSweepPoints;
                sliderFramePtr->setMaximum(PnaSweepPoints-1);
            }
            else
                qDebug("Error: dataProcessor::allocateMem() - cant declare dataBundle - settingInfoPtr->ScanPoints : %d", settingInfoPtr->ScanPoints);
        }
        else
        {
             qDebug("Error: dataProcessor::allocateMem() - cant clear dataBundle - buffScanPoints : %d", buffScanPoints);
        }
    }

    if (allocSuccess)
    {
        VTWAMTitle          = "VTWAM Result";
        postProcDone        = false;
        dataBundleSaved  = false;
        filtPass1en     = false;
        filtPass2en     = false;
        filterType      = 0;
        filterType2     = 0;
        filterRadius    = 0;
        filterRadius2   = 0;
        filterItr       = 0;
        filterItr2      = 0;

        if (resultTimeSig!=NULL)
        {
            free(resultTimeSig);
            resultTimeSig = NULL;
        }

        if (f!=NULL)
        {
            free(f);
            f = NULL;
        }

        resultTimeSig   = (float *)calloc(PnaSweepPoints,sizeof (float)) ;
        f               = (float *)calloc(PnaSweepPoints,sizeof (float)) ;
        for (int i=0;i<PnaSweepPoints;i++)
            f[i] = 8.2 + i*((12.4-8.2)/PnaSweepPoints);

        //makesure the scan info has correct info.
        if (screenShotResult != NULL)
        {
            free(screenShotResult);
            screenShotResult=NULL;
        }

         screenShotResult = (float*) calloc(this->buffScanPoints,sizeof(float));
         qwtSpectrogram2->updateData(screenShotResult," ",0);
         //qwtSpectrogram2->updateAxisXY();

         //makesure the scan info has correct info.
         if (vtwamResult != NULL)
         {
             free(vtwamResult);
             vtwamResult=NULL;
         }

          vtwamResult = (unsigned int*) calloc(this->buffScanPoints,sizeof(unsigned int));

          this->setframeNum(frameNum);
          qwtSpectrogram->updateAxisXY();
    }
    return allocSuccess;
}

void dataProcessor::newWfmCopyToArray_slot(structMeas *pMeas, int curScanPt)
{
    bool updateResult=false;
    int x_length = (settingInfoPtr->scanWidth/settingInfoPtr->scanInterval)+1;
    int y_length = (settingInfoPtr->scanHeight/settingInfoPtr->scanInterval)+1;

    static int wfmToFrameConvFactor_oddLine;
    unsigned int framePoint;
    bool isOddLine =(curScanPt/x_length) % 2;
    //int currentMean = 0;

    //int inputBufStartIndex = (waveformNumber*SAMPLESPERPOINT)%(SAMPLESPERPOINT*SIG_FIFO_LEN);

    if (curScanPt==0) //memory sanity check once at start
    {
        if (isMemValid(dataBundle, 0, frameNum,__FUNCTION__,false) == false)
            return;
        if (pMeas == NULL)
        {
            QMessageBox msgBox(QMessageBox::Critical, tr("Memory Error"),tr("dataProcessor::scanFinished - wfmPtr = NULL"), 0);
            msgBox.exec();
            return;
        }

        //if (applyRealTimeFilter)
            //startParallelProcThread(1,1,dataBundle[1],dataBundle[0],x_length,y_length); // start the real time median mask
        for (int frame=0;frame<PnaSweepPoints;frame++)
            f[frame] = pMeas->f[frame];
    }

    framePoint = curScanPt;
    if (isOddLine)
        framePoint += wfmToFrameConvFactor_oddLine;

    for (int frame=0;frame<PnaSweepPoints;frame++)
    {
        dataBundle[measType::er][frame][framePoint]     = pMeas->e.real[frame];
        dataBundle[measType::ei][frame][framePoint]     = pMeas->e.imag[frame];
        dataBundle[measType::ur][frame][framePoint]     = pMeas->u.real[frame];
        dataBundle[measType::ui][frame][framePoint]     = pMeas->u.imag[frame];
        dataBundle[measType::s11Mag][frame][framePoint] = pMeas->s11.mag[frame];
        dataBundle[measType::s21Mag][frame][framePoint] = pMeas->s21.mag[frame];
    }

    //emit wfmCopyDone_sig(waveformNumber);

    if ( isOddLine) //for odd rows
        wfmToFrameConvFactor_oddLine-=2;
    else //for even rows
        wfmToFrameConvFactor_oddLine = x_length-1;


    dispBuffIndex = settingInfoPtr->selectedMeas; //always show buffer 1 while acquiring the signal

    if (((curScanPt+11)%(x_length)) == 0)
        updateResult = true;
    else if (((curScanPt+1)%(x_length)) == 0)
        updateResult = false;

    //if(updateResult)
    {
        setframeNum(frameNum);
    }

    //#ifdef DAQ_DEBUG_LOGS
    qDebug()<<QDateTime::currentDateTime().time()<<"newWfmCopyToArray_slot - waveformNumber"<<curScanPt<<
              "isOddLine"<<isOddLine<<
              "wfmPtr"<<pMeas;
    //#endif

    emit measDone();
}

void dataProcessor::saveScreenshot()
{
    if (isMemValid(dataBundle, dispBuffIndex, frameNum,__FUNCTION__) == false)
        return;

    //save the actual plot
    QDateTime now = QDateTime::currentDateTime();
    QString captureStoragePath = progDataPath + "\\ScreenShots\\";
    QString captureFileName = "ScreenshotUWPI"+now.toString("ddMMyy_hhmmss");
    if( QDir(captureStoragePath).exists() == false)
        QDir().mkpath(captureStoragePath);
    qwtSpectrogram->savePlot(captureStoragePath+captureFileName);

    if (screenShotResult == NULL)
    {
          qWarning("dataProcessor::saveScreenshot: couldnt allocate screenShotResult");
          return;
    }

     timer.start();
     for(unsigned int i =0;i<this->buffScanPoints;i++)
         screenShotResult[i] = dataBundle[dispBuffIndex][frameNum][i];
     qDebug()<<timer.elapsed();


    qwtSpectrogram2->updateAxisXY();
    //qwtSpectrogram2->updateData((dataBundle[dispBuffIndex][frameNum]),captureFileName);
    qwtSpectrogram2->updateData(screenShotResult,captureFileName);

    //to display a frame give to dataProc and then qwtSpectrogram
}

void dataProcessor::saveScreenshotVtwam()
{
    //show the result if not already shown
    qwtSpectrogram2->updateData(this->vtwamResult,this->VTWAMTitle, 1);
    qwtSpectrogram2->updateAxisXY();

    //save the actual plot
    QDateTime now = QDateTime::currentDateTime();
    QString captureStoragePath = progDataPath + "\\ScreenShots";
    QString captureFileName = "\\ScreenshotVTWAM"+now.toString("ddMMyy_hhmmss");
    if( QDir(captureStoragePath).exists() == false)
        QDir().mkpath(captureStoragePath);
    qwtSpectrogram2->savePlot(captureStoragePath+captureFileName);
}

void dataProcessor::saveMovie()
{
    timer.start();

    if (isMemValid(dataBundle, dispBuffIndex, frameNum,__FUNCTION__) == false)
        return;

    qwtSpectrogram->setMovieImageSize();

    //make storage path
    QDateTime now = QDateTime::currentDateTime();
    QString captureStoragePath = progDataPath + "\\Movies";
    QString captureFileName = "\\Movie"+now.toString("ddMMyy_hhmmss")+".avi";
    if( QDir(captureStoragePath).exists() == false)
        QDir().mkpath(captureStoragePath);

    QString StatusTip;
    QByteArray fileArr = QString(captureStoragePath+captureFileName).toUtf8();
    HBITMAP hbm;
    //
    HAVI avi = CreateAvi(fileArr.toStdString().c_str(),100,NULL);
    //QList<QPixmap> images;
    QPixmap pixMapImage;
    int savedFrameNum = this->frameNum;

    //for (int frame=0; frame < 20; frame++)
    for (int frame=0; frame < PnaSweepPoints; frame++)
    {
        setframeNum(frame);
        pixMapImage = qwtSpectrogram->getPlotPixmap(frame);
        {
            //QLabel imageLabel(this->qwtSpectrogram2);
            //imageLabel= new QLabel(this);
        //    labelMovieDebug->setPixmap(pixMapImage);
        //    labelMovieDebug->showFullScreen();
            //setCentralWidget(imageLabel);
        }

        hbm = QtWin::toHBITMAP(pixMapImage); // memory leaking culprit
        AddAviFrame(avi,hbm);
        DeleteObject(hbm);
        QCoreApplication::processEvents();
        emit updateProgressBar_dataProcessorSignal( ( (double)(frame+1)/PnaSweepPoints)*100 );
        StatusTip = "Generating movie - "+QString::number(frame+1)+"/"+QString::number(PnaSweepPoints)+"frames";
        emit updateStatusBar_dataProcessorSignal(StatusTip);
    }
    CloseAvi(avi);
    qDebug()<<"Movie done in "<<timer.elapsed();

    setframeNum(savedFrameNum);
}

void dataProcessor::plotResultTime(int pointToPlot)
{
    int x_length = (settingInfoPtr->scanWidth/settingInfoPtr->scanInterval)+1;
    float x = (settingInfoPtr->scanInterval*(pointToPlot%x_length) );
    float y = (settingInfoPtr->scanInterval*(pointToPlot/x_length));

    if (resultTimeSig!=NULL)
    {
        if (isMemValid(dataBundle, dispBuffIndex, frameNum,__FUNCTION__) == false)
            return;

        for (int i=0;i<PnaSweepPoints;i++)
            resultTimeSig[i] = dataBundle[dispBuffIndex][i][pointToPlot];
    }
    qDebug()<<"dataProcessor::plotResultTime"<<&dataBundle[dispBuffIndex][0][0]
           <<dataBundle[dispBuffIndex][0][0];
    QString title = measName(dispBuffIndex) + " (x=" +  QString::number(x) + ",y=" + QString::number(y)+")";
    emit updateResultTimePlot(resultTimeSig,title,f);
}

void dataProcessor::setframeNum(int frameNum_arg)
{
    frameNum = frameNum_arg;

    if (isMemValid(dataBundle, dispBuffIndex, frameNum,__FUNCTION__,true) == false)
        return;

    //makesure the scan info has correct info.
    buffScanWidth  = settingInfoPtr->scanWidth;
    buffScanHeight  = settingInfoPtr->scanHeight;
    buffScanInterval  = settingInfoPtr->scanInterval;


    QString labelString;

    if (f!=NULL)
       labelString.sprintf("%.3f GHz",f[frameNum_arg]);
    else
        labelString.sprintf("%.3f GHz",settingInfoPtr->PnaStartFreq+ (double)frameNum_arg*settingInfoPtr->PnaFreqStepSize);

    labelFramePtr->setText(labelString);
    qDebug()<<"dataProcessor::setframeNum frameNum"<<frameNum<<
           "FramePtr:"<<dataBundle[dispBuffIndex][frameNum];
    qwtSpectrogram->updateData((double *)dataBundle[dispBuffIndex][frameNum],labelString);
}

//simply selects which data is to be displayed, processed or un-processed.
void dataProcessor::selectDisplayBuffer(int measIndex)
{
    dispBuffIndex = measIndex;
    setframeNum(frameNum);
}

void dataProcessor::postProcessingFilteringRequested()
{
    int x_length       = (settingInfoPtr->scanWidth/settingInfoPtr->scanInterval)+1;
    int y_length       = (settingInfoPtr->scanHeight/settingInfoPtr->scanInterval)+1;
    //inspect the result structure

    if (isMemValid(dataBundle, 0, frameNum,__FUNCTION__,false) == false)
        return;
      ////////// always apply filter to the data present in buffer 1 and save it to buffer 0;
    if ((resultInfoPtr->filtPass1en)   &&
        resultInfoPtr->filterType       != this->filterType   ||
        resultInfoPtr->filterRadius     != this->filterRadius ||
        resultInfoPtr->filterItr        != this->filterItr    ||

        ((resultInfoPtr->filtPass2en) &&
        resultInfoPtr->filterType2       != this->filterType2   ||
        resultInfoPtr->filterRadius2     != this->filterRadius2 ||
        resultInfoPtr->filterItr2        != this->filterItr2))
    {
        this->filterItr = 0;
        this->filterItr2 = 0; //This will be triggered from within the scanfinished

        //startProcThread(resultInfoPtr->filterType,resultInfoPtr->filterRadius,dataBundle[0],dataBundle[1],x_length,y_length);
    }
}

void dataProcessor::postProcessingVtwamRequested(QString VtwamTitleArg)
{

    if (isMemValid(dataBundle, dispBuffIndex, frameNum,__FUNCTION__) == false)
        return;

     if (vtwamResult == NULL)
     {
           qWarning("dataProcessor::postProcessingVtwamRequested: couldnt allocate vtwamResult");
           return;
     }

     this->VTWAMTitle = VtwamTitleArg;

     //startVtwamThread(dataBundle[dispBuffIndex], vtwamResult, this->buffScanPoints,resultInfoPtr->vtwamStartFr,resultInfoPtr->vtwamEndFr);
}

void dataProcessor::updateResultSpect()
{
    setframeNum(frameNum);
}

void dataProcessor::parallelprocFinished()
{
    qDebug()<<"dataProcessor::parallelprocFinished().";
}

void dataProcessor::stop()
{
    emit abortThread_sig();
}

void dataProcessor::startVtwamThread(short **Input, unsigned int* result, unsigned int buffScanPoints,int startFrame, int endFrame)
{
    this->totalThreads = 1;
    this->coreProcObj = new coreProcessor(1,1,Input,NULL,50, 50, startFrame, endFrame, buffScanPoints,result);
    this->procThread = new QThread;
    this->coreProcObj->moveToThread(procThread);

    //connect(scannerObj, SIGNAL(errorSignal(QString)), this, SLOT(errorHandler(QString)));
    connect(coreProcObj, SIGNAL(updateProgress(int,short,short)), this, SLOT(updateProcProgress(int,short,short)));
    connect(coreProcObj, SIGNAL(finished()), this, SLOT(procFinished()));
    //start process
    connect(procThread, SIGNAL(started()), coreProcObj, SLOT(processVtwam()));
    //quit thread
    connect(coreProcObj, SIGNAL(finished()), procThread, SLOT(quit()));
    //delete after finishing
    connect(coreProcObj, SIGNAL(finished()), coreProcObj, SLOT(deleteLater()));
    connect(procThread, SIGNAL(finished()), procThread, SLOT(deleteLater()));

    this->VtwamProcessing = true;
    this->procThread->start();

    timer.start();
}

void dataProcessor::startProcThread(short filtType ,short krnlRadius, short **Input,short **Output,int x_length,int y_length)
{
    int threadNum = 0,startFrame,endFrame,framesPerThread;
    qDebug()<<"Ideal Thread count:"<<procThread->idealThreadCount();//procThread2->idealThreadCount();
    this->threadFinishedCount = 0;

    if (this->boostSpeedEn)
        this->totalThreads = procThread->idealThreadCount();
    else
        this->totalThreads = 1;

    framesPerThread = PnaSweepPoints/this->totalThreads;

    coreProcObjArr  = new coreProcessor* [this->totalThreads];
    procThreadArr   = new QThread* [this->totalThreads];

    for (threadNum = 0;threadNum<this->totalThreads;threadNum++)
    {
        startFrame = framesPerThread*threadNum;
        //if total frames are not equally distributed among all threads the last thread gets the leftovers
        if (threadNum == this->totalThreads - 1)
            endFrame = PnaSweepPoints;
        else
            endFrame = startFrame + framesPerThread;

        this->coreProcObjArr[threadNum] = new coreProcessor(filtType,krnlRadius, Input,Output,x_length,y_length,startFrame,endFrame) ;
        this->procThreadArr[threadNum] = new QThread;

        this->coreProcObjArr[threadNum]->moveToThread(procThreadArr[threadNum]);


        if (threadNum == 0) // only first thread updates the progress
            connect(coreProcObjArr[threadNum], SIGNAL(updateProgress(int,short,short)), this, SLOT(updateProcProgress(int,short,short)));

        connect(coreProcObjArr[threadNum], SIGNAL(finished()), this, SLOT(procFinishedGather()));
        //start process
        connect(procThreadArr[threadNum], SIGNAL(started()), coreProcObjArr[threadNum], SLOT(process()));
        //quit thread
        connect(coreProcObjArr[threadNum], SIGNAL(finished()), procThreadArr[threadNum], SLOT(quit()));
        //delete after finishing
        connect(coreProcObjArr[threadNum], SIGNAL(finished()), coreProcObjArr[threadNum], SLOT(deleteLater()));
        connect(procThreadArr[threadNum], SIGNAL(finished()), procThreadArr[threadNum], SLOT(deleteLater()));
        this->procThreadArr[threadNum]->start();
    }

    timer.start();
}

void dataProcessor::setBoostSpeedEn(bool val)
{
    this->boostSpeedEn = val;
}

void dataProcessor::updateProcProgress(int curframeNum,short FilterRadius, short filterType)
{
    QString StatusTip;
    if (VtwamProcessing == true)
    {
        emit updateProgressBar_dataProcessorSignal( ( (double)curframeNum/buffScanPoints)*100 );
        QTextStream(&StatusTip)<<"Post-processing (VTWAM ) - Processed "<<curframeNum<<"/"<<this->buffScanPoints<<"points";
        emit updateStatusBar_dataProcessorSignal(StatusTip);
    }
    else
    {
        short fltSize = (FilterRadius<<1)+1;
        int frmaeThreadRemainder = PnaSweepPoints%this->totalThreads;
        emit updateProgressBar_dataProcessorSignal( ( (double)((curframeNum*this->totalThreads)+frmaeThreadRemainder)/PnaSweepPoints)*100 );

        if (filterType == 1)
            QTextStream(&StatusTip)<<"Post-processing(Median filter "<<fltSize<<"x"<<fltSize<<")- Processed "<<((curframeNum*this->totalThreads)+frmaeThreadRemainder)<<"/"<<PnaSweepPoints <<"frames";
        if (filterType == 2)
            QTextStream(&StatusTip)<<"Post-processing(Spatial Avg filter "<<fltSize<<"x"<<fltSize<<")- Processed "<<((curframeNum*this->totalThreads)+frmaeThreadRemainder)<<"/"<<PnaSweepPoints <<"frames";
        emit updateStatusBar_dataProcessorSignal(StatusTip);
        //we can switch the display buff index here as well
    }
}

void dataProcessor::procFinishedGather()
{
    threadFinishedCount++;

    if (threadFinishedCount == totalThreads)
    {
        threadFinishedCount = 0;
        procFinished();
    }
}

void dataProcessor::procFinished()
{
    if (VtwamProcessing == true)
    {
        QString StatusTip;
        emit updateProgressBar_dataProcessorSignal( (double)100 );
        QTextStream(&StatusTip)<<"Post-processing (VTWAM ) - Processed "<<this->buffScanPoints<<"/"<<this->buffScanPoints<<"points";
        emit updateStatusBar_dataProcessorSignal(StatusTip);

        this->VtwamProcessing = false;

        qwtSpectrogram2->updateData(this->vtwamResult,this->VTWAMTitle, 1);
        qwtSpectrogram2->updateAxisXY();

        qDebug()<<"dataProcessor::procFinished() - VTWAM Time taken:"<<timer.elapsed();
    }
    else
    {
        postProcDone = true;
        selectDisplayBuffer(true);
        setframeNum(frameNum);

        qDebug()<<"dataProcessor::procFinished()"<<"filterType" <<resultInfoPtr->filterType<<"filterRadius"<<resultInfoPtr->filterRadius<<"filterItr"
               <<filterItr<<"Time taken:"<<timer.elapsed();
        {
            short FilterBuffNum;
            FilterBuffNum = 1;

            int x_length       = (settingInfoPtr->scanWidth/settingInfoPtr->scanInterval)+1;
            int y_length       = (settingInfoPtr->scanHeight/settingInfoPtr->scanInterval)+1;

            this->dataBundleSaved = false; // this may now be saved if requested
            dispBuffIndex = FilterBuffNum;

            qDebug()<<"dataProcessor::procFinished - FilterBuffNum "<<FilterBuffNum;

            if(this->filterItr < resultInfoPtr->filterItr)
            {
                this->filterItr++;

                if(this->filterItr < resultInfoPtr->filterItr)
                {

                   // startProcThread(resultInfoPtr->filterType,resultInfoPtr->filterRadius,
                   //                dataBundle[FilterBuffNum],dataBundle[FilterBuffNum],x_length,y_length);

                    //block the flow, lest the step 2 is activated.
                    return;
                }
                else
                { //filtering finished so save the applied filter stats in class
                    // do at end of processing ??
                    this->filtPass1en  = resultInfoPtr->filtPass1en;
                    this->filterType   = resultInfoPtr->filterType;
                    this->filterRadius = resultInfoPtr->filterRadius;
                }
            }
            if (resultInfoPtr->filtPass2en)
            {
                if(this->filterItr2 < resultInfoPtr->filterItr2)
                {

                    //startProcThread(resultInfoPtr->filterType2,resultInfoPtr->filterRadius2,
                      //             dataBundle[FilterBuffNum],dataBundle[FilterBuffNum],x_length,y_length);

                    this->filterItr2++;
                }
                else
                { //filtering finished so save the applied filter stats in class
                    // do at end of processing ??
                    this->filtPass2en  = resultInfoPtr->filtPass2en;
                    this->filterType2   = resultInfoPtr->filterType2;
                    this->filterRadius2 = resultInfoPtr->filterRadius2;
                }
            }
        }
    }
}

void dataProcessor::loadData(bool status)
{
    timer.start();
    QFile myfilein;
    QString filepath,infolderpath;
    QString StatusTip;
    qint64 result;

    unsigned int buffScanPointsLoc;
    int buffScanHeightLoc;
    int buffScanWidthLoc;
    float buffScanIntervalLoc;
    int fnum;
    int PnaSweepPointsLoc;
    int index;

    if(dataBundle != NULL && dataBundleSaved == false)
    {
        int result;
        QMessageBox msgBox(QMessageBox::Question, tr("Scan Data"),tr("Current UWPI data has not been saved. Do you want to overwrite this data ?"),
                           QMessageBox::Yes|QMessageBox::No);
        result = msgBox.exec();

        if (result ==QMessageBox::No)
        return;
    }
    QFileDialog *fd = new QFileDialog;
    //QTreeView *tree = fd->findChild <QTreeView*>();
    //tree->setRootIsDecorated(true);
    //tree->setItemsExpandable(true);
    fd->setFileMode(QFileDialog::Directory);
    fd->setOption(QFileDialog::ShowDirsOnly);
    fd->setViewMode(QFileDialog::Detail);
    fd->setDirectory(progDataPath+"\\Data");

    if (fd->exec())
    {
        infolderpath = fd->selectedFiles()[0];
        qDebug()<<filepath;

        //save the data related settings necessary for loading the data next time.
         filepath = infolderpath+"\\Setting(DoNotEdit).bin";
         myfilein.setFileName(filepath);
         if(!myfilein.open(QIODevice::ReadOnly))
         {
             QMessageBox msgBox(QMessageBox::Critical, tr("File Error"),tr("Could'nt open parameter file for data."), 0);
             msgBox.exec();
             return;
         }
         QDataStream in(&myfilein);
         in.setByteOrder(QDataStream::LittleEndian);

         in>>buffScanPointsLoc;
         in>>buffScanHeightLoc;
         in>>buffScanWidthLoc;
         in>>buffScanIntervalLoc;
         in>>PnaSweepPointsLoc;

         myfilein.close();

         settingInfoPtr->ScanPoints     = buffScanPointsLoc;
         settingInfoPtr->scanWidth      = buffScanWidthLoc;
         settingInfoPtr->scanHeight     = buffScanHeightLoc;
         settingInfoPtr->scanInterval   = buffScanIntervalLoc;
         settingInfoPtr->PnaSweepPoints = PnaSweepPointsLoc;
         settingInfoPtr->PnaFreqStepSize    =  (settingInfoPtr->PnaStopFreq  - settingInfoPtr->PnaStartFreq)/settingInfoPtr->PnaSweepPoints;

         qDebug()<<"dataProcessor::loadData"<<
                   "buffScanWidthLoc "<<buffScanWidthLoc<<
                   "buffScanHeightLoc"<< buffScanHeightLoc<<
                   "buffScanIntervalLoc"<< buffScanIntervalLoc<<
                   "buffScanPointsLoc"<<buffScanPointsLoc<<
                   "PnaSweepPoints"<<settingInfoPtr->PnaSweepPoints;

         if (!allocateMem())
            return;

         if (resultTimeSig!=NULL)
             free(resultTimeSig);

         resultTimeSig = (float *)calloc(PnaSweepPoints,sizeof (float)) ;

         if (f!=NULL)
             free(f);

         f      = (float *)calloc(PnaSweepPoints,sizeof (float)) ;


         emit declarePlotMemory_sig();


         //write the frequency range file
         filepath = infolderpath+"\\f.bin";

         myfilein.setFileName(filepath);
         if(!myfilein.open(QIODevice::ReadOnly))
         {
             QMessageBox errBox;
             errBox.setText("Could not open f-file for reading.");
             errBox.exec();
             return;
         }
         result=myfilein.read((char *)&f[0],sizeof(float)*PnaSweepPoints);

         for (int j = 0; j<10;j++)
             qDebug()<<f[j];

         myfilein.close();

         for (fnum = 0; fnum<PnaSweepPoints; fnum++)
         {
             filepath = infolderpath+"\\"+QString::number(fnum)+".bin";

             myfilein.setFileName(filepath);
             if(!myfilein.open(QIODevice::ReadOnly))
             {
                 QMessageBox msgBox(QMessageBox::Critical, tr("File Error"),tr("Could'nt open data file."), 0);
                 msgBox.exec();
                 return;
             }

             for (index = 0; index<measType::noOfMeas; index++)
                 result=myfilein.read((char *)&dataBundle[index][fnum][0],sizeof(float)*buffScanPoints);

             myfilein.close();

             //update current status
             emit updateProgressBar_dataProcessorSignal( ( (double)(fnum+1)/PnaSweepPoints)*100 );
             StatusTip.clear();
             QTextStream(&StatusTip)<<"Loading data frame: "<<fnum+1<<"/"<<PnaSweepPoints;
             emit updateStatusBar_dataProcessorSignal(StatusTip);

             QCoreApplication::processEvents();

             if (fnum==0)
             {
                 dataBundleSaved = true;
                 dispBuffIndex = 0;
                 setframeNum(0);
             }
         }
         qDebug()<<"File Reading Time: (msec)"<<timer.elapsed();
         //clear filtered data and stats;
         emit loadDataDone();
    }
}

void dataProcessor::saveDataCur(bool status)
{
    timer.start();

    QFile myfileout;
    QString filepath;
    QString StatusTip;
    qint64 result;
    int index;

    /*
    if (this->postProcDone == false)
    {
        QMessageBox msgBox(QMessageBox::Critical, tr("Data Error"),tr("There is no change in loaded data. It will be useful to save after processing."), 0);
        msgBox.exec();
        return;
    }
    */

    if (dataBundle == NULL)
    {
        QMessageBox msgBox(QMessageBox::Critical, tr("Data Error"),tr("No data available for saving."), 0);
        msgBox.exec();
        return;
    }

    if( dataBundle[dispBuffIndex] == NULL )
    {
        QMessageBox msgBox(QMessageBox::Critical, tr("Data Error"),tr("No data available for saving."), 0);
        msgBox.exec();
        return;
    }
/*
   if (dataBundleSaved == TRUE)
   {
       QMessageBox msgBox(QMessageBox::Information, tr("Data Saved"),tr("This data was already saved."), 0);
       msgBox.exec();
       qDebug()<<"dataProcessor::saveData - This data was already saved, dispBuffIndex: " << dispBuffIndex;
       return;
   }
*/

   QDateTime now = QDateTime::currentDateTime();
   QString dataStoragePath = this->progDataPath + "\\Data\\Data"+now.toString("ddMMyy_hhmmss")+"\\";
   if( QDir(dataStoragePath).exists() == false)
       QDir().mkpath(dataStoragePath);
   //save the data related settings necessary for loading the data next time.

   filepath = dataStoragePath+"Setting(DoNotEdit).bin";
    myfileout.setFileName(filepath);
    if(!myfileout.open(QIODevice::WriteOnly))
    {
        QMessageBox errBox;
        errBox.setText("Could not open file for writing.");
        errBox.exec();
        return;
    }
    QDataStream out(&myfileout);
    out.setByteOrder(QDataStream::LittleEndian);
    out<<buffScanPoints;
    out<<buffScanHeight;
    out<<buffScanWidth;
    out<<buffScanInterval;
    out<<PnaSweepPoints;


    myfileout.close();

    //write the frequency range file
    filepath = dataStoragePath+"f.bin";

    myfileout.setFileName(filepath);
    if(!myfileout.open(QIODevice::WriteOnly))
    {
        QMessageBox errBox;
        errBox.setText("Could not open file for writing.");
        errBox.exec();
        return;
    }
    result=myfileout.write((char *)&f[0],sizeof(float)*PnaSweepPoints);
    myfileout.close();

    for (int fnum = 0; fnum<PnaSweepPoints; fnum++)
    {
        filepath = dataStoragePath+QString::number(fnum)+".bin";

        myfileout.setFileName(filepath);
        if(!myfileout.open(QIODevice::WriteOnly))
        {
            QMessageBox errBox;
            errBox.setText("Could not open file for writing.");
            errBox.exec();
            return;
        }

        result=myfileout.write((char *)&dataBundle[dispBuffIndex][fnum][0],sizeof(float)*buffScanPoints);

        myfileout.close();

        //update current status
        emit updateProgressBar_dataProcessorSignal( ( (double)(fnum+1)/PnaSweepPoints)*100 );
        StatusTip.clear();
        QTextStream(&StatusTip)<<"Saving data frame: "<<fnum+1<<"/"<<PnaSweepPoints;
        emit updateStatusBar_dataProcessorSignal(StatusTip);

        QCoreApplication::processEvents();
    }
    dataBundleSaved = true;

    qDebug()<<"Filewriting Time: (msec)"<<timer.elapsed()<<"buffScanPoints"<<this->buffScanPoints<<"dispBuffIndex"<<this->dispBuffIndex;
}

void dataProcessor::saveData(bool status)
{
    timer.start();

    QFile myfileout;
    QString filepath;
    QString StatusTip;
    qint64 result;
    int index;

    /*
    if (this->postProcDone == false)
    {
        QMessageBox msgBox(QMessageBox::Critical, tr("Data Error"),tr("There is no change in loaded data. It will be useful to save after processing."), 0);
        msgBox.exec();
        return;
    }
    */

    if (dataBundle == NULL)
    {
        QMessageBox msgBox(QMessageBox::Critical, tr("Data Error"),tr("No data available for saving."), 0);
        msgBox.exec();
        return;
    }

    if (dataBundle[measType::er] == NULL ||
        dataBundle[measType::ei] == NULL ||
        dataBundle[measType::ur] == NULL ||
        dataBundle[measType::ui] == NULL ||
        dataBundle[measType::s11Mag] == NULL ||
        dataBundle[measType::s21Mag] == NULL
            )
    {
        QMessageBox msgBox(QMessageBox::Critical, tr("Data Error"),tr("No data available for saving."), 0);
        msgBox.exec();
        return;
    }
/*
    if(dataBundle[measType::er][frameNum] == NULL ||
            )
    {
        QMessageBox msgBox(QMessageBox::Critical, tr("Data Error"),tr("No data available for saving."), 0);
        msgBox.exec();
        return;
    }
*/

   if (dataBundleSaved == TRUE)
   {
       QMessageBox msgBox(QMessageBox::Information, tr("Data Saved"),tr("This data was already saved."), 0);
       msgBox.exec();
       qDebug()<<"dataProcessor::saveData - This data was already saved, dispBuffIndex: " << dispBuffIndex;
       return;
   }


   QDateTime now = QDateTime::currentDateTime();
   QString dataStoragePath = this->progDataPath + "\\Data\\Data"+now.toString("ddMMyy_hhmmss")+"\\";
   if( QDir(dataStoragePath).exists() == false)
       QDir().mkpath(dataStoragePath);
   //save the data related settings necessary for loading the data next time.

   filepath = dataStoragePath+"Setting(DoNotEdit).bin";
    myfileout.setFileName(filepath);
    if(!myfileout.open(QIODevice::WriteOnly))
    {
        QMessageBox errBox;
        errBox.setText("Could not open file for writing.");
        errBox.exec();
        return;
    }
    QDataStream out(&myfileout);
    out.setByteOrder(QDataStream::LittleEndian);
    out<<buffScanPoints;
    out<<buffScanHeight;
    out<<buffScanWidth;
    out<<buffScanInterval;
    out<<PnaSweepPoints;



    myfileout.close();

    //write the frequency range file
    filepath = dataStoragePath+"f.bin";

    myfileout.setFileName(filepath);
    if(!myfileout.open(QIODevice::WriteOnly))
    {
        QMessageBox errBox;
        errBox.setText("Could not open file for writing.");
        errBox.exec();
        return;
    }
    result=myfileout.write((char *)&f[0],sizeof(float)*PnaSweepPoints);
    myfileout.close();

    for (int fnum = 0; fnum<PnaSweepPoints; fnum++)
    {
        filepath = dataStoragePath+QString::number(fnum)+".bin";

        myfileout.setFileName(filepath);
        if(!myfileout.open(QIODevice::WriteOnly))
        {
            QMessageBox errBox;
            errBox.setText("Could not open file for writing.");
            errBox.exec();
            return;
        }

        for (index = 0; index < measType::noOfMeas; index++)
            result=myfileout.write((char *)&dataBundle[index][fnum][0],sizeof(float)*buffScanPoints);

        myfileout.close();

        //update current status
        emit updateProgressBar_dataProcessorSignal( ( (double)(fnum+1)/PnaSweepPoints)*100 );
        StatusTip.clear();
        QTextStream(&StatusTip)<<"Saving data frame: "<<fnum+1<<"/"<<PnaSweepPoints;
        emit updateStatusBar_dataProcessorSignal(StatusTip);

        QCoreApplication::processEvents();
    }
    dataBundleSaved = true;

    qDebug()<<"Filewriting Time: (msec)"<<timer.elapsed()<<"buffScanPoints"<<this->buffScanPoints<<"dispBuffIndex"<<this->dispBuffIndex;
}

void dataProcessor::saveDataSetting()
{
    QFile myfileout;
    QString filepath;

    QString dataStoragePath = this->progDataPath + "\\Data\\";
    if( QDir(dataStoragePath).exists() == false)
        QDir().mkpath(dataStoragePath);
    //save the data related settings necessary for loading the data next time.

    filepath = dataStoragePath+"Setting(DoNotEdit).bin";
     myfileout.setFileName(filepath);
     if(!myfileout.open(QIODevice::WriteOnly))
     {
         QMessageBox errBox;
         errBox.setText("Could not open file for writing.");
         errBox.exec();
         return;
     }
     QDataStream out(&myfileout);
     out.setByteOrder(QDataStream::LittleEndian);

     out<<settingInfoPtr->ScanPoints;
     out<<settingInfoPtr->scanHeight;
     out<<settingInfoPtr->scanWidth;
     out<<settingInfoPtr->scanInterval;

     myfileout.close();
}

bool dataProcessor::alloc2dArray(int rows,int columns,bool allocRptScanBuffOnly)
{ 
   timer.start();
   short dataBufnum = measType::noOfMeas;
   if(allocRptScanBuffOnly == false)
   {
       if ( (dataBundle = (float ***)calloc(dataBufnum,sizeof(float **))) == NULL)
            return 0;

       for (int i = 0;i<dataBufnum;i++)
       {
           if ( (dataBundle[i] = (float **)calloc(rows,sizeof(float *))) == NULL)
                return 0;

            for (int j = 0; j<rows; j++)
            {
                if( (dataBundle[i][j] = (float *)calloc(columns,sizeof (float))) == NULL)
                    return 0;
            }
       }
   }

   /*
   //initialize data
   for (int measType = 0;measType<measType::noOfMeas;measType++)
   {
       for (int frameNum = 0; frameNum<rows;frameNum++)
       {
           for (int pointNum = 0; pointNum<columns;pointNum++)
           {
               dataBundle[measType][frameNum][pointNum] = -1*measType - frameNum*0.25 - pointNum*0.15;
           }
       }
   }
*/
   //allocate the rpt scan accumulator buffer
   qDebug()<<timer.elapsed()<<"(msec) to declare the dataBuffer";
   qDebug()<<"dataProcessor::alloc2dArray";

   return 1;
}

bool dataProcessor::clear2dArray(int rows,int columns,bool clearRptScanBuffOnly)
{
    if(clearRptScanBuffOnly == false)
    {
        short dataBufnum = measType::noOfMeas;
        if (dataBundle == NULL)
        {
            qDebug()<<"Error: clear2dArray16bit - dataBundle is already free";
            return 0;
        }
        for (int i = 0; i<dataBufnum; i++)
        {
            for (int j = 0; j<rows; j++)
            {
                if(dataBundle[i][j] == NULL)
                {
                    qDebug()<<"Error: clear2dArray - dataBundle[i][j] is already free"<< i<<j;
                    break; //since allocation was sequential, no more rows allocated
                }
                free(dataBundle[i][j]);
                dataBundle[i][j] = NULL;
            }
            free(dataBundle[i]);
            dataBundle[i] = NULL;
        }
        free(dataBundle);
        dataBundle = NULL;
    }

    qDebug()<<"dataProcessor::clear2dArray";

    return 1;
}
bool dataProcessor::isMemValid(float*** dataBundle, int dispBuffIndex, int frameNum ,const char* callername,bool isSilent)
{
    bool return_val = false;
    QString ErrorMsg;
    if (dataBundle!=NULL)
    {
        if (dataBundle[dispBuffIndex] != NULL)
        {
            if(dataBundle[dispBuffIndex][frameNum] != NULL)
                return_val =  true;
            else
                ErrorMsg = QString(callername) +  " - dataBundle[" + QString::number(dispBuffIndex)+"]"+"["+QString::number(frameNum)+"] = NULL";

        }
        else
            ErrorMsg = QString(callername) +  " - dataBundle[" + QString::number(dispBuffIndex)+"] = NULL";
    }
    else
        ErrorMsg = QString(callername) +  " - dataBundle = NULL";

    if (return_val==false)
    {
        qDebug()<<ErrorMsg;
        if (isSilent == false)
        {
            QMessageBox msgBox(QMessageBox::Critical, tr("Memory Error"),ErrorMsg, 0);
            msgBox.exec();
        }
    }

    return return_val;
}

//FiltType = 1: median filter
//FiltType = 2: Spatial filter
//KrnlSize = 3 5 7 -> //KrnlRadius = 1 2 3

coreProcessor::coreProcessor(char filtType, char krnlRadius, short **input, short **output,
                             int x_length, int y_length,int startFrame, int endFrame,unsigned int buffScanPoints,unsigned int * vtwamResult)
{
    this->filtType    =  filtType;
    this->krnlRadius  =  krnlRadius;
    this->input       =  input;
    this->output      =  output;
    this->x_length    =  x_length;
    this->y_length    =  y_length;
    this->startFrame  =  startFrame;
    this->endFrame    =  endFrame;
    this->buffScanPoints = buffScanPoints;
    this->vtwamResult   = vtwamResult;
    this->wvfrmAcquired = -1;
    this->abortThread   = false;
}

coreProcessor::~coreProcessor()
{

}

void coreProcessor::setAbortThread()
{
    this->abortThread = true;
}

void coreProcessor::updateRowColNumAcquired(int wvfrmAcquiredArg)
{
    wvfrmAcquired = wvfrmAcquiredArg;
    //qDebug()<<"coreProcessor::updateRowColNumAcquired" <<wvfrmAcquired;
}

void coreProcessor::processParallel()
{
    int x,y,top,bottom,left,right,yKernel,xKernel,kernelDataIndex,frameNum,i,avgSum,j;
    int wvfrmProcessed = -1;
    int y_start=0,x_start=0,y_end=0,x_end=0;
    short value;
    int reqSignalsAfterCntr = (krnlRadius*x_length)+1;
    //krnlSz = (krnlRadius*2)+1;

    short kernelData[50]; // since max kernel size is 7x7
//    short *tempFrame = NULL;
    int pivot = (x_length-1)>>1;
    int xToUse;
/*
    if ( (tempFrame = (short *)calloc(x_length*y_length,sizeof(short))) == NULL)
    {
        qWarning("coreProcessor::process() - cant declare tempFrame ");
        emit finished();
    }
*/
    //while( wvfrmProcessed < ((x_length*y_length)-1) ) //start counting the waveforms from zero
    while( wvfrmProcessed < ((x_length*y_length)-1) - (reqSignalsAfterCntr) && abortThread==false )
    {
        /*
        qDebug()<<"coreProcessor::processParallel() - BeforeLoop"
                <<"wvfrmAcquired"<<wvfrmAcquired
                <<"((krnlRadius*x_length)+1) aka reqSignalsAfterCntr"<<reqSignalsAfterCntr
               <<"wvfrmProcessed"<<wvfrmProcessed
              <<"(wvfrmAcquired - ((krnlRadius*x_length)+1))"<<(wvfrmAcquired - reqSignalsAfterCntr);
        */
        while( (wvfrmAcquired < ((krnlRadius*x_length)+1) ||
               wvfrmProcessed == (wvfrmAcquired - reqSignalsAfterCntr)) &&
               (abortThread  == false)
               )
        {
            QCoreApplication::processEvents();
        }

        //just for debug print
       x_start = ((wvfrmProcessed+1) % x_length );
       x_end = ( (wvfrmAcquired - reqSignalsAfterCntr) % x_length );

       y_start = ((wvfrmProcessed+1) / x_length );
       y_end = ( (wvfrmAcquired - reqSignalsAfterCntr) / x_length );
        /*
       qDebug()<<"After Loop - coreProcessor::processParallel() - "
              <<"wvfrmProcessed"<<wvfrmProcessed<<"x_start"<<x_start<<"y_start"<<y_start
              <<"wvfrmAcquired"<<wvfrmAcquired<<"x_end"<<x_end<<"y_end"<<y_end
              <<"wvfrmAcquired - ((krnlRadius*x_length)+1)"<<wvfrmAcquired - reqSignalsAfterCntr
             <<"pivot"<<pivot;
        */

        for (frameNum = startFrame;frameNum<endFrame;frameNum++)
        {
            for (y = y_start; y <= y_end; y++)
            {
                //top     = MAX(y-krnlRadius,0);
                //bottom  = MIN(y+krnlRadius,y_length-1);
                top     = y-krnlRadius;
                bottom  = y+krnlRadius;
                if (y_start<y_end) //so two rows should be visited
                {
                    if (y == y_start)
                    {
                        x_start = ((wvfrmProcessed+1) % x_length );
                        x_end   = (x_length-1);
                    }
                    else if (y == y_end)
                    {
                        x_start = 0;
                        x_end   = ( (wvfrmAcquired - reqSignalsAfterCntr) % x_length );
                    }
                    else
                    {
                        x_start =    0;
                        x_end   =   (x_length-1);
                    }
                }
                for (x = x_start; x <= x_end; x++)
                {
                    if (y%2 != 0)
                        xToUse = (pivot-x)+pivot; //x_length-1 because the count starts from '0'
                    else
                        xToUse = x;

                    if ( (y < krnlRadius) ||
                         (y >= (y_length-krnlRadius)) ||
                         (xToUse < krnlRadius) ||
                         (xToUse >= (x_length-krnlRadius)) ) // for border pixels just copy without applying the filter
                    {
                        //no copy necessary in case of same buffer
                        if(output!=input)
                            output[frameNum][xToUse+y*x_length] = input[frameNum][xToUse+y*x_length];
                         /*
                         if (frameNum==100)
                         qDebug()<<"simple copy"<<"frameNum"<<frameNum<<"y: "<<y<<"xToUse: "<<xToUse<<"x:"<<x;
                        */
                        continue;
                    }

                    left    = xToUse-krnlRadius;
                    right   = xToUse+krnlRadius;

                    kernelDataIndex = 0;
                    for (yKernel = top; yKernel<=bottom; yKernel++)
                    {
                        for (xKernel = left; xKernel<=right; xKernel++)
                        {
                            kernelData[kernelDataIndex++] = input[frameNum][xKernel+yKernel*x_length];
                        }
                    }

                    switch (filtType)
                    {
                    case 1: //median
                            switch(krnlRadius)
                            {
                                case 1: value = optMed9(&kernelData[0]) ;break;
                                case 2: value = optMed25(&kernelData[0]);break;
                                case 3: value = optMed49(&kernelData[0]);break;
                                default: qWarning("coreProcessor::process() - Wrong krnlRadius for median filtering");
                                emit finished();break;
                            }
                        break;

                    case 2: //spatial Avg
                            avgSum = 0;
                            for (i = 0; i<kernelDataIndex;i++)
                                avgSum += kernelData[i];
                            value = avgSum/(kernelDataIndex);
                        break;

                    default:
                        qWarning("coreProcessor::process() - Wrong filtType");
                        emit finished();
                        break;
                    }
                    output[frameNum][xToUse+y*x_length] = value;
                    /*
                    if (frameNum==100)
                        qDebug()<<"main loop"<<"frameNum"<<frameNum<<"y:"<<y<<"xToUse:"<<xToUse<<"x:"<<x;
                    */
                }
            }
/*
            for(j = (wvfrmProcessed+1);j<=(wvfrmAcquired - reqSignalsAfterCntr) ;j++)
            {   int tempDebug;
                tempDebug = output[frameNum][j] = tempFrame[j];
            }
*/
        }
        emit updateProgress((frameNum+1),krnlRadius,filtType); //frame number 1~SAMPLESPERPOINT;

        wvfrmProcessed = wvfrmAcquired - reqSignalsAfterCntr;
    }

    //free(tempFrame);
    qDebug()<<QThread::currentThread();
    if (input!=output)
    {
        int j_real;
        for (frameNum = startFrame;frameNum<endFrame;frameNum++)
        {
            for(j = wvfrmProcessed+1;j<=wvfrmAcquired; j++)
            {
                if (((j/x_length) % 2) !=0) //odd row
                {
                    j_real = (pivot - (j%x_length))+pivot;
                    y = (j/x_length) * x_length;

                    j_real+=y;

                }
                else
                    j_real=j;

                output[frameNum][j_real] = input[frameNum][j_real];
            }
        }
    }
    emit finished();
}

void coreProcessor::processVtwam()
{
    unsigned int i;
    int j;
    unsigned int sum;

    if (this->startFrame > this->endFrame)
        SWAP(this->startFrame,this->endFrame);

    for (i=0;i<buffScanPoints;i++)
    {
        sum = 0;
        for (j = this->startFrame; j<=this->endFrame; j++)
        {
            //absolute sum of the corresponding point in frames start~end
            sum += qAbs(input[j][i]);
        }
        vtwamResult[i] = sum;
        if ((i%500) == 0)
            emit updateProgress((i+1),1,1);//frame number 1~SAMPLESPERPOINT;
    }

    qDebug()<<QThread::currentThread();
    emit finished();
}


void coreProcessor::process()
{
    int x,y,top,bottom,left,right,yKernel,xKernel,kernelDataIndex,frameNum,i,avgSum,j;
    short value;
    //krnlSz = (krnlRadius*2)+1;

    short kernelData[50]; // since max kernel size is 7x7
    short *tempFrame = NULL;

    if ( (tempFrame = (short *)calloc(x_length*y_length,sizeof(short))) == NULL)
    {
        qWarning("coreProcessor::process() - cant declare tempFrame ");
        emit finished();
    }
    qDebug()<<" coreProcessor::process Started"<<QThread::currentThread()<<
              "startFrame: "<<startFrame<<
              "endFrame"<<endFrame;

    //for (frameNum = 0;frameNum<SAMPLESPERPOINT;frameNum++)
    for (frameNum = startFrame;frameNum<endFrame;frameNum++)
    {
        for (y = 0; y < y_length; y++)
        {
            //top     = MAX(y-krnlRadius,0);
            //bottom  = MIN(y+krnlRadius,y_length-1);
            top     = y-krnlRadius;
            bottom  = y+krnlRadius;

            for (x = 0; x < x_length; x++)
            {
                if ( (y < krnlRadius) ||
                     (y >= (y_length-krnlRadius)) ||
                     (x < krnlRadius) ||
                     (x >= (x_length-krnlRadius)) ) // for border pixels just copy without applying the filter
                {
                     tempFrame[x+y*x_length] = input[frameNum][x+y*x_length];
                     continue;
                }

                //left    = MAX(x-krnlRadius,0);
                //right   = MIN(x+krnlRadius,x_length);

                left    = x-krnlRadius;
                right   = x+krnlRadius;

                kernelDataIndex = 0;
                for (yKernel = top; yKernel<=bottom; yKernel++)
                {
                    for (xKernel = left; xKernel<=right; xKernel++)
                    {
                        kernelData[kernelDataIndex++] = input[frameNum][xKernel+yKernel*x_length];
                    }
                }

                switch (filtType)
                {
                case 1: //median
                        switch(krnlRadius)
                        {
                            case 1: value = optMed9(&kernelData[0]) ;break;
                            case 2: value = optMed25(&kernelData[0]);break;
                            case 3: value = optMed49(&kernelData[0]);break;
                            default: qWarning("coreProcessor::process() - Wrong krnlRadius for median filtering");
                            emit finished();break;
                        }
                    break;

                case 2: //spatial Avg
                        avgSum = 0;
                        for (i = 0; i<kernelDataIndex;i++)
                            avgSum += kernelData[i];
                        value = avgSum/(kernelDataIndex);
                    break;

                default:
                    qWarning("coreProcessor::process() - Wrong filtType");
                    emit finished();
                    break;
                }
                tempFrame[x+y*x_length] = value;
            }
        }
        for(j = 0;j<(x_length*y_length) ;j++)
            output[frameNum][j] = tempFrame[j];

        if(startFrame==0)
            emit updateProgress((frameNum+1),krnlRadius,filtType);//frame number 1~SAMPLESPERPOINT;
    }

    free(tempFrame);
    qDebug()<<" coreProcessor::process finishing"<<QThread::currentThread()<<
              "startFrame: "<<startFrame<<
              "endFrame"<<endFrame;

    emit finished();
}

inline short coreProcessor::optMed9(short * p)
{
    SORT(p[1], p[2]) ; SORT(p[4], p[5]) ; SORT(p[7], p[8]) ;
    SORT(p[0], p[1]) ; SORT(p[3], p[4]) ; SORT(p[6], p[7]) ;
    SORT(p[1], p[2]) ; SORT(p[4], p[5]) ; SORT(p[7], p[8]) ;
    SORT(p[0], p[3]) ; SORT(p[5], p[8]) ; SORT(p[4], p[7]) ;
    SORT(p[3], p[6]) ; SORT(p[1], p[4]) ; SORT(p[2], p[5]) ;
    SORT(p[4], p[7]) ; SORT(p[4], p[2]) ; SORT(p[6], p[4]) ;
    SORT(p[4], p[2]) ; return(p[4]) ;
}

inline short coreProcessor::optMed25(short * p)
{
    SORT(p[0], p[1]) ; SORT(p[3], p[4]) ; SORT(p[2], p[4]) ;
    SORT(p[2], p[3]) ; SORT(p[6], p[7]) ; SORT(p[5], p[7]) ;
    SORT(p[5], p[6]) ; SORT(p[9], p[10]) ; SORT(p[8], p[10]) ;
    SORT(p[8], p[9]) ; SORT(p[12], p[13]) ; SORT(p[11], p[13]) ;
    SORT(p[11], p[12]) ; SORT(p[15], p[16]) ; SORT(p[14], p[16]) ;
    SORT(p[14], p[15]) ; SORT(p[18], p[19]) ; SORT(p[17], p[19]) ;
    SORT(p[17], p[18]) ; SORT(p[21], p[22]) ; SORT(p[20], p[22]) ;
    SORT(p[20], p[21]) ; SORT(p[23], p[24]) ; SORT(p[2], p[5]) ;
    SORT(p[3], p[6]) ; SORT(p[0], p[6]) ; SORT(p[0], p[3]) ;
    SORT(p[4], p[7]) ; SORT(p[1], p[7]) ; SORT(p[1], p[4]) ;
    SORT(p[11], p[14]) ; SORT(p[8], p[14]) ; SORT(p[8], p[11]) ;
    SORT(p[12], p[15]) ; SORT(p[9], p[15]) ; SORT(p[9], p[12]) ;
    SORT(p[13], p[16]) ; SORT(p[10], p[16]) ; SORT(p[10], p[13]) ;
    SORT(p[20], p[23]) ; SORT(p[17], p[23]) ; SORT(p[17], p[20]) ;
    SORT(p[21], p[24]) ; SORT(p[18], p[24]) ; SORT(p[18], p[21]) ;
    SORT(p[19], p[22]) ; SORT(p[8], p[17]) ; SORT(p[9], p[18]) ;
    SORT(p[0], p[18]) ; SORT(p[0], p[9]) ; SORT(p[10], p[19]) ;
    SORT(p[1], p[19]) ; SORT(p[1], p[10]) ; SORT(p[11], p[20]) ;
    SORT(p[2], p[20]) ; SORT(p[2], p[11]) ; SORT(p[12], p[21]) ;
    SORT(p[3], p[21]) ; SORT(p[3], p[12]) ; SORT(p[13], p[22]) ;
    SORT(p[4], p[22]) ; SORT(p[4], p[13]) ; SORT(p[14], p[23]) ;
    SORT(p[5], p[23]) ; SORT(p[5], p[14]) ; SORT(p[15], p[24]) ;
    SORT(p[6], p[24]) ; SORT(p[6], p[15]) ; SORT(p[7], p[16]) ;
    SORT(p[7], p[19]) ; SORT(p[13], p[21]) ; SORT(p[15], p[23]) ;
    SORT(p[7], p[13]) ; SORT(p[7], p[15]) ; SORT(p[1], p[9]) ;
    SORT(p[3], p[11]) ; SORT(p[5], p[17]) ; SORT(p[11], p[17]) ;
    SORT(p[9], p[17]) ; SORT(p[4], p[10]) ; SORT(p[6], p[12]) ;
    SORT(p[7], p[14]) ; SORT(p[4], p[6]) ; SORT(p[4], p[7]) ;
    SORT(p[12], p[14]) ; SORT(p[10], p[14]) ; SORT(p[6], p[7]) ;
    SORT(p[10], p[12]) ; SORT(p[6], p[10]) ; SORT(p[6], p[17]) ;
    SORT(p[12], p[17]) ; SORT(p[7], p[17]) ; SORT(p[7], p[10]) ;
    SORT(p[12], p[18]) ; SORT(p[7], p[12]) ; SORT(p[10], p[18]) ;
    SORT(p[12], p[20]) ; SORT(p[10], p[20]) ; SORT(p[10], p[12]) ;
    return (p[12]);
}

// for 7X7 filter
inline short coreProcessor::optMed49(short *p)
{
    short i,k;
    for (i=1; i<49; i++)
    {
        for (k = i; (k > 0 && p[k] < p[k-1]); k--)
            SWAP(p[k], p[k-1])
    }
    return (p[24]);
 }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------- movie making code from here onwards---------------------------//
//----------------------------------------------------------------------------------------------------------------------------//

// This is the internal structure represented by the HAVI handle:
typedef struct
{
    IAVIFile *pfile;    // created by CreateAvi
    WAVEFORMATEX wfx;   // as given to CreateAvi (.nChanels=0 if none was given). Used when audio stream is first created.
    int period;         // specified in CreateAvi, used when the video stream is first created
    IAVIStream *as;     // audio stream, initialised when audio stream is first created
    IAVIStream *ps, *psCompressed;  // video stream, when first created
    unsigned long nframe, nsamp;    // which frame will be added next, which sample will be added next
    bool iserr;         // if true, then no function will do anything
} TAviUtil;
HAVI CreateAvi(const char *fn, int frameperiod, const WAVEFORMATEX *wfx)
{
    IAVIFile *pfile;
    AVIFileInit();
    WCHAR y[255];
    LPCWSTR py = y;
    ::MultiByteToWideChar(0, 0, fn, -1, y, 255);
    HRESULT hr = AVIFileOpen(&pfile, py, OF_WRITE|OF_CREATE, NULL);
    if (hr != AVIERR_OK) {
        AVIFileExit();
        return NULL;
    }
    TAviUtil *au = new TAviUtil;
    au->pfile = pfile;
    if (wfx == NULL)
        ZeroMemory(&au->wfx, sizeof(WAVEFORMATEX));
    else
        CopyMemory(&au->wfx, wfx, sizeof(WAVEFORMATEX));
    au->period = frameperiod;
    au->as = 0;
    au->ps = 0;
    au->psCompressed = 0;
    au->nframe = 0;
    au->nsamp = 0;
    au->iserr = false;
    return (HAVI)au;
}
HRESULT CloseAvi(HAVI avi)
{
    if (avi == NULL)
        return AVIERR_BADHANDLE;
    TAviUtil *au = (TAviUtil*)avi;
    if (au->as != 0)
        AVIStreamRelease(au->as);
    au->as=0;
    if (au->psCompressed != 0)
        AVIStreamRelease(au->psCompressed);
    au->psCompressed = 0;
    if (au->ps != 0)
        AVIStreamRelease(au->ps);
    au->ps=0;
    if (au->pfile != 0)
        AVIFileRelease(au->pfile);
    au->pfile = 0;
    AVIFileExit();
    delete au;
    return S_OK;
}

HRESULT AddAviFrame(HAVI avi, HBITMAP hbm)
{
    if (avi == NULL)
        return AVIERR_BADHANDLE;
    if (hbm == NULL)
        return AVIERR_BADPARAM;
    DIBSECTION dibs;
    int sbm = GetObject(hbm, sizeof(dibs), &dibs);
    if (sbm != sizeof(DIBSECTION))
        return AVIERR_BADPARAM;
    TAviUtil *au = (TAviUtil*)avi;
    if (au->iserr)
        return AVIERR_ERROR;
    // create the stream, if it wasn't there before
    if (au->ps == 0) {
        AVISTREAMINFO strhdr;
        ZeroMemory(&strhdr,sizeof(strhdr));
        strhdr.fccType = streamtypeVIDEO;// stream type
        strhdr.fccHandler = 0;
        strhdr.dwScale = au->period;
        strhdr.dwRate = 1000;
        strhdr.dwSuggestedBufferSize  = dibs.dsBmih.biSizeImage;
        SetRect(&strhdr.rcFrame, 0, 0, dibs.dsBmih.biWidth, dibs.dsBmih.biHeight);
        HRESULT hr = AVIFileCreateStream(au->pfile, &au->ps, &strhdr);
        if (hr != AVIERR_OK) {
            au->iserr = true;
            return hr;
        }
    }
    //
    // create an empty compression, if the user hasn't set any
    if (au->psCompressed == 0) {
        AVICOMPRESSOPTIONS opts;
        ZeroMemory(&opts, sizeof(opts));
        //opts.
        opts.fccHandler = mmioFOURCC('D','I','B',' ');
        HRESULT hr = AVIMakeCompressedStream(&au->psCompressed, au->ps, &opts, NULL);
        if (hr != AVIERR_OK) {
            au->iserr = true;
            return hr;
        }
        hr = AVIStreamSetFormat(au->psCompressed, 0, &dibs.dsBmih, dibs.dsBmih.biSize+dibs.dsBmih.biClrUsed*sizeof(RGBQUAD));
        if (hr != AVIERR_OK) {
            au->iserr = true;
            return hr;
        }
    }
    //
    //Now we can add the frame
    HRESULT hr = AVIStreamWrite(au->psCompressed, au->nframe, 1, dibs.dsBm.bmBits, dibs.dsBmih.biSizeImage, AVIIF_KEYFRAME, NULL, NULL);
    if (hr != AVIERR_OK) {
        au->iserr = true;
        return hr;
    }
    au->nframe++; return S_OK;
}

void dataProcessor::loadCoordinates(bool status)
{
    timer.start();
    qint64 result;
    QString StatusTip;

    unsigned int buffScanPointsLoc;
    int buffScanHeightLoc;
    int buffScanWidthLoc;

    //ui->UpdateSettingParStruct();

    buffScanPointsLoc   = settingInfoPtr->ScanPoints;
    buffScanWidthLoc    = settingInfoPtr->xLength;
    buffScanHeightLoc   = settingInfoPtr->ZPoints;

    qDebug()<<"dataProcessor::loadCoordinates"<<
              "buffScanWidthLoc "<<buffScanWidthLoc<<
              "buffScanHeightLoc"<< buffScanHeightLoc;
    if(runtimeNo == 0) //if first time than clear erray
    {
        for (int j=0; j<100;j++)
        {
            for (int index=0; index<2;index++)
            {
                for (int i=0; i<100;i++)
                {
                    Coordinates[j][index][i]=NULL;
                }
            }
        }
        runtimeNo++;
    }


    if(Coordinates [0][0][0] != NULL)
    {
        int result;
        QMessageBox msgBox(QMessageBox::Question, tr("Coordinates"),tr("Coordinates are already loaded. Do you want to overwrite those coordinates ?"),
                           QMessageBox::Yes|QMessageBox::No);
        result = msgBox.exec();

        if (result ==QMessageBox::No)
        return;
    }
    if(settingInfoPtr->scanInterval != 10)
    {
        int result;
        QMessageBox msgBox(QMessageBox::Question, tr("Interval"),tr("Interval is not set to 10 mm. Do you still want to uplaod these coordinates ?"),
                           QMessageBox::Yes|QMessageBox::No);
        result = msgBox.exec();

        if (result ==QMessageBox::No)
        return;
    }
    // if (!allocateMemCoor())
    // return;

    QString filter = "All File (*.*);; Text File (*.txt);; XML File (*.xml);; STL File (*.stl);; BIN File (*.bin)";
    QString file_name = QFileDialog::getOpenFileName(NULL,tr("Open Coordinates file"),"C:/Users/SSL/Desktop/Salahdata",filter);
    qDebug()<<file_name;
    QFile file (file_name);


     if(!file.open(QIODevice::ReadOnly))
     {
         QMessageBox msgBox(QMessageBox::Critical, tr("File Error"),tr("Could'nt open Coordinates file for reading."), 0);
         msgBox.exec();
         return;
     }
/*   QDataStream in(&file);
     QTextStream text(&file);
     in.readBytes();
     text.readAll();
     in.setByteOrder(QDataStream::LittleEndian);*/
     for (int fnum = 0; fnum<buffScanHeightLoc; fnum++)
     {
         for(int index=0; index<2; index++)
         {
             result=file.read((char *)&Coordinates[fnum][index][0],sizeof(float)*buffScanWidthLoc);
             qDebug()<<result ;
         }
         for (int i = 0; i<buffScanWidthLoc; i++)
         {
             qDebug()<< Coordinates[fnum][0][i]<<"  "<< Coordinates[fnum][1][i];
         }



         //update current status
         emit updateProgressBar_dataProcessorSignal( ( (double)(fnum+1)/buffScanHeightLoc)*100 );
         StatusTip.clear();
         QTextStream(&StatusTip)<<"Loading data frame: "<<fnum+1<<"/"<<buffScanHeightLoc;
         emit updateStatusBar_dataProcessorSignal(StatusTip);

         QCoreApplication::processEvents();
         qDebug()<<"File Reading Time: (msec)"<<timer.elapsed();
    }
     file.close();
     loadCoordinatesDone = true;

}


float dataProcessor::AngleCalc(float X, float Y, float CRX , float CRY, float CORX, float CORY)
{
    Dot_product = ((CRX-X)*(CORX-X))+((CRY-Y)*(CORY-Y));
    Magnitude   = (sqrt(pow((CRX-X),2)+pow((CRY-Y),2)))*(sqrt(pow((CORX-X),2)+pow((CORY-Y),2)));
    theta       = acos(abs(Dot_product/Magnitude))*180/M_PI;
    return      theta;
}
void dataProcessor::CalculateParameters()
{
    int buffScanWidthLoc    = settingInfoPtr->xLength;
    int buffScanHeightLoc   = settingInfoPtr->ZPoints;

    //calculating parameters

    Center_of_Rotation [0]= 0;
    Center_of_Rotation [1]= 0;
    //Bringing the specimen coordinates to the first quadrant
    for (int j=0;j<buffScanHeightLoc;j++)
    {
        X_translator[j] = Coordinates[j][0][0]-0;
        Y_translator[j] = Coordinates[j][1][0]-0;
        for (int i=0; i<buffScanWidthLoc;i++)
        {
            //Translated coordinates
            Coordinates[j][0][i] = Coordinates[j][0][i]-X_translator[j];
            Coordinates[j][1][i] = Coordinates[j][1][i]-Y_translator[j];
            qDebug()<< Coordinates[j][0][i]<<"   "<<Coordinates[j][1][i];
        }

        //Estimation of extra points for end point curvature caculation
        special_Xo[j] = 3*Coordinates[j][0][0]-3*Coordinates[j][0][1]+Coordinates[j][0][2];
        special_Yo[j] = 3*Coordinates[j][1][0]-3*Coordinates[j][1][1]+Coordinates[j][1][2];
        special_Xn[j] = 3*Coordinates[j][0][buffScanWidthLoc-1]-3*Coordinates[j][0][buffScanWidthLoc-2]+ Coordinates[j][0][buffScanWidthLoc-3];
        special_Yn[j] = 3*Coordinates[j][1][buffScanWidthLoc-1]-3*Coordinates[j][1][buffScanWidthLoc-2]+ Coordinates[j][1][buffScanWidthLoc-3];

        //Calculate scan parameters
        for (int i=0; i<(buffScanWidthLoc+1);i++)
        {

            if (i==0)                      // if first point
            {
                Chord_Mid [j][0][i] = (special_Xo[j]+ Coordinates[j][0][i])/2; // X
                Chord_Mid [j][1][i] = (special_Yo[j]+ Coordinates[j][1][i])/2; // Y

                //Slope's of chords
                Chord_Slope [j][i]= ((special_Yo[j] - Coordinates[j][1][i])/(special_Xo[j] - Coordinates[j][0][i])); //

                //Slope's of perpendicular bisector of chords
                P_Bisector [j][i] = (-1/Chord_Slope [j][i]);
            }

            else if  (0 < i &&  i < buffScanWidthLoc)
            {
                //Mid Points of chords
                Chord_Mid [j][0][i] = (Coordinates[j][0][i-1]+ Coordinates[j][0][i])/2; // X
                Chord_Mid [j][1][i] = (Coordinates[j][1][i-1]+ Coordinates[j][1][i])/2; // Y

                //Slope's of chords
                Chord_Slope [j][i] = (Coordinates[j][1][i-1]- Coordinates[j][1][i])/(Coordinates[j][0][i-1]- Coordinates[j][0][i]); //

                //Slope's of perpendicular bisector of chords
                P_Bisector [j][i] = (-1/Chord_Slope [j][i]);
            }

            else if (i == buffScanWidthLoc)        // if last point
            {
                Chord_Mid [j][0][i] = (Coordinates[j][0][i-1] + special_Xn[j])/2; // X
                Chord_Mid [j][1][i] = (Coordinates[j][1][i-1] + special_Yn[j])/2; // Y

                //Slope's of chords
                Chord_Slope [j][i] = (Coordinates[j][1][i-1] - special_Yn[j])/(Coordinates[j][0][i-1] - special_Xn[j]); //

                //Slope's of perpendicular bisector of chords
                P_Bisector [j][i] = (-1/Chord_Slope [j][i]);
            }
            //qDebug()<< Chord_Mid [j][0][i]<<"   "<<Chord_Mid [j][1][i]<<"  "<< Chord_Slope [j][i]<<"   "<<P_Bisector [j][i];
        }
        for (int i=0;i<buffScanWidthLoc;i++)
        {

            //Center of circle
            Center[j][0][i] = ((- Chord_Mid [j][1][i] + Chord_Mid [j][1][i+1] + (P_Bisector [j][i]*Chord_Mid [j][0][i]) - (P_Bisector [j][i+1]*Chord_Mid [j][0][i+1]))/(P_Bisector [j][i]-P_Bisector [j][i+1])); // X
            Center[j][1][i] = (P_Bisector [j][i] * ( Center [j][0][i] - Chord_Mid [j][0][i]) + Chord_Mid [j][1][i]); // Y

            //Radius's of curvature
            Radius[j][i] = sqrt(pow((Center[j][0][i]-Coordinates[j][0][i]),2)+pow((Center[j][1][i]-Coordinates[j][1][i]),2));
            //qDebug()<< Center[j][0][i]<<"   "<<Center[j][1][i]<<"   "<< Radius[j][i];
            qDebug()<< Radius[j][i];
        }
        for (int i=0;i<buffScanWidthLoc;i++)
        {
            //Center of Rotations X value
            if (Coordinates[0][1][i]>Center_of_Rotation[1]) // if Y value of coordinate if greater than center Y value
            {
                //Center_of_Rotation(1)=XY_S(i,1);
                Center_of_Rotation[1] = Coordinates[0][1][i];
                CentralValue_X = i;
            }
        }
        //qDebug()<<CentralValue_X;

        for (int z=0;z<CentralValue_X;z++)
        {
            //Center of rotational stage
            Center_of_Rotation[0]= (Coordinates[0][0][z]+Coordinates[0][0][(buffScanWidthLoc-z-1)])/2;
            Center_of_Rotation[1]= Coordinates[0][1][z];
            //Calculate Incident angles
            for (int i=0;i<buffScanWidthLoc;i++)
            {
                //Incident Angles for Rotational stage
                Incident_Angle_R[j][z][i] = AngleCalc(Coordinates[j][0][i], Coordinates[j][1][i], Center_of_Rotation[0] , Center_of_Rotation[1], Center[j][0][i], Center[j][1][i]);

                //Incident Angles for Linear stage
                Incident_Angle_L[j][z][i] = AngleCalc(Coordinates[j][0][i], Coordinates[j][1][i], Center_of_Rotation[0] , Coordinates[j][1][i], Center[j][0][i], Center[j][1][i]);
                //qDebug()<<Incident_Angle_R[j][z][i]<< "    "<<Incident_Angle_L[j][z][i];
            }
        }
        for (int z=0; z<CentralValue_X;z++)
        {

            Center_of_Rotation[0]= (Coordinates[0][0][z]+Coordinates[0][0][(buffScanWidthLoc-z-1)])/2;
            Center_of_Rotation[1]= Coordinates[0][1][z];
            Total_IA       [j][z] = 0;
            Average_IA     [j][z] = 0;
            No_of_Values   [j][z] = 0;
            Total_AOFR     [j][z] = 0;
            int b = 0;

            for (int i=0;i<buffScanWidthLoc;i++)
            {

                if (i == 0)
                {
                    Increment_Angle[j][z][i]=0;
                    Increment_Linear[j][z][i]=0;
                }
                else
                {
                    Increment_Angle[j][z][i]=AngleCalc(Center_of_Rotation[0] , Center_of_Rotation[1],Coordinates[j][0][i-1], Coordinates[j][1][i-1],Coordinates[j][0][i], Coordinates[j][1][i]);
                    Total_AOFR[j][z] = Total_AOFR[j][z]+Increment_Angle[j][z][i];
                    Increment_Linear[j][z][i]=abs(Coordinates[j][1][i-1]-Coordinates[j][1][i]);
                }

                if (Incident_Angle_R[j][z][i] <= Incident_Angle_L[j][z][i] &&  Coordinates[j][1][i]>=Center_of_Rotation[1])//Effective portion angle
                {
                    Final_IA_R[j][z][i]= Incident_Angle_R[j][z][i];
                    Final_IA_L[j][z][i]= 0;
                    b++;
                    Total_IA[j][z]= Total_IA[j][z]+ Final_IA_R[j][z][i];
                    No_of_Values [j][z]= No_of_Values [j][z]+1;
                    if(b==1)
                    {
                        Increment_Angle_RF[j][z][i]=0;
                        Increment_Linear_F[j][z][i]= Increment_Linear[j][z][i];
                    }
                    else
                    {
                        Increment_Angle_RF[j][z][i]=Increment_Angle[j][z][i];
                        Increment_Linear_F[j][z][i]=0;
                    }
                }
                else
                {
                    Final_IA_R[j][z][i]= 0;
                    Final_IA_L[j][z][i]= Incident_Angle_L[j][z][i];
                    Increment_Angle_RF[j][z][i]=0;
                    Increment_Linear_F[j][z][i]= Increment_Linear[j][z][i];
                }
            }
            Average_IA[j][z] = Total_IA[j][z]/(No_of_Values [j][z]);
            //qDebug()<<Average_IA[j][z];
        }

        float lowest_Average_IA=100;
        for (int z=0; z<CentralValue_X;z++)
        {
            if (Average_IA[0][z]<= lowest_Average_IA)
            {
                lowest_Average_IA = Average_IA[0][z];
                CentralValue_Y = z;
            }
        }
        if(settingInfoPtr->AchieveLowIA)//Reduce incident angle by utilizing both the stages
        {
            Center_of_Rotation[0]=(Coordinates[0][0][CentralValue_Y]+Coordinates[0][0][(buffScanWidthLoc-CentralValue_Y-1)])/2;
            Center_of_Rotation[1]=Coordinates[0][1][CentralValue_Y];
            settingInfoPtr->Materialshape = "Zero Incident Angle";
            for(int i=0;i<buffScanWidthLoc;i++)
            {
                //Move coordinates to rotational stage position
                X[j][i]= Coordinates[j][0][i]-Center_of_Rotation[0];
                Y[j][i]= Coordinates[j][1][i]-Center_of_Rotation[1];
                qDebug()<<X[j][i]<<"  "<<Y[j][i];
            }
            thetaR = 0;
            for(int i=0;i<buffScanWidthLoc;i++)
            {
                if (i==0)
                {
                    settingInfoPtr->DegreeIntervalV[j][i] = Incident_Angle_L[j][CentralValue_Y][i];//180-Incident_Angle_L[j][CentralValue_Y][i]

                }
                else
                {
                    if(i<=CentralValue_X)//
                    {
                        /*if(Incident_Angle_L[j][CentralValue_Y][i]>=Incident_Angle_L[j][CentralValue_Y][i-1])
                        {
                            settingInfoPtr->DegreeIntervalV[j][i] = (Incident_Angle_L[j][CentralValue_Y][i-1]-Incident_Angle_L[j][CentralValue_Y][i]);
                        }
                        else
                        {
                            settingInfoPtr->DegreeIntervalV[j][i] = (Incident_Angle_L[j][CentralValue_Y][i]-Incident_Angle_L[j][CentralValue_Y][i-1]);
                        }
                        */settingInfoPtr->DegreeIntervalV[j][i] = (Incident_Angle_L[j][CentralValue_Y][i]-Incident_Angle_L[j][CentralValue_Y][i-1]);
                    }
                    else
                    {
                        /*if(Incident_Angle_L[j][CentralValue_Y][i]>=Incident_Angle_L[j][CentralValue_Y][i-1])
                        {
                            settingInfoPtr->DegreeIntervalV[j][i] = (Incident_Angle_L[j][CentralValue_Y][i]-Incident_Angle_L[j][CentralValue_Y][i-1]);
                        }
                        else
                        {
                            settingInfoPtr->DegreeIntervalV[j][i] = (Incident_Angle_L[j][CentralValue_Y][i-1]-Incident_Angle_L[j][CentralValue_Y][i]);
                        }
                        */settingInfoPtr->DegreeIntervalV[j][i] = (Incident_Angle_L[j][CentralValue_Y][i-1]-Incident_Angle_L[j][CentralValue_Y][i]);
                    }
                }
                thetaR = thetaR + settingInfoPtr->DegreeIntervalV[j][i];

                XR[j][i]= X[j][i]*cos(thetaR/180*M_PI)-Y[j][i]*sin(thetaR/180*M_PI);
                YR[j][i]= X[j][i]*sin(thetaR/180*M_PI)+Y[j][i]*cos(thetaR/180*M_PI);
                referencePoint[j][i] = 450-abs(XR[j][i]);
                if(i==0)
                {
                    settingInfoPtr->LinearIntervalV[j][i]= -YR[j][i];
                    settingInfoPtr->InitialStep = YR[j][i]-Y[j][i];
                    settingInfoPtr->InitialStep = YR[j][i]-Y[j][i];
                }
                else
                {
                    settingInfoPtr->LinearIntervalV[j][i]= YR[j][i-1]-YR[j][i];
                }
                Final_IA[j][i] = 0;
                qDebug()<<i<<"    "<<referencePoint[j][i]<<"       "<<settingInfoPtr->LinearIntervalV[j][i]<<"        "<<settingInfoPtr->DegreeIntervalV[j][i]<<"        "<<thetaR<<"         "<<Incident_Angle_L[j][CentralValue_Y][i];
            }

        }
        else
        {
            settingInfoPtr->Materialshape = "Leading Edge Specimen";
            for(int i=0;i<buffScanWidthLoc;i++)
            {
                Final_IA[j][i] = Final_IA_R[j][CentralValue_Y][i]+Final_IA_L[j][CentralValue_Y][i];
                settingInfoPtr->DegreeIntervalV[j][i] = Increment_Angle_RF[j][CentralValue_Y][i];
                settingInfoPtr->LinearIntervalV[j][i] = Increment_Linear_F[j][CentralValue_Y][i];
                //qDebug()<<settingInfoPtr->DegreeIntervalV[j][i]<<"   "<<settingInfoPtr->LinearIntervalV[j][i];
                qDebug()<<i<<"      "<<settingInfoPtr->DegreeIntervalV[j][i] <<"      "<<settingInfoPtr->LinearIntervalV[j][i];
            }
        }

    }
    settingInfoPtr->CenterOfRotation[0]= (Coordinates[0][0][CentralValue_Y]+Coordinates[0][0][(buffScanWidthLoc-CentralValue_Y-1)])/2;
    settingInfoPtr->CenterOfRotation[1]= Coordinates[0][1][CentralValue_Y];

    emit CalcParametersDone();
}
