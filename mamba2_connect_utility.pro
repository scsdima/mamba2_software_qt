
#-------------------------------------------------
#
# MAMBA 2 PROJECT file
#
#-------------------------------------------------
QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mamba2_connect_utility
TEMPLATE = app
RC_FILE = ti.rc

SOURCE_DIR = $$PWD
DESTDIR = $$SOURCE_DIR/../mamba2_connect_utility_build/

CONFIG(debug, debug|release|final) {
DEFINES += QT_DEBUG
}
CONFIG(release, debug|release|final){
message(RELEASE BUILD)
DEFINES += QT_DEBUG
}
CONFIG(final, debug|release|final){
message(>>>FINAL<<<)
    include ($$SOURCE_DIR/version/version.pri)
}

#-------------------------------------------------
#SOURCES
#-------------------------------------------------
SOURCES += \
    main.cpp\
    mainwindow.cpp \
    graphic.cpp \
    mamba2reg.cpp \
    wav_detector.c \
    customicon.cpp \
    downloadupdate.cpp \
    settings.cpp \
    crc.cpp \
    communication_m1.cpp \
    communication_m2.cpp

#-------------------------------------------------
#HEADERS
#-------------------------------------------------
HEADERS += \
    mainwindow.h \
    customtabwidget.h \
    graphic.h \
    mamba2reg.h \
    wav_detector.h \
    customicon.h \
    buffer.hpp \
    downloadupdate.h \
    version/version.h \
    config.h \
    communication.h \
    settings.h \
    savedsettings.h \
    crc.h \
    communication_m1.h \
    communication_m2.h \
    communication_func.h

#-------------------------------------------------
#FORMS
#-------------------------------------------------
FORMS += \
    mainwindow.ui \
    graphic.ui \
    settings.ui



INCLUDEPATH += $$SOURCE_DIR/qextserialport/ $$SOURCE_DIR/qwt/

LIBS += $$DESTDIR/qwt.dll

DEFINES += COMMUNICATION_METHOD2

win32 {
        CONFIG(debug, debug|release):  {
           LIBS += $$DESTDIR/qextserialportd.dll
        }
        else:    {
           LIBS += $$DESTDIR/qextserialport.dll
        }
}
unix{

}

RESOURCES += \
    single.qrc

OTHER_FILES += \
    ti.rc
