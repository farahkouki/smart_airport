#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <voyageur.h>
#include"arduino.h"
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
    void update_label();

private slots:
   // void on_pushButton_clicked();
     void on_pb_ajouter_clicked();

     void on_pb_supprimer_clicked();

     void on_pb_tri_clicked();

     void on_chercher_cin_clicked();

     void on_pb_modifier_clicked();
     void on_pushButton_PDF_clicked();

     //void on_line_cin_cursorPositionChanged(int arg1, int arg2);

     void on_btn_add_clicked();

     void on_btn_clear_clicked();
 void on_btn_imp_clicked();
 void on_qrcodegen_clicked();
 void on_stat_clicked();

 void on_pushButton_clicked();

 void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    voyageur v;
    voyageur v1;
    QVector<double> qv_x,qv_y;
    arduino A;
    QByteArray data;
};

#endif // MAINWINDOW_H
 void on_pushButton_PDF_clicked();
