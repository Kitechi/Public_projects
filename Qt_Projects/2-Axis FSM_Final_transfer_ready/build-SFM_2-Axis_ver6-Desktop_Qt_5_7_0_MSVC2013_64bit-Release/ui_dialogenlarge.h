/********************************************************************************
** Form generated from reading UI file 'dialogenlarge.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGENLARGE_H
#define UI_DIALOGENLARGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogEnlarge
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_5;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_3;
    QSlider *horizontalSliderEn;
    QLabel *label_2;

    void setupUi(QDialog *DialogEnlarge)
    {
        if (DialogEnlarge->objectName().isEmpty())
            DialogEnlarge->setObjectName(QStringLiteral("DialogEnlarge"));
        DialogEnlarge->resize(1920, 1000);
        DialogEnlarge->setSizeGripEnabled(false);
        scrollArea = new QScrollArea(DialogEnlarge);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 120, 1900, 880));
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1089, 459));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_5 = new QLabel(DialogEnlarge);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1170, 20, 41, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);
        layoutWidget = new QWidget(DialogEnlarge);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(890, 30, 501, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font1;
        font1.setPointSize(12);
        label_4->setFont(font1);

        horizontalLayout_2->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);

        horizontalLayout->addWidget(label_3);

        horizontalSliderEn = new QSlider(layoutWidget);
        horizontalSliderEn->setObjectName(QStringLiteral("horizontalSliderEn"));
        horizontalSliderEn->setMinimum(-3);
        horizontalSliderEn->setMaximum(3);
        horizontalSliderEn->setPageStep(1);
        horizontalSliderEn->setValue(-3);
        horizontalSliderEn->setOrientation(Qt::Horizontal);
        horizontalSliderEn->setTickPosition(QSlider::TicksBothSides);
        horizontalSliderEn->setTickInterval(1);

        horizontalLayout->addWidget(horizontalSliderEn);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        label_2->setFont(font3);

        horizontalLayout->addWidget(label_2);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(DialogEnlarge);

        QMetaObject::connectSlotsByName(DialogEnlarge);
    } // setupUi

    void retranslateUi(QDialog *DialogEnlarge)
    {
        DialogEnlarge->setWindowTitle(QApplication::translate("DialogEnlarge", "Enalrged UWPI Results", 0));
        label_5->setText(QApplication::translate("DialogEnlarge", "Actual", 0));
        label_4->setText(QApplication::translate("DialogEnlarge", "Result Size:", 0));
        label->setText(QString());
        label_3->setText(QApplication::translate("DialogEnlarge", "-", 0));
        label_2->setText(QApplication::translate("DialogEnlarge", "+", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogEnlarge: public Ui_DialogEnlarge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGENLARGE_H
