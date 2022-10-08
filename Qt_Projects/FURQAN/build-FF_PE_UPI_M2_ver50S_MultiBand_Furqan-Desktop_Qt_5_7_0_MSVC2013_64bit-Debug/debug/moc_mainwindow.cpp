/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../FF_PE_UPI_50S_MultiBand/mainwindow.h"
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
    QByteArrayData data[72];
    char stringdata0[1719];
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
QT_MOC_LITERAL(7, 166, 27), // "on_pushButtonDaqSet_clicked"
QT_MOC_LITERAL(8, 194, 33), // "on_pushButtonLdvAutoFocus_cli..."
QT_MOC_LITERAL(9, 228, 37), // "on_lineEditScanHeight_editing..."
QT_MOC_LITERAL(10, 266, 36), // "on_lineEditScanWidth_editingF..."
QT_MOC_LITERAL(11, 303, 15), // "playPauseResult"
QT_MOC_LITERAL(12, 319, 4), // "play"
QT_MOC_LITERAL(13, 324, 22), // "playPauseResultSubband"
QT_MOC_LITERAL(14, 347, 10), // "incrSlider"
QT_MOC_LITERAL(15, 358, 17), // "incrSliderSubband"
QT_MOC_LITERAL(16, 376, 36), // "on_enumPlaySpeed_currentIndex..."
QT_MOC_LITERAL(17, 413, 5), // "index"
QT_MOC_LITERAL(18, 419, 17), // "scanFinished_main"
QT_MOC_LITERAL(19, 437, 34), // "on_pushButtonProcessFilter_cl..."
QT_MOC_LITERAL(20, 472, 17), // "updateVtwamInputs"
QT_MOC_LITERAL(21, 490, 5), // "press"
QT_MOC_LITERAL(22, 496, 7), // "frValue"
QT_MOC_LITERAL(23, 504, 33), // "on_pushButtonProcessVtwam_cli..."
QT_MOC_LITERAL(24, 538, 43), // "on_enumPlaySpeedSubband_curre..."
QT_MOC_LITERAL(25, 582, 28), // "on_pushButtonSetpos_released"
QT_MOC_LITERAL(26, 611, 39), // "on_pushButtonLaserConfigPrfCu..."
QT_MOC_LITERAL(27, 651, 25), // "on_pushButtonInit_clicked"
QT_MOC_LITERAL(28, 677, 30), // "on_groupBoxFilterStep2_toggled"
QT_MOC_LITERAL(29, 708, 4), // "arg1"
QT_MOC_LITERAL(30, 713, 30), // "on_groupBoxFilterStep1_toggled"
QT_MOC_LITERAL(31, 744, 31), // "on_lineEditXpos_editingFinished"
QT_MOC_LITERAL(32, 776, 31), // "on_lineEditZPos_editingFinished"
QT_MOC_LITERAL(33, 808, 30), // "on_radioButtonSubband1_toggled"
QT_MOC_LITERAL(34, 839, 7), // "checked"
QT_MOC_LITERAL(35, 847, 30), // "on_radioButtonSubband2_toggled"
QT_MOC_LITERAL(36, 878, 30), // "on_radioButtonSubband3_toggled"
QT_MOC_LITERAL(37, 909, 33), // "on_pushButtonLaserControl_tog..."
QT_MOC_LITERAL(38, 943, 4), // "Stop"
QT_MOC_LITERAL(39, 948, 13), // "deviceConnect"
QT_MOC_LITERAL(40, 962, 35), // "on_pushButtonLdvAutoFocus_2_c..."
QT_MOC_LITERAL(41, 998, 28), // "on_pushButtonCapture_clicked"
QT_MOC_LITERAL(42, 1027, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(43, 1052, 13), // "setlabelFrame"
QT_MOC_LITERAL(44, 1066, 11), // "frameNumber"
QT_MOC_LITERAL(45, 1078, 20), // "setlabelFrameSubband"
QT_MOC_LITERAL(46, 1099, 11), // "saveSetting"
QT_MOC_LITERAL(47, 1111, 11), // "defaultFile"
QT_MOC_LITERAL(48, 1123, 11), // "loadSetting"
QT_MOC_LITERAL(49, 1135, 14), // "initDoneMsgBox"
QT_MOC_LITERAL(50, 1150, 25), // "on_pushButtonQuit_clicked"
QT_MOC_LITERAL(51, 1176, 20), // "settingBeforeNewScan"
QT_MOC_LITERAL(52, 1197, 28), // "on_pushButtonEnlarge_clicked"
QT_MOC_LITERAL(53, 1226, 14), // "resizeToNormal"
QT_MOC_LITERAL(54, 1241, 15), // "populatePrfList"
QT_MOC_LITERAL(55, 1257, 13), // "intervalIndex"
QT_MOC_LITERAL(56, 1271, 17), // "hiLaserPwrWarning"
QT_MOC_LITERAL(57, 1289, 37), // "on_actionPulse_Energy_Table_t..."
QT_MOC_LITERAL(58, 1327, 34), // "on_pushButtonVtwamAddRange_cl..."
QT_MOC_LITERAL(59, 1362, 37), // "on_pushButtonVtwamClearRanges..."
QT_MOC_LITERAL(60, 1400, 14), // "printVtwamInfo"
QT_MOC_LITERAL(61, 1415, 30), // "on_pushButtonDaqConfig_pressed"
QT_MOC_LITERAL(62, 1446, 34), // "on_checkBoxEnableMultiBand_to..."
QT_MOC_LITERAL(63, 1481, 47), // "on_enumMultiBandSettingLev1_c..."
QT_MOC_LITERAL(64, 1529, 33), // "on_pushButtonFilterConfig_pre..."
QT_MOC_LITERAL(65, 1563, 16), // "setSettingStruct"
QT_MOC_LITERAL(66, 1580, 18), // "UpdateDaqParStruct"
QT_MOC_LITERAL(67, 1599, 18), // "windowLayOutUpdate"
QT_MOC_LITERAL(68, 1618, 32), // "on_pushButtonProcessXCor_clicked"
QT_MOC_LITERAL(69, 1651, 40), // "on_actionBand_Divider_Scenari..."
QT_MOC_LITERAL(70, 1692, 12), // "loadDataMain"
QT_MOC_LITERAL(71, 1705, 13) // "printDataSpec"

    },
    "MainWindow\0postProcessingFilteringRequired\0"
    "\0postProcessingVtwamRequired\0"
    "updateProgressBar_mainwindowSlot\0"
    "endProgressBar_mainwindowSlot\0"
    "updateStatusBar_mainwindowSlot\0"
    "on_pushButtonDaqSet_clicked\0"
    "on_pushButtonLdvAutoFocus_clicked\0"
    "on_lineEditScanHeight_editingFinished\0"
    "on_lineEditScanWidth_editingFinished\0"
    "playPauseResult\0play\0playPauseResultSubband\0"
    "incrSlider\0incrSliderSubband\0"
    "on_enumPlaySpeed_currentIndexChanged\0"
    "index\0scanFinished_main\0"
    "on_pushButtonProcessFilter_clicked\0"
    "updateVtwamInputs\0press\0frValue\0"
    "on_pushButtonProcessVtwam_clicked\0"
    "on_enumPlaySpeedSubband_currentIndexChanged\0"
    "on_pushButtonSetpos_released\0"
    "on_pushButtonLaserConfigPrfCurr_clicked\0"
    "on_pushButtonInit_clicked\0"
    "on_groupBoxFilterStep2_toggled\0arg1\0"
    "on_groupBoxFilterStep1_toggled\0"
    "on_lineEditXpos_editingFinished\0"
    "on_lineEditZPos_editingFinished\0"
    "on_radioButtonSubband1_toggled\0checked\0"
    "on_radioButtonSubband2_toggled\0"
    "on_radioButtonSubband3_toggled\0"
    "on_pushButtonLaserControl_toggled\0"
    "Stop\0deviceConnect\0"
    "on_pushButtonLdvAutoFocus_2_clicked\0"
    "on_pushButtonCapture_clicked\0"
    "on_actionAbout_triggered\0setlabelFrame\0"
    "frameNumber\0setlabelFrameSubband\0"
    "saveSetting\0defaultFile\0loadSetting\0"
    "initDoneMsgBox\0on_pushButtonQuit_clicked\0"
    "settingBeforeNewScan\0on_pushButtonEnlarge_clicked\0"
    "resizeToNormal\0populatePrfList\0"
    "intervalIndex\0hiLaserPwrWarning\0"
    "on_actionPulse_Energy_Table_triggered\0"
    "on_pushButtonVtwamAddRange_clicked\0"
    "on_pushButtonVtwamClearRanges_clicked\0"
    "printVtwamInfo\0on_pushButtonDaqConfig_pressed\0"
    "on_checkBoxEnableMultiBand_toggled\0"
    "on_enumMultiBandSettingLev1_currentIndexChanged\0"
    "on_pushButtonFilterConfig_pressed\0"
    "setSettingStruct\0UpdateDaqParStruct\0"
    "windowLayOutUpdate\0on_pushButtonProcessXCor_clicked\0"
    "on_actionBand_Divider_Scenario_triggered\0"
    "loadDataMain\0printDataSpec"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      63,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  329,    2, 0x06 /* Public */,
       3,    1,  330,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,  333,    2, 0x08 /* Private */,
       5,    0,  336,    2, 0x08 /* Private */,
       6,    1,  337,    2, 0x08 /* Private */,
       7,    0,  340,    2, 0x08 /* Private */,
       8,    0,  341,    2, 0x08 /* Private */,
       9,    0,  342,    2, 0x08 /* Private */,
      10,    0,  343,    2, 0x08 /* Private */,
      11,    1,  344,    2, 0x08 /* Private */,
      13,    1,  347,    2, 0x08 /* Private */,
      14,    0,  350,    2, 0x08 /* Private */,
      15,    0,  351,    2, 0x08 /* Private */,
      16,    1,  352,    2, 0x08 /* Private */,
      18,    0,  355,    2, 0x08 /* Private */,
      19,    0,  356,    2, 0x08 /* Private */,
      20,    2,  357,    2, 0x08 /* Private */,
      23,    0,  362,    2, 0x08 /* Private */,
      24,    1,  363,    2, 0x08 /* Private */,
      25,    0,  366,    2, 0x08 /* Private */,
      26,    0,  367,    2, 0x08 /* Private */,
      27,    0,  368,    2, 0x08 /* Private */,
      28,    1,  369,    2, 0x08 /* Private */,
      30,    1,  372,    2, 0x08 /* Private */,
      31,    0,  375,    2, 0x08 /* Private */,
      32,    0,  376,    2, 0x08 /* Private */,
      33,    1,  377,    2, 0x08 /* Private */,
      35,    1,  380,    2, 0x08 /* Private */,
      36,    1,  383,    2, 0x08 /* Private */,
      37,    1,  386,    2, 0x08 /* Private */,
      38,    0,  389,    2, 0x08 /* Private */,
      39,    0,  390,    2, 0x08 /* Private */,
      40,    0,  391,    2, 0x08 /* Private */,
      41,    0,  392,    2, 0x08 /* Private */,
      42,    0,  393,    2, 0x08 /* Private */,
      43,    1,  394,    2, 0x08 /* Private */,
      45,    1,  397,    2, 0x08 /* Private */,
      46,    1,  400,    2, 0x08 /* Private */,
      46,    0,  403,    2, 0x28 /* Private | MethodCloned */,
      48,    1,  404,    2, 0x08 /* Private */,
      48,    0,  407,    2, 0x28 /* Private | MethodCloned */,
      49,    0,  408,    2, 0x08 /* Private */,
      50,    0,  409,    2, 0x08 /* Private */,
      51,    0,  410,    2, 0x08 /* Private */,
      52,    0,  411,    2, 0x08 /* Private */,
      53,    0,  412,    2, 0x08 /* Private */,
      54,    1,  413,    2, 0x08 /* Private */,
      56,    0,  416,    2, 0x08 /* Private */,
      57,    0,  417,    2, 0x08 /* Private */,
      58,    0,  418,    2, 0x08 /* Private */,
      59,    0,  419,    2, 0x08 /* Private */,
      60,    0,  420,    2, 0x08 /* Private */,
      61,    0,  421,    2, 0x08 /* Private */,
      62,    1,  422,    2, 0x08 /* Private */,
      63,    1,  425,    2, 0x08 /* Private */,
      64,    0,  428,    2, 0x08 /* Private */,
      65,    0,  429,    2, 0x08 /* Private */,
      66,    0,  430,    2, 0x08 /* Private */,
      67,    1,  431,    2, 0x08 /* Private */,
      68,    0,  434,    2, 0x08 /* Private */,
      69,    0,  435,    2, 0x08 /* Private */,
      70,    1,  436,    2, 0x08 /* Private */,
      71,    0,  439,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,   21,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   44,
    QMetaType::Void, QMetaType::Int,   44,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::Bool,   47,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   55,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
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
        case 5: _t->on_pushButtonDaqSet_clicked(); break;
        case 6: _t->on_pushButtonLdvAutoFocus_clicked(); break;
        case 7: _t->on_lineEditScanHeight_editingFinished(); break;
        case 8: _t->on_lineEditScanWidth_editingFinished(); break;
        case 9: _t->playPauseResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->playPauseResultSubband((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->incrSlider(); break;
        case 12: _t->incrSliderSubband(); break;
        case 13: _t->on_enumPlaySpeed_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->scanFinished_main(); break;
        case 15: _t->on_pushButtonProcessFilter_clicked(); break;
        case 16: _t->updateVtwamInputs((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->on_pushButtonProcessVtwam_clicked(); break;
        case 18: _t->on_enumPlaySpeedSubband_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_pushButtonSetpos_released(); break;
        case 20: _t->on_pushButtonLaserConfigPrfCurr_clicked(); break;
        case 21: _t->on_pushButtonInit_clicked(); break;
        case 22: _t->on_groupBoxFilterStep2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->on_groupBoxFilterStep1_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->on_lineEditXpos_editingFinished(); break;
        case 25: _t->on_lineEditZPos_editingFinished(); break;
        case 26: _t->on_radioButtonSubband1_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->on_radioButtonSubband2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->on_radioButtonSubband3_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->on_pushButtonLaserControl_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->Stop(); break;
        case 31: _t->deviceConnect(); break;
        case 32: _t->on_pushButtonLdvAutoFocus_2_clicked(); break;
        case 33: _t->on_pushButtonCapture_clicked(); break;
        case 34: _t->on_actionAbout_triggered(); break;
        case 35: _t->setlabelFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->setlabelFrameSubband((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->saveSetting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->saveSetting(); break;
        case 39: { bool _r = _t->loadSetting((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 40: { bool _r = _t->loadSetting();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 41: _t->initDoneMsgBox(); break;
        case 42: _t->on_pushButtonQuit_clicked(); break;
        case 43: _t->settingBeforeNewScan(); break;
        case 44: _t->on_pushButtonEnlarge_clicked(); break;
        case 45: _t->resizeToNormal(); break;
        case 46: _t->populatePrfList((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->hiLaserPwrWarning(); break;
        case 48: _t->on_actionPulse_Energy_Table_triggered(); break;
        case 49: _t->on_pushButtonVtwamAddRange_clicked(); break;
        case 50: _t->on_pushButtonVtwamClearRanges_clicked(); break;
        case 51: _t->printVtwamInfo(); break;
        case 52: _t->on_pushButtonDaqConfig_pressed(); break;
        case 53: _t->on_checkBoxEnableMultiBand_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 54: _t->on_enumMultiBandSettingLev1_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 55: _t->on_pushButtonFilterConfig_pressed(); break;
        case 56: _t->setSettingStruct(); break;
        case 57: _t->UpdateDaqParStruct(); break;
        case 58: _t->windowLayOutUpdate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 59: _t->on_pushButtonProcessXCor_clicked(); break;
        case 60: _t->on_actionBand_Divider_Scenario_triggered(); break;
        case 61: _t->loadDataMain((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 62: _t->printDataSpec(); break;
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
        if (_id < 63)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 63;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 63)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 63;
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
