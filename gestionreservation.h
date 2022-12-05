#ifndef GESTIONRESERVATION_H
#define GESTIONRESERVATION_H

#include <QMainWindow>
#include"reservation.h"
#include "arduino2.h"
namespace Ui {
class GestionReservation;
}

class GestionReservation : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionReservation(QWidget *parent = nullptr);
    ~GestionReservation();

private slots:
    void on_pushButton_clicked();

    void on_pb_ajouter_reservation_clicked();

    //void on_ID_reservation_cursorPositionChanged(int arg1, int arg2);

    //void on_ID_salle_cursorPositionChanged(int arg1, int arg2);

    //void on_Type_reservation_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_tabWidget_currentChanged(int);

    void on_pushButton_combo_clicked();

    void on_pushButton_combo_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_pdf_clicked();
    void update_label();

    void on_labela_linkActivated(const QString &link);

private:
    Ui::GestionReservation *ui;
    reservation re;
    QByteArray data;
        Arduino2 A2;
};

#endif //GESTIONRESERVATION_H
