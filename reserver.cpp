#include "reserver.h"
#include <QtSql>
#include <QLabel>
#include <QVBoxLayout>
Reserver::Reserver()
{

}
QString Reserver::ajouterReservation(const QString &nom, int &idchambre, const QString &dateD, const QString &dateF, const int &nombrejour)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/pc/OneDrive/Documents/untitled/ma_base_de_donnees.sqlite");

    if (!db.open()) {
        return "Erreur de connexion à la base de données: " + db.lastError().text();
    }

    QSqlQuery query;

    // Récupérer l'ID du client
    QString sqlClient = "SELECT idclient FROM client WHERE nom = :nom";
    query.prepare(sqlClient);
    query.bindValue(":nom", nom);

    int idClient = -1; // Initialiser à une valeur par défaut

    if (query.exec() && query.next()) {
        idClient = query.value("idclient").toInt();
    } else {
        return "La récupération de l'ID du client n'est pas complète : " + query.lastError().text();
    }

    // Vérifier si la chambre est occupée
    QString sqlChambre = "SELECT estoccupee FROM chambre WHERE idchambre = :idchambre";
    query.prepare(sqlChambre);
    query.bindValue(":idchambre", idchambre);

    QString estOccupee;
    if (query.exec() && query.next()) {
        estOccupee = query.value("estoccupee").toString();
    } else {
        return "La récupération de l'état de la chambre n'est pas complète : " + query.lastError().text();
    }

    if (estOccupee == "Non") {
        // Récupérer le montant de la chambre
        QString sqlMontant = "SELECT montant FROM chambre WHERE idchambre = :idchambre";
        query.prepare(sqlMontant);
        query.bindValue(":idchambre", idchambre);

        if (query.exec() && query.next()) {
            double montant = query.value("montant").toDouble();

            // Calculer le montant total
            double montantTotal = montant * nombrejour;

            // Insérer la réservation dans la table "Reservation"
            QString sqlReservation = "INSERT INTO Reservation (idclient, idchambre, datedebut, datefin, nombredejour, mantonttotale)  VALUES (:idClient, :idchambre, :dateD, :dateF, :nombrejour, :montanttotale)";

            query.prepare(sqlReservation);
            query.bindValue(":idClient", idClient);
            query.bindValue(":idchambre", idchambre);
            query.bindValue(":dateD", dateD);
            query.bindValue(":dateF", dateF);
            query.bindValue(":nombrejour", nombrejour);
            query.bindValue(":montanttotale", montantTotal);

            if (query.exec()) {
                // Mettre à jour l'état de la chambre à "Oui" (occupée)
                QString sqlUpdateChambre = "UPDATE chambre SET estoccupee = 'Oui' WHERE idchambre = :idchambre";
                query.prepare(sqlUpdateChambre);
                query.bindValue(":idchambre", idchambre);


                if (query.exec()) {
                    db.close();
                    return "Réservation ajoutée avec succès";
                } else {
                    db.close();
                    return "Erreur lors de la mise à jour de l'état de la chambre : " + query.lastError().text();
                }
            } else {
                db.close();
                return "Erreur lors de l'ajout de la réservation : " + query.lastError().text();
            }
        } else {
            db.close();
            return "Aucun enregistrement trouvé pour idchambre : " + QString::number(idchambre);
        }
    } else {
        db.close();
        return "La chambre est occupée";
    }
}

QStringList Reserver::obtenirTousLesReserver()

{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/pc/OneDrive/Documents/untitled/ma_base_de_donnees.sqlite");

        if (!db.open()) {
            qDebug() << "base de donnee not open " ;
        }
    QStringList listeClients;

       QSqlQuery query("SELECT * FROM Reservation");

       if (query.exec()) {
           while (query.next()) {
               // Récupérez les données de chaque client depuis la base de données
               QString idClient = query.value("idreservation").toString();
               QString nom = query.value("idclient").toString();
               QString prenom = query.value("idchambre").toString();
               QString email = query.value("dateDebut").toString();
               QString numerotelephone = query.value("dateFin").toString();
                QString nombrejour = query.value("nombredejour").toString();
                QString mantont = query.value("mantonttotale").toString();
               // Créez une chaîne de caractères représentant le client
               QString clientString = QString("%1, %2, %3, %4, %5, %6, %7")
                                           .arg(idClient)
                                           .arg(nom)
                                           .arg(prenom)
                                           .arg(email)
                                           .arg(numerotelephone)
                                            .arg(nombrejour)
                                            .arg(mantont);
               // Ajoutez la chaîne de caractères à la liste
               listeClients.append(clientString);
           }
       } else {
           qDebug() << "Erreur lors de la récupération des Reservations: " << query.lastError().text();
       }

       return listeClients;
}


QString Reserver::supprimerReservation(const int& idreservation)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/pc/OneDrive/Documents/untitled/ma_base_de_donnees.sqlite");

    if (!db.open()) {
        return "Erreur de connexion à la base de données: " + db.lastError().text();
    }

    QSqlQuery query;

    // Récupérer l'idchambre associé à la réservation
    query.prepare("SELECT idchambre FROM reservation WHERE idreservation = :idreservation");
    query.bindValue(":idreservation", idreservation);

    if (!query.exec() || !query.next()) {
        db.close();
        return "Erreur lors de la récupération de l'idchambre associé à la réservation : " + query.lastError().text();
    }

    int idchambre = query.value("idchambre").toInt();

    // Vérifier si d'autres réservations existent pour la même chambre
    query.prepare("SELECT COUNT(*) AS count FROM reservation WHERE idchambre = :idchambre");
    query.bindValue(":idchambre", idchambre);

    if (!query.exec() || !query.next()) {
        db.close();
        return "Erreur lors de la vérification des réservations pour la chambre : " + query.lastError().text();
    }

    int countReservations = query.value("count").toInt();

    if (countReservations != 0) {
        // Aucune autre réservation pour cette chambre, mettre à jour la colonne estoccupee à 'Non'
        query.prepare("UPDATE chambre SET estoccupee = 'Non' WHERE idchambre = :idchambre");
        query.bindValue(":idchambre", idchambre);

        if (!query.exec()) {
            db.close();
            return "Erreur lors de la mise à jour de la chambre : " + query.lastError().text();
        }
    }

    // Supprimer la réservation
    query.prepare("DELETE FROM reservation WHERE idreservation = :idreservation");
    query.bindValue(":idreservation", idreservation);

    if (query.exec()) {
        db.close();
        return "Reservation supprimé avec succès.";
    } else {
        db.close();
        return "Erreur lors de la suppression du Reservation : " + query.lastError().text();
    }
}

