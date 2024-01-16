#ifndef EMPLOYE_H
#define EMPLOYE_H
#include "personne.h"

class Employe : public Personne
{
public:
    Employe(const QString& ="" ,const QString& ="",const QString& ="",const QString& ="" , const QString& CNIE ="",const QString & ="",const QString& ="",const double& =0.0);
    QString ajouterClient() const;
    static QStringList obtenirTousLesEmploye();
    static QString supprimerEmployes(const QString& CNIE);
    static QStringList obtenirTousLesEmployeCondition(const QString &str);
private :
    QString poste,password;
    double salaire;
};

#endif // EMPLOYE_H
