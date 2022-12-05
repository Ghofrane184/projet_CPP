#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H
#include "mainwindow.h"
#include "mainwindow3.h"
#include "mainwindow4.h"
#include "gestion_salle.h"
#include "gestionreservation.h"
#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui {
class mainwindow2;
}
QT_END_NAMESPACE

class mainwindow2 : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindow2(QWidget *parent = nullptr);
    ~mainwindow2();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::mainwindow2 *ui;
    Ui::MainWindow *uii;
    MainWindow *m;
    Ui::MainWindow3 *uui;
    MainWindow3 *n;
    Ui::MainWindow4 *uuii;
    MainWindow4 *l;
   //Ui::login *uuui;
  //  login *a;
    Ui::gestion_salle *uuuii;
    gestion_salle *z;
    Ui::GestionReservation *uuuuii;
    GestionReservation *s;


};

#endif // MAINWINDOW2_H
