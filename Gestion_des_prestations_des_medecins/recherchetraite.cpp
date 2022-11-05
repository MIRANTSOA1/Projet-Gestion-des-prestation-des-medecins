#include "recherchetraite.h"
#include "ui_recherchetraite.h"

recherchetraite::recherchetraite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recherchetraite)
{
    ui->setupUi(this);
}

recherchetraite::~recherchetraite()
{
    delete ui;
}

void recherchetraite::on_btnFind_clicked()
{
    acceuil conn;
   QString sValue1 = ui->txtnumtraite->text();
   QString sCriteriaColum1 = "";


    if (ui->rdoNumTraite->isChecked())
       sCriteriaColum1="Num_Traitement";

   else if (ui->rdoDate->isChecked())
       sCriteriaColum1 = "Date_de_consultation";


   qDebug() << "in init()";
   QSqlQueryModel * model = new QSqlQueryModel(this);

   QSqlQuery query( acceuil::getInstance()->getDBInstance());
   query.prepare("select Num_Traitement,Numero_medecin,Numero_patient,Nbjour,Date_de_consultation FROM traitement "
                 "where " +sCriteriaColum1+" like '%" + sValue1 + "%' ");

   if(!query.exec())
      QMessageBox::information(this,"recherche","Error");
   else
   {
       char flag = -1;

       while(query.next())
       {  flag = 1;
          ui->txtnumtraite->setText(query.value(0).toString());

       }
       if(flag == 1)
       {
           qDebug()<<query.value(0).toString();

           model->setQuery(query);
           ui->tableView_traite->setModel(model);
           qDebug() << "rows are : " << model->rowCount();
           ui->tableView_traite->show();
       }
       else
           QMessageBox::information(this,"recherche"," Traitement non Trouver");

   }
}

