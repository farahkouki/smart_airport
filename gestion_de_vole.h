#ifndef GESTION_DE_VOLE_H
#define GESTION_DE_VOLE_H
#include <QString>
#include <QSqlQueryModel>


class gestion_de_vole
{
public:
    gestion_de_vole();

    gestion_de_vole(int ,QString,QString);
    int getid();
    QString getdestination();
    QString gettemps();
    void setid(int);
    void setdestination(QString);
    void settemps(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool rechercher(int);
    QSqlQueryModel* afficher1();
    QSqlQueryModel* tri();
    //QSqlQueryModel* afficher2();






 private:
        int id;
        QString destination,temps;




};

#endif // GESTION_DE_VOLE_H
