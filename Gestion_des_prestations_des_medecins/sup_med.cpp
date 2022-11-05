#include "sup_med.h"
#include "ui_sup_med.h"

sup_med::sup_med(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sup_med)
{
    ui->setupUi(this);
}

sup_med::~sup_med()
{
    delete ui;
}

void sup_med::on_pushButton_2_clicked()
{
    acceuil conn;

    QString Num_medecin = ui->lineEdit->text();

    QSqlQuery query( acceuil::getInstance()->getDBInstance());
    query.prepare("select Num_medecin,Nom_medecin,Taux_journalier from medecin where Num_medecin='" + Num_medecin + "'");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();

    char flag = -1;

    while(query.next())
    {  flag = 1;


    }
    if(flag == 1)
    {
        QSqlQuery qry;
        qry.prepare("Delete from medecin where Num_medecin='"+Num_medecin+"'");
        if (qry.exec()){
            QMessageBox::critical(this, tr("Delete"),tr("Medecin supprimé"));
            conn.connclose();
        }
    }
    else
        QMessageBox::information(this,"recherche"," Medecin non Trouver");
}
