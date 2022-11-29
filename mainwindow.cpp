#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "smtp.h"
#include <QMessageBox>
#include <QSqlQuery>
#include<QIntValidator>
#include <QtPrintSupport/QPrinter>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QtDebug>
#include <QPdfWriter>
#include <QTextStream>
#include<QTextDocument>
#include <QAbstractSocket>
#include"QSortFilterProxyModel"
#include "statistic.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->LINE_CIN->setValidator(new QIntValidator(100, 99999999, this));
    ui->tab_client->setModel(C.afficher());
   connect(ui->pushButtonSend, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->pushButtonClear, SIGNAL(clicked()),this, SLOT(close()));


    socket=new QTcpSocket(this);
   connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
}


MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_B_ajouter_clicked()
{
    int cin=ui->LINE_CIN->text().toInt();
    QString nom =ui->LINE_NOM->text();
    QString prenom =ui->LINE_PRENOM->text();
    Client C(cin,nom,prenom);
bool test=C.ajouter();
if (test)
{
    QMessageBox::information(nullptr, QObject::tr("OK"),
                          QObject::tr("Ajout effectué.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tab_client->setModel(C.afficher());

          }
          else
              QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                          QObject::tr("Ajout non effectué.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_supp_clicked()
{
     /*Client C;
     C.setcin(ui->LINE_C->text().toInt());
    //int cin=ui->LINE_C->text().toInt();
    bool test=C.supprimer(C.getcin());
    QMessageBox msgBox;
    if (test)
    {
        msgBox.setText("Suppression avec succes.");
        ui->tab_client->setModel(C.afficher());

}
    else
      msgBox.setText("Echec de Suppression.");
        msgBox.exec();*/

    Client C1; C1.setcin(ui->LINE_C->text().toInt());
        bool test=C1.supprimer(C1.getcin());
        if (test){


        QMessageBox::information(nullptr, QObject::tr(" OK"),
                    QObject::tr("Delete successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_client->setModel(C.afficher());


    }
    else
            QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                        QObject::tr("Delete failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }








void MainWindow::on_pb_modif_clicked()
{


    Client C2;
        int cin=ui->LINE_C->text().toInt();
        QString nom=ui->LINE_N->text();
        QString prenom=ui->LINE_P->text();

         bool test=C2.Modifier(cin,nom,prenom);
         if (test){
             QMessageBox::information(nullptr, QObject::tr(" OK"),
                         QObject::tr("modifier successful.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_client->setModel(C2.afficher());

         }
         else
         {QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                         QObject::tr("modifier failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);}

    }






void MainWindow::on_B_pdf_clicked()
{
    QSqlDatabase db;
                   QTableView tab_client;
                   QSqlQueryModel * Modal=new  QSqlQueryModel();

                   QSqlQuery qry;
                    qry.prepare("SELECT * FROM client ");
                    qry.exec();
                    Modal->setQuery(qry);
                   tab_client.setModel(Modal);



                    db.close();


                    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = tab_client.model()->rowCount();
                    const int columnCount =  tab_client.model()->columnCount();


                    const QString strTitle ="Document";


                    out <<  "<html>\n"
                        "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg(strTitle)
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"
                       << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des Clients")
                       <<"<br>"
                        <<"<table border=1 cellspacing=0 cellpadding=2>\n";

                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!tab_client.isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(tab_client.model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!tab_client.isColumnHidden(column)) {
                                QString data = tab_client.model()->data(tab_client.model()->index(row, column)).toString().simplified();
                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                            }
                        }
                        out << "</tr>\n";
                    }
                    out <<  "</table>\n"
                            "<br><br>"
                            //<< QString("<p><img src=":/img/aze.png"; width="200"; height="200";\">%1</p>\n")
                            <<"<br>"
                            <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                        out << "<thead><tr bgcolor=#f0f0f0>";

                            out <<  "</table>\n"

                        "</body>\n"
                        "</html>\n";

                    QTextDocument *document = new QTextDocument();
                    document->setHtml(strStream);

                    QPrinter printer;
                    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                    if (dialog->exec() == QDialog::Accepted) {

                        QLabel lab;
                         QPixmap pixmap(":/img/aze.png");
                        lab.setPixmap(pixmap);
                        QPainter painter(&lab);
                        //QPrinter printer(QPrinter::PrinterResolution);

                        //pixmap.load("aze.png");
                        //painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                        //painter.drawPixmap(10,10,50,50, pixmap);

                        document->print(&printer);
                    }

                    printer.setOutputFormat(QPrinter::PdfFormat);
                    printer.setPaperSize(QPrinter::A4);
                    printer.setOutputFileName("/tmp/commandes.pdf");
                    printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                    delete document;
}



void MainWindow::on_B_tri_clicked()
{

    ui->tab_client->setModel(C.trierClient());

}



void MainWindow::on_B_rech_clicked()
{
   Client c;

        c.rechercher(ui->line_rech->text(),ui->tab_client);;

        ui->line_rech->setText("");
}

void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->lineEditEmailCredentials->text(), ui->lineEditPasswordCredentials->text(), ui->lineEditHost->text(), ui->lineEditPort->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->lineEditEmailCredentials->text(), ui->lineEditEmailTo->text() , ui->lineEditSubject->text(),ui->lineEdit->text(), files );
    else
        smtp->sendMail(ui->lineEditEmailCredentials->text(), ui->lineEditEmailTo->text() , ui->lineEditSubject->text(),ui->lineEdit->text());
}


void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}





void MainWindow::on_pushButton_2_clicked()
{


      QString id;
      id=ui->idforpoints->text();
      int aux=C.nbrevent(id);
      QString s = QString::number(aux);

    }


void MainWindow::on_pushButton_3_clicked()
{
    QString id;

            id=ui->idforpoints->text();
            int aux=C.nbrevent(id);
            aux=aux*10;
             QString s = QString::number(aux);


            bool test=C.remise(id);

            if(test){
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("remise successful.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);


            }
            else

            {

                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("remise failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);


            }
}


void MainWindow::on_pb_stat_clicked()
{
    Client C;
        try{
            QT_CHARTS_USE_NAMESPACE
            QChart *chart = new QChart();
            QBarSeries *series = new QBarSeries();
            QBarCategoryAxis *axis = new QBarCategoryAxis();

            QBarSet *set = new QBarSet(" Point de fidelite");
            QStringList typesList;
            QList<QBarSet *> nbrList;
            std::map<QString , int> list = C.statNbrPerType();
            for(auto itr = list.begin() ; itr != list.end(); itr++) {
                typesList.append(itr->first);
    //            nbrList.append(itr->second);
                *set << itr->second;
                nbrList.append(set);
            }
            qDebug() << typesList;
            series->append(set);
            chart->addSeries(series);
            chart->setAnimationOptions(QChart::AllAnimations);
            axis->append(typesList);
            chart->createDefaultAxes();
            chart->setAxisX(axis, series);
            chart->legend()->setAlignment(Qt::AlignBottom);
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
            QPalette pal = qApp->palette();
            pal.setColor(QPalette::Window, QRgb(0x0d4261));
            pal.setColor(QPalette::WindowText, QRgb(0x95212c));
            qApp->setPalette(pal);
            QFont font;
            font.setPixelSize(40);
            chart->setTitleFont(font);
            chart->setTitleBrush(QBrush(Qt::red));
            chart->setTitle("statistique Point fidelite PER CIN");
            chartView->setChart(chart);
            chartView->showNormal();



        }catch(...){

}
}
