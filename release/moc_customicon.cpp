/****************************************************************************
** Meta object code from reading C++ file 'customicon.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../customicon.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customicon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CustomIcon[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x0a,
      39,   11,   11,   11, 0x0a,
      52,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CustomIcon[] = {
    "CustomIcon\0\0state\0set_state(IconState)\0"
    "set_on(bool)\0set_err(bool)\0"
};

void CustomIcon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CustomIcon *_t = static_cast<CustomIcon *>(_o);
        switch (_id) {
        case 0: _t->set_state((*reinterpret_cast< IconState(*)>(_a[1]))); break;
        case 1: _t->set_on((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->set_err((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CustomIcon::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CustomIcon::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CustomIcon,
      qt_meta_data_CustomIcon, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CustomIcon::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CustomIcon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CustomIcon::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CustomIcon))
        return static_cast<void*>(const_cast< CustomIcon*>(this));
    return QWidget::qt_metacast(_clname);
}

int CustomIcon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
