#include "connection.h"
//test git
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("system");
db.setPassword("1234");
if (db.open()){
test=true;


}

    return  test;
}
