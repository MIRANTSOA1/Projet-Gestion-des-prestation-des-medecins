#ifndef SUP_TRAITE_H
#define SUP_TRAITE_H

#include <QDialog>
#include "acceuil.h"

namespace Ui {
class sup_traite;
}

class sup_traite : public QDialog
{
    Q_OBJECT

public:
    explicit sup_traite(QWidget *parent = nullptr);
    ~sup_traite();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::sup_traite *ui;
};

#endif // SUP_TRAITE_H
