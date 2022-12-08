#ifndef VOYAGEUR_H
#define VOYAGEUR_H
#include<QString>
#include <QSqlQueryModel>

class voyageur
{
public:
    voyageur();
    voyageur(int,QString,QString);
    int getcin();
    QString getnom();
    QString getprenom();
    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    bool ajouter1();
    QSqlQueryModel* afficher0();
    bool supprimer1(int);
    QSqlQueryModel* tri1();
    bool rechercher1(int);
    QSqlQueryModel* afficher2();
    bool modifier1 (int);

private:
    int cin;
    QString nom,prenom;
};

#endif // VOYAGEUR_H
