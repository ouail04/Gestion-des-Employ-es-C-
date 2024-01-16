#ifndef RESERVATION_H
#define RESERVATION_H

#include <QMainWindow>
#include<QTableWidget>

namespace Ui {
class Reservation;
}

class Reservation : public QMainWindow
{
    Q_OBJECT

public:
    explicit Reservation(QWidget *parent = nullptr);
    ~Reservation();
    void afficherTousLesReservation(QTableWidget *tableWidget, const QStringList &listeClients);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_supprimerButton_clicked();

    void on_supprimerButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Reservation *ui;
};

#endif // RESERVATION_H
