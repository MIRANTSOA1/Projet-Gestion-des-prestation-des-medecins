#include "listeconsulter.h"
#include "ui_listeconsulter.h"

listeconsulter* listeconsulter::instance = nullptr;

listeconsulter::listeconsulter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listeconsulter)
{
    ui->setupUi(this);
    acceuil conn;
    if(!conn.connOpen())
       ui->label_liste->setText("not connect");
   else
       ui->label_liste->setText("connect");
}

listeconsulter::~listeconsulter()
{
    delete ui;
}

void listeconsulter::on_pushButton_clicked()
{
    acceuil conn;
    QString sValue = ui->txtValue->text();


    // EDITION EN UNE ANNEE

    if (ui->rdoannee->isChecked()){
         QString DATE = ui->txtValue_2->text();

        qDebug() << "in init()";
        QSqlQueryModel * model = new QSqlQueryModel(this);
        QSqlQuery query1( listeconsulter::getInstance()->getDBInstance());
        query1.prepare("select Num_Patient,Nom_Patient FROM patient  WHERE Num_Patient ='" +sValue+"'");
        if(!query1.exec())
                   QMessageBox::information(this,"recherche","Aucun patient");
        else {
            char flag = -1;

            while(query1.next())
            {  flag = 1;
               ui->txtNommed->setText(query1.value(1).toString());
            }
            if(flag == 1)
            {
                showAllElements();
            }

            QSqlQuery query( listeconsulter::getInstance()->getDBInstance());
            query.prepare("SELECT Num_medecin,Nom_medecin,Taux_journalier,Date_de_consultation FROM medecin,traitement,patient WHERE patient.Num_Patient = traitement.Numero_Patient AND medecin.Num_medecin = traitement.Numero_Medecin  AND Num_Patient ='" +sValue+"' AND strftime('%Y',Date_de_consultation) = '"+DATE+"'" );

            if(!query.exec()){
               QMessageBox::information(this,"recherche","Aucun fddspatient");

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
           query.prepare("SELECT DISTINCT Num_medecin,Nom_medecin,Taux_journalier,Date_de_consultation,SUM((Nbjour)) FROM medecin,traitement,patient WHERE patient.Num_Patient = traitement.Numero_Patient AND medecin.Num_medecin = traitement.Numero_Medecin  AND Num_Patient ='" +sValue+"' AND strftime('%Y',Date_de_consultation) = '"+DATE+"'" );

            if(query.exec())
            {
                while(query.next())
                {
                    ui->label_5->setText(query.value(4).toString()+" "+ "jours");
               }
            }
            query.prepare("SELECT DISTINCT Num_medecin,Nom_medecin,Taux_journalier,Date_de_consultation,SUM((Taux_journalier*Nbjour)) FROM medecin,traitement,patient WHERE patient.Num_Patient = traitement.Numero_Patient AND medecin.Num_medecin = traitement.Numero_Medecin  AND Num_Patient ='" +sValue+"' AND strftime('%Y',Date_de_consultation) = '"+DATE+"'" );
             if(query.exec())
             {
                 while(query.next())
                 {
                     ui->label_8->setText(query.value(4).toString()+" " +"Ariary");
                }
             }

        }

       }

    // EDITION EN UN MOIS

    else if (ui->rdomois->isChecked()){
          QString DATE = ui->txtValue_3->text();
         qDebug() << "in init()";
         QSqlQueryModel * model = new QSqlQueryModel(this);
         QSqlQuery query1(listeconsulter::getInstance()->getDBInstance());
         query1.prepare("select Num_Patient,Nom_Patient FROM patient  WHERE Num_Patient ='" +sValue+"'");
         if(!query1.exec())
                    QMessageBox::information(this,"recherche","Aucun patient");
         else {
             char flag = -1;

             while(query1.next())
             {  flag = 1;
                ui->txtNommed->setText(query1.value(1).toString());
             }
             if(flag == 1)
             {
                 showAllElements();
             }
             QSqlQuery query( listeconsulter::getInstance()->getDBInstance());
             query.prepare("SELECT Num_medecin,Nom_medecin,Taux_journalier,Date_de_consultation FROM medecin,traitement,patient WHERE patient.Num_Patient = traitement.Numero_Patient AND medecin.Num_medecin = traitement.Numero_Medecin  AND Num_Patient ='" +sValue+"' AND strftime('%m',Date_de_consultation) = '"+DATE+"'" );


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
            query.prepare("SELECT DISTINCT Num_medecin,Nom_medecin,Taux_journalier,Date_de_consultation,SUM((Nbjour)) FROM medecin,traitement,patient WHERE patient.Num_Patient = traitement.Numero_Patient AND medecin.Num_medecin = traitement.Numero_Medecin  AND Num_Patient ='" +sValue+"' AND strftime('%m',Date_de_consultation) = '"+DATE+"'" );
             if(query.exec())
             {
                 while(query.next())
                 {
                     ui->label_5->setText(query.value(4).toString()+" " +"jours");
                }
             }
             query.prepare("SELECT DISTINCT Num_medecin,Nom_medecin,Taux_journalier,Date_de_consultation,SUM((Taux_journalier*Nbjour)) FROM medecin,traitement,patient WHERE patient.Num_Patient = traitement.Numero_Patient AND medecin.Num_medecin = traitement.Numero_Medecin  AND Num_Patient ='" +sValue+"' AND strftime('%m',Date_de_consultation) = '"+DATE+"'" );
              if(query.exec())
              {
                  while(query.next())
                  {
                      ui->label_8->setText(query.value(4).toString()+" " +"Ariary");
                 }
              }

         }
  }
    // EDITION ENTRE DEUX DATES

     else if (ui->rdodate->isChecked()){
         QString date1,date2;
         date1=ui->dateEdit->text();
         date2=ui->dateEdit_2->text();

         QSqlQueryModel * model = new QSqlQueryModel(this);
         QSqlQuery query1( listeconsulter::getInstance()->getDBInstance());
         query1.prepare("select Num_Patient,Nom_Patient FROM patient  WHERE Num_Patient ='" +sValue+"'");
         if(!query1.exec())
                    QMessageBox::information(this,"recherche","Aucun patient");
         else {
             char flag = -1;

             while(query1.next())
             {  flag = 1;
                ui->txtNommed->setText(query1.value(1).toString());
             }
             if(flag == 1)
             {
                 showAllElements();
             }
             QSqlQuery query( listeconsulter::getInstance()->getDBInstance());
             query.prepare("SELECT Num_medecin,Nom_medecin,Taux_journalier,Date_de_consultation FROM medecin,traitement,patient WHERE patient.Num_Patient = traitement.Numero_Patient AND medecin.Num_medecin = traitement.Numero_Medecin  AND Num_Patient ='" +sValue+"'  AND Date_de_consultation BETWEEN '"+date1+"' AND '"+date2+"'");


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
            query.prepare("SELECT DISTINCT Num_medecin,Nom_medecin,Taux_journalier,Date_de_consultation,SUM((Nbjour)) FROM medecin,traitement,patient WHERE patient.Num_Patient = traitement.Numero_Patient AND medecin.Num_medecin = traitement.Numero_Medecin  AND Num_Patient ='" +sValue+"'  AND Date_de_consultation BETWEEN '"+date1+"' AND '"+date2+"'" );
             if(query.exec())
             {
                 while(query.next())
                 {
                     ui->label_5->setText(query.value(4).toString()+" "+"jours");
                }
             }
             query.prepare("SELECT DISTINCT Num_medecin,Nom_medecin,Taux_journalier,Date_de_consultation,SUM((Taux_journalier*Nbjour)) FROM medecin,traitement,patient WHERE patient.Num_Patient = traitement.Numero_Patient AND medecin.Num_medecin = traitement.Numero_Medecin  AND Num_Patient ='" +sValue+"' AND Date_de_consultation BETWEEN '"+date1+"' AND '"+date2+"'" );
              if(query.exec())
              {
                  while(query.next())
                  {
                      ui->label_8->setText(query.value(4).toString()+" " +"Ariary");
                 }
              }
     }
  }
}
void listeconsulter:: showAllElements()
{
    ui->txtNommed->show();
}
QSqlDatabase listeconsulter::getDBInstance()
{
    return mydb;
}
listeconsulter *listeconsulter::getInstance()
{
    qDebug() << "in MyDB::getInstance()";
    if(instance == nullptr)
        instance = new listeconsulter();
   return instance;

}
