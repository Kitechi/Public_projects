/****************************************************************************
** Meta object code from reading C++ file 'stagecontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../2-Axis_SFM_ver6/stagecontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stagecontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_stageController_t {
    QByteArrayData data[43];
    char stringdata0[490];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_stageController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_stageController_t qt_meta_stringdata_stageController = {
    {
QT_MOC_LITERAL(0, 0, 15), // "stageController"
QT_MOC_LITERAL(1, 16, 39), // "updateProgressBar_stageContro..."
QT_MOC_LITERAL(2, 56, 0), // ""
QT_MOC_LITERAL(3, 57, 10), // "Percentage"
QT_MOC_LITERAL(4, 68, 37), // "updateStatusBar_stageControll..."
QT_MOC_LITERAL(5, 106, 9), // "StatusTip"
QT_MOC_LITERAL(6, 116, 4), // "Xpos"
QT_MOC_LITERAL(7, 121, 4), // "Zpos"
QT_MOC_LITERAL(8, 126, 9), // "JogzpStop"
QT_MOC_LITERAL(9, 136, 9), // "JogznStop"
QT_MOC_LITERAL(10, 146, 9), // "JogxpStop"
QT_MOC_LITERAL(11, 156, 9), // "JogxnStop"
QT_MOC_LITERAL(12, 166, 10), // "JogzpStart"
QT_MOC_LITERAL(13, 177, 10), // "JogznStart"
QT_MOC_LITERAL(14, 188, 10), // "JogxpStart"
QT_MOC_LITERAL(15, 199, 10), // "JogxnStart"
QT_MOC_LITERAL(16, 210, 5), // "Jogzp"
QT_MOC_LITERAL(17, 216, 9), // "enableJog"
QT_MOC_LITERAL(18, 226, 5), // "Jogzn"
QT_MOC_LITERAL(19, 232, 5), // "Jogxp"
QT_MOC_LITERAL(20, 238, 5), // "Jogxn"
QT_MOC_LITERAL(21, 244, 9), // "originSet"
QT_MOC_LITERAL(22, 254, 11), // "originReset"
QT_MOC_LITERAL(23, 266, 10), // "initialPos"
QT_MOC_LITERAL(24, 277, 7), // "getPosZ"
QT_MOC_LITERAL(25, 285, 7), // "getPosX"
QT_MOC_LITERAL(26, 293, 7), // "setPosZ"
QT_MOC_LITERAL(27, 301, 14), // "relToScanStart"
QT_MOC_LITERAL(28, 316, 7), // "setPosX"
QT_MOC_LITERAL(29, 324, 11), // "MoveAbsPosZ"
QT_MOC_LITERAL(30, 336, 11), // "MoveAbsPosX"
QT_MOC_LITERAL(31, 348, 15), // "MoveToScanPoint"
QT_MOC_LITERAL(32, 364, 4), // "xPos"
QT_MOC_LITERAL(33, 369, 4), // "zPos"
QT_MOC_LITERAL(34, 374, 9), // "updatePos"
QT_MOC_LITERAL(35, 384, 15), // "clearErrorReset"
QT_MOC_LITERAL(36, 400, 13), // "setErrorReset"
QT_MOC_LITERAL(37, 414, 10), // "setMovetoX"
QT_MOC_LITERAL(38, 425, 10), // "setMovetoZ"
QT_MOC_LITERAL(39, 436, 12), // "resetMovetoX"
QT_MOC_LITERAL(40, 449, 12), // "resetMovetoZ"
QT_MOC_LITERAL(41, 462, 12), // "setServoStop"
QT_MOC_LITERAL(42, 475, 14) // "clearServoStop"

    },
    "stageController\0updateProgressBar_stageControllerSignal\0"
    "\0Percentage\0updateStatusBar_stageControllerSignal\0"
    "StatusTip\0Xpos\0Zpos\0JogzpStop\0JogznStop\0"
    "JogxpStop\0JogxnStop\0JogzpStart\0"
    "JogznStart\0JogxpStart\0JogxnStart\0Jogzp\0"
    "enableJog\0Jogzn\0Jogxp\0Jogxn\0originSet\0"
    "originReset\0initialPos\0getPosZ\0getPosX\0"
    "setPosZ\0relToScanStart\0setPosX\0"
    "MoveAbsPosZ\0MoveAbsPosX\0MoveToScanPoint\0"
    "xPos\0zPos\0updatePos\0clearErrorReset\0"
    "setErrorReset\0setMovetoX\0setMovetoZ\0"
    "resetMovetoX\0resetMovetoZ\0setServoStop\0"
    "clearServoStop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_stageController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  199,    2, 0x06 /* Public */,
       4,    1,  202,    2, 0x06 /* Public */,
       6,    1,  205,    2, 0x06 /* Public */,
       7,    1,  208,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  211,    2, 0x0a /* Public */,
       9,    0,  212,    2, 0x0a /* Public */,
      10,    0,  213,    2, 0x0a /* Public */,
      11,    0,  214,    2, 0x0a /* Public */,
      12,    0,  215,    2, 0x0a /* Public */,
      13,    0,  216,    2, 0x0a /* Public */,
      14,    0,  217,    2, 0x0a /* Public */,
      15,    0,  218,    2, 0x0a /* Public */,
      16,    1,  219,    2, 0x0a /* Public */,
      18,    1,  222,    2, 0x0a /* Public */,
      19,    1,  225,    2, 0x0a /* Public */,
      20,    1,  228,    2, 0x0a /* Public */,
      21,    0,  231,    2, 0x0a /* Public */,
      22,    0,  232,    2, 0x0a /* Public */,
      23,    0,  233,    2, 0x0a /* Public */,
      24,    0,  234,    2, 0x0a /* Public */,
      25,    0,  235,    2, 0x0a /* Public */,
      26,    2,  236,    2, 0x0a /* Public */,
      26,    1,  241,    2, 0x2a /* Public | MethodCloned */,
      28,    2,  244,    2, 0x0a /* Public */,
      28,    1,  249,    2, 0x2a /* Public | MethodCloned */,
      29,    1,  252,    2, 0x0a /* Public */,
      30,    1,  255,    2, 0x0a /* Public */,
      31,    2,  258,    2, 0x0a /* Public */,
      34,    0,  263,    2, 0x0a /* Public */,
      35,    0,  264,    2, 0x0a /* Public */,
      36,    0,  265,    2, 0x0a /* Public */,
      37,    0,  266,    2, 0x0a /* Public */,
      38,    0,  267,    2, 0x0a /* Public */,
      39,    0,  268,    2, 0x0a /* Public */,
      40,    0,  269,    2, 0x0a /* Public */,
      41,    0,  270,    2, 0x0a /* Public */,
      42,    0,  271,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::UInt,
    QMetaType::UInt,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    2,   27,
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    2,   27,
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Bool, QMetaType::UInt,    2,
    QMetaType::Bool, QMetaType::UInt,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   32,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void stageController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        stageController *_t = static_cast<stageController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateProgressBar_stageControllerSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateStatusBar_stageControllerSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->Xpos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->Zpos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->JogzpStop(); break;
        case 5: _t->JogznStop(); break;
        case 6: _t->JogxpStop(); break;
        case 7: _t->JogxnStop(); break;
        case 8: _t->JogzpStart(); break;
        case 9: _t->JogznStart(); break;
        case 10: _t->JogxpStart(); break;
        case 11: _t->JogxnStart(); break;
        case 12: _t->Jogzp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->Jogzn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->Jogxp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->Jogxn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->originSet(); break;
        case 17: _t->originReset(); break;
        case 18: { bool _r = _t->initialPos();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 19: { uint _r = _t->getPosZ();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 20: { uint _r = _t->getPosX();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 21: _t->setPosZ((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 22: _t->setPosZ((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 23: _t->setPosX((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 24: _t->setPosX((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 25: { bool _r = _t->MoveAbsPosZ((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 26: { bool _r = _t->MoveAbsPosX((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 27: _t->MoveToScanPoint((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 28: _t->updatePos(); break;
        case 29: _t->clearErrorReset(); break;
        case 30: _t->setErrorReset(); break;
        case 31: _t->setMovetoX(); break;
        case 32: _t->setMovetoZ(); break;
        case 33: _t->resetMovetoX(); break;
        case 34: _t->resetMovetoZ(); break;
        case 35: _t->setServoStop(); break;
        case 36: _t->clearServoStop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (stageController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&stageController::updateProgressBar_stageControllerSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (stageController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&stageController::updateStatusBar_stageControllerSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (stageController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&stageController::Xpos)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (stageController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&stageController::Zpos)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject stageController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_stageController.data,
      qt_meta_data_stageController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *stageController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *stageController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_stageController.stringdata0))
        return static_cast<void*>(const_cast< stageController*>(this));
    return QObject::qt_metacast(_clname);
}

int stageController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 37;
    }
    return _id;
}

// SIGNAL 0
void stageController::updateProgressBar_stageControllerSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void stageController::updateStatusBar_stageControllerSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void stageController::Xpos(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void stageController::Zpos(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_scanner_t {
    QByteArrayData data[7];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_scanner_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_scanner_t qt_meta_stringdata_scanner = {
    {
QT_MOC_LITERAL(0, 0, 7), // "scanner"
QT_MOC_LITERAL(1, 8, 8), // "finished"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 10), // "atNewPoint"
QT_MOC_LITERAL(4, 29, 4), // "scan"
QT_MOC_LITERAL(5, 34, 11), // "setStopScan"
QT_MOC_LITERAL(6, 46, 11) // "setMeasDone"

    },
    "scanner\0finished\0\0atNewPoint\0scan\0"
    "setStopScan\0setMeasDone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_scanner[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   45,    2, 0x0a /* Public */,
       5,    0,   46,    2, 0x0a /* Public */,
       6,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void, QMetaType::UInt,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void scanner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        scanner *_t = static_cast<scanner *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->atNewPoint((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 2: _t->scan(); break;
        case 3: _t->setStopScan(); break;
        case 4: _t->setMeasDone(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (scanner::*_t)(uint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&scanner::finished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (scanner::*_t)(uint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&scanner::atNewPoint)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject scanner::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_scanner.data,
      qt_meta_data_scanner,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *scanner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *scanner::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_scanner.stringdata0))
        return static_cast<void*>(const_cast< scanner*>(this));
    return QObject::qt_metacast(_clname);
}

int scanner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void scanner::finished(uint _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void scanner::atNewPoint(uint _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_setupController_t {
    QByteArrayData data[9];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_setupController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_setupController_t qt_meta_stringdata_setupController = {
    {
QT_MOC_LITERAL(0, 0, 15), // "setupController"
QT_MOC_LITERAL(1, 16, 16), // "atNewPointInScan"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 12), // "scanFinished"
QT_MOC_LITERAL(4, 47, 9), // "startScan"
QT_MOC_LITERAL(5, 57, 8), // "stopScan"
QT_MOC_LITERAL(6, 66, 2), // "pt"
QT_MOC_LITERAL(7, 69, 12), // "atNewPt_slot"
QT_MOC_LITERAL(8, 82, 16) // "setMeasDone_slot"

    },
    "setupController\0atNewPointInScan\0\0"
    "scanFinished\0startScan\0stopScan\0pt\0"
    "atNewPt_slot\0setMeasDone_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_setupController[] = {

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
       1,    2,   49,    2, 0x06 /* Public */,
       3,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   55,    2, 0x0a /* Public */,
       5,    0,   56,    2, 0x0a /* Public */,
       3,    1,   57,    2, 0x0a /* Public */,
       7,    1,   60,    2, 0x0a /* Public */,
       8,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,    6,
    QMetaType::Void, QMetaType::UInt,    6,
    QMetaType::Void,

       0        // eod
};

void setupController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        setupController *_t = static_cast<setupController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->atNewPointInScan((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->scanFinished(); break;
        case 2: _t->startScan(); break;
        case 3: _t->stopScan(); break;
        case 4: _t->scanFinished((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 5: _t->atNewPt_slot((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 6: _t->setMeasDone_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (setupController::*_t)(uint , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&setupController::atNewPointInScan)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (setupController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&setupController::scanFinished)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject setupController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_setupController.data,
      qt_meta_data_setupController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *setupController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *setupController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_setupController.stringdata0))
        return static_cast<void*>(const_cast< setupController*>(this));
    return QObject::qt_metacast(_clname);
}

int setupController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void setupController::atNewPointInScan(uint _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void setupController::scanFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
