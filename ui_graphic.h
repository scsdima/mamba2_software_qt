/********************************************************************************
** Form generated from reading UI file 'graphic.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHIC_H
#define UI_GRAPHIC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "customicon.h"
#include "qwt_knob.h"
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_GraphicDlg
{
public:
    QGridLayout *gridLayout;
    QwtPlot *plot;
    QTabWidget *tabWidget;
    QWidget *tabWidgetPage1;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame55;
    QGridLayout *gridLayout_4;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_15;
    CustomIcon *al_ico;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    CustomIcon *warn1_ico;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    CustomIcon *warn2_ico;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    CustomIcon *pwr_ico;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_10;
    CustomIcon *acc_ico;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_12;
    CustomIcon *terminal_ico;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    CustomIcon *tester_ico;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_13;
    CustomIcon *digin_ico;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_14;
    CustomIcon *warning_ico;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_9;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_4;
    QwtKnob *axis_x_dial;
    QLabel *label;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_3;
    QwtKnob *axis_y_dial;
    QLabel *label_2;
    QWidget *History;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QLabel *fileinfo_lb;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnGoToBeginning;
    QPushButton *btnGoToEnd;
    QwtPlot *plot_mini;
    QSlider *slDataSlider;
    QLabel *curdatetime_lb;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *fps_lb;
    QLabel *cur_voltage_lb;
    QLabel *w_val_lb;
    QLabel *v0_v1_lb;
    QLabel *zero_lb;
    QLabel *syspower_lb;
    QLabel *resistor_ed;
    QLabel *localzero_lb;
    QLabel *powerv_lb;
    QLabel *terminal_lb;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QLabel *trigval_lb;
    QLabel *wtrig_lb;
    QLabel *trigsum_lb;
    QLabel *trigcnt_lb;
    QLabel *id_lb;

    void setupUi(QWidget *GraphicDlg)
    {
        if (GraphicDlg->objectName().isEmpty())
            GraphicDlg->setObjectName(QString::fromUtf8("GraphicDlg"));
        GraphicDlg->resize(808, 623);
        gridLayout = new QGridLayout(GraphicDlg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 0, -1, 0);
        plot = new QwtPlot(GraphicDlg);
        plot->setObjectName(QString::fromUtf8("plot"));

        gridLayout->addWidget(plot, 1, 0, 3, 1);

        tabWidget = new QTabWidget(GraphicDlg);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(280, 250));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        tabWidget->setFont(font);
        tabWidgetPage1 = new QWidget();
        tabWidgetPage1->setObjectName(QString::fromUtf8("tabWidgetPage1"));
        verticalLayout_2 = new QVBoxLayout(tabWidgetPage1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame55 = new QFrame(tabWidgetPage1);
        frame55->setObjectName(QString::fromUtf8("frame55"));
        frame55->setFrameShape(QFrame::NoFrame);
        frame55->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame55);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(6);
        frame_6 = new QFrame(frame55);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy1);
        frame_6->setFrameShape(QFrame::StyledPanel);
        horizontalLayout = new QHBoxLayout(frame_6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_15 = new QLabel(frame_6);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(100, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_15->setFont(font1);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        horizontalLayout->addWidget(label_15);

        al_ico = new CustomIcon(frame_6);
        al_ico->setObjectName(QString::fromUtf8("al_ico"));
        sizePolicy.setHeightForWidth(al_ico->sizePolicy().hasHeightForWidth());
        al_ico->setSizePolicy(sizePolicy);
        al_ico->setMinimumSize(QSize(20, 20));
        al_ico->setBaseSize(QSize(20, 0));

        horizontalLayout->addWidget(al_ico);


        gridLayout_4->addWidget(frame_6, 0, 0, 1, 1);

        frame_3 = new QFrame(frame55);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy1.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy1);
        frame_3->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(100, 0));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        horizontalLayout_3->addWidget(label_7);

        warn1_ico = new CustomIcon(frame_3);
        warn1_ico->setObjectName(QString::fromUtf8("warn1_ico"));
        sizePolicy.setHeightForWidth(warn1_ico->sizePolicy().hasHeightForWidth());
        warn1_ico->setSizePolicy(sizePolicy);
        warn1_ico->setMinimumSize(QSize(20, 20));
        warn1_ico->setBaseSize(QSize(20, 0));

        horizontalLayout_3->addWidget(warn1_ico);


        gridLayout_4->addWidget(frame_3, 0, 1, 1, 1);

        frame_5 = new QFrame(frame55);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        sizePolicy1.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy1);
        frame_5->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_4 = new QHBoxLayout(frame_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_8 = new QLabel(frame_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(100, 0));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        horizontalLayout_4->addWidget(label_8);

        warn2_ico = new CustomIcon(frame_5);
        warn2_ico->setObjectName(QString::fromUtf8("warn2_ico"));
        sizePolicy.setHeightForWidth(warn2_ico->sizePolicy().hasHeightForWidth());
        warn2_ico->setSizePolicy(sizePolicy);
        warn2_ico->setMinimumSize(QSize(20, 20));
        warn2_ico->setBaseSize(QSize(20, 0));

        horizontalLayout_4->addWidget(warn2_ico);


        gridLayout_4->addWidget(frame_5, 0, 2, 1, 1);

        frame_2 = new QFrame(frame55);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_5 = new QHBoxLayout(frame_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(100, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        horizontalLayout_5->addWidget(label_9);

        pwr_ico = new CustomIcon(frame_2);
        pwr_ico->setObjectName(QString::fromUtf8("pwr_ico"));
        sizePolicy.setHeightForWidth(pwr_ico->sizePolicy().hasHeightForWidth());
        pwr_ico->setSizePolicy(sizePolicy);
        pwr_ico->setMinimumSize(QSize(20, 20));
        pwr_ico->setBaseSize(QSize(20, 0));

        horizontalLayout_5->addWidget(pwr_ico);


        gridLayout_4->addWidget(frame_2, 1, 0, 1, 1);

        frame_8 = new QFrame(frame55);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_8->sizePolicy().hasHeightForWidth());
        frame_8->setSizePolicy(sizePolicy2);
        frame_8->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_6 = new QHBoxLayout(frame_8);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_10 = new QLabel(frame_8);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(100, 0));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        horizontalLayout_6->addWidget(label_10);

        acc_ico = new CustomIcon(frame_8);
        acc_ico->setObjectName(QString::fromUtf8("acc_ico"));
        sizePolicy.setHeightForWidth(acc_ico->sizePolicy().hasHeightForWidth());
        acc_ico->setSizePolicy(sizePolicy);
        acc_ico->setMinimumSize(QSize(20, 20));
        acc_ico->setBaseSize(QSize(20, 0));

        horizontalLayout_6->addWidget(acc_ico);


        gridLayout_4->addWidget(frame_8, 1, 1, 1, 1);

        frame_7 = new QFrame(frame55);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        sizePolicy1.setHeightForWidth(frame_7->sizePolicy().hasHeightForWidth());
        frame_7->setSizePolicy(sizePolicy1);
        frame_7->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_8 = new QHBoxLayout(frame_7);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_12 = new QLabel(frame_7);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(100, 0));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        horizontalLayout_8->addWidget(label_12);

        terminal_ico = new CustomIcon(frame_7);
        terminal_ico->setObjectName(QString::fromUtf8("terminal_ico"));
        sizePolicy.setHeightForWidth(terminal_ico->sizePolicy().hasHeightForWidth());
        terminal_ico->setSizePolicy(sizePolicy);
        terminal_ico->setMinimumSize(QSize(20, 20));
        terminal_ico->setBaseSize(QSize(20, 0));

        horizontalLayout_8->addWidget(terminal_ico);


        gridLayout_4->addWidget(frame_7, 1, 2, 1, 1);

        frame_4 = new QFrame(frame55);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        sizePolicy1.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy1);
        frame_4->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_7 = new QHBoxLayout(frame_4);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_11 = new QLabel(frame_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(100, 0));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        horizontalLayout_7->addWidget(label_11);

        tester_ico = new CustomIcon(frame_4);
        tester_ico->setObjectName(QString::fromUtf8("tester_ico"));
        sizePolicy.setHeightForWidth(tester_ico->sizePolicy().hasHeightForWidth());
        tester_ico->setSizePolicy(sizePolicy);
        tester_ico->setMinimumSize(QSize(20, 20));
        tester_ico->setBaseSize(QSize(20, 0));

        horizontalLayout_7->addWidget(tester_ico);


        gridLayout_4->addWidget(frame_4, 2, 0, 1, 1);

        frame_9 = new QFrame(frame55);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        sizePolicy1.setHeightForWidth(frame_9->sizePolicy().hasHeightForWidth());
        frame_9->setSizePolicy(sizePolicy1);
        frame_9->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_10 = new QHBoxLayout(frame_9);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_13 = new QLabel(frame_9);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(100, 0));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        horizontalLayout_10->addWidget(label_13);

        digin_ico = new CustomIcon(frame_9);
        digin_ico->setObjectName(QString::fromUtf8("digin_ico"));
        sizePolicy.setHeightForWidth(digin_ico->sizePolicy().hasHeightForWidth());
        digin_ico->setSizePolicy(sizePolicy);
        digin_ico->setMinimumSize(QSize(20, 20));
        digin_ico->setBaseSize(QSize(20, 0));

        horizontalLayout_10->addWidget(digin_ico);


        gridLayout_4->addWidget(frame_9, 2, 1, 1, 1);

        frame_10 = new QFrame(frame55);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        sizePolicy1.setHeightForWidth(frame_10->sizePolicy().hasHeightForWidth());
        frame_10->setSizePolicy(sizePolicy1);
        frame_10->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_11 = new QHBoxLayout(frame_10);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_14 = new QLabel(frame_10);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(100, 0));
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        horizontalLayout_11->addWidget(label_14);

        warning_ico = new CustomIcon(frame_10);
        warning_ico->setObjectName(QString::fromUtf8("warning_ico"));
        sizePolicy.setHeightForWidth(warning_ico->sizePolicy().hasHeightForWidth());
        warning_ico->setSizePolicy(sizePolicy);
        warning_ico->setMinimumSize(QSize(20, 20));
        warning_ico->setBaseSize(QSize(20, 0));

        horizontalLayout_11->addWidget(warning_ico);


        gridLayout_4->addWidget(frame_10, 2, 2, 1, 1);


        verticalLayout_2->addWidget(frame55);

        frame = new QFrame(tabWidgetPage1);
        frame->setObjectName(QString::fromUtf8("frame"));
        horizontalLayout_9 = new QHBoxLayout(frame);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(-1, 0, -1, 0);
        groupBox_8 = new QGroupBox(frame);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        sizePolicy.setHeightForWidth(groupBox_8->sizePolicy().hasHeightForWidth());
        groupBox_8->setSizePolicy(sizePolicy);
        groupBox_8->setMaximumSize(QSize(150, 150));
        groupBox_8->setBaseSize(QSize(0, 120));
        groupBox_8->setFont(font);
        groupBox_8->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));
        verticalLayout_4 = new QVBoxLayout(groupBox_8);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        axis_x_dial = new QwtKnob(groupBox_8);
        axis_x_dial->setObjectName(QString::fromUtf8("axis_x_dial"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(axis_x_dial->sizePolicy().hasHeightForWidth());
        axis_x_dial->setSizePolicy(sizePolicy3);
        axis_x_dial->setMinimumSize(QSize(0, 90));

        verticalLayout_4->addWidget(axis_x_dial);

        label = new QLabel(groupBox_8);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);


        horizontalLayout_9->addWidget(groupBox_8);

        groupBox_7 = new QGroupBox(frame);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        sizePolicy.setHeightForWidth(groupBox_7->sizePolicy().hasHeightForWidth());
        groupBox_7->setSizePolicy(sizePolicy);
        groupBox_7->setMaximumSize(QSize(150, 150));
        groupBox_7->setBaseSize(QSize(0, 120));
        groupBox_7->setFont(font);
        groupBox_7->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));
        verticalLayout_3 = new QVBoxLayout(groupBox_7);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        axis_y_dial = new QwtKnob(groupBox_7);
        axis_y_dial->setObjectName(QString::fromUtf8("axis_y_dial"));
        sizePolicy3.setHeightForWidth(axis_y_dial->sizePolicy().hasHeightForWidth());
        axis_y_dial->setSizePolicy(sizePolicy3);
        axis_y_dial->setMinimumSize(QSize(0, 90));

        verticalLayout_3->addWidget(axis_y_dial);

        label_2 = new QLabel(groupBox_7);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);


        horizontalLayout_9->addWidget(groupBox_7);


        verticalLayout_2->addWidget(frame);

        tabWidget->addTab(tabWidgetPage1, QString());
        History = new QWidget();
        History->setObjectName(QString::fromUtf8("History"));
        gridLayout_7 = new QGridLayout(History);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox_3 = new QGroupBox(History);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        fileinfo_lb = new QLabel(groupBox_3);
        fileinfo_lb->setObjectName(QString::fromUtf8("fileinfo_lb"));
        sizePolicy.setHeightForWidth(fileinfo_lb->sizePolicy().hasHeightForWidth());
        fileinfo_lb->setSizePolicy(sizePolicy);
        fileinfo_lb->setMinimumSize(QSize(200, 50));
        fileinfo_lb->setFont(font);
        fileinfo_lb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_6->addWidget(fileinfo_lb, 0, 1, 1, 1);


        gridLayout_7->addWidget(groupBox_3, 1, 0, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnGoToBeginning = new QPushButton(History);
        btnGoToBeginning->setObjectName(QString::fromUtf8("btnGoToBeginning"));
        sizePolicy.setHeightForWidth(btnGoToBeginning->sizePolicy().hasHeightForWidth());
        btnGoToBeginning->setSizePolicy(sizePolicy);
        btnGoToBeginning->setMinimumSize(QSize(0, 18));
        btnGoToBeginning->setMaximumSize(QSize(16777215, 18));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/btnArrowLeft"), QSize(), QIcon::Normal, QIcon::Off);
        btnGoToBeginning->setIcon(icon);

        horizontalLayout_2->addWidget(btnGoToBeginning);

        btnGoToEnd = new QPushButton(History);
        btnGoToEnd->setObjectName(QString::fromUtf8("btnGoToEnd"));
        sizePolicy.setHeightForWidth(btnGoToEnd->sizePolicy().hasHeightForWidth());
        btnGoToEnd->setSizePolicy(sizePolicy);
        btnGoToEnd->setMinimumSize(QSize(0, 18));
        btnGoToEnd->setMaximumSize(QSize(16777215, 18));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/btnArrowRight"), QSize(), QIcon::Normal, QIcon::Off);
        btnGoToEnd->setIcon(icon1);

        horizontalLayout_2->addWidget(btnGoToEnd);


        gridLayout_7->addLayout(horizontalLayout_2, 3, 0, 1, 3);

        plot_mini = new QwtPlot(History);
        plot_mini->setObjectName(QString::fromUtf8("plot_mini"));
        sizePolicy3.setHeightForWidth(plot_mini->sizePolicy().hasHeightForWidth());
        plot_mini->setSizePolicy(sizePolicy3);
        plot_mini->setMaximumSize(QSize(16777215, 50));
        plot_mini->setBaseSize(QSize(0, 100));

        gridLayout_7->addWidget(plot_mini, 5, 0, 1, 1);

        slDataSlider = new QSlider(History);
        slDataSlider->setObjectName(QString::fromUtf8("slDataSlider"));
        sizePolicy3.setHeightForWidth(slDataSlider->sizePolicy().hasHeightForWidth());
        slDataSlider->setSizePolicy(sizePolicy3);
        slDataSlider->setMinimumSize(QSize(350, 18));
        slDataSlider->setMaximumSize(QSize(16777215, 18));
        slDataSlider->setMouseTracking(true);
        slDataSlider->setOrientation(Qt::Horizontal);

        gridLayout_7->addWidget(slDataSlider, 4, 0, 1, 3);

        curdatetime_lb = new QLabel(History);
        curdatetime_lb->setObjectName(QString::fromUtf8("curdatetime_lb"));
        sizePolicy3.setHeightForWidth(curdatetime_lb->sizePolicy().hasHeightForWidth());
        curdatetime_lb->setSizePolicy(sizePolicy3);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial Black"));
        font3.setPointSize(12);
        curdatetime_lb->setFont(font3);
        curdatetime_lb->setStyleSheet(QString::fromUtf8("background-color: rgb(122, 122, 122);color:rgb(232, 232, 232)"));
        curdatetime_lb->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(curdatetime_lb, 2, 0, 1, 3);

        tabWidget->addTab(History, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        fps_lb = new QLabel(groupBox);
        fps_lb->setObjectName(QString::fromUtf8("fps_lb"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(fps_lb->sizePolicy().hasHeightForWidth());
        fps_lb->setSizePolicy(sizePolicy4);
        fps_lb->setMinimumSize(QSize(100, 0));
        fps_lb->setFont(font);
        fps_lb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(fps_lb, 0, 0, 1, 1);

        cur_voltage_lb = new QLabel(groupBox);
        cur_voltage_lb->setObjectName(QString::fromUtf8("cur_voltage_lb"));
        sizePolicy4.setHeightForWidth(cur_voltage_lb->sizePolicy().hasHeightForWidth());
        cur_voltage_lb->setSizePolicy(sizePolicy4);
        cur_voltage_lb->setMinimumSize(QSize(100, 0));
        cur_voltage_lb->setFont(font);
        cur_voltage_lb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(cur_voltage_lb, 1, 0, 1, 1);

        w_val_lb = new QLabel(groupBox);
        w_val_lb->setObjectName(QString::fromUtf8("w_val_lb"));
        sizePolicy4.setHeightForWidth(w_val_lb->sizePolicy().hasHeightForWidth());
        w_val_lb->setSizePolicy(sizePolicy4);
        w_val_lb->setMinimumSize(QSize(100, 0));
        w_val_lb->setFont(font);
        w_val_lb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(w_val_lb, 2, 0, 1, 1);

        v0_v1_lb = new QLabel(groupBox);
        v0_v1_lb->setObjectName(QString::fromUtf8("v0_v1_lb"));
        sizePolicy4.setHeightForWidth(v0_v1_lb->sizePolicy().hasHeightForWidth());
        v0_v1_lb->setSizePolicy(sizePolicy4);
        v0_v1_lb->setMinimumSize(QSize(100, 0));
        v0_v1_lb->setFont(font);
        v0_v1_lb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(v0_v1_lb, 0, 1, 1, 1);

        zero_lb = new QLabel(groupBox);
        zero_lb->setObjectName(QString::fromUtf8("zero_lb"));
        sizePolicy4.setHeightForWidth(zero_lb->sizePolicy().hasHeightForWidth());
        zero_lb->setSizePolicy(sizePolicy4);
        zero_lb->setMinimumSize(QSize(100, 0));
        zero_lb->setFont(font);
        zero_lb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));
        zero_lb->setWordWrap(false);

        gridLayout_3->addWidget(zero_lb, 1, 1, 1, 1);

        syspower_lb = new QLabel(groupBox);
        syspower_lb->setObjectName(QString::fromUtf8("syspower_lb"));
        sizePolicy4.setHeightForWidth(syspower_lb->sizePolicy().hasHeightForWidth());
        syspower_lb->setSizePolicy(sizePolicy4);
        syspower_lb->setMinimumSize(QSize(100, 0));
        QFont font4;
        font4.setPointSize(10);
        syspower_lb->setFont(font4);
        syspower_lb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(syspower_lb, 2, 1, 1, 1);

        resistor_ed = new QLabel(groupBox);
        resistor_ed->setObjectName(QString::fromUtf8("resistor_ed"));
        sizePolicy4.setHeightForWidth(resistor_ed->sizePolicy().hasHeightForWidth());
        resistor_ed->setSizePolicy(sizePolicy4);
        resistor_ed->setMinimumSize(QSize(100, 0));
        resistor_ed->setFont(font);
        resistor_ed->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(resistor_ed, 3, 1, 1, 1);

        localzero_lb = new QLabel(groupBox);
        localzero_lb->setObjectName(QString::fromUtf8("localzero_lb"));
        sizePolicy4.setHeightForWidth(localzero_lb->sizePolicy().hasHeightForWidth());
        localzero_lb->setSizePolicy(sizePolicy4);
        localzero_lb->setMinimumSize(QSize(100, 0));
        localzero_lb->setFont(font);
        localzero_lb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));
        localzero_lb->setWordWrap(false);

        gridLayout_3->addWidget(localzero_lb, 3, 0, 1, 1);

        powerv_lb = new QLabel(groupBox);
        powerv_lb->setObjectName(QString::fromUtf8("powerv_lb"));
        sizePolicy4.setHeightForWidth(powerv_lb->sizePolicy().hasHeightForWidth());
        powerv_lb->setSizePolicy(sizePolicy4);
        powerv_lb->setMinimumSize(QSize(100, 0));
        powerv_lb->setFont(font);
        powerv_lb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(powerv_lb, 0, 2, 1, 1);

        terminal_lb = new QLabel(groupBox);
        terminal_lb->setObjectName(QString::fromUtf8("terminal_lb"));
        sizePolicy4.setHeightForWidth(terminal_lb->sizePolicy().hasHeightForWidth());
        terminal_lb->setSizePolicy(sizePolicy4);
        terminal_lb->setMinimumSize(QSize(100, 0));
        terminal_lb->setFont(font4);
        terminal_lb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_3->addWidget(terminal_lb, 2, 2, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 2);

        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        trigval_lb = new QLabel(groupBox_2);
        trigval_lb->setObjectName(QString::fromUtf8("trigval_lb"));
        sizePolicy4.setHeightForWidth(trigval_lb->sizePolicy().hasHeightForWidth());
        trigval_lb->setSizePolicy(sizePolicy4);
        trigval_lb->setMinimumSize(QSize(100, 0));
        trigval_lb->setFont(font);
        trigval_lb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_5->addWidget(trigval_lb, 0, 0, 1, 1);

        wtrig_lb = new QLabel(groupBox_2);
        wtrig_lb->setObjectName(QString::fromUtf8("wtrig_lb"));
        sizePolicy4.setHeightForWidth(wtrig_lb->sizePolicy().hasHeightForWidth());
        wtrig_lb->setSizePolicy(sizePolicy4);
        wtrig_lb->setMinimumSize(QSize(100, 0));
        wtrig_lb->setFont(font);
        wtrig_lb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_5->addWidget(wtrig_lb, 1, 0, 1, 1);

        trigsum_lb = new QLabel(groupBox_2);
        trigsum_lb->setObjectName(QString::fromUtf8("trigsum_lb"));
        sizePolicy4.setHeightForWidth(trigsum_lb->sizePolicy().hasHeightForWidth());
        trigsum_lb->setSizePolicy(sizePolicy4);
        trigsum_lb->setMinimumSize(QSize(100, 0));
        trigsum_lb->setFont(font);
        trigsum_lb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_5->addWidget(trigsum_lb, 0, 1, 1, 1);

        trigcnt_lb = new QLabel(groupBox_2);
        trigcnt_lb->setObjectName(QString::fromUtf8("trigcnt_lb"));
        sizePolicy4.setHeightForWidth(trigcnt_lb->sizePolicy().hasHeightForWidth());
        trigcnt_lb->setSizePolicy(sizePolicy4);
        trigcnt_lb->setMinimumSize(QSize(100, 0));
        trigcnt_lb->setFont(font);
        trigcnt_lb->setStyleSheet(QString::fromUtf8("color: rgb(107, 107, 107);"));

        gridLayout_5->addWidget(trigcnt_lb, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 1, 0, 1, 2);

        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 2, 1, 1, 2);

        id_lb = new QLabel(GraphicDlg);
        id_lb->setObjectName(QString::fromUtf8("id_lb"));
        id_lb->setFont(font4);
        id_lb->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        id_lb->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(id_lb, 1, 1, 1, 2);


        retranslateUi(GraphicDlg);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GraphicDlg);
    } // setupUi

    void retranslateUi(QWidget *GraphicDlg)
    {
        GraphicDlg->setWindowTitle(QApplication::translate("GraphicDlg", "Form", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("GraphicDlg", "Alarm", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        al_ico->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("GraphicDlg", "Tamper 1", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        warn1_ico->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("GraphicDlg", "Tamper 2", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        warn2_ico->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_9->setText(QApplication::translate("GraphicDlg", "Power failure", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pwr_ico->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_10->setText(QApplication::translate("GraphicDlg", "Shaking", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        acc_ico->setToolTip(QApplication::translate("GraphicDlg", "Accelerometer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_12->setText(QApplication::translate("GraphicDlg", "End terminal", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        terminal_ico->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_11->setText(QApplication::translate("GraphicDlg", "Tester_on", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tester_ico->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_13->setText(QApplication::translate("GraphicDlg", "Digital In", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        digin_ico->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_14->setText(QApplication::translate("GraphicDlg", "Warning", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        warning_ico->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox_8->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        groupBox_8->setTitle(QApplication::translate("GraphicDlg", "Time (x)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GraphicDlg", "sec", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        groupBox_7->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        groupBox_7->setTitle(QApplication::translate("GraphicDlg", "Voltage(y)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GraphicDlg", "mV", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage1), QApplication::translate("GraphicDlg", "Control", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("GraphicDlg", "File", 0, QApplication::UnicodeUTF8));
        fileinfo_lb->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnGoToBeginning->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnGoToBeginning->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        btnGoToBeginning->setText(QString());
#ifndef QT_NO_STATUSTIP
        btnGoToEnd->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        btnGoToEnd->setText(QString());
#ifndef QT_NO_STATUSTIP
        slDataSlider->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        curdatetime_lb->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(History), QApplication::translate("GraphicDlg", "History", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("GraphicDlg", "Signal", 0, QApplication::UnicodeUTF8));
        fps_lb->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
        cur_voltage_lb->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
        w_val_lb->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
        v0_v1_lb->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
        zero_lb->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
        syspower_lb->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
        resistor_ed->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
        localzero_lb->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
        powerv_lb->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
        terminal_lb->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("GraphicDlg", "Settings", 0, QApplication::UnicodeUTF8));
        trigval_lb->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
        wtrig_lb->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
        trigsum_lb->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
        trigcnt_lb->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("GraphicDlg", "Detail", 0, QApplication::UnicodeUTF8));
        id_lb->setText(QApplication::translate("GraphicDlg", "--", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GraphicDlg: public Ui_GraphicDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHIC_H
