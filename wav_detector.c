/* *********************************************************************


  @File:wav_detector.c

  @Project: E:\workspace_test\1
  @Date: 2014\01\09 21-25-36
  @Description: $d


 
 ********************************************************************* */


 #include "wav_detector.h"
/* Version 1.0*/


/* ********************************************************************* 
  @Function name: vcInit
  @Return: (void) 
  @Parameters: 
	VideoCounter_t *vc 
  @Description: $d
 
 ********************************************************************* */
void vcInit(VideoCounter_t *vc){
    
    switch(vc->config.l_val){
        case 10:
            vc->last_vs[9] =0;
        case 9:
            vc->last_vs[8] =0;
        case 8:              
            vc->last_vs[7] =0;
        case 7:
            vc->last_vs[6] =0;
        case 6:              
            vc->last_vs[5] =0;
        case 5:
            vc->last_vs[4] =0;
        case 4:              
            vc->last_vs[3] =0;
        case 3:
            vc->last_vs[2] =0;
        case 2:              
            vc->last_vs[1] =0;
        case 1:        
            vc->last_vs[0] =0;
            vc->last_v = 0;
    }
            vc->last_vs_i=0;
            vc->av_col_vs_i=0;
            vc->status.firststart=1;
}
    //    enum {vcAlarm=1,vcNothing=0};

/* ********************************************************************* 
  @Function name: vcAddNewValue
  @Return: (UINT8) 
  @Parameters: 
	VideoCounter_t*vc
	UINT16 val 
  @Description: $d
 
 ********************************************************************* */
UINT8 vcAddNewValue(VideoCounter_t*vc,UINT16 val){
            UINT8 i;

            vc->last_vs_i %= vc->config.l_val;
            vc->last_vs[vc->last_vs_i++] = (INT32)val;
            vc->last_v = vc->cur_v;
            vc->cur_v = vc->next_v;//current_value = new_value
            vc->next_v = val; //new_value = value

            vc->avlv=0;
            switch(vc->config.l_val){
                case 10:
                    vc->avlv+=vc->last_vs[9];
                case 9:
                    vc->avlv+=vc->last_vs[8];
                case 8:
                    vc->avlv+=vc->last_vs[7];
                case 7:
                    vc->avlv+=vc->last_vs[6];
                case 6:
                    vc->avlv+=vc->last_vs[5];
                case 5:
                    vc->avlv+=vc->last_vs[4];
                case 4:
                    vc->avlv+=vc->last_vs[3];
                case 3:
                    vc->avlv+=vc->last_vs[2];
                case 2:
                    vc->avlv+=vc->last_vs[1];
                case 1:
                    vc->avlv+=vc->last_vs[0];
            }
            vc->avlv /= vc->config.l_val;

            vc->wval=ABS((INT32)vc->cur_v*vc->cur_v - (INT32)vc->avlv*vc->next_v); // y(x) = x(n)*x(n) - x(n+1)*x(n-1);
            //sprintf(buf,"w=%d,trig=%d",vc->wval,vc->config.wtrigger
            if(vc->wval > vc->config.wtrigger )
            {
                if(!vc->status.alarm && !vc->status.firststart)
                {
                    vc->status.alarm=1;
                    return 1;
                }
            }
            if(vc->status.alarm && (ABS(vc->wval)) < 1000
                        && ABS(vc->cur_v-vc->ref_v) < vc->config.tolerance
                        && ABS(vc->next_v-vc->ref_v) < vc->config.tolerance ) {
                switch(vc->config.l_val){
                  case 10:
                        vc->last_vs[9] =vc->cur_v;
                    case 9:
                        vc->last_vs[8] =vc->cur_v;
                    case 8:
                        vc->last_vs[7] =vc->cur_v;
                    case 7:
                        vc->last_vs[6] =vc->cur_v;
                    case 6:
                        vc->last_vs[5] =vc->cur_v;
                    case 5:
                        vc->last_vs[4] =vc->cur_v;
                    case 4:
                        vc->last_vs[3] =vc->cur_v;
                    case 3:
                        vc->last_vs[2] =vc->cur_v;
                    case 2:
                        vc->last_vs[1] =vc->cur_v;
                    case 1:
                        vc->last_vs[0] =vc->cur_v;
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

           return 0;
    }

/* ********************************************************************* 
  @Function name: 
  @Return: (void)
  @Parameters: 
	VideoCounter_t *vc
	INT32 tolerance
	INT32 trig
	INT8 l_values
	INT8 r_values
  @Description: $d
 
 ********************************************************************* */
void vc_setup(VideoCounter_t *vc,INT32 tolerance,INT32 trig,INT8 l_values,INT8 r_values)
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
	UINT16 *value
	UINT16 *time
  @Description: $d
 
 ********************************************************************* */
void vc_result(VideoCounter_t *vc,UINT16 *value,UINT16 *time)
    {
        *value=0;
        *time=0;
    }
