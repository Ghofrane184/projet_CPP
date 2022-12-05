#include "personnels.h"

#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include<QString>
personnels::personnels()
{
    id=0;
    nom=" ";
    prenom="";
    nbre_jour_conge=0;
    prime=300;
};
personnels::personnels  (int id,QString nom  ,QString prenom  ,int nbre_jour_conge, int prime)
{
    this->id=id;
    this->nom=nom;
    this->prenom= prenom;

    this->nbre_jour_conge=nbre_jour_conge;
    this->prime=prime;

};
int personnels::getid(){return id;}
QString personnels::getnom(){return nom;}
QString personnels::getprenom(){return prenom;}

int personnels::getnbre_jour_conge(){return nbre_jour_conge;}
int personnels::getprime(){return prime;}


void personnels::setid(int id){this->id=id;}
void personnels::setnom(QString nom){this->nom=nom;}
void personnels::setprenom(QString prenom){this->prenom=prenom;}

void personnels::setnbre_jour_conge(int nbre_jour_conge){this->nbre_jour_conge = nbre_jour_conge;}
void personnels::setprime(int prime){this->prime=prime;}

bool personnels::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
    QString nbre_jour_conge_string= QString::number(nbre_jour_conge);
    QString prime_string= QString::number(prime);
             query.prepare("INSERT INTO personnels (id,nom,prenom,nbre_jour_conge,prime)"
                           "VALUES (:id,:nom,:prenom,:nbre_jour_conge,:prime)");
             query.bindValue(":id",id_string);
             query.bindValue(":nom",nom);
             query.bindValue(":prenom",prenom);
             query.bindValue(":nbre_jour_conge",nbre_jour_conge_string);
             query.bindValue(":prime",prime_string);
        return query.exec();
}
QSqlQueryModel* personnels:: afficher()
{
        QSqlQueryModel* model=new QSqlQueryModel();
             model->setQuery("SELECT * from personnels" );
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("id"));
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("nbre_jour_conge"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("prime "));
     return model;

   }
bool personnels::supprimer(int id)
{
    QSqlQuery query;
        QString res = QString::number(id);
        query.prepare("Delete from personnels where ID = :id");
        query.bindValue(":id",res);
        return  query.exec();



}
 bool personnels::modifier()
 {
     QSqlQuery query;
       QString id_string= QString::number(id);
           QString nbre_jour_conge_string= QString::number(nbre_jour_conge);
               QString prime_string= QString::number(prime);
 query.prepare("UPDATE personnels SET id= :id, nom= :nom, prenom=:prenom, nbre_jour_conge=:nbre_jour_conge, prime=:prime  "
                                       " WHERE  ID = '"+id_string+"' ");
              query.bindValue(":id",id_string);
              query.bindValue(":nom",nom);
              query.bindValue(":prenom",prenom);
              query.bindValue(":nbre_jour_conge",nbre_jour_conge_string);
              query.bindValue(":prime",prime_string);

         return query.exec();

 }
  QSqlQueryModel* personnels::rechercherid(QString r)
  {

      QSqlQueryModel * model = new QSqlQueryModel();
          model->setQuery("Select * from personnels where id like '%"+r+"%'  ");
          return model;
  }
  int personnels::change_prime(int x)
  {
    int p;
    if (x>1 && x<=7)
    {
        p=250;
    }
    else if (x>7 && x<=14)
    {
        p=200;
    }
    else if (x>14 && x<=21)
    {
        p=150;
    }
    else if (x>21 && x<=28)
    {
        p=100;
    }
    else if (x>28)
    {
        p=0;
    }
    else
    {
        p=300;
    }
    return  p;
  }



