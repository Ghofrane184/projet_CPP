#ifndef EVENT_H
#define EVENT_H
#include <QString>
#include <QSqlQueryModel>

class Event
{
public:
    Event();
    Event(QString,QString,QString);
    //int getID_event(){return ID_event;}
    QString getDates();
    QString gettype();
    QString getnom_event();
   //void setID_event(int);
   void setDates(QString);
   void settype(QString);
   void setnom_event(QString);
   bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer(QString);
 bool modifier(QString, QString, QString);


 private:
 //int ID_event;
QString Dates;
 QString type,nom_event;


};

#endif // EVENT_H
