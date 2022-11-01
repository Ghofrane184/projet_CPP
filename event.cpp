#include "event.h"
#include <QSqlQuery>
#include <QDebug>
#include <QDateEdit>
#include <QObject>


Event::Event()
{
//ID_event=0;
nom_event=" ";
Dates=" ";
type=" ";
}

Event::Event(QString Dates,QString type,QString nom_event){
//this->ID_event=ID_event;
this->Dates=Dates;
this->type=type;
this->nom_event=nom_event;
   // ID_event=id;
}

/*int Event::getID_event(){
    return ID_event;
}*/
QString Event::getDates(){
    return Dates;
}
QString Event::gettype(){
    return type;
}
QString Event::getnom_event(){
    return nom_event;
}
/*void Event::setID_event(int ID_event){
    this->ID_event=ID_event;
}*/
void Event::setDates(QString Dates){
    this->Dates=Dates;
}
void Event::settype(QString type){
    this->type=type;
}
void Event::setnom_event(QString nom_event){
    this->nom_event=nom_event;
}
bool Event::ajouter(){
    bool test=false;
    QSqlQuery query;


         query.prepare("INSERT INTO GESTION_EVENT (nom_event, type, Dates ) "
                       "VALUES (:nom_event, :type, :Dates)");
         // query.bindValue(":ID_event",ID_event)  ;
         query.bindValue(":Dates", Dates);
         query.bindValue(":type", type);
         query.bindValue(":nom_event", nom_event);
      return query.exec();



         return test;
}
QSqlQueryModel* Event::afficher(){

  QSqlQueryModel* model=new QSqlQueryModel();


       model->setQuery("SELECT* FROM GESTION_EVENT");
       model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM_EVENT"));
       model->setHeaderData(1, Qt::Horizontal,QObject::tr("TYPE"));
       model->setHeaderData(2, Qt::Horizontal,QObject::tr("DATES"));





  return model;
}

bool Event::supprimer(QString nom_event){

    QSqlQuery query;


         query.prepare("Delete from GESTION_EVENT where NOM_EVENT=:nom_event" ) ;

         // query.bindValue(":ID_event",ID_event)  ;

         query.bindValue(":nom_event", nom_event);
      return query.exec();



}

bool Event::modifier(QString Dates,QString type,QString nom_event)
    {
        QSqlQuery query;

        query.prepare("UPDATE gestion_event SET TYPE=:type,DATES=:Dates WHERE NOM_EVENT=:nom_event ");

        query.bindValue(":nom_event", nom_event);
        query.bindValue(":type", type);
        query.bindValue(":Dates", Dates);

        return  query.exec();
}
/*bool Event::modifier(QString Dates,QString type,QString nom_event)
{
    QSqlQuery query;


        query.prepare("UPDATE GESTION_EVENT SET nom_event=:nom_event, type=:type,Dates=:Dates");

        query.bindValue(":Dates", Dates);
        query.bindValue(":type", type);
        query.bindValue(":nom_event", nom_event);

        return    query.exec();
}*/

/*bool Event::modifier(QString Dates, QString type,QString nom_event)
{
    QSqlQuery query;


        query.prepare("UPDATE  SET GESTION_EVENT NOM_EVENT=:nom_event,TYPE=:type, DATES=:Dates");

        query.bindValue(":Dates", Dates);
        query.bindValue(":type", type);
        query.bindValue(":nom_event", nom_event);

        return    query.exec();

}*/



