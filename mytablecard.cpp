#include "mytablecard.h"
#include <QLabel>
#include <myplot.h>
MyTableCard::MyTableCard(QWidget *parent) : QWidget(parent)
{
    //设置显示日均 数值 时间
    QSize size(320*1.3,320*1.3);
    setFixedSize(size);
    QLabel *name =new QLabel(this);
    name->setGeometry(10,0,180,25);
    name->setFont(QFont("Timers",9, QFont::Bold));
    name->setText("日均");
    QLabel *value =new QLabel(this);
    value->setGeometry(20,25,180,25);
    value->setFont(QFont("Timers",17, QFont::Bold));
    value->setText("65");
    QLabel *timeLabel =new QLabel(this);
    timeLabel->setGeometry(10,50,180,30);
    timeLabel->setFont(QFont("Timers",9, QFont::Bold));
    timeLabel->setText("2019年6月至2020年6月");

    //设置图表
    MyPlot *plot=new MyPlot(this);
    plot->setParent(this);
    plot->move(0,80);


}
