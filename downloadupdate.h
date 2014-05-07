

#ifndef DOWNLOADUPDATE_H
#define DOWNLOADUPDATE_H
#include <QString>
#include <QFtp>
#include <QFile>
#include <QUrl>
#include <QProgressDialog>
#include <QProcess>
#include <QtNetwork>
#include <QProgressBar>
#include <QDialog>
#include <QThread>
/*
  http://doc.qt.digia.com/4.7/network-http-httpwindow-cpp.html
  http://doc.qt.digia.com/4.7/network-http-httpwindow-h.html
  */


class AbstractDownloadUpdate : public QObject
{
    Q_OBJECT
public:

    AbstractDownloadUpdate(const QString url_string
                           ,const QString setup_file_name = "setup.exe"
                           ,bool settingQuietMode=false
                            ,QObject *parent=0);
    ~AbstractDownloadUpdate(){}

signals:
    void informationText(QString);

public slots:
    void slot_startUpdate(void );
    void slot_cancelUpdate(void);

protected:

    typedef enum { StepConnect
                   ,StepDownload
                   ,StepInstall
                   ,StepCancel} DownloadStep_t;



    typedef enum { DownloadSuspended
                   ,DownloadRunning = 1} DownloadState_t;

    DownloadStep_t  downloadStep;
    DownloadState_t downloadState;
    QProgressDialog *updateDialog;    
    QString     setupFileName;
    QString     versionFileName;
    QString     currentVersion;
    QDateTime   newVersionDateTime;
    QUrl        setupFileUrl;
    QFile        *file;
    QUrl         serverUrl;
    bool        stepResult;
    qint64      setupFileSize;
    bool    settingQuietMode;

    #define __GoNext() go();
    void go();

    virtual bool initConnection(void) =0;
    virtual bool getVersion(void) = 0;
    virtual bool downloadFile(void) = 0;
    virtual bool closeDownload(void) = 0;

    bool createFile(void);
    bool checkVersion(void);
    bool makeSetup(void);

    QString parseDatafromHtmlCustom(const QString &text,const QString tag1,const QString tag2);

private slots:
    void progressBarChanged(qint64,qint64);
};



class DownloadByHttp : public AbstractDownloadUpdate
{
    Q_OBJECT
public:
    DownloadByHttp(const QString url_string
                           ,const QString setup_file_name = "setup.exe"
                            ,bool settingQuietMode=false
                            ,QObject *parent=0);
    ~DownloadByHttp(){}
private:
    QNetworkReply *httpReply;
    QNetworkAccessManager qnam;
    int httpGetId;
    bool httpRequestAborted;

    virtual bool initConnection(void) ;
    virtual bool getVersion(void) ;
    virtual bool downloadFile(void) ;
    virtual bool closeDownload(void);

private slots:
    void http_commandFinished();
    void http_readyRead();       

};



//    void ftp_commandFinished(int,bool);



#endif // DowNLOADUPDATE_H
