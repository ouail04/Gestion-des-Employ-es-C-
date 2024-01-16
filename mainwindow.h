// MainWindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTextBrowser>
#include <QDebug>
#include<QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void afficherTousLesClients(QTableWidget *tableWidget, const QStringList &listeClients);

    void on_ButtonMise_clicked();

    void on_ButtonChercher_clicked();

    void on_supprimerButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
