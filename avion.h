#ifndef AVION_H
#define AVION_H
#include <QString>
#include <QSqlQueryModel>

class avion
{
public:
    avion();
    avion(int,QString,QString);
        int getid();
        QString getnom();
        QString gettype();
        void setid(int);
        void setnom(QString);
        void settype(QString);
        bool ajouter2();
        QSqlQueryModel* afficher00();
        bool supprimer2(int);
        bool recherche2(int);
        QSqlQueryModel* afficher22();
        QSqlQueryModel* tri2();
    private:
        int id;
        QString nom,type;
};

#endif // AVION_H
