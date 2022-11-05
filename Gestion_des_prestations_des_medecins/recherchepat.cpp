#include "recherchepat.h"
#include "ui_recherchepat.h"

recherchepat::recherchepat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recherchepat)
{
    ui->setupUi(this);
}

recherchepat::~recherchepat()
{
    delete ui;
}

void recherchepat::on_btnFind_clicked()
{
        acceuil conn;
       QString sValue1 = ui->txtnumpat->text();
       QString sCriteriaColum1 = "";

        if (ui->rdoNumpat->isChecked())
           sCriteriaColum1="Num_Patient";
       else if (ui->rdoNompat->isChecked())
           sCriteriaColum1="Nom_Patient";
       else if (ui->rdoAdresse->isChecked())
           sCriteriaColum1 = "Adresse";
       qDebug() << "in init()";
       QSqlQueryModel * model = new QSqlQueryModel(this);

       QSqlQuery query( acceuil::getInstance()->getDBInstance());
       query.prepare("select Num_Patient,Nom_Patient,Adresse FROM patient where " +sCriteriaColum1+" like '%" + sValue1 + "%' ");

       if(!query.exec())
          QMessageBox::information(this,"recherche","Error");
       else
       {
           char flag = -1;

           while(query.next())
           {  flag = 1;
              ui->txtnumpat->setText(query.value(0).toString());

           }
           if(flag == 1)
           {
               qDebug()<<query.value(0).toString();

               model->setQuery(query);
               ui->tableView_pat->setModel(model);
               qDebug() << "rows are : " << model->rowCount();
               ui->tableView_pat->show();
           }
           else
               QMessageBox::information(this,"recherche"," Patient non Trouver");

       }
       }

