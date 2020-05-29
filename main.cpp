#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString qss;
    QFile qssFile(":/stylesheet.qss");
    qssFile.open(QFile::ReadOnly);

    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        qApp->setStyleSheet(qss);
        qssFile.close();
        qDebug()<<"of";
    }


    MainWindow w;
    w.show();

    return a.exec();
}
