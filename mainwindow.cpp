#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_de_vole.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QPixmap>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/elyes/Documents/map1.jpg");
    ui->label_pic->setPixmap(pix);
    QPixmap pix1("C:/Users/elyes/Documents/map1.jpg");
    ui->label_pic1->setPixmap(pix1);
    QPixmap pix2("C:/Users/elyes/Documents/map1.jpg");
    ui->label_pic2->setPixmap(pix2);
    ui->le_id->setValidator( new QIntValidator(0, 9999999, this));
    ui->tab_gestion_de_vole->setModel(V.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::on_pb_ajouter_clicked()
{

    int id=ui->le_id->text().toInt();
    QString destination=ui->le_nom->text();
    int temps=ui->le_prenom->text().toInt();
    ui->tab_gestion_de_vole->setModel(V.afficher());
    gestion_de_vole V(id,destination,temps);
bool test=V.ajouter();
if(test)
    QMessageBox::information(nullptr, QObject::tr("ajout"),
                QObject::tr("ajout successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("ajout failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_clicked()
{
ui->tab_gestion_de_vole->setModel(V.afficher());
bool test=V.afficher();
if(test)
    QMessageBox::information(nullptr, QObject::tr("refesh"),
                QObject::tr("refresh successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("refresh failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pb_supprimer_clicked()
{

    gestion_de_vole V1; V1.setid(ui->le_id_supp->text().toInt());
    bool test=V1.supprimer(V1.getid());
    QMessageBox msgBox;
    if(test)

    msgBox.setText("suppression avec succees.");

        else

        msgBox.setText("echec de suppression.");
        msgBox.exec();


}


void MainWindow::on_pushButton_2_clicked()
{
    gestion_de_vole V1;
        V1.setid(ui->le_id->text().toInt());
        bool test=V1.supprimer(V1.getid());
        if(!test){
            QMessageBox::critical(nullptr, QObject::tr("nope"),
                        QObject::tr("update failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


        ui->tab_gestion_de_vole->setModel(V1.afficher());
        }
        else
        {   int id=ui->le_id->text().toInt();
            QString destination=ui->le_nom->text();
            int temps=ui->le_prenom->text().toInt();
      gestion_de_vole
              V(id , destination, temps);
      bool test1=V.ajouter();

      if(test1)


          QMessageBox::information(nullptr, QObject::tr("ok"),
                      QObject::tr("update successful.\n"
                                  "update effectuer."), QMessageBox::Cancel);


      else

          QMessageBox::critical(nullptr, QObject::tr("nope"),
                      QObject::tr("connection failed.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

