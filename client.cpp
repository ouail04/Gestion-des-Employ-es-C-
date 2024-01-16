#include "client.h"
#include "mainwindow.h"
#include <QtSql>
#include <QLabel>
#include <QVBoxLayout>
Client::Client(const QString& nom,const QString& prenom,const QString& email,const QString& numerotelephone, const QString& CNIE)
    : Personne(nom,prenom,email,numerotelephone, CNIE)
{

}
QString Client::ajouterClient() const
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/pc/OneDrive/Documents/untitled/ma_base_de_donnees.sqlite");

        if (!db.open()) {
            return "Erreur de connexion à la base de données: " + db.lastError().text();
        }

        QSqlQuery query;


       // Assurez-vous que l'ID de la chambre existe dans la table "chambre"

        QString sql = "INSERT INTO client (nom, prenom, email, numerotelephone, cnie) "
                      "VALUES (:nom, :prenom, :email, :numerotelephone, :cnie)";

        query.prepare(sql);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":email", email);
        query.bindValue(":numerotelephone", numerotelephone);
        query.bindValue(":cnie", CNIE);

        if (query.exec()) {
            return "Client ajouté avec succès";
        } else {
            return "Erreur lors de l'ajout du client: " +query.lastError().text();
        }
        db.close();
}

QStringList Client::obtenirTousLesClients()

{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/pc/OneDrive/Documents/untitled/ma_base_de_donnees.sqlite");

        if (!db.open()) {
            qDebug() << "base de donnee not open " ;
        }
    QStringList listeClients;

       QSqlQuery query("SELECT * FROM client");

       if (query.exec()) {
           while (query.next()) {
               // Récupérez les données de chaque client depuis la base de données
               QString idClient = query.value("idclient").toString();
               QString nom = query.value("nom").toString();
               QString prenom = query.value("prenom").toString();
               QString email = query.value("email").toString();
               QString numerotelephone = query.value("numerotelephone").toString();
               QString cnie = query.value("cnie").toString();
               QString idChambre = query.value("idchambre").toString();

               // Créez une chaîne de caractères représentant le client
               QString clientString = QString("%1, %2, %3, %4, %5, %6")
                                           .arg(idClient)
                                           .arg(nom)
                                           .arg(prenom)
                                           .arg(email)
                                           .arg(numerotelephone)
                                           .arg(cnie);

               // Ajoutez la chaîne de caractères à la liste
               listeClients.append(clientString);
           }
       } else {
           qDebug() << "Erreur lors de la récupération des clients: " << query.lastError().text();
       }

       return listeClients;
}
QString Client::getNom()
{
    return nom;
}
QString Client::getPrenom()
{
    return prenom;
}
QString Client::getEmail()
{
    return email;
}
QString Client::getNumeroTelephone()
{
    return numerotelephone;
}
QString Client::getCine()
{
    return CNIE;
}
QStringList Client::obtenirTousLesClientsCondition(const QString &str)

{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/pc/OneDrive/Documents/untitled/ma_base_de_donnees.sqlite");

        if (!db.open()) {
            qDebug() << "base de donnee not open " ;
        }
    QStringList listeClients;

       QSqlQuery query("SELECT * FROM client where CNIE = '"+str+"'");

       if (query.exec()) {
           while (query.next()) {
               // Récupérez les données de chaque client depuis la base de données
               QString idClient = query.value("idclient").toString();
               QString nom = query.value("nom").toString();
               QString prenom = query.value("prenom").toString();
               QString email = query.value("email").toString();
               QString numerotelephone = query.value("numerotelephone").toString();
               QString cnie = query.value("cnie").toString();

               // Créez une chaîne de caractères représentant le client
               QString clientString = QString("%1, %2, %3, %4, %5, %6")
                                           .arg(idClient)
                                           .arg(nom)
                                           .arg(prenom)
                                           .arg(email)
                                           .arg(numerotelephone)
                                           .arg(cnie);

               // Ajoutez la chaîne de caractères à la liste
               listeClients.append(clientString);
           }
       } else {
           qDebug() << "Erreur lors de la récupération des clients: " << query.lastError().text();
       }

       return listeClients;
}
QString Client::supprimerClient(const QString& CNIE)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/pc/OneDrive/Documents/untitled/ma_base_de_donnees.sqlite");

    if (!db.open()) {
        return "Erreur de connexion à la base de données: " + db.lastError().text();
    }

    QSqlQuery query;

    // Assurez-vous que votre table a une colonne "CNIE" pour identifier le client à supprimer
    QString queryStr = "DELETE FROM client WHERE cnie = :cnie";
    query.prepare(queryStr);
    query.bindValue(":cnie", CNIE);

    if (query.exec()) {
        db.close();  // Fermez la connexion après l'exécution de la requête
        return "Client supprimé avec succès.";
    } else {
        db.close();  // Fermez la connexion en cas d'erreur
        return "Erreur lors de la suppression du client : " + query.lastError().text();
    }
}
