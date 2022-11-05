#ifndef ETAT_H
#define ETAT_H

#include <QDialog>
#include  "acceuil.h"

namespace Ui {
class etat;
}

class etat : public QDialog
{
    Q_OBJECT
public:
    QSqlDatabase mydb;
    static etat* getInstance();
      QSqlDatabase getDBInstance();

public:
    explicit etat(QWidget *parent = nullptr);
    ~etat();

private slots:
      void on_pushButton_clicked();

private:
    Ui::etat *ui;
    QStandardItemModel *model;
    QStandardItemModel *model1;
     void showAllElements();
    static etat *instance;
};

#endif // ETAT_H
