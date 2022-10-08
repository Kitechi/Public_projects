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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
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
    QAction *actionBand_Divider_Scenario;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *SettingTab;
    QGroupBox *groupBox_1;
    QCheckBox *checkBoxEnableMultiBand;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelScanInterval_3;
    QComboBox *enumMultiBandSettingLev1;
    QComboBox *enumMultiBandSettingLev2;
    QPushButton *pushButtonFilterConfig;
    QLabel *labelConfigSetting;
    QGroupBox *groupBoxScan;
    QLabel *labelScanPars;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_27;
    QHBoxLayout *horizontalLayout_42;
    QHBoxLayout *horizontalLayout_43;
    QLabel *labelScanRadius;
    QLineEdit *lineEditScanRadius;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelScanHeight;
    QLineEdit *lineEditScanWidth;
    QHBoxLayout *horizontalLayout_44;
    QLabel *labelScanTrigPerRev;
    QComboBox *enumScanTrigPerRev;
    QHBoxLayout *horizontalLayout_45;
    QLabel *labelScanSpeedDegPerSec;
    QComboBox *enumScanScanSpeedDegPerSec;
    QGroupBox *groupBoxMultiScan;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelScanInterval_2;
    QComboBox *enumTotalScans;
    QCheckBox *checkBox_useCurrentResults;
    QVBoxLayout *verticalLayout_28;
    QHBoxLayout *horizontalLayout_30;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_17;
    QComboBox *enumCurrent;
    QPushButton *pushButtonLaserConfigPrfCurr;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *pushButtonLaserControl;
    QLabel *labelLaserStatus;
    QProgressBar *progressBar;
    QWidget *widgetOscilloscope;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_51;
    QHBoxLayout *horizontalLayout_50;
    QHBoxLayout *horizontalLayout_35;
    QPushButton *pushButtonSpinClockWise;
    QPushButton *pushButtonOriginRot;
    QPushButton *pushButtonSpinAClockWise;
    QVBoxLayout *verticalLayout_29;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEditRotPos;
    QPushButton *pushButtonRotSetpos;
    QHBoxLayout *horizontalLayout_6;
    QLCDNumber *lcdNumberRotPos;
    QPushButton *pushButtonRotGetPos;
    QGroupBox *groupBox_7;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QPushButton *pushButtonSetpos;
    QLineEdit *lineEditZPos;
    QLineEdit *lineEditXpos;
    QLabel *label_6;
    QPushButton *pushButtonGetpos;
    QLCDNumber *lcdNumberZpos;
    QLCDNumber *lcdNumberXpos;
    QSplitter *splitter_7;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButtonJogxp;
    QSpacerItem *horizontalSpacer_9;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_31;
    QPushButton *pushButtonJogzn;
    QPushButton *pushButtonOrigin;
    QPushButton *pushButtonJogzp;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_32;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButtonJogxn;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButtonServoStop;
    QPushButton *pushButtonLdvAutoFocus_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_24;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *pushButtonSaveSettings;
    QPushButton *pushButtonLoadSettings;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *pushButtonInit;
    QPushButton *pushButtonDaqSet;
    QPushButton *pushButtonQuit;
    QLabel *labelRefWarning;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_10;
    QProgressBar *ldvSignalLevel;
    QPushButton *pushButtonLdvAutoFocus;
    QCheckBox *checkBoxRealTimeMedian;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_39;
    QHBoxLayout *horizontalLayout_38;
    QHBoxLayout *horizontalLayout_37;
    QLabel *labelScanHeight_2;
    QLineEdit *lineEditDaqVoltage;
    QPushButton *pushButtonDaqConfig;
    QWidget *layoutWidget9;
    QHBoxLayout *horizontalLayout_25;
    QLabel *labelScanInterval_4;
    QComboBox *enumOsciChannel;
    QWidget *layoutWidget10;
    QHBoxLayout *horizontalLayout_36;
    QLabel *labelTrigDelay;
    QLineEdit *lineEditDaqTrigDelay;
    QWidget *Subbandtab;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_40;
    QHBoxLayout *horizontalLayout_41;
    QRadioButton *radioButtonSubband1;
    QRadioButton *radioButtonSubband2;
    QRadioButton *radioButtonSubband3;
    QWidget *layoutWidget11;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_28;
    QComboBox *enumPlaySpeedSubband;
    QPushButton *pushButtonPlayPauseSubband;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_29;
    QSlider *horizontalSliderSubband;
    QLabel *labelFrameSubband;
    QDial *dial_intensity_Subband;
    QScrollArea *scrollArea_2;
    QWidget *widgetSubbandSpect;
    QLabel *labelConfigSettingSubBand;
    QPushButton *pushButtonServoStop3;
    QWidget *ResultTab;
    QWidget *widgetVtwam;
    QScrollArea *scrollArea;
    QWidget *widgettResultSpect;
    QWidget *widgetResultTime;
    QWidget *widgetResultControl;
    QGroupBox *groupBoxResultControl;
    QHBoxLayout *horizontalLayout_21;
    QHBoxLayout *horizontalLayout_20;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_17;
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
    QLabel *labelVtwamInfo;
    QLabel *labelVtwamRangeTitle;
    QPushButton *pushButtonServoStop2;
    QLabel *labelCurrentDataSpec;
    QGroupBox *groupBoxFilter;
    QVBoxLayout *verticalLayout_26;
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
    QPushButton *pushButtonVtwamAddRange;
    QPushButton *pushButtonVtwamClearRanges;
    QPushButton *pushButtonProcessVtwam;
    QPushButton *pushButtonCaptureVtwam;
    QWidget *layoutWidget12;
    QVBoxLayout *verticalLayout_19;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButtonProcessXCor;
    QPushButton *pushButtonCaptureXcor;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_17;
    QPushButton *pushButtonLoadData;
    QPushButton *pushButtonSaveData;
    QWidget *layoutWidget13;
    QVBoxLayout *verticalLayout_24;
    QWidget *layoutWidget14;
    QVBoxLayout *verticalLayout_211;
    QWidget *layoutWidget15;
    QHBoxLayout *horizontalLayout_13;
    QWidget *layoutWidget16;
    QHBoxLayout *horizontalLayout_19;
    QWidget *layoutWidget17;
    QVBoxLayout *verticalLayout_27;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

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
        actionBand_Divider_Scenario = new QAction(MainWindow);
        actionBand_Divider_Scenario->setObjectName(QStringLiteral("actionBand_Divider_Scenario"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 30, 2832, 1171));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        tabWidget->setFont(font);
        SettingTab = new QWidget();
        SettingTab->setObjectName(QStringLiteral("SettingTab"));
        groupBox_1 = new QGroupBox(SettingTab);
        groupBox_1->setObjectName(QStringLiteral("groupBox_1"));
        groupBox_1->setGeometry(QRect(11, 0, 1121, 101));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox_1->setFont(font1);
        checkBoxEnableMultiBand = new QCheckBox(groupBox_1);
        checkBoxEnableMultiBand->setObjectName(QStringLiteral("checkBoxEnableMultiBand"));
        checkBoxEnableMultiBand->setGeometry(QRect(10, 20, 241, 22));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        checkBoxEnableMultiBand->setFont(font2);
        checkBoxEnableMultiBand->setChecked(true);
        layoutWidget = new QWidget(groupBox_1);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(18, 59, 361, 26));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelScanInterval_3 = new QLabel(layoutWidget);
        labelScanInterval_3->setObjectName(QStringLiteral("labelScanInterval_3"));
        labelScanInterval_3->setFont(font);

        horizontalLayout_3->addWidget(labelScanInterval_3);

        enumMultiBandSettingLev1 = new QComboBox(layoutWidget);
        enumMultiBandSettingLev1->setObjectName(QStringLiteral("enumMultiBandSettingLev1"));
        enumMultiBandSettingLev1->setFont(font);

        horizontalLayout_3->addWidget(enumMultiBandSettingLev1);

        enumMultiBandSettingLev2 = new QComboBox(layoutWidget);
        enumMultiBandSettingLev2->setObjectName(QStringLiteral("enumMultiBandSettingLev2"));
        enumMultiBandSettingLev2->setFont(font);

        horizontalLayout_3->addWidget(enumMultiBandSettingLev2);


        horizontalLayout_14->addLayout(horizontalLayout_3);

        pushButtonFilterConfig = new QPushButton(layoutWidget);
        pushButtonFilterConfig->setObjectName(QStringLiteral("pushButtonFilterConfig"));
        pushButtonFilterConfig->setFont(font);
        pushButtonFilterConfig->setCheckable(false);
        pushButtonFilterConfig->setChecked(false);

        horizontalLayout_14->addWidget(pushButtonFilterConfig);

        labelConfigSetting = new QLabel(groupBox_1);
        labelConfigSetting->setObjectName(QStringLiteral("labelConfigSetting"));
        labelConfigSetting->setGeometry(QRect(470, 20, 401, 81));
        labelConfigSetting->setFont(font2);
        labelConfigSetting->setFrameShape(QFrame::NoFrame);
        groupBoxScan = new QGroupBox(SettingTab);
        groupBoxScan->setObjectName(QStringLiteral("groupBoxScan"));
        groupBoxScan->setGeometry(QRect(10, 100, 1571, 221));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        groupBoxScan->setFont(font3);
        labelScanPars = new QLabel(groupBoxScan);
        labelScanPars->setObjectName(QStringLiteral("labelScanPars"));
        labelScanPars->setGeometry(QRect(20, 90, 521, 121));
        labelScanPars->setFont(font2);
        labelScanPars->setFrameShape(QFrame::NoFrame);
        layoutWidget1 = new QWidget(groupBoxScan);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(14, 30, 1519, 69));
        horizontalLayout_27 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        horizontalLayout_27->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setSpacing(6);
        horizontalLayout_42->setObjectName(QStringLiteral("horizontalLayout_42"));
        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setSpacing(6);
        horizontalLayout_43->setObjectName(QStringLiteral("horizontalLayout_43"));
        labelScanRadius = new QLabel(layoutWidget1);
        labelScanRadius->setObjectName(QStringLiteral("labelScanRadius"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelScanRadius->sizePolicy().hasHeightForWidth());
        labelScanRadius->setSizePolicy(sizePolicy);
        labelScanRadius->setFont(font);

        horizontalLayout_43->addWidget(labelScanRadius);

        lineEditScanRadius = new QLineEdit(layoutWidget1);
        lineEditScanRadius->setObjectName(QStringLiteral("lineEditScanRadius"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditScanRadius->sizePolicy().hasHeightForWidth());
        lineEditScanRadius->setSizePolicy(sizePolicy1);
        lineEditScanRadius->setMaximumSize(QSize(70, 22));
        lineEditScanRadius->setFont(font);
        lineEditScanRadius->setMaxLength(5);
        lineEditScanRadius->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_43->addWidget(lineEditScanRadius);


        horizontalLayout_42->addLayout(horizontalLayout_43);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelScanHeight = new QLabel(layoutWidget1);
        labelScanHeight->setObjectName(QStringLiteral("labelScanHeight"));
        sizePolicy.setHeightForWidth(labelScanHeight->sizePolicy().hasHeightForWidth());
        labelScanHeight->setSizePolicy(sizePolicy);
        labelScanHeight->setFont(font);

        horizontalLayout_4->addWidget(labelScanHeight);

        lineEditScanWidth = new QLineEdit(layoutWidget1);
        lineEditScanWidth->setObjectName(QStringLiteral("lineEditScanWidth"));
        sizePolicy1.setHeightForWidth(lineEditScanWidth->sizePolicy().hasHeightForWidth());
        lineEditScanWidth->setSizePolicy(sizePolicy1);
        lineEditScanWidth->setMaximumSize(QSize(70, 20));
        lineEditScanWidth->setFont(font);
        lineEditScanWidth->setToolTipDuration(1000);
#ifndef QT_NO_STATUSTIP
        lineEditScanWidth->setStatusTip(QStringLiteral("Height of scan area. Valid range: 50mm~500mm - Increment: 10mm"));
#endif // QT_NO_STATUSTIP
        lineEditScanWidth->setMaxLength(5);
        lineEditScanWidth->setFrame(true);
        lineEditScanWidth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditScanWidth->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEditScanWidth->setClearButtonEnabled(false);

        horizontalLayout_4->addWidget(lineEditScanWidth);


        horizontalLayout_42->addLayout(horizontalLayout_4);

        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setSpacing(6);
        horizontalLayout_44->setObjectName(QStringLiteral("horizontalLayout_44"));
        labelScanTrigPerRev = new QLabel(layoutWidget1);
        labelScanTrigPerRev->setObjectName(QStringLiteral("labelScanTrigPerRev"));
        sizePolicy.setHeightForWidth(labelScanTrigPerRev->sizePolicy().hasHeightForWidth());
        labelScanTrigPerRev->setSizePolicy(sizePolicy);
        labelScanTrigPerRev->setFont(font);

        horizontalLayout_44->addWidget(labelScanTrigPerRev);

        enumScanTrigPerRev = new QComboBox(layoutWidget1);
        enumScanTrigPerRev->setObjectName(QStringLiteral("enumScanTrigPerRev"));
        sizePolicy1.setHeightForWidth(enumScanTrigPerRev->sizePolicy().hasHeightForWidth());
        enumScanTrigPerRev->setSizePolicy(sizePolicy1);
        enumScanTrigPerRev->setFont(font);

        horizontalLayout_44->addWidget(enumScanTrigPerRev);


        horizontalLayout_42->addLayout(horizontalLayout_44);

        horizontalLayout_45 = new QHBoxLayout();
        horizontalLayout_45->setSpacing(6);
        horizontalLayout_45->setObjectName(QStringLiteral("horizontalLayout_45"));
        labelScanSpeedDegPerSec = new QLabel(layoutWidget1);
        labelScanSpeedDegPerSec->setObjectName(QStringLiteral("labelScanSpeedDegPerSec"));
        sizePolicy.setHeightForWidth(labelScanSpeedDegPerSec->sizePolicy().hasHeightForWidth());
        labelScanSpeedDegPerSec->setSizePolicy(sizePolicy);
        labelScanSpeedDegPerSec->setFont(font);

        horizontalLayout_45->addWidget(labelScanSpeedDegPerSec);

        enumScanScanSpeedDegPerSec = new QComboBox(layoutWidget1);
        enumScanScanSpeedDegPerSec->setObjectName(QStringLiteral("enumScanScanSpeedDegPerSec"));
        sizePolicy1.setHeightForWidth(enumScanScanSpeedDegPerSec->sizePolicy().hasHeightForWidth());
        enumScanScanSpeedDegPerSec->setSizePolicy(sizePolicy1);
        enumScanScanSpeedDegPerSec->setFont(font);

        horizontalLayout_45->addWidget(enumScanScanSpeedDegPerSec);


        horizontalLayout_42->addLayout(horizontalLayout_45);


        horizontalLayout_27->addLayout(horizontalLayout_42);

        groupBoxMultiScan = new QGroupBox(layoutWidget1);
        groupBoxMultiScan->setObjectName(QStringLiteral("groupBoxMultiScan"));
        QFont font4;
        font4.setKerning(false);
        groupBoxMultiScan->setFont(font4);
        groupBoxMultiScan->setTitle(QStringLiteral("Multi-Scan Settings"));
        groupBoxMultiScan->setAlignment(Qt::AlignCenter);
        groupBoxMultiScan->setFlat(false);
        horizontalLayout_11 = new QHBoxLayout(groupBoxMultiScan);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        labelScanInterval_2 = new QLabel(groupBoxMultiScan);
        labelScanInterval_2->setObjectName(QStringLiteral("labelScanInterval_2"));
        labelScanInterval_2->setFont(font);

        horizontalLayout_8->addWidget(labelScanInterval_2);

        enumTotalScans = new QComboBox(groupBoxMultiScan);
        enumTotalScans->setObjectName(QStringLiteral("enumTotalScans"));
        enumTotalScans->setFont(font);

        horizontalLayout_8->addWidget(enumTotalScans);


        horizontalLayout_10->addLayout(horizontalLayout_8);

        checkBox_useCurrentResults = new QCheckBox(groupBoxMultiScan);
        checkBox_useCurrentResults->setObjectName(QStringLiteral("checkBox_useCurrentResults"));
        checkBox_useCurrentResults->setEnabled(false);
        checkBox_useCurrentResults->setFont(font);

        horizontalLayout_10->addWidget(checkBox_useCurrentResults);


        horizontalLayout_11->addLayout(horizontalLayout_10);


        horizontalLayout_27->addWidget(groupBoxMultiScan);

        verticalLayout_28 = new QVBoxLayout();
        verticalLayout_28->setSpacing(6);
        verticalLayout_28->setObjectName(QStringLiteral("verticalLayout_28"));
        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        label_17 = new QLabel(layoutWidget1);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        label_17->setMinimumSize(QSize(0, 0));
        label_17->setFont(font);
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_22->addWidget(label_17);

        enumCurrent = new QComboBox(layoutWidget1);
        enumCurrent->setObjectName(QStringLiteral("enumCurrent"));
        sizePolicy1.setHeightForWidth(enumCurrent->sizePolicy().hasHeightForWidth());
        enumCurrent->setSizePolicy(sizePolicy1);
        enumCurrent->setMinimumSize(QSize(55, 0));
        enumCurrent->setFont(font);

        horizontalLayout_22->addWidget(enumCurrent);


        horizontalLayout_30->addLayout(horizontalLayout_22);

        pushButtonLaserConfigPrfCurr = new QPushButton(layoutWidget1);
        pushButtonLaserConfigPrfCurr->setObjectName(QStringLiteral("pushButtonLaserConfigPrfCurr"));
        sizePolicy1.setHeightForWidth(pushButtonLaserConfigPrfCurr->sizePolicy().hasHeightForWidth());
        pushButtonLaserConfigPrfCurr->setSizePolicy(sizePolicy1);
        pushButtonLaserConfigPrfCurr->setFont(font);
        pushButtonLaserConfigPrfCurr->setCheckable(false);
        pushButtonLaserConfigPrfCurr->setChecked(false);

        horizontalLayout_30->addWidget(pushButtonLaserConfigPrfCurr);


        verticalLayout_28->addLayout(horizontalLayout_30);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setSizeConstraint(QLayout::SetFixedSize);
        pushButtonLaserControl = new QPushButton(layoutWidget1);
        pushButtonLaserControl->setObjectName(QStringLiteral("pushButtonLaserControl"));
        pushButtonLaserControl->setFont(font);
        pushButtonLaserControl->setCheckable(true);
        pushButtonLaserControl->setChecked(false);

        horizontalLayout_18->addWidget(pushButtonLaserControl);

        labelLaserStatus = new QLabel(layoutWidget1);
        labelLaserStatus->setObjectName(QStringLiteral("labelLaserStatus"));
        labelLaserStatus->setFont(font);

        horizontalLayout_18->addWidget(labelLaserStatus);


        verticalLayout_28->addLayout(horizontalLayout_18);


        horizontalLayout_27->addLayout(verticalLayout_28);

        progressBar = new QProgressBar(SettingTab);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(0, 1060, 118, 16));
        progressBar->setValue(24);
        widgetOscilloscope = new QWidget(SettingTab);
        widgetOscilloscope->setObjectName(QStringLiteral("widgetOscilloscope"));
        widgetOscilloscope->setEnabled(true);
        widgetOscilloscope->setGeometry(QRect(0, 660, 1131, 311));
        groupBox_4 = new QGroupBox(SettingTab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 320, 1151, 171));
        groupBox_4->setFont(font3);
        groupBox_6 = new QGroupBox(groupBox_4);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(530, 30, 421, 102));
        groupBox_6->setFlat(false);
        groupBox_6->setCheckable(false);
        horizontalLayout_51 = new QHBoxLayout(groupBox_6);
        horizontalLayout_51->setSpacing(6);
        horizontalLayout_51->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_51->setObjectName(QStringLiteral("horizontalLayout_51"));
        horizontalLayout_50 = new QHBoxLayout();
        horizontalLayout_50->setSpacing(6);
        horizontalLayout_50->setObjectName(QStringLiteral("horizontalLayout_50"));
        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setSpacing(6);
        horizontalLayout_35->setObjectName(QStringLiteral("horizontalLayout_35"));
        pushButtonSpinClockWise = new QPushButton(groupBox_6);
        pushButtonSpinClockWise->setObjectName(QStringLiteral("pushButtonSpinClockWise"));
        QFont font5;
        font5.setPointSize(15);
        font5.setBold(false);
        font5.setWeight(50);
        pushButtonSpinClockWise->setFont(font5);
        pushButtonSpinClockWise->setCheckable(false);

        horizontalLayout_35->addWidget(pushButtonSpinClockWise);

        pushButtonOriginRot = new QPushButton(groupBox_6);
        pushButtonOriginRot->setObjectName(QStringLiteral("pushButtonOriginRot"));
        pushButtonOriginRot->setFont(font2);

        horizontalLayout_35->addWidget(pushButtonOriginRot);

        pushButtonSpinAClockWise = new QPushButton(groupBox_6);
        pushButtonSpinAClockWise->setObjectName(QStringLiteral("pushButtonSpinAClockWise"));
        pushButtonSpinAClockWise->setFont(font5);
        pushButtonSpinAClockWise->setCheckable(false);

        horizontalLayout_35->addWidget(pushButtonSpinAClockWise);


        horizontalLayout_50->addLayout(horizontalLayout_35);

        verticalLayout_29 = new QVBoxLayout();
        verticalLayout_29->setSpacing(6);
        verticalLayout_29->setObjectName(QStringLiteral("verticalLayout_29"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lineEditRotPos = new QLineEdit(groupBox_6);
        lineEditRotPos->setObjectName(QStringLiteral("lineEditRotPos"));
        lineEditRotPos->setFont(font2);
        lineEditRotPos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(lineEditRotPos);

        pushButtonRotSetpos = new QPushButton(groupBox_6);
        pushButtonRotSetpos->setObjectName(QStringLiteral("pushButtonRotSetpos"));
        pushButtonRotSetpos->setFont(font);

        horizontalLayout_5->addWidget(pushButtonRotSetpos);


        verticalLayout_29->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        lcdNumberRotPos = new QLCDNumber(groupBox_6);
        lcdNumberRotPos->setObjectName(QStringLiteral("lcdNumberRotPos"));
        QFont font6;
        font6.setBold(true);
        font6.setWeight(75);
        font6.setStyleStrategy(QFont::PreferDefault);
        lcdNumberRotPos->setFont(font6);
        lcdNumberRotPos->setLayoutDirection(Qt::LeftToRight);
        lcdNumberRotPos->setFrameShape(QFrame::Box);
        lcdNumberRotPos->setFrameShadow(QFrame::Plain);
        lcdNumberRotPos->setLineWidth(1);
        lcdNumberRotPos->setMidLineWidth(0);
        lcdNumberRotPos->setSmallDecimalPoint(false);
        lcdNumberRotPos->setDigitCount(12);
        lcdNumberRotPos->setSegmentStyle(QLCDNumber::Flat);
        lcdNumberRotPos->setProperty("value", QVariant(0.05));

        horizontalLayout_6->addWidget(lcdNumberRotPos);

        pushButtonRotGetPos = new QPushButton(groupBox_6);
        pushButtonRotGetPos->setObjectName(QStringLiteral("pushButtonRotGetPos"));
        pushButtonRotGetPos->setFont(font);

        horizontalLayout_6->addWidget(pushButtonRotGetPos);


        verticalLayout_29->addLayout(horizontalLayout_6);


        horizontalLayout_50->addLayout(verticalLayout_29);


        horizontalLayout_51->addLayout(horizontalLayout_50);

        groupBox_7 = new QGroupBox(groupBox_4);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 30, 511, 131));
        layoutWidget2 = new QWidget(groupBox_7);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(160, 30, 348, 91));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        pushButtonSetpos = new QPushButton(layoutWidget2);
        pushButtonSetpos->setObjectName(QStringLiteral("pushButtonSetpos"));
        pushButtonSetpos->setFont(font);

        gridLayout->addWidget(pushButtonSetpos, 1, 2, 1, 1);

        lineEditZPos = new QLineEdit(layoutWidget2);
        lineEditZPos->setObjectName(QStringLiteral("lineEditZPos"));
        lineEditZPos->setFont(font2);
        lineEditZPos->setCursorPosition(4);
        lineEditZPos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEditZPos, 1, 1, 1, 1);

        lineEditXpos = new QLineEdit(layoutWidget2);
        lineEditXpos->setObjectName(QStringLiteral("lineEditXpos"));
        lineEditXpos->setFont(font2);
        lineEditXpos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEditXpos, 1, 0, 1, 1);

        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 0, 1, 1, 1);

        pushButtonGetpos = new QPushButton(layoutWidget2);
        pushButtonGetpos->setObjectName(QStringLiteral("pushButtonGetpos"));
        pushButtonGetpos->setFont(font);

        gridLayout->addWidget(pushButtonGetpos, 2, 2, 1, 1);

        lcdNumberZpos = new QLCDNumber(layoutWidget2);
        lcdNumberZpos->setObjectName(QStringLiteral("lcdNumberZpos"));
        lcdNumberZpos->setFont(font6);
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

        lcdNumberXpos = new QLCDNumber(layoutWidget2);
        lcdNumberXpos->setObjectName(QStringLiteral("lcdNumberXpos"));
        lcdNumberXpos->setFont(font6);
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

        splitter_7 = new QSplitter(groupBox_7);
        splitter_7->setObjectName(QStringLiteral("splitter_7"));
        splitter_7->setGeometry(QRect(10, 30, 141, 96));
        splitter_7->setLineWidth(0);
        splitter_7->setOrientation(Qt::Vertical);
        splitter_7->setHandleWidth(0);
        layoutWidget3 = new QWidget(splitter_7);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_8 = new QSpacerItem(50, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        pushButtonJogxp = new QPushButton(layoutWidget3);
        pushButtonJogxp->setObjectName(QStringLiteral("pushButtonJogxp"));
        pushButtonJogxp->setFont(font2);
        pushButtonJogxp->setCheckable(false);

        horizontalLayout_2->addWidget(pushButtonJogxp);

        horizontalSpacer_9 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        splitter_7->addWidget(layoutWidget3);
        layoutWidget4 = new QWidget(splitter_7);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        horizontalLayout_31 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        horizontalLayout_31->setContentsMargins(0, 0, 0, 0);
        pushButtonJogzn = new QPushButton(layoutWidget4);
        pushButtonJogzn->setObjectName(QStringLiteral("pushButtonJogzn"));
        pushButtonJogzn->setFont(font2);
        pushButtonJogzn->setCheckable(false);

        horizontalLayout_31->addWidget(pushButtonJogzn);

        pushButtonOrigin = new QPushButton(layoutWidget4);
        pushButtonOrigin->setObjectName(QStringLiteral("pushButtonOrigin"));
        pushButtonOrigin->setFont(font);

        horizontalLayout_31->addWidget(pushButtonOrigin);

        pushButtonJogzp = new QPushButton(layoutWidget4);
        pushButtonJogzp->setObjectName(QStringLiteral("pushButtonJogzp"));
        pushButtonJogzp->setFont(font2);
        pushButtonJogzp->setCheckable(false);

        horizontalLayout_31->addWidget(pushButtonJogzp);

        splitter_7->addWidget(layoutWidget4);
        layoutWidget5 = new QWidget(splitter_7);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        horizontalLayout_32 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        horizontalLayout_32->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_7 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_32->addItem(horizontalSpacer_7);

        pushButtonJogxn = new QPushButton(layoutWidget5);
        pushButtonJogxn->setObjectName(QStringLiteral("pushButtonJogxn"));
        pushButtonJogxn->setFont(font2);
        pushButtonJogxn->setCheckable(false);

        horizontalLayout_32->addWidget(pushButtonJogxn);

        horizontalSpacer_6 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_32->addItem(horizontalSpacer_6);

        splitter_7->addWidget(layoutWidget5);
        pushButtonServoStop = new QPushButton(groupBox_4);
        pushButtonServoStop->setObjectName(QStringLiteral("pushButtonServoStop"));
        pushButtonServoStop->setGeometry(QRect(990, 60, 101, 91));
        pushButtonServoStop->setFont(font3);
        pushButtonLdvAutoFocus_2 = new QPushButton(groupBox_4);
        pushButtonLdvAutoFocus_2->setObjectName(QStringLiteral("pushButtonLdvAutoFocus_2"));
        pushButtonLdvAutoFocus_2->setGeometry(QRect(960, 170, 160, 21));
        pushButtonLdvAutoFocus_2->setFont(font);
        pushButtonLdvAutoFocus_2->setCheckable(false);
        pushButtonLdvAutoFocus_2->setChecked(false);
        groupBox_2 = new QGroupBox(SettingTab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 490, 219, 70));
        horizontalLayout_24 = new QHBoxLayout(groupBox_2);
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        pushButtonSaveSettings = new QPushButton(groupBox_2);
        pushButtonSaveSettings->setObjectName(QStringLiteral("pushButtonSaveSettings"));
        pushButtonSaveSettings->setFont(font);

        horizontalLayout_15->addWidget(pushButtonSaveSettings);

        pushButtonLoadSettings = new QPushButton(groupBox_2);
        pushButtonLoadSettings->setObjectName(QStringLiteral("pushButtonLoadSettings"));
        pushButtonLoadSettings->setFont(font);

        horizontalLayout_15->addWidget(pushButtonLoadSettings);


        horizontalLayout_24->addLayout(horizontalLayout_15);

        layoutWidget6 = new QWidget(SettingTab);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(150, 580, 661, 51));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        pushButtonInit = new QPushButton(layoutWidget6);
        pushButtonInit->setObjectName(QStringLiteral("pushButtonInit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonInit->sizePolicy().hasHeightForWidth());
        pushButtonInit->setSizePolicy(sizePolicy2);
        QFont font7;
        font7.setPointSize(10);
        font7.setBold(true);
        font7.setWeight(75);
        pushButtonInit->setFont(font7);

        horizontalLayout_16->addWidget(pushButtonInit);

        pushButtonDaqSet = new QPushButton(layoutWidget6);
        pushButtonDaqSet->setObjectName(QStringLiteral("pushButtonDaqSet"));
        sizePolicy2.setHeightForWidth(pushButtonDaqSet->sizePolicy().hasHeightForWidth());
        pushButtonDaqSet->setSizePolicy(sizePolicy2);
        pushButtonDaqSet->setFont(font7);

        horizontalLayout_16->addWidget(pushButtonDaqSet);

        pushButtonQuit = new QPushButton(layoutWidget6);
        pushButtonQuit->setObjectName(QStringLiteral("pushButtonQuit"));
        sizePolicy2.setHeightForWidth(pushButtonQuit->sizePolicy().hasHeightForWidth());
        pushButtonQuit->setSizePolicy(sizePolicy2);
        pushButtonQuit->setFont(font7);

        horizontalLayout_16->addWidget(pushButtonQuit);

        labelRefWarning = new QLabel(SettingTab);
        labelRefWarning->setObjectName(QStringLiteral("labelRefWarning"));
        labelRefWarning->setGeometry(QRect(1160, 110, 521, 31));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 127, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        QBrush brush2(QColor(255, 63, 63, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(127, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(170, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush5(QColor(255, 255, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        labelRefWarning->setPalette(palette);
        labelRefWarning->setFont(font7);
        layoutWidget7 = new QWidget(SettingTab);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(770, 510, 501, 31));
        horizontalLayout_23 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget7);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);
        label_10->setLayoutDirection(Qt::LeftToRight);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_23->addWidget(label_10);

        ldvSignalLevel = new QProgressBar(layoutWidget7);
        ldvSignalLevel->setObjectName(QStringLiteral("ldvSignalLevel"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ldvSignalLevel->sizePolicy().hasHeightForWidth());
        ldvSignalLevel->setSizePolicy(sizePolicy3);
        ldvSignalLevel->setMaximum(775);
        ldvSignalLevel->setValue(0);

        horizontalLayout_23->addWidget(ldvSignalLevel);

        pushButtonLdvAutoFocus = new QPushButton(layoutWidget7);
        pushButtonLdvAutoFocus->setObjectName(QStringLiteral("pushButtonLdvAutoFocus"));
        pushButtonLdvAutoFocus->setFont(font);
        pushButtonLdvAutoFocus->setCheckable(false);
        pushButtonLdvAutoFocus->setChecked(false);

        horizontalLayout_23->addWidget(pushButtonLdvAutoFocus);

        checkBoxRealTimeMedian = new QCheckBox(SettingTab);
        checkBoxRealTimeMedian->setObjectName(QStringLiteral("checkBoxRealTimeMedian"));
        checkBoxRealTimeMedian->setEnabled(true);
        checkBoxRealTimeMedian->setGeometry(QRect(150, 640, 501, 17));
        checkBoxRealTimeMedian->setFont(font7);
        checkBoxRealTimeMedian->setChecked(false);
        layoutWidget8 = new QWidget(SettingTab);
        layoutWidget8->setObjectName(QStringLiteral("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(250, 520, 471, 29));
        horizontalLayout_39 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_39->setSpacing(6);
        horizontalLayout_39->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_39->setObjectName(QStringLiteral("horizontalLayout_39"));
        horizontalLayout_39->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setSpacing(6);
        horizontalLayout_38->setObjectName(QStringLiteral("horizontalLayout_38"));
        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setSpacing(6);
        horizontalLayout_37->setObjectName(QStringLiteral("horizontalLayout_37"));
        labelScanHeight_2 = new QLabel(layoutWidget8);
        labelScanHeight_2->setObjectName(QStringLiteral("labelScanHeight_2"));
        labelScanHeight_2->setFont(font);

        horizontalLayout_37->addWidget(labelScanHeight_2);

        lineEditDaqVoltage = new QLineEdit(layoutWidget8);
        lineEditDaqVoltage->setObjectName(QStringLiteral("lineEditDaqVoltage"));
        sizePolicy1.setHeightForWidth(lineEditDaqVoltage->sizePolicy().hasHeightForWidth());
        lineEditDaqVoltage->setSizePolicy(sizePolicy1);
        lineEditDaqVoltage->setMaximumSize(QSize(70, 22));
        lineEditDaqVoltage->setFont(font);
        lineEditDaqVoltage->setMaxLength(4);
        lineEditDaqVoltage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_37->addWidget(lineEditDaqVoltage);


        horizontalLayout_38->addLayout(horizontalLayout_37);


        horizontalLayout_39->addLayout(horizontalLayout_38);

        pushButtonDaqConfig = new QPushButton(layoutWidget8);
        pushButtonDaqConfig->setObjectName(QStringLiteral("pushButtonDaqConfig"));
        pushButtonDaqConfig->setFont(font);

        horizontalLayout_39->addWidget(pushButtonDaqConfig);

        layoutWidget9 = new QWidget(SettingTab);
        layoutWidget9->setObjectName(QStringLiteral("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(900, 630, 211, 29));
        horizontalLayout_25 = new QHBoxLayout(layoutWidget9);
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        horizontalLayout_25->setContentsMargins(0, 0, 0, 0);
        labelScanInterval_4 = new QLabel(layoutWidget9);
        labelScanInterval_4->setObjectName(QStringLiteral("labelScanInterval_4"));
        labelScanInterval_4->setFont(font);

        horizontalLayout_25->addWidget(labelScanInterval_4);

        enumOsciChannel = new QComboBox(layoutWidget9);
        enumOsciChannel->setObjectName(QStringLiteral("enumOsciChannel"));
        enumOsciChannel->setFont(font);

        horizontalLayout_25->addWidget(enumOsciChannel);

        layoutWidget10 = new QWidget(SettingTab);
        layoutWidget10->setObjectName(QStringLiteral("layoutWidget10"));
        layoutWidget10->setGeometry(QRect(1150, 0, 254, 24));
        horizontalLayout_36 = new QHBoxLayout(layoutWidget10);
        horizontalLayout_36->setSpacing(6);
        horizontalLayout_36->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_36->setObjectName(QStringLiteral("horizontalLayout_36"));
        horizontalLayout_36->setContentsMargins(0, 0, 0, 0);
        labelTrigDelay = new QLabel(layoutWidget10);
        labelTrigDelay->setObjectName(QStringLiteral("labelTrigDelay"));
        labelTrigDelay->setFont(font);

        horizontalLayout_36->addWidget(labelTrigDelay);

        lineEditDaqTrigDelay = new QLineEdit(layoutWidget10);
        lineEditDaqTrigDelay->setObjectName(QStringLiteral("lineEditDaqTrigDelay"));
        sizePolicy1.setHeightForWidth(lineEditDaqTrigDelay->sizePolicy().hasHeightForWidth());
        lineEditDaqTrigDelay->setSizePolicy(sizePolicy1);
        lineEditDaqTrigDelay->setMaximumSize(QSize(70, 20));
        lineEditDaqTrigDelay->setFont(font);
        lineEditDaqTrigDelay->setToolTipDuration(1000);
#ifndef QT_NO_STATUSTIP
        lineEditDaqTrigDelay->setStatusTip(QStringLiteral("Height of scan area. Valid range: 50mm~500mm - Increment: 10mm"));
#endif // QT_NO_STATUSTIP
        lineEditDaqTrigDelay->setMaxLength(4);
        lineEditDaqTrigDelay->setFrame(true);
        lineEditDaqTrigDelay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDaqTrigDelay->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEditDaqTrigDelay->setClearButtonEnabled(false);

        horizontalLayout_36->addWidget(lineEditDaqTrigDelay);

        tabWidget->addTab(SettingTab, QString());
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        groupBox_2->raise();
        groupBox_1->raise();
        groupBoxScan->raise();
        progressBar->raise();
        widgetOscilloscope->raise();
        groupBox_4->raise();
        labelRefWarning->raise();
        checkBoxRealTimeMedian->raise();
        layoutWidget->raise();
        Subbandtab = new QWidget();
        Subbandtab->setObjectName(QStringLiteral("Subbandtab"));
        groupBox_3 = new QGroupBox(Subbandtab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(900, 10, 331, 62));
        horizontalLayout_40 = new QHBoxLayout(groupBox_3);
        horizontalLayout_40->setSpacing(6);
        horizontalLayout_40->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_40->setObjectName(QStringLiteral("horizontalLayout_40"));
        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setSpacing(6);
        horizontalLayout_41->setObjectName(QStringLiteral("horizontalLayout_41"));
        radioButtonSubband1 = new QRadioButton(groupBox_3);
        radioButtonSubband1->setObjectName(QStringLiteral("radioButtonSubband1"));
        radioButtonSubband1->setChecked(true);

        horizontalLayout_41->addWidget(radioButtonSubband1);

        radioButtonSubband2 = new QRadioButton(groupBox_3);
        radioButtonSubband2->setObjectName(QStringLiteral("radioButtonSubband2"));

        horizontalLayout_41->addWidget(radioButtonSubband2);

        radioButtonSubband3 = new QRadioButton(groupBox_3);
        radioButtonSubband3->setObjectName(QStringLiteral("radioButtonSubband3"));

        horizontalLayout_41->addWidget(radioButtonSubband3);


        horizontalLayout_40->addLayout(horizontalLayout_41);

        layoutWidget11 = new QWidget(Subbandtab);
        layoutWidget11->setObjectName(QStringLiteral("layoutWidget11"));
        layoutWidget11->setGeometry(QRect(170, 1, 584, 100));
        verticalLayout_18 = new QVBoxLayout(layoutWidget11);
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setContentsMargins(11, 11, 11, 11);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        enumPlaySpeedSubband = new QComboBox(layoutWidget11);
        enumPlaySpeedSubband->setObjectName(QStringLiteral("enumPlaySpeedSubband"));

        horizontalLayout_28->addWidget(enumPlaySpeedSubband);

        pushButtonPlayPauseSubband = new QPushButton(layoutWidget11);
        pushButtonPlayPauseSubband->setObjectName(QStringLiteral("pushButtonPlayPauseSubband"));
        pushButtonPlayPauseSubband->setCheckable(true);
        pushButtonPlayPauseSubband->setAutoDefault(false);

        horizontalLayout_28->addWidget(pushButtonPlayPauseSubband);

        horizontalSpacer_4 = new QSpacerItem(400, 66, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_4);


        verticalLayout_18->addLayout(horizontalLayout_28);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        horizontalSliderSubband = new QSlider(layoutWidget11);
        horizontalSliderSubband->setObjectName(QStringLiteral("horizontalSliderSubband"));
        horizontalSliderSubband->setValue(50);
        horizontalSliderSubband->setOrientation(Qt::Horizontal);

        horizontalLayout_29->addWidget(horizontalSliderSubband);

        labelFrameSubband = new QLabel(layoutWidget11);
        labelFrameSubband->setObjectName(QStringLiteral("labelFrameSubband"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(labelFrameSubband->sizePolicy().hasHeightForWidth());
        labelFrameSubband->setSizePolicy(sizePolicy4);
        labelFrameSubband->setFont(font2);
        labelFrameSubband->setAlignment(Qt::AlignCenter);

        horizontalLayout_29->addWidget(labelFrameSubband);


        verticalLayout_18->addLayout(horizontalLayout_29);

        dial_intensity_Subband = new QDial(Subbandtab);
        dial_intensity_Subband->setObjectName(QStringLiteral("dial_intensity_Subband"));
        dial_intensity_Subband->setGeometry(QRect(730, 0, 153, 69));
        dial_intensity_Subband->setMinimum(50);
        dial_intensity_Subband->setMaximum(25000);
        dial_intensity_Subband->setValue(50);
        dial_intensity_Subband->setWrapping(false);
        dial_intensity_Subband->setNotchTarget(25);
        dial_intensity_Subband->setNotchesVisible(true);
        scrollArea_2 = new QScrollArea(Subbandtab);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(10, 106, 1911, 991));
        scrollArea_2->setFrameShape(QFrame::NoFrame);
        scrollArea_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea_2->setWidgetResizable(false);
        widgetSubbandSpect = new QWidget();
        widgetSubbandSpect->setObjectName(QStringLiteral("widgetSubbandSpect"));
        widgetSubbandSpect->setGeometry(QRect(0, 0, 1121, 831));
        scrollArea_2->setWidget(widgetSubbandSpect);
        labelConfigSettingSubBand = new QLabel(Subbandtab);
        labelConfigSettingSubBand->setObjectName(QStringLiteral("labelConfigSettingSubBand"));
        labelConfigSettingSubBand->setGeometry(QRect(1270, 10, 411, 81));
        labelConfigSettingSubBand->setFont(font2);
        labelConfigSettingSubBand->setFrameShape(QFrame::NoFrame);
        pushButtonServoStop3 = new QPushButton(Subbandtab);
        pushButtonServoStop3->setObjectName(QStringLiteral("pushButtonServoStop3"));
        pushButtonServoStop3->setGeometry(QRect(20, 0, 101, 81));
        pushButtonServoStop3->setFont(font3);
        tabWidget->addTab(Subbandtab, QString());
        ResultTab = new QWidget();
        ResultTab->setObjectName(QStringLiteral("ResultTab"));
        widgetVtwam = new QWidget(ResultTab);
        widgetVtwam->setObjectName(QStringLiteral("widgetVtwam"));
        widgetVtwam->setGeometry(QRect(1730, 1010, 621, 491));
        scrollArea = new QScrollArea(ResultTab);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(140, 100, 1771, 661));
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
        widgetResultTime = new QWidget(ResultTab);
        widgetResultTime->setObjectName(QStringLiteral("widgetResultTime"));
        widgetResultTime->setGeometry(QRect(320, 770, 1721, 251));
        widgetResultControl = new QWidget(ResultTab);
        widgetResultControl->setObjectName(QStringLiteral("widgetResultControl"));
        widgetResultControl->setGeometry(QRect(140, -20, 751, 121));
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
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(horizontalSliderFrame->sizePolicy().hasHeightForWidth());
        horizontalSliderFrame->setSizePolicy(sizePolicy5);
        horizontalSliderFrame->setValue(50);
        horizontalSliderFrame->setOrientation(Qt::Horizontal);

        horizontalLayout_26->addWidget(horizontalSliderFrame);

        labelFrame = new QLabel(groupBoxResultControl);
        labelFrame->setObjectName(QStringLiteral("labelFrame"));
        sizePolicy4.setHeightForWidth(labelFrame->sizePolicy().hasHeightForWidth());
        labelFrame->setSizePolicy(sizePolicy4);
        labelFrame->setFont(font2);
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

        labelVtwamInfo = new QLabel(ResultTab);
        labelVtwamInfo->setObjectName(QStringLiteral("labelVtwamInfo"));
        labelVtwamInfo->setGeometry(QRect(1030, 70, 851, 31));
        labelVtwamInfo->setFont(font2);
        labelVtwamRangeTitle = new QLabel(ResultTab);
        labelVtwamRangeTitle->setObjectName(QStringLiteral("labelVtwamRangeTitle"));
        labelVtwamRangeTitle->setGeometry(QRect(910, 60, 141, 31));
        QFont font8;
        font8.setPointSize(12);
        font8.setBold(false);
        font8.setWeight(50);
        labelVtwamRangeTitle->setFont(font8);
        pushButtonServoStop2 = new QPushButton(ResultTab);
        pushButtonServoStop2->setObjectName(QStringLiteral("pushButtonServoStop2"));
        pushButtonServoStop2->setGeometry(QRect(20, 0, 101, 61));
        QSizePolicy sizePolicy6(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pushButtonServoStop2->sizePolicy().hasHeightForWidth());
        pushButtonServoStop2->setSizePolicy(sizePolicy6);
        pushButtonServoStop2->setFont(font3);
        labelCurrentDataSpec = new QLabel(ResultTab);
        labelCurrentDataSpec->setObjectName(QStringLiteral("labelCurrentDataSpec"));
        labelCurrentDataSpec->setGeometry(QRect(910, 10, 1011, 41));
        QFont font9;
        font9.setPointSize(11);
        labelCurrentDataSpec->setFont(font9);
        groupBoxFilter = new QGroupBox(ResultTab);
        groupBoxFilter->setObjectName(QStringLiteral("groupBoxFilter"));
        groupBoxFilter->setGeometry(QRect(2, 71, 128, 471));
        groupBoxFilter->setToolTipDuration(5000);
        groupBoxFilter->setCheckable(true);
        verticalLayout_26 = new QVBoxLayout(groupBoxFilter);
        verticalLayout_26->setSpacing(6);
        verticalLayout_26->setContentsMargins(11, 11, 11, 11);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        verticalLayout_25 = new QVBoxLayout();
        verticalLayout_25->setSpacing(6);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        groupBoxFilterStep1 = new QGroupBox(groupBoxFilter);
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

        groupBoxFilterStep2 = new QGroupBox(groupBoxFilter);
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

        checkBoxBoostSpeed = new QCheckBox(groupBoxFilter);
        checkBoxBoostSpeed->setObjectName(QStringLiteral("checkBoxBoostSpeed"));
        checkBoxBoostSpeed->setFont(font3);
        checkBoxBoostSpeed->setChecked(true);

        verticalLayout_25->addWidget(checkBoxBoostSpeed);

        pushButtonProcessFilter = new QPushButton(groupBoxFilter);
        pushButtonProcessFilter->setObjectName(QStringLiteral("pushButtonProcessFilter"));

        verticalLayout_25->addWidget(pushButtonProcessFilter);


        verticalLayout_26->addLayout(verticalLayout_25);

        groupBoxVtwam = new QGroupBox(ResultTab);
        groupBoxVtwam->setObjectName(QStringLiteral("groupBoxVtwam"));
        groupBoxVtwam->setGeometry(QRect(2, 548, 129, 247));
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

        pushButtonVtwamAddRange = new QPushButton(groupBoxVtwam);
        pushButtonVtwamAddRange->setObjectName(QStringLiteral("pushButtonVtwamAddRange"));

        verticalLayout_10->addWidget(pushButtonVtwamAddRange);

        pushButtonVtwamClearRanges = new QPushButton(groupBoxVtwam);
        pushButtonVtwamClearRanges->setObjectName(QStringLiteral("pushButtonVtwamClearRanges"));

        verticalLayout_10->addWidget(pushButtonVtwamClearRanges);

        pushButtonProcessVtwam = new QPushButton(groupBoxVtwam);
        pushButtonProcessVtwam->setObjectName(QStringLiteral("pushButtonProcessVtwam"));

        verticalLayout_10->addWidget(pushButtonProcessVtwam);


        verticalLayout_12->addLayout(verticalLayout_10);

        pushButtonCaptureVtwam = new QPushButton(groupBoxVtwam);
        pushButtonCaptureVtwam->setObjectName(QStringLiteral("pushButtonCaptureVtwam"));

        verticalLayout_12->addWidget(pushButtonCaptureVtwam);

        layoutWidget12 = new QWidget(ResultTab);
        layoutWidget12->setObjectName(QStringLiteral("layoutWidget12"));
        layoutWidget12->setGeometry(QRect(2, 800, 131, 188));
        verticalLayout_19 = new QVBoxLayout(layoutWidget12);
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setContentsMargins(11, 11, 11, 11);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        verticalLayout_19->setContentsMargins(0, 0, 0, 0);
        groupBox_5 = new QGroupBox(layoutWidget12);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_14 = new QVBoxLayout(groupBox_5);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        pushButtonProcessXCor = new QPushButton(groupBox_5);
        pushButtonProcessXCor->setObjectName(QStringLiteral("pushButtonProcessXCor"));

        verticalLayout_6->addWidget(pushButtonProcessXCor);

        pushButtonCaptureXcor = new QPushButton(groupBox_5);
        pushButtonCaptureXcor->setObjectName(QStringLiteral("pushButtonCaptureXcor"));

        verticalLayout_6->addWidget(pushButtonCaptureXcor);


        verticalLayout_14->addLayout(verticalLayout_6);


        verticalLayout_19->addWidget(groupBox_5);

        groupBox = new QGroupBox(layoutWidget12);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_17 = new QVBoxLayout(groupBox);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        pushButtonLoadData = new QPushButton(groupBox);
        pushButtonLoadData->setObjectName(QStringLiteral("pushButtonLoadData"));

        verticalLayout_17->addWidget(pushButtonLoadData);

        pushButtonSaveData = new QPushButton(groupBox);
        pushButtonSaveData->setObjectName(QStringLiteral("pushButtonSaveData"));

        verticalLayout_17->addWidget(pushButtonSaveData);


        verticalLayout_19->addWidget(groupBox);

        tabWidget->addTab(ResultTab, QString());
        groupBoxFilter->raise();
        groupBoxVtwam->raise();
        widgetResultControl->raise();
        layoutWidget->raise();
        widgetVtwam->raise();
        scrollArea->raise();
        widgetResultTime->raise();
        labelVtwamInfo->raise();
        labelVtwamRangeTitle->raise();
        pushButtonServoStop2->raise();
        labelCurrentDataSpec->raise();
        layoutWidget13 = new QWidget(centralWidget);
        layoutWidget13->setObjectName(QStringLiteral("layoutWidget13"));
        layoutWidget13->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_24 = new QVBoxLayout(layoutWidget13);
        verticalLayout_24->setSpacing(6);
        verticalLayout_24->setContentsMargins(11, 11, 11, 11);
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        verticalLayout_24->setContentsMargins(0, 0, 0, 0);
        layoutWidget14 = new QWidget(centralWidget);
        layoutWidget14->setObjectName(QStringLiteral("layoutWidget14"));
        layoutWidget14->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_211 = new QVBoxLayout(layoutWidget14);
        verticalLayout_211->setSpacing(6);
        verticalLayout_211->setContentsMargins(11, 11, 11, 11);
        verticalLayout_211->setObjectName(QStringLiteral("verticalLayout_211"));
        verticalLayout_211->setContentsMargins(0, 0, 0, 0);
        layoutWidget15 = new QWidget(centralWidget);
        layoutWidget15->setObjectName(QStringLiteral("layoutWidget15"));
        layoutWidget15->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget15);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        layoutWidget16 = new QWidget(centralWidget);
        layoutWidget16->setObjectName(QStringLiteral("layoutWidget16"));
        layoutWidget16->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_19 = new QHBoxLayout(layoutWidget16);
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        layoutWidget17 = new QWidget(centralWidget);
        layoutWidget17->setObjectName(QStringLiteral("layoutWidget17"));
        layoutWidget17->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_27 = new QVBoxLayout(layoutWidget17);
        verticalLayout_27->setSpacing(6);
        verticalLayout_27->setContentsMargins(11, 11, 11, 11);
        verticalLayout_27->setObjectName(QStringLiteral("verticalLayout_27"));
        verticalLayout_27->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1940, 20));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setContextMenuPolicy(Qt::DefaultContextMenu);
        statusBar->setToolTipDuration(10);
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        QWidget::setTabOrder(pushButtonInit, pushButtonDaqSet);
        QWidget::setTabOrder(pushButtonDaqSet, lineEditScanWidth);
        QWidget::setTabOrder(lineEditScanWidth, enumCurrent);
        QWidget::setTabOrder(enumCurrent, pushButtonLaserConfigPrfCurr);
        QWidget::setTabOrder(pushButtonLaserConfigPrfCurr, pushButtonOrigin);
        QWidget::setTabOrder(pushButtonOrigin, pushButtonServoStop);
        QWidget::setTabOrder(pushButtonServoStop, pushButtonSetpos);
        QWidget::setTabOrder(pushButtonSetpos, pushButtonGetpos);
        QWidget::setTabOrder(pushButtonGetpos, enumPlaySpeed);
        QWidget::setTabOrder(enumPlaySpeed, pushButtonPlayPause);
        QWidget::setTabOrder(pushButtonPlayPause, pushButtonCapture);
        QWidget::setTabOrder(pushButtonCapture, pushButtonSaveMovie);
        QWidget::setTabOrder(pushButtonSaveMovie, dial_intensity);
        QWidget::setTabOrder(dial_intensity, dial_intensity_2);
        QWidget::setTabOrder(dial_intensity_2, pushButtonPlayPauseSubband);
        QWidget::setTabOrder(pushButtonPlayPauseSubband, horizontalSliderSubband);
        QWidget::setTabOrder(horizontalSliderSubband, dial_intensity_Subband);
        QWidget::setTabOrder(dial_intensity_Subband, scrollArea_2);
        QWidget::setTabOrder(scrollArea_2, scrollArea);
        QWidget::setTabOrder(scrollArea, tabWidget);
        QWidget::setTabOrder(tabWidget, groupBoxFilter);
        QWidget::setTabOrder(groupBoxFilter, radioButtonSubband1);
        QWidget::setTabOrder(radioButtonSubband1, horizontalSliderFrame);
        QWidget::setTabOrder(horizontalSliderFrame, enumPlaySpeedSubband);
        QWidget::setTabOrder(enumPlaySpeedSubband, groupBoxFilterStep1);
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
        QWidget::setTabOrder(pushButtonProcessVtwam, pushButtonLoadData);
        QWidget::setTabOrder(pushButtonLoadData, pushButtonSaveData);

        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionBand_Divider_Scenario);
        menuHelp->addAction(actionPulse_Energy_Table);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionSave);

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
        actionBand_Divider_Scenario->setText(QApplication::translate("MainWindow", "Band Divider Scenario", 0));
        groupBox_1->setTitle(QApplication::translate("MainWindow", "Inspection settings", 0));
        checkBoxEnableMultiBand->setText(QApplication::translate("MainWindow", "Enable Multiband Decomposition", 0));
        labelScanInterval_3->setText(QApplication::translate("MainWindow", "Band Selection:", 0));
#ifndef QT_NO_STATUSTIP
        pushButtonFilterConfig->setStatusTip(QApplication::translate("MainWindow", "Configure the laser. ", 0));
#endif // QT_NO_STATUSTIP
        pushButtonFilterConfig->setText(QApplication::translate("MainWindow", "Configure", 0));
        labelConfigSetting->setText(QString());
        groupBoxScan->setTitle(QApplication::translate("MainWindow", "Scan", 0));
        labelScanPars->setText(QApplication::translate("MainWindow", "xnbvxcvn", 0));
        labelScanRadius->setText(QApplication::translate("MainWindow", "Radius (mm):", 0));
#ifndef QT_NO_TOOLTIP
        lineEditScanRadius->setToolTip(QApplication::translate("MainWindow", "Valid range: 50mm~700mm - Increment: 10mm", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEditScanRadius->setStatusTip(QApplication::translate("MainWindow", "Width of scan area. Valid range: 50mm~500mm - Increment: 10mm", 0));
#endif // QT_NO_STATUSTIP
        lineEditScanRadius->setText(QApplication::translate("MainWindow", "200", 0));
        labelScanHeight->setText(QApplication::translate("MainWindow", "Width(mm):", 0));
#ifndef QT_NO_TOOLTIP
        lineEditScanWidth->setToolTip(QApplication::translate("MainWindow", "Valid range: 50mm~700mm - Increment: 10mm", 0));
#endif // QT_NO_TOOLTIP
        labelScanTrigPerRev->setText(QApplication::translate("MainWindow", "Trigs Per Rev:", 0));
        labelScanSpeedDegPerSec->setText(QApplication::translate("MainWindow", "Speed (deg/sec):", 0));
#ifndef QT_NO_TOOLTIP
        labelScanInterval_2->setToolTip(QApplication::translate("MainWindow", "Total number of scans to be done for the inspection.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        labelScanInterval_2->setStatusTip(QApplication::translate("MainWindow", "Total number of scans to be done for the inspection.", 0));
#endif // QT_NO_STATUSTIP
        labelScanInterval_2->setText(QApplication::translate("MainWindow", "Total Scans:", 0));
#ifndef QT_NO_TOOLTIP
        enumTotalScans->setToolTip(QApplication::translate("MainWindow", "Total number of scans to be done for the inspection.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        enumTotalScans->setStatusTip(QApplication::translate("MainWindow", "Total number of scans to be done for the inspection.", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        checkBox_useCurrentResults->setStatusTip(QApplication::translate("MainWindow", "Current result will be combined with the results of the next inspection.", 0));
#endif // QT_NO_STATUSTIP
        checkBox_useCurrentResults->setText(QApplication::translate("MainWindow", "Use current result", 0));
        label_17->setText(QApplication::translate("MainWindow", "Current(A):", 0));
#ifndef QT_NO_STATUSTIP
        pushButtonLaserConfigPrfCurr->setStatusTip(QApplication::translate("MainWindow", "Configure the laser. ", 0));
#endif // QT_NO_STATUSTIP
        pushButtonLaserConfigPrfCurr->setText(QApplication::translate("MainWindow", "Configure", 0));
#ifndef QT_NO_STATUSTIP
        pushButtonLaserControl->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        pushButtonLaserControl->setText(QApplication::translate("MainWindow", "Activate", 0));
        labelLaserStatus->setText(QApplication::translate("MainWindow", "Laser Beam: OFF", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Navigator", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Rotational", 0));
        pushButtonSpinClockWise->setText(QApplication::translate("MainWindow", "\342\206\273", 0));
        pushButtonOriginRot->setText(QApplication::translate("MainWindow", "Origin", 0));
        pushButtonSpinAClockWise->setText(QApplication::translate("MainWindow", "\342\206\272", 0));
        lineEditRotPos->setText(QApplication::translate("MainWindow", "0.00", 0));
        pushButtonRotSetpos->setText(QApplication::translate("MainWindow", "Set", 0));
        pushButtonRotGetPos->setText(QApplication::translate("MainWindow", "Get", 0));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Linear", 0));
        label_5->setText(QApplication::translate("MainWindow", "X-axis (mm)", 0));
        pushButtonSetpos->setText(QApplication::translate("MainWindow", "Set", 0));
        lineEditZPos->setText(QApplication::translate("MainWindow", "0.00", 0));
        lineEditXpos->setText(QApplication::translate("MainWindow", "0.00", 0));
        label_6->setText(QApplication::translate("MainWindow", "Z-axis (mm)", 0));
        pushButtonGetpos->setText(QApplication::translate("MainWindow", "Get", 0));
        pushButtonJogxp->setText(QApplication::translate("MainWindow", "^", 0));
        pushButtonJogzn->setText(QApplication::translate("MainWindow", "<", 0));
        pushButtonOrigin->setText(QApplication::translate("MainWindow", "Origin", 0));
        pushButtonJogzp->setText(QApplication::translate("MainWindow", ">", 0));
        pushButtonJogxn->setText(QApplication::translate("MainWindow", "v", 0));
        pushButtonServoStop->setText(QApplication::translate("MainWindow", "STOP", 0));
#ifndef QT_NO_STATUSTIP
        pushButtonLdvAutoFocus_2->setStatusTip(QApplication::translate("MainWindow", "Auto focus the laser beam of ldv.", 0));
#endif // QT_NO_STATUSTIP
        pushButtonLdvAutoFocus_2->setText(QApplication::translate("MainWindow", "Mark Scan Area", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Scan Parameters", 0));
#ifndef QT_NO_STATUSTIP
        pushButtonSaveSettings->setStatusTip(QApplication::translate("MainWindow", "Save the setting to file. (C:\\FF_PE_UPI_Data\\Setting)", 0));
#endif // QT_NO_STATUSTIP
        pushButtonSaveSettings->setText(QApplication::translate("MainWindow", "Save", 0));
#ifndef QT_NO_STATUSTIP
        pushButtonLoadSettings->setStatusTip(QApplication::translate("MainWindow", "Load the setting from file.", 0));
#endif // QT_NO_STATUSTIP
        pushButtonLoadSettings->setText(QApplication::translate("MainWindow", "Load", 0));
        pushButtonInit->setText(QApplication::translate("MainWindow", "Intialize", 0));
        pushButtonDaqSet->setText(QApplication::translate("MainWindow", "Start", 0));
        pushButtonQuit->setText(QApplication::translate("MainWindow", "Exit", 0));
        labelRefWarning->setText(QApplication::translate("MainWindow", "Refer to laser pulse energy table in Help menu for setting the laser current.", 0));
        label_10->setText(QApplication::translate("MainWindow", "LDV Signal Level:", 0));
#ifndef QT_NO_STATUSTIP
        pushButtonLdvAutoFocus->setStatusTip(QApplication::translate("MainWindow", "Auto focus the laser beam of ldv.", 0));
#endif // QT_NO_STATUSTIP
        pushButtonLdvAutoFocus->setText(QApplication::translate("MainWindow", "Auto Focus", 0));
        checkBoxRealTimeMedian->setText(QApplication::translate("MainWindow", "Apply MEDIAN filter in real time. (JUST FOR DEBUGGING)!!!!", 0));
        labelScanHeight_2->setText(QApplication::translate("MainWindow", "Voltage (mV):", 0));
#ifndef QT_NO_TOOLTIP
        lineEditDaqVoltage->setToolTip(QApplication::translate("MainWindow", "Valid range: 50mm~700mm - Increment: 10mm", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEditDaqVoltage->setStatusTip(QApplication::translate("MainWindow", "Width of scan area. Valid range: 50mm~500mm - Increment: 10mm", 0));
#endif // QT_NO_STATUSTIP
        lineEditDaqVoltage->setText(QApplication::translate("MainWindow", "500", 0));
#ifndef QT_NO_STATUSTIP
        pushButtonDaqConfig->setStatusTip(QApplication::translate("MainWindow", "Save the setting to file. (C:\\FF_PE_UPI_Data\\Setting)", 0));
#endif // QT_NO_STATUSTIP
        pushButtonDaqConfig->setText(QApplication::translate("MainWindow", "Config", 0));
        labelScanInterval_4->setText(QApplication::translate("MainWindow", "Osci Channel:", 0));
        labelTrigDelay->setText(QApplication::translate("MainWindow", "TriggerDelay (samples): ", 0));
#ifndef QT_NO_TOOLTIP
        lineEditDaqTrigDelay->setToolTip(QApplication::translate("MainWindow", "Valid range: 50mm~700mm - Increment: 10mm", 0));
#endif // QT_NO_TOOLTIP
        lineEditDaqTrigDelay->setText(QApplication::translate("MainWindow", "864", 0));
        tabWidget->setTabText(tabWidget->indexOf(SettingTab), QApplication::translate("MainWindow", "Settings", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Subband selection", 0));
        radioButtonSubband1->setText(QApplication::translate("MainWindow", "Sub-band 1", 0));
        radioButtonSubband2->setText(QApplication::translate("MainWindow", "Sub-band 2", 0));
        radioButtonSubband3->setText(QApplication::translate("MainWindow", "Sub-band 3", 0));
#ifndef QT_NO_STATUSTIP
        pushButtonPlayPauseSubband->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        pushButtonPlayPauseSubband->setText(QApplication::translate("MainWindow", "Play", 0));
#ifndef QT_NO_STATUSTIP
        labelFrameSubband->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        labelFrameSubband->setText(QApplication::translate("MainWindow", "10", 0));
#ifndef QT_NO_STATUSTIP
        dial_intensity_Subband->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        labelConfigSettingSubBand->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonServoStop3->setToolTip(QApplication::translate("MainWindow", "Emergency Stop during scan.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonServoStop3->setStatusTip(QApplication::translate("MainWindow", "Emergency Stop during scan.", 0));
#endif // QT_NO_STATUSTIP
        pushButtonServoStop3->setText(QApplication::translate("MainWindow", "STOP", 0));
        tabWidget->setTabText(tabWidget->indexOf(Subbandtab), QApplication::translate("MainWindow", "Sub-band decomposition", 0));
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
        labelFrame->setText(QApplication::translate("MainWindow", "10", 0));
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
        labelVtwamInfo->setText(QString());
        labelVtwamRangeTitle->setText(QApplication::translate("MainWindow", "VTWAM Ranges:", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonServoStop2->setToolTip(QApplication::translate("MainWindow", "Emergency Stop during scan.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonServoStop2->setStatusTip(QApplication::translate("MainWindow", "Emergency Stop during scan.", 0));
#endif // QT_NO_STATUSTIP
        pushButtonServoStop2->setText(QApplication::translate("MainWindow", "STOP", 0));
        labelCurrentDataSpec->setText(QString());
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
        pushButtonVtwamAddRange->setToolTip(QApplication::translate("MainWindow", "Start VTWAM processing.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonVtwamAddRange->setStatusTip(QApplication::translate("MainWindow", "Start VTWAM Processing", 0));
#endif // QT_NO_STATUSTIP
        pushButtonVtwamAddRange->setText(QApplication::translate("MainWindow", "Add Range", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonVtwamClearRanges->setToolTip(QApplication::translate("MainWindow", "Start VTWAM processing.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonVtwamClearRanges->setStatusTip(QApplication::translate("MainWindow", "Start VTWAM Processing", 0));
#endif // QT_NO_STATUSTIP
        pushButtonVtwamClearRanges->setText(QApplication::translate("MainWindow", "Clear Ranges", 0));
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
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Cross Correlation", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonProcessXCor->setToolTip(QApplication::translate("MainWindow", "Start Cross-Correlation processing.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonProcessXCor->setStatusTip(QApplication::translate("MainWindow", "Start VTWAM Processing", 0));
#endif // QT_NO_STATUSTIP
        pushButtonProcessXCor->setText(QApplication::translate("MainWindow", "Process", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonCaptureXcor->setToolTip(QApplication::translate("MainWindow", "Save Cross-Corelation result as an image in c:\\FF_PE_UPI_Data\\ScreenShots.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonCaptureXcor->setStatusTip(QApplication::translate("MainWindow", "Save VTWAM result as an image in c:\\FF_PE_UPI_Data\\ScreenShots.", 0));
#endif // QT_NO_STATUSTIP
        pushButtonCaptureXcor->setText(QApplication::translate("MainWindow", "Save Screenshot", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Data", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonLoadData->setToolTip(QApplication::translate("MainWindow", "Load the previously saved data by selecting its folder.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonLoadData->setStatusTip(QApplication::translate("MainWindow", "Load the previously saved data by selecting its folder.", 0));
#endif // QT_NO_STATUSTIP
        pushButtonLoadData->setText(QApplication::translate("MainWindow", "Load Data", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonSaveData->setToolTip(QApplication::translate("MainWindow", "Save the current UWPI data in C:FF_PE_UPI_DataData.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonSaveData->setStatusTip(QApplication::translate("MainWindow", "Save the current UWPI data in C:\\FF_PE_UPI_Data\\Data.", 0));
#endif // QT_NO_STATUSTIP
        pushButtonSaveData->setText(QApplication::translate("MainWindow", "Save Data", 0));
        tabWidget->setTabText(tabWidget->indexOf(ResultTab), QApplication::translate("MainWindow", "Results", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
