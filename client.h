#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQueryModel>
#include<QTableView>
class Client
{
public:
    Client();
    Client(int,QString,QString);
    int getcin();
    QString getnom();
    QString getprenom();
    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
QSqlQueryModel* trierClient();
    bool supprimer(int);
    bool Modifier(int ,QString ,QString );
    void rechercher(QString a,QTableView *g);
    std::map<QString,int> statNbrPerType();

    int nbrevent(QString);
        bool remise(QString);
private:
    int cin;
    QString nom,prenom;
};

#endif // CLIENT_H
