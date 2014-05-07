#ifndef CONFIG_H
#define CONFIG_H

#include "version/version.h"

#define VERSION_SW "1.03"

/* wav detector options*/
   #define DEFAULT_COLOR_TOLERANCE (50)
   #define DEFAULT_WTRIGGER (100000)
   #define DEFAULT_LAST_VALUES_COUNT (7)
   #define DEFAULT_REFERENCE_VALUES_COUNT (10)

/* graphic points*/
    #define GRAPHIC_POINTS (1000)
    #define GRAPHIC_LINES  (4)

static  const char about_text[] =
         "<HTML><BODY LANG=\"en-US\" DIR=\"LTR\">"
         "<P STYLE=\"margin-bottom: 0in\"><FONT FACE=\"Arial, sans-serif\"><FONT SIZE=5><B>Mamba sensor software</B></FONT></FONT></P>"
         "<P STYLE=\"margin-bottom: 0in\"><FONT FACE=\"Arial, sans-serif\">Techno Invention SRO</FONT></P>"
         "<P STYLE=\"margin-bottom: 0in\"><FONT FACE=\"Arial, sans-serif\">Brno , Czech Republic</FONT></P>"
         "<P STYLE=\"margin-bottom: 0in\"><A HREF=\"http://www.techno-invention.com/\"><FONT FACE=\"Arial, sans-serif\">www.techno-invention.com</FONT></A></P>"
         "<P STYLE=\"margin-bottom: 0in\"><FONT FACE=\"Arial, sans-serif\">sales@techno-invention.com</FONT></P>"
        "<P STYLE=\"margin-bottom: 0in\"><FONT FACE=\"Arial, sans-serif\">version:"VERSION_SW " (from:" VERSION_DATE ")</FONT></P>"
         "</BODY></HTML>";

#define BUTTON_SELECTED "background-color: rgb(255, 170,100)"
static const char COLOR_ACTIVE[] = BUTTON_SELECTED;
static const char BUTTON_NOTSELECTED[] = " ";

static const char TEXT_OK[] ="Ok";
static const char TEXT_CANCEL[] ="Cancel";
static const char TEXT_ERROR[] ="Error";

static const char TIMEDATE_FORMAT[] = "yy.MM.dd hh:mm:ss";
static const char DATETIME_FORMAT_FOR_VERSION[]  ="ddd MMM d hh:mm:ss yyyy";
static const char BUTTON_FRAMED[] = "border-color: rgb(255, 170, 0)";
/*[UPDATE]*/
#define USE_FTP     (false)
static const char UPDATE_URL[] ="http://www.techno-invention.com/update/download.php";

static const char FILE_SETTINGS_INI[] = "config.ini";

#endif
