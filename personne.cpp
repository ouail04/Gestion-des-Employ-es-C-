#include "personne.h"

Personne::Personne(const QString&nom_,const QString&prenom_,const QString&email_,const QString&numerotelephone_,const QString& CNIE_ )
{
     nom = nom_ ; prenom = prenom_ ; email = email_ ; numerotelephone = numerotelephone_; CNIE = CNIE_;
}
Personne::~Personne()
{

}
