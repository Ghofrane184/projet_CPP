#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "conx.h"
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include"arduino.h"
#include"popup.h"
#include "mainwindow2.h"
#include "login.h"

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{





    QApplication a(argc, argv);
   PopUp *popUp = new PopUp();



    Connection c;
    bool test=c.createconnect();
    login aa;
    mainwindow2 ww;
     MainWindow w;
    if(test)
    {aa.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }


    return a.exec();
}
