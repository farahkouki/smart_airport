#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gestion_de_vole.h"
#include <QDate>
#include <QTextBrowser>
#include <QAbstractItemView>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <voyageur.h>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QtCharts>

#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include "etudiant.h"

#include "avion.h"
QT_BEGIN_NAMESPACE
class QTextBrowser;
QT_END_NAMESPACE
QT_BEGIN_NAMESPACE
class QAbstractItemModel;
class QAbstractItemView;
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addPoint(double x, double y);
    void clearData();
    void plot();
    QtCharts::QChartView *chartView ;

            void choix_pie();

            void choix_pie1();
            void choix_pie2();


private slots:
    void on_pb_ajouter_clicked();

    void on_pushButton_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_PDF_clicked();

    void setFontSize(int size);
    void setMonth(int month);
    void setYear(QDate date);





    void on_pushButton_4_clicked();







    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pb_ajouter_voyageur_clicked();

    void on_pb_modifier_voyageur_clicked();

    void on_pb_supprimer1_clicked();

    void on_pb_tri_clicked();

    void on_chercher_cin_clicked();

    void on_btn_imp_clicked();

    void on_pushButton_afficher_voyageur_clicked();

    void on_pushButton_5_clicked();


    void on_pushButton_stat_voyageur_clicked();



    void on_pb_ajouter2_clicked();

    void on_pushButton_afficher_avion_clicked();

    void on_pushButton_supprimer_avion_clicked();

    void on_pushButton_rechercher_avion_clicked();

    void on_pushButton_Tri_avion_clicked();

    void on_pushButton_PDF_avion_clicked();

    void on_pushButton_Update_avion_clicked();



    void on_pushButton_stat_avion_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_QR_clicked();

private:

    etudiant etmp;
    voyageur v;
    voyageur v1;
    QVector<double> qv_x,qv_y;
    Ui::MainWindow *ui;
    gestion_de_vole V;
        avion a;
        avion a1;
        QByteArray data;


    void insertCalendar();

    int fontSize;
    QDate selectedDate;
    QTextBrowser *editor;
    void setupModel();
    void setupViews();
    void loadFile(const QString &path);

    QAbstractItemModel *model = nullptr;
    QAbstractItemView *pieChart = nullptr;

    QSerialPort *serial;
    QString portname;
    quint16 vendorId;
    quint16 productId;
    bool arduino_available;
    void arduino_init();


signals:
    void setCenter(QVariant, QVariant);
    void addMarker(QVariant, QVariant);

};

#endif // MAINWINDOW_H
