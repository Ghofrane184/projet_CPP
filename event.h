#ifndef EVENT_H
#define EVENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlQuery>
#include <QLabel>

class Event
{
public:
    Event();
    Event(QString,QString,QString,QString,int);
    QString getID_event();
    QString getDates();
    QString gettype();
    QString getnom_event();
     int getcin();
   void setID_event(QString);
   void setDates(QString);
   void settype(QString);
   void setnom_event(QString);
   void setcin(int);
   bool ajouter();
   void setParticipantNumber(int);
   int getParticipantNumber();
   QSqlQueryModel* afficher();
   bool supprimer(QString);
   std::map<QString,int> statNbrPerType();
   QString getUID(QString);

 bool modifier(QString, QString, QString);
 bool reportor (QString,QString,QString);
  void rechercher(QString a,QTableView *g);
    QSqlQueryModel * afficher_tri_nom();
     QSqlQueryModel * afficher_tri_nom_DESC();
        QSqlQueryModel * afficher_tri_nom_ASC();
         bool annulation(QString);
         QSqlQueryModel* load();
          bool updatenbr(QString);
       bool retirer(int);


  //NOTIFICATION
      /*   Q_OBJECT

             Q_PROPERTY(float popupOpacity READ getPopupOpacity WRITE setPopupOpacity)



   //void statistique(QVector<double>* ticks,QVector<QString> *labels);*/
 private:
 QString ID_event;
QString Dates;
 QString type,nom_event;
 int participantNumber;
 int cin;



};

#endif // EVENT_H
