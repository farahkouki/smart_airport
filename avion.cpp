#include "avion.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlRecord>

avion::avion()
{
id=0; nom="";type="";
}
avion::avion(int id,QString nom,QString type)
{
    this->id=id;this->nom=nom;this->type=type;}
    int avion ::getid(){return id;};
    QString avion:: getnom(){return nom;}
    QString avion:: gettype(){return type;}
    void avion::setid(int id){this->id=id;}
    void avion::setnom(QString nom){this->nom=nom;}
    void avion::settype(QString type){this->type=type;
}
    bool avion::ajouter2()
    {

        QSqlQuery query;
        QString id_string=QString::number(id);
              query.prepare("INSERT INTO AVION (id, nom, type) "
                            "VALUES (:id, :forename, :surname)");
              query.bindValue(":id", id_string);
              query.bindValue(":forename", nom);
              query.bindValue(":surname", type);
              return query.exec();

    }
    bool avion::supprimer2(int id){
        QSqlQuery query;

              query.prepare(" Delete from AVION where id=:id");
              query.bindValue(0,id);
              return query.exec();
    }

     QSqlQueryModel* avion::afficher00()
    {
        QSqlQueryModel* model=new QSqlQueryModel();

              model->setQuery("SELECT* FROM AVION");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));


        return model ;
    }
     bool avion::recherche2(int id)
      {


            QSqlQuery query("SELECT * FROM AVION");
            QSqlQuery recherche("select * from AVION where  id = "+QString::number(id) );
             // query.prepare ("select * from AJOUTER where id="+QString::number(id));
              QSqlRecord test = recherche.record();

              qDebug() << "Number of columns: " << test.count();

              int nameCol = test.indexOf("id"); // index of the field "name"
              while (recherche.next()){
                  qDebug() << recherche.value(nameCol).toString();
                  QString test= recherche.value(nameCol).toString();
              if (test!=""){query.exec("select from AVION where id="+QString::number(id));

                      return true;
                  }
                  return false;


      }
          return query.exec();


      }
     QSqlQueryModel* avion::afficher22()
      {
          QSqlQueryModel* model=new QSqlQueryModel();

               model->setQuery("select* from AVION where id="+QString::number(id));
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
               return model;

      }
      QSqlQueryModel* avion::tri2()
      {
          QSqlQueryModel* model=new QSqlQueryModel();

               model->setQuery("select* from AVION order by id ASC");
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));


          return model;
      }
