/* *********************************************************************


  @File:graphic.cpp

  @Project: E:\workspace_test\1
  @Date: 2014\01\09 21-39-05
  @Description: $d


 
 ********************************************************************* */


#include "graphic.h"
#include "ui_graphic.h"
#include "mamba2reg.h"
#include <qwt_legend_item.h>
#include <QStringList>
#include <QPainter>
#include <QComboBox>
#include <QFileDialog>
#include <QTimer>
#include "QMessageBox"

#include "buffer.hpp"
#include "wav_detector.h"

#include "customicon.h"



/* ********************************************************************* 
  @Function name: c
  @Return: (Graphic::Graphi) 
  @Parameters: 
	QWidget *parent 
  @Description: $d
 
 ********************************************************************* */
Graphic::Graphic(QWidget *parent)
    :QWidget(parent),tlMaximum(0)
{
    setupUi(this);

    setupGraphic();

    QTimer *timer = new QTimer();
    /************Timer for point per second**************/
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer2Timeout()));

    //*******TIMEr for auto marker setting***************/
    timer = new QTimer();
    timer->start(250);//every 100ms
    connect(timer,SIGNAL(timeout()),this,SLOT(updateGraphic()));

    //***********wavelet algorithm************************
    vcInit(&vc);
    vc_setup(&vc,DEFAULT_COLOR_TOLERANCE,DEFAULT_WTRIGGER
             ,DEFAULT_LAST_VALUES_COUNT
             ,DEFAULT_REFERENCE_VALUES_COUNT);

    dateSyncCtr=0;
    tlCursor=0;
}



/* ********************************************************************* 
  @Function name: Graphic::updateMiniplot
  @Return: (void) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
void Graphic::updateMiniplot(void)
{
    quint32 c;
    quint32 i;
    for(i=0,c=0; i < dataStorage->blockCount(); i++)
    {
        QPointF pointf;
        if(dataStorage->block_at(i).id==DataStorage<quint32>::BlockData)
        {
            pointf.setY(dataStorage->block_at(i).data);
            pointf.setX(c);
            miniplotData->append(pointf);
            c++;
        }
    }
}

/* !!! make Comment*/
bool Graphic::setAxisXY(quint32 axis_x, quint32 axis_y){
    if((axis_x <= 600) && (axis_y <= 1500)){
        double axis_x_double = (double)axis_x;
        double axis_y_double = (double)axis_y;
        axis_x_dial->fitValue(axis_x_double);
        axis_y_dial->setValue(axis_y_double);
        rescaleAxisX(axis_x_double);
        rescaleAxisY(axis_y_double);
    }
    else {
        return false;
    }
    return true;
}


/* ********************************************************************* 
  @Function name: Graphic::timer2Timeout
  @Return: (void) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
void Graphic::timer2Timeout(void)
{ 
    point_sec = point_ctr;
    this->fps_lb->setText(QString().sprintf("<b>point/sec</b>=%d",point_sec));
    point_ctr = 0;
    //updateMiniplot();
}


/* ********************************************************************* 
  @Function name: Graphic::setupGraphic
  @Return: (void) 
  @Parameters: 
	 
  @Description: $d
 
 ********************************************************************* */
