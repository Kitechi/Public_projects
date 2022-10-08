/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FSM_ver4/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MySlider_t {
    QByteArrayData data[5];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MySlider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MySlider_t qt_meta_stringdata_MySlider = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MySlider"
QT_MOC_LITERAL(1, 9, 14), // "mouseMidButton"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "press"
QT_MOC_LITERAL(4, 31, 10) // "currentVal"

    },
    "MySlider\0mouseMidButton\0\0press\0"
    "currentVal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MySlider[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    3,    4,

       0        // eod
};

void MySlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MySlider *_t = static_cast<MySlider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseMidButton((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MySlider::*_t)(bool , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySlider::mouseMidButton)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MySlider::staticMetaObject = {
    { &QSlider::staticMetaObject, qt_meta_stringdata_MySlider.data,
      qt_meta_data_MySlider,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MySlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MySlider::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MySlider.stringdata0))
        return static_cast<void*>(const_cast< MySlider*>(this));
    return QSlider::qt_metacast(_clname);
}

int MySlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void MySlider::mouseMidButton(bool _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[33];
    char stringdata0[699];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 31), // "postProcessingFilteringRequired"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 27), // "postProcessingVtwamRequired"
QT_MOC_LITERAL(4, 72, 32), // "updateProgressBar_mainwindowSlot"
QT_MOC_LITERAL(5, 105, 29), // "endProgressBar_mainwindowSlot"
QT_MOC_LITERAL(6, 135, 30), // "updateStatusBar_mainwindowSlot"
QT_MOC_LITERAL(7, 166, 15), // "playPauseResult"
QT_MOC_LITERAL(8, 182, 4), // "play"
QT_MOC_LITERAL(9, 187, 10), // "incrSlider"
QT_MOC_LITERAL(10, 198, 36), // "on_enumPlaySpeed_currentIndex..."
QT_MOC_LITERAL(11, 235, 5), // "index"
QT_MOC_LITERAL(12, 241, 34), // "on_pushButtonProcessFilter_cl..."
QT_MOC_LITERAL(13, 276, 17), // "updateVtwamInputs"
QT_MOC_LITERAL(14, 294, 5), // "press"
QT_MOC_LITERAL(15, 300, 7), // "frValue"
QT_MOC_LITERAL(16, 308, 33), // "on_pushButtonProcessVtwam_cli..."
QT_MOC_LITERAL(17, 342, 30), // "on_groupBoxFilterStep2_toggled"
QT_MOC_LITERAL(18, 373, 4), // "arg1"
QT_MOC_LITERAL(19, 378, 30), // "on_groupBoxFilterStep1_toggled"
QT_MOC_LITERAL(20, 409, 28), // "on_pushButtonCapture_clicked"
QT_MOC_LITERAL(21, 438, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(22, 463, 28), // "on_pushButtonEnlarge_clicked"
QT_MOC_LITERAL(23, 492, 14), // "resizeToNormal"
QT_MOC_LITERAL(24, 507, 13), // "printDataSpec"
QT_MOC_LITERAL(25, 521, 10), // "InitAtLoad"
QT_MOC_LITERAL(26, 532, 26), // "on_pushButtonStart_clicked"
QT_MOC_LITERAL(27, 559, 28), // "on_pushButtonSetpos_released"
QT_MOC_LITERAL(28, 588, 41), // "on_enumPnaSweepPoints_current..."
QT_MOC_LITERAL(29, 630, 17), // "scanFinished_main"
QT_MOC_LITERAL(30, 648, 12), // "configN1500A"
QT_MOC_LITERAL(31, 661, 22), // "UpdateSettingParStruct"
QT_MOC_LITERAL(32, 684, 14) // "UpdateMeasType"

    },
    "MainWindow\0postProcessingFilteringRequired\0"
    "\0postProcessingVtwamRequired\0"
    "updateProgressBar_mainwindowSlot\0"
    "endProgressBar_mainwindowSlot\0"
    "updateStatusBar_mainwindowSlot\0"
    "playPauseResult\0play\0incrSlider\0"
    "on_enumPlaySpeed_currentIndexChanged\0"
    "index\0on_pushButtonProcessFilter_clicked\0"
    "updateVtwamInputs\0press\0frValue\0"
    "on_pushButtonProcessVtwam_clicked\0"
    "on_groupBoxFilterStep2_toggled\0arg1\0"
    "on_groupBoxFilterStep1_toggled\0"
    "on_pushButtonCapture_clicked\0"
    "on_actionAbout_triggered\0"
    "on_pushButtonEnlarge_clicked\0"
    "resizeToNormal\0printDataSpec\0InitAtLoad\0"
    "on_pushButtonStart_clicked\0"
    "on_pushButtonSetpos_released\0"
    "on_enumPnaSweepPoints_currentIndexChanged\0"
    "scanFinished_main\0configN1500A\0"
    "UpdateSettingParStruct\0UpdateMeasType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  144,    2, 0x06 /* Public */,
       3,    1,  145,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,  148,    2, 0x08 /* Private */,
       5,    0,  151,    2, 0x08 /* Private */,
       6,    1,  152,    2, 0x08 /* Private */,
       7,    1,  155,    2, 0x08 /* Private */,
       9,    0,  158,    2, 0x08 /* Private */,
      10,    1,  159,    2, 0x08 /* Private */,
      12,    0,  162,    2, 0x08 /* Private */,
      13,    2,  163,    2, 0x08 /* Private */,
      16,    0,  168,    2, 0x08 /* Private */,
      17,    1,  169,    2, 0x08 /* Private */,
      19,    1,  172,    2, 0x08 /* Private */,
      20,    0,  175,    2, 0x08 /* Private */,
      21,    0,  176,    2, 0x08 /* Private */,
      22,    0,  177,    2, 0x08 /* Private */,
      23,    0,  178,    2, 0x08 /* Private */,
      24,    0,  179,    2, 0x08 /* Private */,
      25,    0,  180,    2, 0x08 /* Private */,
      26,    0,  181,    2, 0x08 /* Private */,
      27,    0,  182,    2, 0x08 /* Private */,
      28,    1,  183,    2, 0x08 /* Private */,
      29,    0,  186,    2, 0x08 /* Private */,
      30,    0,  187,    2, 0x08 /* Private */,
      31,    0,  188,    2, 0x08 /* Private */,
      32,    0,  189,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,   14,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->postProcessingFilteringRequired(); break;
        case 1: _t->postProcessingVtwamRequired((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateProgressBar_mainwindowSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->endProgressBar_mainwindowSlot(); break;
        case 4: _t->updateStatusBar_mainwindowSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->playPauseResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->incrSlider(); break;
        case 7: _t->on_enumPlaySpeed_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_pushButtonProcessFilter_clicked(); break;
        case 9: _t->updateVtwamInputs((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->on_pushButtonProcessVtwam_clicked(); break;
        case 11: _t->on_groupBoxFilterStep2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_groupBoxFilterStep1_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_pushButtonCapture_clicked(); break;
        case 14: _t->on_actionAbout_triggered(); break;
        case 15: _t->on_pushButtonEnlarge_clicked(); break;
        case 16: _t->resizeToNormal(); break;
        case 17: _t->printDataSpec(); break;
        case 18: _t->InitAtLoad(); break;
        case 19: _t->on_pushButtonStart_clicked(); break;
        case 20: _t->on_pushButtonSetpos_released(); break;
        case 21: _t->on_enumPnaSweepPoints_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->scanFinished_main(); break;
        case 23: _t->configN1500A(); break;
        case 24: _t->UpdateSettingParStruct(); break;
        case 25: _t->UpdateMeasType(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::postProcessingFilteringRequired)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::postProcessingVtwamRequired)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::postProcessingFilteringRequired()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainWindow::postProcessingVtwamRequired(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
