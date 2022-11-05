#ifndef RECHERCHETRAITE_H
#define RECHERCHETRAITE_H

#include <QDialog>
#include  "acceuil.h"

namespace Ui {
class recherchetraite;
}

class recherchetraite : public QDialog
{
    Q_OBJECT

public:
    explicit recherchetraite(QWidget *parent = nullptr);
    ~recherchetraite();

private slots:
    void on_btnFind_clicked();

private:
    Ui::recherchetraite *ui;
};

#endif // RECHERCHETRAITE_H