void Graphic::setupGraphic()
{
    QSizePolicy  sizePolicy1( QSizePolicy::Expanding,QSizePolicy::Expanding);
    plot->setSizePolicy(sizePolicy1);
    plot->setMinimumSize(QSize(450, 300));
    plot->setContextMenuPolicy(Qt::CustomContextMenu );
    popupMenuOnScreen =new QMenu(plot);
    actApplyValues=new QAction(tr("Apply"),plot);
    popupMenuOnScreen->addAction(actApplyValues);

    //Combobox choose graphic
    QPixmap pixmap(QSize(16,16));
    cmbChooseControl = new QComboBox(this);
    cmbChooseControl->setGeometry(5,6,100,20);
    pixmap.fill(Qt::yellow);
    //cmbChooseControl->addItem(QIcon(pixmap),QString("Cable1"));
    pixmap.fill(Qt::cyan);
    //cmbChooseControl->addItem(QIcon(pixmap),QString("Cable2"));
    pixmap.fill(Qt::yellow);
    cmbChooseControl->addItem(QIcon(pixmap),tr("Trigger1"));
    pixmap.fill(Qt::cyan);
    cmbChooseControl->addItem(QIcon(pixmap),tr("Trigger2"));
    //Button turn on grid
    btnGridOn = new QPushButton(this);
    btnGridOn->setIcon(QIcon(":/btnGrid"));
    btnGridOn->setGeometry(110,6,20,20);
    btnGridOn->setCheckable(true);
    btnGridOn->setChecked(true);
    //Button drag line
    btnDragOn = new QPushButton(this);
    btnDragOn->setIcon(QIcon(":/btnDrag"));
    btnDragOn->setGeometry(135,6,20,20);
    btnDragOn->setCheckable(true);
    btnDragOn->setEnabled(true);
    //button trigger
    btnTriggerOn = new QPushButton(this);
    btnTriggerOn->setIcon(QIcon(":/btnTrigger"));
    btnTriggerOn->setGeometry(160,6,20,20);
    btnTriggerOn->setCheckable(true);

    //plot->setTitle(QwtText("Cable signals"));
    // plot->setContextMenuPolicy(Qt::CustomContextMenu);
    //set geometry of the window
    //plot->setGeometry(QRect(0,0,700,350));
    //axis for Y
    plot->setAxisScale(QwtPlot::yLeft, -1500, 1500,500);
    //plot->setAxisTitle(QwtPlot::yLeft,QwtText(tr("Signal , mV(100mV)")));
    //axis for X
    plot->setAxisScale(QwtPlot::xBottom, 0, 50);
    plot->canvas()->setBorderRadius(3);

    QwtPlotCurve *curve;
    QColor color;

    // add curves
    curve =new QwtPlotCurve(tr("Detection"));
    color = Qt::red;
    color.setAlpha(10);
    curve->setPen(QPen(color,3));
    curve->attach(plot);
    QBrush brush;
    brush.setStyle(Qt::Dense3Pattern);
    brush.setColor(Qt::red);
    curve->setBrush(brush);
    line[2].curve = curve;

    line[3].curve = curve;


    curve =new QwtPlotCurve("C signal");
    color = Qt::yellow;
    color.setAlpha(255);
    curve->setPen(QPen(color,2));
    line[0].curve = curve;
    curve->attach(plot);

    curve =new QwtPlotCurve(tr("V signal"));
    color = Qt::cyan;
    color.setAlpha(255);
    curve->setPen(QPen(color));
    line[1].curve = curve;
    curve->attach(plot);





    plot->setAutoFillBackground(1);
    plot->setCanvasBackground(QBrush(QColor(Qt::black)));
    // grid
    grid = new QwtPlotGrid;
    grid->enableYMin(true);
    grid->setMajPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->setMinPen(QPen(Qt::darkGray, 0 , Qt::DotLine));
    grid->attach(plot);
    // legend
    d_legend = new QwtLegend;
    d_legend->setItemMode(QwtLegend::CheckableItem);
    plot->insertLegend(d_legend, QwtPlot::TopLegend);
    //Plot picker horizontal grey line
    d_picker = new QwtPlotPicker(QwtPlot::xBottom, QwtPlot::yLeft
                                 ,QwtPlotPicker::CrossRubberBand
                                 , QwtPicker::AlwaysOn, plot->canvas());
    d_picker->setStateMachine(new QwtPickerDragPointMachine());
    d_picker->setRubberBandPen(QColor(Qt::darkGray));
    d_picker->setRubberBand(QwtPicker::HLineRubberBand);
    d_picker->setTrackerMode(QwtPicker::ActiveOnly);
    d_picker->setTrackerPen(QColor(Qt::lightGray));
    //marker for Yellow signal line       top
    d_marker1_cable1 = new QwtPlotMarker();
    d_marker1_cable1->setValue(1100.0, 1100.0);
    d_marker1_cable1->setLineStyle(QwtPlotMarker::HLine);
    d_marker1_cable1->setLabelAlignment(Qt::AlignRight | Qt::AlignBottom);
    d_marker1_cable1->setLinePen(QPen(Qt::yellow, 0, Qt::DashDotLine));
    d_marker1_cable1->attach(plot);
    //marker for Yellow signal line bottom
    d_marker2_cable1 = new QwtPlotMarker();
    d_marker2_cable1->setValue(10000.0, 10000.0);
    d_marker2_cable1->setLineStyle(QwtPlotMarker::HLine);
    d_marker2_cable1->setLabelAlignment(Qt::AlignRight | Qt::AlignBottom);
    d_marker2_cable1->setLinePen(QPen(Qt::yellow, 0, Qt::DashDotLine));
    d_marker2_cable1->attach(plot);
    // marker for Red signal line top
    d_marker1_cable2 = new QwtPlotMarker();
    d_marker1_cable2->setValue(1100.0, 1100.0);
    d_marker1_cable2->setLineStyle(QwtPlotMarker::HLine);
    d_marker1_cable2->setLabelAlignment(Qt::AlignRight | Qt::AlignBottom);
    d_marker1_cable2->setLinePen(QPen(Qt::cyan, 0, Qt::DashDotLine));
    d_marker1_cable2->attach(plot);
    // marker for Red signal line  bottom
    d_marker2_cable2 = new QwtPlotMarker();
    d_marker2_cable2->setValue(10000.0, 10000.0);
    d_marker2_cable2->setLineStyle(QwtPlotMarker::HLine);
    d_marker2_cable2->setLabelAlignment(Qt::AlignRight | Qt::AlignBottom);
    d_marker2_cable2->setLinePen(QPen(Qt::cyan, 0, Qt::DashDotLine));
    d_marker2_cable2->attach(plot);
    //knob
    axis_x_dial->setRange(60,600,60);
    axis_x_dial->setKnobWidth(50);
    axis_y_dial->setKnobWidth(50);
    axis_y_dial->setRange(100,1500,100);

    connect(axis_x_dial,SIGNAL(valueChanged(double))
            ,this,SLOT(rescaleAxisX(double)));
    connect(axis_y_dial,SIGNAL(valueChanged(double))
            ,this,SLOT(rescaleAxisY(double)));
    //
    al_ico->setIconOn(QImage(":/icoAlarm"));
    al_ico->setIconOff(QImage(":/icoOff"));

    warn1_ico->setIconOn(QImage(":/icoWarning"));
    warn1_ico->setIconOff(QImage(":/icoOff"));

    warn2_ico->setIconOn(QImage(":/icoWarning"));
    warn2_ico->setIconOff(QImage(":/icoOff"));

    terminal_ico->setIconOn(QImage(":/icoWarning"));
    terminal_ico->setIconOff(QImage(":/icoOff"));

    tester_ico->setIconOn(QImage(":/icoBlue"));
    tester_ico->setIconOff(QImage(":/icoOff"));

    acc_ico->setIconOn(QImage(":/icoWarning"));
    acc_ico->setIconOff(QImage(":/icoOff"));

    pwr_ico->setIconOn(QImage(":/icoWarning"));
    pwr_ico->setIconOff(QImage(":/icoOff"));

    warning_ico->setIconOn(QImage(":/icoWarning"));
    warning_ico->setIconOff(QImage(":/icoOff"));

    digin_ico->setIconOn(QImage(":/icoBlue"));
    digin_ico->setIconOff(QImage(":/icoOff"));

    connect(plot, SIGNAL(customContextMenuRequested(QPoint)),SLOT(contextMenuClicked(QPoint)));
    // connect(action,SIGNAL(triggered()),plot,SLOT(on_ActionSetTriggerHere()));
   // connect(d_picker,SIGNAL(selected(QPointF)),this,SLOT(ActionSetTriggerHere(QPointF)));
    connect(btnDragOn,SIGNAL(toggled(bool)),SLOT(setDragModeOn(bool)));
    connect(btnGridOn,SIGNAL(toggled(bool)),SLOT(setGridVisible(bool)));
    connect(btnTriggerOn,SIGNAL(toggled(bool)),SLOT(setTriggerOn(bool)));
    connect(plot, SIGNAL(legendChecked(QwtPlotItem *, bool)),SLOT(showCurve(QwtPlotItem *, bool)));
    connect(d_picker, SIGNAL(moved(const QPoint &)),this,SLOT(moved(const QPoint &)));
    connect(d_picker,SIGNAL(activated(bool)),this,SLOT(setPickerActivate(bool)));
    //  connect(thist,SIGNAL(x_dragged(qint16))(x_dragged(qint16)),this,SLOT(dragGraph(qint16)));
    showCurve(line[0].curve,true);
    showCurve(line[1].curve,false);
    showCurve(line[2].curve,false);
    showCurve(line[3].curve,false);

    //inititalizing data storer    
    scale_x = this->axis_x_dial->value();

    zero=toVoltage(431); //zero for start

    dataStorage = new DataStorage<quint32>();
    clearData();

    plot->setAutoReplot();

    //**********miniplot**************
    plot_mini->canvas()->setBorderRadius(3);
    plot_mini->enableAxis(QwtPlot::xBottom, false);
    plot_mini->enableAxis(QwtPlot::yLeft, false);
    plot_mini->setVisible(0);
    curve =new QwtPlotCurve("signal");
    color = Qt::gray;
    color.setAlpha(255);
    curve->setPen(QPen(color));
    curve->attach(plot_mini);
    line[3].curve = curve;
    miniplotMarker= new QwtPlotMarker();
    miniplotMarker->setValue(1500.0, 1500.0);
    miniplotMarker->setLineStyle(QwtPlotMarker::VLine);
    miniplotMarker->setLinePen(QPen(Qt::red, 0, Qt::DashDotLine));
    miniplotMarker->attach(plot_mini);

    line[0].curve->setSamples(line[0].data);
     line[3].curve->setSamples(line[3].data);
    tlCursor=0;

}


