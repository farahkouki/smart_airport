#ifndef GESTION_DE_VOLE_H
#define GESTION_DE_VOLE_H
#include <QString>
#include <QSqlQueryModel>

class gestion_de_vole
{
public:
    gestion_de_vole();

    gestion_de_vole(int ,QString,int);
    int getid();
    QString getdestination();
    int gettemps();
    void setid(int);
    void setdestination(QString);
    void settemps(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int );


 private:
        int id,temps;
        QString destination;

};

#endif // GESTION_DE_VOLE_H
