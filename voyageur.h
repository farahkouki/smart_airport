
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
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    QSqlQueryModel* tri();
    bool rechercher(int);
    QSqlQueryModel* afficher1();
    bool modifier (int);


private:
    int cin;
    QString nom,prenom;

};

#endif // VOYAGEUR_H
