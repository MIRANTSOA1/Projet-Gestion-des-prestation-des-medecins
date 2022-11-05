#ifndef MODIF_MED_H
#define MODIF_MED_H

#include <QDialog>
#include "acceuil.h"
namespace Ui {
class modif_med;
}

class modif_med : public QDialog
{
    Q_OBJECT

public:
    explicit modif_med(QWidget *parent = nullptr);
    ~modif_med();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::modif_med *ui;
    void showAllElements();
    void hideAllElements();
};

#endif // MODIF_MED_H
