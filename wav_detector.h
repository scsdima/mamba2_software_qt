#ifndef WAV_DETECTOR_H
    #define WAV_DETECTOR_H


    #ifdef __cplusplus
        extern "C"{

    #endif

    #define ABS(X) ((X)<0?(-(X)):(X))

    typedef struct {
        //dynamic values
        quint32         last_vs[10];      //last values
        quint32         last_v;          //last value
        quint32         av_col_vs[20];    //average color values
        quint32         av_col_vs_i;      //last average color index
        quint32         last_vs_i;        //last value index
        quint32         avlv;             //last value
        quint32         cur_v;            //curent value
        quint32         next_v;           //next value
        quint32         ref_v;            //ref values
        quint32         wval;             //acceleration value

        struct{
            bool        alarm      1;
            bool        firststart 1; //
        }status;
        struct{
            quint32     wtrigger;       //acceleration trigge
            quint32     tolerance;
            qint32      l_val;
            qint32      r_val;
        }config;
    }VideoCounter_t;

    void vcInit(VideoCounter_t *pvc);
    quint8 vcAddNewValue(VideoCounter_t*pvc, quint32 value);

    void vc_setup(VideoCounter_t *pvc,quint32 tolerance,quint32 trig,qint8 l_values,qint8 r_values);
    void vc_result(VideoCounter_t *pvc,quint16 *pvalue, quint16 *ptime);
    #ifdef __cplusplus
        }
    #endif
#endif
