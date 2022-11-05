#include "ajout_pat.h"
#include "ui_ajout_pat.h"

ajout_pat::ajout_pat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajout_pat)
{
    ui->setupUi(this);
}

ajout_pat::~ajout_pat()
{
    delete ui;
}

void ajout_pat::on_pushButton_clicked()
{
    //CONNEXION AVEC BD
    // REMARQUE IL FAUT D'ABORD INCLUDER LE FICHIER acceuil.h DANS LE FICHIER ajout_pat.h
    acceuil conn;

           QString Num_Patient,Nom,Adresse;
           Num_Patient = ui->lineEdit_Numpat->text();
           Nom = ui->lineEdit_Nompat->text();
           Adresse = ui->lineEdit_Adresse->text();
           if(!conn.connOpen())
           {
               // NON CONNECTER AVEC BD
               qDebug() << "Failed";
               return;
           }
           conn.connOpen();
           qDebug()<<"in AddLaptop:: on_btnAdd_clicked()";
           QSqlQuery query(  acceuil::getInstance()->getDBInstance());

           query.prepare("select count(Id) from patient where Num_Patient = '" + Num_Patient + "'");
           int flag = -1;
           if(!query.exec())
           {
               qDebug() << query.lastError().text() << query.lastQuery();

           }
           else
           {
               // PATIENT DEJA SAISIE DANS LE BD

               query.next();
               flag = query.value(0).toInt();
               if(flag>0)
               {
               QMessageBox::information(this,"ERROR","Patient déjà saisie");
               }
           }
           if(flag <= 0)
           {
               // AJOUT DES CONTENUES DES PATIENTS
               query.clear();
               query.prepare("insert into patient (Num_Patient ,Nom_Patient ,Adresse) values ('"+Num_Patient+ "','"+Nom+"','"+Adresse+ "')");

              if(!query.exec())
              {
                  qDebug() << query.lastError().text() << query.lastQuery();
              }
               else
              {
                      QMessageBox::information(this,"GOOD","Patient Ajouter Avec Succer");
              }
          }
}
void ajout_pat::on_pushButton_2_clicked()
{
    this->close();
}