/* ********************************************************************* 
  @Function name: Graphic::save
  @Return: (bool) 
  @Parameters: 
	const QString& fname 
  @Description: $d
 
 ********************************************************************* */
bool Graphic::save(const QString& fname) {
    if(dataStorage->blockCount()) {
        return (this->dataStorage->saveToFile(fname));
    }
    else {
        QMessageBox::warning(0,"",tr("nothing to save"));
    }
    return false;
}


/* ********************************************************************* 
  @Function name: Graphic::load
  @Return: (bool) 
  @Parameters: 
	const QString& fname 
  @Description: $d
 
 ********************************************************************* */
bool Graphic::load(const QString& fname) {
    if(dataStorage->loadFromFile(fname)) {
        tlCursor = dataStorage->blockCount()-1;
        tlMaximum = dataStorage->blockCount()-1;
        setEnabled(true);
        return true;
    }
    return false;
}


/* ********************************************************************* 
  @Function name: Graphic::clearData
  @Return: (void) 
  @Parameters: 
	 
  @Description: $d
 
 ********************************************************************* */
void Graphic::clearData()
{
    tlCursor=0;
    dataStorage->clearBlocks();
    line[0].data.clear();
    line[1].data.clear();
    line[2].data.clear();
    line[3].data.clear();
    updateGraphic();
}



