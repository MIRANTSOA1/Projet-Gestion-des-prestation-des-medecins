#include "sup_pat.h"
#include "ui_sup_pat.h"

sup_pat::sup_pat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sup_pat)
{
    ui->setupUi(this);
}

sup_pat::~sup_pat()
{
    delete ui;
}

void sup_pat::on_pushButton_2_clicked()
{
    acceuil conn;

    QString Num_Patient = ui->lineEdit_suppat->text();

    QSqlQuery query( acceuil::getInstance()->getDBInstance());
    query.prepare("select Num_Patient,Nom_Patient,Adresse from patient where Num_Patient='" + Num_Patient + "'");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();

    char flag = -1;

    while(query.next())
    {  flag = 1;


    }
    if(flag == 1)
    {
        QSqlQuery qry;
        qry.prepare("Delete from patient where Num_Patient='"+Num_Patient+"'");
        if (qry.exec()){
            QMessageBox::critical(this, tr("Delete"),tr("Patient supprimer du base de donné"));
            conn.connclose();
        }
    }
    else
        QMessageBox::information(this,"recherche"," Patient non Trouver");
}

