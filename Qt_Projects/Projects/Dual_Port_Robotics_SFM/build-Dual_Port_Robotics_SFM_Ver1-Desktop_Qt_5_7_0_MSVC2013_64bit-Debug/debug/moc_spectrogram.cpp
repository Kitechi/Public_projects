/****************************************************************************
** Meta object code from reading C++ file 'spectrogram.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Dual_Port_Robotics_SFM_Ver1/spectrogram.h"
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
    QByteArrayData data[25];
    char stringdata0[291];
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
QT_MOC_LITERAL(4, 46, 10), // "placeSlave"
QT_MOC_LITERAL(5, 57, 7), // "leftPos"
QT_MOC_LITERAL(6, 65, 6), // "topPos"
QT_MOC_LITERAL(7, 72, 11), // "selectPoint"
QT_MOC_LITERAL(8, 84, 3), // "Pos"
QT_MOC_LITERAL(9, 88, 10), // "updateData"
QT_MOC_LITERAL(10, 99, 12), // "framePointer"
QT_MOC_LITERAL(11, 112, 5), // "title"
QT_MOC_LITERAL(12, 118, 9), // "isIntData"
QT_MOC_LITERAL(13, 128, 12), // "updateAxisXY"
QT_MOC_LITERAL(14, 141, 13), // "enlargeFactor"
QT_MOC_LITERAL(15, 155, 12), // "setIntensity"
QT_MOC_LITERAL(16, 168, 8), // "savePlot"
QT_MOC_LITERAL(17, 177, 13), // "outfolderpath"
QT_MOC_LITERAL(18, 191, 9), // "SaveMovie"
QT_MOC_LITERAL(19, 201, 13), // "getPlotPixmap"
QT_MOC_LITERAL(20, 215, 8), // "frameNum"
QT_MOC_LITERAL(21, 224, 17), // "setMovieImageSize"
QT_MOC_LITERAL(22, 242, 14), // "placeSlaveslot"
QT_MOC_LITERAL(23, 257, 19), // "toggleUWPIGreyScale"
QT_MOC_LITERAL(24, 277, 13) // "isGreyForUWPI"

    },
    "spectrogram\0pointToPlot\0\0SelectedImpingePoint\0"
    "placeSlave\0leftPos\0topPos\0selectPoint\0"
    "Pos\0updateData\0framePointer\0title\0"
    "isIntData\0updateAxisXY\0enlargeFactor\0"
    "setIntensity\0savePlot\0outfolderpath\0"
    "SaveMovie\0getPlotPixmap\0frameNum\0"
    "setMovieImageSize\0placeSlaveslot\0"
    "toggleUWPIGreyScale\0isGreyForUWPI"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_spectrogram[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    2,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,  107,    2, 0x0a /* Public */,
       9,    3,  110,    2, 0x0a /* Public */,
       9,    2,  117,    2, 0x2a /* Public | MethodCloned */,
       9,    1,  122,    2, 0x2a /* Public | MethodCloned */,
      13,    1,  125,    2, 0x0a /* Public */,
      13,    0,  128,    2, 0x2a /* Public | MethodCloned */,
      15,    1,  129,    2, 0x0a /* Public */,
      16,    1,  132,    2, 0x0a /* Public */,
      16,    0,  135,    2, 0x2a /* Public | MethodCloned */,
      18,    1,  136,    2, 0x0a /* Public */,
      18,    0,  139,    2, 0x2a /* Public | MethodCloned */,
      19,    1,  140,    2, 0x0a /* Public */,
      21,    0,  143,    2, 0x0a /* Public */,
      22,    2,  144,    2, 0x0a /* Public */,
      23,    1,  149,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,    8,
    QMetaType::Void, QMetaType::VoidStar, QMetaType::QString, QMetaType::Bool,   10,   11,   12,
    QMetaType::Void, QMetaType::VoidStar, QMetaType::QString,   10,   11,
    QMetaType::Void, QMetaType::VoidStar,   10,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::QPixmap, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Bool,   24,

       0        // eod
};

void spectrogram::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        spectrogram *_t = static_cast<spectrogram *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pointToPlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->placeSlave((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->selectPoint((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 3: _t->updateData((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: _t->updateData((*reinterpret_cast< void*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->updateData((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 6: _t->updateAxisXY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updateAxisXY(); break;
        case 8: _t->setIntensity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->savePlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->savePlot(); break;
        case 11: _t->SaveMovie((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->SaveMovie(); break;
        case 13: { QPixmap _r = _t->getPlotPixmap((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = _r; }  break;
        case 14: _t->setMovieImageSize(); break;
        case 15: _t->placeSlaveslot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->toggleUWPIGreyScale((*reinterpret_cast< bool(*)>(_a[1]))); break;
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&spectrogram::placeSlave)) {
                *result = 1;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
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
void spectrogram::placeSlave(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
