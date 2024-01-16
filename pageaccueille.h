#ifndef PAGEACCUEILLE_H
#define PAGEACCUEILLE_H

#include <QMainWindow>

namespace Ui {
class PageAccueille;
}

class PageAccueille : public QMainWindow
{
    Q_OBJECT

public:
    explicit PageAccueille(QWidget *parent = nullptr);
    ~PageAccueille();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::PageAccueille *ui;
};

#endif // PAGEACCUEILLE_H
