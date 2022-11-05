#include "aide.h"
#include "ui_aide.h"

aide::aide(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aide)
{
    ui->setupUi(this);
}

aide::~aide()
{
    delete ui;
}

//AIDE MOT DE PASSE OUBLIER

void aide::on_push_clicked()
{
    connOpen();
    QString usernam,password;
    usernam = ui->lineEdit_mot->text();
    password = ui->lineEdit_motpass->text();
      if(!mydb.open()){
          qDebug() << "Failed";
          return;
      }
      QSqlQuery qry;

      if (qry.exec("select  * from login where usenam='"+usernam+"' and num='"+password+"' ")){


          if(qry.next()){
          QString   msg = qry.value(1).toString();
          QMessageBox::information(this,"mot de passe",msg);
          }
}
}
