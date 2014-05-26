#ifdef COMMUNICATION_METHOD2
/* *********************************************************************


 @File:communication.cpp

 @Project: E:\workspace_test\1
 @Date: 2014\01\09 21-21-13
 @Description: $d



********************************************************************* */


#include "communication_m2.h"
#include "qextserialport.h"

#include <QDebug>
#include <QTimer>
#include <QDateTime>


QMutex  mutex;


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
    comm_watchdog_timer = 0;
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
   if(timerCounter % (TIMER_1SEC/TIMER_MIN_STEP) == 0){
       sync_1sec = 1;

   }
   if(timerCounter % streamPeriod == 0){
       sync_stream = 1;
   }
   if(!suspended){
   comm_watchdog_timer++;
   if(comm_watchdog_timer > 1000 ) {
       disconnectFromSerialPort();
       emit portDisconnected();
    }
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
           //if stream is enabled or just read status
           if(stream_on) {
               runStream();
           }
           else {
               readStatus();
           }
          processCommands();
          processTextCommand();
       }
       msleep(50);
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
void CommunicationProvider::operation(quint8 deviceAddress,quint8 cmd_code
                                        ,quint32 cmd_data,quint32 timeout)
{
   if(isConnected()){

       CommunicationPacket command
                  = CommunicationPacket(deviceAddress,cmd_code,timeout,cmd_data);
       this->lastAdr=deviceAddress;
       if(cmd_list.isEmpty()) {
           emit operationStarted();
       }
       cmd_list.append(command);
       suspended=0;
   }
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
   while(txt_cmd_lst.count())   {
       txt_cmd=txt_cmd_lst.at(0);
       if(this->sendTextCommmand())   {
           txt_cmd_lst.removeFirst();
           tmp=QString(txt_answ);
           //tmp.replace('\n',"<LF>");
           // tmp.replace('\r',"<CR>");
           emit textCommandAnswer(tmp);
       }

   }
   while(port.bytesAvailable())   {
       textCommandAnswer(QString(port.readAll()));
   }

}

/* *********************************************************************
 @Function name: CommunicationProvider::readStatus
 @Return: (void)
 @Parameters:
   void
 @Description: Drops command to read status every TIMER_1SEC

********************************************************************* */
void CommunicationProvider::readStatus(void)
{
   if(sync_1sec){
       sync_1sec=0;
       CMD = CommunicationPacket(lastAdr,FUNC_GET_STATUS);
       sendCommand();
   }
}


/* *********************************************************************
 @Function name: CommunicationProvider::stream
 @Return: (void)
 @Parameters:
   void
 @Description: sends stream data request to port

********************************************************************* */
void CommunicationProvider::runStream(void)
{
   if(sync_stream){
       sync_stream=false;
       CMD = CommunicationPacket(lastAdr,stream_cmd);
       sendCommand();
   }
}


/* *********************************************************************
 @Function name: CommunicationProvider::processCommand
 @Return: (void)
 @Parameters:
   void
 @Description: $d

********************************************************************* */
void CommunicationProvider::processCommands(void)
{
   mutex.lock();
   QList<CommunicationPacket>  tmp = cmd_list;
   cmd_list.clear();
   mutex.unlock();

   while(tmp.count() > 0)   {
       CMD = tmp.first();
       tmp.removeFirst();
       sendCommand();
   }
   emit operationFinished();
   putToInputBuffer();
   parseInputBuffer();
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
       comm_watchdog_timer =0;
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
   discovering=false;
   suspendCommunication(true);
   msleep(500);
   if(port.isOpen())
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
               if((uchar)data[2]==crc){
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
    quint32 bytes_count=0;
    bool result =false;
    emit activity(1);
    emit activity_answer(0);
    QByteArray data = push_protocol(CMD.adr,CMD.cmd,CMD.param.data);  
    if( port.isOpen() ) {
        bytes_count = port.write(data);
        port.flush();
    }
    result = (bytes_count == data.size());
#ifdef QT_DEBUG
    qDebug()<<"2TX:"<<data.toHex();
#endif
    /*required timeout 50ms by mamba*/ msleep(50);
    emit activity(0);
    return result;
}

/* *********************************************************************
 @Function name: CommunicationProvider::parseInputBuffer
 @Return: (quint16)
 @Parameters:
   void
 @Description: Parse input buffer buffer

********************************************************************* */
quint16 CommunicationProvider::parseInputBuffer(void)
{
    quint16 result=0;    

    while(inputBuffer.size() >= 8){
        QByteArray in_data;
        in_data = QByteArray(inputBuffer).remove(8,inputBuffer.size());

        /* kostyl*/
        if((uchar)in_data[3] == FUNC_GET_STREAM && inputBuffer.size() >= 16){
            in_data = QByteArray(inputBuffer).remove(16,inputBuffer.size());
            if(pop_protocol(&CMD.adr, &CMD.cmd, &CMD.param.data[0], in_data)){
                inputBuffer.remove(0,16);
                quint32 val;
                val =(quint32)CMD.param.val;
                emit commandAnswer(FUNC_GET_ANA0_STATUS,val,true);
                val = (quint32)CMD.param.data[4]|(CMD.param.data[5]<<8);
                emit commandAnswer(FUNC_GET_ANA1, val, true);
                val = (quint32)CMD.param.data[6]|(CMD.param.data[7]<<8);
                emit commandAnswer(FUNC_GET_ANA2, val, true);
                result = true;
            }
        }
        /* end of kostyl*/

        /* normal command*/
        else if(pop_protocol(&CMD.adr, &CMD.cmd, &CMD.param.data[0], in_data))
        {
            result++;
            inputBuffer.remove(0,8);
            emit commandAnswer(CMD.cmd,CMD.param.val,true);
            result = true;
        }
        else{
#ifdef QT_DEBUG
            qDebug()<<inputBuffer.toHex();
            qDebug()<<"error";
#endif
               inputBuffer.remove(0,1);
        }
    }
    if(result ) {
        comm_watchdog_timer =0;
    }
    emit activity_answer(result);
    return result;
}

/* *********************************************************************
@Function name: CommunicationProvider::putToInputBuffer
@Return: (void)
@Parameters:
  void
@Description: Puts data to input buffer from communication port

********************************************************************* */
void CommunicationProvider::putToInputBuffer(void)
{
   if(port.isOpen() && port.bytesAvailable())
   {
       QByteArray in_data =port.readAll();
       inputBuffer.append(in_data);
    #ifdef QT_DEBUG
               qDebug()<<"2RX:"<<in_data.toHex();
    #endif
   }
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
   if(txt_cmd.contains("init"))   {
       to=0;
   }
   else if(txt_cmd.contains("set"))   {
       to=5;
   }
   if(port.isOpen()) {
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
   }

   return true;
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
void CommunicationProvider::slot_discoveryFinished(void)
{
    emit discoveryFinished();
}

#endif
