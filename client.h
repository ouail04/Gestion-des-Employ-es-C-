#ifndef CLIENT_H
#define CLIENT_H
#include "personne.h"
#include "mainwindow.h"

class Client : public Personne
{
public:
    Client(const QString& nom,const QString& prenom,const QString& email,const QString& numerotelephone, const QString& CNIE);
    QString ajouterClient() const;
    static QStringList obtenirTousLesClients();
    static QStringList obtenirTousLesClientsCondition(const QString &);
    static QString supprimerClient(const QString&) ;
    int getId() const;
    QString getNom();
    QString getPrenom();
    QString getEmail();
    QString getNumeroTelephone();
    QString getCine();
private :

};

#endif // CLIENT_H
