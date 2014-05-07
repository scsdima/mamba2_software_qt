#include "crc.h"

/* *********************************************************************
 @Function name: calculate_crc
 @Return: (quint8)
 @Parameters:
   quint8 *data
    quint16 size
 @Description: $d

********************************************************************* */
quint8 calculate_crc(quint8 *data, quint32 size)
{
   quint8 summ=0;
   while(size--)
   {
       summ += *data++;
   }
   return summ;
}
