#include "even1.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include<QSqlQueryModel>
#include<QSqlRecord>
#include<list>
#include<QSqlTableModel>
#include <vector>

#include <QPdfWriter>

even1::even1()
{

}
even1::  even1(QString name,QString stdate,int sttime,QString enddate,int endtime){


    this->Name=name;
        this->startdate=stdate;
        this->starttime=sttime;
    this->enddate=enddate;
    this->endtime=endtime;






}
bool even1 :: ajouter1(){

    QSqlQuery query;
    query.prepare("INSERT INTO EVENT1 (NAME, STARTDATE, STARTTIME,ENDDATE,ENDTIME) "
                      "VALUES (:NAME, :STARTDATE, :STARTTIME,:ENDDATE,:ENDTIME)");
        query.bindValue(":NAME", Name);
        query.bindValue(":STARTDATE", startdate);
        query.bindValue(":STARTTIME", starttime);
        query.bindValue(":ENDDATE", enddate);
        query.bindValue(":ENDTIME", endtime);
         return query.exec();
}
