#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <QStringList>

class Chambre
{
public:
    Chambre();
    static QStringList obtenirTousLesChambres();
    static QStringList obtenirTousLesChambresCondition(const QString &str);
};

#endif // CHAMBRE_H
