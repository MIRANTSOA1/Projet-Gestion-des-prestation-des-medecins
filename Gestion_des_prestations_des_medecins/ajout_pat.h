#ifndef AJOUT_PAT_H
#define AJOUT_PAT_H

#include <QDialog>
#include "acceuil.h"

namespace Ui {
class ajout_pat;
}

class ajout_pat : public QDialog
{
    Q_OBJECT

public:
    explicit ajout_pat(QWidget *parent = nullptr);
    ~ajout_pat();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ajout_pat *ui;
};

#endif // AJOUT_PAT_H