/* ********************************************************************* 
  @Function name: Graphic::moved
  @Return: (void) 
  @Parameters: 
	const QPoint &point 
  @Description: $d
 
 ********************************************************************* */
void Graphic::moved(const QPoint &point)
{

    if(btnTriggerOn->isChecked())
    {
        Y = plot->invTransform(QwtPlot::yLeft,point.y());
        if(cmbChooseControl->currentIndex()==0)
        {
            d_marker1_cable1->setValue(Y,Y);
            d_marker2_cable1->setValue(-Y,-Y);
            this->trig1=(quint32)toADCValue(Y);
        }
        if(cmbChooseControl->currentIndex()==1)
        {
            d_marker1_cable2->setValue(Y,Y);
            d_marker2_cable2->setValue(-Y,-Y);
            this->trig4=(quint32)Y;
        }
    }
    else if(btnDragOn->isChecked())    {
        qint16 cur_x = plot->invTransform(QwtPlot::xBottom,point.x());
        dragX= X - cur_x;
        if(!dragActivated)        {
            x_dragged( dragX);
        }
        dragActivated =0;
        X = cur_x;
    }

    plot->replot();
}


/* ********************************************************************* 
  @Function name: Graphic::showCurve
  @Return: (void) 
  @Parameters: 
	QwtPlotItem *item
	 bool on 
  @Description: $d
 
 ********************************************************************* */
void Graphic::showCurve(QwtPlotItem *item, bool on)
{
    item->setVisible(on);
    line[3].curve->setVisible(line[2].curve->isVisible());
    if(item == line[0].curve)    {
        d_marker1_cable1->setVisible(item->isVisible());
        d_marker2_cable1->setVisible(item->isVisible());
    }
    if(item == line[1].curve)    {
        d_marker1_cable2->setVisible(item->isVisible());
        //d_marker2_cable2->setVisible(item->isVisible());
    }
    QWidget *w = d_legend->find(item);
    if ( w && w->inherits("QwtLegendItem") )    {
        ((QwtLegendItem *)w)->setChecked(on);
    }
    plot->replot();
}



