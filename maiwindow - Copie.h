#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "event.h"
#include "even1.h"
//#include "even1.h"
#include <QMainWindow>
#include <QDate>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QDate>
#include <QMainWindow>
#include <QMainWindow>
#include <QtNetwork>
#include "clients.h"
//include chart
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
#include <QDate>
#include <QMainWindow>
#include"statclient.h"
//3ycha
#include"employe.h"
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
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
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>



QT_BEGIN_NAMESPACE
class QTextBrowser;
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE
class QAbstractItemModel;
class QAbstractItemView;
QT_END_NAMESPACE
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int i =0;
    int j=0;
    int k=0;
    int nb1=0;
    QtCharts::QChartView *chartView ;
            void choix_bar();
            void choix_pie();
            statclient s;

            Etudiant E;
            QSortFilterProxyModel *proxy;
            void show_tables();


           bool fill_form(int);




               void choix_bar1();
             //  void choix_pie();

private:
    Ui::MainWindow *ui;
    Event E1;

    void insertCalendar();

    int fontSize;
    QDate selectedDate;
    QTextBrowser *editor;
    void setupModel();
    void setupViews();
    void loadFile(const QString &path);

    QAbstractItemModel *model = nullptr;
    QAbstractItemView *pieChart = nullptr;
signals:
    void setCenter(QVariant, QVariant);
    void addMarker(QVariant, QVariant);


private:
 //   Ui::MainWindow *ui;
    QSerialPort *serial;
    QString portname;
    quint16 vendorId;
    quint16 productId;
    bool arduino_available;
    void arduino_init();

     Clients cl1;
     int selected=0;

         QStringList files;

         QCamera *mCamera;

         QCameraViewfinder *mCameraViewfinder;

         QCameraImageCapture *mCameraImageCapture;

         QVBoxLayout *mLayout;

         QMenu *mOptionsMenu;

         QAction *mAllumerAction;

         QAction *mEtiendreAction;

         QAction *mCaptureAction;

         //3ycha



};





#endif // MAINWINDOW_H
