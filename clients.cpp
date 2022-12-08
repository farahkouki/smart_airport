#include "clients.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>

Clients::Clients()
{
id=0; nom=""; prenom=""; ad_mail=""; num_tlf="";adresse="";
}
Clients::Clients(int id,QString nom,QString prenom,QString ad_mail,QString num_tlf,QString adresse)
{this->id= id; this->nom= nom; this->prenom= prenom; this->ad_mail= ad_mail; this->num_tlf= num_tlf;this->adresse=adresse;}
int Clients::getid(){return id;}
QString Clients::getnom(){return nom;}
QString Clients::getprenom(){return prenom;}
QString Clients::getad_mail(){return ad_mail;}
QString Clients::getnum_tlf(){return num_tlf;}
QString Clients::getadresse(){return adresse;}
void Clients::setid(int id){this->id=id;}
void Clients::setnom(QString nom){this->nom= nom;}
void Clients::setprenom(QString prenom){this->prenom= prenom;}
void Clients::setad_mail(QString ad_mail){this->ad_mail= ad_mail;}
void Clients::setnum_tlf(QString num_tlf){this->num_tlf= num_tlf;}
void Clients::setadresse(QString adresse){this->adresse= adresse;}
bool Clients :: ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    query.prepare("INSERT INTO Clients (id, nom, prenom, ad_mail, num_tlf, adresse) "
                  "VALUES (:id, :forename, :surname, :email, :tlf, :adress)");
    query.bindValue(":id", id_string);
    query.bindValue(":forename", nom);
    query.bindValue(":surname", prenom);
    query.bindValue(":email", ad_mail);
    query.bindValue(":tlf", num_tlf);
    query.bindValue(":adress", adresse);
   return query.exec();


    //return test;
}
bool Clients ::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from Clients where id =:id  ");
    query.bindValue(0, id);
   return query.exec();
}

  QSqlQueryModel* Clients ::afficher()
   {

   QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("select  * from Clients ");
    model->setHeaderData(0, Qt::Horizontal,QObject:: tr("id"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("ad_mail"));
    model->setHeaderData(4, Qt::Horizontal,QObject:: tr("num_tlf"));
    model->setHeaderData(5, Qt::Horizontal,QObject:: tr("adresse"));


    return model;
}


  QSqlQueryModel * Clients::recherche(int id)
  {

      QSqlQueryModel* model=new QSqlQueryModel();

      model->setQuery("select  * from Clients where  id = "+QString::number(id));
      model->setHeaderData(0, Qt::Horizontal,QObject:: tr("id"));
      model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
      model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
      model->setHeaderData(3, Qt::Horizontal,QObject:: tr("ad_mail"));
      model->setHeaderData(4, Qt::Horizontal,QObject:: tr("num_tlf"));
      model->setHeaderData(5, Qt::Horizontal,QObject:: tr("adresse"));
      return model;
  }

  QSqlQueryModel * Clients::rechercher(QString nom)
          {
             QSqlQueryModel * model = new QSqlQueryModel();
             model->setQuery("select * from Clients where nom = " + nom);
             model->setHeaderData(0, Qt::Horizontal,QObject:: tr("id"));
             model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
             model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
             model->setHeaderData(3, Qt::Horizontal,QObject:: tr("ad_mail"));
             model->setHeaderData(4, Qt::Horizontal,QObject:: tr("num_tlf"));
             model->setHeaderData(5, Qt::Horizontal,QObject:: tr("adresse"));
             return model;
          }



  QSqlQueryModel * Clients::triid_croissant()
          {
              QSqlQueryModel * model= new QSqlQueryModel();
                  model->setQuery("SELECT * FROM Clients ORDER BY id ASC");
                  model->setHeaderData(0, Qt::Horizontal,QObject:: tr("id"));
                  model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
                  model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
                  model->setHeaderData(3, Qt::Horizontal,QObject:: tr("ad_mail"));
                  model->setHeaderData(4, Qt::Horizontal,QObject:: tr("num_tlf"));
                  model->setHeaderData(5, Qt::Horizontal,QObject:: tr("adresse"));
                  return model;
          }

  QSqlQueryModel * Clients::trinom_croissant()
  {
          QSqlQueryModel * model= new QSqlQueryModel();
          model->setQuery("SELECT * FROM Clients ORDER BY nom ASC");
          model->setHeaderData(0, Qt::Horizontal,QObject:: tr("id"));
          model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
          model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal,QObject:: tr("ad_mail"));
          model->setHeaderData(4, Qt::Horizontal,QObject:: tr("num_tlf"));
          model->setHeaderData(5, Qt::Horizontal,QObject:: tr("adresse"));

             return model;
  }

  QSqlQueryModel * Clients::triid_decroissant()
          {
              QSqlQueryModel * model= new QSqlQueryModel();
                  model->setQuery("SELECT * FROM Clients ORDER BY id DESC");
                  model->setHeaderData(0, Qt::Horizontal,QObject:: tr("id"));
                  model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
                  model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
                  model->setHeaderData(3, Qt::Horizontal,QObject:: tr("ad_mail"));
                  model->setHeaderData(4, Qt::Horizontal,QObject:: tr("num_tlf"));
                  model->setHeaderData(5, Qt::Horizontal,QObject:: tr("adresse"));
                  return model;
          }

  QSqlQueryModel * Clients::trinom_decroissant()
          {
              QSqlQueryModel * model= new QSqlQueryModel();
                  model->setQuery("SELECT * FROM Clients ORDER BY nom ASC");
                  model->setHeaderData(0, Qt::Horizontal,QObject:: tr("id"));
                  model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
                  model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));
                  model->setHeaderData(3, Qt::Horizontal,QObject:: tr("ad_mail"));
                  model->setHeaderData(4, Qt::Horizontal,QObject:: tr("num_tlf"));
                  model->setHeaderData(5, Qt::Horizontal,QObject:: tr("adresse"));
                  return model;
          }
