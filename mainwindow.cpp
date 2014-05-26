/* *********************************************************************


  @File:mainwindow.cpp

  @Project: MAMBA2- Software
  @Date: 2014\01\09 21-15-57
  @Description: $d



 ********************************************************************* */


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customtabwidget.h"

#include "mamba2reg.h"
#include "communication.h"
#include "downloadupdate.h"

#include "config.h"


/* ********************************************************************* 
  @CONSTRUCTOR
  @Return: (MainWindow::MainWindow)
  @Parameters:
    QWidget *parent
  @Description: $d

 ********************************************************************* */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),m_conState(StateDisconnected)
{
    ui->setupUi(this);
    m_pmamba = new CommunicationProvider();
    setupCustomUi();
    loadUiState();
    loadConfigurationList() ;
    slot_UpdateUIState();
#ifdef QT_DEBUG
    qDebug()<<"Mamba2 start";
#endif
}


/* ********************************************************************* 
  @Function name: MainWindow::setupCustomUi
  @Return: (void)
  @Parameters:

  @Description: Makes setup for custom components in UI

 ********************************************************************* */
void MainWindow::setupCustomUi()
{
    this->statusBar()->setFont(QFont("Arial",11,QFont::Bold));
    ui->sens_rot->setRange(0,9,1);
    ui->act_ico->setIconOn(QImage(":/icoGreen"));
    ui->act_ico->setIconOff(QImage(":/icoOff"));
    ui->act_ico->set_on(false);
    ui->act_answ_ico->setIconOn(QImage(":/icoGreen"));
    ui->act_answ_ico->setIconOff(QImage(":/icoOff"));
    ui->act_answ_ico->set_on(false);

    formSettings = new Settings(0);
    QStringList portsList;
    m_pmamba->getPortsList(portsList);
    ui->portname_cmb->clear();
    ui->portname_cmb->addItems(portsList);
    ui->btnReset->setVisible(false);

    DownloadByHttp *update = new DownloadByHttp(QString(UPDATE_URL));
    ui->btnInformation->addAction(ui->actionAbout_this_tool);
    ui->btnInformation->addAction(ui->actionStart_updater);
    ui->btnInformation->addAction(ui->actionSettings);
    /* sty;e for application to have buttons orange color*/
    qApp->setStyleSheet(CUSTOM_STYLE);
    /*actions*/
    connect(ui->actionStart_updater,SIGNAL(triggered()),update,SLOT(slot_startUpdate()));
    connect(ui->actionAbout_this_tool,SIGNAL(triggered()),this,SLOT(slot_About()));
    connect(ui->actionSettings,SIGNAL(triggered()),this,SLOT(slot_Settings()));
    connect(ui->btnGType1,SIGNAL(clicked()),this,SLOT(slot_SetProfileN()));
    connect(ui->btnGType2,SIGNAL(clicked()),this,SLOT(slot_SetProfileN()));
    connect(ui->btnGType3,SIGNAL(clicked()),this,SLOT(slot_SetProfileN()));
    connect(ui->btnGType4,SIGNAL(clicked()),this,SLOT(slot_SetProfileN()));
    connect(ui->btnGType5,SIGNAL(clicked()),this,SLOT(slot_SetProfileN()));
    connect(ui->btnConnect,SIGNAL(toggled(bool)),this,SLOT(slot_ConnectSensor(bool)));
    connect(ui->btnSave,SIGNAL(clicked()),this,SLOT(slot_SaveFile()));
    connect(ui->btnLoad,SIGNAL(clicked()),this,SLOT(slot_LoadFile()));
    connect(ui->btnLiveView,SIGNAL(toggled(bool)),this,SLOT( slot_runStream(bool)));
    connect(ui->btnClear,SIGNAL(clicked()),this,SLOT(slot_ClearData()));
    connect(ui->sens_rot,SIGNAL(sliderReleased()),this,SLOT(slot_SetSensitivity()));
    connect(ui->extrasens_btn,SIGNAL(clicked()),this,SLOT(slot_SetSensitivity()));
    connect(ui->t1acc_cb,SIGNAL(clicked()),this,SLOT(slot_TamperSourceClicked()));
    connect(ui->t1cable_cb,SIGNAL(clicked()),this,SLOT(slot_TamperSourceClicked()));
    connect(ui->t1pwr_cb,SIGNAL(clicked()),this,SLOT(slot_TamperSourceClicked()));
    connect(ui->t2acc_cb,SIGNAL(clicked()),this,SLOT(slot_TamperSourceClicked()));
    connect(ui->t2cable_cb,SIGNAL(clicked()),this,SLOT(slot_TamperSourceClicked()));
    connect(ui->t2pwr_cb,SIGNAL(clicked()),this,SLOT(slot_TamperSourceClicked()));
    connect(ui->graph->actionApplyTrigger(),SIGNAL(triggered()),this,SLOT(slot_ApplyTriggers()));
    connect(m_pmamba,SIGNAL(portDisconnected()),this,SLOT(slot_shutdownSession()));
    connect(ui->btnUpdateFirmware,SIGNAL(clicked()),this,SLOT(slot_UpdateFirmware()));
    /* connection provider*/
    connect(m_pmamba,SIGNAL(textCommandAnswer(QString)),this,SLOT(slot_PrintTestMode(QString)));
    //MainWindow
    connect(m_pmamba,SIGNAL(commandAnswer(quint8,quint32,bool))
            ,this,SLOT(slot_CommandAnswer(quint8,quint32,bool)));
    //Graph
    connect(m_pmamba,SIGNAL(commandAnswer(quint8,quint32,bool))
            ,this->ui->graph,SLOT(gotCommandAnswer(quint8,quint32,bool)));
    connect(m_pmamba,SIGNAL(operationFinished()),this,SLOT(slot_completedOperation()));
    connect(m_pmamba,SIGNAL(activity(bool)),this,SLOT(slot_ActivityTX(bool)));
    connect(m_pmamba,SIGNAL(activity_answer(bool)),this,SLOT(slot_ActivityRX(bool)));
}



