#include "modif_traite.h"
#include "ui_modif_traite.h"

modif_traite::modif_traite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modif_traite)
{
    ui->setupUi(this);
    hideAllElements();

}

modif_traite::~modif_traite()
{
    delete ui;
}
void modif_traite::on_pushButton_2_clicked()
{
    acceuil conn;
    hideAllElements();
    QString Num_Traitement = ui->lineEdit_modtraite->text();

    QSqlQuery query( acceuil::getInstance()->getDBInstance());
    query.prepare("select Num_Traitement ,Numero_Medecin ,Numero_Patient,Nbjour,Date_de_consultation from traitement where Num_Traitement='" + Num_Traitement + "'");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();
    char flag = -1;

    while(query.next())
    {  flag = 1;
       //RECUPERATION DES VALEURS
       ui->txtnumtraite->setText(query.value(0).toString());
       ui->txtnummed->setText(query.value(1).toString());
       ui->txtnumpat->setText(query.value(2).toString());
       ui->txtNbjour->setText(query.value(3).toString());
       ui->txtDate->setText(query.value(4).toString());

    }
    if(flag == 1)
    {
        showAllElements();
    }
    else
        QMessageBox::information(this,"recherche"," Traitement non Trouver");

}
void modif_traite:: showAllElements()
{
    ui->txtDate->show(); ui->lblDate->show();
    ui->txtNbjour->show(); ui->lblNbjour->show();
    ui->txtnumpat->show(); ui->label_pat->show();
    ui->txtnummed->show(); ui->label_med->show();
     ui->txtnumtraite->show();  ui->lblnumpat->show();
     ui->pushButton->show();
}

void modif_traite::hideAllElements()
{
    ui->txtDate->hide(); ui->lblDate->hide();
    ui->txtNbjour->hide(); ui->lblNbjour->hide();
      ui->txtnumtraite->hide(); ui->lblnumpat->hide();
      ui->txtnumpat->hide(); ui->label_pat->hide();
      ui->txtnummed->hide(); ui->label_med->hide();
    ui->pushButton->hide();
}
void modif_traite::on_pushButton_clicked()
{
    QString Num_Patient  = ui->txtnumtraite->text();
    QString Nummed = ui->txtnummed->text();
    QString Numpat= ui->txtnumpat->text();
      QString Nbjr = ui->txtNbjour->text();
        QString Date = ui->txtDate->text();

    QSqlQuery query( acceuil::getInstance()->getDBInstance());
    query.clear();

    query.prepare("update traitement set Numero_Patient = '" + Numpat + "',Nbjour = '"+ Nbjr + "',Date_de_consultation = '"+ Date + "' "
     " where Num_Traitement  = '" + Num_Patient  + "'");

   if(!query.exec())
   {
       qDebug() << query.lastError().text() << query.lastQuery();
       QMessageBox::information(this,"modifier","Modification Non Valider");

   }
   else
   {
       qDebug() << "read was successful "<< query.lastQuery();
       hideAllElements();
       QMessageBox::information(this,"modifier","Modification Valider");

   }
}

