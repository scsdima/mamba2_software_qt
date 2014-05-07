#ifdef COMMUNICATION_METHOD1
/* *********************************************************************


  @File:communication.cpp

  @Project: E:\workspace_test\1
  @Date: 2014\01\09 21-21-13
  @Description: $d


 
 ********************************************************************* */


#include "communication_m1.h"
#include "qextserialport.h"

#include <QDebug>
#include <QTimer>
#include <QDateTime>


QMutex  mutex;


/* ********************************************************************* 
  @Function name: t
  @Return: (CommunicationTimeout::CommunicationTimeou) 
  @Parameters: 
	QObject *parent 
  @Description: $d
 
 ********************************************************************* */
CommunicationTimeout::CommunicationTimeout(QObject *parent) :
    QThread(parent),is_timeout(false),count_down(0){
     start(QThread::NormalPriority);
}


/* ********************************************************************* 
  @Function name: CommunicationTimeout::isTimeout
  @Return: (bool) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
bool CommunicationTimeout::isTimeout(void){
    return is_timeout;
}

/* ********************************************************************* 
  @Function name: CommunicationTimeout::startTimer
  @Return: (void) 
  @Parameters: 
	quint32 timeout 
  @Description: $d
 
 ********************************************************************* */
void CommunicationTimeout::startTimer(quint32 timeout){
    count_down = timeout;
    is_timeout = false;    
}

/* ********************************************************************* 
  @Function name: CommunicationTimeout::stopTimer
  @Return: (void) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
void CommunicationTimeout::stopTimer(void){
    count_down=0;
}

/* ********************************************************************* 
  @Function name: CommunicationTimeout::run
  @Return: (void) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
void CommunicationTimeout::run(void){
    forever{
        if( count_down ) {
            msleep(count_down);            
        }
        is_timeout = true;
        count_down = 0;
        msleep(100);
    }
}


/* ********************************************************************* 
  @Function name: r
  @Return: (CommunicationProvider::CommunicationProvide) 
  @Parameters: 
	QObject *parent 
  @Description: $d
 
 ********************************************************************* */
CommunicationProvider::CommunicationProvider(QObject *parent)
    :QThread(parent)
{
    discovering=false;/*not discover*/
    stream_on=false;
    request_stream=false;
    streamPeriod = TIMER_STREAM_DEFAULT;
    suspendCommunication(true);
    syncTimer = new QTimer(this);
    /* for rate calculation */    
    syncTimer->start(TIMER_MIN_STEP);
    start(QThread::NormalPriority);

    connect(syncTimer,SIGNAL(timeout()),this,SLOT(sync_timer()));
    // /* not used */connect(&port,SIGNAL(readyRead()),this,SLOT(readyRead()));

}

/* *********************************************************************
  @Function name: CommunicationProvider::getPortsList
  @Return: (quint32)  - count of ports
  @Parameters:
    QStringList &portsList - list of current connected serial ports in system
  @Description:

 ********************************************************************* */
quint32 CommunicationProvider::getPortsList(QStringList &portsList){
    QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
    if(ports.size() > 0){
        for (quint32 i = 0; i < (quint32)ports.size(); i++)  {
            QString pname = QString(ports.at(i).portName.toLocal8Bit().constData())
                +QString("(%1)").arg(ports.at(i).enumName);
            portsList.append(pname);
        }
    }
    return ports.size();
}

/* ********************************************************************* 
  @Function name: r
  @Return: (CommunicationProvider::~CommunicationProvide) 
  @Parameters: 
	 
  @Description: $d
 
 ********************************************************************* */
CommunicationProvider::~CommunicationProvider()
{

}


/* ********************************************************************* 
  @Function name: CommunicationProvider::sync_timer
  @Return: (void) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
void CommunicationProvider::sync_timer(void) {
    timerCounter++;
    if(timerCounter%(TIMER_1SEC/TIMER_MIN_STEP) == 0){
        sync_1sec = 1;        
    }
    if(timerCounter%streamPeriod == 0){
        sync_stream = 1;
    }
}

/* ********************************************************************* 
  @Function name: CommunicationProvider::suspend
  @Return: (void) 
  @Parameters: 
	bool on 
  @Description: $d
 
 ********************************************************************* */
