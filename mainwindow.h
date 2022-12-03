#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "event.h"
#include "popup.h"
 #include "arduino.h";
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
    void on_PB_ajout_clicked();

    void on_pb_supp_clicked();

    void on_PB_modif_clicked();

    void on_PB_recherche_clicked();

    void on_PB_pdf_clicked();


    void on_l_triasc_clicked();

    void on_l_tri_clicked();

    void on_l_tridesc_clicked();

    void on_pb_annul_clicked();


    void on_PB_loadevent_clicked();

    void on_PB_inscri_clicked();

    void on_PB_report_clicked();

    void on_PB_stat__nbr_t_clicked();
    void update_label();

private:
    Ui::MainWindow *ui;
    Event E;
    PopUp *popUp;
    Arduino A;
};
#endif // MAINWINDOW_H
