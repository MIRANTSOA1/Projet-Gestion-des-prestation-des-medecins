#include "listepatienttraiter.h"
#include "ui_listepatienttraiter.h"

listepatienttraiter* listepatienttraiter::instance = nullptr;

listepatienttraiter::listepatienttraiter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listepatienttraiter)
{
    ui->setupUi(this);
     acceuil conn;
     if(!conn.connOpen())
        ui->label_liste->setText("not connect");
    else
        ui->label_liste->setText("connect");
}

listepatienttraiter::~listepatienttraiter()
{
    delete ui;
}

void listepatienttraiter::on_pushButton_clicked()
{

    acceuil conn;
    QString sValue = ui->txtValue->text();

    if (ui->rdoannee->isChecked()){
         QString DATE = ui->txtValue_2->text();

        qDebug() << "in init()";
        QSqlQueryModel * model = new QSqlQueryModel(this);
        QSqlQuery query1( listepatienttraiter::getInstance()->getDBInstance());
        query1.prepare("select Num_medecin,Nom_medecin,Taux_journalier FROM medecin  WHERE Num_medecin ='" +sValue+"'");
        if(!query1.exec())
                   QMessageBox::information(this,"recherche","Aucun patient");
        else {
            char flag = -1;

            while(query1.next())
            {  flag = 1;

               ui->txtNommed->setText(query1.value(1).toString());
               ui->txtTaux->setText(query1.value(2).toString());

            }
            if(flag == 1)
            {
                showAllElements();
            }

            QSqlQuery query( listepatienttraiter::getInstance()->getDBInstance());
            query.prepare("select Num_Patient,Nom_Patient,Adresse,Nbjour,(Nbjour*Taux_journalier) AS[Montant] FROM patient,medecin,traitement WHERE traitement.Numero_Medecin = medecin.Num_medecin AND patient.Num_Patient = traitement.Numero_Patient AND Numero_Medecin ='" +sValue+"' AND strftime('%Y',Date_de_consultation) = '"+DATE+"'" );


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
           query.prepare("select Num_Patient,Nom_Patient,Adresse,Nbjour,SUM((Nbjour*Taux_journalier))  FROM patient,medecin,traitement WHERE traitement.Numero_Medecin = medecin.Num_medecin AND patient.Num_Patient = traitement.Numero_Patient AND Numero_Medecin ='" +sValue+"' AND strftime('%Y',Date_de_consultation) = '"+DATE+"'" );
            if(query.exec())
            {
                while(query.next())
                {
                    ui->label_5->setText(query.value(4).toString()+" " +"Ariary");
               }
            }

        }

       }
   else if (ui->rdomois->isChecked()){
         QString DATE = ui->txtValue_3->text();
        qDebug() << "in init()";
        QSqlQueryModel * model = new QSqlQueryModel(this);
        QSqlQuery query1( listepatienttraiter::getInstance()->getDBInstance());
        query1.prepare("select Num_medecin,Nom_medecin,Taux_journalier FROM medecin  WHERE Num_medecin ='" +sValue+"'");
        if(!query1.exec())
                   QMessageBox::information(this,"recherche","Aucun patient");
        else {
            char flag = -1;

            while(query1.next())
            {  flag = 1;

               ui->txtNommed->setText(query1.value(1).toString());
               ui->txtTaux->setText(query1.value(2).toString());

            }
            if(flag == 1)
            {
                showAllElements();
            }
            QSqlQuery query( listepatienttraiter::getInstance()->getDBInstance());
            query.prepare("select Num_Patient,Nom_Patient,Adresse,Nbjour,(Nbjour*Taux_journalier) AS[Montant] FROM patient,medecin,traitement WHERE traitement.Numero_Medecin = medecin.Num_medecin AND patient.Num_Patient = traitement.Numero_Patient AND Numero_Medecin ='" +sValue+"' AND strftime('%m',Date_de_consultation) = '"+DATE+"'" );

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
           query.prepare("select Num_Patient,Nom_Patient,Adresse,Nbjour,SUM((Nbjour*Taux_journalier))  FROM patient,medecin,traitement WHERE traitement.Numero_Medecin = medecin.Num_medecin AND patient.Num_Patient = traitement.Numero_Patient AND Numero_Medecin ='" +sValue+"' AND strftime('%m',Date_de_consultation) = '"+DATE+"'" );
            if(query.exec())
            {
                while(query.next())
                {
                    ui->label_5->setText(query.value(4).toString()+" " +"Ariary");
               }
            }

        }
 }
    else if (ui->rdodate->isChecked()){
        QString date1,date2;
        date1=ui->dateEdit->text();
        date2=ui->dateEdit_2->text();

        QSqlQueryModel * model = new QSqlQueryModel(this);
        QSqlQuery query1( listepatienttraiter::getInstance()->getDBInstance());
        query1.prepare("select Num_medecin,Nom_medecin,Taux_journalier FROM medecin  WHERE Num_medecin ='" +sValue+"'");
        if(!query1.exec())
                   QMessageBox::information(this,"recherche","Aucun patient");
        else {


            char flag = -1;

            while(query1.next())
            {  flag = 1;

               ui->txtNommed->setText(query1.value(1).toString());
               ui->txtTaux->setText(query1.value(2).toString());

            }
            if(flag == 1)
            {
                showAllElements();
            }
            QSqlQuery query( listepatienttraiter::getInstance()->getDBInstance());
            query.prepare("select Num_Patient,Nom_Patient,Adresse,Nbjour,(Nbjour*Taux_journalier) AS[Montant] FROM patient,medecin,traitement WHERE traitement.Numero_Medecin = medecin.Num_medecin AND patient.Num_Patient = traitement.Numero_Patient AND Numero_Medecin ='" +sValue+"'  AND Date_de_consultation BETWEEN '"+date1+"' AND '"+date2+"'");
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
           query.prepare("select Num_Patient,Nom_Patient,Adresse,Nbjour,SUM((Nbjour*Taux_journalier)) FROM patient,medecin,traitement WHERE traitement.Numero_Medecin = medecin.Num_medecin AND patient.Num_Patient = traitement.Numero_Patient AND Numero_Medecin ='" +sValue+"'  AND Date_de_consultation BETWEEN '"+date1+"' AND '"+date2+"'" );
            if(query.exec())
            {
                while(query.next())
                {
                    ui->label_5->setText(query.value(4).toString()+" "+"Ariary");
               }
            }

    }
 }
}
void listepatienttraiter:: showAllElements()
{
    ui->txtTaux->show();
    ui->txtNommed->show();

}
QSqlDatabase listepatienttraiter::getDBInstance()
{
    return mydb;
}
listepatienttraiter *listepatienttraiter::getInstance()
{
    qDebug() << "in MyDB::getInstance()";

    if(instance == nullptr)
        instance = new listepatienttraiter();
    return instance;

}

