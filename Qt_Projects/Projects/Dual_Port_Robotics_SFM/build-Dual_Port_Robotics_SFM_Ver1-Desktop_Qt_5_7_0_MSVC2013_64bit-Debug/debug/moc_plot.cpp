/****************************************************************************
** Meta object code from reading C++ file 'plot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Dual_Port_Robotics_SFM_Ver1/plot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Plot_t {
    QByteArrayData data[21];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Plot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Plot_t qt_meta_stringdata_Plot = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Plot"
QT_MOC_LITERAL(1, 5, 11), // "UpdateCurve"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 6), // "float*"
QT_MOC_LITERAL(4, 25, 4), // "y_pt"
QT_MOC_LITERAL(5, 30, 5), // "Title"
QT_MOC_LITERAL(6, 36, 4), // "x_pt"
QT_MOC_LITERAL(7, 41, 16), // "updateVertMarker"
QT_MOC_LITERAL(8, 58, 9), // "markerPos"
QT_MOC_LITERAL(9, 68, 15), // "updateAxisScale"
QT_MOC_LITERAL(10, 84, 8), // "initPlot"
QT_MOC_LITERAL(11, 93, 13), // "decalreMemory"
QT_MOC_LITERAL(12, 107, 17), // "setPlotAttributes"
QT_MOC_LITERAL(13, 125, 5), // "title"
QT_MOC_LITERAL(14, 131, 6), // "yTitle"
QT_MOC_LITERAL(15, 138, 4), // "yMin"
QT_MOC_LITERAL(16, 143, 4), // "yMax"
QT_MOC_LITERAL(17, 148, 6), // "xTitle"
QT_MOC_LITERAL(18, 155, 4), // "xMin"
QT_MOC_LITERAL(19, 160, 4), // "xMax"
QT_MOC_LITERAL(20, 165, 10) // "UpdatePlot"

    },
    "Plot\0UpdateCurve\0\0float*\0y_pt\0Title\0"
    "x_pt\0updateVertMarker\0markerPos\0"
    "updateAxisScale\0initPlot\0decalreMemory\0"
    "setPlotAttributes\0title\0yTitle\0yMin\0"
    "yMax\0xTitle\0xMin\0xMax\0UpdatePlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Plot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x0a /* Public */,
       1,    2,   66,    2, 0x2a /* Public | MethodCloned */,
       1,    1,   71,    2, 0x2a /* Public | MethodCloned */,
       7,    1,   74,    2, 0x0a /* Public */,
       9,    0,   77,    2, 0x0a /* Public */,
      10,    0,   78,    2, 0x0a /* Public */,
      11,    0,   79,    2, 0x0a /* Public */,
      12,    7,   80,    2, 0x0a /* Public */,
      20,    0,   95,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, 0x80000000 | 3,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::Double, QMetaType::Double,   13,   14,   15,   16,   17,   18,   19,
    QMetaType::Void,

       0        // eod
};

void Plot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Plot *_t = static_cast<Plot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->UpdateCurve((*reinterpret_cast< float*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< float*(*)>(_a[3]))); break;
        case 1: _t->UpdateCurve((*reinterpret_cast< float*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->UpdateCurve((*reinterpret_cast< float*(*)>(_a[1]))); break;
        case 3: _t->updateVertMarker((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->updateAxisScale(); break;
        case 5: _t->initPlot(); break;
        case 6: _t->decalreMemory(); break;
        case 7: _t->setPlotAttributes((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7]))); break;
        case 8: _t->UpdatePlot(); break;
        default: ;
        }
    }
}

const QMetaObject Plot::staticMetaObject = {
    { &QwtPlot::staticMetaObject, qt_meta_stringdata_Plot.data,
      qt_meta_data_Plot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Plot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Plot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Plot.stringdata0))
        return static_cast<void*>(const_cast< Plot*>(this));
    return QwtPlot::qt_metacast(_clname);
}

int Plot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
