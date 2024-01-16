#include "pageaccueille.h"
#include "ui_pageaccueille.h"
#include "gestionemploye.h"
#include "mainwindow.h"
#include "gestionchambre.h"
#include "reservation.h"

PageAccueille::PageAccueille(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PageAccueille)
{
    ui->setupUi(this);
}

PageAccueille::~PageAccueille()
{
    delete ui;
}

void PageAccueille::on_pushButton_clicked()
{
        hide();
        GestionEmploye *emp = new GestionEmploye;
        emp->show();  // Affichez la fenêtre GestionEmploye

}


void PageAccueille::on_pushButton_3_clicked()
{
    hide();
    MainWindow *windo = new MainWindow();
    windo->show();
}
void PageAccueille::on_pushButton_5_clicked()
{
    hide();
    Reservation *w= new Reservation();
    w->show();
}



void PageAccueille::on_pushButton_6_clicked()
{
    hide();
    GestionChambre *w = new GestionChambre(); ;
    w->show();
}

