#include "connection.h"
#include<QDebug>
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet");
db.setUserName("personnels");//inserer nom de l'utilisateur
db.setPassword("personnels");//inserer mot de passe de cet utilisateur


if (db.open())
test=true;





    return  test;
}
