#ifndef CUSTOMICON_H
#define CUSTOMICON_H

#include <QWidget>
#include <QPixmap>

class CustomIcon : public QWidget
{
    Q_OBJECT
public:
    CustomIcon(QWidget *parent = 0);
    CustomIcon(QWidget *parent
               ,const QImage &icon_on
               ,const QImage &icon_off
               ,const QImage &icon_err) ;

    void setIconOn(const QImage &icon)    ;
    void setIconErr(const QImage &icon)    ;
    void setIconOff(const QImage &icon)    ;

private :
    enum IconState{ICON_OFF,ICON_ON,ICON_ERR} state;
    QSize size;
    QImage img_on;
    QImage img_err;
    QImage img_off;
    void paintEvent(QPaintEvent *);
    void operator =(bool on){ set_on(on);}

signals:
    
public slots:
    void set_state(IconState state);
    void set_on(bool);
    void set_err(bool);
};

#endif // CUSTOMICON_H

