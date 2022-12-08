#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>

namespace Ui {
class mainwindow;
}

class mainwindow : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

private:
    Ui::mainwindow *ui;
};

#endif // MAINWINDOW_H
