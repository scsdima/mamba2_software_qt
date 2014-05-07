/* *********************************************************************


  @File:downloadupdate.cpp

  @Project: E:\workspace_test\1
  @Date: 2014\01\09 21-39-34
  @Description: $d



 ********************************************************************* */


#include "downloadupdate.h"
#include <QMessageBox>
#include <QProcess>
#include <QApplication>
#include <QtDebug>
#include <QProcess>
#include <QDir>
#include<QMessageBox>
#include <QProgressBar>

#include "config.h"

/* *********************************************************************

  @CONSTRUCTOR: AbstractDownloadUpdate

  @Parameters:
        const QString url_string
        const QString setup_file_name
        QObject *parent
  @Description:


 ********************************************************************* */
AbstractDownloadUpdate::
AbstractDownloadUpdate(const QString url_string
                       ,const QString setup_file_name
                       ,bool settingQuietMode
                       ,QObject *parent)
    :QObject(parent)
{
    this->serverUrl = QUrl(url_string);
    this->versionFileName = "app.inf";
    this->setupFileName = QString("%1\\%2")
                            .arg(QDir::toNativeSeparators(QDir::currentPath()))
                            .arg(setup_file_name);
    this->settingQuietMode = settingQuietMode;
    this->downloadStep = StepCancel;
    this->file= NULL;
    updateDialog = new QProgressDialog(0);
    updateDialog->setWindowTitle(tr("[Download update]"));
    updateDialog->setLabelText(tr("Connecting..."));
    updateDialog->hide();
    connect(updateDialog,SIGNAL(canceled()),this,SLOT(slot_cancelUpdate()));
    connect(this,SIGNAL(informationText(QString)),updateDialog,SLOT(setLabelText(QString)));
    stepResult = false;
}

/* *********************************************************************
  @Function name: ::startUpdate
  @Return: (void)
  @Parameters:
    void
  @Description: $d

 ********************************************************************* */
void AbstractDownloadUpdate::
slot_startUpdate(void){
    if (!setupFileName.isEmpty() ){
        if (QFile::exists(setupFileName)) {
            QFile::remove(setupFileName);
        }
        file = new QFile(setupFileName);
        if (!file->open(QIODevice::WriteOnly)) {
            QMessageBox::information(0, tr("Update"),
                                     tr("Unable to save the file %1:\n %2.")
                                     .arg(setupFileName).arg(file->errorString()));
            delete file;
            file = NULL;
        }
        else{
            if(QUrl(this->serverUrl).isValid()){
                updateDialog->setModal(true);
                updateDialog->show();
                QApplication::sendPostedEvents();
                go();
            }
        }
    }
}

/* *********************************************************************
  @Function name: ::cancelUpdate
  @Return: (void)
  @Parameters:
    void
  @Description: $d

 ********************************************************************* */
void AbstractDownloadUpdate::
slot_cancelUpdate(void){
    downloadStep = StepConnect;
    updateDialog->hide();
    if(file != NULL){
        if(file->isOpen()){
            file->close();
        }
        delete file;
        file = NULL;
    }
    closeDownload();
}

/* *********************************************************************
  @Function name: :: go
  @Return: (void)
  @Parameters:
    bool
  @Description: $d

 ********************************************************************* */
void AbstractDownloadUpdate::
go()
{
    //const DownloadStep_t stepOrder[] = {StepConnect,StepDownload,StepInstall,StepCancel};
    bool result =false;
    if(stepResult == true){
        //kostyl
        downloadStep = (DownloadStep_t)((quint32)downloadStep+1);
    }
    else{
        downloadStep = StepConnect;
    }
    switch(downloadStep){

    case StepConnect:
#ifdef QT_DEBUG
        qDebug()<<"StepConnect";
#endif
        emit informationText(tr("Connecting..."));
        result = initConnection();
        emit informationText(tr("Getting version information..."));
        result |= getVersion();
        break;

    case StepDownload:
#ifdef QT_DEBUG
        qDebug()<<"StepDownload";
#endif
        emit informationText(tr("Checking version..."));
        if(checkVersion()){
            emit informationText(tr("Downloading update..."));
            result = downloadFile();
        }
        break;

    case StepInstall:
#ifdef QT_DEBUG
        qDebug()<<"StepInstall";
#endif
        emit informationText(tr("Running Setup file"));
        result = makeSetup();
        break;

    case StepCancel:
#ifdef QT_DEBUG
        qDebug()<<"StepCancel";
#endif
    default:
        result = closeDownload();
        break;
    }

    if(result != true ){
#ifdef QT_DEBUG
        qDebug()<<"Error Stop";
#endif
        slot_cancelUpdate();
    }
}


