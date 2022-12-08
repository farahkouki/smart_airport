#include "event.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include<QSqlQueryModel>
#include<QSqlRecord>
#include<list>
#include<QSqlTableModel>
#include <vector>

#include <QPdfWriter>
//#include<qSort>

Event::Event()
{
    id=0;
    nom="";
    prenom="";
    nb =0;



}
int i=0;


Event::Event(int id,int nb,QString nom,QString prenom){
        this->id=id;
     this->nb=nb;
        this->nom=nom;
        this->prenom=prenom;


}
int Event:: getid(){
    return id;
}
int Event:: getnb(){
    return nb;
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
    QString nb_string=QString::number(nb);
     QString mv1=QString::number(mv);
    // QString mv11=QString::number(mv);

    query.prepare("INSERT INTO Etudiant (id, nom, prenom,nb) "
                  "VALUES (:id, :forename, :surname,:nb)");



    query.bindValue(":id", id_string);
      query.bindValue(":nb", nb_string);
    query.bindValue(":forename", nom);
    query.bindValue(":surname", prenom);


   return query.exec();


}


bool Event ::supprimer(int id){

    QSqlQuery query("SELECT * FROM Etudiant");
    QSqlQuery q("select * from Etudiant where  id = "+QString::number(id) );
      QSqlRecord rec = q.record();

      qDebug() << "Number of columns: " << rec.count();

      int nameCol = rec.indexOf("id"); // index of the field "name"
      while (q.next()){
          qDebug() << q.value(nameCol).toString();
          QString a= q.value(nameCol).toString();
          if(a!=""){query.exec( "Delete from  Etudiant where id = "+QString::number(id));
              return true;}
}

        return false ;


       }






QSqlQueryModel* Event :: afficher(){



 QSqlQueryModel* model=new QSqlQueryModel();


 model->setQuery("select  * from Etudiant ");
 model->setHeaderData(0, Qt::Horizontal,QObject:: tr("id"));
 model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
   model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));

 model->setHeaderData(3, Qt::Horizontal,QObject:: tr("nb"));
 return model;
}


bool Event ::chercher(int id){



    QSqlQuery q("select * from Etudiant where  id = "+QString::number(id) );
      QSqlRecord rec = q.record();

      qDebug() << "Number of columns: " << rec.count();

      int nameCol = rec.indexOf("id"); // index of the field "name"
      while (q.next()){

          qDebug() << q.value(nameCol).toString();
          QString a= q.value(nameCol).toString();
          if(a!=""){

                return true;

}
}
        return false;  }



QSqlQueryModel* Event :: afficher1(){



 QSqlQueryModel* model=new QSqlQueryModel();



 model->setQuery("select  * from Etudiant  where id="+QString::number(id));
 model->setHeaderData(0, Qt::Horizontal,QObject:: tr("id"));
 model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
   model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject:: tr("nb"));

 return model;
}

QSqlQueryModel* Event :: tree(){
 QSqlQueryModel* model=new QSqlQueryModel();


 model->setQuery("select  * from Etudiant  ORDER BY id");
 model->setHeaderData(0, Qt::Horizontal,QObject:: tr("id"));
 model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
   model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
model->setHeaderData(3, Qt::Horizontal,QObject:: tr("nb"));

 return model;



}
/*
void TextEdit::filePrint()
 {

 }


*/

