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

    typedef struct {
        //dynamic values
        INT32 last_vs[10];      //last values
        UINT32 last_v;          //last value
        INT32 av_col_vs[20];    //average color values
        UINT8 av_col_vs_i;      //last average color index
        UINT8 last_vs_i;        //last value index
        INT32 avlv;             //last value
        INT32 cur_v;            //curent value
        INT32 next_v;           //next value
        INT32 ref_v;            //ref values
        INT32 wval;             //acceleration value

        struct{
            unsigned alarm:1;
            unsigned firststart:1; //
        }status;
        struct{
            INT32   wtrigger;       //acceleration trigge
            INT32 tolerance;
            INT8 l_val;
            INT8 r_val;
        }config;
    }VideoCounter_t;

    void vcInit(VideoCounter_t *);
    UINT8 vcAddNewValue(VideoCounter_t*,UINT16 );

    void vc_setup(VideoCounter_t *,INT32 tolerance,INT32 trig,INT8 l_values,INT8 r_values);
    void vc_result(VideoCounter_t *,UINT16 *value,UINT16 *time);
    #ifdef __cplusplus
        }
    #endif
#endif
