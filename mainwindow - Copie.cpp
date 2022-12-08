#include "mainwindow.h"
#include "ui_mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);
}

mainwindow::~mainwindow()
{
    delete ui;
}
