#ifndef EVENT_H
#define EVENT_H


#ifndef ETUDIANT_H
#define ETUDIANT_H
#include<QString>
#include<QSqlQueryModel>

class Event
{
public:
    Event ();

   Event (int,int,QString,QString);
 Event (int,int,QString,QString,int);
    int getid();
    int getnb();

    QString getnom();
    QString getprenom();
    void setid(int);
    void setnb(int);
    void setnom(QString);
    void setprenom(QString);
    bool ajouter();

    bool test/*=false*/;
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher1();
    QSqlQueryModel* tree();
    bool supprimer(int);
    bool chercher(int);
    bool select(int);
  bool update();
int mv;


private :
  //nb =nombre de inviteeeeeeeee
    int id,nb;
    QString nom,prenom;
};

#endif // ETUDIANT_H


#endif // EVENT_H
