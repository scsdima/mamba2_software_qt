/* *********************************************************************


  @File:customicon.cpp

  @Project: E:\workspace_test\1
  @File info : D.Chikov   2014\01\09 21-23-11
  @Description: $d


 
 ********************************************************************* */


#include "customicon.h"
#include <QPainter>


/* ********************************************************************* 
  @Function name: n
  @Return: (CustomIcon::CustomIco) 
  @Parameters: 
	QWidget *parent 
  @Description: $d
 
 ********************************************************************* */
CustomIcon::CustomIcon(QWidget *parent) :
    QWidget(parent)
{
}


/* ********************************************************************* 
  @Function name: n
  @Return: (CustomIcon::CustomIco) 
  @Parameters: 
	QWidget *parent
	const QImage &icon_on
	const QImage &icon_off
	const QImage &icon_err 
  @Description: $d
 
 ********************************************************************* */
CustomIcon::CustomIcon(QWidget *parent,const QImage &icon_on,const QImage &icon_off,const QImage &icon_err) :
    QWidget(parent)
{
    setIconOn(icon_on);
    setIconOff(icon_off);
    setIconErr(icon_err);
}

/* ********************************************************************* 
  @Function name: CustomIcon::setIconOn
  @Return: (void) 
  @Parameters: 
	const QImage &icon 
  @Description: $d
 
 ********************************************************************* */
void CustomIcon::setIconOn(const QImage &icon)    {
    this->img_on=icon;
}


/* ********************************************************************* 
  @Function name: CustomIcon::setIconErr
  @Return: (void) 
  @Parameters: 
	const QImage &icon 
  @Description: $d
 
 ********************************************************************* */
void CustomIcon::setIconErr(const QImage &icon)    {
    this->img_on=icon;
}


/* ********************************************************************* 
  @Function name: CustomIcon::setIconOff
  @Return: (void) 
  @Parameters: 
	const QImage &icon 
  @Description: $d
 
 ********************************************************************* */
void CustomIcon::setIconOff(const QImage &icon)    {
    this->img_off=icon;
}


/* ********************************************************************* 
  @Function name: CustomIcon::set_on
  @Return: (void) 
  @Parameters: 
	bool on 
  @Description: $d
 
 ********************************************************************* */
void CustomIcon::set_on(bool on)
{
    state=on?ICON_ON:ICON_OFF;
}

/* ********************************************************************* 
  @Function name: CustomIcon::set_err
  @Return: (void) 
  @Parameters: 
	bool err 
  @Description: $d
 
 ********************************************************************* */
void CustomIcon::set_err(bool err)
{
    static IconState prev_state;
    if(err) prev_state=this->state;
    state=err?ICON_ERR:prev_state;
}

/* ********************************************************************* 
  @Function name: CustomIcon::set_state
  @Return: (void) 
  @Parameters: 
	IconState state 
  @Description: $d
 
 ********************************************************************* */
void CustomIcon::set_state(IconState state)
{
    this->state=state;
}



/* ********************************************************************* 
  @Function name: CustomIcon::paintEvent
  @Return: (void) 
  @Parameters: 
	QPaintEvent *ev 
  @Description: $d
 
 ********************************************************************* */
void CustomIcon::paintEvent(QPaintEvent *ev){
    QPainter p(this);
    p.drawImage(QPoint(0,0),state?img_on:img_off);
    p.end();
}
