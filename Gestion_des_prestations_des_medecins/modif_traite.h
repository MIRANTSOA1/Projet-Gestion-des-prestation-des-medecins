#ifndef MODIF_TRAITE_H
#define MODIF_TRAITE_H

#include <QDialog>
#include  "acceuil.h"

namespace Ui {
class modif_traite;
}

class modif_traite : public QDialog
{
    Q_OBJECT

public:
    explicit modif_traite(QWidget *parent = nullptr);
    ~modif_traite();

    void affichageDonneecombo2();

      void affichageDonneecombo();

private slots:
      void on_pushButton_2_clicked();

      void on_pushButton_clicked();

private:
    Ui::modif_traite *ui;
      QStandardItemModel *model;
      void showAllElements();
      void hideAllElements();
};

#endif // MODIF_TRAITE_H
