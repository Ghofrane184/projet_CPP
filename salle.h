#ifndef SALLE_S
#define SALLE_S

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class salle
{

private:

    QString nom,genre,date;
    int capacity;
      public:
            salle();
            salle(QString,int,QString,QString);



             QString getdate();
            QString getnom();
             QString getgenre();



            void setdate(QString date);
            void setnom(QString nom);
            void setgenre(QString genre);




            bool ajouter();
            QSqlQueryModel* afficher();

            bool modifier(int);
             bool recherche_id(int);
            QSqlQueryModel* recherche_nom(QString);
           QSqlQueryModel* recherche_date(QString);
           QSqlQueryModel* recherche_genre(QString);
           QSqlQueryModel* tri_nom();



             int statistique_genre(QString);
             int statistique_salle();

            void notifcation();
            bool supprimer(int);


};

#endif // SALLE_H
