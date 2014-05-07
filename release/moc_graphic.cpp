/****************************************************************************
** Meta object code from reading C++ file 'graphic.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../graphic.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Graphic[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,    9,    8,    8, 0x0a,
      56,   52,    8,    8, 0x0a,
      85,    8,    8,    8, 0x0a,
     101,    8,    8,    8, 0x0a,
     116,    8,    8,    8, 0x0a,
     133,    8,    8,    8, 0x0a,
     145,    8,    8,    8, 0x0a,
     160,    8,    8,    8, 0x08,
     180,  176,    8,    8, 0x08,
     206,  198,    8,    8, 0x08,
     235,    8,    8,    8, 0x08,
     262,    8,    8,    8, 0x08,
     279,  276,    8,    8, 0x08,
     300,  276,    8,    8, 0x08,
     320,  276,    8,    8, 0x08,
     339,    8,    8,    8, 0x08,
     363,    8,    8,    8, 0x08,
     384,    8,    8,    8, 0x08,
     419,  405,    8,    8, 0x08,
     468,  457,    8,    8, 0x08,
     492,    8,    8,    8, 0x08,
     522,    8,    8,    8, 0x08,
     555,  546,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Graphic[] = {
    "Graphic\0\0cursor_position\0"
    "setTimeLineCursor(quint32)\0qdt\0"
    "setTimeLineCursor(QDateTime)\0"
    "updateGraphic()\0updateSlider()\0"
    "updateMiniplot()\0clearData()\0"
    "refresh_plot()\0timer2Timeout()\0pos\0"
    "x_dragged(qint16)\0item,on\0"
    "showCurve(QwtPlotItem*,bool)\0"
    "contextMenuClicked(QPoint)\0moved(QPoint)\0"
    "on\0setGridVisible(bool)\0setDragModeOn(bool)\0"
    "setTriggerOn(bool)\0setPickerActivate(bool)\0"
    "rescaleAxisX(double)\0rescaleAxisY(double)\0"
    "graf_n,val,ok\0gotCommandAnswer(quint8,quint32,bool)\0"
    "graf_n,val\0newValue(quint8,double)\0"
    "on_btnGoToBeginning_clicked()\0"
    "on_btnGoToEnd_clicked()\0position\0"
    "on_slDataSlider_sliderMoved(int)\0"
};

void Graphic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Graphic *_t = static_cast<Graphic *>(_o);
        switch (_id) {
        case 0: _t->setTimeLineCursor((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 1: _t->setTimeLineCursor((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 2: _t->updateGraphic(); break;
        case 3: _t->updateSlider(); break;
        case 4: _t->updateMiniplot(); break;
        case 5: _t->clearData(); break;
        case 6: _t->refresh_plot(); break;
        case 7: _t->timer2Timeout(); break;
        case 8: _t->x_dragged((*reinterpret_cast< qint16(*)>(_a[1]))); break;
        case 9: _t->showCurve((*reinterpret_cast< QwtPlotItem*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->contextMenuClicked((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 11: _t->moved((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 12: _t->setGridVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->setDragModeOn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->setTriggerOn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->setPickerActivate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->rescaleAxisX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->rescaleAxisY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->gotCommandAnswer((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 19: _t->newValue((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 20: _t->on_btnGoToBeginning_clicked(); break;
        case 21: _t->on_btnGoToEnd_clicked(); break;
        case 22: _t->on_slDataSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Graphic::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Graphic::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Graphic,
      qt_meta_data_Graphic, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Graphic::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Graphic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Graphic::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Graphic))
        return static_cast<void*>(const_cast< Graphic*>(this));
    if (!strcmp(_clname, "Ui::GraphicDlg"))
        return static_cast< Ui::GraphicDlg*>(const_cast< Graphic*>(this));
    return QWidget::qt_metacast(_clname);
}

int Graphic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
