#-------------------------------------------------
#
# Project created by QtCreator 2016-07-11T12:11:57
#
#-------------------------------------------------

DEFINES += MAXSAMPLESPERPOINT=2000\ #keep samples point in power of 2 to keep the DMA notification aligned
        += SPECTBASESIZE=400\
        += STAGESETPOSMAXTRIALS=10\
        += ACTUALSYSTEM

CONFIG  += qwt

LIBS += vfw32.lib Gdi32.lib User32.lib

QT       += \
            core gui \
            network widgets\
            winextras\
            serialport\
            axcontainer



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SFM_2-Axis_ver6
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dataProcessor.cpp \
    plot.cpp \
    spectrogram.cpp \
    dialogenlarge.cpp \
    pnacontroller.cpp \
    stagecontroller.cpp


HEADERS  += mainwindow.h \
    structDef.h \
    dataProcessor.h \
    plot.h \
    spectrogram.h \
    dialogenlarge.h \
    pnacontroller.h \
    stagecontroller.h


FORMS    += mainwindow.ui \
    dialogenlarge.ui

RESOURCES += \
    MyRes.qrc

DISTFILES += \
    Include/Pmac.def

