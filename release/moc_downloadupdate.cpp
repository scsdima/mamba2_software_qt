/****************************************************************************
** Meta object code from reading C++ file 'downloadupdate.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../downloadupdate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloadupdate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AbstractDownloadUpdate[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   23,   23,   23, 0x0a,
      68,   23,   23,   23, 0x0a,
      90,   88,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AbstractDownloadUpdate[] = {
    "AbstractDownloadUpdate\0\0"
    "informationText(QString)\0slot_startUpdate()\0"
    "slot_cancelUpdate()\0,\0"
    "progressBarChanged(qint64,qint64)\0"
};

void AbstractDownloadUpdate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AbstractDownloadUpdate *_t = static_cast<AbstractDownloadUpdate *>(_o);
        switch (_id) {
        case 0: _t->informationText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slot_startUpdate(); break;
        case 2: _t->slot_cancelUpdate(); break;
        case 3: _t->progressBarChanged((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AbstractDownloadUpdate::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AbstractDownloadUpdate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AbstractDownloadUpdate,
      qt_meta_data_AbstractDownloadUpdate, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AbstractDownloadUpdate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AbstractDownloadUpdate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AbstractDownloadUpdate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AbstractDownloadUpdate))
        return static_cast<void*>(const_cast< AbstractDownloadUpdate*>(this));
    return QObject::qt_metacast(_clname);
}

int AbstractDownloadUpdate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AbstractDownloadUpdate::informationText(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_DownloadByHttp[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      39,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DownloadByHttp[] = {
    "DownloadByHttp\0\0http_commandFinished()\0"
    "http_readyRead()\0"
};

void DownloadByHttp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DownloadByHttp *_t = static_cast<DownloadByHttp *>(_o);
        switch (_id) {
        case 0: _t->http_commandFinished(); break;
        case 1: _t->http_readyRead(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DownloadByHttp::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DownloadByHttp::staticMetaObject = {
    { &AbstractDownloadUpdate::staticMetaObject, qt_meta_stringdata_DownloadByHttp,
      qt_meta_data_DownloadByHttp, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DownloadByHttp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DownloadByHttp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DownloadByHttp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DownloadByHttp))
        return static_cast<void*>(const_cast< DownloadByHttp*>(this));
    return AbstractDownloadUpdate::qt_metacast(_clname);
}

int DownloadByHttp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractDownloadUpdate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
