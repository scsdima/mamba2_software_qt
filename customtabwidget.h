#ifndef CUSTOMTABSHEET_H
    #define CUSTOMTABSHEET_H

    #include <QTabWidget>            
    #include <QTabBar>

    class CustomTabWidget:public QTabWidget
    {
        Q_OBJECT
    public:
        CustomTabWidget(QWidget *parent):QTabWidget(parent){}
        ~CustomTabWidget(){}

        void setUnread(int idx,const QColor &color){
            const_cast<QTabBar*>(tabBar())->setTabTextColor(idx,color);
        }

    private slots:
        void  tab_switched(int tab_n){
            tabBar()->setTabTextColor(tab_n,Qt::AutoColor);
        }
    };

#endif // CUSTOMTABSHEET_H