/* ********************************************************************* 
  @Function name: Graphic::setTriggerOn
  @Return: (void) 
  @Parameters: 
	bool on 
  @Description: $d
 
 ********************************************************************* */
void Graphic::setTriggerOn(bool on){
    if(btnDragOn->isChecked()) btnDragOn->setChecked(!on);
}


/* ********************************************************************* 
  @Function name: Graphic::setGridVisible
  @Return: (void) 
  @Parameters: 
	bool on 
  @Description: $d
 
 ********************************************************************* */
void Graphic::setGridVisible(bool on){
    grid->setVisible(on);    //***********wavelet algorithm************************
    vcInit(&vc);

    vc_setup(&vc,DEFAULT_COLOR_TOLERANCE,DEFAULT_WTRIGGER
             ,DEFAULT_LAST_VALUES_COUNT
             ,DEFAULT_REFERENCE_VALUES_COUNT);
}


/* ********************************************************************* 
  @Function name: Graphic::setDragModeOn
  @Return: (void) 
  @Parameters: 
	bool on 
  @Description: $d
 
 ********************************************************************* */
void Graphic::setDragModeOn(bool on)
{
    if(btnTriggerOn->isChecked()) btnTriggerOn->setChecked( !on  );
    if(on)    {
        plot->canvas()->setCursor(QCursor(Qt::ClosedHandCursor));
        d_picker->setRubberBand(QwtPicker::VLineRubberBand);
    }
    else    {
        plot->canvas()->setCursor(QCursor(Qt::CrossCursor));
        d_picker->setRubberBand(QwtPicker::HLineRubberBand);
    }
}


/* ********************************************************************* 
  @Function name: Graphic::contextMenuClicked
  @Return: (void) 
  @Parameters: 
	const QPoint &position 
  @Description: $d
 
 ********************************************************************* */
void Graphic::contextMenuClicked(const QPoint &position){
    popupMenuOnScreen->popup(plot->mapToGlobal(position));
}



/* ********************************************************************* 
  @Function name: Graphic::setPickerActivate
  @Return: (void) 
  @Parameters: 
	bool on 
  @Description: $d
 
 ********************************************************************* */
void Graphic::setPickerActivate(bool on){
    dragActivated =on;
}



/* ********************************************************************* 
  @Function name: Graphic::axisScaleTimeReleased
  @Return: (void) 
  @Parameters: 
	double value 
  @Description: $d
 
 ********************************************************************* */
void Graphic::rescaleAxisX(double value){
    scale_x = value;
    for ( quint16 i = 0; i < scale_x; i++ ){
        timeData[(quint32)scale_x - 1 - i] = i;//!!!
    }
    plot->setAxisScale(QwtPlot::xBottom,0,scale_x, scale_x / 6);
    plot->replot();

}


/* ********************************************************************* 
  @Function name: Graphic::axisScaleVoltageReleased
  @Return: (void) 
  @Parameters: 
	double value 
  @Description: $d
 
 ********************************************************************* */
void Graphic::rescaleAxisY(double value)
{
    scale_y = value;
    plot->setAxisScale(QwtPlot::yLeft, -scale_y, scale_y, scale_y/2);
    plot->replot();
}



/* ********************************************************************* 
  @Function name: Graphic::setupTriggers
  @Return: (void) 
  @Parameters: 
	quint32 wtrig
	quint32 trigcnt
	quint32 trigsum
	quint32 trig 
  @Description: $d
 
 ********************************************************************* */