void AbstractDownloadUpdate::
progressBarChanged(qint64 bytesDownloaded,qint64 total){
#ifdef QT_DEBUG
    qDebug("%ld, %ld",(long int)setupFileSize,(long int)bytesDownloaded);
#endif
    updateDialog->setMaximum((int)setupFileSize);
    updateDialog->setValue((int)bytesDownloaded);
}



/* *********************************************************************
  @Function name: AbstractDownloadUpdate::  makeSetup
  @Return: (void)
  @Parameters:

  @Description: $d

 ********************************************************************* */
#include "windows.h"
bool AbstractDownloadUpdate::
makeSetup(void)
{

    if(file != NULL && file->isOpen()){
        file->flush();
        file->close();
    }
            QMessageBox::information(0,""
                                     ,QString(tr("Program need to be closed in order to install update\n"))
                                     ,QMessageBox::Ok);
    QProcess *execProcess = new QProcess(0);
    bool result = execProcess->startDetached("\""+setupFileName+"\"");
    if(result ){
        qApp->exit();
    }else{

     #if QT_DEBUG
    /*D*/    QMessageBox::information(0,"Error"
                                 ,QString("error running:")+setupFileName
                                 ,QMessageBox::Ok);
    #endif
    }
    return result;
}

/* *********************************************************************
  @Function name: DownloadUpdate::controlVersion
  @Return: (bool)  1- no need update , 0 - need update
  @Parameters:
    void
  @Description: $d

 ********************************************************************* */
bool AbstractDownloadUpdate::
    checkVersion(void )
{
    bool newVersionAvailable = false;
    QDateTime currentVersionDateTime
            = QDateTime::fromString(QString(VERSION_DATE)
                                    ,DATETIME_FORMAT_FOR_VERSION);
    if(currentVersionDateTime < newVersionDateTime){
        newVersionAvailable = true;
    }
#ifdef QT_DEBUG
    qDebug()<<"current:"<<currentVersionDateTime<<"new:"<<newVersionDateTime;
#endif
    if(newVersionAvailable){
        QMessageBox msgBox;
        msgBox.setText(tr("New version is available"));
        msgBox.setInformativeText(tr("do you want to update?"));
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        if(settingQuietMode )        {
           return true;
        }
        else if(msgBox.exec() == QMessageBox::Yes){
            return true;
        }

    }
    else{
        QMessageBox::information(0,"",tr("You have the latest version."));
    }
    return false;//false
}

/* *********************************************************************
  @Function name: DownloadUpdate::parseDatafromHtmlCustom
  @Return: (void)
  @Parameters:
        const QString &text -  text to parse
        const QString tag1 - tag1 begining
        const QString tag2	 - tag2 end
  @Description: get text between tag1 and tag2

 ********************************************************************* */
QString AbstractDownloadUpdate::parseDatafromHtmlCustom(const QString &text,const QString tag1,const QString tag2)
{
    QString result_text=text;
    qint32 pos_begin=  text.indexOf(tag1,0);
    qint32 pos_end=  text.indexOf(tag2,pos_begin);
    if(pos_begin >= 0 && pos_end > 0){
        result_text.remove(pos_end,result_text.size());
        result_text.remove(0,pos_begin+tag1.size());
    }
    return result_text;
}


