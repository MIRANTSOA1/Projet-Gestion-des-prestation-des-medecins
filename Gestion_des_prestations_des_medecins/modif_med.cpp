#include "modif_med.h"
#include "ui_modif_med.h"

modif_med::modif_med(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modif_med)
{
    ui->setupUi(this);
    acceuil conn;
    if(!conn.connOpen())
       ui->label_connect->setText("not connect");
   else
       ui->label_connect->setText("connect");
    hideAllElements();
}

modif_med::~modif_med()
{
    delete ui;
}

void modif_med::on_pushButton_2_clicked()
{
    acceuil conn;
    hideAllElements();
    QString Num_medecin = ui->lineEdit->text();

    QSqlQuery query( acceuil::getInstance()->getDBInstance());
    query.prepare("select Num_medecin,Nom_medecin,Taux_journalier from medecin where Num_medecin='" + Num_medecin + "'");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();
    char flag = -1;

    while(query.next())
    {  flag = 1;
       //RECUPERATION DES VALEURS

       ui->txtnummed->setText(query.value(0).toString());
       ui->txtNommed->setText(query.value(1).toString());
       ui->txtTaux->setText(query.value(2).toString());

    }
    if(flag == 1)
    {
        showAllElements();
    }
    else
        QMessageBox::information(this,"recherche"," Medecin non Trouver");

}
void modif_med:: showAllElements()
{
    ui->txtTaux->show(); ui->lblTaux->show();
    ui->txtNommed->show(); ui->lblNommed->show();
     ui->txtnummed->show();  ui->lblnummede->show();
     ui->pushButton->show();
}

void modif_med::hideAllElements()
{
    ui->txtTaux->hide(); ui->lblTaux->hide();
    ui->txtNommed->hide(); ui->lblNommed->hide();
      ui->txtnummed->hide(); ui->lblnummede->hide();
    ui->pushButton->hide();
}

void modif_med::on_pushButton_clicked()
{
    QString Num_medecin  = ui->txtnummed->text();
    QString Nom     = ui->txtNommed->text();
    QString Taux_journalier      = ui->txtTaux->text();
    QSqlQuery query( acceuil::getInstance()->getDBInstance());
    query.clear();

    query.prepare("update medecin set Nom_medecin = '" + Nom + "',Taux_journalier = '"+ Taux_journalier + "' where Num_medecin  = '" + Num_medecin  + "'");

   if(!query.exec())
   {
       qDebug() << query.lastError().text() << query.lastQuery();

   }
   else
   {
       qDebug() << "read was successful "<< query.lastQuery();
       hideAllElements();
       QMessageBox::information(this,"modifier","Modification Valider");

   }
}

