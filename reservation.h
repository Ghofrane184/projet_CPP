#ifndef RESERVATION_H
#define RESERVATION_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtGui>
#include <QtSql>
#include <QtCore>
#include <QTableView>
#include "qcustomplot.h"
class reservation
{
public:
    reservation(){};
    reservation(int,QString,int,int,QString);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
    bool modifier(int ,QString,int,int,QString);
    //
                QSqlQueryModel * trie_type();


                bool rechidreservation(int);
                QSqlQueryModel* rechercheridreservation(QString);

                bool rechidclient(int);
                QSqlQueryModel* rechercheridclient(QString);

                bool rechidsalle(int);
                QSqlQueryModel* rechercheridsalle(QString);

                  void statistique(QVector<double>* ticks,QVector<QString> *labels);



private:
    int id_reservation;
    QString type_reservation;
    int id_salle;
    int id_client;
    QString date_reservation;

};

#endif // RESERVATION_H
