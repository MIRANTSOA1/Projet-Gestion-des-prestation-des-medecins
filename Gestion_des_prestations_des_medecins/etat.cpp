#include "etat.h"
#include "ui_etat.h"

etat* etat::instance = nullptr;
etat::etat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::etat)
{
    ui->setupUi(this);
    acceuil conn;

}

etat::~etat()
{
    delete ui;
}

void etat::on_pushButton_clicked()
{
    // REMARQUE IL FAUT D'ABORD INCLUDER LE FICHIER acceuil.h DANS LE FICHIER etat.h
    //CONNEXION AVEC BD

    acceuil conn;

    QString sValue = ui->txtValue->text();

    qDebug() << "in init()";
    QSqlQueryModel * model = new QSqlQueryModel(this);
    QSqlQuery query1(etat::getInstance()->getDBInstance());
    query1.prepare("select Num_medecin,Nom_medecin FROM medecin,traitement  WHERE strftime('%Y',Date_de_consultation)='" +sValue+"'");
    if(!query1.exec())
               QMessageBox::information(this,"recherche","Aucun patient");
    else {
          QSqlQuery query(etat::getInstance()->getDBInstance());
        query.prepare("select DISTINCT Num_medecin,Nom_medecin,SUM((Nbjour*Taux_journalier)) AS [PRESTATION] FROM medecin,traitement  WHERE traitement.Numero_Medecin = medecin.Num_medecin   AND strftime('%Y',Date_de_consultation)='" +sValue+"' GROUP BY    Num_medecin" );
        if(!query.exec()){
           qDebug() << query.lastError().text() << query.lastQuery();

        }
        else
        {
           if(query.numRowsAffected()>0)
           qDebug() << "== success query fetch() : " << query.lastQuery();
           else {
               qDebug() << " No record ! found ";
               qDebug() << " Query is : " << query.lastQuery();

           }
        }
        while(query.next())

            qDebug()<<query.value(0).toString();
        model->setQuery(query);
        ui->tableViewed->setModel(model);
        qDebug() << "rows are : " << model->rowCount();
        ui->tableViewed->show();
        qDebug() << "rows are : " << model->rowCount();
        ui->tableViewed->show();
       query.prepare("select DISTINCT Num_medecin,Nom_medecin,SUM((Nbjour*Taux_journalier)) FROM medecin,traitement  WHERE traitement.Numero_Medecin = medecin.Num_medecin   AND strftime('%Y',Date_de_consultation)='" +sValue+"'" );
        if(query.exec())
        {
            while(query.next())
            {
                ui->label_5->setText(query.value(2).toString()+" " +"Ariary");
           }
        }

    }
}
QSqlDatabase etat::getDBInstance()
{
    return mydb;
}
etat *etat::getInstance()
{
    qDebug() << "in MyDB::getInstance()";

    if(instance == nullptr)
        instance = new etat();

    return instance;

}



