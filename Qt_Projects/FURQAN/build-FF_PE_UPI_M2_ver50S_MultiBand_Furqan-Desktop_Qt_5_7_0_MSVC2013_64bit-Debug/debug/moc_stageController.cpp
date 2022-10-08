/****************************************************************************
** Meta object code from reading C++ file 'stageController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FF_PE_UPI_50S_MultiBand/stageController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stageController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_stageController_t {
    QByteArrayData data[47];
    char stringdata0[544];
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
QT_MOC_LITERAL(23, 266, 7), // "getPosZ"
QT_MOC_LITERAL(24, 274, 7), // "getPosX"
QT_MOC_LITERAL(25, 282, 7), // "setPosZ"
QT_MOC_LITERAL(26, 290, 14), // "relToScanStart"
QT_MOC_LITERAL(27, 305, 7), // "setPosX"
QT_MOC_LITERAL(28, 313, 9), // "startScan"
QT_MOC_LITERAL(29, 323, 6), // "height"
QT_MOC_LITERAL(30, 330, 5), // "width"
QT_MOC_LITERAL(31, 336, 3), // "PRF"
QT_MOC_LITERAL(32, 340, 8), // "interval"
QT_MOC_LITERAL(33, 349, 13), // "startAtCurPos"
QT_MOC_LITERAL(34, 363, 9), // "updatePos"
QT_MOC_LITERAL(35, 373, 15), // "clearErrorReset"
QT_MOC_LITERAL(36, 389, 13), // "setErrorReset"
QT_MOC_LITERAL(37, 403, 10), // "setMovetoX"
QT_MOC_LITERAL(38, 414, 10), // "setMovetoZ"
QT_MOC_LITERAL(39, 425, 12), // "resetMovetoX"
QT_MOC_LITERAL(40, 438, 12), // "resetMovetoZ"
QT_MOC_LITERAL(41, 451, 12), // "setServoStop"
QT_MOC_LITERAL(42, 464, 14), // "clearServoStop"
QT_MOC_LITERAL(43, 479, 12), // "markScanArea"
QT_MOC_LITERAL(44, 492, 19), // "clearScanAreaMarker"
QT_MOC_LITERAL(45, 512, 17), // "isReadyForRptScan"
QT_MOC_LITERAL(46, 530, 13) // "gotoScanStart"

    },
    "stageController\0updateProgressBar_stageControllerSignal\0"
    "\0Percentage\0updateStatusBar_stageControllerSignal\0"
    "StatusTip\0Xpos\0Zpos\0JogzpStop\0JogznStop\0"
    "JogxpStop\0JogxnStop\0JogzpStart\0"
    "JogznStart\0JogxpStart\0JogxnStart\0Jogzp\0"
    "enableJog\0Jogzn\0Jogxp\0Jogxn\0originSet\0"
    "originReset\0getPosZ\0getPosX\0setPosZ\0"
    "relToScanStart\0setPosX\0startScan\0"
    "height\0width\0PRF\0interval\0startAtCurPos\0"
    "updatePos\0clearErrorReset\0setErrorReset\0"
    "setMovetoX\0setMovetoZ\0resetMovetoX\0"
    "resetMovetoZ\0setServoStop\0clearServoStop\0"
    "markScanArea\0clearScanAreaMarker\0"
    "isReadyForRptScan\0gotoScanStart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_stageController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  209,    2, 0x06 /* Public */,
       4,    1,  212,    2, 0x06 /* Public */,
       6,    1,  215,    2, 0x06 /* Public */,
       7,    1,  218,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  221,    2, 0x0a /* Public */,
       9,    0,  222,    2, 0x0a /* Public */,
      10,    0,  223,    2, 0x0a /* Public */,
      11,    0,  224,    2, 0x0a /* Public */,
      12,    0,  225,    2, 0x0a /* Public */,
      13,    0,  226,    2, 0x0a /* Public */,
      14,    0,  227,    2, 0x0a /* Public */,
      15,    0,  228,    2, 0x0a /* Public */,
      16,    1,  229,    2, 0x0a /* Public */,
      18,    1,  232,    2, 0x0a /* Public */,
      19,    1,  235,    2, 0x0a /* Public */,
      20,    1,  238,    2, 0x0a /* Public */,
      21,    0,  241,    2, 0x0a /* Public */,
      22,    0,  242,    2, 0x0a /* Public */,
      23,    0,  243,    2, 0x0a /* Public */,
      24,    0,  244,    2, 0x0a /* Public */,
      25,    2,  245,    2, 0x0a /* Public */,
      25,    1,  250,    2, 0x2a /* Public | MethodCloned */,
      27,    2,  253,    2, 0x0a /* Public */,
      27,    1,  258,    2, 0x2a /* Public | MethodCloned */,
      28,    5,  261,    2, 0x0a /* Public */,
      28,    4,  272,    2, 0x2a /* Public | MethodCloned */,
      34,    0,  281,    2, 0x0a /* Public */,
      35,    0,  282,    2, 0x0a /* Public */,
      36,    0,  283,    2, 0x0a /* Public */,
      37,    0,  284,    2, 0x0a /* Public */,
      38,    0,  285,    2, 0x0a /* Public */,
      39,    0,  286,    2, 0x0a /* Public */,
      40,    0,  287,    2, 0x0a /* Public */,
      41,    0,  288,    2, 0x0a /* Public */,
      42,    0,  289,    2, 0x0a /* Public */,
      43,    3,  290,    2, 0x0a /* Public */,
      44,    0,  297,    2, 0x0a /* Public */,
      45,    0,  298,    2, 0x0a /* Public */,
      46,    0,  299,    2, 0x0a /* Public */,

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
    QMetaType::UInt,
    QMetaType::UInt,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    2,   26,
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    2,   26,
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Bool, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Bool,   29,   30,   31,   32,   33,
    QMetaType::Bool, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,   29,   30,   31,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Float, QMetaType::Float, QMetaType::Float,   29,   30,   32,
    QMetaType::Void,
    QMetaType::Bool,
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
        case 18: { uint _r = _t->getPosZ();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 19: { uint _r = _t->getPosX();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 20: _t->setPosZ((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 21: _t->setPosZ((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 22: _t->setPosX((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 23: _t->setPosX((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 24: { bool _r = _t->startScan((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 25: { bool _r = _t->startScan((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 26: _t->updatePos(); break;
        case 27: _t->clearErrorReset(); break;
        case 28: _t->setErrorReset(); break;
        case 29: _t->setMovetoX(); break;
        case 30: _t->setMovetoZ(); break;
        case 31: _t->resetMovetoX(); break;
        case 32: _t->resetMovetoZ(); break;
        case 33: _t->setServoStop(); break;
        case 34: _t->clearServoStop(); break;
        case 35: { bool _r = _t->markScanArea((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 36: _t->clearScanAreaMarker(); break;
        case 37: { bool _r = _t->isReadyForRptScan();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 38: _t->gotoScanStart(); break;
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
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 39)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 39;
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
QT_END_MOC_NAMESPACE
