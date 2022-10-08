/****************************************************************************
** Meta object code from reading C++ file 'robotController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Dual_Port_Robotics_SFM_Ver1/robotController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robotController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_robotController_t {
    QByteArrayData data[54];
    char stringdata0[579];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_robotController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_robotController_t qt_meta_stringdata_robotController = {
    {
QT_MOC_LITERAL(0, 0, 15), // "robotController"
QT_MOC_LITERAL(1, 16, 39), // "updateProgressBar_robotContro..."
QT_MOC_LITERAL(2, 56, 0), // ""
QT_MOC_LITERAL(3, 57, 10), // "Percentage"
QT_MOC_LITERAL(4, 68, 37), // "updateStatusBar_robotControll..."
QT_MOC_LITERAL(5, 106, 9), // "StatusTip"
QT_MOC_LITERAL(6, 116, 4), // "Xpos"
QT_MOC_LITERAL(7, 121, 4), // "Ypos"
QT_MOC_LITERAL(8, 126, 4), // "Zpos"
QT_MOC_LITERAL(9, 131, 10), // "sendStrCmd"
QT_MOC_LITERAL(10, 142, 5), // "char*"
QT_MOC_LITERAL(11, 148, 10), // "sendString"
QT_MOC_LITERAL(12, 159, 11), // "QByteArray*"
QT_MOC_LITERAL(13, 171, 8), // "rspArray"
QT_MOC_LITERAL(14, 180, 4), // "home"
QT_MOC_LITERAL(15, 185, 4), // "stop"
QT_MOC_LITERAL(16, 190, 5), // "Jogxp"
QT_MOC_LITERAL(17, 196, 5), // "Jogxn"
QT_MOC_LITERAL(18, 202, 5), // "Jogyp"
QT_MOC_LITERAL(19, 208, 5), // "Jogyn"
QT_MOC_LITERAL(20, 214, 5), // "Jogzp"
QT_MOC_LITERAL(21, 220, 5), // "Jogzn"
QT_MOC_LITERAL(22, 226, 8), // "jogStart"
QT_MOC_LITERAL(23, 235, 4), // "axis"
QT_MOC_LITERAL(24, 240, 9), // "direction"
QT_MOC_LITERAL(25, 250, 7), // "jogStop"
QT_MOC_LITERAL(26, 258, 7), // "jogSlot"
QT_MOC_LITERAL(27, 266, 12), // "moveToTarget"
QT_MOC_LITERAL(28, 279, 15), // "structRobTarget"
QT_MOC_LITERAL(29, 295, 6), // "target"
QT_MOC_LITERAL(30, 302, 18), // "updateToolRotation"
QT_MOC_LITERAL(31, 321, 8), // "useMoveJ"
QT_MOC_LITERAL(32, 330, 6), // "getPos"
QT_MOC_LITERAL(33, 337, 10), // "getHomePos"
QT_MOC_LITERAL(34, 348, 12), // "markScanArea"
QT_MOC_LITERAL(35, 361, 9), // "startScan"
QT_MOC_LITERAL(36, 371, 14), // "gotoScanPrePos"
QT_MOC_LITERAL(37, 386, 13), // "gotoScanStart"
QT_MOC_LITERAL(38, 400, 14), // "genTestPattern"
QT_MOC_LITERAL(39, 415, 14), // "testPatternNum"
QT_MOC_LITERAL(40, 430, 14), // "uploadScanGrid"
QT_MOC_LITERAL(41, 445, 4), // "offs"
QT_MOC_LITERAL(42, 450, 5), // "inPos"
QT_MOC_LITERAL(43, 456, 7), // "xOffset"
QT_MOC_LITERAL(44, 464, 7), // "yOffset"
QT_MOC_LITERAL(45, 472, 7), // "zOffset"
QT_MOC_LITERAL(46, 480, 11), // "setIsVcCont"
QT_MOC_LITERAL(47, 492, 15), // "isVcContSlected"
QT_MOC_LITERAL(48, 508, 10), // "turnOffPos"
QT_MOC_LITERAL(49, 519, 12), // "loadMountPos"
QT_MOC_LITERAL(50, 532, 16), // "bracketAttachPos"
QT_MOC_LITERAL(51, 549, 7), // "genTrig"
QT_MOC_LITERAL(52, 557, 14), // "ldvLaserTurnOn"
QT_MOC_LITERAL(53, 572, 6) // "turnOn"

    },
    "robotController\0updateProgressBar_robotControllerSignal\0"
    "\0Percentage\0updateStatusBar_robotControllerSignal\0"
    "StatusTip\0Xpos\0Ypos\0Zpos\0sendStrCmd\0"
    "char*\0sendString\0QByteArray*\0rspArray\0"
    "home\0stop\0Jogxp\0Jogxn\0Jogyp\0Jogyn\0"
    "Jogzp\0Jogzn\0jogStart\0axis\0direction\0"
    "jogStop\0jogSlot\0moveToTarget\0"
    "structRobTarget\0target\0updateToolRotation\0"
    "useMoveJ\0getPos\0getHomePos\0markScanArea\0"
    "startScan\0gotoScanPrePos\0gotoScanStart\0"
    "genTestPattern\0testPatternNum\0"
    "uploadScanGrid\0offs\0inPos\0xOffset\0"
    "yOffset\0zOffset\0setIsVcCont\0isVcContSlected\0"
    "turnOffPos\0loadMountPos\0bracketAttachPos\0"
    "genTrig\0ldvLaserTurnOn\0turnOn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_robotController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  194,    2, 0x06 /* Public */,
       4,    1,  197,    2, 0x06 /* Public */,
       6,    1,  200,    2, 0x06 /* Public */,
       7,    1,  203,    2, 0x06 /* Public */,
       8,    1,  206,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,  209,    2, 0x0a /* Public */,
       9,    1,  214,    2, 0x2a /* Public | MethodCloned */,
      14,    0,  217,    2, 0x0a /* Public */,
      15,    0,  218,    2, 0x0a /* Public */,
      16,    0,  219,    2, 0x0a /* Public */,
      17,    0,  220,    2, 0x0a /* Public */,
      18,    0,  221,    2, 0x0a /* Public */,
      19,    0,  222,    2, 0x0a /* Public */,
      20,    0,  223,    2, 0x0a /* Public */,
      21,    0,  224,    2, 0x0a /* Public */,
      22,    2,  225,    2, 0x0a /* Public */,
      25,    0,  230,    2, 0x0a /* Public */,
      26,    0,  231,    2, 0x0a /* Public */,
      27,    3,  232,    2, 0x0a /* Public */,
      27,    2,  239,    2, 0x2a /* Public | MethodCloned */,
      27,    1,  244,    2, 0x2a /* Public | MethodCloned */,
      32,    1,  247,    2, 0x0a /* Public */,
      32,    0,  250,    2, 0x2a /* Public | MethodCloned */,
      34,    0,  251,    2, 0x0a /* Public */,
      35,    0,  252,    2, 0x0a /* Public */,
      36,    0,  253,    2, 0x0a /* Public */,
      37,    0,  254,    2, 0x0a /* Public */,
      38,    1,  255,    2, 0x0a /* Public */,
      40,    0,  258,    2, 0x0a /* Public */,
      41,    4,  259,    2, 0x0a /* Public */,
      46,    1,  268,    2, 0x0a /* Public */,
      48,    0,  271,    2, 0x0a /* Public */,
      49,    0,  272,    2, 0x0a /* Public */,
      50,    0,  273,    2, 0x0a /* Public */,
      51,    0,  274,    2, 0x0a /* Public */,
      52,    1,  275,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 10, 0x80000000 | 12,   11,   13,
    QMetaType::Bool, 0x80000000 | 10,   11,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   23,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 28, QMetaType::Bool, QMetaType::Bool,   29,   30,   31,
    QMetaType::Void, 0x80000000 | 28, QMetaType::Bool,   29,   30,
    QMetaType::Void, 0x80000000 | 28,   29,
    0x80000000 | 28, QMetaType::Bool,   33,
    0x80000000 | 28,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Short,   39,
    QMetaType::Bool,
    0x80000000 | 28, 0x80000000 | 28, QMetaType::Float, QMetaType::Float, QMetaType::Float,   42,   43,   44,   45,
    QMetaType::Bool, QMetaType::Bool,   47,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   53,

       0        // eod
};

