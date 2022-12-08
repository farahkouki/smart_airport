#ifndef MODELETABLESQL_H
#define MODELETABLESQL_H

#include <QSqlTableModel>

class ModeleTableSql : public QSqlTableModel
{
public:
    ModeleTableSql();

    void setOrderByClause(QString orderByClause);

    virtual QString orderByClause() const;

protected:
    QString m_orderClause;
};

#endif // MODELETABLESQL_H
ModeleTableSql::ModeleTableSql()
{
}

void ModeleTableSql::setOrderByClause(QString orderByClause)
{
    m_orderClause=orderByClause;
}

QString ModeleTableSql::orderByClause() const
{
    return m_orderClause;
}

