#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "personnels.h"
#include<QPrinter>
#include<QPrintDialog>
#include <QApplication>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(){}

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

   /* void on_le_id_textEdited(const QString &arg1);

    void on_pb_rechercher_clicked();

    void on_le_id_5_textChanged(const QString &arg1);*/

    void on_le_id_5_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_pb_pdf_clicked();

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    personnels p;
};






#endif // MAINWINDOW_H
