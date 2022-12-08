#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Project2A");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("211JMT6653");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}









/*
gestion_de_vole V1;
V1.setid(ui->chercher_id->text().toInt());
bool test=V1.rechercher(V1.getid());
QMessageBox msgBox;
if(test)

msgBox.setText("id trouver.");

    else

    msgBox.setText("echec.");
    msgBox.exec();


ui->tab_gestion_de_vole->setModel(V1.afficher());
*/
