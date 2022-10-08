/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mainwindow.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionAbout;
    QAction *actionAL_CFRP;
    QAction *actionKAF_Standard;
    QAction *actionPulse_Energy_Table;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Setting;
    QPushButton *pushButtonStart;
    QGroupBox *groupBox_5;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_15;
    QLabel *labelScanHeight_5;
    QLineEdit *lineEditPnametalPlateThickness;
    QHBoxLayout *horizontalLayout_18;
    QLabel *labelScanHeight_7;
    QLineEdit *lineEditPnasampleThickness;
    QHBoxLayout *horizontalLayout_16;
    QLabel *labelScanHeight_6;
    QLineEdit *lineEditPnadistToSample;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_17;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelScanInterval_5;
    QLineEdit *lineEditPnaPower;
    QHBoxLayout *horizontalLayout;
    QLabel *labelScanHeight_4;
    QLineEdit *lineEditPnaIFBW;
    QPushButton *pushButtonPnaConfig;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelScanHeight_3;
    QLineEdit *lineEditPnaStartFreq;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelScanInterval_4;
    QLineEdit *lineEditPnaStopFreq;
    QHBoxLayout *horizontalLayout_13;
    QLabel *labelScanWidth_4;
    QComboBox *enumPnaSweepPoints;
    QGroupBox *groupBoxScan;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *labelScanHeight_2;
    QLineEdit *lineEditScanHeight;
    QLabel *labelScanWidth_2;
    QLineEdit *lineEditScanWidth;
    QLabel *labelScanInterval_3;
    QComboBox *enumScanInterval;
    QSplitter *splitter_3;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelMaterialShape;
    QComboBox *enumMaterialShape;
    QSplitter *splitter;
    QWidget *widget2;
    QFormLayout *formLayout_2;
    QLabel *labelRadius;
    QLineEdit *lineEditRadius;
    QLabel *labelArcLength;
    QLineEdit *lineEditArclength;
    QWidget *layoutWidget_6;
    QVBoxLayout *verticalLayout_24;
    QLabel *labelHeightCoordinates;
    QLineEdit *lineEditHeightCoordinates;
    QWidget *widgetOscilloscope;
    QGroupBox *groupBox_1;
    QHBoxLayout *horizontalLayout_25;
    QSplitter *splitter_2;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_7;
    QComboBox *enumMaterials;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_8;
    QComboBox *enumThickness;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_9;
    QComboBox *enumRef;
    QPushButton *pushButtonPnaMeasure;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_22;
    QLabel *labelScanWidth_5;
    QComboBox *enumMeasType;
    QPushButton *pushButtonQuit;
    QGroupBox *groupBox_Coordinates;
    QSplitter *splitter_4;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_24;
    QPushButton *pushButton_LoadCoordinates;
    QPushButton *pushButton_CalaculateParameters;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_10;
    QLabel *label_XValue;
    QComboBox *enumGraphType;
    QCustomPlot *customPlot;
    QCheckBox *checkBoxIA;
    QGroupBox *groupBox_6;
    QWidget *layoutWidget_12;
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonSetpos;
    QLineEdit *lineEditZPos;
    QPushButton *pushButtonGetpos;
    QLCDNumber *lcdNumberZpos;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEditRobAngleTheta;
    QLCDNumber *lcdNumberRobAngleTheta;
    QLabel *label_15;
    QLCDNumber *lcdNumberYpos;
    QLineEdit *lineEditYPos;
    QLineEdit *lineEditRobAnglePhi;
    QLabel *label_19;
    QLabel *label_13;
    QLCDNumber *lcdNumberXpos;
    QLineEdit *lineEditXpos;
    QLCDNumber *lcdNumberRobAnglePhi;
    QCheckBox *checkBoxRobotControllerSelect;
    QSplitter *splitter_5;
    QSplitter *splitter_8;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_28;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButtonJogzp;
    QSpacerItem *horizontalSpacer_11;
    QWidget *layoutWidget_10;
    QHBoxLayout *horizontalLayout_35;
    QPushButton *pushButtonJogyp;
    QPushButton *pushButtonOrigin;
    QPushButton *pushButtonJogyn;
    QWidget *layoutWidget_11;
    QHBoxLayout *horizontalLayout_36;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButtonJogzn;
    QSpacerItem *horizontalSpacer_13;
    QWidget *layoutWidget_13;
    QVBoxLayout *verticalLayout_32;
    QPushButton *pushButtonJogxp;
    QPushButton *pushButtonJogxn;
    QPushButton *pushButtonServoStop;
    QWidget *Result;
    QScrollArea *scrollArea;
    QWidget *widgettResultSpect;
    QWidget *widgetResultTime;
    QLabel *labelCurrentDataSpec;
    QWidget *widgetVtwam;
    QWidget *widgetResultControl;
    QGroupBox *groupBoxResultControl;
    QHBoxLayout *horizontalLayout_21;
    QHBoxLayout *horizontalLayout_20;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_17;
    QComboBox *enumMeasType_2;
    QComboBox *enumPlaySpeed;
    QPushButton *pushButtonPlayPause;
    QPushButton *pushButtonCapture;
    QPushButton *pushButtonSaveMovie;
    QPushButton *pushButtonEnlarge;
    QHBoxLayout *horizontalLayout_26;
    MySlider *horizontalSliderFrame;
    QLabel *labelFrame;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_9;
    QDial *dial_intensity;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *checkBoxGreyscale;
    QVBoxLayout *verticalLayout_21;
    QDial *dial_intensity_2;
    QSpacerItem *verticalSpacer_2;
    QProgressBar *progressBar;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_33;
    QPushButton *pushButtonLoadData;
    QPushButton *pushButtonSaveData;
    QGroupBox *groupBoxFilter;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_25;
    QVBoxLayout *verticalLayout_23;
    QGroupBox *groupBoxFilterStep1;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelImageFilterIterations;
    QComboBox *enumImageFilterIterations;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelImageFilterType;
    QComboBox *enumImageFilterType;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelImageFilterSize;
    QComboBox *enumImageFilterSize;
    QGroupBox *groupBoxFilterStep2;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_15;
    QVBoxLayout *verticalLayout_16;
    QLabel *labelImageFilterIterations_2;
    QComboBox *enumImageFilterIterations_2;
    QVBoxLayout *verticalLayout_20;
    QLabel *labelImageFilterType_2;
    QComboBox *enumImageFilterType_2;
    QVBoxLayout *verticalLayout_22;
    QLabel *labelImageFilterSize_2;
    QComboBox *enumImageFilterSize_2;
    QCheckBox *checkBoxBoostSpeed;
    QPushButton *pushButtonProcessFilter;
    QGroupBox *groupBoxVtwam;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_33;
    QLineEdit *lineEditVtwamStart;
    QLabel *labelVtwamStart;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_34;
    QLineEdit *lineEditVtwamEnd;
    QLabel *labelVtwamEnd;
    QPushButton *pushButtonProcessVtwam;
    QPushButton *pushButtonCaptureVtwam;
    QPushButton *pushButtonServoStop2;
    QPushButton *pushButtonSaveDataCurrent;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1940, 1213);
        MainWindow->setIconSize(QSize(24, 24));
        MainWindow->setAnimated(false);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral("images/save.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSave->setIcon(icon);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAL_CFRP = new QAction(MainWindow);
        actionAL_CFRP->setObjectName(QStringLiteral("actionAL_CFRP"));
        actionKAF_Standard = new QAction(MainWindow);
        actionKAF_Standard->setObjectName(QStringLiteral("actionKAF_Standard"));
        actionPulse_Energy_Table = new QAction(MainWindow);
        actionPulse_Energy_Table->setObjectName(QStringLiteral("actionPulse_Energy_Table"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 2001, 1181));
        Setting = new QWidget();
        Setting->setObjectName(QStringLiteral("Setting"));
        pushButtonStart = new QPushButton(Setting);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));
        pushButtonStart->setGeometry(QRect(300, 420, 215, 49));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonStart->sizePolicy().hasHeightForWidth());
        pushButtonStart->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        pushButtonStart->setFont(font);
        groupBox_5 = new QGroupBox(Setting);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 260, 801, 141));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        groupBox_5->setFont(font1);
        layoutWidget = new QWidget(groupBox_5);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(240, 29, 281, 82));
        verticalLayout_14 = new QVBoxLayout(layoutWidget);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        labelScanHeight_5 = new QLabel(layoutWidget);
        labelScanHeight_5->setObjectName(QStringLiteral("labelScanHeight_5"));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        labelScanHeight_5->setFont(font2);

        horizontalLayout_15->addWidget(labelScanHeight_5);

        lineEditPnametalPlateThickness = new QLineEdit(layoutWidget);
        lineEditPnametalPlateThickness->setObjectName(QStringLiteral("lineEditPnametalPlateThickness"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditPnametalPlateThickness->sizePolicy().hasHeightForWidth());
        lineEditPnametalPlateThickness->setSizePolicy(sizePolicy1);
        lineEditPnametalPlateThickness->setMaximumSize(QSize(70, 20));
        lineEditPnametalPlateThickness->setFont(font2);
        lineEditPnametalPlateThickness->setToolTipDuration(1000);
#ifndef QT_NO_STATUSTIP
        lineEditPnametalPlateThickness->setStatusTip(QStringLiteral(""));
#endif // QT_NO_STATUSTIP
        lineEditPnametalPlateThickness->setMaxLength(5);
        lineEditPnametalPlateThickness->setFrame(true);
        lineEditPnametalPlateThickness->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPnametalPlateThickness->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEditPnametalPlateThickness->setClearButtonEnabled(false);

        horizontalLayout_15->addWidget(lineEditPnametalPlateThickness);


        verticalLayout_14->addLayout(horizontalLayout_15);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        labelScanHeight_7 = new QLabel(layoutWidget);
        labelScanHeight_7->setObjectName(QStringLiteral("labelScanHeight_7"));
        labelScanHeight_7->setFont(font2);

        horizontalLayout_18->addWidget(labelScanHeight_7);

        lineEditPnasampleThickness = new QLineEdit(layoutWidget);
        lineEditPnasampleThickness->setObjectName(QStringLiteral("lineEditPnasampleThickness"));
        sizePolicy1.setHeightForWidth(lineEditPnasampleThickness->sizePolicy().hasHeightForWidth());
        lineEditPnasampleThickness->setSizePolicy(sizePolicy1);
        lineEditPnasampleThickness->setMaximumSize(QSize(70, 20));
        lineEditPnasampleThickness->setFont(font2);
        lineEditPnasampleThickness->setToolTipDuration(1000);
#ifndef QT_NO_STATUSTIP
        lineEditPnasampleThickness->setStatusTip(QStringLiteral(""));
#endif // QT_NO_STATUSTIP
        lineEditPnasampleThickness->setMaxLength(5);
        lineEditPnasampleThickness->setFrame(true);
        lineEditPnasampleThickness->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPnasampleThickness->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEditPnasampleThickness->setClearButtonEnabled(false);

        horizontalLayout_18->addWidget(lineEditPnasampleThickness);


        verticalLayout_14->addLayout(horizontalLayout_18);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        labelScanHeight_6 = new QLabel(layoutWidget);
        labelScanHeight_6->setObjectName(QStringLiteral("labelScanHeight_6"));
        labelScanHeight_6->setFont(font2);

        horizontalLayout_16->addWidget(labelScanHeight_6);

        lineEditPnadistToSample = new QLineEdit(layoutWidget);
        lineEditPnadistToSample->setObjectName(QStringLiteral("lineEditPnadistToSample"));
        sizePolicy1.setHeightForWidth(lineEditPnadistToSample->sizePolicy().hasHeightForWidth());
        lineEditPnadistToSample->setSizePolicy(sizePolicy1);
        lineEditPnadistToSample->setMaximumSize(QSize(70, 20));
        lineEditPnadistToSample->setFont(font2);
        lineEditPnadistToSample->setToolTipDuration(1000);
#ifndef QT_NO_STATUSTIP
        lineEditPnadistToSample->setStatusTip(QStringLiteral(""));
#endif // QT_NO_STATUSTIP
        lineEditPnadistToSample->setMaxLength(5);
        lineEditPnadistToSample->setFrame(true);
        lineEditPnadistToSample->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPnadistToSample->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEditPnadistToSample->setClearButtonEnabled(false);

        horizontalLayout_16->addWidget(lineEditPnadistToSample);


        verticalLayout_14->addLayout(horizontalLayout_16);

        layoutWidget1 = new QWidget(groupBox_5);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(570, 29, 191, 90));
        verticalLayout_17 = new QVBoxLayout(layoutWidget1);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelScanInterval_5 = new QLabel(layoutWidget1);
        labelScanInterval_5->setObjectName(QStringLiteral("labelScanInterval_5"));
        labelScanInterval_5->setFont(font2);

        horizontalLayout_6->addWidget(labelScanInterval_5);

        lineEditPnaPower = new QLineEdit(layoutWidget1);
        lineEditPnaPower->setObjectName(QStringLiteral("lineEditPnaPower"));
        sizePolicy1.setHeightForWidth(lineEditPnaPower->sizePolicy().hasHeightForWidth());
        lineEditPnaPower->setSizePolicy(sizePolicy1);
        lineEditPnaPower->setMaximumSize(QSize(70, 22));
        lineEditPnaPower->setFont(font2);
        lineEditPnaPower->setMaxLength(5);
        lineEditPnaPower->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(lineEditPnaPower);


        verticalLayout_17->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelScanHeight_4 = new QLabel(layoutWidget1);
        labelScanHeight_4->setObjectName(QStringLiteral("labelScanHeight_4"));
        labelScanHeight_4->setFont(font2);

        horizontalLayout->addWidget(labelScanHeight_4);

        lineEditPnaIFBW = new QLineEdit(layoutWidget1);
        lineEditPnaIFBW->setObjectName(QStringLiteral("lineEditPnaIFBW"));
        sizePolicy1.setHeightForWidth(lineEditPnaIFBW->sizePolicy().hasHeightForWidth());
        lineEditPnaIFBW->setSizePolicy(sizePolicy1);
        lineEditPnaIFBW->setMaximumSize(QSize(70, 20));
        lineEditPnaIFBW->setFont(font2);
        lineEditPnaIFBW->setToolTipDuration(1000);
