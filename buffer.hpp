#pragma once
#include <QList>
#include <QDateTime>
#include <QFile>
#include <QDebug>



namespace data_storage{
    class DataStorage;
    struct DateTime;

}


struct DateTime{
    struct  {
        quint8 day   ;
        quint8  month ;
        quint8 year   ;
    }date;
    struct{
        quint8 hour;
        quint8 minute;
        quint8 second;
    }time;
};

static const QDateTime toQdt(const DateTime &datetime){
    QDateTime qdt;
    qdt.setDate(QDate(datetime.date.year,datetime.date.month,datetime.date.day));
    qdt.setTime(QTime(datetime.time.hour,datetime.time.minute,datetime.time.second));
    return qdt;
}

static const DateTime toDt(const QDateTime &qdt)
{
    DateTime datetime;
    datetime.date.day=qdt.date().day();
    datetime.date.month=qdt.date().month();
    datetime.date.year=quint8(qdt.date().year()-2000);
    datetime.time.hour=qdt.time().hour();
    datetime.time.minute=qdt.time().minute();
    datetime.time.second=qdt.time().second();
    return datetime;
}


template <typename T>
class DataStorage{

public:

    typedef enum {BlockData=0x01,BlockDateTimeMarker=0x21} BlockId ;
    DataStorage()
    {
        list.clear();
        _cur_pos=-1;
        //  qDebug()<<"size:"<<sizeof(T)<<sizeof(DateTime)<<sizeof(Block);
    }


    struct Block{
        unsigned char id;
        union {
            struct{
                DateTime datetime;
                quint8 fq;
            };
            T data;
        };
    };


    qint32 findByDateTime(QDateTime search_time){
        quint32 index=0;
        quint32 found_index=0;
        search_time=search_time.addYears(-2000);
        if(list.count() && list.first().id==BlockDateTimeMarker)
        {
            //first record every time is date and less then record is searching
            foreach(Block bl,list )
            {
                if(bl.id==BlockDateTimeMarker)
                {
                    QDateTime qdt=toQdt(bl.datetime);
                    if( qdt >= search_time)
                    {
                        return found_index;
                    }
                    else found_index=index;
                }
                index++;
            }
            return index - 1;
        }
        return (-1);
    }
    void appendBlock(Block block)
    {
        if( _cur_pos == -1 ) _cur_pos = list.count() - 1;
        list.append(block);
    }
    quint32 blockCount() const{                return list.count();   }

    void appendMarker(const DateTime &dt,const unsigned char fq)
    {
        Block bl;
        bl.id=BlockDateTimeMarker;
        bl.datetime=dt;
        bl.fq=fq;
        appendBlock(bl);
        _cur_marker=list.count()-1;
        _cur_datetime = dt;
    }

    void appendData(T &data)    {
        Block bl;
        bl.id=BlockData;
        bl.data=data;
        appendBlock(bl);
    }

    const QDateTime nearDateTime()    {
        return QDateTime();
    }

    const Block block_at(quint32 i) {
        return list[i];
    }

    void setCurrentPos(qint32 pos)  {
        _cur_pos=pos;
    }

    const T * getNext() {
        //if current position is higher then count()
        if(_cur_pos >= list.count()) {
            _cur_marker=0;
            return 0;
        }
        while( _cur_pos < list.count()) {
            if( list.at(_cur_pos).id == BlockData) {
                break;
            }
            _cur_datetime=list.at(_cur_pos).datetime;
            _cur_pos++;
        }
        return (T*)&list[_cur_pos++].data;
    }

    quint32 leftMarker( quint32 i) {
        if(list.count() > 0) {
            quint32 list_size = (quint32)list.count();
            if( i > (list_size-1) ) {
                return (quint32)0;
            }
            //when recording runs it speed up
            if( i == (list_size-1) ) {
                return _cur_marker;
            }
            for(; i!=0; i--) {
                if(list.at(i).id == BlockDateTimeMarker) {
                    return i;
                }
            }
        }
        return (quint32)0;
    }

    const DateTime rightMarker(){
        return DateTime();
    }

    qint32 currentPostion() const {
        return _cur_pos;
    }

    bool saveToFile(const QString & fname){
        //TODO save to file
        QFile file(fname);
        file.open(QFile::WriteOnly);
        if(!file.isOpen()) return false;

        file.write("mamba2data");
        foreach(Block bl,list) {
            if(!file.write((char*)&bl,sizeof(Block)))
                return false;
        }
        file.close();
        return true;
    }

    bool loadFromFile(const QString &fname){
        QFile file(fname);
        list.clear();
        file.open(QFile::ReadOnly);
        if( !file.isOpen() ) {
            return false;
        }
        QByteArray h = QByteArray(file.read(10));
        if(h == QByteArray("mamba2data")) {
            while(!file.atEnd()) {
                Block bl;
                file.read(( char*) &bl,sizeof(Block));
                this->list.append(bl);
            }
        }
        file.close();
        return true;
    }

    void clearBlocks(void) {
        list.clear();
        _cur_marker=0;
        _cur_datetime=DateTime();
    }

    quint32 dataSize(void) {
        return list.count()*sizeof(Block);
    }

    const DateTime & startTime(void)  {
        return (DateTime)list.first().datetime;
    }

private:

    qint32 _cur_pos;
    quint32 _cur_marker;//offset from nearest marker left
    DateTime _cur_datetime;
    quint16 _frequency;
    QList<Block>   list;
};


