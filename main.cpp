#include "mainwindow.h"
#include "reservation.h"
#include "gestionchambre.h"
#include "gestionemploye.h"
#include "pageaccueille.h"
#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PageAccueille window;



    window.show();

    return a.exec();
}




