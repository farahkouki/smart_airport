#include "sqleventmodel.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QList>
#include <QObject>

SqlEventModel::SqlEventModel()
{
    createConnection();
}

void SqlEventModel::createConnection()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("system");
    db.setPassword("1234");
    if (!db.open()){
    return;


    }
    QSqlQuery query;
    // We store the time as seconds because it's easier to query.
    query.exec("create table Event (name TEXT, startDate DATE, startTime INT, endDate DATE, endTime INT)");
    query.exec("insert into Event values('Grocery shopping', '2014-01-01', 36000, '2014-01-01', 39600)");
    query.exec("insert into Event values('Ice skating', '2014-01-01', 57600, '2014-01-01', 61200)");
    query.exec("insert into Event values('Doctor''s appointment', '2014-01-15', 57600, '2014-01-15', 63000)");
    query.exec("insert into Event values('Conference', '2014-01-24', 32400, '2014-01-28', 61200)");

    return;

    }