void robotController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        robotController *_t = static_cast<robotController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateProgressBar_robotControllerSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateStatusBar_robotControllerSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->Xpos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->Ypos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->Zpos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: { bool _r = _t->sendStrCmd((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< QByteArray*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->sendStrCmd((*reinterpret_cast< char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->home();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->stop(); break;
        case 9: _t->Jogxp(); break;
        case 10: _t->Jogxn(); break;
        case 11: _t->Jogyp(); break;
        case 12: _t->Jogyn(); break;
        case 13: _t->Jogzp(); break;
        case 14: _t->Jogzn(); break;
        case 15: _t->jogStart((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->jogStop(); break;
        case 17: _t->jogSlot(); break;
        case 18: _t->moveToTarget((*reinterpret_cast< structRobTarget(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 19: _t->moveToTarget((*reinterpret_cast< structRobTarget(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 20: _t->moveToTarget((*reinterpret_cast< structRobTarget(*)>(_a[1]))); break;
        case 21: { structRobTarget _r = _t->getPos((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< structRobTarget*>(_a[0]) = _r; }  break;
        case 22: { structRobTarget _r = _t->getPos();
            if (_a[0]) *reinterpret_cast< structRobTarget*>(_a[0]) = _r; }  break;
        case 23: { bool _r = _t->markScanArea();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 24: { bool _r = _t->startScan();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 25: _t->gotoScanPrePos(); break;
        case 26: _t->gotoScanStart(); break;
        case 27: _t->genTestPattern((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 28: { bool _r = _t->uploadScanGrid();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 29: { structRobTarget _r = _t->offs((*reinterpret_cast< structRobTarget(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< structRobTarget*>(_a[0]) = _r; }  break;
        case 30: { bool _r = _t->setIsVcCont((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 31: _t->turnOffPos(); break;
        case 32: _t->loadMountPos(); break;
        case 33: _t->bracketAttachPos(); break;
        case 34: _t->genTrig(); break;
        case 35: _t->ldvLaserTurnOn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (robotController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&robotController::updateProgressBar_robotControllerSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (robotController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&robotController::updateStatusBar_robotControllerSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (robotController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&robotController::Xpos)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (robotController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&robotController::Ypos)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (robotController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&robotController::Zpos)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject robotController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_robotController.data,
      qt_meta_data_robotController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *robotController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *robotController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_robotController.stringdata0))
        return static_cast<void*>(const_cast< robotController*>(this));
    return QObject::qt_metacast(_clname);
}

int robotController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 36)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 36;
    }
    return _id;
}

// SIGNAL 0
void robotController::updateProgressBar_robotControllerSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void robotController::updateStatusBar_robotControllerSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void robotController::Xpos(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void robotController::Ypos(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void robotController::Zpos(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
