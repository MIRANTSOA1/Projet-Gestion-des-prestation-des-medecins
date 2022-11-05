#ifndef SUP_MED_H
#define SUP_MED_H

#include <QDialog>
#include "acceuil.h"

namespace Ui {
class sup_med;
}

class sup_med : public QDialog
{
    Q_OBJECT

public:
    explicit sup_med(QWidget *parent = nullptr);
    ~sup_med();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::sup_med *ui;
};

#endif // SUP_MED_H