#ifndef QT_NO_STATUSTIP
        lineEditPnaIFBW->setStatusTip(QStringLiteral(""));
#endif // QT_NO_STATUSTIP
        lineEditPnaIFBW->setMaxLength(5);
        lineEditPnaIFBW->setFrame(true);
        lineEditPnaIFBW->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPnaIFBW->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEditPnaIFBW->setClearButtonEnabled(false);

        horizontalLayout->addWidget(lineEditPnaIFBW);


        verticalLayout_17->addLayout(horizontalLayout);

        pushButtonPnaConfig = new QPushButton(layoutWidget1);
        pushButtonPnaConfig->setObjectName(QStringLiteral("pushButtonPnaConfig"));
        sizePolicy.setHeightForWidth(pushButtonPnaConfig->sizePolicy().hasHeightForWidth());
        pushButtonPnaConfig->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(false);
        font3.setWeight(50);
        pushButtonPnaConfig->setFont(font3);

        verticalLayout_17->addWidget(pushButtonPnaConfig);

        layoutWidget2 = new QWidget(groupBox_5);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(13, 29, 180, 86));
        verticalLayout_6 = new QVBoxLayout(layoutWidget2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        labelScanHeight_3 = new QLabel(layoutWidget2);
        labelScanHeight_3->setObjectName(QStringLiteral("labelScanHeight_3"));
        labelScanHeight_3->setFont(font2);

        horizontalLayout_9->addWidget(labelScanHeight_3);

        lineEditPnaStartFreq = new QLineEdit(layoutWidget2);
        lineEditPnaStartFreq->setObjectName(QStringLiteral("lineEditPnaStartFreq"));
        sizePolicy1.setHeightForWidth(lineEditPnaStartFreq->sizePolicy().hasHeightForWidth());
        lineEditPnaStartFreq->setSizePolicy(sizePolicy1);
        lineEditPnaStartFreq->setMaximumSize(QSize(70, 20));
        lineEditPnaStartFreq->setFont(font2);
        lineEditPnaStartFreq->setToolTipDuration(1000);
#ifndef QT_NO_STATUSTIP
        lineEditPnaStartFreq->setStatusTip(QStringLiteral(""));
#endif // QT_NO_STATUSTIP
        lineEditPnaStartFreq->setMaxLength(5);
        lineEditPnaStartFreq->setFrame(true);
        lineEditPnaStartFreq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPnaStartFreq->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEditPnaStartFreq->setClearButtonEnabled(false);

        horizontalLayout_9->addWidget(lineEditPnaStartFreq);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelScanInterval_4 = new QLabel(layoutWidget2);
        labelScanInterval_4->setObjectName(QStringLiteral("labelScanInterval_4"));
        labelScanInterval_4->setFont(font2);

        horizontalLayout_3->addWidget(labelScanInterval_4);

        lineEditPnaStopFreq = new QLineEdit(layoutWidget2);
        lineEditPnaStopFreq->setObjectName(QStringLiteral("lineEditPnaStopFreq"));
        sizePolicy1.setHeightForWidth(lineEditPnaStopFreq->sizePolicy().hasHeightForWidth());
        lineEditPnaStopFreq->setSizePolicy(sizePolicy1);
        lineEditPnaStopFreq->setMaximumSize(QSize(70, 22));
        lineEditPnaStopFreq->setFont(font2);
        lineEditPnaStopFreq->setMaxLength(5);
        lineEditPnaStopFreq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lineEditPnaStopFreq);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        labelScanWidth_4 = new QLabel(layoutWidget2);
        labelScanWidth_4->setObjectName(QStringLiteral("labelScanWidth_4"));
        labelScanWidth_4->setFont(font2);

        horizontalLayout_13->addWidget(labelScanWidth_4);

        enumPnaSweepPoints = new QComboBox(layoutWidget2);
        enumPnaSweepPoints->setObjectName(QStringLiteral("enumPnaSweepPoints"));
        enumPnaSweepPoints->setFont(font2);

        horizontalLayout_13->addWidget(enumPnaSweepPoints);


        verticalLayout_6->addLayout(horizontalLayout_13);

        groupBoxScan = new QGroupBox(Setting);
        groupBoxScan->setObjectName(QStringLiteral("groupBoxScan"));
        groupBoxScan->setGeometry(QRect(10, 0, 621, 111));
        groupBoxScan->setFont(font1);
        widget = new QWidget(groupBoxScan);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 166, 80));
        formLayout = new QFormLayout(widget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelScanHeight_2 = new QLabel(widget);
        labelScanHeight_2->setObjectName(QStringLiteral("labelScanHeight_2"));
        labelScanHeight_2->setFont(font2);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelScanHeight_2);

        lineEditScanHeight = new QLineEdit(widget);
        lineEditScanHeight->setObjectName(QStringLiteral("lineEditScanHeight"));
        sizePolicy1.setHeightForWidth(lineEditScanHeight->sizePolicy().hasHeightForWidth());
        lineEditScanHeight->setSizePolicy(sizePolicy1);
        lineEditScanHeight->setMaximumSize(QSize(70, 20));
        lineEditScanHeight->setFont(font2);
        lineEditScanHeight->setToolTipDuration(1000);
#ifndef QT_NO_STATUSTIP
        lineEditScanHeight->setStatusTip(QStringLiteral("Height of scan area. Valid range: 50mm~500mm - Increment: 10mm"));