/* *********************************************************************

  @CONSTRUCTOR: DownloadByHttp::DownloadByHttp

  @Parameters:
        const QString url_string
        const QString setup_file_name
        QObject *parent
  @Description:


 ********************************************************************* */
DownloadByHttp::DownloadByHttp(const QString url_string
                               ,const QString setup_file_name
                               ,bool settingQuietMode
                               ,QObject *parent)
    :AbstractDownloadUpdate(url_string,setup_file_name,parent)
{

}

/* *********************************************************************
  @Function name: DownloadByHttp ::closeDownload
  @Return: (bool)
  @Parameters:

  @Description: slot

 ********************************************************************* */
bool DownloadByHttp ::closeDownload(void)
{
    if(httpReply != NULL){
        httpReply->abort();
        httpReply->deleteLater();
    }
    return true;
}

/* *********************************************************************
  @Function name: DownloadByHttp ::connectServer
  @Return: (bool)
  @Parameters:

  @Description: slot

 ********************************************************************* */
bool DownloadByHttp ::initConnection(void) {

    return true;
}

bool DownloadByHttp ::getVersion(void) {
    bool result = false;
    httpReply = qnam.get(QNetworkRequest(this->serverUrl));
    if(httpReply != NULL ){
        ///TODO check server
        connect(httpReply, SIGNAL(finished()),
                this, SLOT(http_commandFinished()));
        result= true;
    }
    return result;
}

/* *********************************************************************
  @Function name: DownloadByHttp::downloadFile
  @Return: (bool)
  @Parameters:
    void
  @Description: $d

 ********************************************************************* */
bool DownloadByHttp ::downloadFile(void){
    bool result = false;

    httpReply = qnam.get(QNetworkRequest(this->setupFileUrl));
    if(httpReply != NULL){
        connect(httpReply, SIGNAL(finished()),
                this, SLOT(http_commandFinished()));
        connect(httpReply, SIGNAL(readyRead()),
                this, SLOT(http_readyRead()));
        connect(httpReply, SIGNAL(downloadProgress(qint64,qint64)),
                this, SLOT(progressBarChanged(qint64,qint64)));
        result = true;
    }
    return result;
}

/* ********************************************************************* 
  @Function name: DownloadUpdate::http_readyRead
  @Return: (void)
  @Parameters:

  @Description: SLOT reads data from html page

 ********************************************************************* */
void DownloadByHttp::http_readyRead()
{
    if(downloadStep == StepDownload){
        /* TODO insert downloading function*/
        if(file && file->isOpen()){
            file->write(httpReply->readAll());
        }
    }
}

/* *********************************************************************
  @Function name: DownloadUpdate::http_commandFinished
  @Return: (void)
  @Parameters:

  @Description: SLOT

 ********************************************************************* */
void DownloadByHttp::http_commandFinished()
{

    if(httpReply->error()){
         stepResult = false;
    }
    else{
        stepResult = true;
        if(downloadStep== StepConnect){
            QString text = httpReply->readAll();
            QString date_text = parseDatafromHtmlCustom(text,"<fver>","</fver>");
            QString size_text = parseDatafromHtmlCustom(text,"<fsize>","</fsize>");
            QString url_text = parseDatafromHtmlCustom(text,"<furl>","</furl>");
            if(!date_text.isEmpty() ){
                setupFileUrl =QUrl(url_text);
                newVersionDateTime = QDateTime::fromString(date_text,DATETIME_FORMAT_FOR_VERSION);
                setupFileSize = size_text.toInt();
#ifdef QT_DEBUG
                qDebug()<<text;
                qDebug()<<setupFileUrl;
                qDebug()<<newVersionDateTime;
                qDebug()<<size_text;
#endif
            }
            else{
               stepResult = false;
            }
        }
    }
    disconnect(this, SLOT(http_commandFinished()));
    disconnect(this, SLOT(http_readyRead()));
    disconnect(this, SLOT(progressBarChanged(qint64,qint64)));
    httpReply->deleteLater();
    __GoNext();
}

