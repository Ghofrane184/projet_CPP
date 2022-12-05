#include "gestion_salle.h"
#include "ui_gestion_salle.h"
#include "salle.h"
#include "QWidget"
#include <QMessageBox>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QSqlQuery>
#include <QTabWidget>
#include <QTableWidget>
#include<QDebug>
#include <QPrintDialog>
#include<QFileDialog>
#include<QPdfWriter>
#include<QPrinter>
#include<QFile>
#include <QAbstractSocket>
#include <QSslSocket>
#include<QStringList>
#include <iostream>
#include<QTextDocument>
#include <QValidator>
#include <QIntValidator>
#include <QString>


gestion_salle::gestion_salle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_salle)
{
    ui->setupUi(this);
    QRegularExpression rnumber("\\b([0-9][0-9][-][0-9][0-9][-][0-9][0-9][0-9][0-9])\\b",QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionValidator *valnumber = new QRegularExpressionValidator(rnumber,this);
     ui->date->setValidator(valnumber);

     QRegularExpression r1number("\\b[0-9]*\\b",QRegularExpression::CaseInsensitiveOption);
     QRegularExpressionValidator *val = new QRegularExpressionValidator(r1number,this);
      ui->capacity->setValidator(val);

      QRegularExpression r2number("\\b([a-zA-Z])([a-zA-Z0-9])*\\b",QRegularExpression::CaseInsensitiveOption);
      QRegularExpressionValidator *val1 = new QRegularExpressionValidator(r2number,this);
       ui->nom->setValidator(val1);
        ui->genre->setValidator(val1);


         ui->mod_date->setValidator(valnumber);
         ui->mod_cap->setValidator(val);
         ui->mod_nom->setValidator(val1);
         ui->mod_genre->setValidator(val1);
    ui->salleview->setModel(S.afficher());

    // stat salle



           ui->vip->setValue(0);
           ui->normal->setValue(0);

           int SA=0,SO=0;
            int a =S.statistique_genre("normal");
           int o=S.statistique_genre("vip");

            int t=S.statistique_salle();
            SA=(a*100)/t;
            SO=(o*100)/t;



        ui->vip->setValue(SO);
         ui->normal->setValue(SA);

}

gestion_salle::~gestion_salle()
{
    delete ui;
}

void gestion_salle::on_pushButton_clicked()
{

    QString nom=ui->nom->text();
    int capacity=ui->capacity->text().toInt();
    QString genre=ui->genre->text();
      QString date=ui->date->text();

    salle S(nom,capacity, genre, date);
    bool test=S.ajouter();


    QMessageBox msgBox;
    if(test)
  {
        QMessageBox::information(nullptr, QObject::tr("Salle added"),
                    QObject::tr("Add successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->salleview->setModel(S.afficher());


    }

    else{
        msgBox.setText("Echec d'ajout");
    msgBox.exec();}
}

void gestion_salle::on_pushButton_4_clicked()
{
    int id=ui->supp_salle->text().toInt();
    bool test=S.supprimer(id);
    if(test){
        QMessageBox::information(nullptr, QObject::tr("Salle Deleted"),
                    QObject::tr("Delete successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->salleview->setModel(S.afficher());
    }
    else{
         QMessageBox msgBox;
        msgBox.setText("Echec de supprimer");
    msgBox.exec();}
}

void gestion_salle::on_pushButton_3_clicked()
{
    salle s;
        QSqlQuery query;
        int id=ui->supp_salle->text().toInt();
        QString id_string=QString::number(id);
       if(s.recherche_id(id))
       {
           query.prepare("SELECT * FROM SALLE WHERE ID_SALLE = :id");
           query.bindValue(":id",id_string);
           query.exec();
           while(query.next())
       {
           ui->mod_nom->setText(query.value(1).toString());
           ui->mod_cap->setText(query.value(2).toString());
           ui->mod_genre->setText(query.value(3).toString());
           ui->mod_date->setText(query.value(4).toString());


        }
       }
}

void gestion_salle::on_pushButton_2_clicked()
{
    //salle s;
        QMessageBox msg;
        int id=ui->supp_salle->text().toInt();
        QString nom=ui->mod_nom->text();
        int cap=ui->mod_cap->text().toInt();
        QString genre=ui->mod_genre->text();
        QString date=ui->mod_date->text();

        salle *s = new salle(nom,cap,genre,date);

        bool test=s->modifier(id);



        if(test)
        {
            msg.setText("modification avec succès");
             ui->salleview->setModel(S.afficher());

        }
        else
            msg.setText("echec de modification");

        msg.exec();
}

void gestion_salle::on_pushButton_7_clicked()
{
    QSqlQuery *b = new QSqlQuery();

          QSqlQueryModel *model = new QSqlQueryModel();

          b->prepare("SELECT * FROM SALLE ORDER BY NOM_SALLE");

          b->exec();

          model->setQuery(*b);

       ui->salleview->setModel(model);
}

void gestion_salle::on_pushButton_9_clicked()
{

    QSqlQuery *b = new QSqlQuery();

          QSqlQueryModel *model = new QSqlQueryModel();

          b->prepare("SELECT * FROM SALLE ORDER BY GENRE");

          b->exec();

          model->setQuery(*b);

       ui->salleview->setModel(model);

}

void gestion_salle::on_pushButton_8_clicked()
{
    QSqlQuery *b = new QSqlQuery();

          QSqlQueryModel *model = new QSqlQueryModel();

          b->prepare("SELECT * FROM SALLE ORDER BY capacity");

          b->exec();

          model->setQuery(*b);

       ui->salleview->setModel(model);
}

void gestion_salle::on_pushButton_6_clicked()
{
    QString NOM=ui->chercher->text();

             QSqlQueryModel * model= new QSqlQueryModel();

             model->setQuery("select * FROM SALLE where NOM_SALLE='"+NOM+"'");
             model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
             model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
             model->setHeaderData(2,Qt::Horizontal,QObject::tr("Capacity"));
             model->setHeaderData(3,Qt::Horizontal,QObject::tr("Genre"));
             model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));


             ui->salleview->setModel(model);
}

void gestion_salle::on_pushButton_10_clicked()
{
    QString g=ui->chercher->text();

             QSqlQueryModel * model= new QSqlQueryModel();

             model->setQuery("select * FROM SALLE where GENRE='"+g+"'");
             model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
             model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
             model->setHeaderData(2,Qt::Horizontal,QObject::tr("Capacity"));
             model->setHeaderData(3,Qt::Horizontal,QObject::tr("Genre"));
             model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));


             ui->salleview->setModel(model);
}

void gestion_salle::on_pushButton_11_clicked()
{
    QString d=ui->chercher->text();

             QSqlQueryModel * model= new QSqlQueryModel();

             model->setQuery("select * FROM SALLE where DATE_SALLE='"+d+"'");
             model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
             model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
             model->setHeaderData(2,Qt::Horizontal,QObject::tr("Capacity"));
             model->setHeaderData(3,Qt::Horizontal,QObject::tr("Genre"));
             model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date"));


             ui->salleview->setModel(model);
}

void gestion_salle::on_pushButton_5_clicked()
{
    QSqlDatabase db;
                           QTableView tabe;
                           QSqlQueryModel * Modal=new  QSqlQueryModel();

                           QSqlQuery qry;
                            qry.prepare("SELECT * FROM SALLE ");
                            qry.exec();
                            Modal->setQuery(qry);
                            tabe.setModel(Modal);

                            db.close();

                            QString strStream;
                            QTextStream out(&strStream);

                            const int rowCount = tabe.model()->rowCount();
                            const int columnCount =  tabe.model()->columnCount();

                            const QString strTitle ="Document";


                            out <<  "<html>\n"
                                    "<img src='C:/Users/Adem/Desktop/Salle/Salle/download.png' height='120' width='120'/>"
                                "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                <<  QString("<title>%1</title>\n").arg(strTitle)
                                <<  "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"
                               << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des salles")
                               <<"<br>"

                               <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                            out << "<thead><tr bgcolor=#f0f0f0>";
                            for (int column = 0; column < columnCount; column++)
                                if (!tabe.isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(tabe.model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";

                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!tabe.isColumnHidden(column)) {
                                        QString data = tabe.model()->data(tabe.model()->index(row, column)).toString().simplified();
                                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                    }
                                }
                                out << "</tr>\n";
                            }
                            out <<  "</table>\n"
                                    "<br><br>"
                                    <<"<br>"
                                    <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                                out << "<thead><tr bgcolor=#f0f0f0>";

                                    out <<  "</table>\n"

                                "</body>\n"
                                "</html>\n";


                            QTextDocument *document = new QTextDocument();
                            document->setHtml(strStream);

                            QPrinter printer;
                            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                            if (dialog->exec() == QDialog::Accepted) {

                                document->print(&printer);
                            }

                            printer.setOutputFormat(QPrinter::PdfFormat);
                            printer.setPaperSize(QPrinter::A4);
                            printer.setOutputFileName("/tmp/salle.pdf");
                            printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                            delete document;
}