#endif // QT_NO_STATUSTIP
        lineEditScanHeight->setMaxLength(3);
        lineEditScanHeight->setFrame(true);
        lineEditScanHeight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditScanHeight->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEditScanHeight->setClearButtonEnabled(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditScanHeight);

        labelScanWidth_2 = new QLabel(widget);
        labelScanWidth_2->setObjectName(QStringLiteral("labelScanWidth_2"));
        labelScanWidth_2->setFont(font2);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelScanWidth_2);

        lineEditScanWidth = new QLineEdit(widget);
        lineEditScanWidth->setObjectName(QStringLiteral("lineEditScanWidth"));
        sizePolicy1.setHeightForWidth(lineEditScanWidth->sizePolicy().hasHeightForWidth());
        lineEditScanWidth->setSizePolicy(sizePolicy1);
        lineEditScanWidth->setMaximumSize(QSize(70, 22));
        lineEditScanWidth->setFont(font2);
        lineEditScanWidth->setMaxLength(3);
        lineEditScanWidth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditScanWidth);

        labelScanInterval_3 = new QLabel(widget);
        labelScanInterval_3->setObjectName(QStringLiteral("labelScanInterval_3"));
        labelScanInterval_3->setFont(font2);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelScanInterval_3);

        enumScanInterval = new QComboBox(widget);
        enumScanInterval->setObjectName(QStringLiteral("enumScanInterval"));
        enumScanInterval->setFont(font2);

        formLayout->setWidget(2, QFormLayout::FieldRole, enumScanInterval);

        splitter_3 = new QSplitter(groupBoxScan);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(230, 20, 341, 80));
        splitter_3->setOrientation(Qt::Vertical);
        widget1 = new QWidget(splitter_3);
        widget1->setObjectName(QStringLiteral("widget1"));
        horizontalLayout_8 = new QHBoxLayout(widget1);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        labelMaterialShape = new QLabel(widget1);
        labelMaterialShape->setObjectName(QStringLiteral("labelMaterialShape"));
        labelMaterialShape->setFont(font2);

        horizontalLayout_8->addWidget(labelMaterialShape);

        enumMaterialShape = new QComboBox(widget1);
        enumMaterialShape->setObjectName(QStringLiteral("enumMaterialShape"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(enumMaterialShape->sizePolicy().hasHeightForWidth());
        enumMaterialShape->setSizePolicy(sizePolicy2);
        enumMaterialShape->setFont(font2);

        horizontalLayout_8->addWidget(enumMaterialShape);

        splitter_3->addWidget(widget1);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget2 = new QWidget(splitter);
        widget2->setObjectName(QStringLiteral("widget2"));
        formLayout_2 = new QFormLayout(widget2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        labelRadius = new QLabel(widget2);
        labelRadius->setObjectName(QStringLiteral("labelRadius"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelRadius->sizePolicy().hasHeightForWidth());
        labelRadius->setSizePolicy(sizePolicy3);
        labelRadius->setFont(font2);
        labelRadius->setLayoutDirection(Qt::RightToLeft);
        labelRadius->setTextFormat(Qt::PlainText);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelRadius);

        lineEditRadius = new QLineEdit(widget2);
        lineEditRadius->setObjectName(QStringLiteral("lineEditRadius"));
        lineEditRadius->setFont(font2);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditRadius);

        labelArcLength = new QLabel(widget2);
        labelArcLength->setObjectName(QStringLiteral("labelArcLength"));
        labelArcLength->setFont(font2);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelArcLength);

        lineEditArclength = new QLineEdit(widget2);
        lineEditArclength->setObjectName(QStringLiteral("lineEditArclength"));
        lineEditArclength->setFont(font2);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEditArclength);

        splitter->addWidget(widget2);
        layoutWidget_6 = new QWidget(splitter);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        verticalLayout_24 = new QVBoxLayout(layoutWidget_6);
        verticalLayout_24->setSpacing(6);
        verticalLayout_24->setContentsMargins(11, 11, 11, 11);
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        verticalLayout_24->setContentsMargins(0, 0, 0, 0);
        labelHeightCoordinates = new QLabel(layoutWidget_6);
        labelHeightCoordinates->setObjectName(QStringLiteral("labelHeightCoordinates"));
        labelHeightCoordinates->setFont(font2);

        verticalLayout_24->addWidget(labelHeightCoordinates, 0, Qt::AlignHCenter);

        lineEditHeightCoordinates = new QLineEdit(layoutWidget_6);
        lineEditHeightCoordinates->setObjectName(QStringLiteral("lineEditHeightCoordinates"));
        lineEditHeightCoordinates->setFont(font2);

        verticalLayout_24->addWidget(lineEditHeightCoordinates, 0, Qt::AlignRight|Qt::AlignVCenter);

        splitter->addWidget(layoutWidget_6);
        splitter_3->addWidget(splitter);
        layoutWidget_6->raise();
        splitter->raise();
        widgetOscilloscope = new QWidget(Setting);
        widgetOscilloscope->setObjectName(QStringLiteral("widgetOscilloscope"));
        widgetOscilloscope->setGeometry(QRect(20, 500, 791, 371));
        groupBox_1 = new QGroupBox(Setting);
        groupBox_1->setObjectName(QStringLiteral("groupBox_1"));
        groupBox_1->setGeometry(QRect(970, 10, 771, 71));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(true);
        font4.setWeight(75);
        groupBox_1->setFont(font4);
        horizontalLayout_25 = new QHBoxLayout(groupBox_1);
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        splitter_2 = new QSplitter(groupBox_1);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setEnabled(true);
        splitter_2->setOrientation(Qt::Horizontal);
        layoutWidget_3 = new QWidget(splitter_2);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font2);
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(label_7);

        enumMaterials = new QComboBox(layoutWidget_3);
        enumMaterials->setObjectName(QStringLiteral("enumMaterials"));
        sizePolicy2.setHeightForWidth(enumMaterials->sizePolicy().hasHeightForWidth());
        enumMaterials->setSizePolicy(sizePolicy2);
        enumMaterials->setFont(font2);

        horizontalLayout_10->addWidget(enumMaterials);

        splitter_2->addWidget(layoutWidget_3);
        layoutWidget_4 = new QWidget(splitter_2);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font2);
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(label_8);

        enumThickness = new QComboBox(layoutWidget_4);
        enumThickness->setObjectName(QStringLiteral("enumThickness"));
        sizePolicy2.setHeightForWidth(enumThickness->sizePolicy().hasHeightForWidth());
        enumThickness->setSizePolicy(sizePolicy2);
        enumThickness->setFont(font2);

        horizontalLayout_11->addWidget(enumThickness);

        splitter_2->addWidget(layoutWidget_4);
        layoutWidget_5 = new QWidget(splitter_2);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font2);
        label_9->setLayoutDirection(Qt::LeftToRight);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_14->addWidget(label_9);

        enumRef = new QComboBox(layoutWidget_5);
        enumRef->setObjectName(QStringLiteral("enumRef"));
        sizePolicy2.setHeightForWidth(enumRef->sizePolicy().hasHeightForWidth());
        enumRef->setSizePolicy(sizePolicy2);
        enumRef->setFont(font2);

        horizontalLayout_14->addWidget(enumRef);

        splitter_2->addWidget(layoutWidget_5);

        horizontalLayout_25->addWidget(splitter_2);

        pushButtonPnaMeasure = new QPushButton(Setting);
        pushButtonPnaMeasure->setObjectName(QStringLiteral("pushButtonPnaMeasure"));
        pushButtonPnaMeasure->setGeometry(QRect(10, 420, 215, 49));
        sizePolicy.setHeightForWidth(pushButtonPnaMeasure->sizePolicy().hasHeightForWidth());
        pushButtonPnaMeasure->setSizePolicy(sizePolicy);
        pushButtonPnaMeasure->setFont(font);
        layoutWidget3 = new QWidget(Setting);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(50, 500, 117, 24));
        horizontalLayout_22 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        labelScanWidth_5 = new QLabel(layoutWidget3);
        labelScanWidth_5->setObjectName(QStringLiteral("labelScanWidth_5"));
        labelScanWidth_5->setFont(font2);

        horizontalLayout_22->addWidget(labelScanWidth_5);

        enumMeasType = new QComboBox(layoutWidget3);
        enumMeasType->setObjectName(QStringLiteral("enumMeasType"));
        enumMeasType->setFont(font2);

        horizontalLayout_22->addWidget(enumMeasType);

        pushButtonQuit = new QPushButton(Setting);
        pushButtonQuit->setObjectName(QStringLiteral("pushButtonQuit"));
        pushButtonQuit->setGeometry(QRect(580, 420, 221, 51));
        pushButtonQuit->setFont(font1);
        groupBox_Coordinates = new QGroupBox(Setting);
        groupBox_Coordinates->setObjectName(QStringLiteral("groupBox_Coordinates"));
        groupBox_Coordinates->setGeometry(QRect(640, 0, 321, 111));
        splitter_4 = new QSplitter(groupBox_Coordinates);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setGeometry(QRect(20, 20, 290, 71));
        splitter_4->setOrientation(Qt::Vertical);
        widget3 = new QWidget(splitter_4);
        widget3->setObjectName(QStringLiteral("widget3"));
        horizontalLayout_24 = new QHBoxLayout(widget3);
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        horizontalLayout_24->setContentsMargins(0, 0, 0, 0);
        pushButton_LoadCoordinates = new QPushButton(widget3);
        pushButton_LoadCoordinates->setObjectName(QStringLiteral("pushButton_LoadCoordinates"));
        pushButton_LoadCoordinates->setMinimumSize(QSize(108, 0));

        horizontalLayout_24->addWidget(pushButton_LoadCoordinates);

        pushButton_CalaculateParameters = new QPushButton(widget3);
        pushButton_CalaculateParameters->setObjectName(QStringLiteral("pushButton_CalaculateParameters"));

        horizontalLayout_24->addWidget(pushButton_CalaculateParameters);

        splitter_4->addWidget(widget3);
        widget4 = new QWidget(splitter_4);
        widget4->setObjectName(QStringLiteral("widget4"));
        horizontalLayout_27 = new QHBoxLayout(widget4);
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        horizontalLayout_27->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(widget4);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_27->addWidget(label_10);

        label_XValue = new QLabel(widget4);
        label_XValue->setObjectName(QStringLiteral("label_XValue"));

        horizontalLayout_27->addWidget(label_XValue);

        splitter_4->addWidget(widget4);
        enumGraphType = new QComboBox(Setting);
        enumGraphType->setObjectName(QStringLiteral("enumGraphType"));
        enumGraphType->setGeometry(QRect(1040, 270, 191, 22));
        enumGraphType->setFont(font2);
        customPlot = new QCustomPlot(Setting);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(830, 300, 531, 491));
        checkBoxIA = new QCheckBox(Setting);
        checkBoxIA->setObjectName(QStringLiteral("checkBoxIA"));
        checkBoxIA->setGeometry(QRect(830, 270, 181, 20));
        groupBox_6 = new QGroupBox(Setting);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 110, 1131, 151));
        groupBox_6->setFont(font1);
        layoutWidget_12 = new QWidget(groupBox_6);
        layoutWidget_12->setObjectName(QStringLiteral("layoutWidget_12"));
        layoutWidget_12->setGeometry(QRect(350, 20, 765, 101));
        gridLayout_2 = new QGridLayout(layoutWidget_12);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonSetpos = new QPushButton(layoutWidget_12);
        pushButtonSetpos->setObjectName(QStringLiteral("pushButtonSetpos"));
        pushButtonSetpos->setFont(font2);

        gridLayout_2->addWidget(pushButtonSetpos, 1, 10, 1, 1);

        lineEditZPos = new QLineEdit(layoutWidget_12);
        lineEditZPos->setObjectName(QStringLiteral("lineEditZPos"));
        lineEditZPos->setFont(font);
        lineEditZPos->setCursorPosition(4);
        lineEditZPos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lineEditZPos, 1, 2, 1, 1);

        pushButtonGetpos = new QPushButton(layoutWidget_12);
        pushButtonGetpos->setObjectName(QStringLiteral("pushButtonGetpos"));
        pushButtonGetpos->setFont(font2);

        gridLayout_2->addWidget(pushButtonGetpos, 3, 10, 1, 1);

        lcdNumberZpos = new QLCDNumber(layoutWidget_12);
        lcdNumberZpos->setObjectName(QStringLiteral("lcdNumberZpos"));
        QFont font5;
        font5.setBold(true);
        font5.setWeight(75);
        font5.setStyleStrategy(QFont::PreferDefault);
        lcdNumberZpos->setFont(font5);
        lcdNumberZpos->setLayoutDirection(Qt::LeftToRight);
        lcdNumberZpos->setFrameShape(QFrame::Box);
        lcdNumberZpos->setFrameShadow(QFrame::Plain);
        lcdNumberZpos->setLineWidth(1);
        lcdNumberZpos->setMidLineWidth(0);
        lcdNumberZpos->setSmallDecimalPoint(false);
        lcdNumberZpos->setDigitCount(12);
        lcdNumberZpos->setSegmentStyle(QLCDNumber::Flat);
        lcdNumberZpos->setProperty("value", QVariant(0.05));

        gridLayout_2->addWidget(lcdNumberZpos, 3, 2, 1, 1);

        label_11 = new QLabel(layoutWidget_12);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font2);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_11, 0, 2, 1, 1);

        label_12 = new QLabel(layoutWidget_12);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font2);
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_12, 0, 1, 1, 1);

        lineEditRobAngleTheta = new QLineEdit(layoutWidget_12);
        lineEditRobAngleTheta->setObjectName(QStringLiteral("lineEditRobAngleTheta"));
        lineEditRobAngleTheta->setFont(font);
        lineEditRobAngleTheta->setCursorPosition(1);
        lineEditRobAngleTheta->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lineEditRobAngleTheta, 1, 6, 1, 1);

        lcdNumberRobAngleTheta = new QLCDNumber(layoutWidget_12);
        lcdNumberRobAngleTheta->setObjectName(QStringLiteral("lcdNumberRobAngleTheta"));
        lcdNumberRobAngleTheta->setFont(font5);
        lcdNumberRobAngleTheta->setLayoutDirection(Qt::LeftToRight);
        lcdNumberRobAngleTheta->setFrameShape(QFrame::Box);
        lcdNumberRobAngleTheta->setFrameShadow(QFrame::Plain);
        lcdNumberRobAngleTheta->setLineWidth(1);
        lcdNumberRobAngleTheta->setMidLineWidth(0);
        lcdNumberRobAngleTheta->setSmallDecimalPoint(false);
        lcdNumberRobAngleTheta->setDigitCount(12);
        lcdNumberRobAngleTheta->setSegmentStyle(QLCDNumber::Flat);
        lcdNumberRobAngleTheta->setProperty("value", QVariant(0.05));

        gridLayout_2->addWidget(lcdNumberRobAngleTheta, 3, 6, 1, 1);

        label_15 = new QLabel(layoutWidget_12);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font2);
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_15, 0, 6, 1, 1);

        lcdNumberYpos = new QLCDNumber(layoutWidget_12);
        lcdNumberYpos->setObjectName(QStringLiteral("lcdNumberYpos"));
        lcdNumberYpos->setFont(font5);
        lcdNumberYpos->setLayoutDirection(Qt::LeftToRight);
        lcdNumberYpos->setFrameShape(QFrame::Box);
        lcdNumberYpos->setFrameShadow(QFrame::Plain);
        lcdNumberYpos->setLineWidth(1);
        lcdNumberYpos->setMidLineWidth(0);
        lcdNumberYpos->setSmallDecimalPoint(false);
        lcdNumberYpos->setDigitCount(12);
        lcdNumberYpos->setSegmentStyle(QLCDNumber::Flat);
        lcdNumberYpos->setProperty("value", QVariant(0.05));

        gridLayout_2->addWidget(lcdNumberYpos, 3, 1, 1, 1);

        lineEditYPos = new QLineEdit(layoutWidget_12);
        lineEditYPos->setObjectName(QStringLiteral("lineEditYPos"));
        lineEditYPos->setFont(font);
        lineEditYPos->setCursorPosition(4);
        lineEditYPos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lineEditYPos, 1, 1, 1, 1);

        lineEditRobAnglePhi = new QLineEdit(layoutWidget_12);
        lineEditRobAnglePhi->setObjectName(QStringLiteral("lineEditRobAnglePhi"));
        lineEditRobAnglePhi->setFont(font);
        lineEditRobAnglePhi->setCursorPosition(1);
        lineEditRobAnglePhi->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lineEditRobAnglePhi, 1, 7, 1, 1);

        label_19 = new QLabel(layoutWidget_12);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font2);
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_19, 0, 7, 1, 1);

        label_13 = new QLabel(layoutWidget_12);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font2);
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_13, 0, 4, 1, 1);

        lcdNumberXpos = new QLCDNumber(layoutWidget_12);
        lcdNumberXpos->setObjectName(QStringLiteral("lcdNumberXpos"));
        lcdNumberXpos->setFont(font5);
        lcdNumberXpos->setLayoutDirection(Qt::LeftToRight);
        lcdNumberXpos->setFrameShape(QFrame::Box);
        lcdNumberXpos->setFrameShadow(QFrame::Plain);
        lcdNumberXpos->setLineWidth(1);
        lcdNumberXpos->setMidLineWidth(0);
        lcdNumberXpos->setSmallDecimalPoint(false);
        lcdNumberXpos->setDigitCount(12);
        lcdNumberXpos->setSegmentStyle(QLCDNumber::Flat);
        lcdNumberXpos->setProperty("value", QVariant(0.05));

        gridLayout_2->addWidget(lcdNumberXpos, 3, 4, 1, 1);

        lineEditXpos = new QLineEdit(layoutWidget_12);
        lineEditXpos->setObjectName(QStringLiteral("lineEditXpos"));
        lineEditXpos->setFont(font);
        lineEditXpos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lineEditXpos, 1, 4, 1, 1);

        lcdNumberRobAnglePhi = new QLCDNumber(layoutWidget_12);
        lcdNumberRobAnglePhi->setObjectName(QStringLiteral("lcdNumberRobAnglePhi"));
        lcdNumberRobAnglePhi->setFont(font5);
        lcdNumberRobAnglePhi->setLayoutDirection(Qt::LeftToRight);
        lcdNumberRobAnglePhi->setFrameShape(QFrame::Box);
        lcdNumberRobAnglePhi->setFrameShadow(QFrame::Plain);
        lcdNumberRobAnglePhi->setLineWidth(1);
        lcdNumberRobAnglePhi->setMidLineWidth(0);
        lcdNumberRobAnglePhi->setSmallDecimalPoint(false);
        lcdNumberRobAnglePhi->setDigitCount(12);
        lcdNumberRobAnglePhi->setSegmentStyle(QLCDNumber::Flat);
        lcdNumberRobAnglePhi->setProperty("value", QVariant(0.05));

        gridLayout_2->addWidget(lcdNumberRobAnglePhi, 3, 7, 1, 1);

        checkBoxRobotControllerSelect = new QCheckBox(groupBox_6);
        checkBoxRobotControllerSelect->setObjectName(QStringLiteral("checkBoxRobotControllerSelect"));
        checkBoxRobotControllerSelect->setGeometry(QRect(20, 120, 537, 19));
        splitter_5 = new QSplitter(groupBox_6);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setGeometry(QRect(10, 19, 331, 96));
        splitter_5->setOrientation(Qt::Horizontal);
        splitter_8 = new QSplitter(splitter_5);
        splitter_8->setObjectName(QStringLiteral("splitter_8"));
        splitter_8->setLineWidth(0);
        splitter_8->setOrientation(Qt::Vertical);
        splitter_8->setHandleWidth(0);
        layoutWidget_2 = new QWidget(splitter_8);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        horizontalLayout_28 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        horizontalLayout_28->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_10 = new QSpacerItem(50, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_10);

        pushButtonJogzp = new QPushButton(layoutWidget_2);
        pushButtonJogzp->setObjectName(QStringLiteral("pushButtonJogzp"));
        pushButtonJogzp->setFont(font);
        pushButtonJogzp->setCheckable(false);

        horizontalLayout_28->addWidget(pushButtonJogzp);

        horizontalSpacer_11 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_11);

        splitter_8->addWidget(layoutWidget_2);
        layoutWidget_10 = new QWidget(splitter_8);
        layoutWidget_10->setObjectName(QStringLiteral("layoutWidget_10"));
        horizontalLayout_35 = new QHBoxLayout(layoutWidget_10);
        horizontalLayout_35->setSpacing(6);
        horizontalLayout_35->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_35->setObjectName(QStringLiteral("horizontalLayout_35"));
        horizontalLayout_35->setContentsMargins(0, 0, 0, 0);
        pushButtonJogyp = new QPushButton(layoutWidget_10);
        pushButtonJogyp->setObjectName(QStringLiteral("pushButtonJogyp"));
        pushButtonJogyp->setFont(font);
        pushButtonJogyp->setCheckable(false);

        horizontalLayout_35->addWidget(pushButtonJogyp);

        pushButtonOrigin = new QPushButton(layoutWidget_10);
        pushButtonOrigin->setObjectName(QStringLiteral("pushButtonOrigin"));
        pushButtonOrigin->setFont(font2);

        horizontalLayout_35->addWidget(pushButtonOrigin);

        pushButtonJogyn = new QPushButton(layoutWidget_10);
        pushButtonJogyn->setObjectName(QStringLiteral("pushButtonJogyn"));
        pushButtonJogyn->setFont(font);
        pushButtonJogyn->setCheckable(false);

        horizontalLayout_35->addWidget(pushButtonJogyn);

        splitter_8->addWidget(layoutWidget_10);
        layoutWidget_11 = new QWidget(splitter_8);
        layoutWidget_11->setObjectName(QStringLiteral("layoutWidget_11"));
        horizontalLayout_36 = new QHBoxLayout(layoutWidget_11);
        horizontalLayout_36->setSpacing(6);
        horizontalLayout_36->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_36->setObjectName(QStringLiteral("horizontalLayout_36"));
        horizontalLayout_36->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_12 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_36->addItem(horizontalSpacer_12);

        pushButtonJogzn = new QPushButton(layoutWidget_11);
        pushButtonJogzn->setObjectName(QStringLiteral("pushButtonJogzn"));
        pushButtonJogzn->setFont(font);
        pushButtonJogzn->setCheckable(false);

        horizontalLayout_36->addWidget(pushButtonJogzn);

        horizontalSpacer_13 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_36->addItem(horizontalSpacer_13);

        splitter_8->addWidget(layoutWidget_11);
        splitter_5->addWidget(splitter_8);
        layoutWidget_13 = new QWidget(splitter_5);
        layoutWidget_13->setObjectName(QStringLiteral("layoutWidget_13"));
        verticalLayout_32 = new QVBoxLayout(layoutWidget_13);
        verticalLayout_32->setSpacing(6);
        verticalLayout_32->setContentsMargins(11, 11, 11, 11);
        verticalLayout_32->setObjectName(QStringLiteral("verticalLayout_32"));
        verticalLayout_32->setContentsMargins(0, 0, 0, 0);
        pushButtonJogxp = new QPushButton(layoutWidget_13);
        pushButtonJogxp->setObjectName(QStringLiteral("pushButtonJogxp"));
        pushButtonJogxp->setFont(font);
        pushButtonJogxp->setCheckable(false);

        verticalLayout_32->addWidget(pushButtonJogxp);

        pushButtonJogxn = new QPushButton(layoutWidget_13);
        pushButtonJogxn->setObjectName(QStringLiteral("pushButtonJogxn"));
        pushButtonJogxn->setFont(font);
        pushButtonJogxn->setCheckable(false);

        verticalLayout_32->addWidget(pushButtonJogxn);

        splitter_5->addWidget(layoutWidget_13);
        pushButtonServoStop = new QPushButton(splitter_5);
        pushButtonServoStop->setObjectName(QStringLiteral("pushButtonServoStop"));
        pushButtonServoStop->setFont(font1);
        splitter_5->addWidget(pushButtonServoStop);
        tabWidget->addTab(Setting, QString());
        Result = new QWidget();
        Result->setObjectName(QStringLiteral("Result"));
        scrollArea = new QScrollArea(Result);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(150, 110, 1771, 661));
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setLineWidth(1);
        scrollArea->setMidLineWidth(1);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(false);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        widgettResultSpect = new QWidget();
        widgettResultSpect->setObjectName(QStringLiteral("widgettResultSpect"));
        widgettResultSpect->setGeometry(QRect(0, 0, 1750, 671));
        scrollArea->setWidget(widgettResultSpect);
        widgetResultTime = new QWidget(Result);
        widgetResultTime->setObjectName(QStringLiteral("widgetResultTime"));
        widgetResultTime->setGeometry(QRect(250, 780, 1721, 251));
        labelCurrentDataSpec = new QLabel(Result);
        labelCurrentDataSpec->setObjectName(QStringLiteral("labelCurrentDataSpec"));
        labelCurrentDataSpec->setGeometry(QRect(990, 70, 1021, 31));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setWeight(75);
        labelCurrentDataSpec->setFont(font6);
        widgetVtwam = new QWidget(Result);
        widgetVtwam->setObjectName(QStringLiteral("widgetVtwam"));
        widgetVtwam->setGeometry(QRect(1740, 1020, 621, 491));
        widgetResultControl = new QWidget(Result);
        widgetResultControl->setObjectName(QStringLiteral("widgetResultControl"));
        widgetResultControl->setGeometry(QRect(150, -10, 751, 121));
        groupBoxResultControl = new QGroupBox(widgetResultControl);
        groupBoxResultControl->setObjectName(QStringLiteral("groupBoxResultControl"));
        groupBoxResultControl->setGeometry(QRect(-10, 10, 771, 111));
        groupBoxResultControl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        groupBoxResultControl->setFlat(false);
        horizontalLayout_21 = new QHBoxLayout(groupBoxResultControl);
        horizontalLayout_21->setSpacing(0);
        horizontalLayout_21->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        horizontalLayout_21->setContentsMargins(15, 8, 15, 0);
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(5);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_17->setSizeConstraint(QLayout::SetDefaultConstraint);
        enumMeasType_2 = new QComboBox(groupBoxResultControl);
        enumMeasType_2->setObjectName(QStringLiteral("enumMeasType_2"));
        enumMeasType_2->setFont(font2);

        horizontalLayout_17->addWidget(enumMeasType_2);

        enumPlaySpeed = new QComboBox(groupBoxResultControl);
        enumPlaySpeed->setObjectName(QStringLiteral("enumPlaySpeed"));

        horizontalLayout_17->addWidget(enumPlaySpeed);

        pushButtonPlayPause = new QPushButton(groupBoxResultControl);
        pushButtonPlayPause->setObjectName(QStringLiteral("pushButtonPlayPause"));
        pushButtonPlayPause->setCheckable(true);
        pushButtonPlayPause->setAutoDefault(false);

        horizontalLayout_17->addWidget(pushButtonPlayPause);

        pushButtonCapture = new QPushButton(groupBoxResultControl);
        pushButtonCapture->setObjectName(QStringLiteral("pushButtonCapture"));

        horizontalLayout_17->addWidget(pushButtonCapture);

        pushButtonSaveMovie = new QPushButton(groupBoxResultControl);
        pushButtonSaveMovie->setObjectName(QStringLiteral("pushButtonSaveMovie"));

        horizontalLayout_17->addWidget(pushButtonSaveMovie);

        pushButtonEnlarge = new QPushButton(groupBoxResultControl);
        pushButtonEnlarge->setObjectName(QStringLiteral("pushButtonEnlarge"));
        pushButtonEnlarge->setCheckable(false);
        pushButtonEnlarge->setAutoDefault(false);

        horizontalLayout_17->addWidget(pushButtonEnlarge);


        verticalLayout->addLayout(horizontalLayout_17);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(0);
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        horizontalSliderFrame = new MySlider(groupBoxResultControl);
        horizontalSliderFrame->setObjectName(QStringLiteral("horizontalSliderFrame"));
        horizontalSliderFrame->setEnabled(true);
        sizePolicy2.setHeightForWidth(horizontalSliderFrame->sizePolicy().hasHeightForWidth());
        horizontalSliderFrame->setSizePolicy(sizePolicy2);
        horizontalSliderFrame->setValue(50);
        horizontalSliderFrame->setOrientation(Qt::Horizontal);

        horizontalLayout_26->addWidget(horizontalSliderFrame);

        labelFrame = new QLabel(groupBoxResultControl);
        labelFrame->setObjectName(QStringLiteral("labelFrame"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(labelFrame->sizePolicy().hasHeightForWidth());
        labelFrame->setSizePolicy(sizePolicy4);
        labelFrame->setFont(font);
        labelFrame->setAlignment(Qt::AlignCenter);

        horizontalLayout_26->addWidget(labelFrame);


        verticalLayout->addLayout(horizontalLayout_26);

        verticalSpacer_3 = new QSpacerItem(97, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout_20->addLayout(verticalLayout);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        dial_intensity = new QDial(groupBoxResultControl);
        dial_intensity->setObjectName(QStringLiteral("dial_intensity"));
        dial_intensity->setFocusPolicy(Qt::StrongFocus);
        dial_intensity->setToolTipDuration(5000);
        dial_intensity->setMinimum(50);
        dial_intensity->setMaximum(25000);
        dial_intensity->setSingleStep(5);
        dial_intensity->setPageStep(20);
        dial_intensity->setValue(50);
        dial_intensity->setTracking(true);
        dial_intensity->setOrientation(Qt::Horizontal);
        dial_intensity->setWrapping(false);
        dial_intensity->setNotchTarget(15);
        dial_intensity->setNotchesVisible(true);

        verticalLayout_9->addWidget(dial_intensity);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_5);

        checkBoxGreyscale = new QCheckBox(groupBoxResultControl);
        checkBoxGreyscale->setObjectName(QStringLiteral("checkBoxGreyscale"));

        horizontalLayout_12->addWidget(checkBoxGreyscale);


        verticalLayout_9->addLayout(horizontalLayout_12);


        horizontalLayout_20->addLayout(verticalLayout_9);


        horizontalLayout_21->addLayout(horizontalLayout_20);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setSpacing(6);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        dial_intensity_2 = new QDial(groupBoxResultControl);
        dial_intensity_2->setObjectName(QStringLiteral("dial_intensity_2"));
        dial_intensity_2->setMinimumSize(QSize(50, 65));
        dial_intensity_2->setFocusPolicy(Qt::StrongFocus);
        dial_intensity_2->setToolTipDuration(5000);
        dial_intensity_2->setMinimum(50);
        dial_intensity_2->setMaximum(25000);
        dial_intensity_2->setSingleStep(5);
        dial_intensity_2->setPageStep(20);
        dial_intensity_2->setValue(50);
        dial_intensity_2->setWrapping(false);
        dial_intensity_2->setNotchTarget(15);
        dial_intensity_2->setNotchesVisible(true);

        verticalLayout_21->addWidget(dial_intensity_2);

        verticalSpacer_2 = new QSpacerItem(97, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_21->addItem(verticalSpacer_2);


        horizontalLayout_21->addLayout(verticalLayout_21);

        progressBar = new QProgressBar(Result);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(1190, 1170, 118, 23));
        progressBar->setValue(24);
        groupBox = new QGroupBox(Result);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 117, 103));
        verticalLayout_33 = new QVBoxLayout(groupBox);
        verticalLayout_33->setSpacing(6);
        verticalLayout_33->setContentsMargins(11, 11, 11, 11);
        verticalLayout_33->setObjectName(QStringLiteral("verticalLayout_33"));
        pushButtonLoadData = new QPushButton(groupBox);
        pushButtonLoadData->setObjectName(QStringLiteral("pushButtonLoadData"));

        verticalLayout_33->addWidget(pushButtonLoadData);

        pushButtonSaveData = new QPushButton(groupBox);
        pushButtonSaveData->setObjectName(QStringLiteral("pushButtonSaveData"));

        verticalLayout_33->addWidget(pushButtonSaveData);

        groupBoxFilter = new QGroupBox(Result);
        groupBoxFilter->setObjectName(QStringLiteral("groupBoxFilter"));
        groupBoxFilter->setEnabled(true);
        groupBoxFilter->setGeometry(QRect(12, 260, 133, 507));
        groupBoxFilter->setToolTipDuration(5000);
        groupBoxFilter->setCheckable(true);
        layoutWidget4 = new QWidget(groupBoxFilter);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(12, 28, 109, 577));
        verticalLayout_25 = new QVBoxLayout(layoutWidget4);
        verticalLayout_25->setSpacing(6);
        verticalLayout_25->setContentsMargins(11, 11, 11, 11);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        verticalLayout_25->setContentsMargins(0, 0, 0, 0);
        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        groupBoxFilterStep1 = new QGroupBox(layoutWidget4);
        groupBoxFilterStep1->setObjectName(QStringLiteral("groupBoxFilterStep1"));
        groupBoxFilterStep1->setToolTipDuration(5000);
        groupBoxFilterStep1->setFlat(false);
        groupBoxFilterStep1->setCheckable(true);
        verticalLayout_11 = new QVBoxLayout(groupBoxFilterStep1);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        labelImageFilterIterations = new QLabel(groupBoxFilterStep1);
        labelImageFilterIterations->setObjectName(QStringLiteral("labelImageFilterIterations"));

        verticalLayout_3->addWidget(labelImageFilterIterations);

        enumImageFilterIterations = new QComboBox(groupBoxFilterStep1);
        enumImageFilterIterations->setObjectName(QStringLiteral("enumImageFilterIterations"));

        verticalLayout_3->addWidget(enumImageFilterIterations);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        labelImageFilterType = new QLabel(groupBoxFilterStep1);
        labelImageFilterType->setObjectName(QStringLiteral("labelImageFilterType"));

        verticalLayout_5->addWidget(labelImageFilterType);

        enumImageFilterType = new QComboBox(groupBoxFilterStep1);
        enumImageFilterType->setObjectName(QStringLiteral("enumImageFilterType"));

        verticalLayout_5->addWidget(enumImageFilterType);


        verticalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelImageFilterSize = new QLabel(groupBoxFilterStep1);
        labelImageFilterSize->setObjectName(QStringLiteral("labelImageFilterSize"));

        verticalLayout_2->addWidget(labelImageFilterSize);

        enumImageFilterSize = new QComboBox(groupBoxFilterStep1);
        enumImageFilterSize->setObjectName(QStringLiteral("enumImageFilterSize"));

        verticalLayout_2->addWidget(enumImageFilterSize);


        verticalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_11->addLayout(verticalLayout_4);


        verticalLayout_23->addWidget(groupBoxFilterStep1);

        groupBoxFilterStep2 = new QGroupBox(layoutWidget4);
        groupBoxFilterStep2->setObjectName(QStringLiteral("groupBoxFilterStep2"));
        groupBoxFilterStep2->setCheckable(true);
        verticalLayout_13 = new QVBoxLayout(groupBoxFilterStep2);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        labelImageFilterIterations_2 = new QLabel(groupBoxFilterStep2);
        labelImageFilterIterations_2->setObjectName(QStringLiteral("labelImageFilterIterations_2"));

        verticalLayout_16->addWidget(labelImageFilterIterations_2);

        enumImageFilterIterations_2 = new QComboBox(groupBoxFilterStep2);
        enumImageFilterIterations_2->setObjectName(QStringLiteral("enumImageFilterIterations_2"));

        verticalLayout_16->addWidget(enumImageFilterIterations_2);


        verticalLayout_15->addLayout(verticalLayout_16);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        labelImageFilterType_2 = new QLabel(groupBoxFilterStep2);
        labelImageFilterType_2->setObjectName(QStringLiteral("labelImageFilterType_2"));

        verticalLayout_20->addWidget(labelImageFilterType_2);

        enumImageFilterType_2 = new QComboBox(groupBoxFilterStep2);
        enumImageFilterType_2->setObjectName(QStringLiteral("enumImageFilterType_2"));

        verticalLayout_20->addWidget(enumImageFilterType_2);


        verticalLayout_15->addLayout(verticalLayout_20);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        labelImageFilterSize_2 = new QLabel(groupBoxFilterStep2);
        labelImageFilterSize_2->setObjectName(QStringLiteral("labelImageFilterSize_2"));

        verticalLayout_22->addWidget(labelImageFilterSize_2);

        enumImageFilterSize_2 = new QComboBox(groupBoxFilterStep2);
        enumImageFilterSize_2->setObjectName(QStringLiteral("enumImageFilterSize_2"));

        verticalLayout_22->addWidget(enumImageFilterSize_2);


        verticalLayout_15->addLayout(verticalLayout_22);


        verticalLayout_13->addLayout(verticalLayout_15);


        verticalLayout_23->addWidget(groupBoxFilterStep2);


        verticalLayout_25->addLayout(verticalLayout_23);

        checkBoxBoostSpeed = new QCheckBox(layoutWidget4);
        checkBoxBoostSpeed->setObjectName(QStringLiteral("checkBoxBoostSpeed"));
        checkBoxBoostSpeed->setFont(font1);
        checkBoxBoostSpeed->setChecked(true);

        verticalLayout_25->addWidget(checkBoxBoostSpeed);

        pushButtonProcessFilter = new QPushButton(layoutWidget4);
        pushButtonProcessFilter->setObjectName(QStringLiteral("pushButtonProcessFilter"));

        verticalLayout_25->addWidget(pushButtonProcessFilter);

        groupBoxVtwam = new QGroupBox(Result);
        groupBoxVtwam->setObjectName(QStringLiteral("groupBoxVtwam"));
        groupBoxVtwam->setGeometry(QRect(12, 774, 133, 217));
        verticalLayout_12 = new QVBoxLayout(groupBoxVtwam);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_3 = new QLabel(groupBoxVtwam);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_7->addWidget(label_3);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QStringLiteral("horizontalLayout_33"));
        lineEditVtwamStart = new QLineEdit(groupBoxVtwam);
        lineEditVtwamStart->setObjectName(QStringLiteral("lineEditVtwamStart"));
        lineEditVtwamStart->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_33->addWidget(lineEditVtwamStart);

        labelVtwamStart = new QLabel(groupBoxVtwam);
        labelVtwamStart->setObjectName(QStringLiteral("labelVtwamStart"));

        horizontalLayout_33->addWidget(labelVtwamStart);


        verticalLayout_7->addLayout(horizontalLayout_33);


        verticalLayout_10->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_4 = new QLabel(groupBoxVtwam);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_8->addWidget(label_4);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        lineEditVtwamEnd = new QLineEdit(groupBoxVtwam);
        lineEditVtwamEnd->setObjectName(QStringLiteral("lineEditVtwamEnd"));
        lineEditVtwamEnd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_34->addWidget(lineEditVtwamEnd);

        labelVtwamEnd = new QLabel(groupBoxVtwam);
        labelVtwamEnd->setObjectName(QStringLiteral("labelVtwamEnd"));

        horizontalLayout_34->addWidget(labelVtwamEnd);


        verticalLayout_8->addLayout(horizontalLayout_34);


        verticalLayout_10->addLayout(verticalLayout_8);

        pushButtonProcessVtwam = new QPushButton(groupBoxVtwam);
        pushButtonProcessVtwam->setObjectName(QStringLiteral("pushButtonProcessVtwam"));

        verticalLayout_10->addWidget(pushButtonProcessVtwam);


        verticalLayout_12->addLayout(verticalLayout_10);

        pushButtonCaptureVtwam = new QPushButton(groupBoxVtwam);
        pushButtonCaptureVtwam->setObjectName(QStringLiteral("pushButtonCaptureVtwam"));

        verticalLayout_12->addWidget(pushButtonCaptureVtwam);

        pushButtonServoStop2 = new QPushButton(Result);
        pushButtonServoStop2->setObjectName(QStringLiteral("pushButtonServoStop2"));
        pushButtonServoStop2->setGeometry(QRect(910, 0, 121, 101));
        sizePolicy.setHeightForWidth(pushButtonServoStop2->sizePolicy().hasHeightForWidth());
        pushButtonServoStop2->setSizePolicy(sizePolicy);
        pushButtonServoStop2->setFont(font6);
        pushButtonSaveDataCurrent = new QPushButton(Result);
        pushButtonSaveDataCurrent->setObjectName(QStringLiteral("pushButtonSaveDataCurrent"));
        pushButtonSaveDataCurrent->setGeometry(QRect(10, 120, 121, 31));
        tabWidget->addTab(Result, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1940, 26));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setContextMenuPolicy(Qt::DefaultContextMenu);
        statusBar->setToolTipDuration(10);
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(enumPlaySpeed, pushButtonPlayPause);
        QWidget::setTabOrder(pushButtonPlayPause, pushButtonCapture);
        QWidget::setTabOrder(pushButtonCapture, pushButtonSaveMovie);
        QWidget::setTabOrder(pushButtonSaveMovie, dial_intensity);
        QWidget::setTabOrder(dial_intensity, dial_intensity_2);
        QWidget::setTabOrder(dial_intensity_2, scrollArea);
        QWidget::setTabOrder(scrollArea, groupBoxFilter);
        QWidget::setTabOrder(groupBoxFilter, horizontalSliderFrame);
        QWidget::setTabOrder(horizontalSliderFrame, groupBoxFilterStep1);
        QWidget::setTabOrder(groupBoxFilterStep1, enumImageFilterIterations);
        QWidget::setTabOrder(enumImageFilterIterations, enumImageFilterType);
        QWidget::setTabOrder(enumImageFilterType, enumImageFilterSize);
        QWidget::setTabOrder(enumImageFilterSize, groupBoxFilterStep2);
        QWidget::setTabOrder(groupBoxFilterStep2, enumImageFilterIterations_2);
        QWidget::setTabOrder(enumImageFilterIterations_2, enumImageFilterType_2);
        QWidget::setTabOrder(enumImageFilterType_2, enumImageFilterSize_2);
        QWidget::setTabOrder(enumImageFilterSize_2, pushButtonProcessFilter);
        QWidget::setTabOrder(pushButtonProcessFilter, lineEditVtwamStart);
        QWidget::setTabOrder(lineEditVtwamStart, lineEditVtwamEnd);
        QWidget::setTabOrder(lineEditVtwamEnd, pushButtonProcessVtwam);
        QWidget::setTabOrder(pushButtonProcessVtwam, pushButtonCaptureVtwam);
        QWidget::setTabOrder(pushButtonCaptureVtwam, pushButtonLoadData);
        QWidget::setTabOrder(pushButtonLoadData, pushButtonSaveData);

        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
