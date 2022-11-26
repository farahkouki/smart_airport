#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "voyageur.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>
#include "QrCode.hpp"
#include<QDebug>

using namespace qrcodegen;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/farah kouki/Desktop/photo c++/map2.jpg");
    ui->label_pic->setPixmap(pix);
    ui->le_cin->setValidator( new QIntValidator(0,999,this));
    ui->tab_voyageur->setModel(v.afficher());
    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone);
int ret=A.connect_arduino();
switch(ret){
case(0):qDebug()<<"arduino is available and connected to:"<<A.getarduino_port_name();
    break;
    case(1):qDebug()<<"arduino is available but not connected to:"<<A.getarduino_port_name();
break;
case(-1):qDebug()<<"arduino is not available" ;

}
QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::addPoint(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
}

void MainWindow::clearData()
{
qv_x.clear();
qv_y.clear();
}

void MainWindow::plot()
{
    ui->plot->graph(0)->setData(qv_x,qv_y);
    ui->plot->replot();
    ui->plot->update();
}

void MainWindow::on_pb_ajouter_clicked()
{
    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    ui->tab_voyageur->setModel(v.afficher());
    voyageur v(cin,nom,prenom);


    bool test=v.ajouter();
     ui->tab_voyageur->setModel(v.afficher());
    if(test)
        QMessageBox::information(nullptr,QObject::tr("ajout"),
                                QObject::tr("ajout successful.\n"
                                            "click Cancel to exit."),QMessageBox::Cancel );
    else
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                QObject::tr("ajout failed.\n"
                                            "click Cancel to exit."),QMessageBox::Cancel );
    //QMessageBox msgBox;
  }

void MainWindow::on_pb_supprimer_clicked()
{
voyageur v1;
    v1.setcin(ui->le_id_supp->text().toInt());
    bool test=v1.supprimer(v1.getcin());
    QMessageBox msgBox;
    if(test)
       { msgBox.setText("suppression avec succes");
    ui->tab_voyageur->setModel(v.afficher());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();

}

void MainWindow::on_pb_tri_clicked()
{
     ui->tabletri->setModel(v1.tri());
}

void MainWindow::on_chercher_cin_clicked()
{
    v1.setcin(ui->line_cin->text().toInt());
    bool test=v1.rechercher(v1.getcin());
    ui->tablevoyageur->setModel(v1.afficher1());
    if(test)
        QMessageBox::information(nullptr,QObject::tr("recherche"),
                                QObject::tr("recherche successful.\n"
                                            "click Cancel to exit."),QMessageBox::Cancel );
    else
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                QObject::tr("recherche failed.\n"
                                            "click Cancel to exit."),QMessageBox::Cancel );

}

