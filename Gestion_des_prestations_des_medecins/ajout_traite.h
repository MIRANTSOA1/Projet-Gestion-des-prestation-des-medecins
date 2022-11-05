#ifndef AJOUT_TRAITE_H
#define AJOUT_TRAITE_H

#include <QDialog>
#include "acceuil.h"
namespace Ui {
class ajout_traite;
}

class ajout_traite : public QDialog
{
    Q_OBJECT

public:
    explicit ajout_traite(QWidget *parent = nullptr);

    ~ajout_traite();

    void affichageDonneecombo2();

      void affichageDonneecombo();
private slots:
      void on_pushButton_clicked();

private:
    Ui::ajout_traite *ui;
    QStandardItemModel *model;
};

#endif // AJOUT_TRAITE_H
