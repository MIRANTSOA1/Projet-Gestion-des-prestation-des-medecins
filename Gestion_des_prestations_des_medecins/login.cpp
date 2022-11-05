#include "login.h"
#include "ui_login.h"
#include "aide.h"
Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

}
Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    connOpen();
    QString usernam,password;
    usernam = ui->lineEdit_user->text();
    password = ui->lineEdit_pass->text();
      if(!mydb.open()){
          qDebug() << "Failed";
          return;
      }
      QSqlQuery qry;

      if (qry.exec("select  * from login where usenam='"+usernam+"' and password='"+password+"' ")){

          if(qry.next()){
              this->hide();
              acceuil acceuil;
              acceuil.setModal(true);
              acceuil.exec();
          }
          else
               QMessageBox::information(this,"ERROR","Mot de passe oublier");

      }

}


void Login::on_pushButton_2_clicked()
{
    aide aide;
    aide.setModal(true);
    aide.exec();
}