void MainWindow::on_pb_modifier_clicked()
{
      voyageur v1;

        int cin =ui->le_cin->text().toInt();

           QString nom =ui->le_nom->text();

           QString prenom =ui->le_prenom->text();

voyageur V (cin ,nom ,prenom);

    bool test=V.modifier(cin);

    ui->tab_voyageur->setModel(v1.afficher());

    if(test)

 {

        QMessageBox::information(nullptr, QObject::tr("SUCCESS"),

                    QObject::tr("update successful.\n"

                                "modifaction effectuer."), QMessageBox::Cancel);
 }

    else
   QMessageBox::critical(nullptr, QObject::tr("ERROR"),

                    QObject::tr("connection failed.\n"

                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
void MainWindow::on_pushButton_PDF_clicked()
{
    int i=0;int j=0;

   int id =ui->le_cin->text().toInt();

    QString cin_string=QString::number(id);

           QString nom =ui->le_nom->text();

            QString prenom =ui->le_prenom->text();


            QPdfWriter pdf("C:/Users/farah kouki/Desktop/Atelier_Connexion.pdf");

            QPainter painter (&pdf);

            painter.setPen(Qt::blue);

          //  painter.drawTabel

            painter.drawText(i,j,"cin:="+cin_string);

            painter.drawText(i+100,j+100,"nom:="+nom);

            painter.drawText(i+100,j+200,"prenom:="+prenom);

}

void MainWindow::on_btn_add_clicked()
{
addPoint(ui->bx_x->value(),ui->bx_y->value());
plot();
}

void MainWindow::on_btn_clear_clicked()
{
clearData();
plot();
}

void MainWindow::on_qrcodegen_clicked()
{
    int tabeq=ui->tab_voyageur->currentIndex().row();
           QVariant idd=ui->tab_voyageur->model()->data(ui->tab_voyageur->model()->index(tabeq,0));
           QString id= idd.toString();
           QSqlQuery qry;
           qry.prepare("select * from VOYAGEUR where CIN=:id");
           qry.bindValue(":CIN",id);
           qry.exec();
              QString  cin,nom,prenom;

           while(qry.next()){


               cin=qry.value(2).toString();
               nom=qry.value(3).toString();
               prenom=qry.value(4).toString();


           }

                  id="CIN:"+cin+"NOM:"+nom+"PRENOM:"+prenom;
           QrCode qr = QrCode::encodeText(id.toUtf8().constData(), QrCode::Ecc::HIGH);

           // Read the black & white pixels
           QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
           for (int y = 0; y < qr.getSize(); y++) {
               for (int x = 0; x < qr.getSize(); x++) {
                   int color = qr.getModule(x, y);  // 0 for white, 1 for black

                   // You need to modify this part
                   if(color==0)
                       im.setPixel(x, y,qRgb(254, 254, 254));
                   else
                       im.setPixel(x, y,qRgb(0, 0, 0));
               }
           }
           im=im.scaled(200,200);
           ui->qrcodecommande->setPixmap(QPixmap::fromImage(im));

}
void MainWindow::on_btn_imp_clicked()
{
    QString strStream;
                             QTextStream out(&strStream);

                             const int rowCount = ui->tab_voyageur->model()->rowCount();
                             const int columnCount = ui->tab_voyageur->model()->columnCount();
                             QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                             out <<"<html>\n"
                                   "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                 << "<title>ERP - COMmANDE LIST<title>\n "
                                 << "</head>\n"
                                 "<body bgcolor=#ffffff link=#5000A0>\n"
                                 "<h1 style=\"text-align: center;\"><strong> ******VOYAGEUR******"+TT+" </strong></h1>"
                                 "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                   "</br> </br>";
                             // headers
                             out << "<thead><tr bgcolor=#d6e5ff>";
                             for (int column = 0; column < columnCount; column++)
                                 if (!ui->tab_voyageur->isColumnHidden(column))
                                     out << QString("<th>%1</th>").arg(ui->tab_voyageur->model()->headerData(column, Qt::Horizontal).toString());
                             out << "</tr></thead>\n";

                             // data table
                             for (int row = 0; row < rowCount; row++) {
                                 out << "<tr>";
                                 for (int column = 0; column < columnCount; column++) {
                                     if (!ui->tab_voyageur->isColumnHidden(column)) {
                                         QString data =ui->tab_voyageur->model()->data(ui->tab_voyageur->model()->index(row, column)).toString().simplified();
                                         out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                     }
                                 }
                                 out << "</tr>\n";
                             }
                             out <<  "</table>\n"
                                 "</body>\n"
                                 "</html>\n";

                             QTextDocument *document = new QTextDocument();
                             document->setHtml(strStream);

                             QPrinter printer;

                             QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                             if (dialog->exec() == QDialog::Accepted) {
                                 document->print(&printer);
                             }

                             delete document;


}



void MainWindow::on_pushButton_clicked()
{
    A.write_to_arduino("0");
}

void MainWindow::on_pushButton_2_clicked()
{
    A.write_to_arduino("1");
}
void MainWindow::update_label()
{
    data=A.read_from_arduino();

if(data=="1")

       ui->label_10->setText("allumer"); // si les données reçues de arduino via la liaison série sont égales à 1
   // alors afficher allumer

   else if (data=="0")

       ui->label_10->setText("clignoter");   // si les données reçues de arduino via la liaison série sont égales à 0
    //alors afficher clignoter
}
