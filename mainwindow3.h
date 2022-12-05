#ifndef MAINWINDOW3_H
#define MAINWINDOW3_H

#include <QMainWindow>
#include "client.h"
#include "smtp.h"
#include "arduino1.h"


namespace Ui {
class MainWindow3;
}

class MainWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow3(QWidget *parent = nullptr);
    ~MainWindow3();
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
    Ui::MainWindow3 *ui;
    Client C;
      QStringList files;
        QTcpSocket *socket;
        QByteArray data; // variable contenant les données reçues

        Arduino1 A; // objet temporaire


};

#endif // MAINWINDOW3_H
