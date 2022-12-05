#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QSqlError>
#include<QObject>
#include<QMessageBox>
#include<map>

Client::Client()
{
cin=0; nom=""; prenom="";
}

Client::Client(int cin,QString nom,QString prenom )
{this->cin=cin; this->nom=nom; this->prenom=prenom;}

int Client:: getcin(){return cin;}
QString Client:: getnom(){return nom;}
QString Client::getprenom(){return prenom;}
void Client::setcin(int cin){this->cin=cin;}
void Client::setnom(QString nom){this->nom=nom;}
void Client::setprenom(QString prenom){this->prenom=prenom;}

bool Client::ajouter()
{
   QSqlQuery query;

      QString cin_string=QString::number(cin);

    query.prepare("INSERT INTO CLIENT(nom, prenom,cin)"
                  "VALUES (:nom, :prenom,:cin)");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":cin",cin);

    qDebug()<<query.lastError();


    return query.exec();
}




bool Client::supprimer(int CIN)
{

    QSqlQuery query;


         query.prepare("Delete from CLIENT where CIN=:cin" ) ;
         query.bindValue(":cin", CIN);
         qDebug()<<query.lastError();
      return query.exec();



}



 QSqlQueryModel* Client::afficher()
 {
    QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM client");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));



    return model;
 }

    bool Client::Modifier(int cin,QString nom,QString prenom)
    {
        QSqlQuery query;

        QString cin_string =QString::number(cin);
        query.prepare("UPDATE Client SET  nom=:nom ,prenom=:prenom WHERE cin=:cin");

        query.bindValue(":cin", cin_string);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);

         return  query.exec();

 }


    QSqlQueryModel *Client::trierClient()
        {
            QSqlQueryModel * model=new QSqlQueryModel();
              QString cin1=QString::number(cin);
            model->setQuery("select * from client order by cin" );

            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));

            model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));

            model->setHeaderData(3,Qt::Horizontal,QObject::tr("cin"));
              return model;

    }

    void Client::rechercher(QString a,QTableView *g)
    {
        {
            QSqlQuery qry;
             QSqlQueryModel *m=new QSqlQueryModel();//initialisation
             qry.prepare("select * from Client where NOM like '%"+a+"%' OR PRENOM like '%"+a+"%' OR CIN like '%"+a+"%'");
                         qry.exec();
                     m->setQuery(qry);
             g->setModel(m);


         }
    }



    int Client::nbrevent(QString cin)
    {
    QSqlQuery qry;
    int nbr=0;
    bool test;

    qry.prepare("select COUNT(*) from CLIENT,GESTION_EVENT where CLIENT.CIN=GESTION_EVENT.CIN AND CLIENT.CIN=:CIN");

    qry.bindValue(":CIN",cin);
    qry.exec();

    while(qry.next())

    {

        nbr=qry.value("COUNT(*)").toInt();

    }

    qry.prepare("UPDATE CLIENT SET POINTSF=:nbr WHERE CIN=:cin");
    qry.bindValue(":nbr",nbr);
    qry.bindValue(":cin",cin);
    test=qry.exec();

    if (test)
    {
    QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("points ajouter avec success.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    }

    else

    {

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("ajout de points failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

    return nbr;

        }


        bool Client::remise(QString cin){
            QSqlQuery qry;
            int nbr=0;

            qry.prepare("select POINTSF from CLIENT WHERE CIN=:cin");

            qry.bindValue(":cin",cin);
            qry.exec();

            while(qry.next()){

                nbr=qry.value("POINTSF").toInt();

            }

               nbr=nbr*10;

            qry.prepare("UPDATE CLIENT SET PROMO=:nbr WHERE CIN=:cin");
            qry.bindValue(":nbr",nbr);
            qry.bindValue(":cin",cin);


    return qry.exec();


        }


        std::map<QString,int> Client::statNbrPerType()
        {
            QSqlQuery query;
            std::map <QString,int> list;
            try {
                query.prepare("SELECT SUM(POINTSF) ,CIN from CLIENT GROUP BY CIN");
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