void CommunicationProvider::suspendCommunication(bool on)
{
    suspended = on;
    if( on )         {
        emit thread_suspended();
    }
    else  {
        emit thread_start();
    }
}


/* ********************************************************************* 
  @Function name: CommunicationProvider::run
  @Return: (void) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
void CommunicationProvider::run(void)
{
    forever {
        if( !suspended ){
            //request on stream
            if(request_stream && cmd_list.isEmpty()) {
                request_stream = 0;
                stream_on = 1;
            }
            //stream

            if(stream_on) {
                runStream();
            }
            else {
                readStatus();
            }

           processCommand();
           processTextCommand();
           //
        }
        msleep(10);
    }
    exec();
}

/* ********************************************************************* 
  @Function name: CommunicationProvider::operation
  @Return: (void) 
  @Parameters: 
	quint8 adr
	quint8 cmd
	quint32 cmdp
	quint32 to 
  @Description: $d
 
 ********************************************************************* */
void CommunicationProvider::operation(quint8 adr,quint8 cmd,quint32 cmdp,quint32 to)
{
    if(isConnected()){

        CommunicationPacket command;//Command(quint8 cmd,quint8 adr,quint32 val,quint32 to)
        this->lastAdr=adr;
        command.adr = adr;
        command.cmd=cmd;
        command.param.val=cmdp;
        command.timeout= to;
        suspended=0;
        if(cmd_list.isEmpty()) {
            emit operationStarted();
        }
        cmd_list.append(command);
        suspended=0;
    }
}


/* *********************************************************************
  @Function name: CommunicationProvider::commandAvailable
  @Return: (bool)
  @Parameters:
    void
  @Description: $d

 ********************************************************************* */
bool CommunicationProvider::commandAvailable(void)
{
    return cmd_list.count();
}


/* ********************************************************************* 
  @Function name: CommunicationProvider::processTextCommand
  @Return: (void) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
void CommunicationProvider::processTextCommand(void)
{
    QString tmp;
    while(txt_cmd_lst.count())
    {
        txt_cmd=txt_cmd_lst.at(0);
        if(this->sendTextCommmand())
        {
            txt_cmd_lst.removeFirst();
            tmp=QString(txt_answ);
            //tmp.replace('\n',"<LF>");
            // tmp.replace('\r',"<CR>");
            emit textCommandAnswer(tmp);
        }

    }
    while(port.bytesAvailable())
    {
        textCommandAnswer(QString(port.readAll()));
    }

}

/* ********************************************************************* 
  @Function name: CommunicationProvider::readStatus
  @Return: (void) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
void CommunicationProvider::readStatus(void)
{
    //sends status update command every 300ms
    if(sync_1sec)
    {
        sync_1sec=0;
        CMD.cmd = 0x01;
        CMD.adr = lastAdr;
        CMD.timeout = 100;
        CMD.param.val = 0;
        cmd_list.removeAt(0);

        if(sendCommand()){
            emit commandAnswer(CMD.cmd,CMD.param.val,true);
        }
        else {
            emit commandAnswer(CMD.cmd,CMD.param.val,false);
        }
    }
}


/* ********************************************************************* 
  @Function name: CommunicationProvider::stream
  @Return: (void) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
void CommunicationProvider::runStream(void)
{    
    if(sync_stream){
        sync_stream=false;
        CMD = CommunicationPacket(lastAdr,stream_cmd,50,0);
        bool send_result = sendCommand();
        emit commandAnswer(CMD.cmd,CMD.param.val,send_result);
        if(send_result){
            quint32 val;
            val = (quint32)CMD.param.data[4]|(CMD.param.data[5]<<8);
            emit commandAnswer(0x05, val, true);
            val = (quint32)CMD.param.data[6]|(CMD.param.data[7]<<8);
            emit commandAnswer(0x03, val, true);
        }

        /* send data after synchro period */
        /* 0x0f contains this data inside it*/
        if(sync_1sec && stream_cmd != 0x0f)
        {
            sync_1sec = false;
            static quint8 extra_cmd=0;
            switch(extra_cmd)
            {
            case 0:
                CMD.cmd=0x03;
                extra_cmd=1;
                break;
            case 1:
                CMD.cmd=0x05;
                extra_cmd=0;
                break;
            default:
                extra_cmd=0;
                break;
            }
            send_result = sendCommand();
            emit commandAnswer(CMD.cmd,CMD.param.val,send_result);
        }
    }
}


