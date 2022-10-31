#include "etudiant.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>


etudiant::etudiant()
{
id=0; nom=" "; prenom=" ";
}

etudiant::etudiant(int id,QString nom,QString prenom)
{this->id=id;this->nom=nom;this->prenom=prenom;}
int etudiant::getid(){return id;}
QString etudiant::getnom(){return nom;}
QString etudiant::getprenom(){return prenom;}
void etudiant::setid(int id){this->id=id;}
void etudiant::setnom(QString nom){this->nom=nom;}
void etudiant::setprenom(QString prenom){this->prenom=prenom;}


bool etudiant :: ajouter(){

    QSqlQuery query;
    QString id_string=QString::number(id);
    query.prepare("INSERT INTO etudiant (id, nom, prenom) "
                  "VALUES (:id, :forename, :surname)");
    query.bindValue(":id", id_string);
    query.bindValue(":forename", nom);
    query.bindValue(":surname", prenom);
    return query.exec();


    //return test;
}
bool gestion_de_vole::supprimer(int id)
{
    QSqlQuery query;
    query.prepare(" Delete from etudiant where id=:id");
    query.bindValue(0, id);

    return query.exec();
}
QSqlQueryModel* gestion_de_vole::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("select* from etudiant");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));


    return model;
}
