/****************************************************************************
** Meta object code from reading C++ file 'rotStageController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FF_PE_UPI_R_ver4_Horizontal/rotStageController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rotStageController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_rotStageController_t {
    QByteArrayData data[28];
    char stringdata0[361];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rotStageController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rotStageController_t qt_meta_stringdata_rotStageController = {
    {
QT_MOC_LITERAL(0, 0, 18), // "rotStageController"
QT_MOC_LITERAL(1, 19, 39), // "updateProgressBar_stageContro..."
QT_MOC_LITERAL(2, 59, 0), // ""
QT_MOC_LITERAL(3, 60, 10), // "Percentage"
QT_MOC_LITERAL(4, 71, 37), // "updateStatusBar_stageControll..."
QT_MOC_LITERAL(5, 109, 9), // "StatusTip"
QT_MOC_LITERAL(6, 119, 3), // "pos"
QT_MOC_LITERAL(7, 123, 7), // "revDone"
QT_MOC_LITERAL(8, 131, 40), // "updateStatusBar_rotStageContr..."
QT_MOC_LITERAL(9, 172, 4), // "stop"
QT_MOC_LITERAL(10, 177, 13), // "spinClockWise"
QT_MOC_LITERAL(11, 191, 17), // "spinAntiClockWise"
QT_MOC_LITERAL(12, 209, 4), // "home"
QT_MOC_LITERAL(13, 214, 6), // "getPos"
QT_MOC_LITERAL(14, 221, 6), // "setPos"
QT_MOC_LITERAL(15, 228, 8), // "position"
QT_MOC_LITERAL(16, 237, 9), // "startScan"
QT_MOC_LITERAL(17, 247, 11), // "intervalDeg"
QT_MOC_LITERAL(18, 259, 8), // "speedDeg"
QT_MOC_LITERAL(19, 268, 11), // "numOfRevArg"
QT_MOC_LITERAL(20, 280, 11), // "isClockWise"
QT_MOC_LITERAL(21, 292, 14), // "SendAndReceive"
QT_MOC_LITERAL(22, 307, 5), // "char*"
QT_MOC_LITERAL(23, 313, 10), // "sendString"
QT_MOC_LITERAL(24, 324, 14), // "showTelnetMsgs"
QT_MOC_LITERAL(25, 339, 11), // "const char*"
QT_MOC_LITERAL(26, 351, 3), // "msg"
QT_MOC_LITERAL(27, 355, 5) // "count"

    },
    "rotStageController\0"
    "updateProgressBar_stageControllerSignal\0"
    "\0Percentage\0updateStatusBar_stageControllerSignal\0"
    "StatusTip\0pos\0revDone\0"
    "updateStatusBar_rotStageControllerSignal\0"
    "stop\0spinClockWise\0spinAntiClockWise\0"
    "home\0getPos\0setPos\0position\0startScan\0"
    "intervalDeg\0speedDeg\0numOfRevArg\0"
    "isClockWise\0SendAndReceive\0char*\0"
    "sendString\0showTelnetMsgs\0const char*\0"
    "msg\0count"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rotStageController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       6,    1,   90,    2, 0x06 /* Public */,
       7,    1,   93,    2, 0x06 /* Public */,
       8,    1,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   99,    2, 0x0a /* Public */,
      10,    0,  100,    2, 0x0a /* Public */,
      11,    0,  101,    2, 0x0a /* Public */,
      12,    0,  102,    2, 0x0a /* Public */,
      13,    0,  103,    2, 0x0a /* Public */,
      14,    1,  104,    2, 0x0a /* Public */,
      16,    4,  107,    2, 0x0a /* Public */,
      21,    1,  116,    2, 0x0a /* Public */,
      24,    2,  119,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Float,
    QMetaType::Void, QMetaType::Float,   15,
    QMetaType::Bool, QMetaType::Float, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   17,   18,   19,   20,
    QMetaType::QByteArray, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 25, QMetaType::Int,   26,   27,

       0        // eod
};

void rotStageController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        rotStageController *_t = static_cast<rotStageController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateProgressBar_stageControllerSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateStatusBar_stageControllerSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->pos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->revDone((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->updateStatusBar_rotStageControllerSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->stop(); break;
        case 6: _t->spinClockWise(); break;
        case 7: _t->spinAntiClockWise(); break;
        case 8: _t->home(); break;
        case 9: { float _r = _t->getPos();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 10: _t->setPos((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 11: { bool _r = _t->startScan((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { QByteArray _r = _t->SendAndReceive((*reinterpret_cast< char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 13: _t->showTelnetMsgs((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (rotStageController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rotStageController::updateProgressBar_stageControllerSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (rotStageController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rotStageController::updateStatusBar_stageControllerSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (rotStageController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rotStageController::pos)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (rotStageController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rotStageController::revDone)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (rotStageController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&rotStageController::updateStatusBar_rotStageControllerSignal)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject rotStageController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_rotStageController.data,
      qt_meta_data_rotStageController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *rotStageController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rotStageController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_rotStageController.stringdata0))
        return static_cast<void*>(const_cast< rotStageController*>(this));
    return QObject::qt_metacast(_clname);
}

int rotStageController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void rotStageController::updateProgressBar_stageControllerSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rotStageController::updateStatusBar_stageControllerSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void rotStageController::pos(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void rotStageController::revDone(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void rotStageController::updateStatusBar_rotStageControllerSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
