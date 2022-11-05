#ifndef SUP_PAT_H
#define SUP_PAT_H

#include <QDialog>
#include "acceuil.h"

namespace Ui {
class sup_pat;
}

class sup_pat : public QDialog
{
    Q_OBJECT

public:
    explicit sup_pat(QWidget *parent = nullptr);
    ~sup_pat();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::sup_pat *ui;
};

#endif // SUP_PAT_H