/* ********************************************************************* 
  @Function name: MainWindow::applyTriggers
  @Return: (void)
  @Parameters:

  @Description: Applying trigers to sensor

 ********************************************************************* */
void MainWindow::slot_ApplyTriggers()
{
#ifdef QT_DEBUG
    qDebug()<<"trigger:"<<ui->graph->trigger1();//!!!!
#endif
    m_pmamba->operation(m_currentAddress,FUNC_SET_CLATRIGVAL,ui->graph->trigger1());
}

/* ********************************************************************* 
  DESTRUCTOR
  @Return: (MainWindow::~MainWindow)
  @Parameters:

  @Description:

 ********************************************************************* */
MainWindow::~MainWindow(){
    delete ui;
}


/* ********************************************************************* 
  @Function name: MainWindow::loadConfigurationList
  @Return: (void)
  @Parameters:

  @Description: Loads para,eters currently on server.
  May be used for load and apply to the other sensor for quick setup

 ********************************************************************* */
void MainWindow::loadConfigurationList(){
    QSettings settings("./config.ini",QSettings::IniFormat);
    QStringList list = settings.childGroups();
    list.removeAt(list.indexOf("UI"));
    ui->config_lst->addItems(list);
}

/* ********************************************************************* 
  @Function name: MainWindow::populate_ui
  @Return: (void)
  @Parameters:

  @Description: SLOT: Populates data to form

 ********************************************************************* */
void MainWindow::slot_PopulateUi(){
    QString tmp;
    //detection mode
    ui->detmode_cmb->setCurrentIndex(MambaCfg.DetectionMode);
    //acc sensitivity
    ui->acc_sens_sl->setValue(MambaCfg.AccSensitivity);
    ui->accsens_ed->setText(QString::number(MambaCfg.AccSensitivity));
    //tmp=QString("-%1%").arg();
    ui->didown_sl->setValue(MambaCfg.DigitalInSens);
    //power trigger    
    qint32 i= getPowerTriggerIndexByValue( MambaCfg.PowerTrig);
    ui->pwrtrig_sl->setValue(i);
    //tampers
    ui->t1acc_cb->setChecked(MambaCfg.t1src.bits.Acc);
    ui->t1pwr_cb->setChecked(MambaCfg.t1src.bits.Pwr);
    ui->t1cable_cb->setChecked(MambaCfg.t1src.bits.CableEnd);
    ui->t2acc_cb->setChecked(MambaCfg.t2src.bits.Acc);
    ui->t2pwr_cb->setChecked(MambaCfg.t2src.bits.Pwr);
    ui->t2cable_cb->setChecked(MambaCfg.t2src.bits.CableEnd);

    //amplifier
    i = getPotPositionByValue(MambaCfg.PotentiometerValue);
    ui->sens_rot->setValue( i % 10);
    ui->extrasens_btn->setChecked( i >= 10);
    ui->pot_ed->setText(QString::number(MambaCfg.PotentiometerValue));


    switch(MambaCfg.ProfieN){
    case 0:
        break;
    case 1:
        ui->btnGType1->setChecked(true);
        break;

    case 2:
        ui->btnGType2->setChecked(true);
        break;

    case 3:
        ui->btnGType3->setChecked(true);
        break;

    case 4:
        ui->btnGType4->setChecked(true);
        break;
    case 5:
        ui->btnGType5->setChecked(true);
        break;

    }

    //expert
    ui->trigcnt_ed->setText(QString::number(MambaCfg.DetectionConfig.ClassicTriggerCount));
    ui->trigsum_ed->setText(QString::number(MambaCfg.DetectionConfig.ClassicTriggerSum));
    ui->trigval_ed->setText(QString::number(MambaCfg.DetectionConfig.ClassicTriggerValue));
    //
    ui->wtrigger_ed->setText(QString::number(MambaCfg.DetectionConfig.VaveletWTrig));
    ui->buflen_ed->setText(QString::number(MambaCfg.DetectionConfig.VaveletLastCount));
    ui->reflen_ed->setText(QString::number(MambaCfg.DetectionConfig.VaveletReferenceCount));
    ui->tolerance_ed->setText(QString::number(MambaCfg.DetectionConfig.VaveletTolerance));

    //graph
    ui->graph->setupTriggers(MambaCfg.DetectionConfig.VaveletWTrig
                             ,MambaCfg.DetectionConfig.ClassicTriggerCount
                             ,MambaCfg.DetectionConfig.ClassicTriggerSum
                             ,MambaCfg.DetectionConfig.ClassicTriggerValue);

}


