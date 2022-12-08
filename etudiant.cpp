    #include "etudiant.h"
    #include <QSqlRecord>
    #include <QDebug>


etudiant::etudiant(int id,QString nom, QString prenom)
{
   this->id=id;
   this->nom=nom;
   this->prenom=prenom;
}

bool etudiant::ajouter()
{
  QSqlQuery query;
  QString res = QString::number(id);

  query.prepare("INSERT INTO SECURITE (id, nom, prenomm)""VALUES (:id, :nom, :prenomm)");

  query.bindValue(":id",res);
  query.bindValue(":nom",nom);
  query.bindValue(":prenomm",prenom);

  return query.exec();
}

QSqlQueryModel * etudiant::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from SECURITE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenomm"));

    return model;
}

bool etudiant::supprimer(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);

    query.prepare("Delete from SECURITE where ID= :id");
    query.bindValue(":id",res);
    return query.exec();
}

bool etudiant::recherche(int id)
{


      QSqlQuery query("SELECT * FROM SECURITE");
      QSqlQuery recherche("select * from SECURITE where  ID = "+QString::number(id) );
       // query.prepare ("select * from TABLE2 where id="+QString::number(id));
        QSqlRecord test = recherche.record();

        qDebug() << "Number of columns: " << test.count();

        int nameCol = test.indexOf("id"); // index of the field "name"
        while (recherche.next()){
            qDebug() << recherche.value(nameCol).toString();
            QString test= recherche.value(nameCol).toString();
        if (test!=""){query.exec("select from SECURITE where ID="+QString::number(id));

                return true;
            }
            return false;


}
    return query.exec();
}

QSqlQueryModel * etudiant::afficher2(int id)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QString res= QString::number(id);
    model->setQuery("SELECT * from SECURITE WHERE ID=:id");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenomm"));

    return model;
}

QSqlQueryModel * etudiant::affichercroi()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QString res= QString::number(id);
    model->setQuery("SELECT * from SECURITE ORDER BY ID");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenomm"));

    return model;
}

QSqlQueryModel * etudiant::afficherdecroi()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QString res= QString::number(id);
    model->setQuery("SELECT * from SECURITE ORDER BY ID DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenomm"));

    return model;
}








