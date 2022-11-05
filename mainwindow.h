#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gestion_de_vole.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pushButton_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    gestion_de_vole V;
};

#endif // MAINWINDOW_H
