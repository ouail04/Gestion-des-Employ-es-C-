// MainWindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "pageaccueille.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    afficherTousLesClients(ui->tableWidgetClients,Client::obtenirTousLesClients());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString CNIE = ui->CNIE->text();
    QString numero = ui->numeroTelephone->text();
    QString email= ui->email->text();
    Client c(nom,prenom,email,numero,CNIE);
    ui->label->setText(c.ajouterClient());
}


void MainWindow::afficherTousLesClients(QTableWidget *tableWidget, const QStringList &listeClients)
{
    // Effacez le contenu actuel du tableau
    tableWidget->clearContents();
    tableWidget->setRowCount(0);

    if (!listeClients.isEmpty()) {
        // Divisez la première ligne pour déterminer le nombre de colonnes
        QStringList premierClient = listeClients.first().split(", ");
        int nombreColonnes = premierClient.size();

        // Assurez-vous que le nombre de colonnes dans le tableau est correct
        if (tableWidget->columnCount() != nombreColonnes) {
            tableWidget->setColumnCount(nombreColonnes);
        }

        // Ajustez le nombre de lignes du tableau
        tableWidget->setRowCount(listeClients.size());

        // Parcourez la liste de clients et ajoutez-les au tableau
        for (int row = 0; row < listeClients.size(); row++) {
            // Divisez la chaîne du client en colonnes
            QStringList colonnes = listeClients[row].split(", ");

            // Ajoutez les données aux cellules de la ligne
            for (int col = 0; col < nombreColonnes; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(colonnes[col]);
                tableWidget->setItem(row, col, item);
            }
        }
    }
}

void MainWindow::on_ButtonMise_clicked()
{
    afficherTousLesClients(ui->tableWidgetClients,Client::obtenirTousLesClients());
}


void MainWindow::on_ButtonChercher_clicked()
{
    QString str = ui->CNIECherche->text();
    QStringList list = Client::obtenirTousLesClientsCondition(str);
    afficherTousLesClients(ui->tableWidgetClients_2,list);
}


void MainWindow::on_supprimerButton_clicked()
{
    // Récupérer le CNIE du client à supprimer depuis l'interface utilisateur
    QString CNIE = ui->messagesupp->text(); // Assurez-vous de remplacer cnieLineEdit par le nom réel de votre QLineEdit

    // Appeler la méthode de suppression du client en utilisant le CNIE comme paramètre
    QString resultatSuppression = Client::supprimerClient(CNIE);
    // Mettre à jour l'interface utilisateur ou afficher un message en fonction du résultat
    ui->message->setText(resultatSuppression);
}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    PageAccueille *w = new PageAccueille();
    w->show();
}

