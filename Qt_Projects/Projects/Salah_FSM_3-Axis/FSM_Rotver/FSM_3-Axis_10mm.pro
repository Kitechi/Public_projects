
#-------------------------------------------------
#
# Project created by QtCreator 2016-07-11T12:11:57
#
#-------------------------------------------------

DEFINES += MAXSAMPLESPERPOINT=2000\ #keep samples point in power of 2 to keep the DMA notification aligned
        += SPECTBASESIZE=400\
        += STAGESETPOSMAXTRIALS=10\
        += PULSEWIDTH=150\
        += ACTUALSYSTEM

CONFIG  += qwt

LIBS += vfw32.lib Gdi32.lib User32.lib

QT       += \
            core gui \
            network widgets\
            winextras\
            serialport\
            axcontainer


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = FSM_3-Axis_10mm
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dataProcessor.cpp \
    plot.cpp \
    spectrogram.cpp \
    dialogenlarge.cpp \
    pnacontroller.cpp \
    hstageController.cpp \
    vstageController.cpp \
    stagecontroller.cpp \
    rotStageController.cpp \
    QTelnet.cpp \
    qcustomplot.cpp


HEADERS  += mainwindow.h \
    structDef.h \
    dataProcessor.h \
    plot.h \
    spectrogram.h \
    dialogenlarge.h \
    pnacontroller.h \
    hstageController.h \
    vstageController.h \
    stagecontroller.h \
    rotStageController.h \
    QTelnet.h \
    qcustomplot.h


FORMS    += mainwindow.ui \
    dialogenlarge.ui

RESOURCES += \
    MyRes.qrc

DISTFILES += \
    Include/Pmac.def
