#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
#include "arduino.h"
#include <QDateEdit>
#include <QMessageBox>
#include<QIntValidator>
#include<QSqlQuery>
#include <QtPrintSupport/QPrinter>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QPdfWriter>
#include <QTextStream>
#include <QTextDocument>
#include <QDialog>
#include <QLabel>
#include <QSystemTrayIcon>
#include <QSqlQueryModel>
#include <QComboBox>
#include <QDebug>

// QCHARTS IMPORT

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

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    popUp = new PopUp();



    QRegularExpression rnumber("\\b([0-9][0-9][-][0-9][0-9][-][0-9][0-9][0-9][0-9])\\b",QRegularExpression::CaseInsensitiveOption);
        QRegularExpressionValidator *valnumber = new QRegularExpressionValidator(rnumber,this);
         ui->l_dates->setValidator(valnumber);

         QRegularExpression r2number("\\b([a-zA-Z])([a-zA-Z0-9])*\\b",QRegularExpression::CaseInsensitiveOption);
               QRegularExpressionValidator *val1 = new QRegularExpressionValidator(r2number,this);
                ui->l_eventname->setValidator(val1);
                ui->l_eventype->setValidator(val1);
                ui->tab_event->setModel(E.afficher());


                /*const bool arduinotStatus = A.getConnected();
                if(arduinotStatus){
                    popUp->setPopupText("Arduino is connected");

                       popUp->show();
                }else {
                    QMessageBox::warning(nullptr,QObject::tr( "ARDUINO"),"Could not connect to Arduino uno");
                }
                QObject::connect(A.arduino,SIGNAL(readyRead()),this,SLOT(update_label()));*/





}
MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_PB_ajout_clicked()
{
    QString Dates=ui->l_dates->text();
    QString type=ui->l_eventype->text();
QString nom_event =ui->l_eventname->text();
int cin=ui->l_CIN->text().toInt();
QString ID_event= ui->l_idevent->text();

Event E(ID_event,Dates,type,nom_event,cin);

bool test= E.ajouter();
if (test){
    QMessageBox::information(nullptr, QObject::tr(" OK"),
                QObject::tr("Ajout successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tab_event->setModel(E.afficher());//refresh

}
else
    QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                QObject::tr("Ajout failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}



void MainWindow::on_pb_supp_clicked()
{
    Event E1; E1.setnom_event(ui->l_eventname_supp->text());
    bool test=E1.supprimer(E1.getnom_event());
    if (test){


    QMessageBox::information(nullptr, QObject::tr(" OK"),
                QObject::tr("Delete successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_event->setModel(E.afficher());


}
else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("Ajout failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}






/*void MainWindow::on_PB_modif_clicked()
{
    QSqlQuery query;

    QString Dates=ui->l_Dates_modif->text();
    QString type=ui->l_eventtype_modif->text();
QString nom_event =ui->l_eventname_modif->text();

      query.prepare("UPDATE GESTION_EVENT SET NOM_EVENT='"+nom_event+"',TYPE='"+type+"',DATES='"+Dates+"' ");

       if(query.exec())
        {
           QMessageBox::information(nullptr, QObject::tr(" OK"),
                       QObject::tr("UPDATE successful.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_event->setModel(E.afficher());

        }
        else
        {
           QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                       QObject::tr("uPDATE failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

        }



 }*/


void MainWindow::on_PB_modif_clicked()
{


        Event E2;

        QString Dates=ui->l_Dates_modif->text();
        QString type=ui->l_eventtype_modif->text();
    QString nom_event =ui->l_eventname_modif->text();

             bool test=E2.modifier(Dates,type,nom_event);
             if (test){
                 QMessageBox::information(nullptr, QObject::tr(" OK"),
                             QObject::tr("modifier successful.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
                  ui->tab_event->setModel(E.afficher());

             }
             else
             {QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                             QObject::tr("modifier failed.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}

        }





void MainWindow::on_PB_recherche_clicked()
{

    Event E3;

            E3.rechercher(ui->l_recherche->text(),ui->tab_event);;

    ui->l_recherche->setText("");
}


void MainWindow::on_PB_pdf_clicked()
{QSqlDatabase db;
    QTableView tab_event;
    QSqlQueryModel * Modal=new  QSqlQueryModel();

    QSqlQuery query;
     query.prepare("SELECT * FROM GESTION_EVENT ");
     query.exec();
     Modal->setQuery(query);
    tab_event.setModel(Modal);



     db.close();


     QString strStream;
     QTextStream out(&strStream);

     const int rowCount = tab_event.model()->rowCount();
     const int columnCount =  tab_event.model()->columnCount();


     const QString strTitle ="Document";


     out <<  "<html>\n"
         "<head>\n"
             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
         <<  QString("<title>%1</title>\n").arg(strTitle)
         <<  "</head>\n"
         "<body bgcolor=#ffffff link=#5000A0>\n"
        << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des Event")
        <<"<br>"
         <<"<table border=1 cellspacing=0 cellpadding=2>\n";

     out << "<thead><tr bgcolor=#f0f0f0>";
     for (int column = 0; column < columnCount; column++)
         if (!tab_event.isColumnHidden(column))
             out << QString("<th>%1</th>").arg(tab_event.model()->headerData(column, Qt::Horizontal).toString());
     out << "</tr></thead>\n";

     for (int row = 0; row < rowCount; row++) {
         out << "<tr>";
         for (int column = 0; column < columnCount; column++) {
             if (!tab_event.isColumnHidden(column)) {
                 QString data = tab_event.model()->data(tab_event.model()->index(row, column)).toString().simplified();
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


void MainWindow::on_l_tri_clicked()
{

    ui->tab_event->setModel(E.afficher_tri_nom());

}

void MainWindow::on_l_tridesc_clicked()
{
     ui->tab_event->setModel(E.afficher_tri_nom_DESC());
}

void MainWindow::on_l_triasc_clicked()
{
    ui->tab_event->setModel(E.afficher_tri_nom_ASC());
}

void MainWindow::on_pb_annul_clicked()
{
    Event E1; E1.setID_event(ui->l_ID_event_anull->text());
    bool test=E1.annulation(E1.getID_event());
     QString lol="Event deleted with succes";
      QString lool="Event failed to delete";
    if (test){

    ui->tab_event->setModel(E.afficher());


    popUp->setPopupText(lol);

       popUp->show();

}
else
        popUp->setPopupText(lool);

           popUp->show();


}



void MainWindow::on_PB_loadevent_clicked()
{



 ui->lc_event->setModel(E.load());

}

void MainWindow::on_PB_inscri_clicked()
{
 /*QString text = ui->lc_event->currentText();
 Event E3;
int kj;

QString RFID_RESULT = E3.getUID(text);
qDebug() << "RFID RESULT" << RFID_RESULT;
const bool arduint_access_rfid = A.checkAccessRFID(RFID_RESULT);
qDebug() << "arduino _access rfid" << arduint_access_rfid;
int ko = 0;
kj=E3.retirer(ko);
bool result = E3.updatenbr(text);
if(!arduint_access_rfid){
    QMessageBox::information(nullptr, QObject::tr(" OK"),
                QObject::tr("Wrong Magnetic card.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tab_event->setModel(E.afficher());
}*/
/*if (result && arduint_access_rfid ){
    popUp->setPopupText("Magnetic card ok");
    popUp->show();
if (result){

     QMessageBox::information(nullptr, QObject::tr(" OK"),
                 QObject::tr("inscription successful.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
      ui->tab_event->setModel(E.afficher());

 }
 else
 {QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                 QObject::tr("inscription failed.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);}
qDebug() << result << "update result";*/

}





void MainWindow::on_PB_report_clicked()
{
    QString Dates=ui->l_dates_report->text();
    QString idEvent = ui->l_idevent_report->text();
    QString nom_event =ui->l_eventname_report->text();
    Event E;
    if (E.reportor(Dates,idEvent,nom_event)){
        QMessageBox::information(nullptr, QObject::tr(" OK"),
                        QObject::tr("report successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_event->setModel(E.afficher());

        }
        else
        {QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                        QObject::tr("report failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_PB_stat__nbr_t_clicked()
{
    Event E;
    try{
        QT_CHARTS_USE_NAMESPACE
        QChart *chart = new QChart();
        QBarSeries *series = new QBarSeries();
        QBarCategoryAxis *axis = new QBarCategoryAxis();

        QBarSet *set = new QBarSet(" NBR INSCRIPTION");
        QStringList typesList;
        QList<QBarSet *> nbrList;
        std::map<QString , int> list = E.statNbrPerType();
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
        chart->setTitle("statistique NBR PER TYPE");
        chartView->setChart(chart);
        chartView->showNormal();



    }catch(...){
        qDebug() << "error";
    }

}
/*void MainWindow::update_label()
{
    QString text = ui->lc_event->currentText();
    Event E3;
   int kj;

   QString RFID_RESULT = E3.getUID(text);
   qDebug() << "RFID RESULT" << RFID_RESULT;
   const bool arduint_access_rfid = A.checkAccessRFID(RFID_RESULT);
   qDebug() << "arduino _access rfid" << arduint_access_rfid;
   int ko = 0;
   kj=E3.retirer(ko);
   bool result = E3.updatenbr(text);
   if(!arduint_access_rfid){
       QMessageBox::information(nullptr, QObject::tr(" OK"),
                   QObject::tr("Wrong Magnetic card.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_event->setModel(E.afficher());
   }
   if (result && arduint_access_rfid ){
       popUp->setPopupText("Magnetic card ok");
       popUp->show();*/
       /* QMessageBox::information(nullptr, QObject::tr(" OK"),
                    QObject::tr("inscription successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/
         /*ui->tab_event->setModel(E.afficher());

    }
    else
    {QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("inscription failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
   qDebug() << result << "update result";

}*/
