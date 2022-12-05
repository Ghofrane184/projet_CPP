#include "salle.h"

#include <QSqlQuery>
#include <QtDebug>
#include<QSqlQueryModel>
#include <QString>
#include <QFileDialog>
#include <QTextDocument>
#include <QObject>
#include<QDate>
#include<QSoundEffect>
#include <QIcon>
#include <QSystemTrayIcon>
#include <QMessageBox>

salle::salle()
{
nom="";
capacity=0;
genre="";
date="";
}

salle::salle(QString nom ,int capacity,QString genre,QString date)
{
this->nom=nom;
this->capacity=capacity;
this->genre=genre;
this->date=date;
}


QString salle::getnom(){
    return nom;
}

QString salle::getgenre(){
    return genre;
}
QString salle::getdate(){
    return date;
}

void salle::setnom(QString nom){
    this->nom=nom;

}
void salle::setgenre(QString genre){
    this->genre=genre;
}
void salle::setdate(QString date){
    this->date=date;
}



bool salle::ajouter(){

    QSqlQuery query;
   QString cap=QString::number(capacity);

    query.prepare("INSERT INTO SALLE (NOM_SALLE,CAPACITY,GENRE,DATE_SALLE) VALUES (:nom,:capacity,:genre,:date)");

    query.bindValue(":nom",nom);
    query.bindValue(":genre",genre);
    query.bindValue(":date", date);
    query.bindValue(":capacity",cap);



    return query.exec();



}

QSqlQueryModel* salle::afficher(){

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from SALLE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Capacity"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Genre"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));


   return model;

}
bool salle::supprimer(int id){
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM SALLE WHERE ID_SALLE=:id");
    query.bindValue(":id",res);



    return query.exec();


}
bool salle::recherche_id(int id)
{


    QSqlQuery query;
     QString id_string=QString::number(id);
    query.prepare("SELECT * FROM SALLE WHERE ID_SALLE= :id");
    query.bindValue(":id", id_string);
    if (query.exec() && query.next())
    {
            return true;
    }
    else
    {
        return false;
    }
}
bool salle::modifier(int id){

    QSqlQuery query;
    QString cap=QString::number(capacity);


    if (id)
    {

          query.prepare("UPDATE SALLE SET NOM_SALLE=:nom, CAPACITY=:cap , GENRE=:genre , DATE_SALLE=:date WHERE ID_SALLE=:id");
          query.bindValue(":id", id);
          query.bindValue(":cap", cap);
          query.bindValue(":nom", nom);
          query.bindValue(":genre",genre);
          query.bindValue(":date",date);

    }
          return query.exec();

}

int salle :: statistique_genre(QString genre)
{
 int nbrEO=0;
  QSqlQuery requete("select * from SALLE where GENRE like '"+genre+"%' ; ");
   while(requete.next())
    {
        nbrEO++;
        }
   return nbrEO;

}
int salle :: statistique_salle()
{
 int nbrEO=0;
  QSqlQuery requete("select * from SALLE ; ");
   while(requete.next())
    {
        nbrEO++;
        }
   return nbrEO;

}
