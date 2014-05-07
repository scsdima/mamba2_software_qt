#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "ui_graphic.h"

#include <QWidget>
#include <QPointF>
#include <QMenu>
#include <QComboBox>
#include <QPushButton>
#include <QThread>
#include <QCloseEvent>


#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_legend.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>
#include <qwt_scale_draw.h>


#include "config.h"
#include "buffer.hpp"
#include "wav_detector.h"
#include "mamba2reg.h"


class TimeScaleDraw: public QwtScaleDraw
{
public:
    TimeScaleDraw(const QTime &base):
        baseTime(base)    {
    }
    virtual QwtText label(double v) const     {
        QTime upTime = baseTime.addSecs((int)v);
        return upTime.toString();
    }
private:
    QTime baseTime;
};


class Graphic:public QWidget,public Ui::GraphicDlg
{


    enum {SIGNAL_LINE=0,W_LINE,ALARM_LINE,LONG_LINE};
    Q_OBJECT

public:
    explicit Graphic(QWidget *parent=0);
    ~Graphic();

    QAction  * actionApplyTrigger() const {return actApplyValues;}
    bool save(const QString& fname) ;
    bool load(const QString& fname) ;
    quint32     timeline_cursor(void) const   {
        return tlCursor;
    }
    void        setupTriggers(quint32 wtrig,quint32 trigcnt,quint32 trigsum,quint32 trig);

    quint32    trigger1(void) const {
        return trig1;
    }
    //    quint32    trigger2() const {return toADCValue(trig2);}
    //    quint32    trigger3() const {return toADCValue(trig3);}
    //    quint32    trigger4() const {return toADCValue(trig4);}
    bool setAxisXY(quint32 axis_x,quint32 axis_y);
    quint32  dataStorageDataCount() const {return dataStorage->dataSize();}
private :
    VideoCounter_t  vc;
    quint32     tlCursor;
    quint32     tlMaximum;
    double    scale_x;
    double    scale_y;
    quint32     trig1;
    quint32     trig2;
    quint32     trig3;
    quint32     trig4;
    //markers
    qint16      Y,X;
    quint16     dragX;
    uchar       point_sec;
    uchar       point_ctr;
    int         dateSyncCtr;
    Status_t    status;
    double      zero; //value of zero
    volatile bool dragActivated;
    volatile bool recording;

    struct GraphicLine
    {
        QwtPlotCurve *curve;
        QVector<QPointF> data;
    } line[GRAPHIC_LINES];

    QwtPlotCurve *miniplotCurve;
    QVector<QPointF> *miniplotData;

    double  timeData[GRAPHIC_POINTS];
    quint32 dataCount;

    DataStorage<quint32>    *dataStorage;

    QDateTime startDateTime;

    //custom UI
    //plot
    QAction     *actApplyValues;
    QwtLegend       *d_legend;
    QMenu           *popupMenuOnScreen;
    QwtPlotMarker   *d_marker1_cable1;
    QwtPlotMarker   *d_marker2_cable1;
    QwtPlotMarker   *d_marker1_cable2;
    QwtPlotMarker   *d_marker2_cable2;
    QwtPlotPicker   *d_picker;
    QPoint          lastClickedPoint;
    QwtPlotGrid     *grid;
    //mini plot
    QwtPlotMarker  *miniplotMarker;

    //custom elements ui
    QComboBox *cmbChooseControl;
    QPushButton *btnGridOn;
    QPushButton *btnDragOn;
    QPushButton *btnTriggerOn;
    QButtonGroup *axisVoltage;
    QButtonGroup *axisTime;

    /* */
    const   QwtPlotCurve *cpuCurve(int id) const { return line[id].curve; }
    void    processStatus(quint32 val);
    void    setupGraphic(void);    
    double  toVoltage(qint32 v);
    void    updateStatusBox(void);
    void    applyData(double val);
    void    dropMarker(void);

public slots:
    void    setTimeLineCursor(quint32 cursor_position);
    void    setTimeLineCursor(const QDateTime &qdt);
    void    updateGraphic(void);
    void    updateSlider(void);
    void    updateMiniplot(void);
    void    clearData(void);    
    void    refresh_plot(void);

private slots:

    void timer2Timeout(void);
    void x_dragged(qint16 pos);
    void showCurve(QwtPlotItem *item, bool on);
    void contextMenuClicked(const QPoint &);
    void moved(const QPoint &);
    void setGridVisible(bool on);
    void setDragModeOn(bool on);
    void setTriggerOn(bool on);
    void setPickerActivate(bool);
    void rescaleAxisX(double);
    void rescaleAxisY(double);
    void gotCommandAnswer(quint8 graf_n,quint32 val,bool ok);
    void newValue(quint8 graf_n,double val);

    void on_btnGoToBeginning_clicked(void);
    void on_btnGoToEnd_clicked(void);
    void on_slDataSlider_sliderMoved(int position);
};


#endif // GRAPHIC_H
