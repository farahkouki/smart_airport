#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QList>
#include <QObject>

class Connection
{
public:
    Connection();
    bool createconnect();


   // Q_INVOKABLE QList<QObject*> eventsForDate(const QDate &date);

};

#endif // CONNECTION_H
