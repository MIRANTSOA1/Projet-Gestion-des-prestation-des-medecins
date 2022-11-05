#include "acceuil.h"
#include "ui_acceuil.h"
#include "ajout_med.h"
#include "modif_med.h"
#include "sup_med.h"
#include "recherchemed.h"
#include "ajout_pat.h"
#include "modif_pat.h"
#include "recherchepat.h"
#include  "sup_pat.h"
#include  "ajout_traite.h"
#include  "sup_traite.h"
#include  "modif_traite.h"
#include  "recherchetraite.h"
#include  "listepatienttraiter.h"
#include  "listeconsulter.h"
#include  "etat.h"
#include  "QDesktopServices"
#include  "QUrl"

acceuil* acceuil::instance = nullptr;

acceuil::acceuil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::acceuil)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Aroniaina/Desktop/Nouveau dossier/Gestion_des_prestations_des_medecins/img/istockphoto-512278456-170667a.jpg");
    ui->labelimage->setPixmap(pix);
   QPixmap pix1("C:/Users/Aroniaina/Desktop/Nouveau dossier/Gestion_des_prestations_des_medecins/img/36ff1eb788f78ce2e18af233557c5d99.png");
    ui->labelpicmed->setPixmap(pix1);
    QPixmap pix2("C:/Users/Aroniaina/Desktop/Nouveau dossier/Gestion_des_prestations_des_medecins/img/istockphoto-1220315936-170667a.jpg");
     ui->labelpicpat->setPixmap(pix2);
    connOpen();
    affichageDonneeMedecin();
    affichageDonneePatient();
    affichageDonneeTraite();
}

void acceuil::affichageDonneeMedecin(){
    QSqlQuery requete; int ligne(0);
       requete.exec("select count(*) from medecin");
       while (requete.next()) {
           ligne=requete.value(0).toInt();
       }

       model = new  QStandardItemModel(ligne,3);
           int row (0);
           requete.exec("select Num_medecin ,Nom_medecin ,Taux_journalier from medecin");
           while (requete.next()) {
               for (int j=0; j<3 ;j++) {

                   QStandardItem *item=new QStandardItem(requete.value(j).toString());
                   model->setItem(row,j,item);

               }
               row++;
           }
            model->setHeaderData(0,Qt::Horizontal,"Num_medecin");
            model->setHeaderData(1,Qt::Horizontal,"Nom-medecin");
            model->setHeaderData(2,Qt::Horizontal,"Taux_journalier");

            ui->tableView_med->setModel(model);
}

void acceuil::affichageDonneePatient(){
    QSqlQuery requete; int ligne(0);
       requete.exec("select count(*) from patient");
       while (requete.next()) {
           ligne=requete.value(0).toInt();
       }
       model = new  QStandardItemModel(ligne,3);
           int row (0);
           requete.exec("select Num_Patient ,Nom_Patient ,Adresse from patient");
           while (requete.next()) {
               for (int j=0; j<3 ;j++) {

                   QStandardItem *item=new QStandardItem(requete.value(j).toString());
                   model->setItem(row,j,item);

               }
               row++;
           }
            model->setHeaderData(0,Qt::Horizontal,"Num_Patient");
            model->setHeaderData(1,Qt::Horizontal,"Nom_Patient");
            model->setHeaderData(2,Qt::Horizontal,"Adresse");

            ui->tableView_pat->setModel(model);

}

