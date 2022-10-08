/****************************************************************************
** Meta object code from reading C++ file 'dataProcessor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FSM_ver5_N7/dataProcessor.h"
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
    QByteArrayData data[13];
    char stringdata0[165];
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
QT_MOC_LITERAL(9, 93, 15), // "processParallel"
QT_MOC_LITERAL(10, 109, 23), // "updateRowColNumAcquired"
QT_MOC_LITERAL(11, 133, 16), // "wvfrmAcquiredArg"
QT_MOC_LITERAL(12, 150, 14) // "setAbortThread"

    },
    "coreProcessor\0updateProgress\0\0curFrame\0"
    "FilterRadius\0filterType\0finished\0"
    "process\0processVtwam\0processParallel\0"
    "updateRowColNumAcquired\0wvfrmAcquiredArg\0"
    "setAbortThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_coreProcessor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   49,    2, 0x06 /* Public */,
       6,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   57,    2, 0x0a /* Public */,
       8,    0,   58,    2, 0x0a /* Public */,
       9,    0,   59,    2, 0x0a /* Public */,
      10,    1,   60,    2, 0x0a /* Public */,
      12,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Short, QMetaType::Short,    3,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
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
        case 4: _t->processParallel(); break;
        case 5: _t->updateRowColNumAcquired((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setAbortThread(); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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
    QByteArrayData data[56];
    char stringdata0[786];
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
QT_MOC_LITERAL(6, 110, 20), // "updateResultTimePlot"
QT_MOC_LITERAL(7, 131, 6), // "float*"
QT_MOC_LITERAL(8, 138, 4), // "y_pt"
QT_MOC_LITERAL(9, 143, 5), // "title"
QT_MOC_LITERAL(10, 149, 4), // "x_pt"
QT_MOC_LITERAL(11, 154, 27), // "updateRowColNumAcquired_sig"
QT_MOC_LITERAL(12, 182, 15), // "abortThread_sig"
QT_MOC_LITERAL(13, 198, 21), // "declarePlotMemory_sig"
QT_MOC_LITERAL(14, 220, 12), // "loadDataDone"
QT_MOC_LITERAL(15, 233, 8), // "measDone"
QT_MOC_LITERAL(16, 242, 11), // "setframeNum"
QT_MOC_LITERAL(17, 254, 12), // "frameNum_arg"
QT_MOC_LITERAL(18, 267, 19), // "selectDisplayBuffer"
QT_MOC_LITERAL(19, 287, 9), // "measIndex"
QT_MOC_LITERAL(20, 297, 32), // "postProcessingFilteringRequested"
QT_MOC_LITERAL(21, 330, 28), // "postProcessingVtwamRequested"
QT_MOC_LITERAL(22, 359, 13), // "VtwamTitleArg"
QT_MOC_LITERAL(23, 373, 18), // "updateProcProgress"
QT_MOC_LITERAL(24, 392, 11), // "curframeNum"
QT_MOC_LITERAL(25, 404, 12), // "FilterRadius"
QT_MOC_LITERAL(26, 417, 10), // "filterType"
QT_MOC_LITERAL(27, 428, 12), // "procFinished"
QT_MOC_LITERAL(28, 441, 8), // "saveData"
QT_MOC_LITERAL(29, 450, 6), // "status"
QT_MOC_LITERAL(30, 457, 11), // "saveDataCur"
QT_MOC_LITERAL(31, 469, 8), // "loadData"
QT_MOC_LITERAL(32, 478, 14), // "plotResultTime"
QT_MOC_LITERAL(33, 493, 11), // "pointToPlot"
QT_MOC_LITERAL(34, 505, 14), // "saveScreenshot"
QT_MOC_LITERAL(35, 520, 10), // "isMemValid"
QT_MOC_LITERAL(36, 531, 8), // "float***"
QT_MOC_LITERAL(37, 540, 10), // "dataBundle"
QT_MOC_LITERAL(38, 551, 13), // "dispBuffIndex"
QT_MOC_LITERAL(39, 565, 8), // "frameNum"
QT_MOC_LITERAL(40, 574, 11), // "const char*"
QT_MOC_LITERAL(41, 586, 10), // "callername"
QT_MOC_LITERAL(42, 597, 8), // "isSilent"
QT_MOC_LITERAL(43, 606, 9), // "saveMovie"
QT_MOC_LITERAL(44, 616, 17), // "updateResultSpect"
QT_MOC_LITERAL(45, 634, 20), // "parallelprocFinished"
QT_MOC_LITERAL(46, 655, 19), // "saveScreenshotVtwam"
QT_MOC_LITERAL(47, 675, 4), // "stop"
QT_MOC_LITERAL(48, 680, 18), // "procFinishedGather"
QT_MOC_LITERAL(49, 699, 15), // "setBoostSpeedEn"
QT_MOC_LITERAL(50, 715, 3), // "val"
QT_MOC_LITERAL(51, 719, 15), // "saveDataSetting"
QT_MOC_LITERAL(52, 735, 22), // "newWfmCopyToArray_slot"
QT_MOC_LITERAL(53, 758, 11), // "structMeas*"
QT_MOC_LITERAL(54, 770, 5), // "pMeas"
QT_MOC_LITERAL(55, 776, 9) // "curScanPt"

    },
    "dataProcessor\0updateProgressBar_dataProcessorSignal\0"
    "\0Percentage\0updateStatusBar_dataProcessorSignal\0"
    "StatusTip\0updateResultTimePlot\0float*\0"
    "y_pt\0title\0x_pt\0updateRowColNumAcquired_sig\0"
    "abortThread_sig\0declarePlotMemory_sig\0"
    "loadDataDone\0measDone\0setframeNum\0"
    "frameNum_arg\0selectDisplayBuffer\0"
    "measIndex\0postProcessingFilteringRequested\0"
    "postProcessingVtwamRequested\0VtwamTitleArg\0"
    "updateProcProgress\0curframeNum\0"
    "FilterRadius\0filterType\0procFinished\0"
    "saveData\0status\0saveDataCur\0loadData\0"
    "plotResultTime\0pointToPlot\0saveScreenshot\0"
    "isMemValid\0float***\0dataBundle\0"
    "dispBuffIndex\0frameNum\0const char*\0"
    "callername\0isSilent\0saveMovie\0"
    "updateResultSpect\0parallelprocFinished\0"
    "saveScreenshotVtwam\0stop\0procFinishedGather\0"
    "setBoostSpeedEn\0val\0saveDataSetting\0"
    "newWfmCopyToArray_slot\0structMeas*\0"
    "pMeas\0curScanPt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dataProcessor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  174,    2, 0x06 /* Public */,
       4,    1,  177,    2, 0x06 /* Public */,
       6,    3,  180,    2, 0x06 /* Public */,
      11,    1,  187,    2, 0x06 /* Public */,
      12,    0,  190,    2, 0x06 /* Public */,
      13,    0,  191,    2, 0x06 /* Public */,
      14,    0,  192,    2, 0x06 /* Public */,
      15,    0,  193,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    1,  194,    2, 0x0a /* Public */,
      18,    1,  197,    2, 0x0a /* Public */,
      20,    0,  200,    2, 0x0a /* Public */,
      21,    1,  201,    2, 0x0a /* Public */,
      23,    3,  204,    2, 0x0a /* Public */,
      23,    2,  211,    2, 0x2a /* Public | MethodCloned */,
      23,    1,  216,    2, 0x2a /* Public | MethodCloned */,
      27,    0,  219,    2, 0x0a /* Public */,
      28,    1,  220,    2, 0x0a /* Public */,
      30,    1,  223,    2, 0x0a /* Public */,
      31,    1,  226,    2, 0x0a /* Public */,
      32,    1,  229,    2, 0x0a /* Public */,
      34,    0,  232,    2, 0x0a /* Public */,
      35,    5,  233,    2, 0x0a /* Public */,
      35,    4,  244,    2, 0x2a /* Public | MethodCloned */,
      43,    0,  253,    2, 0x0a /* Public */,
      44,    0,  254,    2, 0x0a /* Public */,
      45,    0,  255,    2, 0x0a /* Public */,
      46,    0,  256,    2, 0x0a /* Public */,
      47,    0,  257,    2, 0x0a /* Public */,
      48,    0,  258,    2, 0x0a /* Public */,
      49,    1,  259,    2, 0x0a /* Public */,
      51,    0,  262,    2, 0x0a /* Public */,
      52,    2,  263,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QString, 0x80000000 | 7,    8,    9,   10,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::Int, QMetaType::Short, QMetaType::Short,   24,   25,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Short,   24,   25,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 36, QMetaType::Int, QMetaType::Int, 0x80000000 | 40, QMetaType::Bool,   37,   38,   39,   41,   42,
    QMetaType::Bool, 0x80000000 | 36, QMetaType::Int, QMetaType::Int, 0x80000000 | 40,   37,   38,   39,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 53, QMetaType::Int,   54,   55,

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
        case 2: _t->updateResultTimePlot((*reinterpret_cast< float*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< float*(*)>(_a[3]))); break;
        case 3: _t->updateRowColNumAcquired_sig((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->abortThread_sig(); break;
        case 5: _t->declarePlotMemory_sig(); break;
        case 6: _t->loadDataDone(); break;
        case 7: _t->measDone(); break;
        case 8: _t->setframeNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->selectDisplayBuffer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->postProcessingFilteringRequested(); break;
        case 11: _t->postProcessingVtwamRequested((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->updateProcProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3]))); break;
        case 13: _t->updateProcProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2]))); break;
        case 14: _t->updateProcProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->procFinished(); break;
        case 16: _t->saveData((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->saveDataCur((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->loadData((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->plotResultTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->saveScreenshot(); break;
        case 21: { bool _r = _t->isMemValid((*reinterpret_cast< float***(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const char*(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 22: { bool _r = _t->isMemValid((*reinterpret_cast< float***(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const char*(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 23: _t->saveMovie(); break;
        case 24: _t->updateResultSpect(); break;
        case 25: _t->parallelprocFinished(); break;
        case 26: _t->saveScreenshotVtwam(); break;
        case 27: _t->stop(); break;
        case 28: _t->procFinishedGather(); break;
        case 29: _t->setBoostSpeedEn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->saveDataSetting(); break;
        case 31: _t->newWfmCopyToArray_slot((*reinterpret_cast< structMeas*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
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
            typedef void (dataProcessor::*_t)(float * , QString , float * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dataProcessor::updateResultTimePlot)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (dataProcessor::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dataProcessor::updateRowColNumAcquired_sig)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (dataProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dataProcessor::abortThread_sig)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (dataProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dataProcessor::declarePlotMemory_sig)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (dataProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dataProcessor::loadDataDone)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (dataProcessor::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dataProcessor::measDone)) {
                *result = 7;
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
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 32;
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
void dataProcessor::updateResultTimePlot(float * _t1, QString _t2, float * _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void dataProcessor::updateRowColNumAcquired_sig(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void dataProcessor::abortThread_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void dataProcessor::declarePlotMemory_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void dataProcessor::loadDataDone()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void dataProcessor::measDone()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
