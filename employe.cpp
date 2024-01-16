#include "employe.h"
#include "mainwindow.h"
#include <QtSql>
#include <QLabel>
#include <QVBoxLayout>
Employe::Employe(const QString& nom_,const QString& prenom_,const QString& email_,const QString& numerotelephone_, const QString& CNIE_,const QString & poste_,const QString& password_,const double & salaire_)
    :Personne(nom_,prenom_,email_,numerotelephone_,CNIE_)
{
    poste = poste_; password = password_; salaire = salaire_;

}
QString Employe::ajouterClient() const
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/pc/OneDrive/Documents/untitled/ma_base_de_donnees.sqlite");

        if (!db.open()) {
            return "Erreur de connexion à la base de données: " + db.lastError().text();
        }

        QSqlQuery query;


       // Assurez-vous que l'ID de la chambre existe dans la table "chambre"

        QString sql = "INSERT INTO employe (nom, prenom, email, numerotelephone, cnie,poste,salaire,password) "
                      "VALUES (:nom, :prenom, :email, :numerotelephone, :cnie,:poste,:salaire,:password)";

        query.prepare(sql);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":email", email);
        query.bindValue(":numerotelephone", numerotelephone);
        query.bindValue(":cnie", CNIE);
        query.bindValue(":poste", poste);
        query.bindValue(":salaire", salaire);
        query.bindValue(":password", password);

        if (query.exec()) {
            return "Employe ajouté avec succès";
        } else {
            return "Erreur lors de l'ajout du Employe: " +query.lastError().text();
        }
        db.close();
}
QStringList Employe::obtenirTousLesEmploye()

{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/pc/OneDrive/Documents/untitled/ma_base_de_donnees.sqlite");

        if (!db.open()) {
            qDebug() << "base de donnee not open " ;
        }
    QStringList listeClients;

       QSqlQuery query("SELECT * FROM employe");

       if (query.exec()) {
           while (query.next()) {
               // Récupérez les données de chaque client depuis la base de données
               QString idClient = query.value("idemploye").toString();
               QString nom = query.value("nom").toString();
               QString prenom = query.value("prenom").toString();
               QString email = query.value("email").toString();
               QString numerotelephone = query.value("numerotelephone").toString();
               QString cnie = query.value("cnie").toString();
               QString poste = query.value("poste").toString();
               QString salaire = query.value("salaire").toString();
               QString password = query.value("password").toString();

               // Créez une chaîne de caractères représentant le client
               QString clientString = QString("%1, %2, %3, %4, %5, %6, %7, %8, %9")
                                           .arg(idClient)
                                           .arg(nom)
                                           .arg(prenom)
                                           .arg(email)
                                           .arg(numerotelephone)
                                           .arg(cnie)
                                           .arg(poste)
                                           .arg(salaire)
                                           .arg(password);

               // Ajoutez la chaîne de caractères à la liste
               listeClients.append(clientString);
           }
       } else {
           qDebug() << "Erreur lors de la récupération des clients: " << query.lastError().text();
       }

       return listeClients;
}

QString Employe::supprimerEmployes(const QString& CNIE)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/pc/OneDrive/Documents/untitled/ma_base_de_donnees.sqlite");


    if (!db.open()) {
        return "Erreur de connexion à la base de données: " + db.lastError().text();
    }

    QSqlQuery query;

    // Assurez-vous que votre table a une colonne "CNIE" pour identifier le client à supprimer
    QString queryStr = "DELETE FROM employe WHERE cnie = :cnie";
    query.prepare(queryStr);
    query.bindValue(":cnie", CNIE);

    if (query.exec()) {
        db.close();  // Fermez la connexion après l'exécution de la requête
        return "Employe supprimé avec succès.";
    } else {
        db.close();  // Fermez la connexion en cas d'erreur
        return "Erreur lors de la suppression du Employe : " + query.lastError().text();
    }
}
QStringList Employe::obtenirTousLesEmployeCondition(const QString &str)

{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/pc/OneDrive/Documents/untitled/ma_base_de_donnees.sqlite");

        if (!db.open()) {
            qDebug() << "base de donnee not open " ;
        }
    QStringList listeClients;

       QSqlQuery query("SELECT * FROM employe where cnie ='"+str+"'");

       if (query.exec()) {
           while (query.next()) {
               // Récupérez les données de chaque client depuis la base de données
               QString idClient = query.value("idemploye").toString();
               QString nom = query.value("nom").toString();
               QString prenom = query.value("prenom").toString();
               QString email = query.value("email").toString();
               QString numerotelephone = query.value("numerotelephone").toString();
               QString cnie = query.value("cnie").toString();
               QString poste = query.value("poste").toString();
               QString salaire = query.value("salaire").toString();
               QString password = query.value("password").toString();

               // Créez une chaîne de caractères représentant le client
               QString clientString = QString("%1, %2, %3, %4, %5, %6, %7, %8, %9")
                                           .arg(idClient)
                                           .arg(nom)
                                           .arg(prenom)
                                           .arg(email)
                                           .arg(numerotelephone)
                                           .arg(cnie)
                                           .arg(poste)
                                           .arg(salaire)
                                           .arg(password);

               // Ajoutez la chaîne de caractères à la liste
               listeClients.append(clientString);
           }
       } else {
           qDebug() << "Erreur lors de la récupération des clients: " << query.lastError().text();
       }

       return listeClients;
}