void gestion_salle::on_pushButton_12_clicked()
{
      ui->salleview->setModel(S.afficher());

      //stat
      ui->vip->setValue(0);
      ui->normal->setValue(0);

      int SA=0,SO=0;
       int a =S.statistique_genre("normal");
      int o=S.statistique_genre("vip");

       int t=S.statistique_salle();
       SA=(a*100)/t;
       SO=(o*100)/t;



   ui->vip->setValue(SO);
    ui->normal->setValue(SA);
}



void gestion_salle::on_pushButton_ajoutprofil_clicked()
{
    QMessageBox msgBox;
    int id=ui->lineEdit_id->text().toInt();
    QString nomutilisateur=ui->lineEditnometprenom->text();
    QString mdp=ui->lineEdit_mdp->text();
    authentification A(id,nomutilisateur,mdp);
    bool test=A.ajouter();
    if (test){
        ui->tableView_profil->setModel(A.afficher());
            msgBox.setText("Profil ajoute");
            msgBox.exec();
           }
        else
        {
            msgBox.setText("ID existe deja");
            msgBox.exec();

    }
}

void gestion_salle::on_pushButton_spradmin_clicked()
{
    authentification A1;A1.setid(ui->lineEdit_scin_admin->text().toInt());
    bool test=A1.supprimer(A1.getid());
    if (test){
        authentification A;
        ui->tableView_profil->setModel(A.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un admin"),
                    QObject::tr("admin supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
}
void gestion_salle::on_pushButton_modifierprofil_clicked()
{
    authentification A;
    QMessageBox msg;
    A.setid(ui->lineEdit_mid->text().toInt());
    A.setnomutilisateur(ui->mnom->text());
    A.setmdp(ui->lineEdit_mmdp->text());

    bool test=A.modifier(A.getid());
    if(test)
    {
        msg.setText("modification avec succès");
        ui->tableView_profil->setModel(A.afficher());
    }
    else
        msg.setText("echec de modification");

    msg.exec();
}

void gestion_salle::on_rechercherid_clicked()
{
    authentification A;
    QSqlQuery query;
    int id=ui->lineEdit_mid->text().toInt();
    QString id_string=QString::number(id);
   if(A.recherche_id(id))
   {
       query.prepare("SELECT * FROM PROFIL WHERE id like :id");
       query.bindValue(0,id_string);
       query.exec();
       while(query.next()){
       ui->mnom->setText(query.value(1).toString());
       ui->lineEdit_mmdp->setText(query.value(2).toString());
    }
   }
}

void gestion_salle::on_trinomprofil_clicked()
{
    QMessageBox msgBox ;

    QSqlQueryModel *model = new QSqlQueryModel();
             model->setQuery("SELECT * FROM PROFIL order by nom_utilisateur ASC");
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom d'utilisateur"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("mot de passe"));
             ui->tableView_profil->setModel(model);
             ui->tableView_profil->show();
             msgBox.setText("Tri avec succès.");
             msgBox.exec();
}

void gestion_salle::on_triidprofil_clicked()
{
    QMessageBox msgBox ;

    QSqlQueryModel *model = new QSqlQueryModel();
             model->setQuery("SELECT * FROM PROFIL order by id ASC");
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom d'utilisateur"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("mot de passe"));
             ui->tableView_profil->setModel(model);
             ui->tableView_profil->show();
             msgBox.setText("Tri avec succès.");
             msgBox.exec();
}

void gestion_salle::on_pushButton_imprimerprofil_clicked()
{
    //imprimer

          QPrinter printer;

          printer.setPrinterName("desiered printer name");

        QPrintDialog dialog(&printer,this);

          if(dialog.exec()== QDialog::Rejected)

              return;
}

void gestion_salle::on_pushButton_pdfprofil_clicked()
{
                     QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tableView_profil->model()->rowCount();
                     const int columnCount = ui->tableView_profil->model()->columnCount();

                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView_profil->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView_profil->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView_profil->isColumnHidden(column)) {
                                 QString data = ui->tableView_profil->model()->data(ui->tableView_profil->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n"
                         "</body>\n"
                         "</html>\n";

               QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                 if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                QPrinter printer (QPrinter::PrinterResolution);
                 printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName(fileName);

                QTextDocument doc;
                 doc.setHtml(strStream);
                 doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                 doc.print(&printer);
}


void gestion_salle::on_pushButton_rechprofil_clicked()
{
            authentification A;
            if (ui->comboBox_2->currentText()=="Rechercher par ID")
            {
                int id=ui->lineEdit_profilrech->text().toInt();
                if (A.recherche_id(id))
                {
                    ui->tableView_profil->setModel(A.afficher_id(id));
                }
            }
            else if(ui->comboBox_2->currentText()=="Rechercher par nom d'utilisateur")
            {
                QString nomutilisateur=ui->lineEdit_profilrech->text();
                if (A.recherche_nom(nomutilisateur))
                {
                    ui->tableView_profil->setModel(A.afficher_nom(nomutilisateur));
                }
            }
}


