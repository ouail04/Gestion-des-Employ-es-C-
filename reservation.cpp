#include "reservation.h"
#include "ui_reservation.h"
#include "reserver.h"
#include <QSqlQuery>
#include"pageaccueille.h"

Reservation::Reservation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reservation)
{
    ui->setupUi(this);
    afficherTousLesReservation(ui->tableWidget, Reserver::obtenirTousLesReserver());
}

Reservation::~Reservation()
{
    delete ui;
}

void Reservation::on_pushButton_clicked()
{
    QString nom = ui->client->text();
    QString id = ui->num->text();
    int aid  = id.toInt();
    QString dateD= ui->dateD->text();
    QString dateF= ui->dateF->text();
    QString n = ui->njour->text();
    int v = n.toInt();
   ui->label_5->setText(Reserver::ajouterReservation(nom,aid,dateD,dateF,v));
}

void Reservation::afficherTousLesReservation(QTableWidget *tableWidget, const QStringList & listeClients)
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

void Reservation::on_pushButton_2_clicked()
{
    afficherTousLesReservation(ui->tableWidget, Reserver::obtenirTousLesReserver());
}


void Reservation::on_supprimerButton_clicked()
{
    QString CNIE = ui->messagesupp->text();
    int aid = CNIE.toInt();// Assurez-vous de remplacer cnieLineEdit par le nom réel de votre QLineEdit

    // Appeler la méthode de suppression du client en utilisant le CNIE comme paramètre
    QString resultatSuppression = Reserver::supprimerReservation(aid);
    // Mettre à jour l'interface utilisateur ou afficher un message en fonction du résultat
    ui->message->setText(resultatSuppression);
}


void Reservation::on_supprimerButton_2_clicked()
{
    QString cnie = ui->messagesupp_2->text();

       // Vérifier que le CNIE n'est pas vide
       if (cnie.isEmpty()) {
           // Afficher un message d'erreur ou prendre une autre action appropriée
           ui->erreur->setText("Cnie est vide");
           return;
       }

       // Exécuter la requête SQL pour récupérer les informations du client
       QSqlQuery query;
       query.prepare("SELECT idclient, nom, prenom, numeroTelephone FROM client WHERE CNIE = :cnie");
       query.bindValue(":cnie", cnie);

       if (query.exec() && query.next()) {
           QString nom = query.value("nom").toString();
           QString prenom = query.value("prenom").toString();
           QString numeroTelephone = query.value("numeroTelephone").toString();

           // Afficher les valeurs dans les labels correspondants
           ui->nomF->setText(nom);
           ui->prenomF->setText(prenom);
           ui->telephoneF->setText(numeroTelephone);
           ui->cnieF->setText(cnie);

           // Récupérer le montant total depuis la requête
           query.prepare("SELECT SUM(reservation.mantontTotale) AS mantontTotale "
                         "FROM reservation "
                         "JOIN client ON reservation.idclient = client.idclient "
                         "WHERE client.CNIE = :cnie");
           query.bindValue(":cnie", cnie);

           if (query.exec() && query.next()) {
               double montantTotal = query.value("mantontTotale").toDouble();

               // Afficher le montant total dans un label
               ui->montantF->setText(QString::number(montantTotal));

               query.prepare("SELECT COUNT(*) AS nombreChambresReservees "
                                                 "FROM reservation "
                                                 "JOIN client ON reservation.idclient = client.idclient "
                                                 "WHERE client.CNIE = :cnie");
                                   query.bindValue(":cnie", cnie);

                                   if (query.exec() && query.next()) {
                                       // Récupérer le nombre de chambres réservées depuis la requête
                                       int nombreChambresReservees = query.value("nombreChambresReservees").toInt();

                                       // Afficher le nombre de chambres réservées dans un label
                                       ui->chambreF->setText(QString::number(nombreChambresReservees));}



           } else {
               // Afficher un message d'erreur ou prendre une autre action appropriée
               ui->erreur->setText("Erreur lors de la récupération du montant total de la facture: " );
           }

           // Reste du code pour récupérer et afficher le nombre de chambres réservées

       } else {
           // Afficher un message d'erreur ou prendre une autre action appropriée
           ui->erreur->setText("Erreur lors de la récupération des informations du client: " );
       }
    }



void Reservation::on_pushButton_3_clicked()
{
    hide();
    PageAccueille *w = new PageAccueille();
    w->show();
}

