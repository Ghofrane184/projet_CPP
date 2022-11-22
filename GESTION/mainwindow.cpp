#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personnels.h"
#include<QMessageBox>
#include<QIntValidator>
#include<QSqlQueryModel>
#include <QSqlQuery>
#include<QObject>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

        ui->le_id->setValidator(new QIntValidator(0, 9999999, this));
        ui->tableView_2->setModel(p.afficher());}


void MainWindow::on_pb_supprimer_clicked()
{
    int id = ui->le_id_2->text().toInt();
        bool test=p.supprimer(id);
        if (test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Suppression effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                     QObject::tr("Suppression non effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
ui->tableView_2->setModel(p.afficher());
}

void MainWindow::on_pb_modifier_clicked()
{
    int id=ui->le_id_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();

   int nbre_jour_conge=ui->le_nbre_jour_conge_2->text().toInt();
   int prime=(p.change_prime(nbre_jour_conge));
   personnels p ( id,nom,prenom,nbre_jour_conge,prime );
   bool test = p.modifier();
       if (test)
       {
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                    QObject::tr("mise à jour effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
       }
       else
           QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                    QObject::tr("mise à jour non effectué \n" "Click cancel to exit."),QMessageBox::Cancel);


ui->tableView_2->setModel(p.afficher());
}

void MainWindow::on_pb_ajouter_clicked()
{

    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int nbre_jour_conge= 0;
    int prime= 300;
    personnels p ( id,nom,prenom,nbre_jour_conge,prime );
    bool test = p.ajouter();
       if (test)
       {
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                    QObject::tr("Ajout effectué \n" "Click cancel to exit."),QMessageBox::Cancel);
       }
       else
           QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                    QObject::tr("Ajout non effectué \n" "Click cancel to exit."),QMessageBox::Cancel);

    ui->tableView_2->setModel(p.afficher());
}




void MainWindow::on_le_id_5_textChanged(const QString &arg1)
{
    ui->tableView_2->setModel(p.rechercherid(arg1));
}



void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QSqlQueryModel * model = new QSqlQueryModel();
        switch (index)
        {
        case 1:
            model->setQuery("Select * from personnels ORDER BY id ASC");
            ui->tableView_2->setModel(model);
            break;
        case 2:
            model->setQuery("Select * from personnels ORDER BY nom ASC");
            ui->tableView_2->setModel(model);
            break;
        case 3:
            model->setQuery("Select * from personnels ORDER BY prenom ASC");
            ui->tableView_2->setModel(model);
            break;


}}

void MainWindow::on_pb_pdf_clicked()
{
QPrinter printer;
    printer.setPrinterName("Personnels");

   QPrintDialog dialog(&printer,this);
    if (dialog.exec() == QDialog::Rejected) return;
    ui->textEdit->print(&printer);
}



void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    QString pdf;
    QString val=ui->tableView_2->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from personnels WHERE id=:val or nom=:val or prenom=:val or nbre_jour_conge=:val or prime=:val" );
    qry.bindValue(":val",val);
    if(qry.exec())
    {
        while (qry.next())
        {

           pdf =(qry.value(0).toString() + "\n" + qry.value(1).toString() + "\n" + qry.value(2).toString() + "\n" + qry.value(3).toString() + "\n" + qry.value(4).toString() + "\n" + qry.value(5).toString() );
        }
    }
    ui->textEdit->setText(pdf);


}

void MainWindow::on_pushButton_clicked()
{
    QSqlQuery q1,q2,q3,q4,q5,q6;
    qreal tot=0,c1=0,c2=0,c3=0,c4=0,c5=0;
    q1.prepare("Select * from personnels");
    if(q1.exec())
    {
        while (q1.next())
        {
            tot++;
        }
    }
    q2.prepare("Select * from personnels where prime ='100'");
    if(q2.exec())
    {
        while (q2.next())
        {
            c1++;
        }
    }
    q3.prepare("Select * from personnels where prime ='150'");
    if(q3.exec())
    {
        while (q3.next())
        {
            c2++;
        }
    }
    q4.prepare("Select * from personnels where prime ='200'");
    if(q4.exec())
    {
        while (q4.next())
        {
            c3++;
        }
    }
    q5.prepare("Select * from personnels where prime ='250'");
    if(q5.exec())
    {
        while (q5.next())
        {
            c4++;
        }
    }
    q6.prepare("Select * from personnels where prime ='300'");
    if(q6.exec())
    {
        while (q6.next())
        {
            c5++;
        }
    }
    c1=c1/tot;
    c2=c2/tot;
    c3=c3/tot;
    c4=c4/tot;
    c5=c5/tot;
    QPieSeries *series = new QPieSeries();
            series->append("100",c1);
            series->append("150",c2);
            series->append("200",c3);
            series->append("250",c4);
            series->append("300",c5);
            QPieSlice *slice0 = series->slices().at(0);
            slice0->setExploded();
            slice0->setLabelVisible();
            slice0->setPen(QPen(Qt::darkGray, 2));
            slice0->setBrush(Qt::gray);
            QPieSlice *slice1 = series->slices().at(1);
            slice1->setExploded();
            slice1->setLabelVisible();
            slice1->setPen(QPen(Qt::darkRed, 2));
            slice1->setBrush(Qt::red);
            QPieSlice *slice2 = series->slices().at(2);
            slice2->setExploded();
            slice2->setLabelVisible();
            slice2->setPen(QPen(Qt::darkYellow, 2));
            slice2->setBrush(Qt::yellow);
            QPieSlice *slice3 = series->slices().at(3);
            slice3->setExploded();
            slice3->setLabelVisible();
            slice3->setPen(QPen(Qt::darkGreen, 2));
            slice3->setBrush(Qt::green);
            QPieSlice *slice4 = series->slices().at(4);
            slice4->setExploded();
            slice4->setLabelVisible();
            slice4->setPen(QPen(Qt::blue, 2));
            slice4->setBrush(Qt::cyan);
            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle("LES PRIMES");
            chart->setAnimationOptions(QChart::AllAnimations);
            chart->legend()->hide();
            QChartView *chartView = new QChartView(chart,ui->statistique);
            chartView->setRenderHint(QPainter::Antialiasing);
            QGridLayout *layout = new QGridLayout();
            layout->addWidget(chartView);
            ui->statistique->setLayout(layout);
}

