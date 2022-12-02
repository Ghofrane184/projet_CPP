#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "smtp.h"
#include "arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_B_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_modif_clicked();



    void on_B_tri_clicked();



    void on_B_rech_clicked();

    void on_B_pdf_clicked();
    void sendMail();
    void mailSent(QString );




    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pb_stat_clicked();

private:
    Ui::MainWindow *ui;
   Client C;
     QStringList files;
       QTcpSocket *socket;
       QByteArray data; // variable contenant les données reçues

       Arduino A; // objet temporaire


};
#endif // MAINWINDOW_H