#ifndef QT_NO_WHATSTHIS
        MainWindow->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
#ifndef QT_NO_STATUSTIP
        actionSave->setStatusTip(QApplication::translate("MainWindow", "Save inspection settings.", 0));
#endif // QT_NO_STATUSTIP
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionAL_CFRP->setText(QApplication::translate("MainWindow", "AL/Graphite", 0));
        actionKAF_Standard->setText(QApplication::translate("MainWindow", "KAF Standard", 0));
        actionPulse_Energy_Table->setText(QApplication::translate("MainWindow", "Pulse Energy Table", 0));
        pushButtonStart->setText(QApplication::translate("MainWindow", "Scan", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "PNA", 0));
        labelScanHeight_5->setText(QApplication::translate("MainWindow", "Metal Plate Thickness (mm):", 0));
#ifndef QT_NO_TOOLTIP
        lineEditPnametalPlateThickness->setToolTip(QApplication::translate("MainWindow", "Valid range: 50mm~500mm - Increment: 10mm", 0));
#endif // QT_NO_TOOLTIP
        labelScanHeight_7->setText(QApplication::translate("MainWindow", "Sample Plate Thickness (mm):", 0));
#ifndef QT_NO_TOOLTIP
        lineEditPnasampleThickness->setToolTip(QApplication::translate("MainWindow", "Valid range: 50mm~500mm - Increment: 10mm", 0));
