#ifndef AJOUT_MED_H
#define AJOUT_MED_H

#include <QDialog>
#include "acceuil.h"

namespace Ui {
class ajout_med;
}

class ajout_med : public QDialog
{
    Q_OBJECT

public:
    explicit ajout_med(QWidget *parent = nullptr);
    ~ajout_med();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ajout_med *ui;
};

#endif // AJOUT_MED_H
