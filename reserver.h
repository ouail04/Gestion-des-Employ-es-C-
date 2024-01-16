#ifndef RESERVER_H
#define RESERVER_H
#include <QString>

class Reserver
{
public:
    Reserver();
    static QString ajouterReservation(const QString &,int &,const QString &,const QString &,const int& );
    static QStringList obtenirTousLesReserver();
    static QString supprimerReservation(const int& idreservation);

};

#endif // RESERVER_H
