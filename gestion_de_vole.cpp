#include "gestion_de_vole.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

gestion_de_vole::gestion_de_vole()
{
id=0; destination=" "; temps=0;
}
gestion_de_vole::gestion_de_vole(int id,QString destination,int temps)
{this->id=id;this->destination=destination;this->temps=temps;}
int gestion_de_vole::getid(){return id;}
QString gestion_de_vole::getdestination(){return destination;}
int gestion_de_vole::gettemps(){return temps;}
void gestion_de_vole::setid(int id){this->id=id;}
void gestion_de_vole::setdestination(QString destination){this->destination=destination;}
void gestion_de_vole::settemps(int temps){this->temps=temps;}
bool  gestion_de_vole:: ajouter(){

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString temps_string=QString::number(temps);
    query.prepare("INSERT INTO gestion_de_vole (id, destination, temps) "
                  "VALUES (:id, :forename, :temps)");
    query.bindValue(":id", id_string);
    query.bindValue(":forename", destination);
    query.bindValue(":temps", temps_string);
    return query.exec();


    //return test;
}
bool gestion_de_vole::supprimer(int id)
{
    QSqlQuery query;
    query.prepare(" Delete from gestion_de_vole where id=:id");
    query.bindValue(0, id);

    return query.exec();
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