/* ********************************************************************* 
  @Function name: MainWindow::on_remove_cfg_btn_clicked
  @Return: (void)
  @Parameters:

  @Description: SLOT: remove configuration button, eletes string from
                ini file

 ********************************************************************* */
void MainWindow::on_remove_cfg_btn_clicked(){
    QSettings settings("config.ini",QSettings::IniFormat);
    if(QMessageBox::information(this,tr(""),tr("Delete configuration save?")
                                ,QMessageBox::Yes, QMessageBox::No)
            == QMessageBox::Yes)    {
        settings.remove(ui->config_lst->currentItem()->text());
        delete ui->config_lst->currentItem();
    }
}


/* ********************************************************************* 
  @Function name: MainWindow::on_tofile_btn_clicked
  @Return: (void)
  @Parameters:

  @Description: SLOT save configuration to file button.
  It makes binary string in file config.ini in groupname of configuration

 ********************************************************************* */
void MainWindow::on_tofile_btn_clicked() {
    bool answ;
    QSettings settings("config.ini",QSettings::IniFormat);
    QString groupName = QInputDialog::getText(this,(""),tr("Configuration name:")
                                              ,QLineEdit::Normal,tr("my configuration"),&answ);
    if (answ && !groupName.isEmpty()
            && ui->config_lst->findItems(groupName,Qt::MatchExactly).isEmpty()) {
        settings.beginGroup(groupName);
        settings.setValue("config",QByteArray((char*)&MambaCfg
                                              ,sizeof(Config_t)).toHex().constData());
        settings.endGroup();
        ui->config_lst->addItem(groupName);
    }
    else    {
        QMessageBox::information(this,tr("")
                                 ,tr("Such configuration name already exists"), QMessageBox::Ok);
    }
}


/* ********************************************************************* 
  @Function name: MainWindow::slot_UpdateUIState
  @Return: (void)
  @Parameters:
    bool turn_on
  @Description: Update Ui and enables checks of buttons according
                to system state

 ********************************************************************* */
void MainWindow::slot_UpdateUIState(){

    bool connected = false;
    bool btn_connect_checked = false;
    bool stream_on = false;
    bool graph_has_data = (ui->graph->dataStorageDataCount()>0);

    switch(m_conState){
    case StateDisconnected:
        connected = false;
        btn_connect_checked =  false;
        break;
    case StateRequestConnect:
        connected = false;
        btn_connect_checked =  true;
        break;
    case StateConfigRead:
        connected = false;
        btn_connect_checked =  true;
        break;
    case StateConnected:
        connected = true;
        btn_connect_checked =  true;
        break;
    case StateLiveView:
        connected = true;
        btn_connect_checked =  true;
        stream_on = true;
        break;
    }
    QString  btn_connect_text = (connected==true)?tr("Disconnect"):tr("Connect");
    ui->btnConnect->setText(btn_connect_text);
    ui->btnConnect->setChecked(btn_connect_checked);
    ui->actionStart_updater->setEnabled(!connected);
    ui->actionSettings->setEnabled(!connected);
    ui->portname_cmb->setEnabled(!btn_connect_checked);
    ui->adr_cmb->setEnabled(!btn_connect_checked);
    ui->btnLiveView->setEnabled(connected);
    ui->graph->setEnabled(connected);
    ui->graph->plot->setEnabled(connected);
    ui->control_pn->setEnabled(connected);
    ui->btnLoad->setEnabled(!stream_on);
    ui->btnSave->setEnabled(graph_has_data && !stream_on);
    ui->btnClear->setEnabled(graph_has_data && !stream_on);
    QApplication::processEvents();
}


/* ********************************************************************* 
  @Function name: MainWindow::slot_Print
  @Return: (void)
  @Parameters:
    const QString text
  @Description: Orinting text to output of mainwindow

 ********************************************************************* */
void MainWindow::slot_Print(const QString text) {
    this->statusBar()->showMessage(tr(text.toLatin1()));
}


/* ********************************************************************* 
  @Function name: MainWindow::processStatus
  @Return: (void)
  @Parameters:
    quint32 val
  @Description: Checks status regoster

 ********************************************************************* */
void MainWindow::processStatus(quint32 val) {
    static Status_t status_old;
    static Status_t status;
    static Status_t status_dif;
    QDateTime dt = QDateTime::currentDateTime();
    status.value = val;
    status_dif.value = status_old.value ^ status.value;
    if(status_dif.bits.Alarm && status.bits.Alarm)    {
        ui->alarm_lst->addItem(dt.toString(TIMEDATE_FORMAT)+ " ALARM");
    }
    enableTester(status.bits.TesterEnabled);
    status_old = status;
}


