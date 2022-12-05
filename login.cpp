#include "login.h"
#include "ui_login.h"
#include "salle.h"
#include "gestion_salle.h"
#include <QMessageBox>
#include <iostream>
#include <QMessageBox>
#include  <QDebug>
#include "authentification.h"
#include "mainwindow2.h"


login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
  setWindowTitle("~~~~");
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_quiter1_clicked()
{
   close();
}

void login::on_pushButton_connecter_clicked()
{
    authentification A2;
    A2.setid(ui->lineEdit_loginid->text().toInt());
    A2.setmdp(ui->lineEdit_loginmdp->text());
    if(A2.recherche_id_mdp(A2.getid(),A2.getmdp())){
   ww= new mainwindow2(this);
  ww->show();
}
}

void login::on_pushButton_inscrire_clicked()
{
    ww = new mainwindow2();
    ww->show();
}

void login::on_pushButton_mdpoublie_clicked()
{
    authentification A2;
    A2.setid(ui->lineEdit_loginid->text().toInt());
    if(A2.recherche_id(A2.getid())){
    ww = new mainwindow2();
    ww->show();
    }
}





