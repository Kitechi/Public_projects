/****************************************************************************
** Meta object code from reading C++ file 'QTelnet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FF_PE_UPI_R_ver4_Horizontal/QTelnet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QTelnet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QTelnet_t {
    QByteArrayData data[13];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTelnet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTelnet_t qt_meta_stringdata_QTelnet = {
    {
QT_MOC_LITERAL(0, 0, 7), // "QTelnet"
QT_MOC_LITERAL(1, 8, 7), // "newData"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 11), // "const char*"
QT_MOC_LITERAL(4, 29, 4), // "buff"
QT_MOC_LITERAL(5, 34, 3), // "len"
QT_MOC_LITERAL(6, 38, 11), // "endOfRecord"
QT_MOC_LITERAL(7, 50, 9), // "echoLocal"
QT_MOC_LITERAL(8, 60, 4), // "echo"
QT_MOC_LITERAL(9, 65, 11), // "socketError"
QT_MOC_LITERAL(10, 77, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(11, 106, 3), // "err"
QT_MOC_LITERAL(12, 110, 11) // "onReadyRead"

    },
    "QTelnet\0newData\0\0const char*\0buff\0len\0"
    "endOfRecord\0echoLocal\0echo\0socketError\0"
    "QAbstractSocket::SocketError\0err\0"
    "onReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTelnet[] = {

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
       1,    2,   39,    2, 0x06 /* Public */,
       6,    0,   44,    2, 0x06 /* Public */,
       7,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   48,    2, 0x08 /* Private */,
      12,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,

       0        // eod
};

void QTelnet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QTelnet *_t = static_cast<QTelnet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newData((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->endOfRecord(); break;
        case 2: _t->echoLocal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->socketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->onReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QTelnet::*_t)(const char * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QTelnet::newData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QTelnet::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QTelnet::endOfRecord)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QTelnet::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QTelnet::echoLocal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject QTelnet::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_QTelnet.data,
      qt_meta_data_QTelnet,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QTelnet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTelnet::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QTelnet.stringdata0))
        return static_cast<void*>(const_cast< QTelnet*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int QTelnet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QTelnet::newData(const char * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QTelnet::endOfRecord()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void QTelnet::echoLocal(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
