#ifndef ACCEUIL_H
#define ACCEUIL_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QSqlQuery>
#include "QStandardItemModel"

namespace Ui {
class acceuil;
}

class acceuil : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    static acceuil* getInstance();
      QSqlDatabase getDBInstance();
   void connclose()
   {
       mydb.close();
              mydb.removeDatabase(QSqlDatabase::defaultConnection);

   };
   bool connOpen()
   {
       mydb = QSqlDatabase::addDatabase("QSQLITE");
      mydb.setDatabaseName("D:/Projet/Gestion des prestations des medecins.db");

      if(!mydb.open()){
                 qDebug()<< ("Not connected");
                 return false;

             }
             else qDebug()<<("Connected");
             return true;
   };
public:
    explicit acceuil(QWidget *parent = nullptr);
    ~acceuil();

private slots:
    void on_pushButton_23_clicked();

    void affichageDonneeMedecin();

    void affichageDonneePatient();

    void affichageDonneeTraite();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButtonoms_clicked();

private:
    Ui::acceuil *ui;
    QStandardItemModel *model;

    static acceuil *instance;
};

#endif // ACCEUIL_H