#endif // QT_NO_TOOLTIP
        lineEditPnasampleThickness->setText(QString());
        labelScanHeight_6->setText(QApplication::translate("MainWindow", "Distance to sample (mm):", 0));
#ifndef QT_NO_TOOLTIP
        lineEditPnadistToSample->setToolTip(QApplication::translate("MainWindow", "Valid range: 50mm~500mm - Increment: 10mm", 0));
#endif // QT_NO_TOOLTIP
        lineEditPnadistToSample->setText(QString());
        labelScanInterval_5->setText(QApplication::translate("MainWindow", "Power (dB):", 0));
#ifndef QT_NO_TOOLTIP
        lineEditPnaPower->setToolTip(QApplication::translate("MainWindow", "Valid range: 50mm~500mm - Increment: 10mm", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEditPnaPower->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        labelScanHeight_4->setText(QApplication::translate("MainWindow", "IFBW (Hz):", 0));
#ifndef QT_NO_TOOLTIP
        lineEditPnaIFBW->setToolTip(QApplication::translate("MainWindow", "Valid range: 50mm~500mm - Increment: 10mm", 0));
#endif // QT_NO_TOOLTIP
        pushButtonPnaConfig->setText(QApplication::translate("MainWindow", "Configure", 0));
        labelScanHeight_3->setText(QApplication::translate("MainWindow", "Start Freq (GHz):", 0));
#ifndef QT_NO_TOOLTIP
        lineEditPnaStartFreq->setToolTip(QApplication::translate("MainWindow", "Valid range: 50mm~500mm - Increment: 10mm", 0));
#endif // QT_NO_TOOLTIP
        labelScanInterval_4->setText(QApplication::translate("MainWindow", "Stop Freq (GHz):", 0));
#ifndef QT_NO_TOOLTIP
        lineEditPnaStopFreq->setToolTip(QApplication::translate("MainWindow", "Valid range: 50mm~500mm - Increment: 10mm", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEditPnaStopFreq->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        labelScanWidth_4->setText(QApplication::translate("MainWindow", "Sweep Points:", 0));
        groupBoxScan->setTitle(QApplication::translate("MainWindow", "Scan Parameters", 0));
        labelScanHeight_2->setText(QApplication::translate("MainWindow", "Height (mm):", 0));
#ifndef QT_NO_TOOLTIP
        lineEditScanHeight->setToolTip(QApplication::translate("MainWindow", "Valid range: 50mm~500mm - Increment: 10mm", 0));
#endif // QT_NO_TOOLTIP
        labelScanWidth_2->setText(QApplication::translate("MainWindow", "Width (mm):", 0));
#ifndef QT_NO_TOOLTIP
        lineEditScanWidth->setToolTip(QApplication::translate("MainWindow", "Valid range: 50mm~500mm - Increment: 10mm", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEditScanWidth->setStatusTip(QApplication::translate("MainWindow", "Width of scan area. Valid range: 50mm~500mm - Increment: 10mm", 0));
#endif // QT_NO_STATUSTIP
        labelScanInterval_3->setText(QApplication::translate("MainWindow", "Interval(mm): ", 0));
        labelMaterialShape->setText(QApplication::translate("MainWindow", "Material Shape:", 0));
        labelRadius->setText(QApplication::translate("MainWindow", "Radius (mm):", 0));
        labelArcLength->setText(QApplication::translate("MainWindow", "Arc-length (mm):", 0));
        labelHeightCoordinates->setText(QString());
        groupBox_1->setTitle(QApplication::translate("MainWindow", "Inspection settings", 0));
        label_7->setText(QApplication::translate("MainWindow", "Material:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Thickness (mm):", 0));
        label_9->setText(QApplication::translate("MainWindow", "KAF Standard: ", 0));
        pushButtonPnaMeasure->setText(QApplication::translate("MainWindow", "Measure", 0));
        labelScanWidth_5->setText(QApplication::translate("MainWindow", "Meas:", 0));
        pushButtonQuit->setText(QApplication::translate("MainWindow", "Exit", 0));
        groupBox_Coordinates->setTitle(QApplication::translate("MainWindow", "Coordinates", 0));
        pushButton_LoadCoordinates->setText(QApplication::translate("MainWindow", "Load Coordinates", 0));
        pushButton_CalaculateParameters->setText(QApplication::translate("MainWindow", "Calculate Parameters", 0));
        label_10->setText(QApplication::translate("MainWindow", " Specimen placement  Position:", 0));
        label_XValue->setText(QApplication::translate("MainWindow", "(X Value,Y Value)", 0));
        checkBoxIA->setText(QApplication::translate("MainWindow", "Achieve Low Incident Angle", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Robot Navigator", 0));
        pushButtonSetpos->setText(QApplication::translate("MainWindow", "Set", 0));
        lineEditZPos->setText(QApplication::translate("MainWindow", "0.00", 0));
        pushButtonGetpos->setText(QApplication::translate("MainWindow", "Get", 0));
        label_11->setText(QApplication::translate("MainWindow", "Y-axis (rob.z) ", 0));
        label_12->setText(QApplication::translate("MainWindow", "X-axis (rob.y)", 0));
        lineEditRobAngleTheta->setText(QApplication::translate("MainWindow", "0", 0));
        label_15->setText(QApplication::translate("MainWindow", "Yaw", 0));
        lineEditYPos->setText(QApplication::translate("MainWindow", "0.00", 0));
        lineEditRobAnglePhi->setText(QApplication::translate("MainWindow", "0", 0));
        label_19->setText(QApplication::translate("MainWindow", "Pitch", 0));
        label_13->setText(QApplication::translate("MainWindow", " Z-axis (rob.x)", 0));
        lineEditXpos->setText(QApplication::translate("MainWindow", "0.00", 0));
        checkBoxRobotControllerSelect->setText(QApplication::translate("MainWindow", "Select Virtual Controller", 0));
        pushButtonJogzp->setText(QApplication::translate("MainWindow", "^", 0));
        pushButtonJogyp->setText(QApplication::translate("MainWindow", "<", 0));
        pushButtonOrigin->setText(QApplication::translate("MainWindow", "Origin", 0));
        pushButtonJogyn->setText(QApplication::translate("MainWindow", ">", 0));
        pushButtonJogzn->setText(QApplication::translate("MainWindow", "v", 0));
        pushButtonJogxp->setText(QApplication::translate("MainWindow", "X+ ^", 0));
        pushButtonJogxn->setText(QApplication::translate("MainWindow", "X- v", 0));
        pushButtonServoStop->setText(QApplication::translate("MainWindow", "STOP", 0));
        tabWidget->setTabText(tabWidget->indexOf(Setting), QApplication::translate("MainWindow", "Setting", 0));
        labelCurrentDataSpec->setText(QString());
        groupBoxResultControl->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        enumPlaySpeed->setToolTip(QApplication::translate("MainWindow", "Play speed for the UWPI data visualisation.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        enumPlaySpeed->setStatusTip(QApplication::translate("MainWindow", "Play speed for the UWPI data visualisation.", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        pushButtonPlayPause->setToolTip(QApplication::translate("MainWindow", "Displays the current UWPI data in a frame-wise fashion. ", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonPlayPause->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        pushButtonPlayPause->setText(QApplication::translate("MainWindow", "Play", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonCapture->setToolTip(QApplication::translate("MainWindow", "Save UWPI result as an image in c:\\FF_PE_UPI_Data\\ScreenShots.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonCapture->setStatusTip(QApplication::translate("MainWindow", "Save UWPI result as an image in c:\\FF_PE_UPI_Data\\ScreenShots.", 0));
#endif // QT_NO_STATUSTIP
        pushButtonCapture->setText(QApplication::translate("MainWindow", "Save Screenshot", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonSaveMovie->setToolTip(QApplication::translate("MainWindow", "Save the UWPI result as a movie.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonSaveMovie->setStatusTip(QApplication::translate("MainWindow", "Save the UWPI result as a movie.", 0));
#endif // QT_NO_STATUSTIP
        pushButtonSaveMovie->setText(QApplication::translate("MainWindow", "Save Movie", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonEnlarge->setToolTip(QApplication::translate("MainWindow", "Displays the current UWPI data in a frame-wise fashion. ", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonEnlarge->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        pushButtonEnlarge->setText(QApplication::translate("MainWindow", "Show Actual Size", 0));
#ifndef QT_NO_STATUSTIP
        horizontalSliderFrame->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        labelFrame->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        labelFrame->setText(QApplication::translate("MainWindow", "8.200 GHz", 0));
#ifndef QT_NO_TOOLTIP
        dial_intensity->setToolTip(QApplication::translate("MainWindow", "Change the colour intensity of the UWPI result.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        dial_intensity->setStatusTip(QApplication::translate("MainWindow", "Change the colour intensity of the UWPI result.", 0));
#endif // QT_NO_STATUSTIP
        checkBoxGreyscale->setText(QApplication::translate("MainWindow", "Greyscale", 0));
#ifndef QT_NO_TOOLTIP
        dial_intensity_2->setToolTip(QApplication::translate("MainWindow", "Change the colour intensity of the VTWAM result.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        dial_intensity_2->setStatusTip(QApplication::translate("MainWindow", "Change the colour intensity of the VTWAM result.", 0));
#endif // QT_NO_STATUSTIP
        groupBox->setTitle(QApplication::translate("MainWindow", "Data", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonLoadData->setToolTip(QApplication::translate("MainWindow", "Load the previously saved data by selecting its folder.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonLoadData->setStatusTip(QApplication::translate("MainWindow", "Load the previously saved data by selecting its folder.", 0));
#endif // QT_NO_STATUSTIP
        pushButtonLoadData->setText(QApplication::translate("MainWindow", "Load Data", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonSaveData->setToolTip(QApplication::translate("MainWindow", "Save the currentdata in C:\\FSM_Data\\Data.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonSaveData->setStatusTip(QApplication::translate("MainWindow", "Save the currentdata in C:\\FSM_Data\\Data", 0));
#endif // QT_NO_STATUSTIP
        pushButtonSaveData->setText(QApplication::translate("MainWindow", "Save Data", 0));
#ifndef QT_NO_TOOLTIP
        groupBoxFilter->setToolTip(QApplication::translate("MainWindow", "Enable to perform additional post-processing.", 0));
#endif // QT_NO_TOOLTIP
        groupBoxFilter->setTitle(QApplication::translate("MainWindow", "Filter", 0));
#ifndef QT_NO_TOOLTIP
        groupBoxFilterStep1->setToolTip(QApplication::translate("MainWindow", "Enable to perform step-1 of post-processing.", 0));
#endif // QT_NO_TOOLTIP
        groupBoxFilterStep1->setTitle(QApplication::translate("MainWindow", "Step-1", 0));
        labelImageFilterIterations->setText(QApplication::translate("MainWindow", "Iteration:", 0));
        labelImageFilterType->setText(QApplication::translate("MainWindow", "Type:", 0));
        labelImageFilterSize->setText(QApplication::translate("MainWindow", "Size:", 0));
#ifndef QT_NO_TOOLTIP
        groupBoxFilterStep2->setToolTip(QApplication::translate("MainWindow", "Enable to perform step-2 of post-processing.", 0));
#endif // QT_NO_TOOLTIP
        groupBoxFilterStep2->setTitle(QApplication::translate("MainWindow", "Step-2", 0));
        labelImageFilterIterations_2->setText(QApplication::translate("MainWindow", "Iteration:", 0));
        labelImageFilterType_2->setText(QApplication::translate("MainWindow", "Type:", 0));
        labelImageFilterSize_2->setText(QApplication::translate("MainWindow", "Size:", 0));
#ifndef QT_NO_TOOLTIP
        checkBoxBoostSpeed->setToolTip(QApplication::translate("MainWindow", "Processing faster with higher CPU utilization.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBoxBoostSpeed->setStatusTip(QApplication::translate("MainWindow", "Processing faster with higher CPU utilization.", 0));
#endif // QT_NO_STATUSTIP
        checkBoxBoostSpeed->setText(QApplication::translate("MainWindow", "Boost speed", 0));
        pushButtonProcessFilter->setText(QApplication::translate("MainWindow", "Process", 0));
#ifndef QT_NO_TOOLTIP
        groupBoxVtwam->setToolTip(QApplication::translate("MainWindow", "VTWAM Processing", 0));
#endif // QT_NO_TOOLTIP
        groupBoxVtwam->setTitle(QApplication::translate("MainWindow", "VTWAM", 0));
        label_3->setText(QApplication::translate("MainWindow", "Start:", 0));
        labelVtwamStart->setText(QApplication::translate("MainWindow", "US", 0));
        label_4->setText(QApplication::translate("MainWindow", "End:", 0));
        labelVtwamEnd->setText(QApplication::translate("MainWindow", "US", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonProcessVtwam->setToolTip(QApplication::translate("MainWindow", "Start VTWAM processing.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonProcessVtwam->setStatusTip(QApplication::translate("MainWindow", "Start VTWAM Processing", 0));
#endif // QT_NO_STATUSTIP
        pushButtonProcessVtwam->setText(QApplication::translate("MainWindow", "Process", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonCaptureVtwam->setToolTip(QApplication::translate("MainWindow", "Save VTWAM result as an image in c:\\FF_PE_UPI_Data\\ScreenShots.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonCaptureVtwam->setStatusTip(QApplication::translate("MainWindow", "Save VTWAM result as an image in c:\\FF_PE_UPI_Data\\ScreenShots.", 0));
#endif // QT_NO_STATUSTIP
        pushButtonCaptureVtwam->setText(QApplication::translate("MainWindow", "Save Screenshot", 0));
        pushButtonServoStop2->setText(QApplication::translate("MainWindow", "Stop", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonSaveDataCurrent->setToolTip(QApplication::translate("MainWindow", "Save the currentdata in C:\\FSM_Data\\Data.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonSaveDataCurrent->setStatusTip(QApplication::translate("MainWindow", "Save the currentdata in C:\\FSM_Data\\Data", 0));
#endif // QT_NO_STATUSTIP
        pushButtonSaveDataCurrent->setText(QApplication::translate("MainWindow", "Save Current Data", 0));
        tabWidget->setTabText(tabWidget->indexOf(Result), QApplication::translate("MainWindow", "Result", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
