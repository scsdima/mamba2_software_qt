/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   12,   11,   11, 0x08,
      37,   12,   11,   11, 0x08,
      72,   59,   11,   11, 0x08,
     112,   11,   11,   11, 0x08,
     133,   11,   11,   11, 0x08,
     165,  160,   11,   11, 0x08,
     185,  160,   11,   11, 0x08,
     213,   11,   11,   11, 0x08,
     231,   11,   11,   11, 0x08,
     257,   11,   11,   11, 0x08,
     278,   11,   11,   11, 0x08,
     307,  299,   11,   11, 0x08,
     332,   11,   11,   11, 0x08,
     348,   11,   11,   11, 0x08,
     364,   11,   11,   11, 0x08,
     381,   11,   11,   11, 0x08,
     394,   11,   11,   11, 0x08,
     410,   11,   11,   11, 0x08,
     432,   11,   11,   11, 0x08,
     451,   11,   11,   11, 0x08,
     474,   11,   11,   11, 0x08,
     496,   11,   11,   11, 0x08,
     524,   11,   11,   11, 0x08,
     548,   11,   11,   11, 0x08,
     576,   11,   11,   11, 0x08,
     610,  604,   11,   11, 0x08,
     650,  604,   11,   11, 0x08,
     689,   11,   11,   11, 0x08,
     721,   11,   11,   11, 0x08,
     747,   11,   11,   11, 0x08,
     771,   11,   11,   11, 0x08,
     797,   11,   11,   11, 0x08,
     823,   11,   11,   11, 0x08,
     851,  604,   11,   11, 0x08,
     885,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on\0slot_ActivityTX(bool)\0"
    "slot_ActivityRX(bool)\0cmd,cmd_p,ok\0"
    "slot_CommandAnswer(quint8,quint32,bool)\0"
    "slot_ApplyTriggers()\0slot_TamperSourceClicked()\0"
    "text\0slot_Print(QString)\0"
    "slot_PrintTestMode(QString)\0"
    "slot_PopulateUi()\0slot_completedOperation()\0"
    "slot_UpdateUIState()\0slot_runStream(bool)\0"
    "checked\0slot_ConnectSensor(bool)\0"
    "slot_SaveFile()\0slot_LoadFile()\0"
    "slot_ClearData()\0slot_About()\0"
    "slot_Settings()\0slot_SetSensitivity()\0"
    "slot_SetProfileN()\0slot_shutdownSession()\0"
    "slot_UpdateFirmware()\0on_remove_cfg_btn_clicked()\0"
    "on_tofile_btn_clicked()\0"
    "on_defsetting_btn_clicked()\0"
    "on_fromdevice_btn_clicked()\0index\0"
    "on_pwrtrig_cmb_currentIndexChanged(int)\0"
    "on_didown_cmb_currentIndexChanged(int)\0"
    "on_acc_sens_sl_sliderReleased()\0"
    "on_pushButton_5_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_sendtxtcmd_btn_clicked()\0"
    "on_alarm_lst_clicked(QModelIndex)\0"
    "on_btnApplySavedConfig_clicked()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->slot_ActivityTX((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->slot_ActivityRX((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->slot_CommandAnswer((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->slot_ApplyTriggers(); break;
        case 4: _t->slot_TamperSourceClicked(); break;
        case 5: _t->slot_Print((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->slot_PrintTestMode((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->slot_PopulateUi(); break;
        case 8: _t->slot_completedOperation(); break;
        case 9: _t->slot_UpdateUIState(); break;
        case 10: _t->slot_runStream((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->slot_ConnectSensor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->slot_SaveFile(); break;
        case 13: _t->slot_LoadFile(); break;
        case 14: _t->slot_ClearData(); break;
        case 15: _t->slot_About(); break;
        case 16: _t->slot_Settings(); break;
        case 17: _t->slot_SetSensitivity(); break;
        case 18: _t->slot_SetProfileN(); break;
        case 19: _t->slot_shutdownSession(); break;
        case 20: _t->slot_UpdateFirmware(); break;
        case 21: _t->on_remove_cfg_btn_clicked(); break;
        case 22: _t->on_tofile_btn_clicked(); break;
        case 23: _t->on_defsetting_btn_clicked(); break;
        case 24: _t->on_fromdevice_btn_clicked(); break;
        case 25: _t->on_pwrtrig_cmb_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_didown_cmb_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_acc_sens_sl_sliderReleased(); break;
        case 28: _t->on_pushButton_5_clicked(); break;
        case 29: _t->on_pushButton_clicked(); break;
        case 30: _t->on_pushButton_3_clicked(); break;
        case 31: _t->on_pushButton_2_clicked(); break;
        case 32: _t->on_sendtxtcmd_btn_clicked(); break;
        case 33: _t->on_alarm_lst_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 34: _t->on_btnApplySavedConfig_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
