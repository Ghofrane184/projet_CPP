#include "gestionreservation.h"
#include "ui_gestionreservation.h"
#include "reservation.h"

#include <QMessageBox>

GestionReservation::GestionReservation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GestionReservation)
{
    ui->setupUi(this);
    ui->tableView->setModel(re.afficher());

    // read_from_arduino();


      int ret=A2.connect_arduino(); // lancer la connexion à arduino
           switch(ret){
           case(0):qDebug()<< "arduino is available and connected to : "<< A2.getarduino_port_name();
               break;
           case(1):qDebug() << "arduino is available but not connected to :" <<A2.getarduino_port_name();
              break;
           case(-1):qDebug() << "arduino is not available";
           }
            QObject::connect(A2.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

}

GestionReservation::~GestionReservation()
{
    delete ui;
}

void GestionReservation::update_label()
{
    data=A2.read_from_arduino();


    if (data=="1")
        ui->labela->setText("Carte Detected");
    else if (data=="0")
        ui->labela->setText("Access denied");

}
void GestionReservation::on_pushButton_clicked()
{
    int id_reservation=ui->ID_reservation_2->text().toInt();reservation R1;
        bool test=R1.supprimer(id_reservation);

        if (test)
        {
            ui->tableView->setModel(R1.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression effectué \n"
                                                 "Click Cancel to exist ."),QMessageBox::Cancel);

        }
        else
              QMessageBox::critical(nullptr, QObject::tr("no"),
                          QObject::tr("Suppression failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}

void GestionReservation::on_pb_ajouter_reservation_clicked()
{
    int id_reservation=ui->ID_reservation->text().toInt();
    QString type_reservation=ui->Type_reservation->text();
    int id_salle=ui->comboBox->currentText().toInt();
    int id_client=ui->comboBox_2->currentText().toInt();
    QString date_reservation=ui->Date_reservation->text();
   reservation R(id_reservation,type_reservation,id_salle,id_client,date_reservation);
   QSqlQuery query;
   bool test=R.ajouter();//inserer reservation  dans la table
       if (test)
       {
           ui->tableView->setModel(R.afficher());
           QMessageBox::information(nullptr,QObject::tr("ok"),
                                    QObject::tr("ajout effectué \n"
                                                "Click Cancel to exist ."),QMessageBox::Cancel);

       }
       else
             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("connection failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}




void GestionReservation::on_pushButton_2_clicked()
{
    int id_reservation=ui->ID_reservation->text().toInt();
    QString type_reservation=ui->Type_reservation->text();
    int id_salle=ui->comboBox->currentText().toInt();
    int id_client=ui->comboBox_2->currentText().toInt();
    QString date_reservation=ui->Date_reservation->text();
   reservation R(id_reservation,type_reservation,id_salle,id_client,date_reservation);
   QSqlQuery query;
   bool test=R.modifier(id_reservation,type_reservation,id_salle,id_client,date_reservation);
       if (test)
       {
           ui->tableView->setModel(R.afficher());
           QMessageBox::information(nullptr,QObject::tr("ok"),
                                    QObject::tr("modification effectué \n"
                                                "Click Cancel to exist ."),QMessageBox::Cancel);

       }
       else
             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("modification failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

}

void GestionReservation::on_pushButton_3_clicked()
{ 

        reservation R;

        QString choix=ui->comboBox_chercher->currentText();

               if (choix=="ID_RESERVATION")
               {
                   QString ID_RESERVATION = ui->lineEdit_rech->text();
                   ui->tableView_3->setModel(R.rechercheridreservation(ID_RESERVATION));
               }
               if (choix=="ID_CLIENT")
               {
                   QString ID_CLIENT = ui->lineEdit_rech->text();
                   ui->tableView_3->setModel(R.rechercheridclient(ID_CLIENT));
               }
               if (choix=="ID_SALLE")
               {
                   QString ID_SALLE = ui->lineEdit_rech->text();
                   ui->tableView_3->setModel(R.rechercheridsalle(ID_SALLE));
               }

}

void GestionReservation::on_pushButton_4_clicked()
{
    reservation R;
             QString choix=ui->comboBox_tri->currentText();
             if (choix=="TYPE_RESERVATION")
             {
                 ui->tableView_3->setModel(R.trie_type());
                 ui->tableView_3->setModel(R.afficher());
                 bool test=R.trie_type();//tri type
                 if (test)
                 {

             ui->tableView_3->setModel(R.trie_type());
                     QMessageBox::information(nullptr,QObject::tr("ok"),
                                              QObject::tr("tri type effectué \n"
                                                          "Click Cancel to exist ."),QMessageBox::Cancel);

                 }
                 else
                       QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                                   QObject::tr("tri type failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
             }
}

void GestionReservation::on_tabWidget_currentChanged(int index)
{
    // background //
                  QLinearGradient gradient(0, 0, 0, 400);
                  gradient.setColorAt(0, QColor(90, 90, 90));
                  gradient.setColorAt(0.38, QColor(105, 105, 105));
                  gradient.setColorAt(1, QColor(70, 70, 70));
                  ui->plot->setBackground(QBrush(gradient));

                  QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
                  amande->setAntialiased(false);
                  amande->setStackingGap(1);
                   //couleurs
                  amande->setName("Repartition des GESTION_RESERVATION selon TYPE_RESERVATION ");
                  amande->setPen(QPen(QColor(111, 9, 176).lighter(170)));
                  amande->setBrush(QColor(111, 9, 176));

                   //axe des abscisses
                  QVector<double> ticks;
                  QVector<QString> labels;
                  re.statistique(&ticks,&labels);

                  QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
                  textTicker->addTicks(ticks, labels);
                  ui->plot->xAxis->setTicker(textTicker);
                  ui->plot->xAxis->setTickLabelRotation(60);
                  ui->plot->xAxis->setSubTicks(false);
                  ui->plot->xAxis->setTickLength(0, 4);
                  ui->plot->xAxis->setRange(0, 8);
                  ui->plot->xAxis->setBasePen(QPen(Qt::white));
                  ui->plot->xAxis->setTickPen(QPen(Qt::white));
                  ui->plot->xAxis->grid()->setVisible(true);
                  ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
                  ui->plot->xAxis->setTickLabelColor(Qt::white);
                  ui->plot->xAxis->setLabelColor(Qt::white);

                  // axe des ordonnées
                  ui->plot->yAxis->setRange(0,10);
                  ui->plot->yAxis->setPadding(5);
                  ui->plot->yAxis->setLabel("Statistiques");
                  ui->plot->yAxis->setBasePen(QPen(Qt::white));
                  ui->plot->yAxis->setTickPen(QPen(Qt::white));
                  ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
                  ui->plot->yAxis->grid()->setSubGridVisible(true);
                  ui->plot->yAxis->setTickLabelColor(Qt::white);
                  ui->plot->yAxis->setLabelColor(Qt::white);
                  ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
                  ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

                  // ajout des données  (statistiques de reservation)//

                  QVector<double> PlaceData;
                  QSqlQuery q1("SELECT COUNT(TYPE_RESERVATION) FROM GESTION_RESERVATION GROUP BY TYPE_RESERVATION");
                  while (q1.next()) {
                                int  nbr_fautee = q1.value(0).toInt();
                                PlaceData<< nbr_fautee;
                                  }
                  amande->setData(ticks, PlaceData);

                  ui->plot->legend->setVisible(true);
                  ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
                  ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
                  ui->plot->legend->setBorderPen(Qt::NoPen);
                  QFont legendFont = font();
                  legendFont.setPointSize(5);
                  ui->plot->legend->setFont(legendFont);
                  ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void GestionReservation::on_pushButton_combo_clicked()
{
    QSqlQuery query2("SELECT ID_SALLE FROM SALLE");
            while (query2.next())
                {
                  QString nsch=query2.value(0).toString();
                  ui->comboBox->addItem(nsch);
                  ui->comboBox->setEditText(nsch);
                }
}

void GestionReservation::on_pushButton_combo_2_clicked()
{
    QSqlQuery query2("SELECT CIN FROM CLIENT");
            while (query2.next())
                {
                  QString nsch=query2.value(0).toString();
                  ui->comboBox_2->addItem(nsch);
                  ui->comboBox_2->setEditText(nsch);
                }
}


void GestionReservation::on_pushButton_pdf_clicked()
{
    QPrinter print;
    print.setPrinterName("ID_RESERVATION");
    QPrintDialog dialog(&print,this);
    if (dialog.exec() == QDialog::Rejected) return;
    ui->text_pdf->print(&print);
}

