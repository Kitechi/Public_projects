/****************************************************************************
** Meta object code from reading C++ file 'hstageController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FSM_ver5_N7/hstageController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hstageController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_hstageController_t {
    QByteArrayData data[18];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hstageController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hstageController_t qt_meta_stringdata_hstageController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "hstageController"
QT_MOC_LITERAL(1, 17, 6), // "curPos"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 40), // "updateProgressBar_hstageContr..."
QT_MOC_LITERAL(4, 66, 10), // "Percentage"
QT_MOC_LITERAL(5, 77, 38), // "updateStatusBar_hstageControl..."
QT_MOC_LITERAL(6, 116, 9), // "StatusTip"
QT_MOC_LITERAL(7, 126, 4), // "home"
QT_MOC_LITERAL(8, 131, 4), // "stop"
QT_MOC_LITERAL(9, 136, 4), // "kill"
QT_MOC_LITERAL(10, 141, 8), // "jogMinus"
QT_MOC_LITERAL(11, 150, 7), // "jogPlus"
QT_MOC_LITERAL(12, 158, 9), // "setPosAbs"
QT_MOC_LITERAL(13, 168, 6), // "posNum"
QT_MOC_LITERAL(14, 175, 10), // "isPosCheck"
QT_MOC_LITERAL(15, 186, 13), // "setPosAttempt"
QT_MOC_LITERAL(16, 200, 9), // "setPosRel"
QT_MOC_LITERAL(17, 210, 6) // "getPos"

    },
    "hstageController\0curPos\0\0"
    "updateProgressBar_hstageControllerSignal\0"
    "Percentage\0updateStatusBar_hstageControllerSignal\0"
    "StatusTip\0home\0stop\0kill\0jogMinus\0"
    "jogPlus\0setPosAbs\0posNum\0isPosCheck\0"
    "setPosAttempt\0setPosRel\0getPos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hstageController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    1,   82,    2, 0x06 /* Public */,
       5,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   88,    2, 0x0a /* Public */,
       8,    0,   89,    2, 0x0a /* Public */,
       9,    0,   90,    2, 0x0a /* Public */,
      10,    0,   91,    2, 0x0a /* Public */,
      11,    0,   92,    2, 0x0a /* Public */,
      12,    3,   93,    2, 0x0a /* Public */,
      12,    2,  100,    2, 0x2a /* Public | MethodCloned */,
      12,    1,  105,    2, 0x2a /* Public | MethodCloned */,
      16,    1,  108,    2, 0x0a /* Public */,
      17,    0,  111,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Float, QMetaType::Bool, QMetaType::Int,   13,   14,   15,
    QMetaType::Bool, QMetaType::Float, QMetaType::Bool,   13,   14,
    QMetaType::Bool, QMetaType::Float,   13,
    QMetaType::Void, QMetaType::Float,   13,
    QMetaType::Float,

       0        // eod
};

void hstageController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        hstageController *_t = static_cast<hstageController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->curPos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->updateProgressBar_hstageControllerSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updateStatusBar_hstageControllerSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->home(); break;
        case 4: _t->stop(); break;
        case 5: _t->kill(); break;
        case 6: _t->jogMinus(); break;
        case 7: _t->jogPlus(); break;
        case 8: { bool _r = _t->setPosAbs((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { bool _r = _t->setPosAbs((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->setPosAbs((*reinterpret_cast< float(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: _t->setPosRel((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 12: { float _r = _t->getPos();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (hstageController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&hstageController::curPos)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (hstageController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&hstageController::updateProgressBar_hstageControllerSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (hstageController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&hstageController::updateStatusBar_hstageControllerSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject hstageController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_hstageController.data,
      qt_meta_data_hstageController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *hstageController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hstageController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_hstageController.stringdata0))
        return static_cast<void*>(const_cast< hstageController*>(this));
    return QObject::qt_metacast(_clname);
}

int hstageController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void hstageController::curPos(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void hstageController::updateProgressBar_hstageControllerSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void hstageController::updateStatusBar_hstageControllerSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
