#include "modif_pat.h"
#include "ui_modif_pat.h"

modif_pat::modif_pat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modif_pat)
{
    ui->setupUi(this);
    hideAllElements();
}

modif_pat::~modif_pat()
{
    delete ui;
}

void modif_pat::on_pushButton_2_clicked()
{
    acceuil conn;
    hideAllElements();
    QString Num_Patient = ui->lineEdit_modpat->text();

    QSqlQuery query( acceuil::getInstance()->getDBInstance());
    query.prepare("select Num_Patient,Nom_Patient,Adresse from patient where Num_Patient='" + Num_Patient + "'");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();
    char flag = -1;
    while(query.next())
    {  flag = 1;
       //RECUPERATION DES VALEURS

       ui->txtnumpat->setText(query.value(0).toString());
       ui->txtNompat->setText(query.value(1).toString());
       ui->txtAdresse->setText(query.value(2).toString());

    }
    if(flag == 1)
    {
        showAllElements();
    }
    else
        QMessageBox::information(this,"recherche"," Medecin non Trouver");

}
void modif_pat:: showAllElements()
{
    ui->txtAdresse->show(); ui->lblAdresse->show();
    ui->txtNompat->show(); ui->lblNompat->show();
     ui->txtnumpat->show();  ui->lblnumpat->show();
     ui->pushButton->show();
}
void modif_pat::hideAllElements()
{
    ui->txtAdresse->hide(); ui->lblAdresse->hide();
    ui->txtNompat->hide(); ui->lblNompat->hide();
    ui->txtnumpat->hide(); ui->lblnumpat->hide();
    ui->pushButton->hide();
}
void modif_pat::on_pushButton_clicked()
{
    QString Num_Patient  = ui->txtnumpat->text();
    QString Nom     = ui->txtNompat->text();
    QString Adresse      = ui->txtAdresse->text();

    QSqlQuery query( acceuil::getInstance()->getDBInstance());
    query.clear();

    query.prepare("update patient set Nom_Patient = '" + Nom + "',Adresse = '"+ Adresse + "'  where Num_Patient  = '" + Num_Patient  + "'");

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
