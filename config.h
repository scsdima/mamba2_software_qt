#ifndef CONFIG_H
#define CONFIG_H

    #include "version/version.h"    

/* wav detector options*/
   #define DEFAULT_COLOR_TOLERANCE          (50)
   #define DEFAULT_WTRIGGER                 (100000)
   #define DEFAULT_LAST_VALUES_COUNT        (7)
   #define DEFAULT_REFERENCE_VALUES_COUNT   (10)

/* graphic points*/
    #define GRAPHIC_POINTS                  (1000)
    #define GRAPHIC_LINES                   (4)




static const char TEXT_OK[] ="Ok";
static const char TEXT_CANCEL[] ="Cancel";
static const char TEXT_ERROR[] ="Error";

static const char TIMEDATE_FORMAT[] = "yy.MM.dd hh:mm:ss";
static const char DATETIME_FORMAT_FOR_VERSION[]  ="ddd MMM d hh:mm:ss yyyy";


/*[UPDATE]*/
#define USE_FTP     (false)
static const char UPDATE_URL[] ="http://www.techno-invention.com/update/download.php";
static const char FILE_SETTINGS_INI[] = "config.ini";

#endif
