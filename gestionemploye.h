#ifndef GESTIONEMPLOYE_H
#define GESTIONEMPLOYE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTextBrowser>
#include <QDebug>
#include<QTableWidget>

namespace Ui {
class GestionEmploye;
}

class GestionEmploye : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionEmploye(QWidget *parent = nullptr);
    ~GestionEmploye();
    void afficherTousLesEmploye(QTableWidget *tableWidget, const QStringList &listeClients);


private slots:
    void on_pushButton_2_clicked();

    void on_ButtonMise_clicked();

    void on_supprimerButton_2_clicked();

    void on_chercher_clicked();

    void on_pushButton_clicked();

private:
    Ui::GestionEmploye *ui;
};

#endif // GESTIONEMPLOYE_H
