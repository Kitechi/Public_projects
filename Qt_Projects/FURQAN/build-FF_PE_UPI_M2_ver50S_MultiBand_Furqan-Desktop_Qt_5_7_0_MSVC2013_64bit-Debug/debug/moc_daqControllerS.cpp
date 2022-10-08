/****************************************************************************
** Meta object code from reading C++ file 'daqControllerS.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FF_PE_UPI_50S_MultiBand/daqControllerS.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'daqControllerS.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_fetcher_t {
    QByteArrayData data[17];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fetcher_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fetcher_t qt_meta_stringdata_fetcher = {
    {
QT_MOC_LITERAL(0, 0, 7), // "fetcher"
QT_MOC_LITERAL(1, 8, 10), // "newArrival"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "errorSignal"
QT_MOC_LITERAL(4, 32, 3), // "err"
QT_MOC_LITERAL(5, 36, 8), // "finished"
QT_MOC_LITERAL(6, 45, 5), // "fetch"
QT_MOC_LITERAL(7, 51, 13), // "fetchOsciMode"
QT_MOC_LITERAL(8, 65, 7), // "setPars"
QT_MOC_LITERAL(9, 73, 17), // "ST_SPCM_CARDINFO*"
QT_MOC_LITERAL(10, 91, 11), // "pstCard_arg"
QT_MOC_LITERAL(11, 103, 13), // "reqWfmCnt_arg"
QT_MOC_LITERAL(12, 117, 16), // "pvDataBuffer_arg"
QT_MOC_LITERAL(13, 134, 14), // "OsciModeEn_arg"
QT_MOC_LITERAL(14, 149, 16), // "dwDataBufLen_arg"
QT_MOC_LITERAL(15, 166, 5), // "reset"
QT_MOC_LITERAL(16, 172, 16) // "resetWaitForCopy"

    },
    "fetcher\0newArrival\0\0errorSignal\0err\0"
    "finished\0fetch\0fetchOsciMode\0setPars\0"
    "ST_SPCM_CARDINFO*\0pstCard_arg\0"
    "reqWfmCnt_arg\0pvDataBuffer_arg\0"
    "OsciModeEn_arg\0dwDataBufLen_arg\0reset\0"
    "resetWaitForCopy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fetcher[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       3,    1,   59,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   65,    2, 0x0a /* Public */,
       7,    0,   66,    2, 0x0a /* Public */,
       8,    5,   67,    2, 0x0a /* Public */,
      15,    0,   78,    2, 0x0a /* Public */,
      16,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Long,    2,    2,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int, QMetaType::VoidStar, QMetaType::Bool, QMetaType::ULong,   10,   11,   12,   13,   14,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void fetcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fetcher *_t = static_cast<fetcher *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newArrival((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2]))); break;
        case 1: _t->errorSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->fetch(); break;
        case 4: _t->fetchOsciMode(); break;
        case 5: _t->setPars((*reinterpret_cast< ST_SPCM_CARDINFO*(*)>(_a[1])),(*reinterpret_cast< qint32(*)>(_a[2])),(*reinterpret_cast< void*(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< ulong(*)>(_a[5]))); break;
        case 6: _t->reset(); break;
        case 7: _t->resetWaitForCopy(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (fetcher::*_t)(int , long );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fetcher::newArrival)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (fetcher::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fetcher::errorSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (fetcher::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fetcher::finished)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject fetcher::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_fetcher.data,
      qt_meta_data_fetcher,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *fetcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fetcher::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_fetcher.stringdata0))
        return static_cast<void*>(const_cast< fetcher*>(this));
    return QObject::qt_metacast(_clname);
}

int fetcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void fetcher::newArrival(int _t1, long _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void fetcher::errorSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void fetcher::finished(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_daqController_t {
    QByteArrayData data[18];
    char stringdata0[272];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_daqController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_daqController_t qt_meta_stringdata_daqController = {
    {
QT_MOC_LITERAL(0, 0, 13), // "daqController"
QT_MOC_LITERAL(1, 14, 37), // "updateProgressBar_daqControll..."
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 10), // "Percentage"
QT_MOC_LITERAL(4, 64, 35), // "updateStatusBar_daqController..."
QT_MOC_LITERAL(5, 100, 9), // "StatusTip"
QT_MOC_LITERAL(6, 110, 18), // "newWfmReadyForCopy"
QT_MOC_LITERAL(7, 129, 6), // "short*"
QT_MOC_LITERAL(8, 136, 10), // "WfmPointer"
QT_MOC_LITERAL(9, 147, 14), // "waveformNumber"
QT_MOC_LITERAL(10, 162, 12), // "scanFinished"
QT_MOC_LITERAL(11, 175, 14), // "updatePlotOsci"
QT_MOC_LITERAL(12, 190, 12), // "errorHandler"
QT_MOC_LITERAL(13, 203, 15), // "newArrivalInDaq"
QT_MOC_LITERAL(14, 219, 9), // "lAvailPos"
QT_MOC_LITERAL(15, 229, 11), // "acqFinished"
QT_MOC_LITERAL(16, 241, 18), // "setallowOsciUpdate"
QT_MOC_LITERAL(17, 260, 11) // "wfmCopyDone"

    },
    "daqController\0updateProgressBar_daqControllerSignal\0"
    "\0Percentage\0updateStatusBar_daqControllerSignal\0"
    "StatusTip\0newWfmReadyForCopy\0short*\0"
    "WfmPointer\0waveformNumber\0scanFinished\0"
    "updatePlotOsci\0errorHandler\0newArrivalInDaq\0"
    "lAvailPos\0acqFinished\0setallowOsciUpdate\0"
    "wfmCopyDone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_daqController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       6,    2,   70,    2, 0x06 /* Public */,
      10,    1,   75,    2, 0x06 /* Public */,
      11,    1,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   81,    2, 0x0a /* Public */,
      13,    2,   84,    2, 0x0a /* Public */,
      15,    1,   89,    2, 0x0a /* Public */,
      16,    0,   92,    2, 0x0a /* Public */,
      17,    1,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Long,    2,   14,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void daqController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        daqController *_t = static_cast<daqController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateProgressBar_daqControllerSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateStatusBar_daqControllerSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->newWfmReadyForCopy((*reinterpret_cast< short*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->scanFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->updatePlotOsci((*reinterpret_cast< short*(*)>(_a[1]))); break;
        case 5: _t->errorHandler((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->newArrivalInDaq((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2]))); break;
        case 7: _t->acqFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setallowOsciUpdate(); break;
        case 9: _t->wfmCopyDone((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (daqController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&daqController::updateProgressBar_daqControllerSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (daqController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&daqController::updateStatusBar_daqControllerSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (daqController::*_t)(short * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&daqController::newWfmReadyForCopy)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (daqController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&daqController::scanFinished)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (daqController::*_t)(short * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&daqController::updatePlotOsci)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject daqController::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_daqController.data,
      qt_meta_data_daqController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *daqController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *daqController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_daqController.stringdata0))
        return static_cast<void*>(const_cast< daqController*>(this));
    return QWidget::qt_metacast(_clname);
}

int daqController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void daqController::updateProgressBar_daqControllerSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void daqController::updateStatusBar_daqControllerSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void daqController::newWfmReadyForCopy(short * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void daqController::scanFinished(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void daqController::updatePlotOsci(short * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
