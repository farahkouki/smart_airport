 #include"voyageur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlRecord>

voyageur::voyageur()
{
cin=0; nom="";prenom="";
}
voyageur::voyageur(int cin,QString nom,QString prenom)
{

this->cin=cin;this->nom=nom;this->prenom=prenom;}
int voyageur ::getcin(){return cin;};
QString voyageur:: getnom(){return nom;}
QString voyageur:: getprenom(){return prenom;}
void voyageur::setcin(int cin){this->cin=cin;}
void voyageur::setnom(QString nom){this->nom=nom;}
void voyageur::setprenom(QString prenom){this->prenom=prenom;}
bool voyageur::ajouter()
{
    bool test=false;
    QSqlQuery query;
    QString cin_string=QString::number(cin);
    QString id_string=QString::number(cin);
          query.prepare("INSERT INTO voyageur (cin, nom, prenom) "
                        "VALUES (:id, :forename, :surname)");
          query.bindValue(":id", cin_string);
          query.bindValue(":forename", prenom);
          query.bindValue(":surname", nom);
          return query.exec();
    return test ;
}
bool voyageur :: modifier(int cin){

       QSqlQuery query;


       query.prepare("UPDATE voyageur set  cin=:cin,nom=:nom,prenom=:prenom where cin=:cin");
       query.bindValue(":cin", cin);
       query.bindValue(":prenom", prenom);
       query.bindValue(":nom", nom);

      return query.exec();

}


bool voyageur::supprimer(int cin){
    QSqlQuery query;

          query.prepare(" Delete from voyageur where cin=:cin");
          query.bindValue(0,cin);
          return query.exec();
}

 QSqlQueryModel* voyageur::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM voyageur");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));

    return model ;
}
 QSqlQueryModel* voyageur::tri()
 {
     QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM voyageur order by cin ASC ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));

return model ;
 }
 bool voyageur::rechercher(int cin)
 {


       QSqlQuery query("SELECT * FROM voyageur");
       QSqlQuery recherche("select * from voyageur where  cin = "+QString::number(cin) );
        // query.prepare ("select * from voyageur where cin="+QString::number(cin));
         QSqlRecord rec = recherche.record();

         qDebug() << "Number of columns: " << rec.count();

         int nameCol = rec.indexOf("cin"); // index of the field "name"
         while (recherche.next()){
             qDebug() << recherche.value(nameCol).toString();
             QString test= recherche.value(nameCol).toString();
         if (test!=""){query.exec("select from voyageur where cin="+QString::number(cin));

                 return true;
             }
             return false;


 }
     return query.exec();


}
 QSqlQueryModel* voyageur::afficher1()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM voyageur where cin="+QString::number(cin));
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));

    return model ;
}
