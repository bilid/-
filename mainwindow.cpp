#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QWheelEvent>
#include <QTableWidget>
#include <qcustomplot.h>
#include "myplot.h"
#include <mytabwidget.h>
#include <mytablecard.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //    QVector<QString> labels(5);
    //    QVector<double> values(5);
    //    for(int i=0;i<5;++i)
    //        labels[i]=QString("MAC")+('0'+i);
    //    values[0]=(10.05);
    //    values[1]=23;
    //    values[2]=12;
    //    values[3]=19.3;
    //    values[4]=20;
    //    MyPlot *eee=new MyPlot(this);
    //    eee->setParent(this);
    //    eee->setGeometry(0,0,500,500);
    //QCPBars* bars=new QCPBars(eee->xAxis,eee->yAxis);

    MyTabWidget *tabWidget=new MyTabWidget();
    tabWidget->setParent(this);
    tabWidget->setGeometry(0,0,320*1.3,320*1.3);

    MyTableCard *card1 = new MyTableCard();
    MyTableCard *card2 = new MyTableCard();
    MyTableCard *card3 = new MyTableCard();
    MyTableCard *card4 = new MyTableCard();

    tabWidget->addTab(card1,"日");
    tabWidget->addTab(card2,"周");
    tabWidget->addTab(card3,"月");
    tabWidget->addTab(card4,"年");
    tabWidget->setStyleSheet("QTabBar::tab {background: #00000000;border: none;border-bottom: 2px solid #3c3e42;width: 55;margin-right: 0px;"
                             "padding-left:20px;padding-right:20px;padding-top:5px;padding-bottom:5px;color:#686a6e;}"
                             "QTabBar::tab:hover {background: #3a3a3f;}"
                             "QTabBar::tab:selected {border-color: #3a3a3f;color:#dcdde4;border-bottom-color: #dcdde4;}");



}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::wheelEvent(QWheelEvent *event)
//{
//    if(event->delta() > 0) //当滚轮向上滑，远离使用者
//    {
//        qDebug()<<"放大";
//    }
//    else //当滚轮向下滑，靠近使用者
//    {
//        qDebug()<<"缩小";
//    }
//}
