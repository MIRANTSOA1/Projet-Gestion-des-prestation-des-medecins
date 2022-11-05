#include "recherchemed.h"
#include "ui_recherchemed.h"

recherchemed::recherchemed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recherchemed)
{
    ui->setupUi(this);
}

recherchemed::~recherchemed()
{
    delete ui;
}

void recherchemed::on_btnFind_clicked()
{
    acceuil conn;
    QString sValue = ui->txtValue->text();
    QString sCriteriaColum = "";

     if (ui->rdoNummed->isChecked())
        sCriteriaColum="Num_medecin";
    else if (ui->rdoNom->isChecked())
        sCriteriaColum="Nom_medecin";
    else if (ui->rdoTaux->isChecked())
        sCriteriaColum = "Taux_journalier";

    qDebug() << "in init()";
    QSqlQueryModel * model = new QSqlQueryModel(this);
    QSqlQuery query( acceuil::getInstance()->getDBInstance());
    query.prepare("select Num_medecin,Nom_medecin,Taux_journalier FROM medecin where " +sCriteriaColum+" like '%" + sValue + "%' ");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();
    else
    {
        char flag = -1;
        while(query.next())
        {  flag = 1;
           ui->txtValue->setText(query.value(0).toString());
        }
        if(flag == 1)
        {
            qDebug()<<query.value(0).toString();

            model->setQuery(query);
            ui->tableView->setModel(model);
            qDebug() << "rows are : " << model->rowCount();
            ui->tableView->show();
        }
        else
            QMessageBox::information(this,"recherche"," Medecin non Trouver");
    }
    }
