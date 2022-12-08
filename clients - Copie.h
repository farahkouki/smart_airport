#ifndef CLIENTS_H
#define CLIENTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Clients
{
public:
    Clients() ;
    Clients(int,QString,QString,QString,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    QString getad_mail();
    QString getnum_tlf();
    QString getadresse();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setad_mail(QString);
    void setnum_tlf(QString);
    void setadresse(QString);
    bool ajouter();
        bool test/*=false*/;
        QSqlQueryModel* afficher();
        bool supprimer(int);
        bool select(int);
          bool update();
          QSqlQueryModel * recherche(int);
          QSqlQueryModel * rechercher(QString);
          QSqlQueryModel * triid_croissant();
          QSqlQueryModel * trinom_croissant();
          QSqlQueryModel * triid_decroissant();
          QSqlQueryModel * trinom_decroissant();

private:
    int id;
    QString nom,prenom,ad_mail,num_tlf,adresse;
};

#endif // CLIENTS_H