/* ********************************************************************* 
  @Function name: CommunicationProvider::processCommand
  @Return: (void) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
void CommunicationProvider::processCommand(void)
{
    mutex.lock();
    QList<CommunicationPacket>  tmp = cmd_list;
    cmd_list.clear();
    mutex.unlock();

    while(tmp.count())
    {
        CMD = tmp.first();
        tmp.removeFirst();
        bool result = sendCommand();
        emit commandAnswer(CMD.cmd,CMD.param.val,result);
        if(tmp.count() == 0) {
            emit operationFinished();
            break;
        }
    }
}


/* ********************************************************************* 
  @Function name: CommunicationProvider::connectToSerialPort
  @Return: (bool) 
  @Parameters: 
	const QString &port_name 
  @Description: $d
 
 ********************************************************************* */
bool CommunicationProvider::connectToSerialPort(const QString &port_name)
{
    if(port.isOpen()) {
        return false;
    }
    port.setPortName(port_name);
    if(port.open(QIODevice::ReadWrite))
    {
        port.setBaudRate(BAUD19200);
        port.setFlowControl(FLOW_OFF);
        port.setParity(PAR_NONE);
        port.setDataBits(DATA_8);
        port.setStopBits(STOP_1);
        port.setTimeout(50);
        port.setQueryMode(QextSerialPort::Polling);
        return true;
    }
    return false;
}


/* ********************************************************************* 
  @Function name: CommunicationProvider::disconnectFromSerialPort
  @Return: (void) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
void CommunicationProvider::disconnectFromSerialPort(void)
{
    discovering=0;
    suspendCommunication(true);
    msleep(500);
    port.close();
}




/* ********************************************************************* 
  @Function name: CommunicationProvider::push_protocol
  @Return: (const QByteArray) 
  @Parameters: 
	quint8 adr
	quint8 cmd
	quint8 *cmdp 
  @Description: $d
 
 ********************************************************************* */
const QByteArray CommunicationProvider::push_protocol(quint8 adr,quint8 cmd,quint8 *cmdp)
{
    QByteArray data;
    data.append('\xAA');
    data.append(adr);
    data.append(calculate_crc(cmdp,4)+cmd);
    data.append(cmd);
    data.append((char*)cmdp,4);
    return data;
}


/* ********************************************************************* 
  @Function name: CommunicationProvider::pop_protocol
  @Return: (bool) 
  @Parameters: 
	quint8 *adr
	quint8 *cmd
	quint8 *cmdp
	const QByteArray &data 
  @Description: $d
 
 ********************************************************************* */
bool CommunicationProvider::pop_protocol(quint8 *adr,quint8 *cmd,quint8 *cmdp,const QByteArray &data)
{

    bool answer =(((uchar)data[1]&0x80)!=0);
    *adr=data[1]&(~0x80);
    *cmd=data[3];

    if(!answer) {
        return false;
    }

    if((uchar)data[0] == 0xAA )
    {
        switch(*cmd)
        {
        case 0x0f:
            if(data.count() == 16 )
            {
                if((uchar)data[2] == 0xF0)
                {
                    cmdp[0]=data[6]; //swapped
                    cmdp[1]=data[7];
                    cmdp[2]=data[4];
                    cmdp[3]=data[5];
                    cmdp[4]=data[8];
                    cmdp[5]=data[9];
                    cmdp[6]=data[10];
                    cmdp[7]=data[11];
                    cmdp[8]=data[12];
                    cmdp[9]=data[13];
                    cmdp[10]=data[14];
                    cmdp[11]=data[15];
                    cmdp[12]=data[16];
                    return true;
                }
            }

            break;

        default:
            if(data.count()==8)
            {
                cmdp[0]=data[4];
                cmdp[1]=data[5];
                cmdp[2]=data[6];
                cmdp[3]=data[7];
                quint8 crc = calculate_crc(cmdp,4) + *cmd;
                if( (uchar)data[2] == crc ){
                    return true;
                }
            }
            break;
        }//switch
        }
    return false;
}


