/****************************************************************************
** Meta object code from reading C++ file 'communication_m2.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../communication_m2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'communication_m2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CommunicationProvider[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,
      48,   38,   22,   22, 0x05,
      75,   22,   22,   22, 0x05,
      96,   94,   22,   22, 0x05,
     150,  138,   22,   22, 0x05,
     189,  185,   22,   22, 0x05,
     216,   22,   22,   22, 0x05,
     235,   22,   22,   22, 0x05,
     255,   22,   22,   22, 0x05,
     274,   22,   22,   22, 0x05,
     289,   22,   22,   22, 0x05,
     311,   22,   22,   22, 0x05,
     330,   22,   22,   22, 0x05,
     350,   22,   22,   22, 0x05,
     367,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
     387,   22,   22,   22, 0x0a,
     415,  412,   22,   22, 0x0a,
     442,   22,   22,   22, 0x0a,
     492,  464,   22,   22, 0x0a,
     533,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CommunicationProvider[] = {
    "CommunicationProvider\0\0thread_start()\0"
    "adc0,adc1\0newValues(quint16,quint16)\0"
    "thread_suspended()\0,\0"
    "sensorExtraInformation(quint8,QByteArray)\0"
    "cmd,cmdp,ok\0commandAnswer(quint8,quint32,bool)\0"
    "txt\0textCommandAnswer(QString)\0"
    "operationStarted()\0operationFinished()\0"
    "reportFps(quint16)\0activity(bool)\0"
    "activity_answer(bool)\0portDisconnected()\0"
    "sensorFound(quint8)\0startDiscovery()\0"
    "discoveryFinished()\0slot_discoveryFinished()\0"
    "on\0suspendCommunication(bool)\0"
    "resumeCommunication()\0deviceAddr,freq,stream_type\0"
    "startStream(quint8,quint32,StreamType_t)\0"
    "sync_timer()\0"
};

void CommunicationProvider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CommunicationProvider *_t = static_cast<CommunicationProvider *>(_o);
        switch (_id) {
        case 0: _t->thread_start(); break;
        case 1: _t->newValues((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 2: _t->thread_suspended(); break;
        case 3: _t->sensorExtraInformation((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 4: _t->commandAnswer((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 5: _t->textCommandAnswer((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->operationStarted(); break;
        case 7: _t->operationFinished(); break;
        case 8: _t->reportFps((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 9: _t->activity((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->activity_answer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->portDisconnected(); break;
        case 12: _t->sensorFound((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 13: _t->startDiscovery(); break;
        case 14: _t->discoveryFinished(); break;
        case 15: _t->slot_discoveryFinished(); break;
        case 16: _t->suspendCommunication((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->resumeCommunication(); break;
        case 18: _t->startStream((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< StreamType_t(*)>(_a[3]))); break;
        case 19: _t->sync_timer(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CommunicationProvider::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CommunicationProvider::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_CommunicationProvider,
      qt_meta_data_CommunicationProvider, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CommunicationProvider::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CommunicationProvider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CommunicationProvider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CommunicationProvider))
        return static_cast<void*>(const_cast< CommunicationProvider*>(this));
    return QThread::qt_metacast(_clname);
}

int CommunicationProvider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void CommunicationProvider::thread_start()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CommunicationProvider::newValues(quint16 _t1, quint16 _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CommunicationProvider::thread_suspended()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void CommunicationProvider::sensorExtraInformation(quint8 _t1, QByteArray _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CommunicationProvider::commandAnswer(quint8 _t1, quint32 _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CommunicationProvider::textCommandAnswer(const QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CommunicationProvider::operationStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void CommunicationProvider::operationFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void CommunicationProvider::reportFps(quint16 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CommunicationProvider::activity(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void CommunicationProvider::activity_answer(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void CommunicationProvider::portDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void CommunicationProvider::sensorFound(quint8 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void CommunicationProvider::startDiscovery()
{
    QMetaObject::activate(this, &staticMetaObject, 13, 0);
}

// SIGNAL 14
void CommunicationProvider::discoveryFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}
QT_END_MOC_NAMESPACE
