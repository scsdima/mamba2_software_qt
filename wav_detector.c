/* *********************************************************************


  @File:wav_detector.c

  @Project: E:\workspace_test\1
  @Date: 2014\01\09 21-25-36
  @Description: Detection method


 
 ********************************************************************* */


 #include "wav_detector.h"


/* ********************************************************************* 
  @Function name: vcInit
  @Return: (void) 
  @Parameters: 
	VideoCounter_t *vc 
  @Description: $d
 
 ********************************************************************* */
  void vcInit(VideoCounter_t *pvc){
    quint32 i = vc->config.l_val - 1;
    while( i-- ) {
        vc->last_vs[i] =0;
    }   
    vc->last_v = 0;
    vc->last_vs_i=0;
    vc->av_col_vs_i=0;
    vc->status.firststart = true;
}
    //    enum {vcAlarm=1,vcNothing=0};

/* ********************************************************************* 
  @Function name: vcAddNewValue
  @Return: (quint8) 
  @Parameters: 
	VideoCounter_t*vc
	quint16 val 
  @Description: $d
 
 ********************************************************************* */
bool vcAddNewValue(VideoCounter_t* pvc, quint32 val){            

            vc->last_vs_i %= vc->config.l_val;
            vc->last_vs[vc->last_vs_i++] = (qint32)val;
            vc->last_v = vc->cur_v;
            vc->cur_v = vc->next_v;//current_value = new_value
            vc->next_v = val; //new_value = value            
            quint32 i = vc->config.l_val-1;
            quint32 avlv = 0;
            while(i--){                
                avlv+=vc->last_vs[i];                
            }
            vc->avlv = (avlv/vc->config.l_val);
            vc->wval=ABS((qint32)vc->cur_v*vc->cur_v - (qint32)vc->avlv*vc->next_v); // y(x) = x(n)*x(n) - x(n+1)*x(n-1);
            //sprintf(buf,"w=%d,trig=%d",vc->wval,vc->config.wtrigger
            if(vc->wval > vc->config.wtrigger )
            {
                if(!vc->status.alarm && !vc->status.firststart)
                {
                    vc->status.alarm=1;
                    return true;
                }
            }
            if(vc->status.alarm && (ABS(vc->wval)) < 1000
                        && ABS(vc->cur_v-vc->ref_v) < vc->config.tolerance
                        && ABS(vc->next_v-vc->ref_v) < vc->config.tolerance ) {
                quint i = vc->config.l_val-1;
                while(i--){
                        vc->last_vs[i] = vc->cur_v;
                }
                vc->status.alarm = 0;
            }                     
          //  if((!vc->alarm && vc->wval<10 )||wc.firststart) {
              if( ABS(vc->wval) < 10 ) {
                if(vc->av_col_vs_i==9) vc->status.firststart=0;
                vc->av_col_vs[vc->av_col_vs_i++]=vc->cur_v;
                vc->av_col_vs_i %= 10;
                vc->ref_v=0;
                for( i=0; i< 10;i++) vc->ref_v+=vc->av_col_vs[i];
                vc->ref_v/=10;
            }
           return false;
    }

/* ********************************************************************* 
  @Function name: 
  @Return: (void)
  @Parameters: 
	VideoCounter_t *vc
	qint32 tolerance
	qint32 trig
	qint8 l_values
	qint8 r_values
  @Description: makes setup for detection method
 
 ********************************************************************* */
void vc_setup(VideoCounter_t *pvc, qint32 tolerance, qint32 trig, qint32 l_values, qint32 r_values)
    {
        vc->config.tolerance=tolerance;
        vc->config.wtrigger=trig;
        vc->config.l_val=l_values;
        vc->config.r_val=r_values;
    }

/* ********************************************************************* 
  @Function name: vc_result
  @Return: (void)
  @Parameters: 
	VideoCounter_t *vc
	quint16 *value
	quint16 *time
  @Description: gets final  result 
 
 ********************************************************************* */
void vc_result(VideoCounter_t *pvc, quint16 *pvalue, quint16 *ptime)
    {
        *pvalue=0;
        *ptime=0;
    }
