#include "gestionchambre.h"
#include "ui_gestionchambre.h"
#include "pageaccueille.h"
#include "chambre.h"

GestionChambre::GestionChambre(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GestionChambre)
{
    ui->setupUi(this);
    afficherTousLesChambres(ui->tableWidgetClients,Chambre::obtenirTousLesChambres());
}

GestionChambre::~GestionChambre()
{
    delete ui;
}
void GestionChambre::afficherTousLesChambres(QTableWidget *tableWidget, const QStringList &listeClients)
{
    // Effacez le contenu actuel du tableau
    tableWidget->clearContents();
    tableWidget->setRowCount(0);

    if (!listeClients.isEmpty()) {
        // Divisez la première ligne pour déterminer le nombre de colonnes
        QStringList premierClient = listeClients.first().split(", ");
        int nombreColonnes = premierClient.size();

        // Assurez-vous que le nombre de colonnes dans le tableau est correct
        if (tableWidget->columnCount() != nombreColonnes) {
            tableWidget->setColumnCount(nombreColonnes);
        }

        // Ajustez le nombre de lignes du tableau
        tableWidget->setRowCount(listeClients.size());

        // Parcourez la liste de clients et ajoutez-les au tableau
        for (int row = 0; row < listeClients.size(); row++) {
            // Divisez la chaîne du client en colonnes
            QStringList colonnes = listeClients[row].split(", ");

            // Ajoutez les données aux cellules de la ligne
            for (int col = 0; col < nombreColonnes; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(colonnes[col]);
                tableWidget->setItem(row, col, item);
            }
        }
    }
}

void GestionChambre::on_ButtonMise_clicked()
{
    afficherTousLesChambres(ui->tableWidgetClients,Chambre::obtenirTousLesChambres());
}


void GestionChambre::on_ButtonChercher_clicked()
{
    QString str = ui->CNIECherche->text();
    afficherTousLesChambres(ui->tableWidgetClients_2,Chambre::obtenirTousLesChambresCondition(str));
}


void GestionChambre::on_pushButton_clicked()
{
    hide();
    PageAccueille *w = new PageAccueille();
    w->show();
}

