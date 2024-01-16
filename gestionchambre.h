#ifndef GESTIONCHAMBRE_H
#define GESTIONCHAMBRE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTextBrowser>
#include <QDebug>
#include<QTableWidget>

namespace Ui {
class GestionChambre;
}

class GestionChambre : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionChambre(QWidget *parent = nullptr);
    ~GestionChambre();
    void afficherTousLesChambres(QTableWidget *tableWidget, const QStringList &listeClients);

private slots:
    void on_ButtonMise_clicked();

    void on_ButtonChercher_clicked();

    void on_pushButton_clicked();

private:
    Ui::GestionChambre *ui;
};

#endif // GESTIONCHAMBRE_H