/* ********************************************************************* 
  @Function name: MainWindow::enableTester
  @Return: (void)
  @Parameters:
    bool en
  @Description: Ebnables tester controls on MainWindow

 ********************************************************************* */
void MainWindow::enableTester(bool en) {
    ui->tester_tab->setEnabled(en);
    ui->tester_tab->repaint();
}


/* ********************************************************************* 
  @Function name: MainWindow::
  @Return: (void)
  @Parameters:
    quint8 cmd
    quint32 cmd_p
    bool ok
  @Description: This SLOT get command answer

 ********************************************************************* */
void MainWindow::slot_CommandAnswer(quint8 cmd, quint32 cmd_p, bool ok)
{
    quint32 val = cmd_p;
    switch(cmd)
    {
    case FUNC_GET_STREAM:
    case FUNC_GET_ANA0_STATUS:
    {
        quint32 status_value = cmd_p >> 16;
        processStatus(status_value);
    }
        break;

    case FUNC_GET_STATUS:
        if(m_conState == StateRequestConnect)
        {
            if(ok) {
                m_conState = StateConfigRead;
                slot_Print(TEXT_OK);
                request_config();
            }
            else{
                m_conState = StateDisconnected;
                slot_Print(tr(TEXT_ERROR));
            }
            slot_UpdateUIState();
        }
        processStatus(cmd_p);
        break;
        //config common parameters
    case FUNC_GET_POTVAL:
        MambaCfg.PotentiometerValue=val;
        break;
    case FUNC_GET_BAUD:
        //MambaCfg.PortSpeed=val;
        break;
    case FUNC_GET_DETMODE:
        MambaCfg.DetectionMode = val;
        break;
    case FUNC_GET_ACCSENS:
        MambaCfg.AccSensitivity = val;
        break;
    case FUNC_GET_PWRTRIG:
        MambaCfg.PowerTrig = val;
        break;
    case FUNC_GET_T0DUR:
        MambaCfg.AlarmDuration = val;
        break;
    case FUNC_GET_T1DUR:
        MambaCfg.Tamper1Duration = val;
        break;
    case FUNC_GET_T2DUR:
        MambaCfg.Tamper2Duration = val;
        break;
    case FUNC_GET_DISENS:
        MambaCfg.DigitalInSens = val;
        break;
    case FUNC_GET_T1T2CFG:
        MambaCfg.t1src.val = val>>16;
        MambaCfg.t2src.val = val;
        break;
    case FUNC_GET_PROFILEN:
        MambaCfg.ProfieN = val;
        break;
    case FUNC_GET_SIGTRIG:
        MambaCfg.DetectionConfig.ClassicTriggerValue = val;
        break;
    case FUNC_GET_SIGTRIGSUM:
        MambaCfg.DetectionConfig.ClassicTriggerSum=val;
        break;
    case FUNC_GET_SIGTRIGCTR:
        MambaCfg.DetectionConfig.ClassicTriggerCount=val;
        break;
    case FUNC_GET_WAVWTRIG:
        MambaCfg.DetectionConfig.VaveletWTrig=val;
        break;
    case FUNC_GET_WAVTOLERANCE:
        MambaCfg.DetectionConfig.VaveletTolerance=val;
        break;
    case FUNC_GET_WAVLVAL:
        MambaCfg.DetectionConfig.VaveletLastCount=val;
        break;
    case FUNC_GET_WAVRVAL:
        MambaCfg.DetectionConfig.VaveletReferenceCount=val;

        break;
    case FUNC_READ: //read all config
        break;

    case FUNC_SET_PROFILEN:
        m_pmamba->operation(m_currentAddress,FUNC_GET_PROFILEN);//reread profile n
        m_pmamba->operation(m_currentAddress,FUNC_GET_SIGTRIG);//triggers
        break;

    default:
        break;

    }//switch

    if( (cmd >= FUNC_GET_POTVAL) && (cmd <FUNC_READ) && ok )   {
        slot_PopulateUi();
    }
}

/* ********************************************************************* 
  @Function name: MainWindow::slot_ActivityTX
  @Return: (void)
  @Parameters:
    bool on
  @Description: activity on tx symbols

 ********************************************************************* */
void MainWindow::slot_ActivityTX(bool on){
    ui->act_ico->set_on(on);
    ui->act_ico->repaint();
}

/* ********************************************************************* 
  @Function name: MainWindow::activity_answer
  @Return: (void)
  @Parameters:
    bool on
  @Description: activity on rx symbols

 ********************************************************************* */
void MainWindow::slot_ActivityRX(bool on){
    ui->act_answ_ico->set_on(on);
    ui->act_answ_ico->repaint();
}


/* ********************************************************************* 
  @Function name: MainWindow::slot_completedOperation
  @Return: (void)
  @Parameters:

  @Description: When finished sending block of data

 ********************************************************************* */
