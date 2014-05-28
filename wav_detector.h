#ifndef WAV_DETECTOR_H
    #define WAV_DETECTOR_H


    #ifdef __cplusplus

extern "C"{


    #endif

    #define ABS(X) ((X)<0?(-(X)):(X))


typedef     signed int INT32 ;
typedef     unsigned int UINT32 ;
typedef     unsigned short UINT16 ;
typedef     unsigned char UINT8 ;
typedef     signed char INT8;

#ifndef FALSE
#define  FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define MAXIMUM_LVAL (20)
#define MAXIMUM_RVAL (20)
#define QUIET_SIGNAL_WLEV (10)
#define NORMAL_SIGNAL_WLEV (1000)

    typedef struct {
    INT32 wtrigger; //acceleration trigger
    INT32 tolerance;
    UINT8 lval_cnt;
    UINT8 rval_cnt;
} VideoCounterConfig_t;

typedef volatile struct {
    //dynamic values
    INT32 last_v_buf[MAXIMUM_LVAL]; //last values buffer
    UINT8 last_v_idx; //last value index
    UINT32 last_v; //last value

    INT32 ref_v_buf[MAXIMUM_RVAL]; //color values for refference color
    UINT8 ref_v_idx; //last average color index
    INT32 ref_v; //ref color value

    INT32 avlv; //average value
    INT32 cur_v; //curent value
    INT32 next_v; //next value
    INT32 wval; //acceleration value

    struct {
        unsigned alarm : 1;
        unsigned warning : 1;
        unsigned firststart : 1; //
    } status;

    VideoCounterConfig_t config;
} VideoCounter_t;

void    vcInit(VideoCounter_t *vc);
UINT8   vcAddNewValue(VideoCounter_t *vc, UINT16 val);
void    vc_setup(VideoCounter_t *vc, INT32 tolerance, INT32 trig
    , INT8 lval_cnt, INT8 rval_cnt);
void    vc_result(VideoCounter_t *vc, UINT16 *value, UINT16 *time);

#ifdef __cplusplus
}
#endif
#endif


