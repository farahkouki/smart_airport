#ifndef SQLEVENTMODEL_H
#define SQLEVENTMODEL_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QList>
#include <QObject>
class SqlEventModel
{
public:
    SqlEventModel();
    void createConnection();
};

#endif // SQLEVENTMODEL_H