void Graphic::setupTriggers(quint32 wtrig,quint32 trigcnt,quint32 trigsum,quint32 trig)
{
    QString tmp;
    this->trig1=trig;
    this->trig2=trigcnt;
    this->trig3=trigsum;
    this->trig4=wtrig;

    d_marker1_cable1->setValue(toVoltage(trig),toVoltage(trig));
    d_marker2_cable1->setValue(-toVoltage(trig),-toVoltage(trig));

    d_marker1_cable2->setValue(wtrig,wtrig/1000);
    d_marker2_cable2->setVisible(0);

    this->wtrig_lb->setText(tmp.sprintf("<b>Wt trig</b>=%u",wtrig));
    this->trigcnt_lb->setText(tmp.sprintf("<b>trigger counter</b>=%d",trigcnt));
    this->trigsum_lb->setText(tmp.sprintf("<b>trigger summa</b>=%d",trigsum));
    this->trigval_lb->setText(tmp.sprintf("<b>trigger</b>=%5.0fmV", toVoltage(trig)));
}


/* ********************************************************************* 
  @Function name: Graphic::updateStatusBox
  @Return: (void) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
void Graphic::updateStatusBox(void )
{
    ///setting icons
    al_ico->set_on(status.bits.Alarm);
    warn1_ico->set_on(status.bits.Tamper1);
    warn2_ico->set_on(status.bits.Tamper2);
    tester_ico->set_on(status.bits.TesterEnabled);
    terminal_ico->set_on(status.bits.CableState);
    pwr_ico->set_on(status.bits.PowerProblem);
    acc_ico->set_on(status.bits.AccMove);
    warning_ico->set_on(status.bits.Warning);
    digin_ico->set_on(status.bits.DigitalIn);

    al_ico->repaint();
    warn1_ico->repaint();
    warn2_ico->repaint();
    terminal_ico->repaint();
    tester_ico->repaint();
    acc_ico->repaint();
    pwr_ico->repaint();
    digin_ico->repaint();
    warning_ico->repaint();
}


/* ********************************************************************* 
  @Function name: Graphic::dropMarker
  @Return: (void) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
void Graphic::dropMarker(void)
{
    unsigned char fq= (point_sec==0)?5:point_sec;
    dataStorage->appendMarker(toDt(QDateTime::currentDateTime()),fq);
}


/* ********************************************************************* 
  @Function name: gotCommandAnswer
  @Return: (void Graphic::) 
  @Parameters: 
	quint8 cmd
	quint32 val
	bool ok 
  @Description: $d
 
 ********************************************************************* */
void Graphic:: gotCommandAnswer(quint8 cmd,quint32 val,bool ok)
{
QString tmp;
    if(ok)
    {
        switch(cmd)
        {
            case 0x01://a0 read
            {
                status.value=val;
                updateStatusBox();
                break;
            }
            case 0x0f:
            case 0x0a://a0 read
            {
                quint32 adc_val;
                double voltage;
                //save this point
                if(dataStorage->blockCount()==0){
                    startDateTime=QDateTime::currentDateTime();
                    dropMarker();
                }


                dataStorage->appendData(val);

                //status
                status.value=val>>16;
                adc_val=val&0x000003ff;
                voltage=toVoltage(adc_val)-zero;

                processStatus(status.value);

                updateGraphic();
                applyData(voltage);

                //fro date syncronizators
                if(dateSyncCtr++ >= 200){
                    dateSyncCtr=0;
                    dropMarker();
                }

                tlCursor=dataStorage->blockCount()-1;
                tlMaximum =dataStorage->blockCount()-1;

                point_ctr++;//fps
            }
                break;

            case 0x03:
                powerv_lb->setText(tmp.sprintf("<b>power mV</b>=%5.2f",(double)val*23.5));
                break;

            case 0x05://terminal
                terminal_lb->setText(tmp.sprintf("<b>terminal unit</b>:%u",val));
                break;

            case 0x08://ID
                if( (val < 2019999u) && (val > 2010000u) ) {
                    id_lb->setText(tmp.sprintf("<b><l>SENSOR ID:%u</l></b>",val));
                }
                else{
                    id_lb->setText(tmp.sprintf("<b><l>SENSOR ID:-NO ID-</l></b>"));
                }
                break;

            case 0x0b://zero read
                #ifdef QT_DEBUG
                qDebug()<<"zero=" << val << toVoltage(val);
                #endif
                zero=toVoltage(val);
                zero_lb->setText(tmp.sprintf("<b>zero</b>=%5.2fmV",zero));
                break;

        }
    }
}


/* ********************************************************************* 
  @Function name: Graphic::processStatus
  @Return: (void) 
  @Parameters: 
	quint32 val 
  @Description: $d
 
 ********************************************************************* */