void MainWindow::slot_completedOperation(){
    if(m_conState == StateConfigRead){
        m_conState = StateConnected;
        slot_Print(TEXT_OK);
        slot_PopulateUi();
    }
    slot_UpdateUIState();
}

/* ********************************************************************* 
  @Function name: MainWindow::on_defsetting_btn_clicked
  @Return: (void)
  @Parameters:

  @Description: $d

 ********************************************************************* */
void MainWindow::on_defsetting_btn_clicked() {    
    m_pmamba->operation(m_currentAddress,FUNC_DEFAULTS);
    m_pmamba->operation(m_currentAddress,FUNC_RESET);
    slot_shutdownSession();
}


/* ********************************************************************* 
  @Function name: MainWindow::request_config
  @Return: (void)
  @Parameters:

  @Description: $d

 ********************************************************************* */
void MainWindow::request_config() {
    m_conState = StateConfigRead;
    slot_Print("Reading configuration...");
    //common parameters
    m_pmamba->operation(m_currentAddress,FUNC_GET_POTVAL,0);//potentiometer value
    //m_pmamba->operation(adr,0x21,0);//baud rate
    m_pmamba->operation(m_currentAddress,FUNC_GET_DETMODE,0);//detection mode
    m_pmamba->operation(m_currentAddress,FUNC_GET_ACCSENS,0);//acc sens
    m_pmamba->operation(m_currentAddress,FUNC_GET_PWRTRIG,0);//power trigger
    //m_pmamba->operation(adr,0x25,0);//alarm duration
    //m_pmamba->operation(adr,0x26,0);//t1duration
    //m_pmamba->operation(adr,0x27,0);//t2 duration
    m_pmamba->operation(m_currentAddress,FUNC_GET_DISENS,0);//di sensitivity
    m_pmamba->operation(m_currentAddress,FUNC_GET_FWVER,0);
    m_pmamba->operation(m_currentAddress,FUNC_GET_PROFILEN,0);//Profile number
    m_pmamba->operation(m_currentAddress,FUNC_GET_T1T2CFG,0);//Tampers
    m_pmamba->operation(m_currentAddress,FUNC_GET_WVAL,0);
    //C mode
    m_pmamba->operation(m_currentAddress,FUNC_GET_SIGTRIG,0);//
    m_pmamba->operation(m_currentAddress,FUNC_GET_SIGTRIGSUM,0);//
    m_pmamba->operation(m_currentAddress,FUNC_GET_SIGTRIGCTR,0);//
    //v mode
    m_pmamba->operation(m_currentAddress,FUNC_GET_WAVWTRIG,0);//
    m_pmamba->operation(m_currentAddress,FUNC_GET_WAVTOLERANCE,0);//
    m_pmamba->operation(m_currentAddress,FUNC_GET_WAVLVAL,0);//
    m_pmamba->operation(m_currentAddress,FUNC_GET_WAVRVAL,0);//
    //signals
    m_pmamba->operation(m_currentAddress,FUNC_GET_ANA1);//
    m_pmamba->operation(m_currentAddress,FUNC_GET_ANA2);//
    m_pmamba->operation(m_currentAddress,FUNC_GET_DEVID);//
}


/* ********************************************************************* 
  @Function name: MainWindow::on_fromdevice_btn_clicked
  @Return: (void)
  @Parameters:

  @Description: $d

 ********************************************************************* */
void MainWindow::on_fromdevice_btn_clicked() {
    request_config();
}

/* ********************************************************************* 
  @Function name: MainWindow::slot_SetProfileN
  @Return: (void)
  @Parameters:

  @Description: $d

 ********************************************************************* */
void MainWindow::slot_SetProfileN() {
    quint32 profile_n = 0;
    if(ui->btnGType1->isChecked()) profile_n = 1;
    if(ui->btnGType2->isChecked()) profile_n = 2;
    if(ui->btnGType3->isChecked()) profile_n = 3;
    if(ui->btnGType4->isChecked()) profile_n = 4;
    if(ui->btnGType5->isChecked()) profile_n = 5;
    m_pmamba->operation(m_currentAddress,FUNC_SET_PROFILEN,profile_n);//set profile n

}

/* ********************************************************************* 
  @Function name: MainWindow::on_pwrtrig_cmb_currentIndexChanged
  @Return: (void)
  @Parameters:
    int index
  @Description: $d

 ********************************************************************* */
void MainWindow::on_pwrtrig_sl_valueChanged(int value)
{
    qint32 pwrValue = getValueByPowerTriggerIndex(value);
    m_pmamba->operation(m_currentAddress,FUNC_SET_PWRTRIG,(quint32)pwrValue);
    MambaCfg.PowerTrig = (quint16)pwrValue;
}


/* ********************************************************************* 
  @Function name: MainWindow::on_didown_cmb_currentIndexChanged
  @Return: (void)
  @Parameters:
    int index
  @Description: $d

 ********************************************************************* */
void MainWindow::on_didown_sl_sliderMoved(int position)
{
    m_pmamba->operation(m_currentAddress,FUNC_SET_DISENS,(quint32)position);
    MambaCfg.DigitalInSens=(quint16)position;
}


