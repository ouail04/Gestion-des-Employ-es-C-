#include "chambre.h"
#include "mainwindow.h"
#include <QtSql>
#include <QLabel>
#include <QVBoxLayout>
Chambre::Chambre()
{

}
QStringList Chambre::obtenirTousLesChambres()

{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/pc/OneDrive/Documents/untitled/ma_base_de_donnees.sqlite");

        if (!db.open()) {
            qDebug() << "base de donnee not open " ;
        }
    QStringList listeClients;

       QSqlQuery query("SELECT * FROM chambre");

       if (query.exec()) {
           while (query.next()) {
               // Récupérez les données de chaque client depuis la base de données
               QString idChambre = query.value("idchambre").toString();
               QString type = query.value("type").toString();
               QString capacite = query.value("capacite").toString();
               QString estoccupee = query.value("estoccupee").toString();
               QString montant = query.value("montant").toString();

               // Créez une chaîne de caractères représentant le client
               QString clientString = QString("%1, %2, %3, %4, %5")
                                           .arg(idChambre)
                                           .arg(type)
                                           .arg(capacite)
                                           .arg(estoccupee)
                                           .arg(montant);

               // Ajoutez la chaîne de caractères à la liste
               listeClients.append(clientString);
           }
       } else {
           qDebug() << "Erreur lors de la récupération des clients: " << query.lastError().text();
       }

       return listeClients;
}

QStringList Chambre::obtenirTousLesChambresCondition(const QString &str)

{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/pc/OneDrive/Documents/untitled/ma_base_de_donnees.sqlite");

        if (!db.open()) {
            qDebug() << "base de donnee not open " ;
        }
    QStringList listeClients;

       QSqlQuery query("SELECT * FROM chambre where type ='"+str+"'");

       if (query.exec()) {
           while (query.next()) {
               // Récupérez les données de chaque client depuis la base de données
               QString idChambre = query.value("idchambre").toString();
               QString type = query.value("type").toString();
               QString capacite = query.value("capacite").toString();
               QString estoccupee = query.value("estoccupee").toString();
               QString montant = query.value("montant").toString();

               // Créez une chaîne de caractères représentant le client
               QString clientString = QString("%1, %2, %3, %4, %5")
                                           .arg(idChambre)
                                           .arg(type)
                                           .arg(capacite)
                                           .arg(estoccupee)
                                           .arg(montant);

               // Ajoutez la chaîne de caractères à la liste
               listeClients.append(clientString);
           }
       } else {
           qDebug() << "Erreur lors de la récupération des clients: " << query.lastError().text();
       }

       return listeClients;
}