void acceuil::affichageDonneeTraite(){
    QSqlQuery requete; int ligne(0);
       requete.exec("select count(*) from patient");
       while (requete.next()) {
           ligne=requete.value(0).toInt();
       }
     //  QMessageBox::warning(this,"",QString::number(ligne));
       model = new  QStandardItemModel(ligne,5);
           int row (0);
           requete.exec("select Num_Traitement ,Numero_medecin ,Numero_Patient,Nbjour,Date_de_consultation from traitement");
           while (requete.next()) {
               for (int j=0; j<5 ;j++) {

                   QStandardItem *item=new QStandardItem(requete.value(j).toString());
                   model->setItem(row,j,item);

               }
               row++;
           }
            model->setHeaderData(0,Qt::Horizontal,"Num_Traitement");
            model->setHeaderData(1,Qt::Horizontal,"Numero_medecin");
            model->setHeaderData(2,Qt::Horizontal,"Numero_Patient");
             model->setHeaderData(3,Qt::Horizontal,"Nbjour");
              model->setHeaderData(4,Qt::Horizontal,"Date_de_consultation");

            ui->tableView_traite->setModel(model);

}
QSqlDatabase acceuil::getDBInstance()
{
    return mydb;
}
acceuil *acceuil::getInstance()
{
    qDebug() << "in MyDB::getInstance()";

    if(instance == nullptr)
        instance = new acceuil();

    return instance;

}


acceuil::~acceuil()
{
    delete ui;
}

void acceuil::on_pushButton_23_clicked()
{
    ajout_med ajout_med;
    ajout_med.setModal(true);
    ajout_med.exec();
}


void acceuil::on_pushButton_24_clicked()
{
    modif_med modif_med;
    modif_med.setModal(true);
    modif_med.exec();
}


void acceuil::on_pushButton_25_clicked()
{
    sup_med sup_med;
    sup_med.setModal(true);
    sup_med.exec();
}


void acceuil::on_pushButton_26_clicked()
{
    recherchemed recherchemed;
    recherchemed.setModal(true);
    recherchemed.exec();
}


void acceuil::on_pushButton_27_clicked()
{
    acceuil conn;
    affichageDonneeMedecin();
}


void acceuil::on_pushButton_36_clicked()
{
    ajout_pat ajout_pat;
    ajout_pat.setModal(true);
    ajout_pat.exec();
}


void acceuil::on_pushButton_37_clicked()
{
    modif_pat modif_pat;
    modif_pat.setModal(true);
    modif_pat.exec();
}


void acceuil::on_pushButton_39_clicked()
{
    recherchepat recherchepat;
    recherchepat.setModal(true);
    recherchepat.exec();
}


void acceuil::on_pushButton_38_clicked()
{
    sup_pat sup_pat;
    sup_pat.setModal(true);
    sup_pat.exec();
}


void acceuil::on_pushButton_40_clicked()
{
    acceuil conn;
    affichageDonneePatient();
}


void acceuil::on_pushButton_41_clicked()
{
    ajout_traite ajout_taite;
    ajout_taite.setModal(true);
    ajout_taite.exec();
}


void acceuil::on_pushButton_43_clicked()
{
    sup_traite sup_traite;
    sup_traite.setModal(true);
    sup_traite.exec();
}


void acceuil::on_pushButton_42_clicked()
{
    modif_traite modif_traite;
    modif_traite.setModal(true);
    modif_traite.exec();
}


void acceuil::on_pushButton_45_clicked()
{
    acceuil conn;
    affichageDonneeTraite();
}


void acceuil::on_pushButton_44_clicked()
{
    recherchetraite recherchetraite;
    recherchetraite.setModal(true);
    recherchetraite.exec();
}


void acceuil::on_pushButton_clicked()
{
   listepatienttraiter listepatienttraiter;
   listepatienttraiter.setModal(true);
   listepatienttraiter.exec();
}



void acceuil::on_pushButton_2_clicked()
{
  etat etat;
  etat.setModal(true);
  etat.exec();
 }


void acceuil::on_pushButton_3_clicked()
{
    listeconsulter listeconsulter;
    listeconsulter.setModal(true);
    listeconsulter.exec();
}


void acceuil::on_pushButton_4_clicked()
{
    this->close();
}


void acceuil::on_pushButtonoms_clicked()
{
  QString link="https://www.who.int/fr";
  QDesktopServices::openUrl(QUrl(link));
}

