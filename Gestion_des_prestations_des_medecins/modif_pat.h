#ifndef MODIF_PAT_H
#define MODIF_PAT_H

#include <QDialog>
#include "acceuil.h"

namespace Ui {
class modif_pat;
}

class modif_pat : public QDialog
{
    Q_OBJECT

public:
    explicit modif_pat(QWidget *parent = nullptr);
    ~modif_pat();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::modif_pat *ui;
    void showAllElements();
    void hideAllElements();
};

#endif // MODIF_PAT_H
