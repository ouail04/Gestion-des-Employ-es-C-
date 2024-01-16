#include "gestionemploye.h"
#include "ui_gestionemploye.h"
#include "employe.h"
#include"pageaccueille.h"

GestionEmploye::GestionEmploye(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GestionEmploye)
{
    ui->setupUi(this);
    afficherTousLesEmploye(ui->tableWidgetEmploye,Employe::obtenirTousLesEmploye());
}

GestionEmploye::~GestionEmploye()
{
    delete ui;
}

void GestionEmploye::on_pushButton_2_clicked()
{
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString CNIE = ui->CINE->text();
    QString numero = ui->telephone->text();
    QString email= ui->email->text();
    QString poste = ui->poste->text();
    QString aid = ui->salaire->text();
    double salaire = aid.toDouble();
    QString password = ui->password->text();
    Employe c(nom,prenom,email,numero,CNIE,poste,password,salaire);
    ui->conne->setText(c.ajouterClient());
}

void GestionEmploye::afficherTousLesEmploye(QTableWidget *tableWidget, const QStringList &listeClients)
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


void GestionEmploye::on_ButtonMise_clicked()
{
    afficherTousLesEmploye(ui->tableWidgetEmploye,Employe::obtenirTousLesEmploye());

}


void GestionEmploye::on_supprimerButton_2_clicked()
{
    // Récupérer le CNIE du client à supprimer depuis l'interface utilisateur
       QString CNIE = ui->messagesupprimer->text(); // Assurez-vous de remplacer cnieLineEdit par le nom réel de votre QLineEdit

       // Appeler la méthode de suppression du client en utilisant le CNIE comme paramètre
       QString resultatSuppression = Employe::supprimerEmployes(CNIE);
       // Mettre à jour l'interface utilisateur ou afficher un message en fonction du résultat
       ui->message_2->setText(resultatSuppression);

}


void GestionEmploye::on_chercher_clicked()
{
    QString str = ui->messagechercher->text();
    QStringList list = Employe::obtenirTousLesEmployeCondition(str);
    afficherTousLesEmploye(ui->tableWidgetEmploye_2,list);
}


void GestionEmploye::on_pushButton_clicked()
{
    hide();
    PageAccueille *w = new PageAccueille();
    w->show();
}

