#include "ajout_med.h"
#include "ui_ajout_med.h"

ajout_med::ajout_med(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajout_med)
{
    ui->setupUi(this);
    acceuil conn;
     if(!conn.connOpen())
        ui->label_ajoutmed->setText("not connect");
    else
        ui->label_ajoutmed->setText("connect");
}

ajout_med::~ajout_med()
{
    delete ui;
}

void ajout_med::on_pushButton_clicked()
{
    //connection avec BASE DE DONNEES
    // REMARQUE IL FAUT D'ABORD INCLUDER LE FICHIER acceuil.h DANS LE FICHIER ajout_med.h
     acceuil conn;

     /* AJOUT DES MEDECINS */

            QString Num_medecin,Nom,Taux_journalier;
            Num_medecin = ui->lineEdit_Nummed->text();
            Nom = ui->lineEdit_Nommed->text();
            Taux_journalier = ui->spinBox->text();
            if(!conn.connOpen())
            {
                qDebug() << "Failed";
                return;
            }
            conn.connOpen();

            qDebug()<<"in AddLaptop:: on_btnAdd_clicked()";
            QSqlQuery query(  acceuil::getInstance()->getDBInstance());
            query.prepare("select count(Id) from medecin where Num_medecin = '" + Num_medecin + "'");
            int flag = -1;
            if(!query.exec())
            {
                // SI query ne marche pas

                qDebug() << query.lastError().text() << query.lastQuery();
            }
            else
            {
                 // SI MEDECIN DEJA SAISIE

                query.next();
                flag = query.value(0).toInt();
                if(flag>0)
                {
                QMessageBox::information(this,"Non","Medecin déjà saisie");
                }
            }

            if(flag <= 0)
            {   // INSERTION DES CONTENUES DU TABLE MEDECIN

                query.clear();
                query.prepare("insert into medecin (Num_medecin ,Nom_medecin ,Taux_journalier) "
                              "values ('"+Num_medecin+ "','"+Nom+"','"+Taux_journalier+ "')");

               if(!query.exec())
               {
                   // SI query ne marche pas

                   qDebug() << query.lastError().text() << query.lastQuery();
               }
                else
               {       // AJOUTER AVEC SUCCES
                       QMessageBox::information(this,"GOOD","Medecin Ajouter Avec Succès");
               }
           }
 }
void ajout_med::on_pushButton_2_clicked()
{
    this->close();
}

