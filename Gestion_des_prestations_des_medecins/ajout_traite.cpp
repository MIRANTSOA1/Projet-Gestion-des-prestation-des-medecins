#include "ajout_traite.h"
#include "ui_ajout_traite.h"

ajout_traite::ajout_traite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajout_traite)
{
    ui->setupUi(this);

     affichageDonneecombo();
     affichageDonneecombo2();
}

ajout_traite::~ajout_traite()
{
    delete ui;
}

// AFFICHAGE DES NUMEROS DES MEDECINS  EXISTANT DANS LE TABLE MEDECIN

void ajout_traite::affichageDonneecombo(){
    QSqlQuery requete; int ligne(0);
       requete.exec("select count(*) from medecin");
       while (requete.next()) {
           ligne=requete.value(0).toInt();
       }
       model = new  QStandardItemModel(ligne,3);
           int row (0);
           requete.exec("select Num_medecin from medecin");
           while (requete.next()) {
               for (int j=0; j<3 ;j++) {

                   QStandardItem *item=new QStandardItem(requete.value(j).toString());
                   model->setItem(row,j,item);

               }
               row++;
           }
            model->setHeaderData(0,Qt::Horizontal,"Num_medecin");


            ui->comboBox1->setModel(model);
}

// AFFICHAGE DES NUMEROS DES PATIENTS EXISTANT  DANS LE TABLE PATIENT

void ajout_traite::affichageDonneecombo2(){
    QSqlQuery requete; int ligne(0);
       requete.exec("select count(*) from patient");
       while (requete.next()) {
           ligne=requete.value(0).toInt();
       }
       model = new  QStandardItemModel(ligne,3);
           int row (0);
           requete.exec("select Num_Patient from patient");
           while (requete.next()) {
               for (int j=0; j<3 ;j++) {

                   QStandardItem *item=new QStandardItem(requete.value(j).toString());
                   model->setItem(row,j,item);

               }
               row++;
           }
            model->setHeaderData(0,Qt::Horizontal,"Num_Patient");
            ui->comboBox2->setModel(model);
}


// CODE AJOUT TRAITEMENT

void ajout_traite::on_pushButton_clicked()
{
    //CONNEXION AVEC BD
   // REMARQUE IL FAUT D'ABORD INCLUDER LE FICHIER acceuil.h DANS LE FICHIER ajout_traite.h
    acceuil conn;
           QString Num_Traitement,Num_medecin,Num_Patient,Nbjour;
           Num_Traitement = ui->lineEdit_Numtraite->text();
          Num_medecin = ui->comboBox1->currentText();
           Num_Patient = ui->comboBox2->currentText();
           Nbjour = ui->spinBox->text();
           QDate date = QDate::currentDate();
         QString  Date_de_concultation = date.toString("yyyy-MM-dd");

           if(!conn.connOpen())
           {
               qDebug() << "Failed";
               return;
           }

           conn.connOpen();
           qDebug()<<"in AddLaptop:: on_btnAdd_clicked()";

           QSqlQuery query(  acceuil::getInstance()->getDBInstance());
           query.prepare("select count(ID) from traitement where Num_Traitement = '" + Num_Traitement + "'");
           int flag = -1;
           if(!query.exec())
           {
               qDebug() << query.lastError().text() << query.lastQuery();
           }
           else
           {
               query.next();
               flag = query.value(0).toInt();
               if(flag>0)
               {
               QMessageBox::information(this,"tsia","Traitement déjà saisie");
               }
           }

           if(flag <= 0)
           {
               query.clear();
               query.prepare("insert into traitement (Num_Traitement ,Numero_medecin ,Numero_patient,Nbjour,Date_de_consultation) "
                             "values ('"+Num_Traitement+ "','"+Num_medecin+"','"+Num_Patient+ "','"+Nbjour+ "','"+Date_de_concultation+ "')");

              if(!query.exec())
              {
                  qDebug() << query.lastError().text() << query.lastQuery();
                   QMessageBox::information(this,"ERROR","ERROR");

              }
               else
              {
                      QMessageBox::information(this,"SUCCES","Traitement Ajouter Avec Succés");
              }
          }
}