/* ********************************************************************* 
  @Function name: MainWindow::slot_TamperSourceClicked
  @Return: (void)
  @Parameters:

  @Description: On tamper source control clicked to change source of tamper

 ********************************************************************* */
void MainWindow::slot_TamperSourceClicked(){
    TamperSetting t1;
    TamperSetting t2;
    t1.val = 0;
    t2.val = 0;
    t1.bits.Acc = ui->t1acc_cb->isChecked();
    t1.bits.Pwr = ui->t1pwr_cb->isChecked();
    t1.bits.CableEnd = ui->t1cable_cb->isChecked();
    t2.bits.Acc = ui->t2acc_cb->isChecked();
    t2.bits.Pwr = ui->t2pwr_cb->isChecked();
    t2.bits.CableEnd = ui->t2cable_cb->isChecked();
#ifdef QT_DEBUG
    qDebug()<<"tamper value:"<<t1.val<<t2.val;
#endif
    quint32 val32 = ( t1.val << 16) + t2.val;
    m_pmamba->operation(m_currentAddress,FUNC_SET_T1T2CFG,val32,3000);
}


/* ********************************************************************* 
  @Function name: MainWindow::on_acc_sens_sl_sliderReleased
  @Return: (void)
  @Parameters:

  @Description: $d

 ********************************************************************* */
void MainWindow::on_acc_sens_sl_sliderReleased()
{
    MambaCfg.AccSensitivity = (quint8)ui->acc_sens_sl->value();
    m_pmamba->operation(m_currentAddress, FUNC_SET_ACCSENS , ui->acc_sens_sl->value());
}
//saving windows controls positions


/* ********************************************************************* 
  @Function name: MainWindow::saveUiState
  @Return: (void)
  @Parameters:

  @Description: This function saves state of MainWindow amd controls on it

 ********************************************************************* */
void MainWindow::saveUiState(){
    QSettings settings("config.ini",QSettings::IniFormat);
    settings.beginGroup("UI");
    settings.setValue("axis_x_dial",ui->graph->axis_x_dial->value());
    settings.setValue("axis_y_dial",ui->graph->axis_y_dial->value());
    settings.setValue("port_n",ui->portname_cmb->currentIndex());
    settings.setValue("last_adr",ui->adr_cmb->currentIndex());
    settings.setValue("fw_ver",ui->fwver_cmb->currentIndex());
    settings.endGroup();
}


/* ********************************************************************* 
  @Function name: MainWindow::loadUiState
  @Return: (void)
  @Parameters:

  @Description: Loads last saved ui state from config.ini

 ********************************************************************* */
void MainWindow::loadUiState() {
    QSettings settings("config.ini",QSettings::IniFormat);
    settings.beginGroup("UI");
    ui->graph->setAxisXY((double)settings.value("axis_x_dial").toInt()
                         ,(double)settings.value("axis_y_dial").toInt());
    /* last opened/used port number restoring*/
    qint32  port_n = settings.value("port_n").toInt();
    if(port_n < ui->portname_cmb->count()){
        ui->portname_cmb->setCurrentIndex(port_n);
    }
    ui->adr_cmb->setCurrentIndex(settings.value("last_adr",0).toInt());
    ui->fwver_cmb->setCurrentIndex(settings.value("fw_ver",0).toUInt());
    settings.endGroup();
}


/* ********************************************************************* 
  @Function name: MainWindow::closeEvent
  @Return: (void)
  @Parameters:
    QCloseEvent *ev
  @Description: on close window event

 ********************************************************************* */
void MainWindow::closeEvent(QCloseEvent *ev) {
    slot_shutdownSession();
    saveUiState();
    ev->accept();

}


/* ********************************************************************* 
  @Function name: MainWindow::test_slot_Print
  @Return: (void)
  @Parameters:
    const QString text
  @Description: slot for print from test mode command

 ********************************************************************* */
void MainWindow::slot_PrintTestMode(const QString text) {
    ui->testconsole_lst->insertPlainText("\n");
    ui->testconsole_lst->insertHtml(text);
    QTextCursor c = ui->testconsole_lst->textCursor();
    c.movePosition(QTextCursor::End);
    ui->testconsole_lst->setTextCursor(c);
}


/* *********************************************************************
  @Function name: MainWindow::slot_shutdownSession(void)
  @Return: (void)
  @Parameters:

  @Description: shutdown session of communication

 ********************************************************************* */
void MainWindow::slot_shutdownSession(void){
#ifdef QT_DEBUG
    qDebug()<<"shutdown";
#endif
    if(m_conState == StateLiveView ){
        slot_runStream(false);
        slot_UpdateUIState();
    }
    slot_ConnectSensor(false);
    slot_UpdateUIState();
    bool graph_has_data = (ui->graph->dataStorageDataCount()>0);
    if(graph_has_data){
        if(QMessageBox::information(this,tr(""),tr("Unsaved data available. Save?")
                                    ,QMessageBox::Yes, QMessageBox::No)
                == QMessageBox::Yes)    {
            slot_SaveFile();
            ui->graph->clearData();
        }
    }
}


