#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
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

    void on_toolButton_6_clicked();

    void on_B_tri_clicked();

    void on_toolButton_5_clicked();

    void on_B_rech_clicked();

private:
    Ui::MainWindow *ui;
   Client C;
};
#endif // MAINWINDOW_H
