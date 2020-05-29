#include "myplot.h"
#include <qcustomplot.h>
//初始化列表中初始化QVector
MyPlot::MyPlot(QWidget *parent):time(QVector<double>(21)),value(QVector<double>(21))
{

    QSize size(320*1.3,320*1.3-140);
    this->setFixedSize(size);
    this->setLocale(QLocale(QLocale::Chinese, QLocale::China));
    this->addGraph();
    QPen pen;
    pen.setColor(QColor(0, 0, 255, 200));
    this->graph(0)->setLineStyle(QCPGraph::lsLine);//设置数据点由一条直线连接
    this->graph(0)->setPen(pen);

    this->addGraph(); // 红色点
    this->graph(1)->setPen(QPen(Qt::red));
    this->graph(1)->setLineStyle(QCPGraph::lsNone);
    this->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);

    QStringList list = results.split("#");//假设数据
    qDebug()<<list<<list.length();

    QString temp;//定义一个临时变量
    for (int i=0; i<21; ++i)
    {
        time[i] = QDateTime::fromString(list[2*i],"yyyy-MM-dd hh:mm:ss").toTime_t();
        temp = list.at(2*i+1);
        value[i] = temp.toInt();
    }
    this->graph(0)->setData(time, value);//设置数据
    this->graph(0)->rescaleValueAxis();
    this->graph(1)->addData(time, value);//设置点

    //    配置下轴显示日期和时间，而不是数字：
    this->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    this->xAxis->setDateTimeFormat("MM-dd");
    // 设置一个更紧凑的字体大小为底部和左轴刻度标签：
    this->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    this->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
    // 设置一天为固定的一个刻度
    this->xAxis->setAutoTickStep(false);
    this->xAxis->setTickStep(3600*24); // 一天的秒数
    this->xAxis->setSubTickCount(9);//一个大刻度包含4个小刻度
    // 设置轴标签
    this->xAxis->setLabel("时间(h)");
    this->yAxis->setLabel("体温(℃)");
    // 设置上边和右边轴没有刻度和标签
    this->xAxis2->setVisible(true);
    this->yAxis2->setVisible(true);//坐标轴是否可见
    this->xAxis2->setTicks(false);//刻度是否可见
    this->yAxis2->setTicks(false);
    this->xAxis2->setTickLabels(false);//轴标签是否可见
    this->yAxis2->setTickLabels(false);
    // 设置轴范围和显示全部数据
    this->xAxis->setRange(time[0],time[0]+24*3600*7);
    this->yAxis->setRange(30, 45);
    // 显示图例
    this->graph(0)->setName("心率");
    this->graph(1)->setName("具体数值");
    this->legend->setVisible(true);
    this->replot();

}

void MyPlot::wheelEvent(QWheelEvent *event)
{
    this->yAxis->setRange(30, 100);

    this->replot();
    //    static double i=9;
    //    if(event->delta() > 0) //当滚轮向上滑，远离使用者
    //    {
    //        xBarVector.removeFirst();

    //        xBarVector<<i++;
    //        yBarVector.removeFirst();

    //        yBarVector<<i++;
    //        //this->xAxis->setRange(xBarVector.at(0),xBarVector.at(xBarVector.size()-1));
    //        this->yAxis->rescale(true);
    //        qDebug()<<"放大";
    //        rectBar->setData(xBarVector, yBarVector);

    //        this->replot();
    //    }
    //    else //当滚轮向下滑，靠近使用者
    //    {
    //        qDebug()<<"缩小";
    //    }
}
