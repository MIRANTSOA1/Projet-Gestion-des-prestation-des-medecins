#ifndef LISTEPATIENTTRAITER_H
#define LISTEPATIENTTRAITER_H

#include <QDialog>
#include "acceuil.h"

namespace Ui {
class listepatienttraiter;
}

class listepatienttraiter : public QDialog
{
    Q_OBJECT
public:
    QSqlDatabase mydb;
    static listepatienttraiter* getInstance();
      QSqlDatabase getDBInstance();
public:
    explicit listepatienttraiter(QWidget *parent = nullptr);
    ~listepatienttraiter();

private slots:
    void on_pushButton_clicked();

private:
    Ui::listepatienttraiter *ui;
    QStandardItemModel *model;
    QStandardItemModel *model1;
     void showAllElements();
    static listepatienttraiter *instance;
};

#endif // LISTEPATIENTTRAITER_H
