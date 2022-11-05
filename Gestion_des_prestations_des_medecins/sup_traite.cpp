#include "sup_traite.h"
#include "ui_sup_traite.h"

sup_traite::sup_traite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sup_traite)
{
    ui->setupUi(this);
}

sup_traite::~sup_traite()
{
    delete ui;
}

void sup_traite::on_pushButton_2_clicked()
{
    acceuil conn;

    QString Num_Traitement = ui->lineEdit_suptraite->text();

    QSqlQuery query( acceuil::getInstance()->getDBInstance());
    query.prepare("select Num_Traitement ,Numero_medecin ,Numero_patient,Nbjour,Date_de_consultation from traitement"
                  " where Num_Traitement='" + Num_Traitement + "'");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();

    char flag = -1;

    while(query.next())
    {  flag = 1;


    }
    if(flag == 1)
    {
        QSqlQuery qry;
        qry.prepare("Delete from traitement where Num_Traitement='"+Num_Traitement+"'");
        if (qry.exec()){
            QMessageBox::critical(this, tr("Delete"),tr("Traitement supprimer du base de donné"));
            conn.connclose();
        }
    }
    else
        QMessageBox::information(this,"recherche"," Traitement non Trouver");
}

