/****************************************************************************
** Meta object code from reading C++ file 'dataProcessor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FF_PE_UPI_50S_MultiBand/dataProcessor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataProcessor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_coreProcessor_t {
    QByteArrayData data[15];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_coreProcessor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_coreProcessor_t qt_meta_stringdata_coreProcessor = {
    {
QT_MOC_LITERAL(0, 0, 13), // "coreProcessor"
QT_MOC_LITERAL(1, 14, 14), // "updateProgress"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "curFrame"
QT_MOC_LITERAL(4, 39, 12), // "FilterRadius"
QT_MOC_LITERAL(5, 52, 10), // "filterType"
QT_MOC_LITERAL(6, 63, 8), // "finished"
QT_MOC_LITERAL(7, 72, 7), // "process"
QT_MOC_LITERAL(8, 80, 12), // "processVtwam"
QT_MOC_LITERAL(9, 93, 11), // "processXCor"
QT_MOC_LITERAL(10, 105, 10), // "processIIR"
QT_MOC_LITERAL(11, 116, 15), // "processParallel"
QT_MOC_LITERAL(12, 132, 23), // "updateRowColNumAcquired"
QT_MOC_LITERAL(13, 156, 16), // "wvfrmAcquiredArg"
QT_MOC_LITERAL(14, 173, 14) // "setAbortThread"

    },
    "coreProcessor\0updateProgress\0\0curFrame\0"
    "FilterRadius\0filterType\0finished\0"
    "process\0processVtwam\0processXCor\0"
    "processIIR\0processParallel\0"
    "updateRowColNumAcquired\0wvfrmAcquiredArg\0"
    "setAbortThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_coreProcessor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x06 /* Public */,
       6,    0,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   67,    2, 0x0a /* Public */,
       8,    0,   68,    2, 0x0a /* Public */,
       9,    0,   69,    2, 0x0a /* Public */,
      10,    0,   70,    2, 0x0a /* Public */,
      11,    0,   71,    2, 0x0a /* Public */,
      12,    1,   72,    2, 0x0a /* Public */,
      14,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Short, QMetaType::Short,    3,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

       0        // eod
};

void coreProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        coreProcessor *_t = static_cast<coreProcessor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3]))); break;
        case 1: _t->finished(); break;
        case 2: _t->process(); break;
        case 3: _t->processVtwam(); break;
        case 4: _t->processXCor(); break;
        case 5: _t->processIIR(); break;
        case 6: _t->processParallel(); break;
        case 7: _t->updateRowColNumAcquired((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setAbortThread(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (coreProcessor::*_t)(int , short , short );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&coreProcessor::updateProgress)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (coreProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&coreProcessor::finished)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject coreProcessor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_coreProcessor.data,
      qt_meta_data_coreProcessor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *coreProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *coreProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_coreProcessor.stringdata0))
        return static_cast<void*>(const_cast< coreProcessor*>(this));
    return QObject::qt_metacast(_clname);
}

int coreProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void coreProcessor::updateProgress(int _t1, short _t2, short _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void coreProcessor::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
struct qt_meta_stringdata_dataProcessor_t {
    QByteArrayData data[58];
    char stringdata0[871];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dataProcessor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dataProcessor_t qt_meta_stringdata_dataProcessor = {
    {
QT_MOC_LITERAL(0, 0, 13), // "dataProcessor"
QT_MOC_LITERAL(1, 14, 37), // "updateProgressBar_dataProcess..."
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 10), // "Percentage"
QT_MOC_LITERAL(4, 64, 35), // "updateStatusBar_dataProcessor..."
QT_MOC_LITERAL(5, 100, 9), // "StatusTip"
QT_MOC_LITERAL(6, 110, 14), // "updateOsciPlot"
QT_MOC_LITERAL(7, 125, 7), // "double*"
QT_MOC_LITERAL(8, 133, 10), // "WfmPointer"
QT_MOC_LITERAL(9, 144, 20), // "updateResultTimePlot"
QT_MOC_LITERAL(10, 165, 6), // "short*"
QT_MOC_LITERAL(11, 172, 4), // "y_pt"
QT_MOC_LITERAL(12, 177, 5), // "title"
QT_MOC_LITERAL(13, 183, 27), // "updateRowColNumAcquired_sig"
QT_MOC_LITERAL(14, 211, 15), // "abortThread_sig"
QT_MOC_LITERAL(15, 227, 12), // "setStagePosX"
QT_MOC_LITERAL(16, 240, 12), // "setStagePosZ"
QT_MOC_LITERAL(17, 253, 15), // "wfmCopyDone_sig"
QT_MOC_LITERAL(18, 269, 22), // "newWfmCopyToArray_slot"
QT_MOC_LITERAL(19, 292, 6), // "wfmPtr"
QT_MOC_LITERAL(20, 299, 14), // "waveformNumber"
QT_MOC_LITERAL(21, 314, 11), // "setframeNum"
QT_MOC_LITERAL(22, 326, 12), // "frameNum_arg"
QT_MOC_LITERAL(23, 339, 19), // "selectDisplayBuffer"
QT_MOC_LITERAL(24, 359, 8), // "Filtered"
QT_MOC_LITERAL(25, 368, 32), // "postProcessingFilteringRequested"
QT_MOC_LITERAL(26, 401, 28), // "postProcessingVtwamRequested"
QT_MOC_LITERAL(27, 430, 13), // "VtwamTitleArg"
QT_MOC_LITERAL(28, 444, 12), // "scanFinished"
QT_MOC_LITERAL(29, 457, 15), // "rptScanFinished"
QT_MOC_LITERAL(30, 473, 18), // "updateProcProgress"
QT_MOC_LITERAL(31, 492, 11), // "curframeNum"
QT_MOC_LITERAL(32, 504, 12), // "FilterRadius"
QT_MOC_LITERAL(33, 517, 10), // "filterType"
QT_MOC_LITERAL(34, 528, 12), // "procFinished"
QT_MOC_LITERAL(35, 541, 8), // "saveData"
QT_MOC_LITERAL(36, 550, 6), // "status"
QT_MOC_LITERAL(37, 557, 8), // "loadData"
QT_MOC_LITERAL(38, 566, 12), // "saveDataComp"
QT_MOC_LITERAL(39, 579, 12), // "loadDataComp"
QT_MOC_LITERAL(40, 592, 14), // "plotResultTime"
QT_MOC_LITERAL(41, 607, 11), // "pointToPlot"
QT_MOC_LITERAL(42, 619, 14), // "saveScreenshot"
QT_MOC_LITERAL(43, 634, 18), // "setframeNumSubband"
QT_MOC_LITERAL(44, 653, 13), // "chooseSubband"
QT_MOC_LITERAL(45, 667, 7), // "subband"
QT_MOC_LITERAL(46, 675, 9), // "saveMovie"
QT_MOC_LITERAL(47, 685, 17), // "updateResultSpect"
QT_MOC_LITERAL(48, 703, 20), // "parallelprocFinished"
QT_MOC_LITERAL(49, 724, 19), // "saveScreenshotVtwam"
QT_MOC_LITERAL(50, 744, 4), // "stop"
QT_MOC_LITERAL(51, 749, 12), // "setRlTmMdFlt"
QT_MOC_LITERAL(52, 762, 22), // "applyRealTimeFilterArg"
QT_MOC_LITERAL(53, 785, 18), // "procFinishedGather"
QT_MOC_LITERAL(54, 804, 15), // "setBoostSpeedEn"
QT_MOC_LITERAL(55, 820, 3), // "val"
QT_MOC_LITERAL(56, 824, 27), // "postProcessingXCorRequested"
QT_MOC_LITERAL(57, 852, 18) // "saveScreenshotXcor"

    },
    "dataProcessor\0updateProgressBar_dataProcessorSignal\0"
    "\0Percentage\0updateStatusBar_dataProcessorSignal\0"
    "StatusTip\0updateOsciPlot\0double*\0"
    "WfmPointer\0updateResultTimePlot\0short*\0"
    "y_pt\0title\0updateRowColNumAcquired_sig\0"
    "abortThread_sig\0setStagePosX\0setStagePosZ\0"
    "wfmCopyDone_sig\0newWfmCopyToArray_slot\0"
    "wfmPtr\0waveformNumber\0setframeNum\0"
    "frameNum_arg\0selectDisplayBuffer\0"
    "Filtered\0postProcessingFilteringRequested\0"
    "postProcessingVtwamRequested\0VtwamTitleArg\0"
    "scanFinished\0rptScanFinished\0"
    "updateProcProgress\0curframeNum\0"
    "FilterRadius\0filterType\0procFinished\0"
    "saveData\0status\0loadData\0saveDataComp\0"
    "loadDataComp\0plotResultTime\0pointToPlot\0"
    "saveScreenshot\0setframeNumSubband\0"
    "chooseSubband\0subband\0saveMovie\0"
    "updateResultSpect\0parallelprocFinished\0"
    "saveScreenshotVtwam\0stop\0setRlTmMdFlt\0"
    "applyRealTimeFilterArg\0procFinishedGather\0"
    "setBoostSpeedEn\0val\0postProcessingXCorRequested\0"
    "saveScreenshotXcor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dataProcessor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      38,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  204,    2, 0x06 /* Public */,
       4,    1,  207,    2, 0x06 /* Public */,
       6,    1,  210,    2, 0x06 /* Public */,
       9,    2,  213,    2, 0x06 /* Public */,
      13,    1,  218,    2, 0x06 /* Public */,
      14,    0,  221,    2, 0x06 /* Public */,
      15,    2,  222,    2, 0x06 /* Public */,
      16,    2,  227,    2, 0x06 /* Public */,
      17,    1,  232,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    2,  235,    2, 0x0a /* Public */,
      21,    1,  240,    2, 0x0a /* Public */,
      23,    1,  243,    2, 0x0a /* Public */,
      25,    0,  246,    2, 0x0a /* Public */,
      26,    1,  247,    2, 0x0a /* Public */,
      28,    1,  250,    2, 0x0a /* Public */,
      29,    0,  253,    2, 0x0a /* Public */,
      30,    3,  254,    2, 0x0a /* Public */,
      30,    2,  261,    2, 0x2a /* Public | MethodCloned */,
      30,    1,  266,    2, 0x2a /* Public | MethodCloned */,
      34,    0,  269,    2, 0x0a /* Public */,
      35,    1,  270,    2, 0x0a /* Public */,
      37,    1,  273,    2, 0x0a /* Public */,
      38,    1,  276,    2, 0x0a /* Public */,
      39,    1,  279,    2, 0x0a /* Public */,
      40,    1,  282,    2, 0x0a /* Public */,
      42,    0,  285,    2, 0x0a /* Public */,
      43,    1,  286,    2, 0x0a /* Public */,
      44,    1,  289,    2, 0x0a /* Public */,
      46,    0,  292,    2, 0x0a /* Public */,
      47,    0,  293,    2, 0x0a /* Public */,
      48,    0,  294,    2, 0x0a /* Public */,
      49,    0,  295,    2, 0x0a /* Public */,
      50,    0,  296,    2, 0x0a /* Public */,
      51,    1,  297,    2, 0x0a /* Public */,
      53,    0,  300,    2, 0x0a /* Public */,
      54,    1,  301,    2, 0x0a /* Public */,
      56,    0,  304,    2, 0x0a /* Public */,
      57,    0,  305,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int,   19,   20,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Short, QMetaType::Short,   31,   32,   33,
    QMetaType::Void, QMetaType::Int, QMetaType::Short,   31,   32,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   36,
    QMetaType::Void, QMetaType::Bool,   36,
    QMetaType::Void, QMetaType::Bool,   36,
    QMetaType::Void, QMetaType::Bool,   36,
    QMetaType::Void, QMetaType::Int,   41,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Short,   45,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   52,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   55,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dataProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dataProcessor *_t = static_cast<dataProcessor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateProgressBar_dataProcessorSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateStatusBar_dataProcessorSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateOsciPlot((*reinterpret_cast< double*(*)>(_a[1]))); break;
        case 3: _t->updateResultTimePlot((*reinterpret_cast< short*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->updateRowColNumAcquired_sig((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->abortThread_sig(); break;
        case 6: _t->setStagePosX((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->setStagePosZ((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->wfmCopyDone_sig((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->newWfmCopyToArray_slot((*reinterpret_cast< short*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->setframeNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->selectDisplayBuffer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->postProcessingFilteringRequested(); break;
        case 13: _t->postProcessingVtwamRequested((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->scanFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->rptScanFinished(); break;
        case 16: _t->updateProcProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3]))); break;
        case 17: _t->updateProcProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2]))); break;
        case 18: _t->updateProcProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->procFinished(); break;
        case 20: _t->saveData((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->loadData((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->saveDataComp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->loadDataComp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->plotResultTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->saveScreenshot(); break;
        case 26: _t->setframeNumSubband((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->chooseSubband((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 28: _t->saveMovie(); break;
        case 29: _t->updateResultSpect(); break;
        case 30: _t->parallelprocFinished(); break;
        case 31: _t->saveScreenshotVtwam(); break;
        case 32: _t->stop(); break;
        case 33: _t->setRlTmMdFlt((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->procFinishedGather(); break;
        case 35: _t->setBoostSpeedEn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->postProcessingXCorRequested(); break;
        case 37: _t->saveScreenshotXcor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (dataProcessor::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dataProcessor::updateProgressBar_dataProcessorSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (dataProcessor::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dataProcessor::updateStatusBar_dataProcessorSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (dataProcessor::*_t)(double * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dataProcessor::updateOsciPlot)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (dataProcessor::*_t)(short * , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dataProcessor::updateResultTimePlot)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (dataProcessor::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dataProcessor::updateRowColNumAcquired_sig)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (dataProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dataProcessor::abortThread_sig)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (dataProcessor::*_t)(uint , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dataProcessor::setStagePosX)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (dataProcessor::*_t)(uint , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dataProcessor::setStagePosZ)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (dataProcessor::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dataProcessor::wfmCopyDone_sig)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject dataProcessor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_dataProcessor.data,
      qt_meta_data_dataProcessor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *dataProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dataProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_dataProcessor.stringdata0))
        return static_cast<void*>(const_cast< dataProcessor*>(this));
    return QObject::qt_metacast(_clname);
}

int dataProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 38)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 38;
    }
    return _id;
}

// SIGNAL 0
void dataProcessor::updateProgressBar_dataProcessorSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void dataProcessor::updateStatusBar_dataProcessorSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void dataProcessor::updateOsciPlot(double * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void dataProcessor::updateResultTimePlot(short * _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void dataProcessor::updateRowColNumAcquired_sig(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void dataProcessor::abortThread_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void dataProcessor::setStagePosX(uint _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void dataProcessor::setStagePosZ(uint _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void dataProcessor::wfmCopyDone_sig(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
