#include "event.h"
#include <QSqlQuery>
#include <QDebug>
#include <QDateEdit>
#include <QObject>
#include <QVariant>
#include <QSystemTrayIcon>
#include <QSqlError>
#include <QPrinter>
#include <map>
#include <QtSerialPort>
#include <QSerialPortInfo>
#include "arduino.h"


Event::Event()
{
ID_event="";
nom_event=" ";
Dates=" ";
type=" ";
participantNumber = 0;
}

Event::Event(QString ID_event,QString Dates,QString type,QString nom_event){
this->ID_event=ID_event;
this->Dates=Dates;
this->type=type;
this->nom_event=nom_event;
this->participantNumber = 0;
   // ID_event=id;
}

QString Event::getID_event(){
    return ID_event;
}
QString Event::getDates(){
    return Dates;
}
QString Event::gettype(){
    return type;
}
QString Event::getnom_event(){
    return nom_event;
}
void Event::setID_event(QString ID_event){
    this->ID_event=ID_event;
}
void Event::setDates(QString Dates){
    this->Dates=Dates;
}
void Event::settype(QString type){
    this->type=type;
}
void Event::setnom_event(QString nom_event){
    this->nom_event=nom_event;
}
void Event::setParticipantNumber(int number){
    this->participantNumber = number;
}

int Event::getParticipantNumber(){
    return this->participantNumber;
}
bool Event::ajouter(){
    bool test=false;
    QSqlQuery query;


         query.prepare("INSERT INTO GESTION_EVENT (ID_event, nom_event, type, Dates ) "
                       "VALUES (:ID_event, :nom_event, :type, :Dates)");
          query.bindValue(":ID_event",ID_event)  ;
         query.bindValue(":Dates", Dates);
         query.bindValue(":type", type);
         query.bindValue(":nom_event", nom_event);
         query.bindValue(":nbr",0);
      return query.exec();



         return test;
}
QSqlQueryModel* Event::load(){

QSqlQueryModel* model=new QSqlQueryModel();


     model->setQuery("SELECT Nom_event FROM GESTION_EVENT");



     return model;
     }
QSqlQueryModel* Event::afficher(){

  QSqlQueryModel* model=new QSqlQueryModel();


       model->setQuery("SELECT * FROM GESTION_EVENT");
           model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_EVENT"));
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
         qDebug()<<query.lastError();
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

void Event::rechercher(QString a,QTableView *g)
 {QSqlQuery query;
         QSqlQueryModel *m=new QSqlQueryModel();//initialisation
         query.prepare("select * from gestion_event where NOM_EVENT like'%"+a+"%' OR TYPE like '%"+a+"%'" "");
                     query.exec();
                 m->setQuery(query);
        g->setModel(m);


     }

QSqlQueryModel* Event:: afficher_tri_nom()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from GESTION_EVENT order by NOM_EVENT");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_EVENT"));
model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM_EVENT"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("DATES"));


    return model;
}

QSqlQueryModel* Event:: afficher_tri_nom_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from GESTION_EVENT order by NOM_EVENT desc");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_EVENT"));
model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM_EVENT"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("DATES"));

    return model;
}
QSqlQueryModel* Event:: afficher_tri_nom_ASC()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from GESTION_EVENT order by NOM_EVENT asc");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_EVENT"));
model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM_EVENT"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("TYPE"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("DATES"));

    return model;
}

bool Event::annulation(QString ID_event){

    QSqlQuery query;


         query.prepare("Delete from GESTION_EVENT where ID_EVENT=:ID_event" ) ;



         query.bindValue(":ID_event", ID_event);
      return query.exec();



}



bool Event::reportor(QString Dates,QString ID_event, QString nom_event)
{
    try{
        QSqlQuery query;
        QSqlQuery query1;
        query.prepare("SELECT DATES FROM GESTION_EVENT WHERE DATES LIKE :date");
        query.bindValue(":date",Dates);

        int index = 0;
        if(query.exec()){
        while(query.next()){
            index++;
            qDebug() << index << "index";
        }
        if(index != 0){
            return false;
        }else {
            query1.prepare("UPDATE gestion_event SET DATES=:date WHERE NOM_EVENT LIKE :nom");
            query1.bindValue(":date", Dates);
            query1.bindValue(":nom",nom_event);
            return query1.exec();
        }
        }else {
            return false;
        }
    }catch(QSqlError){
        return false;
    }

}

bool Event::retirer(int ko){

QSqlQueryModel* model=new QSqlQueryModel();

QSqlQuery query;
query.prepare("SELECT CAPACITY FROM GESTION_SALLES");
 ko = query.value(0).toInt();
 qInfo() << "============================";
qInfo() << ko;



return  query.exec();

     }


std::map<QString,int> Event::statNbrPerType(){
    QSqlQuery query;
    std::map <QString,int> list;
    try {
        query.prepare("SELECT SUM(NBR) ,TYPE from GESTION_EVENT GROUP BY TYPE");
        if(query.exec()){
            while (query.next()) {
                query.value('s').toInt();
                list.insert({query.value(1).toString() , query.value(0).toInt()});
            }
        return list;
        }



    } catch (...) {
        list["error"] = 0;
        return  list;
    }

}
QString Event::getUID(QString nom){
    try {
        QSqlQuery query;
        query.prepare("SELECT ID_RFID FROM GESTION_EVENT WHERE NOM_EVENT LIKE '"+nom+"'");
        if(query.exec()){
            query.first();
            QString rfid = query.value(0).toString();
            qDebug() << rfid << "rfid value";
            return rfid;
        }
    } catch (std::exception &e) {
        qFatal("Error %s",
        e.what());
    }

}//bech ijib l id mel base w ycomarti biha mel base uid ijib fiha men houni
bool Event::updatenbr(QString pizza)
{
    try {
        QSqlQuery query;
        QSqlQuery query1;
        QSqlQuery query3;


        query1.prepare("SELECT NBR FROM GESTION_EVENT WHERE NOM_EVENT LIKE '"+pizza+"'");
        query1.bindValue(":name",pizza);
        query3.exec("SELECT  GESTION_SALLES.CAPACITY FROM GESTION_SALLES , GESTION_EVENT WHERE GESTION_SALLES.ID_SALLES = GESTION_EVENT.ID_SALLES AND GESTION_EVENT.NOM_EVENT='"+pizza+"'");

        if(!query1.exec() && !query3.exec()){
            qDebug() << query1.lastError() << "error query1" << query3.lastError() << "error query3";
            return false;
        }else {
            query1.first();
            query3.first();
            int nbrEvent = query1.value(0).toInt();
            int nbrCapacity = query3.value(0).toInt();
            if(nbrEvent >= nbrCapacity){
                return false;
            }
            qDebug() << nbrCapacity << "capacity query3"  << query3.first() << "query3.first" << query3.isActive() << "check query execution";
            qDebug() << nbrEvent << " int value";
            nbrEvent++;
            query.prepare("UPDATE gestion_event SET NBR=:nbr WHERE NOM_EVENT LIKE '"+pizza+"'");
            query.bindValue(":nbr",nbrEvent);

            return query.exec();
        }

    } catch (QSqlError) {
        return false;
    }

}



// NOTIFICATION/




