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
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelScanWidth_2;
    QLineEdit *lineEditScanWidth;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelScanHeight_2;
    QLineEdit *lineEditScanHeight;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelScanInterval_3;
    QComboBox *enumScanInterval;
    QWidget *widgetOscilloscope;
    QGroupBox *groupBox_4;
    QSplitter *splitter_7;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButtonJogxp;
    QSpacerItem *horizontalSpacer_9;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_31;
    QPushButton *pushButtonJogzn;
    QPushButton *pushButtonOrigin;
    QPushButton *pushButtonJogzp;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_32;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButtonJogxn;
    QSpacerItem *horizontalSpacer_6;
    QWidget *layoutWidget_9;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButtonGetpos;
    QLineEdit *lineEditXPos;
    QPushButton *pushButtonSetpos;
    QLineEdit *lineEditZPos;
    QLCDNumber *lcdNumberZpos;
    QLCDNumber *lcdNumberXpos;
    QPushButton *pushButtonServoKill;
    QPushButton *pushButtonPnaMeasure;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_22;
    QLabel *labelScanWidth_5;
    QComboBox *enumMeasType;
    QPushButton *pushButtonServoStop;
    QGroupBox *groupBox_plotyAxisRange;
    QLineEdit *lineEdit_yLowerLimit;
    QLineEdit *lineEdit_yUpperLimit;
    QPushButton *pushButton_ySet;
    QLabel *label_yMin;
    QLabel *label_yMax;
    QWidget *Result;
    QScrollArea *scrollArea;
    QWidget *widgettResultSpect;
    QWidget *widgetResultTime;
    QLabel *labelCurrentDataSpec;
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
    QPushButton *pushButtonServoStop2;
    QPushButton *pushButtonSaveDataCurrent;
    QGroupBox *groupBox_colorbar;
    QLineEdit *lineEdit_lowerLimit;
    QLineEdit *lineEdit_upperLimit;
    QPushButton *pushButton_set;
    QLabel *label_Min;
    QLabel *label_Max;
    QGroupBox *groupBox_resultplot_yAxisRange;
    QLineEdit *lineEdit_yLowerLimit_result;
    QLineEdit *lineEdit_yUpperLimit_result;
    QPushButton *pushButton_ySet_result;
    QLabel *label_yMin_result;
    QLabel *label_yMax_result;
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
        tabWidget->setGeometry(QRect(0, 0, 1941, 1181));
        Setting = new QWidget();
        Setting->setObjectName(QStringLiteral("Setting"));
        pushButtonStart = new QPushButton(Setting);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));
        pushButtonStart->setGeometry(QRect(300, 390, 215, 49));
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
        groupBox_5->setGeometry(QRect(10, 230, 791, 132));
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
        groupBoxScan->setGeometry(QRect(10, 10, 791, 71));
        groupBoxScan->setFont(font1);
        horizontalLayout_8 = new QHBoxLayout(groupBoxScan);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelScanWidth_2 = new QLabel(groupBoxScan);
        labelScanWidth_2->setObjectName(QStringLiteral("labelScanWidth_2"));
        labelScanWidth_2->setFont(font2);

        horizontalLayout_2->addWidget(labelScanWidth_2);

        lineEditScanWidth = new QLineEdit(groupBoxScan);
        lineEditScanWidth->setObjectName(QStringLiteral("lineEditScanWidth"));
        sizePolicy1.setHeightForWidth(lineEditScanWidth->sizePolicy().hasHeightForWidth());
        lineEditScanWidth->setSizePolicy(sizePolicy1);
        lineEditScanWidth->setMaximumSize(QSize(70, 22));
        lineEditScanWidth->setFont(font2);
        lineEditScanWidth->setMaxLength(3);
        lineEditScanWidth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lineEditScanWidth);


        horizontalLayout_8->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelScanHeight_2 = new QLabel(groupBoxScan);
        labelScanHeight_2->setObjectName(QStringLiteral("labelScanHeight_2"));
        labelScanHeight_2->setFont(font2);

        horizontalLayout_4->addWidget(labelScanHeight_2);

        lineEditScanHeight = new QLineEdit(groupBoxScan);
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

        horizontalLayout_4->addWidget(lineEditScanHeight);


        horizontalLayout_8->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelScanInterval_3 = new QLabel(groupBoxScan);
        labelScanInterval_3->setObjectName(QStringLiteral("labelScanInterval_3"));
        labelScanInterval_3->setFont(font2);

        horizontalLayout_7->addWidget(labelScanInterval_3);

        enumScanInterval = new QComboBox(groupBoxScan);
        enumScanInterval->setObjectName(QStringLiteral("enumScanInterval"));
        enumScanInterval->setFont(font2);

        horizontalLayout_7->addWidget(enumScanInterval);


        horizontalLayout_8->addLayout(horizontalLayout_7);

        widgetOscilloscope = new QWidget(Setting);
        widgetOscilloscope->setObjectName(QStringLiteral("widgetOscilloscope"));
        widgetOscilloscope->setGeometry(QRect(20, 500, 791, 441));
        groupBox_4 = new QGroupBox(Setting);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 90, 791, 131));
        groupBox_4->setFont(font1);
        splitter_7 = new QSplitter(groupBox_4);
        splitter_7->setObjectName(QStringLiteral("splitter_7"));
        splitter_7->setGeometry(QRect(20, 20, 141, 96));
        splitter_7->setLineWidth(0);
        splitter_7->setOrientation(Qt::Vertical);
        splitter_7->setHandleWidth(0);
        layoutWidget_6 = new QWidget(splitter_7);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_8 = new QSpacerItem(50, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        pushButtonJogxp = new QPushButton(layoutWidget_6);
        pushButtonJogxp->setObjectName(QStringLiteral("pushButtonJogxp"));
        pushButtonJogxp->setEnabled(true);
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        pushButtonJogxp->setFont(font4);
        pushButtonJogxp->setCheckable(false);

        horizontalLayout_5->addWidget(pushButtonJogxp);

        horizontalSpacer_9 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        splitter_7->addWidget(layoutWidget_6);
        layoutWidget_7 = new QWidget(splitter_7);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        horizontalLayout_31 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        horizontalLayout_31->setContentsMargins(0, 0, 0, 0);
        pushButtonJogzn = new QPushButton(layoutWidget_7);
        pushButtonJogzn->setObjectName(QStringLiteral("pushButtonJogzn"));
        pushButtonJogzn->setFont(font4);
        pushButtonJogzn->setCheckable(false);

        horizontalLayout_31->addWidget(pushButtonJogzn);

        pushButtonOrigin = new QPushButton(layoutWidget_7);
        pushButtonOrigin->setObjectName(QStringLiteral("pushButtonOrigin"));
        pushButtonOrigin->setFont(font2);

        horizontalLayout_31->addWidget(pushButtonOrigin);

        pushButtonJogzp = new QPushButton(layoutWidget_7);
        pushButtonJogzp->setObjectName(QStringLiteral("pushButtonJogzp"));
        pushButtonJogzp->setFont(font4);
        pushButtonJogzp->setCheckable(false);

        horizontalLayout_31->addWidget(pushButtonJogzp);

        splitter_7->addWidget(layoutWidget_7);
        layoutWidget_8 = new QWidget(splitter_7);
        layoutWidget_8->setObjectName(QStringLiteral("layoutWidget_8"));
        horizontalLayout_32 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        horizontalLayout_32->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_7 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_32->addItem(horizontalSpacer_7);

        pushButtonJogxn = new QPushButton(layoutWidget_8);
        pushButtonJogxn->setObjectName(QStringLiteral("pushButtonJogxn"));
        pushButtonJogxn->setFont(font);
        pushButtonJogxn->setCheckable(false);

        horizontalLayout_32->addWidget(pushButtonJogxn);

        horizontalSpacer_6 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_32->addItem(horizontalSpacer_6);

        splitter_7->addWidget(layoutWidget_8);
        layoutWidget_9 = new QWidget(groupBox_4);
        layoutWidget_9->setObjectName(QStringLiteral("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(300, 20, 363, 91));
        gridLayout = new QGridLayout(layoutWidget_9);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_9);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(layoutWidget_9);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 0, 1, 1, 1);

        pushButtonGetpos = new QPushButton(layoutWidget_9);
        pushButtonGetpos->setObjectName(QStringLiteral("pushButtonGetpos"));
        pushButtonGetpos->setFont(font2);

        gridLayout->addWidget(pushButtonGetpos, 2, 2, 1, 1);

        lineEditXPos = new QLineEdit(layoutWidget_9);
        lineEditXPos->setObjectName(QStringLiteral("lineEditXPos"));
        lineEditXPos->setFont(font);
        lineEditXPos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEditXPos, 1, 0, 1, 1);

        pushButtonSetpos = new QPushButton(layoutWidget_9);
        pushButtonSetpos->setObjectName(QStringLiteral("pushButtonSetpos"));
        pushButtonSetpos->setFont(font2);

        gridLayout->addWidget(pushButtonSetpos, 1, 2, 1, 1);

        lineEditZPos = new QLineEdit(layoutWidget_9);
        lineEditZPos->setObjectName(QStringLiteral("lineEditZPos"));
        lineEditZPos->setFont(font);
        lineEditZPos->setCursorPosition(4);
        lineEditZPos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEditZPos, 1, 1, 1, 1);

        lcdNumberZpos = new QLCDNumber(layoutWidget_9);
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

        gridLayout->addWidget(lcdNumberZpos, 2, 1, 1, 1);

        lcdNumberXpos = new QLCDNumber(layoutWidget_9);
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

        gridLayout->addWidget(lcdNumberXpos, 2, 0, 1, 1);

        pushButtonServoKill = new QPushButton(groupBox_4);
        pushButtonServoKill->setObjectName(QStringLiteral("pushButtonServoKill"));
        pushButtonServoKill->setGeometry(QRect(200, 20, 71, 91));
        pushButtonServoKill->setFont(font1);
        layoutWidget_9->raise();
        splitter_7->raise();
        pushButtonServoKill->raise();
        pushButtonPnaMeasure = new QPushButton(Setting);
        pushButtonPnaMeasure->setObjectName(QStringLiteral("pushButtonPnaMeasure"));
        pushButtonPnaMeasure->setGeometry(QRect(10, 390, 215, 49));
        sizePolicy.setHeightForWidth(pushButtonPnaMeasure->sizePolicy().hasHeightForWidth());
        pushButtonPnaMeasure->setSizePolicy(sizePolicy);
        pushButtonPnaMeasure->setFont(font);
        layoutWidget3 = new QWidget(Setting);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(50, 500, 120, 24));
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

        pushButtonServoStop = new QPushButton(Setting);
        pushButtonServoStop->setObjectName(QStringLiteral("pushButtonServoStop"));
        pushButtonServoStop->setGeometry(QRect(580, 390, 221, 51));
        pushButtonServoStop->setFont(font1);
        groupBox_plotyAxisRange = new QGroupBox(Setting);
        groupBox_plotyAxisRange->setObjectName(QStringLiteral("groupBox_plotyAxisRange"));
        groupBox_plotyAxisRange->setGeometry(QRect(900, 490, 141, 111));
        groupBox_plotyAxisRange->setFont(font1);
        lineEdit_yLowerLimit = new QLineEdit(groupBox_plotyAxisRange);
        lineEdit_yLowerLimit->setObjectName(QStringLiteral("lineEdit_yLowerLimit"));
        lineEdit_yLowerLimit->setGeometry(QRect(60, 25, 61, 20));
        lineEdit_yLowerLimit->setFont(font2);
        lineEdit_yLowerLimit->setLayoutDirection(Qt::LeftToRight);
        lineEdit_yLowerLimit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_yUpperLimit = new QLineEdit(groupBox_plotyAxisRange);
        lineEdit_yUpperLimit->setObjectName(QStringLiteral("lineEdit_yUpperLimit"));
        lineEdit_yUpperLimit->setGeometry(QRect(60, 53, 61, 20));
        lineEdit_yUpperLimit->setFont(font2);
        lineEdit_yUpperLimit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_ySet = new QPushButton(groupBox_plotyAxisRange);
        pushButton_ySet->setObjectName(QStringLiteral("pushButton_ySet"));
        pushButton_ySet->setGeometry(QRect(15, 80, 95, 23));
        pushButton_ySet->setFont(font2);
        label_yMin = new QLabel(groupBox_plotyAxisRange);
        label_yMin->setObjectName(QStringLiteral("label_yMin"));
        label_yMin->setGeometry(QRect(15, 25, 41, 16));
        label_yMin->setFont(font2);
        label_yMax = new QLabel(groupBox_plotyAxisRange);
        label_yMax->setObjectName(QStringLiteral("label_yMax"));
        label_yMax->setGeometry(QRect(15, 53, 41, 16));
        label_yMax->setFont(font2);
        tabWidget->addTab(Setting, QString());
        Result = new QWidget();
        Result->setObjectName(QStringLiteral("Result"));
        scrollArea = new QScrollArea(Result);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(150, 110, 1631, 661));
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
        widgetResultTime->setGeometry(QRect(320, 780, 1301, 251));
        labelCurrentDataSpec = new QLabel(Result);
        labelCurrentDataSpec->setObjectName(QStringLiteral("labelCurrentDataSpec"));
        labelCurrentDataSpec->setGeometry(QRect(1080, 10, 1021, 81));
        labelCurrentDataSpec->setFont(font4);
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
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(horizontalSliderFrame->sizePolicy().hasHeightForWidth());
        horizontalSliderFrame->setSizePolicy(sizePolicy2);
        horizontalSliderFrame->setValue(50);
        horizontalSliderFrame->setOrientation(Qt::Horizontal);

        horizontalLayout_26->addWidget(horizontalSliderFrame);

        labelFrame = new QLabel(groupBoxResultControl);
        labelFrame->setObjectName(QStringLiteral("labelFrame"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelFrame->sizePolicy().hasHeightForWidth());
        labelFrame->setSizePolicy(sizePolicy3);
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
        groupBox->setGeometry(QRect(10, 60, 121, 103));
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

        pushButtonServoStop2 = new QPushButton(Result);
        pushButtonServoStop2->setObjectName(QStringLiteral("pushButtonServoStop2"));
        pushButtonServoStop2->setGeometry(QRect(910, 5, 121, 101));
        sizePolicy.setHeightForWidth(pushButtonServoStop2->sizePolicy().hasHeightForWidth());
        pushButtonServoStop2->setSizePolicy(sizePolicy);
        pushButtonServoStop2->setFont(font4);
        pushButtonSaveDataCurrent = new QPushButton(Result);
        pushButtonSaveDataCurrent->setObjectName(QStringLiteral("pushButtonSaveDataCurrent"));
        pushButtonSaveDataCurrent->setGeometry(QRect(10, 21, 121, 23));
        groupBox_colorbar = new QGroupBox(Result);
        groupBox_colorbar->setObjectName(QStringLiteral("groupBox_colorbar"));
        groupBox_colorbar->setGeometry(QRect(10, 180, 121, 111));
        groupBox_colorbar->setFont(font1);
        lineEdit_lowerLimit = new QLineEdit(groupBox_colorbar);
        lineEdit_lowerLimit->setObjectName(QStringLiteral("lineEdit_lowerLimit"));
        lineEdit_lowerLimit->setGeometry(QRect(49, 25, 61, 20));
        lineEdit_lowerLimit->setFont(font2);
        lineEdit_lowerLimit->setLayoutDirection(Qt::LeftToRight);
        lineEdit_lowerLimit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_upperLimit = new QLineEdit(groupBox_colorbar);
        lineEdit_upperLimit->setObjectName(QStringLiteral("lineEdit_upperLimit"));
        lineEdit_upperLimit->setGeometry(QRect(49, 53, 61, 20));
        lineEdit_upperLimit->setFont(font2);
        lineEdit_upperLimit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_set = new QPushButton(groupBox_colorbar);
        pushButton_set->setObjectName(QStringLiteral("pushButton_set"));
        pushButton_set->setGeometry(QRect(15, 80, 95, 23));
        pushButton_set->setFont(font2);
        label_Min = new QLabel(groupBox_colorbar);
        label_Min->setObjectName(QStringLiteral("label_Min"));
        label_Min->setGeometry(QRect(15, 25, 23, 16));
        label_Min->setFont(font2);
        label_Max = new QLabel(groupBox_colorbar);
        label_Max->setObjectName(QStringLiteral("label_Max"));
        label_Max->setGeometry(QRect(15, 53, 24, 16));
        label_Max->setFont(font2);
        groupBox_resultplot_yAxisRange = new QGroupBox(Result);
        groupBox_resultplot_yAxisRange->setObjectName(QStringLiteral("groupBox_resultplot_yAxisRange"));
        groupBox_resultplot_yAxisRange->setGeometry(QRect(150, 780, 141, 131));
        groupBox_resultplot_yAxisRange->setFont(font1);
        lineEdit_yLowerLimit_result = new QLineEdit(groupBox_resultplot_yAxisRange);
        lineEdit_yLowerLimit_result->setObjectName(QStringLiteral("lineEdit_yLowerLimit_result"));
        lineEdit_yLowerLimit_result->setGeometry(QRect(65, 20, 61, 20));
        lineEdit_yLowerLimit_result->setFont(font2);
        lineEdit_yLowerLimit_result->setLayoutDirection(Qt::LeftToRight);
        lineEdit_yLowerLimit_result->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_yUpperLimit_result = new QLineEdit(groupBox_resultplot_yAxisRange);
        lineEdit_yUpperLimit_result->setObjectName(QStringLiteral("lineEdit_yUpperLimit_result"));
        lineEdit_yUpperLimit_result->setGeometry(QRect(65, 50, 61, 20));
        lineEdit_yUpperLimit_result->setFont(font2);
        lineEdit_yUpperLimit_result->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_ySet_result = new QPushButton(groupBox_resultplot_yAxisRange);
        pushButton_ySet_result->setObjectName(QStringLiteral("pushButton_ySet_result"));
        pushButton_ySet_result->setGeometry(QRect(20, 80, 106, 31));
        pushButton_ySet_result->setFont(font2);
        label_yMin_result = new QLabel(groupBox_resultplot_yAxisRange);
        label_yMin_result->setObjectName(QStringLiteral("label_yMin_result"));
        label_yMin_result->setGeometry(QRect(20, 20, 41, 16));
        label_yMin_result->setFont(font2);
        label_yMax_result = new QLabel(groupBox_resultplot_yAxisRange);
        label_yMax_result->setObjectName(QStringLiteral("label_yMax_result"));
        label_yMax_result->setGeometry(QRect(20, 50, 41, 16));
        label_yMax_result->setFont(font2);
        tabWidget->addTab(Result, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1940, 21));
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
        QWidget::setTabOrder(scrollArea, horizontalSliderFrame);
        QWidget::setTabOrder(horizontalSliderFrame, pushButtonLoadData);
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
        groupBoxScan->setTitle(QApplication::translate("MainWindow", "Scan", 0));
        labelScanWidth_2->setText(QApplication::translate("MainWindow", "Width(mm):", 0));
