#ifndef RECHERCHEPAT_H
#define RECHERCHEPAT_H

#include <QDialog>
#include  "acceuil.h"

namespace Ui {
class recherchepat;
}

class recherchepat : public QDialog
{
    Q_OBJECT

public:
    explicit recherchepat(QWidget *parent = nullptr);
    ~recherchepat();

private slots:
    void on_btnFind_clicked();

private:
    Ui::recherchepat *ui;
};

#endif // RECHERCHEPAT_H
