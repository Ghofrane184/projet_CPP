#ifndef CONX_H
#define CONX_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    Connection();
    bool createconnect();
};



#endif // CONX_H
