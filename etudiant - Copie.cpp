#include "etudiant.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include<QSqlQueryModel>


Event::Event()
{
    id=0;
    nom="";
    prenom="";



}
Event::Event(int id,QString nom,QString prenom){
    this->id=id;
        this->nom=nom;
        this->prenom=prenom;

}
int Event:: getid(){
    return id;
}
QString Event:: getnom () {
    return nom;
}
QString  Event::getprenom(){ return prenom;}
void Event:: setid(int id){
       this->id=id;
}
void Event:: setnom(QString nom){
     this->nom=nom;
}
void Event:: setprenom(QString prenom){
     this->prenom=prenom;
}
bool Event :: ajouter(){

    QSqlQuery query;
    QString id_string=QString::number(id);
    query.prepare("INSERT INTO Etudiant (id, nom, prenom) "
                  "VALUES (:id, :forename, :surname)");
    query.bindValue(":id", id_string);
    query.bindValue(":forename", nom);
    query.bindValue(":surname", prenom);
   return query.exec();


    //return test;
}
bool Event ::supprimer(int id){

    QSqlQuery query;

    query.prepare("Delete from Etudiant where id =:id  ");
    query.bindValue(0, id);

   return query.exec();





}
   QSqlQueryModel* Event :: afficher(){



    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("select  * from Etudiant ");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
      model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));


    return model;
}





