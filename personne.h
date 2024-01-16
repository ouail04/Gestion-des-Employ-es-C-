#ifndef PERSONNE_H
#define PERSONNE_H
#include <QString>


class Personne
{
public:
    Personne(const QString& = NULL,const QString& = NULL,const QString& = NULL,const QString& = NULL,const QString& = NULL);
    Personne();
    ~Personne();
   protected:
    QString nom,prenom,email,numerotelephone, CNIE;
};

#endif // PERSONNE_H
