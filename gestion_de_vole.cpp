#include "gestion_de_vole.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <vector>
#include <QSortFilterProxyModel>
#include <QCalendarWidget>
#include <QDate>
#include <QApplication>
#include <QTextBrowser>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QDateTimeEdit>
#include <QVBoxLayout>
#include <QTextLayout>
#include <QTextTableCell>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QtCharts>








gestion_de_vole::gestion_de_vole()
{
id=0; destination=" "; temps=" ";
}
gestion_de_vole::gestion_de_vole(int id,QString destination,QString temps)
{this->id=id;this->destination=destination;this->temps=temps;}
int gestion_de_vole::getid(){return id;}
QString gestion_de_vole::getdestination(){return destination;}
QString gestion_de_vole::gettemps(){return temps;}
void gestion_de_vole::setid(int id){this->id=id;}
void gestion_de_vole::setdestination(QString destination){this->destination=destination;}
void gestion_de_vole::settemps(QString temps){this->temps=temps;}
bool  gestion_de_vole:: ajouter(){

    QSqlQuery query;
    QString id_string=QString::number(id);
    query.prepare("INSERT INTO gestion_de_vole (id, destination, temps) "
                  "VALUES (:id, :forename, :surname)");
    query.bindValue(":id", id_string);
    query.bindValue(":forename", destination);
    query.bindValue(":surname", temps);
    return query.exec();


    //return test;
}
bool gestion_de_vole::supprimer(int id)
{

    QSqlQuery query("SELECT * FROM gestion_de_vole");
    QSqlQuery supp("select * from gestion_de_vole where  id = "+QString::number(id) );
    QSqlRecord rec = supp.record();

    qDebug() << "Number of columns: " << rec.count();

    int nameCol = rec.indexOf("id"); // index of the field "name"
    while (supp.next()){
        qDebug() << supp.value(nameCol).toString();
        QString test= supp.value(nameCol).toString();

    if(test!=""){query.exec( "Delete from gestion_de_vole  where id = "+QString::number(id));
        return true;}
}

  return false ;




}
QSqlQueryModel* gestion_de_vole::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("select* from gestion_de_vole");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Destination"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Temps"));


    return model;
}
bool gestion_de_vole::rechercher(int id)
{


      QSqlQuery query("SELECT * FROM gestion_de_vole");
      QSqlQuery recherche("select * from gestion_de_vole where  id = "+QString::number(id) );
       // query.prepare ("select * from getion_de_vole where id="+QString::number(id));
        QSqlRecord rec = recherche.record();

        qDebug() << "Number of columns: " << rec.count();

        int nameCol = rec.indexOf("id"); // index of the field "name"
        while (recherche.next()){
            qDebug() << recherche.value(nameCol).toString();
            QString test= recherche.value(nameCol).toString();
        if (test!=""){query.exec("select from gestion_de_vole where id="+QString::number(id));

                return true;
            }
            return false;


}
    return query.exec();


}

QSqlQueryModel* gestion_de_vole::afficher1()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("select* from gestion_de_vole where id="+QString::number(id));
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Destination"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Temps"));
         return model;

}

QSqlQueryModel* gestion_de_vole::tri()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("select* from gestion_de_vole order by id ASC");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Destination"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Temps"));


    return model;
}
