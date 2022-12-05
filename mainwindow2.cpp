#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "mainwindow.h"
#include "mainwindow3.h"
#include "mainwindow4.h"
#include "gestion_salle.h"
#include "gestionreservation.h"
mainwindow2::mainwindow2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindow2)
{
    ui->setupUi(this);
}

mainwindow2::~mainwindow2()
{
    delete ui;
}


void mainwindow2::on_pushButton_clicked()
{

    m=new MainWindow(this);
            m->show();



}

void mainwindow2::on_pushButton_2_clicked()
{

        n=new MainWindow3(this);
                n->show();

}

void mainwindow2::on_pushButton_3_clicked()
{
    l=new MainWindow4(this);
            l->show();

}

void mainwindow2::on_pushButton_6_clicked()
{
    z=new gestion_salle(this);
            z->show();
}

void mainwindow2::on_pushButton_5_clicked()
{
    s=new GestionReservation(this);
            s->show();
}