void Graphic::processStatus(quint32 val)
{
    static Status_t status_old;
    static Status_t status;
    static Status_t status_dif;
    status.value=val;
    status_dif.value=status_old.value ^ status.value;

    if(status_dif.bits.Alarm &&status.bits.Alarm)
    {        
        dropMarker();
    }

    status_old=status;
    updateStatusBox();
}


/* ********************************************************************* 
  @Function name: Graphic::applyData
  @Return: (void) 
  @Parameters: 
	double voltage 
  @Description: $d
 
 ********************************************************************* */
void Graphic::applyData(double voltage)
{
    static double old_voltage;
    QString tmp;

    //populating data
    cur_voltage_lb->setText(tmp.sprintf("<b>signal</b>=%5.2f mV",voltage));
    w_val_lb->setText(tmp.sprintf("<b>Wt</b>=%d",(qint32)vc.wval));
    v0_v1_lb->setText(tmp.sprintf("<b>v0-v1</b>=%5.2f mV",old_voltage-voltage));
    old_voltage=voltage;

    localzero_lb->setText(tmp.sprintf("<b>local zero</b>=%5.0fmV",toVoltage(vc.ref_v)));
    tmp=QString("<p><b>file size:</b> %2</p>"
                "<p><b>records:</b> %1</p>"
                "<p><b>started at:%3</b></p>"
                )   .arg(dataStorage->blockCount())
                    .arg(dataStorage->dataSize())
                    .arg(startDateTime.toString("dd:MM:yyyy [hh:mm:ss] "));
    fileinfo_lb->setText(tmp);

}


/* ********************************************************************* 
  @Function name: Graphic::toVoltage
  @Return: (double) 
  @Parameters: 
	qint32 v 
  @Description: $d
 
 ********************************************************************* */
double Graphic::toVoltage(qint32 v)
{
   return convertToMambaVoltage(v);
}


/* ********************************************************************* 
  @Function name: newValue
  @Return: (void Graphic::) 
  @Parameters: 
	quint8 graf_n
	double dval 
  @Description: $d
 
 ********************************************************************* */
void Graphic:: newValue(quint8 graf_n,double dval)
{
//    //moving if datacount < then i
//    for ( int i = dataCount;( i < scale_x )&& i > 0; i-- )
//    {
//           line[graf_n].data[i]= line[graf_n].data[i-1];
//    }

//    line[graf_n].data[0] = dval;
//    if ( dataCount < scale_x )
//        dataCount++;
//    for ( int j = 0; j < scale_x; j++ )
//        timeData[j]++;
//    plot->setAxisScale(QwtPlot::xBottom,timeData[scale_x- 1], timeData[0]);
}


/* ********************************************************************* 
  @Function name: Graphic::updateSlider
  @Return: (void) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
void Graphic::updateSlider(void)
{     
     slDataSlider->setMaximum(tlMaximum);
     slDataSlider->setValue(tlCursor);
}


/* ********************************************************************* 
  @Function name: Graphic::updateGraphic
  @Return: (void) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
void Graphic::updateGraphic(void)
{

    int i=scale_x;
   int di=tlCursor;
   line[0].data.clear();
   line[1].data.clear();
   line[2].data.clear();
   line[3].data.clear();
   //if some data
  if(dataStorage->blockCount())
   {

        while( i && di )
        {
            if(dataStorage->block_at(di).id == DataStorage<quint32>::BlockData)
            {
                Status_t st;
                QPointF point1,point2,point3,point4;
                quint32 adc_val;
                quint32 val = dataStorage->block_at(di).data;

                st.value = (quint16)(val>>16);
                adc_val = val&0x000003ff;

                double voltage=toVoltage(adc_val)-zero;

                point1.setX(i);
                point1.setY(voltage);
                line[0].data.append(point1);

                vcAddNewValue(&vc,adc_val);
                point2.setX(i);
                point2.setY(vc.wval/100);
                line[1].data.append(point2);

                point3.setX(i);
                point3.setY(st.bits.Alarm?scale_y:0);
                line[2].data.append(point3);
                point3.setY(st.bits.Alarm?-scale_y:0);
                line[3].data.append(point3);

                //line[3].data.append(point4);
                //qDebug()<<point;
                i--;
            }
            di--;
        }


        //***************ALTER
        if(dataStorage->blockCount())
        {
//            //find nearest left merker
            quint32 i = dataStorage->leftMarker(tlCursor);
            //getting frequency and calc seconds to add
            quint32 secs=(tlCursor-i)/dataStorage->block_at(i).fq;
            //marker datetime
            QDateTime markerdt=toQdt(dataStorage->block_at(i).datetime);
            //seconds adding to marker datetime and show
            curdatetime_lb->setText(markerdt.addSecs(secs).toString("yy.MM.dd hh:mm:ss"));
        }
        //plot_mini->replot();


   }
    line[0].curve->setSamples(line[0].data);
    line[1].curve->setSamples(line[1].data);
    line[2].curve->setSamples(line[2].data);
    line[3].curve->setSamples(line[3].data);
    updateSlider();
    plot->replot();
}


/**********!!!!!!!!!!!!!!!!!!*/

