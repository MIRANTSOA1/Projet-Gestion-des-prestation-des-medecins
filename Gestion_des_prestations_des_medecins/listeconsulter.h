#ifndef LISTECONSULTER_H
#define LISTECONSULTER_H

#include <QDialog>
#include  "acceuil.h"

namespace Ui {
class listeconsulter;
}

class listeconsulter : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    static listeconsulter* getInstance();
      QSqlDatabase getDBInstance();

public:
    explicit listeconsulter(QWidget *parent = nullptr);
    ~listeconsulter();

private slots:
    void on_pushButton_clicked();

private:
    Ui::listeconsulter *ui;
    QStandardItemModel *model;
    QStandardItemModel *model1;
     void showAllElements();
    static listeconsulter *instance;
};

#endif // LISTECONSULTER_H
