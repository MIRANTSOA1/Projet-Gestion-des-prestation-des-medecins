#ifndef AIDE_H
#define AIDE_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QSqlQuery>
#include "QStandardItemModel"

namespace Ui {
class aide;
}

class aide : public QDialog
{
    Q_OBJECT
    QSqlDatabase mydb;

   void connclose()
   {
       mydb.close();
              mydb.removeDatabase(QSqlDatabase::defaultConnection);

   };
   bool connOpen()
   {
       mydb = QSqlDatabase::addDatabase("QSQLITE");
      mydb.setDatabaseName("D:/Projet/login.db");

      if(!mydb.open()){
                 qDebug()<< ("Not connected");
                 return false;

             }
             else qDebug()<<("Connected");
             return true;
   };

public:
    explicit aide(QWidget *parent = nullptr);
    ~aide();

private slots:
    void on_push_clicked();

private:
    Ui::aide *ui;
};

#endif // AIDE_H