/* ********************************************************************* 
  @Function name: Graphic::x_dragged
  @Return: (void) 
  @Parameters: 
	qint16 dragx 
  @Description: $d
 
 ********************************************************************* */
void Graphic::x_dragged(qint16 dragx){//drags graphic X axis
    qint32 position = (qint32)tlCursor + dragx;
    qint32 max_position = (qint32)dataStorage->blockCount()-1;
    //left border
    position = (position < 0) ? 0 : position;
    //right border
    position = ( position > (max_position) )? max_position : position;
    tlCursor = position;
}

/**********!!!!!!!!!!!!!!!!!!*/

/* ********************************************************************* 
  @Function name: Graphic::on_slDataSlider_sliderMoved
  @Return: (void) 
  @Parameters: 
	qint32 position 
  @Description: $d
 
 ********************************************************************* */
void Graphic::on_slDataSlider_sliderMoved(int position)
{
    position    =   (int)(position < (qint32)scale_x) ? (qint32)scale_x : position;
    position    =   (int)(position > (qint32)tlMaximum) ? (qint32)tlMaximum : position;
    tlCursor = position;
}


/* ********************************************************************* 
  @Function name: Graphic::setTimeLineCursor
  @Return: (void) 
  @Parameters: 
	quint32 cursor 
  @Description: $d
 
 ********************************************************************* */
void Graphic::setTimeLineCursor(quint32 cursor)
{
    this->tlCursor = (cursor < scale_x ) ? scale_x : cursor;
    if(tlCursor > tlMaximum) {
        tlCursor = tlMaximum;
    }
}


/* ********************************************************************* 
  @Function name: Graphic::setTimeLineCursor
  @Return: (void) 
  @Parameters: 
	const QDateTime &qdt 
  @Description: $d
 
 ********************************************************************* */
void Graphic::setTimeLineCursor(const QDateTime &qdt)
{
    qint32 i;

    i = dataStorage->findByDateTime(qdt);
    #ifdef QT_DEBUG
        qDebug() << "searching:" << qdt;
        qDebug() << " number " << i << "total:" << dataStorage->blockCount();
    #endif
    if( i == -1 )
    {
        QMessageBox::warning(0,"warning",tr("This point is not tracked"));
    }
    else{
        setTimeLineCursor(i);
    }
}


/* ********************************************************************* 
  @Function name: Graphic::refresh_plot
  @Return: (void) 
  @Parameters: 
	 
  @Description: $d
 
 ********************************************************************* */
void Graphic::refresh_plot(){

}


/* ********************************************************************* 
  @Function name: c
  @Return: (Graphic::~Graphi) 
  @Parameters: 
	 
  @Description: $d
 
 ********************************************************************* */
Graphic::~Graphic(){

}


/* ********************************************************************* 
  @Function name: Graphic::on_btnGoToBeginning_clicked
  @Return: (void) 
  @Parameters: 
	void 
  @Description: $d
 
 ********************************************************************* */
void Graphic::on_btnGoToBeginning_clicked(void){
    quint32 total = dataStorage->blockCount();
    if( total > 0 ) {
        tlCursor = ( (total > scale_x) ? scale_x : total ) - 1;
    }    
}


/* ********************************************************************* 
  @Function name: Graphic::on_btnGoToEnd_clicked
  @Return: (void) 
  @Parameters: 
	 
  @Description: $d
 
 ********************************************************************* */
void Graphic::on_btnGoToEnd_clicked()
{
    tlCursor = dataStorage->blockCount() - 1;
}

