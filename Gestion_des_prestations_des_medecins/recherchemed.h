#ifndef RECHERCHEMED_H
#define RECHERCHEMED_H

#include <QDialog>
#include "acceuil.h"

namespace Ui {
class recherchemed;
}

class recherchemed : public QDialog
{
    Q_OBJECT

public:
    explicit recherchemed(QWidget *parent = nullptr);
    ~recherchemed();

private slots:
    void on_btnFind_clicked();

private:
    Ui::recherchemed *ui;
};

#endif // RECHERCHEMED_H