#ifndef QT_NO_TOOLTIP
        lineEditScanWidth->setToolTip(QApplication::translate("MainWindow", "Valid range: 50mm~500mm - Increment: 10mm", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEditScanWidth->setStatusTip(QApplication::translate("MainWindow", "Width of scan area. Valid range: 50mm~500mm - Increment: 10mm", 0));
#endif // QT_NO_STATUSTIP
        labelScanHeight_2->setText(QApplication::translate("MainWindow", "Height(mm):", 0));
#ifndef QT_NO_TOOLTIP
        lineEditScanHeight->setToolTip(QApplication::translate("MainWindow", "Valid range: 50mm~500mm - Increment: 10mm", 0));
#endif // QT_NO_TOOLTIP
        labelScanInterval_3->setText(QApplication::translate("MainWindow", "Interval(mm):", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Navigator", 0));
        pushButtonJogxp->setText(QApplication::translate("MainWindow", "^", 0));
        pushButtonJogzn->setText(QApplication::translate("MainWindow", "<", 0));
        pushButtonOrigin->setText(QApplication::translate("MainWindow", "Origin", 0));
        pushButtonJogzp->setText(QApplication::translate("MainWindow", ">", 0));
        pushButtonJogxn->setText(QApplication::translate("MainWindow", "v", 0));
        label_5->setText(QApplication::translate("MainWindow", "X-axis (mm)", 0));
        label_6->setText(QApplication::translate("MainWindow", "Z-axis (mm)", 0));
        pushButtonGetpos->setText(QApplication::translate("MainWindow", "Get", 0));
        lineEditXPos->setText(QApplication::translate("MainWindow", "0.00", 0));
        pushButtonSetpos->setText(QApplication::translate("MainWindow", "Set", 0));
        lineEditZPos->setText(QApplication::translate("MainWindow", "0.00", 0));
        pushButtonServoKill->setText(QApplication::translate("MainWindow", "KILL", 0));
        pushButtonPnaMeasure->setText(QApplication::translate("MainWindow", "Measure", 0));
        labelScanWidth_5->setText(QApplication::translate("MainWindow", "Meas:", 0));
        pushButtonServoStop->setText(QApplication::translate("MainWindow", "STOP", 0));
        groupBox_plotyAxisRange->setTitle(QApplication::translate("MainWindow", "Y-Axis range", 0));
        pushButton_ySet->setText(QApplication::translate("MainWindow", "Set", 0));
        label_yMin->setText(QApplication::translate("MainWindow", "Lower: ", 0));
        label_yMax->setText(QApplication::translate("MainWindow", "Upper:", 0));
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
        pushButtonServoStop2->setText(QApplication::translate("MainWindow", "Stop", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonSaveDataCurrent->setToolTip(QApplication::translate("MainWindow", "Save the currentdata in C:\\FSM_Data\\Data.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonSaveDataCurrent->setStatusTip(QApplication::translate("MainWindow", "Save the currentdata in C:\\FSM_Data\\Data", 0));
#endif // QT_NO_STATUSTIP
        pushButtonSaveDataCurrent->setText(QApplication::translate("MainWindow", "Save Current Data", 0));
        groupBox_colorbar->setTitle(QApplication::translate("MainWindow", "Colorbar range", 0));
        pushButton_set->setText(QApplication::translate("MainWindow", "Set", 0));
        label_Min->setText(QApplication::translate("MainWindow", "Min: ", 0));
        label_Max->setText(QApplication::translate("MainWindow", "Max:", 0));
        groupBox_resultplot_yAxisRange->setTitle(QApplication::translate("MainWindow", "Y-Axis limits", 0));
        pushButton_ySet_result->setText(QApplication::translate("MainWindow", "Set", 0));
        label_yMin_result->setText(QApplication::translate("MainWindow", "Lower: ", 0));
        label_yMax_result->setText(QApplication::translate("MainWindow", "Upper:", 0));
        tabWidget->setTabText(tabWidget->indexOf(Result), QApplication::translate("MainWindow", "Result", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
