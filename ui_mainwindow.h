/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "customicon.h"
#include "customtabwidget.h"
#include "graphic.h"
#include "qwt_knob.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout_this_tool;
    QAction *actionStart_updater;
    QAction *actionSettings;
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    CustomTabWidget *control_pn;
    QWidget *tab;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_9;
    QwtKnob *sens_rot;
    QLabel *label_16;
    QPushButton *extrasens_btn;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QGridLayout *gridLayout_4;
    QLabel *label_10;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_22;
    QLabel *label_23;
    QPushButton *btnGType2;
    QPushButton *btnGType3;
    QPushButton *btnGType4;
    QPushButton *btnGType5;
    QPushButton *btnGType1;
    QWidget *tab_6;
    QGridLayout *gridLayout_3;
    QCheckBox *t2cable_cb;
    QCheckBox *t1cable_cb;
    QCheckBox *t2pwr_cb;
    QCheckBox *t1pwr_cb;
    QLabel *label_11;
    QCheckBox *t2acc_cb;
    QCheckBox *t1acc_cb;
    QLabel *label_12;
    QCheckBox *t1acc_cb_2;
    QLabel *label_4;
    QLabel *label_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label_26;
    QSlider *acc_sens_sl;
    QLabel *label_25;
    QComboBox *pwrtrig_cmb;
    QLabel *label_5;
    QComboBox *didown_cmb;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_9;
    QWidget *tab_7;
    QGridLayout *gridLayout_11;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_2;
    QPushButton *fromdevice_btn;
    QPushButton *pushButton;
    QPushButton *defsetting_btn;
    QPushButton *pushButton_5;
    QTabWidget *tabWidget_2;
    QWidget *tab_5;
    QGridLayout *gridLayout_6;
    QComboBox *detmode_cmb;
    QLabel *label_21;
    QLineEdit *pot_ed;
    QLabel *label_24;
    QLineEdit *accsens_ed;
    QLabel *label_20;
    QWidget *tab_8;
    QGridLayout *gridLayout_7;
    QLabel *label_6;
    QLineEdit *trigsum_ed;
    QLabel *label_7;
    QLineEdit *trigcnt_ed;
    QLabel *label_8;
    QLineEdit *trigval_ed;
    QSpacerItem *horizontalSpacer;
    QLabel *label_19;
    QWidget *tab_9;
    QGridLayout *gridLayout_8;
    QLabel *label_14;
    QLineEdit *buflen_ed;
    QLabel *label_15;
    QLineEdit *reflen_ed;
    QLabel *label_2;
    QLineEdit *tolerance_ed;
    QLabel *label_13;
    QLineEdit *wtrigger_ed;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget;
    QGridLayout *gridLayout_10;
    QLabel *label_30;
    QLineEdit *passw_ed;
    QPushButton *btnUpdateFirmware;
    QLabel *label_29;
    QComboBox *fwver_cmb;
    QWidget *config_tab;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *config_lst;
    QVBoxLayout *verticalLayout;
    QPushButton *tofile_btn;
    QPushButton *remove_cfg_btn;
    QPushButton *btnApplySavedConfig;
    QWidget *tester_tab;
    QGridLayout *gridLayout_12;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *textcmd_ed;
    QPushButton *sendtxtcmd_btn;
    QSpacerItem *horizontalSpacer_3;
    QTextBrowser *testconsole_lst;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_31;
    QProgressBar *progressBar;
    QPushButton *pushButton_4;
    QListWidget *alarm_lst;
    QSpacerItem *horizontalSpacer_5;
    QFrame *connect_pn;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_9;
    QFrame *line;
    QComboBox *portname_cmb;
    QFrame *line_2;
    QLabel *label;
    QComboBox *adr_cmb;
    QPushButton *btnConnect;
    QFrame *line_3;
    QLabel *label_27;
    CustomIcon *act_ico;
    QLabel *label_28;
    CustomIcon *act_answ_ico;
    QFrame *line_4;
    QPushButton *btnSave;
    QPushButton *btnLoad;
    QPushButton *btnClear;
    QFrame *line_5;
    QPushButton *btnLiveView;
    QFrame *line_7;
    QPushButton *btnReset;
    QFrame *line_6;
    QToolButton *btnInformation;
    QSpacerItem *horizontalSpacer_2;
    Graphic *graph;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1221, 688);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(600, 600));
        MainWindow->setBaseSize(QSize(0, 600));
        actionAbout_this_tool = new QAction(MainWindow);
        actionAbout_this_tool->setObjectName(QString::fromUtf8("actionAbout_this_tool"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/ti.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_this_tool->setIcon(icon);
        QFont font;
        font.setPointSize(10);
        actionAbout_this_tool->setFont(font);
        actionStart_updater = new QAction(MainWindow);
        actionStart_updater->setObjectName(QString::fromUtf8("actionStart_updater"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/update_application.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart_updater->setIcon(icon1);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/settings-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(-1, 2, -1, 2);
        control_pn = new CustomTabWidget(centralWidget);
        control_pn->setObjectName(QString::fromUtf8("control_pn"));
        control_pn->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(control_pn->sizePolicy().hasHeightForWidth());
        control_pn->setSizePolicy(sizePolicy1);
        control_pn->setMinimumSize(QSize(0, 220));
        control_pn->setMaximumSize(QSize(16777215, 220));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        control_pn->setFont(font1);
        control_pn->setIconSize(QSize(20, 20));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(120, 0));
        groupBox->setFont(font1);
        gridLayout_9 = new QGridLayout(groupBox);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        sens_rot = new QwtKnob(groupBox);
        sens_rot->setObjectName(QString::fromUtf8("sens_rot"));
        sens_rot->setMinimumSize(QSize(80, 100));
        label_16 = new QLabel(sens_rot);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(0, 0, 93, 19));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        label_16->setFont(font2);
        label_16->setWordWrap(true);

        gridLayout_9->addWidget(sens_rot, 0, 0, 1, 2);

        extrasens_btn = new QPushButton(groupBox);
        extrasens_btn->setObjectName(QString::fromUtf8("extrasens_btn"));
        extrasens_btn->setMinimumSize(QSize(200, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        extrasens_btn->setFont(font3);
        extrasens_btn->setStyleSheet(QString::fromUtf8(""));
        extrasens_btn->setCheckable(true);

        gridLayout_9->addWidget(extrasens_btn, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 2, 1);

        tabWidget = new QTabWidget(tab);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setMinimumSize(QSize(500, 0));
        QFont font4;
        font4.setPointSize(8);
        tabWidget->setFont(font4);
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_4 = new QGridLayout(tab_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial"));
        font5.setBold(true);
        font5.setWeight(75);
        label_10->setFont(font5);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_10, 0, 1, 1, 1);

        label_17 = new QLabel(tab_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font5);
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_17, 0, 2, 1, 1);

        label_18 = new QLabel(tab_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font5);
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_18, 0, 4, 1, 1);

        label_22 = new QLabel(tab_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font5);
        label_22->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_22, 0, 5, 1, 1);

        label_23 = new QLabel(tab_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setMaximumSize(QSize(16777215, 20));
        label_23->setFont(font5);
        label_23->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_23, 0, 6, 1, 1);

        btnGType2 = new QPushButton(tab_4);
        btnGType2->setObjectName(QString::fromUtf8("btnGType2"));
        btnGType2->setMinimumSize(QSize(100, 78));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("images/02.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGType2->setIcon(icon3);
        btnGType2->setIconSize(QSize(70, 70));
        btnGType2->setCheckable(true);
        btnGType2->setAutoExclusive(true);

        gridLayout_4->addWidget(btnGType2, 1, 2, 2, 1);

        btnGType3 = new QPushButton(tab_4);
        btnGType3->setObjectName(QString::fromUtf8("btnGType3"));
        btnGType3->setMinimumSize(QSize(100, 78));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("images/03.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGType3->setIcon(icon4);
        btnGType3->setIconSize(QSize(70, 70));
        btnGType3->setCheckable(true);
        btnGType3->setAutoExclusive(true);

        gridLayout_4->addWidget(btnGType3, 1, 4, 2, 1);

        btnGType4 = new QPushButton(tab_4);
        btnGType4->setObjectName(QString::fromUtf8("btnGType4"));
        btnGType4->setMinimumSize(QSize(100, 78));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("images/04.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGType4->setIcon(icon5);
        btnGType4->setIconSize(QSize(70, 70));
        btnGType4->setCheckable(true);
        btnGType4->setAutoExclusive(true);

        gridLayout_4->addWidget(btnGType4, 1, 5, 2, 1);

        btnGType5 = new QPushButton(tab_4);
        btnGType5->setObjectName(QString::fromUtf8("btnGType5"));
        btnGType5->setMinimumSize(QSize(100, 78));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("images/05.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGType5->setIcon(icon6);
        btnGType5->setIconSize(QSize(70, 70));
        btnGType5->setCheckable(true);
        btnGType5->setAutoExclusive(true);

        gridLayout_4->addWidget(btnGType5, 1, 6, 2, 1);

        btnGType1 = new QPushButton(tab_4);
        btnGType1->setObjectName(QString::fromUtf8("btnGType1"));
        btnGType1->setMinimumSize(QSize(100, 78));
        btnGType1->setLayoutDirection(Qt::LeftToRight);
        btnGType1->setAutoFillBackground(false);
        btnGType1->setStyleSheet(QString::fromUtf8(""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("images/01.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGType1->setIcon(icon7);
        btnGType1->setIconSize(QSize(70, 70));
        btnGType1->setCheckable(true);
        btnGType1->setChecked(false);
        btnGType1->setAutoExclusive(true);
        btnGType1->setFlat(false);

        gridLayout_4->addWidget(btnGType1, 1, 1, 2, 1);

        tabWidget->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout_3 = new QGridLayout(tab_6);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        t2cable_cb = new QCheckBox(tab_6);
        t2cable_cb->setObjectName(QString::fromUtf8("t2cable_cb"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Arial"));
        font6.setPointSize(8);
        font6.setBold(false);
        font6.setWeight(50);
        t2cable_cb->setFont(font6);
        t2cable_cb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(t2cable_cb, 4, 1, 1, 1);

        t1cable_cb = new QCheckBox(tab_6);
        t1cable_cb->setObjectName(QString::fromUtf8("t1cable_cb"));
        t1cable_cb->setFont(font6);
        t1cable_cb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(t1cable_cb, 4, 0, 1, 1);

        t2pwr_cb = new QCheckBox(tab_6);
        t2pwr_cb->setObjectName(QString::fromUtf8("t2pwr_cb"));
        t2pwr_cb->setFont(font6);
        t2pwr_cb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(t2pwr_cb, 3, 1, 1, 1);

        t1pwr_cb = new QCheckBox(tab_6);
        t1pwr_cb->setObjectName(QString::fromUtf8("t1pwr_cb"));
        t1pwr_cb->setFont(font6);
        t1pwr_cb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(t1pwr_cb, 3, 0, 1, 1);

        label_11 = new QLabel(tab_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy3);
        QFont font7;
        font7.setFamily(QString::fromUtf8("Arial"));
        font7.setPointSize(8);
        font7.setBold(true);
        font7.setWeight(75);
        label_11->setFont(font7);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(label_11, 0, 0, 1, 1);

        t2acc_cb = new QCheckBox(tab_6);
        t2acc_cb->setObjectName(QString::fromUtf8("t2acc_cb"));
        t2acc_cb->setFont(font6);
        t2acc_cb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(t2acc_cb, 2, 1, 1, 1);

        t1acc_cb = new QCheckBox(tab_6);
        t1acc_cb->setObjectName(QString::fromUtf8("t1acc_cb"));
        t1acc_cb->setFont(font6);
        t1acc_cb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(t1acc_cb, 2, 0, 1, 1);

        label_12 = new QLabel(tab_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy3.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy3);
        label_12->setFont(font7);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(label_12, 0, 1, 1, 1);

        t1acc_cb_2 = new QCheckBox(tab_6);
        t1acc_cb_2->setObjectName(QString::fromUtf8("t1acc_cb_2"));
        t1acc_cb_2->setEnabled(false);
        t1acc_cb_2->setFont(font6);
        t1acc_cb_2->setStyleSheet(QString::fromUtf8(""));
        t1acc_cb_2->setChecked(true);

        gridLayout_3->addWidget(t1acc_cb_2, 1, 0, 1, 1);

        label_4 = new QLabel(tab_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font7);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(label_4, 0, 6, 1, 1);

        label_3 = new QLabel(tab_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font7);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(label_3, 0, 3, 1, 1);

        frame = new QFrame(tab_6);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFont(font4);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_26 = new QLabel(frame);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout->addWidget(label_26);

        acc_sens_sl = new QSlider(frame);
        acc_sens_sl->setObjectName(QString::fromUtf8("acc_sens_sl"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(acc_sens_sl->sizePolicy().hasHeightForWidth());
        acc_sens_sl->setSizePolicy(sizePolicy4);
        acc_sens_sl->setFont(font1);
        acc_sens_sl->setMinimum(3);
        acc_sens_sl->setMaximum(10);
        acc_sens_sl->setPageStep(1);
        acc_sens_sl->setOrientation(Qt::Horizontal);
        acc_sens_sl->setTickPosition(QSlider::TicksBelow);

        horizontalLayout->addWidget(acc_sens_sl);

        label_25 = new QLabel(frame);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout->addWidget(label_25);


        gridLayout_3->addWidget(frame, 2, 3, 2, 1);

        pwrtrig_cmb = new QComboBox(tab_6);
        pwrtrig_cmb->setObjectName(QString::fromUtf8("pwrtrig_cmb"));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Arial"));
        font8.setPointSize(8);
        pwrtrig_cmb->setFont(font8);
        pwrtrig_cmb->setEditable(false);

        gridLayout_3->addWidget(pwrtrig_cmb, 1, 6, 3, 1);

        label_5 = new QLabel(tab_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font7);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(label_5, 0, 8, 1, 1);

        didown_cmb = new QComboBox(tab_6);
        didown_cmb->setObjectName(QString::fromUtf8("didown_cmb"));
        didown_cmb->setFont(font8);
        didown_cmb->setEditable(false);

        gridLayout_3->addWidget(didown_cmb, 2, 8, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 2, 9, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 2, 7, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_8, 2, 4, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_9, 2, 2, 1, 1);

        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        gridLayout_11 = new QGridLayout(tab_7);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        groupBox_6 = new QGroupBox(tab_7);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        verticalLayout_2 = new QVBoxLayout(groupBox_6);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        fromdevice_btn = new QPushButton(groupBox_6);
        fromdevice_btn->setObjectName(QString::fromUtf8("fromdevice_btn"));
        fromdevice_btn->setFont(font2);

        verticalLayout_2->addWidget(fromdevice_btn);

        pushButton = new QPushButton(groupBox_6);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font8);

        verticalLayout_2->addWidget(pushButton);

        defsetting_btn = new QPushButton(groupBox_6);
        defsetting_btn->setObjectName(QString::fromUtf8("defsetting_btn"));
        defsetting_btn->setFont(font8);

        verticalLayout_2->addWidget(defsetting_btn);

        pushButton_5 = new QPushButton(groupBox_6);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font8);

        verticalLayout_2->addWidget(pushButton_5);


        gridLayout_11->addWidget(groupBox_6, 0, 2, 1, 1);

        tabWidget_2 = new QTabWidget(tab_7);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setTabPosition(QTabWidget::West);
        tabWidget_2->setElideMode(Qt::ElideNone);
        tabWidget_2->setUsesScrollButtons(true);
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_6 = new QGridLayout(tab_5);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        detmode_cmb = new QComboBox(tab_5);
        detmode_cmb->setObjectName(QString::fromUtf8("detmode_cmb"));
        detmode_cmb->setFont(font2);

        gridLayout_6->addWidget(detmode_cmb, 0, 2, 1, 1);

        label_21 = new QLabel(tab_5);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font2);

        gridLayout_6->addWidget(label_21, 1, 0, 1, 1);

        pot_ed = new QLineEdit(tab_5);
        pot_ed->setObjectName(QString::fromUtf8("pot_ed"));
        pot_ed->setFont(font2);

        gridLayout_6->addWidget(pot_ed, 1, 2, 1, 1);

        label_24 = new QLabel(tab_5);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setFont(font2);

        gridLayout_6->addWidget(label_24, 2, 0, 1, 1);

        accsens_ed = new QLineEdit(tab_5);
        accsens_ed->setObjectName(QString::fromUtf8("accsens_ed"));
        accsens_ed->setFont(font2);

        gridLayout_6->addWidget(accsens_ed, 2, 2, 1, 1);

        label_20 = new QLabel(tab_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font2);

        gridLayout_6->addWidget(label_20, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_5, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        gridLayout_7 = new QGridLayout(tab_8);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_6 = new QLabel(tab_8);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_7->addWidget(label_6, 0, 0, 1, 1);

        trigsum_ed = new QLineEdit(tab_8);
        trigsum_ed->setObjectName(QString::fromUtf8("trigsum_ed"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(trigsum_ed->sizePolicy().hasHeightForWidth());
        trigsum_ed->setSizePolicy(sizePolicy5);
        trigsum_ed->setMaximumSize(QSize(100, 16777215));

        gridLayout_7->addWidget(trigsum_ed, 0, 1, 1, 1);

        label_7 = new QLabel(tab_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_7->addWidget(label_7, 1, 0, 1, 1);

        trigcnt_ed = new QLineEdit(tab_8);
        trigcnt_ed->setObjectName(QString::fromUtf8("trigcnt_ed"));
        sizePolicy5.setHeightForWidth(trigcnt_ed->sizePolicy().hasHeightForWidth());
        trigcnt_ed->setSizePolicy(sizePolicy5);
        trigcnt_ed->setMaximumSize(QSize(100, 16777215));

        gridLayout_7->addWidget(trigcnt_ed, 1, 1, 1, 1);

        label_8 = new QLabel(tab_8);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_7->addWidget(label_8, 2, 0, 1, 1);

        trigval_ed = new QLineEdit(tab_8);
        trigval_ed->setObjectName(QString::fromUtf8("trigval_ed"));
        sizePolicy5.setHeightForWidth(trigval_ed->sizePolicy().hasHeightForWidth());
        trigval_ed->setSizePolicy(sizePolicy5);
        trigval_ed->setMaximumSize(QSize(100, 16777215));

        gridLayout_7->addWidget(trigval_ed, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer, 0, 3, 1, 1);

        label_19 = new QLabel(tab_8);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(200);
        sizePolicy6.setVerticalStretch(150);
        sizePolicy6.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy6);
        label_19->setMinimumSize(QSize(250, 100));
        label_19->setPixmap(QPixmap(QString::fromUtf8("images/signal.png")));
        label_19->setScaledContents(true);

        gridLayout_7->addWidget(label_19, 0, 2, 2, 1);

        tabWidget_2->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        gridLayout_8 = new QGridLayout(tab_9);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_14 = new QLabel(tab_9);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_8->addWidget(label_14, 0, 0, 1, 1);

        buflen_ed = new QLineEdit(tab_9);
        buflen_ed->setObjectName(QString::fromUtf8("buflen_ed"));
        sizePolicy5.setHeightForWidth(buflen_ed->sizePolicy().hasHeightForWidth());
        buflen_ed->setSizePolicy(sizePolicy5);
        buflen_ed->setMaximumSize(QSize(100, 16777215));

        gridLayout_8->addWidget(buflen_ed, 0, 1, 1, 1);

        label_15 = new QLabel(tab_9);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_8->addWidget(label_15, 1, 0, 1, 1);

        reflen_ed = new QLineEdit(tab_9);
        reflen_ed->setObjectName(QString::fromUtf8("reflen_ed"));
        sizePolicy5.setHeightForWidth(reflen_ed->sizePolicy().hasHeightForWidth());
        reflen_ed->setSizePolicy(sizePolicy5);
        reflen_ed->setMaximumSize(QSize(100, 16777215));

        gridLayout_8->addWidget(reflen_ed, 1, 1, 1, 1);

        label_2 = new QLabel(tab_9);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_8->addWidget(label_2, 2, 0, 1, 1);

        tolerance_ed = new QLineEdit(tab_9);
        tolerance_ed->setObjectName(QString::fromUtf8("tolerance_ed"));
        sizePolicy5.setHeightForWidth(tolerance_ed->sizePolicy().hasHeightForWidth());
        tolerance_ed->setSizePolicy(sizePolicy5);
        tolerance_ed->setMaximumSize(QSize(100, 16777215));

        gridLayout_8->addWidget(tolerance_ed, 2, 1, 1, 1);

        label_13 = new QLabel(tab_9);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_8->addWidget(label_13, 3, 0, 1, 1);

        wtrigger_ed = new QLineEdit(tab_9);
        wtrigger_ed->setObjectName(QString::fromUtf8("wtrigger_ed"));
        sizePolicy5.setHeightForWidth(wtrigger_ed->sizePolicy().hasHeightForWidth());
        wtrigger_ed->setSizePolicy(sizePolicy5);
        wtrigger_ed->setMaximumSize(QSize(100, 16777215));

        gridLayout_8->addWidget(wtrigger_ed, 3, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        tabWidget_2->addTab(tab_9, QString());

        gridLayout_11->addWidget(tabWidget_2, 0, 1, 1, 1);

        widget = new QWidget(tab_7);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_10 = new QGridLayout(widget);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_30 = new QLabel(widget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setEnabled(false);
        label_30->setFont(font1);

        gridLayout_10->addWidget(label_30, 0, 0, 1, 1);

        passw_ed = new QLineEdit(widget);
        passw_ed->setObjectName(QString::fromUtf8("passw_ed"));
        passw_ed->setEnabled(false);
        passw_ed->setEchoMode(QLineEdit::Password);

        gridLayout_10->addWidget(passw_ed, 0, 1, 1, 1);

        btnUpdateFirmware = new QPushButton(widget);
        btnUpdateFirmware->setObjectName(QString::fromUtf8("btnUpdateFirmware"));
        btnUpdateFirmware->setFont(font2);

        gridLayout_10->addWidget(btnUpdateFirmware, 1, 1, 1, 1);

        label_29 = new QLabel(widget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font1);

        gridLayout_10->addWidget(label_29, 2, 0, 1, 1);

        fwver_cmb = new QComboBox(widget);
        fwver_cmb->setObjectName(QString::fromUtf8("fwver_cmb"));
        fwver_cmb->setFont(font2);

        gridLayout_10->addWidget(fwver_cmb, 2, 1, 1, 1);


        gridLayout_11->addWidget(widget, 0, 0, 1, 1);

        tabWidget->addTab(tab_7, QString());
        config_tab = new QWidget();
        config_tab->setObjectName(QString::fromUtf8("config_tab"));
        horizontalLayout_2 = new QHBoxLayout(config_tab);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        config_lst = new QListWidget(config_tab);
        config_lst->setObjectName(QString::fromUtf8("config_lst"));
        config_lst->setFont(font);
        config_lst->setWordWrap(true);
        config_lst->setSortingEnabled(false);

        horizontalLayout_2->addWidget(config_lst);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tofile_btn = new QPushButton(config_tab);
        tofile_btn->setObjectName(QString::fromUtf8("tofile_btn"));

        verticalLayout->addWidget(tofile_btn);

        remove_cfg_btn = new QPushButton(config_tab);
        remove_cfg_btn->setObjectName(QString::fromUtf8("remove_cfg_btn"));

        verticalLayout->addWidget(remove_cfg_btn);

        btnApplySavedConfig = new QPushButton(config_tab);
        btnApplySavedConfig->setObjectName(QString::fromUtf8("btnApplySavedConfig"));

        verticalLayout->addWidget(btnApplySavedConfig);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidget->addTab(config_tab, QString());
        tester_tab = new QWidget();
        tester_tab->setObjectName(QString::fromUtf8("tester_tab"));
        gridLayout_12 = new QGridLayout(tester_tab);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        groupBox_7 = new QGroupBox(tester_tab);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        verticalLayout_3 = new QVBoxLayout(groupBox_7);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton_3 = new QPushButton(groupBox_7);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_3->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(groupBox_7);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);


        gridLayout_12->addWidget(groupBox_7, 0, 1, 2, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        textcmd_ed = new QLineEdit(tester_tab);
        textcmd_ed->setObjectName(QString::fromUtf8("textcmd_ed"));

        horizontalLayout_3->addWidget(textcmd_ed);

        sendtxtcmd_btn = new QPushButton(tester_tab);
        sendtxtcmd_btn->setObjectName(QString::fromUtf8("sendtxtcmd_btn"));

        horizontalLayout_3->addWidget(sendtxtcmd_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        gridLayout_12->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        testconsole_lst = new QTextBrowser(tester_tab);
        testconsole_lst->setObjectName(QString::fromUtf8("testconsole_lst"));

        gridLayout_12->addWidget(testconsole_lst, 0, 0, 1, 1);

        tabWidget->addTab(tester_tab, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);

        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/control.png"), QSize(), QIcon::Normal, QIcon::Off);
        control_pn->addTab(tab, icon8, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_2 = new QWidget(tab_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(200, 0));
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_31 = new QLabel(widget_2);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        verticalLayout_4->addWidget(label_31);

        progressBar = new QProgressBar(widget_2);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        verticalLayout_4->addWidget(progressBar);

        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout_4->addWidget(pushButton_4);


        gridLayout_2->addWidget(widget_2, 0, 1, 1, 1);

        alarm_lst = new QListWidget(tab_2);
        alarm_lst->setObjectName(QString::fromUtf8("alarm_lst"));

        gridLayout_2->addWidget(alarm_lst, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/Warning-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        control_pn->addTab(tab_2, icon9, QString());

        gridLayout_5->addWidget(control_pn, 3, 0, 1, 1);

        connect_pn = new QFrame(centralWidget);
        connect_pn->setObjectName(QString::fromUtf8("connect_pn"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(connect_pn->sizePolicy().hasHeightForWidth());
        connect_pn->setSizePolicy(sizePolicy7);
        connect_pn->setMinimumSize(QSize(0, 35));
        connect_pn->setFrameShape(QFrame::StyledPanel);
        connect_pn->setFrameShadow(QFrame::Plain);
        horizontalLayout_16 = new QHBoxLayout(connect_pn);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(-1, 3, -1, 3);
        label_9 = new QLabel(connect_pn);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy8);
        label_9->setMinimumSize(QSize(0, 24));
        label_9->setMaximumSize(QSize(16777215, 24));
        QFont font9;
        font9.setFamily(QString::fromUtf8("Arial Black"));
        font9.setPointSize(10);
        font9.setBold(true);
        font9.setWeight(75);
        label_9->setFont(font9);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        horizontalLayout_16->addWidget(label_9);

        line = new QFrame(connect_pn);
        line->setObjectName(QString::fromUtf8("line"));
        QSizePolicy sizePolicy9(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy9);
        line->setMinimumSize(QSize(3, 0));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_16->addWidget(line);

        portname_cmb = new QComboBox(connect_pn);
        portname_cmb->setObjectName(QString::fromUtf8("portname_cmb"));
        QSizePolicy sizePolicy10(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(portname_cmb->sizePolicy().hasHeightForWidth());
        portname_cmb->setSizePolicy(sizePolicy10);
        portname_cmb->setMinimumSize(QSize(150, 24));
        portname_cmb->setMaximumSize(QSize(16777215, 24));
        portname_cmb->setFont(font);

        horizontalLayout_16->addWidget(portname_cmb);

        line_2 = new QFrame(connect_pn);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        sizePolicy9.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy9);
        line_2->setMinimumSize(QSize(3, 0));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_16->addWidget(line_2);

        label = new QLabel(connect_pn);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy8.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy8);
        label->setMinimumSize(QSize(0, 24));
        label->setMaximumSize(QSize(16777215, 24));
        label->setFont(font9);
        label->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        horizontalLayout_16->addWidget(label);

        adr_cmb = new QComboBox(connect_pn);
        adr_cmb->setObjectName(QString::fromUtf8("adr_cmb"));
        sizePolicy8.setHeightForWidth(adr_cmb->sizePolicy().hasHeightForWidth());
        adr_cmb->setSizePolicy(sizePolicy8);
        adr_cmb->setMinimumSize(QSize(0, 24));
        adr_cmb->setMaximumSize(QSize(16777215, 24));
        adr_cmb->setFont(font);

        horizontalLayout_16->addWidget(adr_cmb);

        btnConnect = new QPushButton(connect_pn);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        sizePolicy5.setHeightForWidth(btnConnect->sizePolicy().hasHeightForWidth());
        btnConnect->setSizePolicy(sizePolicy5);
        btnConnect->setMinimumSize(QSize(100, 0));
        btnConnect->setMaximumSize(QSize(100, 16777215));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/connect-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnConnect->setIcon(icon10);
        btnConnect->setIconSize(QSize(24, 24));
        btnConnect->setCheckable(true);

        horizontalLayout_16->addWidget(btnConnect);

        line_3 = new QFrame(connect_pn);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        sizePolicy9.setHeightForWidth(line_3->sizePolicy().hasHeightForWidth());
        line_3->setSizePolicy(sizePolicy9);
        line_3->setMinimumSize(QSize(3, 0));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_16->addWidget(line_3);

        label_27 = new QLabel(connect_pn);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        QFont font10;
        font10.setFamily(QString::fromUtf8("Arial Black"));
        font10.setPointSize(10);
        label_27->setFont(font10);
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        horizontalLayout_16->addWidget(label_27);

        act_ico = new CustomIcon(connect_pn);
        act_ico->setObjectName(QString::fromUtf8("act_ico"));
        sizePolicy5.setHeightForWidth(act_ico->sizePolicy().hasHeightForWidth());
        act_ico->setSizePolicy(sizePolicy5);
        act_ico->setMinimumSize(QSize(20, 20));
        act_ico->setBaseSize(QSize(20, 0));

        horizontalLayout_16->addWidget(act_ico);

        label_28 = new QLabel(connect_pn);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font10);
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        horizontalLayout_16->addWidget(label_28);

        act_answ_ico = new CustomIcon(connect_pn);
        act_answ_ico->setObjectName(QString::fromUtf8("act_answ_ico"));
        sizePolicy5.setHeightForWidth(act_answ_ico->sizePolicy().hasHeightForWidth());
        act_answ_ico->setSizePolicy(sizePolicy5);
        act_answ_ico->setMinimumSize(QSize(20, 20));
        act_answ_ico->setBaseSize(QSize(20, 0));

        horizontalLayout_16->addWidget(act_answ_ico);

        line_4 = new QFrame(connect_pn);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        sizePolicy9.setHeightForWidth(line_4->sizePolicy().hasHeightForWidth());
        line_4->setSizePolicy(sizePolicy9);
        line_4->setMinimumSize(QSize(3, 0));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_16->addWidget(line_4);

        btnSave = new QPushButton(connect_pn);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setMinimumSize(QSize(100, 0));
        btnSave->setMaximumSize(QSize(100, 16777215));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/Save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon11);
        btnSave->setIconSize(QSize(24, 24));

        horizontalLayout_16->addWidget(btnSave);

        btnLoad = new QPushButton(connect_pn);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));
        btnLoad->setMinimumSize(QSize(100, 0));
        btnLoad->setMaximumSize(QSize(100, 16777215));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/Load-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLoad->setIcon(icon12);
        btnLoad->setIconSize(QSize(24, 24));

        horizontalLayout_16->addWidget(btnLoad);

        btnClear = new QPushButton(connect_pn);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setMinimumSize(QSize(100, 0));
        btnClear->setMaximumSize(QSize(100, 16777215));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/Delete-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClear->setIcon(icon13);
        btnClear->setIconSize(QSize(24, 24));

        horizontalLayout_16->addWidget(btnClear);

        line_5 = new QFrame(connect_pn);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        sizePolicy9.setHeightForWidth(line_5->sizePolicy().hasHeightForWidth());
        line_5->setSizePolicy(sizePolicy9);
        line_5->setMinimumSize(QSize(3, 0));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_16->addWidget(line_5);

        btnLiveView = new QPushButton(connect_pn);
        btnLiveView->setObjectName(QString::fromUtf8("btnLiveView"));
        btnLiveView->setMinimumSize(QSize(100, 0));
        btnLiveView->setMaximumSize(QSize(100, 16777215));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/play_24.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLiveView->setIcon(icon14);
        btnLiveView->setIconSize(QSize(24, 24));
        btnLiveView->setCheckable(true);

        horizontalLayout_16->addWidget(btnLiveView);

        line_7 = new QFrame(connect_pn);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout_16->addWidget(line_7);

        btnReset = new QPushButton(connect_pn);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));
        sizePolicy5.setHeightForWidth(btnReset->sizePolicy().hasHeightForWidth());
        btnReset->setSizePolicy(sizePolicy5);
        btnReset->setMinimumSize(QSize(100, 0));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/Reset-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnReset->setIcon(icon15);
        btnReset->setIconSize(QSize(24, 24));

        horizontalLayout_16->addWidget(btnReset);

        line_6 = new QFrame(connect_pn);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_16->addWidget(line_6);

        btnInformation = new QToolButton(connect_pn);
        btnInformation->setObjectName(QString::fromUtf8("btnInformation"));
        btnInformation->setFont(font10);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/Info-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnInformation->setIcon(icon16);
        btnInformation->setIconSize(QSize(24, 24));
        btnInformation->setPopupMode(QToolButton::InstantPopup);
        btnInformation->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_16->addWidget(btnInformation);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_2);


        gridLayout_5->addWidget(connect_pn, 0, 0, 1, 1);

        graph = new Graphic(centralWidget);
        graph->setObjectName(QString::fromUtf8("graph"));
        graph->setEnabled(false);
        sizePolicy8.setHeightForWidth(graph->sizePolicy().hasHeightForWidth());
        graph->setSizePolicy(sizePolicy8);
        graph->setMinimumSize(QSize(0, 196));
        graph->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_5->addWidget(graph, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1221, 18));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        control_pn->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Mamba Sensor", 0, QApplication::UnicodeUTF8));
        actionAbout_this_tool->setText(QApplication::translate("MainWindow", "About this tool", 0, QApplication::UnicodeUTF8));
        actionStart_updater->setText(QApplication::translate("MainWindow", "Start updater", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_16->setText(QApplication::translate("MainWindow", "Amplifier", 0, QApplication::UnicodeUTF8));
        extrasens_btn->setText(QApplication::translate("MainWindow", "Extra", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Wired fence", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "Rigid fence", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "Concerete wall", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "Photovoltaic", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "Underground ", 0, QApplication::UnicodeUTF8));
        btnGType2->setText(QString());
        btnGType3->setText(QString());
        btnGType4->setText(QString());
        btnGType5->setText(QString());
        btnGType1->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Detection", 0, QApplication::UnicodeUTF8));
        t2cable_cb->setText(QApplication::translate("MainWindow", "End terminal", 0, QApplication::UnicodeUTF8));
        t1cable_cb->setText(QApplication::translate("MainWindow", "End terminal", 0, QApplication::UnicodeUTF8));
        t2pwr_cb->setText(QApplication::translate("MainWindow", "Power failure", 0, QApplication::UnicodeUTF8));
        t1pwr_cb->setText(QApplication::translate("MainWindow", "Power failure", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Tamper 1(NC2)", 0, QApplication::UnicodeUTF8));
        t2acc_cb->setText(QApplication::translate("MainWindow", "Accelerometer", 0, QApplication::UnicodeUTF8));
        t1acc_cb->setText(QApplication::translate("MainWindow", "Accelerometer", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Tamper 2(NC3)", 0, QApplication::UnicodeUTF8));
        t1acc_cb_2->setText(QApplication::translate("MainWindow", "Reed relay", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Minimum power voltage", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Accelerometer", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "min", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        acc_sens_sl->setToolTip(QApplication::translate("MainWindow", "Sensitivity (min:3 max:10)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_25->setText(QApplication::translate("MainWindow", "max", 0, QApplication::UnicodeUTF8));
        pwrtrig_cmb->clear();
        pwrtrig_cmb->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "7 volts", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8 volts", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9 volts", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10 volts", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "11 volts", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "12 volts", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "13 volts", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "14 volts", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "15 volts", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("MainWindow", "Digital in --", 0, QApplication::UnicodeUTF8));
        didown_cmb->clear();
        didown_cmb->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "-10%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "-20%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "-30%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "-40%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "-50%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "-60%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "-70%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "-80%", 0, QApplication::UnicodeUTF8)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Controls", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QString());
        fromdevice_btn->setText(QApplication::translate("MainWindow", "Read", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Write", 0, QApplication::UnicodeUTF8));
        defsetting_btn->setText(QApplication::translate("MainWindow", "Default", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        detmode_cmb->clear();
        detmode_cmb->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "classic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "wavelet", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "classic and wavelet", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "classic or wavelet", 0, QApplication::UnicodeUTF8)
        );
        label_21->setText(QApplication::translate("MainWindow", "Potentiometer", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "Accelerometer", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "Detection", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "Misc", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Trig sum   ", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Trig cnt", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Trig val", 0, QApplication::UnicodeUTF8));
        label_19->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("MainWindow", "C mode", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Buf len max 10", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Ref len max 10", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Tolerance 50..100", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Wt max=x^2 ", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QApplication::translate("MainWindow", "W mode", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "Password", 0, QApplication::UnicodeUTF8));
        btnUpdateFirmware->setText(QApplication::translate("MainWindow", "Firmware update", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "Firmware", 0, QApplication::UnicodeUTF8));
        fwver_cmb->clear();
        fwver_cmb->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ver 1.00", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", ">ver 1.01", 0, QApplication::UnicodeUTF8)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindow", "Expert", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        config_lst->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        tofile_btn->setText(QApplication::translate("MainWindow", "Save configuration", 0, QApplication::UnicodeUTF8));
        remove_cfg_btn->setText(QApplication::translate("MainWindow", "Remove configuration", 0, QApplication::UnicodeUTF8));
        btnApplySavedConfig->setText(QApplication::translate("MainWindow", "Apply", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(config_tab), QApplication::translate("MainWindow", "Saved configurations", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "init", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "get status", 0, QApplication::UnicodeUTF8));
        sendtxtcmd_btn->setText(QApplication::translate("MainWindow", "SEND", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tester_tab), QApplication::translate("MainWindow", "Test-Mode", 0, QApplication::UnicodeUTF8));
        control_pn->setTabText(control_pn->indexOf(tab), QApplication::translate("MainWindow", "Sensor setup", 0, QApplication::UnicodeUTF8));
        label_31->setText(QString());
        pushButton_4->setText(QApplication::translate("MainWindow", "Download from sensor", 0, QApplication::UnicodeUTF8));
        control_pn->setTabText(control_pn->indexOf(tab_2), QApplication::translate("MainWindow", "Alarm list", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Serial port", 0, QApplication::UnicodeUTF8));
        portname_cmb->clear();
        portname_cmb->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "COM1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "COM4", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("MainWindow", "Adr", 0, QApplication::UnicodeUTF8));
        adr_cmb->clear();
        adr_cmb->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "21", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "22", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "23", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "24", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "25", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "26", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "27", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "28", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "29", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "31", 0, QApplication::UnicodeUTF8)
        );
        btnConnect->setText(QApplication::translate("MainWindow", "Connect", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "TX", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        act_ico->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_28->setText(QApplication::translate("MainWindow", "RX", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        act_answ_ico->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btnSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        btnLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        btnClear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        btnLiveView->setText(QApplication::translate("MainWindow", "Live view", 0, QApplication::UnicodeUTF8));
        btnReset->setText(QApplication::translate("MainWindow", "Reset sensor", 0, QApplication::UnicodeUTF8));
        btnInformation->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
