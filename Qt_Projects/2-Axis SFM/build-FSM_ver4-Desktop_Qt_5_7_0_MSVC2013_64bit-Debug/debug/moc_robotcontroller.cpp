/****************************************************************************
** Meta object code from reading C++ file 'robotcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Users/SSL/Desktop/SFM_with_TCP/robotcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robotcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
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
struct qt_meta_stringdata_robotController_t {
    QByteArrayData data[9];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_robotController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_robotController_t qt_meta_stringdata_robotController = {
    {
QT_MOC_LITERAL(0, 0, 15), // "robotController"
QT_MOC_LITERAL(1, 16, 16), // "atNewPointInScan"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 12), // "scanFinished"
QT_MOC_LITERAL(4, 47, 9), // "startScan"
QT_MOC_LITERAL(5, 57, 8), // "stopScan"
QT_MOC_LITERAL(6, 66, 2), // "pt"
QT_MOC_LITERAL(7, 69, 12), // "atNewPt_slot"
QT_MOC_LITERAL(8, 82, 16) // "setMeasDone_slot"

    },
    "robotController\0atNewPointInScan\0\0"
    "scanFinished\0startScan\0stopScan\0pt\0"
    "atNewPt_slot\0setMeasDone_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_robotController[] = {

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

void robotController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        robotController *_t = static_cast<robotController *>(_o);
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
            typedef void (robotController::*_t)(uint , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&robotController::atNewPointInScan)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (robotController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&robotController::scanFinished)) {
                *result = 1;
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
void robotController::atNewPointInScan(uint _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void robotController::scanFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
