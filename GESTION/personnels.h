
#ifndef PERSONNELS_H
#define PERSONNELS_H
#include <QSqlQueryModel>
#include <QSqlQuery>
#include<QString>


class personnels
{

private:
    int id,prime,nbre_jour_conge;
    QString nom , prenom ;
public:




    personnels();



   personnels(int ,QString ,QString ,int ,int );
int getid();
         QString getnom();
          QString getprenom();


               int getnbre_jour_conge();
               int getprime();

        //getters

        void setid(int);
        void setnom(QString);

       void setprenom(QString);

       void setnbre_jour_conge(int);
        void setprime(int);

        //setters



        bool ajouter();
        QSqlQueryModel* afficher();
        bool supprimer (int);
        bool modifier();
        QSqlQueryModel*rechercherid(QString);
        int change_prime (int);



       //fonction
};


#endif//PERSONNELS_H
