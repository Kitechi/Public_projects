/****************************************************************************
** Meta object code from reading C++ file 'spectrogram.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../2-Axis_SFM_ver6/spectrogram.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spectrogram.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_spectrogram_t {
    QByteArrayData data[32];
    char stringdata0[348];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_spectrogram_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_spectrogram_t qt_meta_stringdata_spectrogram = {
    {
QT_MOC_LITERAL(0, 0, 11), // "spectrogram"
QT_MOC_LITERAL(1, 12, 11), // "pointToPlot"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 20), // "SelectedImpingePoint"
QT_MOC_LITERAL(4, 46, 11), // "pointToMove"
QT_MOC_LITERAL(5, 58, 4), // "xPos"
QT_MOC_LITERAL(6, 63, 4), // "yPos"
QT_MOC_LITERAL(7, 68, 10), // "placeSlave"
QT_MOC_LITERAL(8, 79, 7), // "leftPos"
QT_MOC_LITERAL(9, 87, 6), // "topPos"
QT_MOC_LITERAL(10, 94, 11), // "selectPoint"
QT_MOC_LITERAL(11, 106, 3), // "Pos"
QT_MOC_LITERAL(12, 110, 10), // "updateData"
QT_MOC_LITERAL(13, 121, 12), // "framePointer"
QT_MOC_LITERAL(14, 134, 5), // "title"
QT_MOC_LITERAL(15, 140, 9), // "isIntData"
QT_MOC_LITERAL(16, 150, 12), // "updateAxisXY"
QT_MOC_LITERAL(17, 163, 13), // "enlargeFactor"
QT_MOC_LITERAL(18, 177, 12), // "setIntensity"
QT_MOC_LITERAL(19, 190, 3), // "min"
QT_MOC_LITERAL(20, 194, 3), // "max"
QT_MOC_LITERAL(21, 198, 16), // "setIntensityDial"
QT_MOC_LITERAL(22, 215, 9), // "dialValue"
QT_MOC_LITERAL(23, 225, 8), // "savePlot"
QT_MOC_LITERAL(24, 234, 13), // "outfolderpath"
QT_MOC_LITERAL(25, 248, 9), // "SaveMovie"
QT_MOC_LITERAL(26, 258, 13), // "getPlotPixmap"
QT_MOC_LITERAL(27, 272, 8), // "frameNum"
QT_MOC_LITERAL(28, 281, 17), // "setMovieImageSize"
QT_MOC_LITERAL(29, 299, 14), // "placeSlaveslot"
QT_MOC_LITERAL(30, 314, 19), // "toggleUWPIGreyScale"
QT_MOC_LITERAL(31, 334, 13) // "isGreyForUWPI"

    },
    "spectrogram\0pointToPlot\0\0SelectedImpingePoint\0"
    "pointToMove\0xPos\0yPos\0placeSlave\0"
    "leftPos\0topPos\0selectPoint\0Pos\0"
    "updateData\0framePointer\0title\0isIntData\0"
    "updateAxisXY\0enlargeFactor\0setIntensity\0"
    "min\0max\0setIntensityDial\0dialValue\0"
    "savePlot\0outfolderpath\0SaveMovie\0"
    "getPlotPixmap\0frameNum\0setMovieImageSize\0"
    "placeSlaveslot\0toggleUWPIGreyScale\0"
    "isGreyForUWPI"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_spectrogram[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,
       4,    2,  112,    2, 0x06 /* Public */,
       7,    2,  117,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  122,    2, 0x0a /* Public */,
      12,    3,  125,    2, 0x0a /* Public */,
      12,    2,  132,    2, 0x2a /* Public | MethodCloned */,
      12,    1,  137,    2, 0x2a /* Public | MethodCloned */,
      16,    1,  140,    2, 0x0a /* Public */,
      16,    0,  143,    2, 0x2a /* Public | MethodCloned */,
      18,    2,  144,    2, 0x0a /* Public */,
      21,    1,  149,    2, 0x0a /* Public */,
      23,    1,  152,    2, 0x0a /* Public */,
      23,    0,  155,    2, 0x2a /* Public | MethodCloned */,
      25,    1,  156,    2, 0x0a /* Public */,
      25,    0,  159,    2, 0x2a /* Public | MethodCloned */,
      26,    1,  160,    2, 0x0a /* Public */,
      28,    0,  163,    2, 0x0a /* Public */,
      29,    2,  164,    2, 0x0a /* Public */,
      30,    1,  169,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,   11,
    QMetaType::Void, QMetaType::VoidStar, QMetaType::QString, QMetaType::Bool,   13,   14,   15,
    QMetaType::Void, QMetaType::VoidStar, QMetaType::QString,   13,   14,
    QMetaType::Void, QMetaType::VoidStar,   13,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   20,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void,
    QMetaType::QPixmap, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Bool,   31,

       0        // eod
};

void spectrogram::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        spectrogram *_t = static_cast<spectrogram *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pointToPlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->pointToMove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->placeSlave((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->selectPoint((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 4: _t->updateData((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 5: _t->updateData((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->updateData((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 7: _t->updateAxisXY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->updateAxisXY(); break;
        case 9: _t->setIntensity((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->setIntensityDial((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->savePlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->savePlot(); break;
        case 13: _t->SaveMovie((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->SaveMovie(); break;
        case 15: { QPixmap _r = _t->getPlotPixmap((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 16: _t->setMovieImageSize(); break;
        case 17: _t->placeSlaveslot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: _t->toggleUWPIGreyScale((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (spectrogram::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&spectrogram::pointToPlot)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (spectrogram::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&spectrogram::pointToMove)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (spectrogram::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&spectrogram::placeSlave)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject spectrogram::staticMetaObject = {
    { &QwtPlot::staticMetaObject, qt_meta_stringdata_spectrogram.data,
      qt_meta_data_spectrogram,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *spectrogram::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *spectrogram::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_spectrogram.stringdata0))
        return static_cast<void*>(const_cast< spectrogram*>(this));
    return QwtPlot::qt_metacast(_clname);
}

int spectrogram::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void spectrogram::pointToPlot(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void spectrogram::pointToMove(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void spectrogram::placeSlave(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