/* ********************************************************************* 
  @Function name: MainWindow::on_pushButton_5_clicked
  @Return: (void)
  @Parameters:

  @Description: $d

 ********************************************************************* */
void MainWindow::on_pushButton_5_clicked() {
    m_pmamba->operation(m_currentAddress, FUNC_RESET ,0,20000);
    ::Sleep(500);
    slot_shutdownSession();
    slot_Print("resetting sensor...");
    slot_UpdateUIState();
}


/* ********************************************************************* 
  @Function name: MainWindow::on_pushButton_clicked
  @Return: (void)
  @Parameters:

  @Description: $d

 ********************************************************************* */
void MainWindow::on_pushButton_clicked() {
    slot_Print("Rewriting configuration...");
    m_pmamba->operation(m_currentAddress,FUNC_SET_POTVAL, MambaCfg.PotentiometerValue);
    m_pmamba->operation(m_currentAddress,FUNC_SET_DETMODE,ui->detmode_cmb->currentIndex());//detection modeS
    m_pmamba->operation(m_currentAddress,FUNC_SET_CLATRIGCTR,ui->trigcnt_ed->text().toUInt());
    m_pmamba->operation(m_currentAddress,FUNC_SET_CLATRIGVAL,ui->trigval_ed->text().toUInt());
    m_pmamba->operation(m_currentAddress,FUNC_SET_CLATRUGSUM,ui->trigsum_ed->text().toUInt());
    m_pmamba->operation(m_currentAddress,FUNC_SET_WAVLVAL,ui->reflen_ed->text().toUInt());
    m_pmamba->operation(m_currentAddress,FUNC_SET_WAVRVAL,ui->buflen_ed->text().toUInt());
    m_pmamba->operation(m_currentAddress,FUNC_SET_WAVWTRIG,ui->wtrigger_ed->text().toUInt());
    m_pmamba->operation(m_currentAddress,FUNC_SET_WAVTOLERACE,ui->tolerance_ed->text().toUInt());
    m_pmamba->operation(m_currentAddress,FUNC_SET_ACCSENS,ui->accsens_ed->text().toUInt());
}


/* ********************************************************************* 
  @Function name: MainWindow::on_pushButton_3_clicked
  @Return: (void)
  @Parameters:

  @Description: $d

 ********************************************************************* */
void MainWindow::on_pushButton_3_clicked() {
    m_pmamba->text_command("init\n");
    slot_PrintTestMode("<font color=\"blue\"><b>init<b></font>");
}


/* ********************************************************************* 
  @Function name: MainWindow::on_pushButton_2_clicked
  @Return: (void)
  @Parameters:

  @Description: $d

 ********************************************************************* */
void MainWindow::on_pushButton_2_clicked() {
    m_pmamba->text_command("get status\n");
    slot_PrintTestMode("<font color=\"blue\"><b>get status<b></font>");
}


/* ********************************************************************* 
  @Function name: MainWindow::on_sendtxtcmd_btn_clicked
  @Return: (void)
  @Parameters:

  @Description: $d

 ********************************************************************* */
void MainWindow::on_sendtxtcmd_btn_clicked() {
    QString tmp=ui->textcmd_ed->text()+"\n";
    m_pmamba->text_command(tmp.toLatin1());
    slot_PrintTestMode(QString("<font color=\"blue\"><b>%1<b></font>").arg(tmp));
}


/* ********************************************************************* 
  @Function name: MainWindow::slot_runStream
  @Return: (void)
  @Parameters:
    bool on - (true) stream run
  @Description: starts and stops stream

 ********************************************************************* */
void MainWindow::slot_runStream(bool on) {
    CommunicationProvider::StreamType_t stream_type;
    if(on){
        if(ui->fwver_cmb->currentIndex() == 0) {
            stream_type = CommunicationProvider::Stream0A;
        }
        else {
            stream_type = CommunicationProvider::Stream0F;
        }
        m_conState = StateLiveView;
    }
    else{
        m_conState = StateConnected;
        stream_type = CommunicationProvider::StreamStop;
    }
    m_pmamba->startStream(m_currentAddress,5/*hz*/,stream_type);
    slot_UpdateUIState();
}


/* ********************************************************************* 
  @Function name: MainWindow::on_alarm_lst_clicked
  @Return: (void)
  @Parameters:
    const QModelIndex &index
  @Description: $d

 ********************************************************************* */
void MainWindow::on_alarm_lst_clicked(const QModelIndex &index){
    slot_runStream(false);
    ui->graph->setTimeLineCursor(extDateTime(ui->alarm_lst->item(index.row())->text()));
}


/* ********************************************************************* 
  @Function name: MainWindow::extDateTime
  @Return: (QDateTime)
  @Parameters:
    QString text
  @Description: Extract time date format from text in format
                TIMEDATE_FORMAT
 ********************************************************************* */
