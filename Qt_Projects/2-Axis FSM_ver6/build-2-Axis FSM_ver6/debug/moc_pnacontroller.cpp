/****************************************************************************
** Meta object code from reading C++ file 'pnacontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pnacontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pnacontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_pnaController_t {
    QByteArrayData data[24];
    char stringdata0[342];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pnaController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pnaController_t qt_meta_stringdata_pnaController = {
    {
QT_MOC_LITERAL(0, 0, 13), // "pnaController"
QT_MOC_LITERAL(1, 14, 37), // "updateProgressBar_pnaControll..."
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 10), // "Percentage"
QT_MOC_LITERAL(4, 64, 35), // "updateStatusBar_pnaController..."
QT_MOC_LITERAL(5, 100, 9), // "StatusTip"
QT_MOC_LITERAL(6, 110, 18), // "newWfmReadyForCopy"
QT_MOC_LITERAL(7, 129, 11), // "structMeas*"
QT_MOC_LITERAL(8, 141, 5), // "pMeas"
QT_MOC_LITERAL(9, 147, 9), // "curScanPt"
QT_MOC_LITERAL(10, 157, 12), // "scanFinished"
QT_MOC_LITERAL(11, 170, 14), // "updatePlotOsci"
QT_MOC_LITERAL(12, 185, 6), // "float*"
QT_MOC_LITERAL(13, 192, 13), // "doS11MeasSCPI"
QT_MOC_LITERAL(14, 206, 14), // "waveformNumber"
QT_MOC_LITERAL(15, 221, 17), // "configS11MeasSCPI"
QT_MOC_LITERAL(16, 239, 18), // "isImmediateMeasArg"
QT_MOC_LITERAL(17, 258, 15), // "doMeasureN1500A"
QT_MOC_LITERAL(18, 274, 16), // "isScanInProgress"
QT_MOC_LITERAL(19, 291, 12), // "configN1500A"
QT_MOC_LITERAL(20, 304, 16), // "selectMeasN1500A"
QT_MOC_LITERAL(21, 321, 10), // "selectMeas"
QT_MOC_LITERAL(22, 332, 4), // "show"
QT_MOC_LITERAL(23, 337, 4) // "hide"

    },
    "pnaController\0updateProgressBar_pnaControllerSignal\0"
    "\0Percentage\0updateStatusBar_pnaControllerSignal\0"
    "StatusTip\0newWfmReadyForCopy\0structMeas*\0"
    "pMeas\0curScanPt\0scanFinished\0"
    "updatePlotOsci\0float*\0doS11MeasSCPI\0"
    "waveformNumber\0configS11MeasSCPI\0"
    "isImmediateMeasArg\0doMeasureN1500A\0"
    "isScanInProgress\0configN1500A\0"
    "selectMeasN1500A\0selectMeas\0show\0hide"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pnaController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       4,    1,  107,    2, 0x06 /* Public */,
       6,    2,  110,    2, 0x06 /* Public */,
      10,    1,  115,    2, 0x06 /* Public */,
      11,    3,  118,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  125,    2, 0x0a /* Public */,
      13,    0,  128,    2, 0x2a /* Public | MethodCloned */,
      15,    1,  129,    2, 0x0a /* Public */,
      15,    0,  132,    2, 0x2a /* Public | MethodCloned */,
      17,    2,  133,    2, 0x0a /* Public */,
      17,    1,  138,    2, 0x2a /* Public | MethodCloned */,
      17,    0,  141,    2, 0x2a /* Public | MethodCloned */,
      19,    1,  142,    2, 0x0a /* Public */,
      19,    0,  145,    2, 0x2a /* Public | MethodCloned */,
      20,    1,  146,    2, 0x0a /* Public */,
      20,    0,  149,    2, 0x2a /* Public | MethodCloned */,
      22,    0,  150,    2, 0x0a /* Public */,
      23,    0,  151,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 12, QMetaType::QString, 0x80000000 | 12,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    9,   18,
    QMetaType::Void, QMetaType::UInt,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void pnaController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        pnaController *_t = static_cast<pnaController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateProgressBar_pnaControllerSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateStatusBar_pnaControllerSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->newWfmReadyForCopy((*reinterpret_cast< structMeas*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->scanFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->updatePlotOsci((*reinterpret_cast< float*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< float*(*)>(_a[3]))); break;
        case 5: _t->doS11MeasSCPI((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 6: _t->doS11MeasSCPI(); break;
        case 7: _t->configS11MeasSCPI((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->configS11MeasSCPI(); break;
        case 9: _t->doMeasureN1500A((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->doMeasureN1500A((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 11: _t->doMeasureN1500A(); break;
        case 12: _t->configN1500A((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->configN1500A(); break;
        case 14: _t->selectMeasN1500A((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->selectMeasN1500A(); break;
        case 16: _t->show(); break;
        case 17: _t->hide(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (pnaController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pnaController::updateProgressBar_pnaControllerSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (pnaController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pnaController::updateStatusBar_pnaControllerSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (pnaController::*_t)(structMeas * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pnaController::newWfmReadyForCopy)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (pnaController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pnaController::scanFinished)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (pnaController::*_t)(float * , QString , float * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&pnaController::updatePlotOsci)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject pnaController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_pnaController.data,
      qt_meta_data_pnaController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pnaController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pnaController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pnaController.stringdata0))
        return static_cast<void*>(const_cast< pnaController*>(this));
    return QObject::qt_metacast(_clname);
}

int pnaController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void pnaController::updateProgressBar_pnaControllerSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void pnaController::updateStatusBar_pnaControllerSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void pnaController::newWfmReadyForCopy(structMeas * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void pnaController::scanFinished(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void pnaController::updatePlotOsci(float * _t1, QString _t2, float * _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
