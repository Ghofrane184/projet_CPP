#include "reservation.h"
#include <QTableView>


reservation::reservation(int ID_reservation,QString type_reservation,int ID_salle,int ID_client,QString date_reservation)
{
    this->id_reservation=ID_reservation;
    this->type_reservation=type_reservation;
    this->id_salle=ID_salle;
    this->id_client=ID_client;
    this->date_reservation=date_reservation;
}



bool reservation::ajouter()
{
QSqlQuery query;
QString id_reservation_string =QString::number(id_reservation);
QString id_salle_string =QString::number(id_salle);
QString id_client_string =QString::number(id_client);


query.prepare("INSERT INTO GESTION_RESERVATION (ID_RESERVATION, TYPE_RESERVATION, ID_SALLE , ID_CLIENT , DATE_RESERVATION) "
                    "VALUES (:ID_RESERVATION, :TYPE_RESERVATION, :ID_SALLE , :ID_CLIENT , :DATE_RESERVATION)");


query.bindValue(":ID_RESERVATION", id_reservation);
query.bindValue(":TYPE_RESERVATION", type_reservation);
query.bindValue(":ID_SALLE", id_salle);
query.bindValue(":ID_CLIENT", id_client);
query.bindValue(":DATE_RESERVATION", date_reservation);

return    query.exec();
}



QSqlQueryModel * reservation::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from GESTION_RESERVATION");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RESERVATION"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_RESERVATION"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_SALLE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_CLIENT"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_RESERVATION"));
        return model;
}



bool reservation::supprimer(int id_reservation)
{
QSqlQuery query;
QString id_reservation_string =QString::number(id_reservation);
query.prepare("Delete from GESTION_RESERVATION where ID_RESERVATION=:ID_RESERVATION");
query.bindValue(":ID_RESERVATION",id_reservation_string);
return    query.exec();
}




bool reservation::modifier(int id_reservation,QString type_reservation,int id_salle,int id_client,QString date_reservation)
{
    QSqlQuery query;
    QString id_reservation_string =QString::number(id_reservation);
    QString id_salle_string =QString::number(id_salle);
    QString id_client_string =QString::number(id_client);

    query.prepare("update GESTION_RESERVATION set TYPE_RESERVATION=:TYPE_RESERVATION,ID_SALLE=:ID_SALLE,ID_CLIENT=:ID_CLIENT,DATE_RESERVATION=:DATE_RESERVATION where ID_RESERVATION=:ID_RESERVATION");


    query.bindValue(":ID_RESERVATION", id_reservation);
    query.bindValue(":TYPE_RESERVATION", type_reservation);
    query.bindValue(":ID_SALLE", id_salle);
    query.bindValue(":ID_CLIENT", id_client);
    query.bindValue(":DATE_RESERVATION", date_reservation);

    return    query.exec();
}
//recherche selon 3 criteres

bool reservation::rechidreservation(int x){
    QSqlQuery query;
    query.prepare("select * from GESTION_RESERVATION where ID_RESERVATION = :ID_RESERVATION;");
    query.bindValue(":ID_RESERVATION", x);
    return query.exec();
}

QSqlQueryModel* reservation::rechercheridreservation(QString a)
    {

    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from GESTION_RESERVATION where ID_RESERVATION ='"+a+"' ");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RESERVATION"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_RESERVATION"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_SALLE"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_CLIENT"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_RESERVATION"));
            return model;
    }

bool reservation::rechidclient(int x){
    QSqlQuery query;
    query.prepare("select * from GESTION_RESERVATION where ID_CLIENT = :ID_CLIENT;");
    query.bindValue(":ID_CLIENT", x);
    return query.exec();}

QSqlQueryModel* reservation::rechercheridclient(QString a)
    {

    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from GESTION_RESERVATION where ID_CLIENT ='"+a+"' ");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RESERVATION"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_RESERVATION"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_SALLE"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_CLIENT"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_RESERVATION"));
            return model;
    }
bool reservation::rechidsalle(int x){
    QSqlQuery query;
    query.prepare("select * from GESTION_RESERVATION where ID_SALLE = :ID_SALLE;");
    query.bindValue(":ID_SALLE", x);
    return query.exec();
}
QSqlQueryModel* reservation::rechercheridsalle(QString a)
    {

    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from GESTION_RESERVATION where ID_SALLE ='"+a+"' ");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RESERVATION"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_RESERVATION"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_SALLE"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_CLIENT"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_RESERVATION"));
            return model;
    }

QSqlQueryModel * reservation::trie_type()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM GESTION_RESERVATION ORDER BY TYPE_RESERVATION ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_RESERVATION"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_RESERVATION"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_SALLE"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_CLIENT"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_RESERVATION"));
    return model;
}

void reservation::statistique(QVector<double>* ticks,QVector<QString> *labels)
{
    QSqlQuery q;
    int i=0;
    q.exec("select TYPE_RESERVATION from GESTION_RESERVATION GROUP BY TYPE_RESERVATION ");
    while (q.next())
    {
        QString identifiant = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<identifiant;
    }
}
/*
void MainWindow::on_tab_passager_clicked(const QModelIndex &index)
{
    QString numpass=ui->tab_passager->model()->data(index).toString();
     QSqlQuery qry;
     qry.prepare("select * from PASSAGER where NUMPASS=:NUMPASS");
     qry.bindValue(":NUMPASS",numpass);
     if (qry.exec())
     {
         while(qry.next())
         {


             QString s=("numero passeport: "+qry.value(0).toString()+"\n""Nom: "+qry.value(4).toString()+"\n""Prenom: "+qry.value(2).toString()+"\n""Destination: "+qry.value(5).toString()+"\n""Classe: "+qry.value(3).toString()+"\n""Billet: "+qry.value(6).toString()+"\n""Bagages: "+qry.value(1).toString());
             ui->tab_pdf->setText(s);
         }
     }
         else
         {
            QMessageBox::warning(this,"error","no information");
         }
}


void MainWindow::on_pb_impri_clicked()
{
    QPrinter printer;
    printer.setPrinterName("fichier");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)
    {

        return ;
    }
    else
        ui->tab_pdf->print(&printer);
}
*/