QDateTime MainWindow::extDateTime(QString text){
    QDateTime dtm;
    text.chop(text.size() - sizeof(TIMEDATE_FORMAT)+1);
#ifdef QT_DEBUG
    qDebug() << text;
#endif
    dtm = QDateTime::fromString(text, TIMEDATE_FORMAT);
    dtm = dtm.addYears(100);// need to add 100 years
    return dtm;
}

/* *********************************************************************
  @Function name: MainWindow::on_actionAbout_this_tool_triggered
  @Return: (void)
  @Parameters:

  @Description: Opens about window

 ********************************************************************* */
void MainWindow::slot_About(){
    QMessageBox::information(this,tr("About"),QString(about_text));
}

/* *********************************************************************
  @Function name: MainWindow::slot_ClearData
  @Return: (void)
  @Parameters:

  @Description: This function clears data in data storer(graphic)

 ********************************************************************* */
void MainWindow::slot_ClearData(){
#ifdef QT_DEBUG
    qDebug() << "clear";
#endif

    ui->graph->clearData();
    /*Stop recording*/
    slot_UpdateUIState();
}

/* *********************************************************************
  @Function name: MainWindow::slot_LoadFile()
  @Return: (void)
  @Parameters:

  @Description: Loads data from file *.dat

 ********************************************************************* */
void MainWindow::slot_LoadFile()
{
    QString  filename = QFileDialog::getOpenFileName(this
                                                     ,tr("Open flle")
                                                     , ""
                                                     , tr("Files (*.dat)"));
    ui->graph->load(filename);
}

/* *********************************************************************
  @Function name: MainWindow::slot_ConnectSensor
  @Return: (void)
  @Parameters:
    bool checked - tryies to connect sensor
  @Description: $d

 ********************************************************************* */
void MainWindow::slot_ConnectSensor(bool checked)
{
    QString portname = ui->portname_cmb->currentText();
    portname.remove(portname.indexOf("("),portname.count());
#ifdef QT_DEBUG
    qDebug() << portname << checked;
#endif
    m_currentAddress = ui->adr_cmb->currentText().toInt();
    if(checked )    {
        if(m_pmamba->connectToSerialPort(portname)) {
            m_conState = StateRequestConnect;
            m_pmamba->operation(m_currentAddress,FUNC_GET_STATUS,0,500);
            return;
        }
    }
    else {
        m_conState = StateDisconnected;
        m_pmamba->disconnectFromSerialPort();
    }
    slot_UpdateUIState();
}


/* *********************************************************************
  @Function name: MainWindow::slot_SaveFile()
  @Return: (void)
  @Parameters:

  @Description: Save graphic *.dat to file

 ********************************************************************* */

void MainWindow::slot_SaveFile(){
    QString  filename=QFileDialog::getSaveFileName(this,tr("Save flle")
                                                   , "", tr("Files (*.dat)"));
    ui->graph->save(filename);
}

/* *********************************************************************
  @Function name: MainWindow::slot_Settings
  @Return: (void)
  @Parameters:

  @Description: Starts form settings

 ********************************************************************* */
void MainWindow::slot_Settings(){
    formSettings->setModal(true);
    formSettings->exec();
}

/* *********************************************************************
  @Function name: MainWindow::btnApplySavedConfig_clicked()
  @Return: (void)
  @Parameters:

  @Description: This fnction make apply for config saved ini
                config.ini file

 ********************************************************************* */
void MainWindow::on_btnApplySavedConfig_clicked(){
    QSettings settings(FILE_SETTINGS_INI,QSettings::IniFormat);
    QString groupName = ui->config_lst->item(ui->config_lst->currentRow())->text();

    settings.beginGroup(groupName);
    memcpy((char*)&MambaCfg
           ,QByteArray::fromHex(settings.value("config",new char(sizeof(Config_t))).toByteArray()).constData()
           ,sizeof(MambaCfg));
    settings.endGroup();
    slot_PopulateUi();
}

/* *********************************************************************
  @Function name: MainWindow::slot_SetSensitivity()
  @Return: (void)
  @Parameters:

  @Description: This function set sensitivity potentiometer to mamba

 ********************************************************************* */
void MainWindow::slot_SetSensitivity(){
    if(ui->extrasens_btn->isChecked()){
        QMessageBox::warning(0,tr("Warning")
                             ,tr("Extra sensitivity mode is ON now!\n"
                                 "Depending on type of installation this may cause false alarms.")
                             ,QMessageBox::Ok);
    }
    else {

    }
    quint16 pos= (quint16)ui->sens_rot->value();
    pos += (quint16) (ui->extrasens_btn->isChecked()?10:0);
    MambaCfg.PotentiometerValue = getValueByPotPosition(pos);
    m_pmamba->operation(m_currentAddress,FUNC_SET_POTVAL,MambaCfg.PotentiometerValue);
}

/* *********************************************************************
  @Function name: MainWindow::slot_UpdateFirmware
  @Return: (void)
  @Parameters:

  @Description: Update firmware in sensor

 ********************************************************************* */
void MainWindow::slot_UpdateFirmware(void){
    QMessageBox::information(0,tr("[Update firmware]")
                             ,"Please contact vendor of product."
                             ,QMessageBox::Ok);
}