/* ********************************************************************* 
  @Function name: CommunicationProvider::sendCommand
  @Return: (bool) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
bool CommunicationProvider::sendCommand(void)
{    
    bool result=false;
    int retry=3;
    int to = CMD.timeout;
    QByteArray in_data;
    QByteArray out_data;
    /*check if some data is available*/
    if(port.bytesAvailable())
    {
        port.readAll();
    }
    result=false;
    while(retry--)
    {
        quint8 cmd = CMD.cmd;

        //if(!stream_on) msleep(50);
        out_data = push_protocol(CMD.adr,CMD.cmd,CMD.param.data);
        port.write(out_data);
        port.flush();
#ifdef QT_DEBUG
        qDebug()<<"TX:"<<out_data.toHex();
#endif
        emit activity(1);
        for(timeoutTimer.startTimer(to); !timeoutTimer.isTimeout(); ){
            if(port.bytesAvailable() >= 8 ) {
                emit activity_answer(1);
                in_data = port.readAll();
                break;
            }
        }      
        if(in_data.count() > 0)
        {
#ifdef QT_DEBUG
            qDebug()<<"RX:"<< in_data.toHex();
#endif
            if(pop_protocol(&CMD.adr, &CMD.cmd, CMD.param.data, in_data) && CMD.cmd == cmd)
            {                
                    /*OK*/
                    result=true;
                    break;                             
            }
            else{
#ifdef QT_DEBUG
                   qDebug()<<"ERROR";
#endif
            }
        }
        /*only for RETRY*/
        port.readAll();
        msleep(50);
    }
    emit activity_answer(0);
    emit activity(0);    
    return result;
}


/* ********************************************************************* 
  @Function name: CommunicationProvider::sendTextCommmand
  @Return: (bool) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
bool CommunicationProvider::sendTextCommmand(void)
{
    int res=0,to=5;
    if(txt_cmd.contains("init"))
    {
        to=100;
    }
    else if(txt_cmd.contains("set"))
    {
        to=20;
    }
    port.write(txt_cmd);
    #ifdef QT_DEBUG
        qDebug()<<"TEXT TX:"<<txt_cmd;
    #endif
    txt_answ.clear();
    while(1) {
        while(to-- && port.bytesAvailable()==0)   {
            msleep(100);
        }
        if(port.bytesAvailable())        {
            txt_answ+=port.readAll();
            #ifdef QT_DEBUG
                qDebug()<<"TEXT RX:"<<txt_answ;
            #endif
            res=1;
        }
        else {
            return res;
        }
    }

    return 0;
}


/* ********************************************************************* 
  @Function name: CommunicationProvider::text_command
  @Return: (void) 
  @Parameters: 
	const char* text 
  @Description: $d
 
 ********************************************************************* */
void CommunicationProvider::text_command(const char* text){
    txt_cmd_lst.append(QByteArray(text));
}


/* ********************************************************************* 
  @Function name: CommunicationProvider::startStream
  @Return: (void) 
  @Parameters: 
	bool on 
  @Description: $d
 
 ********************************************************************* */
void CommunicationProvider::startStream(quint8 deviceAddr,quint32 freq,StreamType_t stream_type){

    bool on = (stream_type!=StreamStop);

    streamPeriod = (1000/TIMER_MIN_STEP)/freq;
    if(on ) {
        switch(stream_type){
        case Stream0F:
             stream_cmd = 0x0f;
            break;
        case Stream0A:
             stream_cmd = 0x0a;
            break;
        default:
            on = false;
            break;
        }
        operation(deviceAddr,FUNC_GET_ZERO);//zero read
        request_stream=1;
        suspended=0;
    }
    else {
        stream_on=0;
    }
}


/* ********************************************************************* 
  @Function name: CommunicationProvider::setSpeed
  @Return: (void) 
  @Parameters: 
	quint16 speed 
  @Description: $d
 
 ********************************************************************* */
void CommunicationProvider::setSpeed(quint16 speed)
{
    if((BaudRateType)speed == BAUD19200){
        port.setBaudRate(BAUD19200);
    }
}


/* ********************************************************************* 
  @Function name: CommunicationProvider::discovery
  @Return: (void) 
  @Parameters: 
	void 
  @Description: Making discovery of sensors connected
 
 ********************************************************************* */
void CommunicationProvider::discovery(void)
{    
     emit discoveryFinished();
}

#endif
