#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
#include <QDateEdit>
#include <QMessageBox>
#include<QIntValidator>
#include<QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegularExpression rnumber("\\b([0-9][0-9][-][0-9][0-9][-][0-9][0-9][0-9][0-9])\\b",QRegularExpression::CaseInsensitiveOption);
        QRegularExpressionValidator *valnumber = new QRegularExpressionValidator(rnumber,this);
         ui->l_dates->setValidator(valnumber);

         QRegularExpression r2number("\\b([a-zA-Z])([a-zA-Z0-9])*\\b",QRegularExpression::CaseInsensitiveOption);
               QRegularExpressionValidator *val1 = new QRegularExpressionValidator(r2number,this);
                ui->l_eventname->setValidator(val1);
                ui->l_eventype->setValidator(val1);
                ui->tab_event->setModel(E.afficher());




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
//int id_event= ui->l_id->text().toInt();

Event E(Dates,type,nom_event);

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
                QObject::tr("Delete failed.\n"
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


