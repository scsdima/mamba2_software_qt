/* *********************************************************************


  @File:mamba2reg.h

  @Project: E:\workspace_test\1
  @Date: 2014\01\09 21-29-14
  @Description: $d


 
 ********************************************************************* */


#ifndef MAMBA2REG_H
    #define MAMBA2REG_H
    #include <QtGlobal>


    #ifdef __cplusplus
     extern "C"{
    #endif


/* ********************************************************************* 
  @Return: 	3300 mV
  @Description: system power voltage +V ref
 
 ********************************************************************* */
    #define MAMBA_VDD       (3300)

/* ********************************************************************* 
  @Return: (#define MAMBA_ADC_RES) 
  @Description: ADC resolution
 
 ********************************************************************* */
    #define MAMBA_ADC_RES   (1024)

/* ********************************************************************* 
  @Return: mV
  @Description: System power
 
 ********************************************************************* */
    #define SYSTEM_POWER    (MAMBA_VDD)


    #pragma pack(push, 1)
    typedef union {
        struct {
            unsigned Alarm         : 1;
            unsigned CableState    : 2;
            unsigned Tamper1       : 1;
            unsigned Tamper2       : 1;
            unsigned DataReceived  : 1;
            unsigned AccMove       : 1;
            unsigned PowerProblem  : 1;
            unsigned TesterEnabled : 1;
            unsigned selftest_ok   : 1;
            unsigned selftest_req  : 1;
            unsigned DigitalIn:1;
            unsigned Warning:1;
        }bits;
        quint16 value;
    }Status_t;

    typedef union {
        struct {
            unsigned Acc : 1;
            unsigned Pwr : 1;
            unsigned CableEnd : 1;
            unsigned Di : 1;
        } bits;
        unsigned char val;
    } TamperSetting;

//    typedef struct{
//        quint8 pre;
//        quint8 adr;
//        quint8 sum;
//        quint8 cmd;
//        union{
//            quint8 db[4];
//            quint32 val;
//            struct{
//            quint16 hval;
//            quint16 lval;
//            };
//        }data;
//    }t_cmd;

//    typedef struct{
//        quint8 pre;
//        quint8 adr;
//        quint8 sum;
//        quint8 cmd;
//        struct{
//        quint16 a0;
//        Status_t status;
//        quint16 a1;
//        quint16 a2;
//        quint32 wsig;
//        }data;
//    }t_advanced_cmd;

    enum DETECTION_MODE{MODE_CLA=0,MODE_VAC,MODE_VOC,MODE_WAV};

    typedef struct  {
        quint8   __crc;
        quint8   PotentiometerValue;
        quint8   PortSpeed;
        quint8   DetectionMode;
        quint8 ProfieN;
        quint8   AccSensitivity;
        quint16  PowerTrig;
        quint16  AlarmDuration;
        quint16  Tamper1Duration;
        quint16  Tamper2Duration;
        quint16  DigitalInSens;
        TamperSetting   t1src;
        TamperSetting   t2src;
        //detections
        struct
        {
            quint32  VaveletTolerance;
            quint32  VaveletWTrig;
            quint8   VaveletLastCount;
            quint8   VaveletReferenceCount;
            quint16  ClassicTriggerSum;
            quint16  ClassicTriggerCount;
            quint16  ClassicTriggerValue;
        }DetectionConfig;
    } Config_t;
  #pragma pack(pop)

    typedef enum BaudRates{ sicBAUD9600 = 0,
                            sicBAUD14400 = 1,
                            sicBAUD19200 = 2 } MambaBaudRates_t;

     typedef enum { POT_POS1=0, POT_POS2,
                    POT_POS3,POT_POS4,POT_POS5,POT_POS6,
                    POT_POS7,POT_POS8,POT_POS9,POT_POS10,
                    POT_POS11,POT_POS12,POT_POS13,POT_POS14,
                    POT_POS15,POT_POS16,POT_POS17,POT_POS18,
                    POT_POS19,POT_POS20 ,POT_MAX} MambaPotPosition_t;

    typedef enum {PWR_7V,  PWR_8V, PWR_9V, PWR_10V,
                  PWR_11V, PWR_12V, PWR_13V, PWR_14V,
                  PWR_15V, PWR_MAX} MambaPowerVoltage_t;

     static const quint16 std_pot_values[POT_MAX]
             = {255, 200, 180 , 160, 130, 100, 80, 50, 30, 25,
               20, 16,  14  ,  12,  10,  9, 8, 7, 6, 5};

     static const quint16 std_power_trig[PWR_MAX]
             = {300, 340, 380, 425, 470, 510, 550, 600, 640};


     extern Config_t     MambaCfg;
     extern Status_t     MambaStatus;



/* ********************************************************************* 
  @Function name: __getIndexOf__
  @Return: (static qint16) 
  @Parameters: 
	quint16 val
	 const quint16 arr[]
	 quint16 arr_size 
  @Description: $d
 
 ********************************************************************* */
     static qint16  __getIndexOf__(quint16 val, const quint16 arr[], quint16 arr_size) {
         qint16 i=0;
         for(; i < (qint16)arr_size; i++) {
             if( arr[i] == val ) {
                 return i;
             }
         }
         return -1;
     }

    /* if out of range returns -1*/

/* ********************************************************************* 
  @Function name: getPotPosition
  @Return: (inline static qint16) 
  @Parameters: 
	quint16 val 
  @Description: $d
 
 ********************************************************************* */
    static qint16 getPotPositionByValue(quint16 val){
        return __getIndexOf__(val, std_pot_values , POT_MAX);
    }

/* ********************************************************************* 
  @Function name: getPotPosition
  @Return: (inline static qint16) 
  @Parameters: 
	quint16 val 
  @Description: $d
 
 ********************************************************************* */
   static qint16 getValueByPotPosition(quint16 val){
        return (val<POT_MAX)? std_pot_values[val]: (-1);
    }

    /* if out of range returns -1*/

/* ********************************************************************* 
  @Function name: getPowerTrigger
  @Return: (inline static qint16) 
  @Parameters: 
	quint16 val 
  @Description: $d
 
 ********************************************************************* */
   static qint16 getPowerTriggerIndexByValue(quint16 val){
        return __getIndexOf__(val, std_power_trig, PWR_MAX)+7;
    }

/* ********************************************************************* 
  @Function name: getPowerTrigger
  @Return: (inline static qint16) 
  @Parameters: 
	quint16 val 
  @Description: $d
 
 ********************************************************************* */
    static qint16 getValueByPowerTriggerIndex(quint16 val){
        return ((val-7)<PWR_MAX) ? std_power_trig[val-7]: (-1);
    }


/* ********************************************************************* 
  @Function name: convertToMambaVoltage
  @Return: (inline static double) 
  @Parameters: 
	quint16 value 
  @Description: $d
 
 ********************************************************************* */
   static double convertToMambaVoltage(quint16 value) {
        double voltage = (double)value*((double)MAMBA_VDD/MAMBA_ADC_RES);
        return voltage;
    }


/* ********************************************************************* 
  @Function name: convertVoltageToMamba
  @Return: (inline static quint16) 
  @Parameters: 
	double voltage 
  @Description: $d
 
 ********************************************************************* */
    static quint16 convertVoltageToMamba(double voltage) {
        double value = (double)(voltage * MAMBA_ADC_RES / MAMBA_VDD );
        return (quint16)value;
    }


/* ********************************************************************* 
  @Function name: mVoltagePerPoint
  @Return: (inline static double) 
  @Parameters: 
	 
  @Description: $d
 
 ********************************************************************* */
    static double mVoltagePerPoint()    {
        return ((double)SYSTEM_POWER/(double)MAMBA_ADC_RES);
    }


/* ********************************************************************* 
  @Function name: toAnalogVoltage
  @Return: (inline  static double) 
  @Parameters: 
	double voltage 
  @Description: $d
 
 ********************************************************************* */
    static double toAnalogVoltage(double voltage) {
        return ((double)voltage*mVoltagePerPoint());
    }

/* ********************************************************************* 
  @Function name: fromVoltage
  @Return: (inline static  double) 
  @Parameters: 
	double voltage 
  @Description: $d
 
 ********************************************************************* */
     static  double fromVoltage(double voltage)     {
        return ((double)voltage/mVoltagePerPoint());
    }

/* ********************************************************************* 
  @Function name: toADCValue
  @Return: (inline static double) 
  @Parameters: 
	double voltage 
  @Description: $d
 
 ********************************************************************* */
     static double toADCValue(double voltage)      {
        return ((double)voltage/mVoltagePerPoint());
    }


    #ifdef __cplusplus
       }
    #endif
#endif // MAMBA2REG_H

