/****************************************************************************
** Meta object code from reading C++ file 'ldvController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FF_PE_UPI_R_ver4_Horizontal/ldvController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ldvController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ldvController_t {
    QByteArrayData data[10];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ldvController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ldvController_t qt_meta_stringdata_ldvController = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ldvController"
QT_MOC_LITERAL(1, 14, 37), // "updateProgressBar_ldvControll..."
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 10), // "Percentage"
QT_MOC_LITERAL(4, 64, 35), // "updateStatusBar_ldvController..."
QT_MOC_LITERAL(5, 100, 9), // "StatusTip"
QT_MOC_LITERAL(6, 110, 14), // "ldvSignalLevel"
QT_MOC_LITERAL(7, 125, 10), // "percentage"
QT_MOC_LITERAL(8, 136, 11), // "setMainPage"
QT_MOC_LITERAL(9, 148, 14) // "getSignalLevel"

    },
    "ldvController\0updateProgressBar_ldvControllerSignal\0"
    "\0Percentage\0updateStatusBar_ldvControllerSignal\0"
    "StatusTip\0ldvSignalLevel\0percentage\0"
    "setMainPage\0getSignalLevel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ldvController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   48,    2, 0x0a /* Public */,
       9,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Bool,

       0        // eod
};

void ldvController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ldvController *_t = static_cast<ldvController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateProgressBar_ldvControllerSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateStatusBar_ldvControllerSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->ldvSignalLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { bool _r = _t->setMainPage();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->getSignalLevel();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ldvController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ldvController::updateProgressBar_ldvControllerSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ldvController::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ldvController::updateStatusBar_ldvControllerSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ldvController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ldvController::ldvSignalLevel)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ldvController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ldvController.data,
      qt_meta_data_ldvController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ldvController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ldvController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ldvController.stringdata0))
        return static_cast<void*>(const_cast< ldvController*>(this));
    return QObject::qt_metacast(_clname);
}

int ldvController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ldvController::updateProgressBar_ldvControllerSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ldvController::updateStatusBar_ldvControllerSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ldvController::ldvSignalLevel(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
