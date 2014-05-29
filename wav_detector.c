/* *********************************************************************


  @File:wav_detector.c

  @Project: E:\workspace_test\1
  @File info : D.Chikov   2014\01\09 21-25-36
  @Description: $d


 
 ********************************************************************* */


 #include "wav_detector.h"
/* Version 1.0*/


/* *********************************************************************
  @Function name:  vcInit
  @Return: (void)
  @Parameters:
        VideoCounter_t *vc
  @Description: detector initialization

 ********************************************************************* */
void vcInit(VideoCounter_t *vc) {
    UINT8 i;
    for (i = 0; i < vc->config.lval_cnt; i++) {
        vc->last_v_buf[i] = 0;
    }
    vc->last_v = 0;
    vc->last_v_idx = 0;
    vc->ref_v_idx = 0;
    vc->status.firststart = TRUE;
}

/* *********************************************************************
  @Function name:  vcAddNewValue
  @Return: (UINT8) returns 1 if alarm
  @Parameters:
        VideoCounter_t*vc
         UINT16 val
  @Description: adds new value to detect aarm or warning

 ********************************************************************* */
UINT8 vcAddNewValue(VideoCounter_t*vc, UINT16 val) {
    UINT8 i;
    INT32 tmp;

    vc->last_v_idx %= vc->config.lval_cnt;
    vc->last_v_buf[vc->last_v_idx] = (INT32) val;
    vc->last_v_idx++;
    vc->last_v = vc->cur_v;
    vc->cur_v = vc->next_v; //current_value = new_value
    vc->next_v = val; //new_value = value

    tmp = 0;
    for (i = 0; i < vc->config.lval_cnt; i++) {
        tmp += vc->last_v_buf[i];
    }
    vc->avlv = tmp/vc->config.lval_cnt;

    vc->wval = vc->cur_v * vc->cur_v - vc->avlv * vc->next_v; // y(x) = x(n)*x(n) - x(n+1)*x(n-1);
    //sprintf(buf,"w=%d,trig=%d",vc->wval,vc->config.wtrigger
    if ((ABS(vc->wval)) > vc->config.wtrigger) {
        if (!vc->status.alarm && !vc->status.firststart) {
            vc->status.alarm = 1;
            return 1;
        }
    }
    if (vc->status.alarm && (ABS(vc->wval)) < NORMAL_SIGNAL_WLEV
            && ABS(vc->cur_v - vc->ref_v) < vc->config.tolerance
            && ABS(vc->next_v - vc->ref_v) < vc->config.tolerance) {

        for (i = 0; i < vc->config.lval_cnt; i++) {
            vc->last_v_buf[i] = vc->cur_v;
        }
        vc->status.alarm = FALSE;
    }

    //  if((!vc->alarm && vc->wval<10 )||wc.firststart)
    if (ABS(vc->wval) < QUIET_SIGNAL_WLEV) {
        if (vc->ref_v_idx == 9) {
            vc->status.firststart = FALSE;
        }

        /* adding new value to rval*/
        vc->ref_v_buf[vc->ref_v_idx] = vc->cur_v;
        vc->ref_v_idx = (vc->ref_v_idx + 1) % vc->config.rval_cnt;

        /*calculating refference value*/
        tmp = 0;
        for (i = 0; i < vc->config.rval_cnt; i++) {
            tmp += vc->ref_v_buf[i];
        }
        /* calculating average value*/
        vc->ref_v = tmp/vc->config.rval_cnt;
    }

    return 0;
}

/* *********************************************************************
  @Function name:  vc_setup
  @Return: (void)
  @Parameters:
        VideoCounter_t *vc
         INT32 tolerance
         INT32 trig
         INT8 l_values
         INT8 r_values
  @Description: makes setup fo algoritm

 ********************************************************************* */
void vc_setup(VideoCounter_t *vc, INT32 tolerance, INT32 trig
                                    , INT8 lval_cnt, INT8 rval_cnt) {
    vc->config.tolerance = tolerance;
    vc->config.wtrigger = trig;
    vc->config.lval_cnt = (lval_cnt<=MAXIMUM_LVAL)? lval_cnt:MAXIMUM_LVAL;
    vc->config.rval_cnt = (rval_cnt<=MAXIMUM_RVAL)? rval_cnt:MAXIMUM_RVAL;
}

/* *********************************************************************
  @Function name:  vc_result
  @Return: (void)
  @Parameters:
        VideoCounter_t *vc
         UINT16 *value
         UINT16 *time
  @Description: gets result from algoritm

 ********************************************************************* */
void vc_result(VideoCounter_t *vc, UINT16 *value, UINT16 *time) {
    /*allways return 0*/
    *value = 0;
    *time = 0;
}
