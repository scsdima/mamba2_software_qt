#ifdef COMMUNICATION_METHOD1
#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "qextserialport.h"
#include "qextserialenumerator.h"

#include <QByteArray>
#include <QObject>
#include <QString>
#include <QPointF>
#include <QTimer>
#include <QMutex>
#include <QThread>
#include <QStringList>

#include "communication_func.h"
#include "crc.h"

static const quint32 TIMER_1SEC = (1000);
static const quint32 TIMER_STREAM_DEFAULT = (200);
static const quint32 TIMER_MIN_STEP = (10);

namespace Communication{
    class CommunicationProvider;
    struct Command;
    class CommunicationTimeout;
    struct CommunicationPacket;
}


/*
 *  Communication timeout package
 */
class CommunicationTimeout : public QThread
{
    Q_OBJECT
private:
    quint32 count_down;
    bool is_timeout;
    void run(void);

public:
    explicit CommunicationTimeout(QObject *parent = 0);
    bool isTimeout(void);
    void startTimer(quint32 timeout);
    void stopTimer(void);

signals:

public slots:

};

/*
 *  communication packet
 */
struct CommunicationPacket{
public:
    CommunicationPacket(){}
    CommunicationPacket(quint8 adr, quint8 cmd, quint32 timeout, quint32 data){
        this->adr = adr;
        this->cmd = cmd;
        this->param.val = data;
        this->timeout =  timeout;
    }
    quint8   adr;
    quint8   cmd;
    quint32  timeout;/* mS*/
    union {
        quint32 val;
        quint16 val16[2];
        quint8  data[32];
    }param;
};

/*
 * communication
 */
class CommunicationProvider: public QThread
{
    Q_OBJECT
public:
    /* types for class*/

    typedef enum {StreamStop,Stream0A,Stream0F}StreamType_t;


    explicit CommunicationProvider(QObject *parent=0);
    ~CommunicationProvider();

    bool    connectToSerialPort(const QString &port_name);
    void    disconnectFromSerialPort() ;

    bool    isConnected() const {
        return port.isOpen();
    }

    void    setSpeed(quint16);

    const   QByteArray getData();
   // void    sendData(quint16 address, const QByteArray&);

    void    addAdcValues(double ,double);

    quint16 frequency(void) const  {
        return frequency_hz;
    }
    void    setFrequency(quint16 freq) {
        frequency_hz = freq;
    }

    inline bool isSuspended(void) const {
        return suspended;
    }

    virtual const QByteArray   push_protocol(quint8 adr, quint8 cmd, quint8 *cmdp);
    virtual bool   pop_protocol(quint8*adr, quint8*cmd, quint8*cmdp, const QByteArray &data);

    void    operation(quint8 adr, quint8 cmd, quint32 cmdp=0, quint32 timeout=1000);
    void    text_command( const char* text);
    //uint32_t get32b_result() const {return *((uint32_t*)_cmdp);}

    bool    commandAvailable(void);
    quint8   streamCmd(void) const  {
        return  stream_cmd;
    }
    quint32 getPortsList(QStringList &portsList);

signals:
    void    gotAnswer(quint16,bool);
    void    thread_start(void);
    void    showStatus(quint8);
    void    newValues(quint16 adc0,quint16 adc1);
    void    thread_suspended(void);    
    void    sensorExtraInformation(quint8 ,QByteArray);
    void    commandAnswer(quint8 cmd,quint32 cmdp,bool ok);
    void    textCommandAnswer(const QString txt);
    void    operationStarted(void);
    void    operationFinished(void);    
    void    reportFps(quint16);
    void    activity(bool);
    void    activity_answer(bool);

    void    sensorFound(quint8 );/* not implemented*/
    void    startDiscovery(void);/* not implemented*/
    void    discoveryFinished(void);/* not implemented*/

public slots:
    void    discovery(void) ;/* not implemented*/
    void    suspendCommunication(bool on) ;
    void    resumeCommunication(void) {
        suspended=0;
    }
    void    startStream(quint8 deviceAddr,quint32 freq,StreamType_t stream_type);

private:   
    void        run(void);
    bool        sendCommand(void);
    bool        sendTextCommmand(void);
    void        processCommand(void);
    void        processTextCommand(void);
    void        setupConnections(void);
    void        runStream(void);
    void        readStatus(void);

    CommunicationTimeout timeoutTimer;
    QextSerialPort port;
    volatile bool unsynchronized;
    volatile bool suspended;
    volatile bool sync;
    volatile bool sync_1sec;
    volatile bool sync_stream;
    volatile bool discovering;
    volatile bool stream_on;
    volatile bool request_stream;

    QByteArray  inputBuffer;
    quint16     nextSynchCtr;
    quint8      _currentAddress;
    quint16     frequency_hz;
    QTimer      *syncTimer;
    quint32     timerCounter;
    quint32     streamPeriod;
    quint8      lastAdr;
    CommunicationPacket CMD;
    quint8 stream_cmd;
    QList<CommunicationPacket> cmd_list;/* commands pool*/
    QByteArray cmd_out_data;//out data buffer

    /* text command*/
    QList<QByteArray> txt_cmd_lst;/* text commands pool*/
    QByteArray txt_cmd;
    QByteArray txt_answ;

private slots:
    void sync_timer(void);
};


#endif // PROTOCOL_H
#endif
