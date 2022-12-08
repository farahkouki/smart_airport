#ifndef STATCLIENT_H
#define STATCLIENT_H
#include <QtCharts>
#include <QPieSeries>
#include <QPieSlice>
#include <QBarSeries>
#include <QSqlQuery>
#include <QString>
QT_CHARTS_USE_NAMESPACE

class statclient
{
    QChart *chart;
        QChartView *chartView;
public:
    statclient();
    QChartView * Preparechart(QString,QString);
};

#endif // STATCLIENT_H
