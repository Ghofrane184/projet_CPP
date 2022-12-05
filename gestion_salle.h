#ifndef GESTION_SALLE_H
#define GESTION_SALLE_H
#include <QWidget>
#include "salle.h"
#include "authentification.h"
#include <QMainWindow>

namespace Ui {
class gestion_salle;
}

class gestion_salle : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion_salle(QWidget *parent = nullptr);
    ~gestion_salle();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_ajoutprofil_clicked();
    void on_trinomprofil_clicked();
    void on_triidprofil_clicked();
    void on_pushButton_modifierprofil_clicked();
    void on_pushButton_imprimerprofil_clicked();
    void on_pushButton_pdfprofil_clicked();
    void on_pushButton_rechprofil_clicked();
    void on_rechercherid_clicked();
    void on_pushButton_spradmin_clicked();





private:
    Ui::gestion_salle *ui;
    authentification A;
     salle S;
};

#endif // GESTION_SALLE_H
