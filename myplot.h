#ifndef MYPLOT_H
#define MYPLOT_H
#include <QPushButton>
#include <QWidget>
#include <qcustomplot.h>

class MyPlot : public QCustomPlot
{
    Q_OBJECT
public:
    explicit MyPlot(QWidget *parent = 0);
    //QVector<double> time(21), value(21);//给数组赋值，时间和数值 7*3=21个数据

signals:

public slots:
protected:
    void wheelEvent(QWheelEvent *event);
private:
  QVector<double> time , value ;//给数组赋值，时间和数值 7*3=21个数据
    QVector<double> xBarVector, yBarVector;
    QCPBars *rectBar ;
    //    QVector<double>year_value,  month_value, week_value,day_value;
    QString results = "2016-06-01 08:00:00#36#"
                      "2016-06-01 12:00:00#37#2016-06-01 18:00:00#37#"
                      "2016-06-02 08:00:00#36#2016-06-02 12:00:00#37#"
                      "2016-06-02 18:00:00#37#2016-06-03 08:00:00#36#"
                      "2016-06-03 12:00:00#35#2016-06-03 18:00:00#37#"
                      "2016-06-04 08:00:00#36#2016-06-04 12:00:00#37#"
                      "2016-06-04 18:00:00#37#2016-06-05 08:00:00#36#"
                      "2016-06-05 12:00:00#37#2016-06-05 18:00:00#36#"
                      "2016-06-06 08:00:00#37#2016-06-06 12:00:00#36#"
                      "2016-06-06 18:00:00#37#2016-06-07 08:00:00#37#"
                      "2016-06-07 12:00:00#37#2016-06-07 18:00:00#36#";

};

#endif // MYPLOT_H
