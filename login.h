#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "salle.h"
#include "gestion_salle.h"
#include "authentification.h"
#include "mainwindow2.h"
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();


private slots:
    void on_pushButton_quiter1_clicked();

    void on_pushButton_connecter_clicked();

    void on_pushButton_inscrire_clicked();

    void on_pushButton_mdpoublie_clicked();




private:
    Ui::login *ui;
  Ui::mainwindow2 *uii;
   mainwindow2 *ww;
    authentification A;
    salle S;
    gestion_salle *G;


};

#endif // LOGIN_H
