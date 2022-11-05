#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QSqlQuery>
#include "QStandardItemModel"
#include "acceuil.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
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
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
