#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_de_vole.h"
#include "voyageur.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QPixmap>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QFileInfo>
#include <QFileDialog>
#include <QCalendarWidget>
#include <QDate>
#include <QApplication>
#include <QtWidgets>
#include "preview.h"
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connection.h"
#include "etudiant.h"
#include <QFileDialog>
#include <QMessageBox>
#include "exportexcelobject.h"
#include "camera.h"
#include "ui_camera.h"
#include <QPrinter>
#include <QTextDocument>
#include <QCameraViewfinder>
#include "stat.h"
#include "arduino.h"
#include <QtSerialPort/QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "qrcode.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


//menhne bech yabda
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();

  auto obj = ui->quickWidget->rootObject();
  connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));
  connect(this, SIGNAL(addMarker(QVariant, QVariant)), obj, SLOT(addMarker(QVariant, QVariant)));

      emit setCenter(36.847507, 10.325402);
      emit addMarker(36.847507, 10.325402);
   ui->le_id->setValidator( new QIntValidator(100, 9999999, this));
   ui->tab_gestion_de_vole->setModel(V.afficher());
   ui->le_cin->setValidator( new QIntValidator(0,999,this));
   ui->tab_voyageur->setModel(v.afficher0());
    QPixmap pix("C:/Users/elyes/Documents/map1.jpg");
    ui->label_pic->setPixmap(pix);
    QPixmap pix1("C:/Users/elyes/Documents/map1.jpg");
    ui->label_pic1->setPixmap(pix1);
    QPixmap pix2("C:/Users/elyes/Documents/map1.jpg");
    ui->label_pic2->setPixmap(pix2);
    QPixmap pix3("C:/Users/elyes/Documents/map1.jpg");
    ui->label_pic3->setPixmap(pix3);
    QPixmap pix4("C:/Users/elyes/Documents/map1.jpg");
    ui->label_pic4->setPixmap(pix4);
    QPixmap pix5("C:/Users/elyes/Documents/map1.jpg");
    ui->label_pic5->setPixmap(pix5);
    QPixmap pix6("C:/Users/elyes/Documents/map1.jpg");
    ui->label_pic6->setPixmap(pix6);
    QPixmap pix7("C:/Users/elyes/Documents/map1.jpg");
    ui->label_pic7->setPixmap(pix7);
    QPixmap pix8("C:/Users/elyes/Documents/map1.jpg");
    ui->label_pic8->setPixmap(pix8);
    QPixmap pix9("C:/Users/elyes/Documents/map1.jpg");
    ui->label_pic9->setPixmap(pix9);
    QPixmap pix10("C:/Users/elyes/Documents/map1.jpg");
    ui->label_pic10->setPixmap(pix10);
    QPixmap pix11("C:/Users/elyes/Documents/map1.jpg");
    ui->label_pic11->setPixmap(pix11);
    QPixmap pix12("C:/Users/elyes/Documents/airport-security-service-flat-illustration-vector 6.jpg");
    ui->label_pic12->setPixmap(pix12);
    QPixmap pix13("C:/Users/elyes/Documents/airport-security-service-flat-illustration-vector 6.jpg");
    ui->label_pic13->setPixmap(pix13);
    QPixmap pix14("C:/Users/elyes/Documents/airport-security-service-flat-illustration-vector 6.jpg");
    ui->label_pic14->setPixmap(pix14);
    QPixmap pix15("C:/Users/elyes/Documents/airport-security-service-flat-illustration-vector 6.jpg");
    ui->label_pic15->setPixmap(pix15);
    QPixmap pix16("C:/Users/elyes/Documents/map1.jpg");
    ui->label_pic16->setPixmap(pix16);
    QPixmap pix17("C:/Users/elyes/Documents/airport-security-service-flat-illustration-vector 6.jpg");
    ui->label_pic17->setPixmap(pix17);
    QPixmap pix18("C:/Users/elyes/Documents/airport-security-service-flat-illustration-vector 6.jpg");
    ui->label_pic18->setPixmap(pix18);
    ui->le_id->setValidator( new QIntValidator(0, 9999999, this));
    ui->tab_gestion_de_vole->setModel(V.afficher());
    serial=new QSerialPort();
    arduino_available=false;
    foreach (const QSerialPortInfo &serial_Info,QSerialPortInfo::availablePorts()) {
        qDebug()<<"Puerto: "<<serial_Info.portName();
                portname = serial_Info.portName();
                qDebug()<<"Vendor Id: "<<serial_Info.vendorIdentifier();
                vendorId = serial_Info.vendorIdentifier();
                qDebug()<<"Product Id: "<<serial_Info.productIdentifier();
                productId = serial_Info.productIdentifier();
                arduino_available = true;
            }
            if(arduino_available){
                arduino_init();
            }

    }



MainWindow::~MainWindow()
{
    delete ui;


}


void MainWindow::on_pb_ajouter_clicked()
{

    int id=ui->le_id->text().toInt();
    QString destination=ui->le_nom->text();
    QString temps=ui->le_prenom->text();
    ui->tab_gestion_de_vole->setModel(V.afficher());
    gestion_de_vole V(id,destination,temps);
bool test=V.ajouter();
if(test)
    QMessageBox::information(nullptr, QObject::tr("ajout"),
                QObject::tr("ajout successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("ajout failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_clicked()
{
ui->tab_gestion_de_vole->setModel(V.afficher());
bool test=V.afficher();
if(test)
    QMessageBox::information(nullptr, QObject::tr("refesh"),
                QObject::tr("refresh successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("refresh failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pb_supprimer_clicked()
{

    gestion_de_vole V1; V1.setid(ui->le_id_supp->text().toInt());
    bool test=V1.supprimer(V1.getid());
    QMessageBox msgBox;
    if(test)

    msgBox.setText("suppression avec succees.");

        else

        msgBox.setText("echec de suppression.");
        msgBox.exec();


}


void MainWindow::on_pushButton_2_clicked()
{
    gestion_de_vole V1;
        V1.setid(ui->le_id->text().toInt());
        bool test=V1.supprimer(V1.getid());
        if(!test){
            QMessageBox::critical(nullptr, QObject::tr("nope"),
                        QObject::tr("update failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


        ui->tab_gestion_de_vole->setModel(V1.afficher());
        }
        else
        {   int id=ui->le_id->text().toInt();
            QString destination=ui->le_nom->text();
            QString temps=ui->le_prenom->text();
      gestion_de_vole
              V(id , destination, temps);
      bool test1=V.ajouter();

      if(test1)


          QMessageBox::information(nullptr, QObject::tr("ok"),
                      QObject::tr("update successful.\n"
                                  "update effectuer."), QMessageBox::Cancel);


      else

          QMessageBox::critical(nullptr, QObject::tr("nope"),
                      QObject::tr("connection failed.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_3_clicked()

{
    gestion_de_vole V1;
    V1.setid(ui->chercher_id->text().toInt());
    bool test=V.rechercher(V1.getid());
    ui->tab_gestion_de_vole_2->setModel(V1.afficher1());


    if(test)


        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("recherche successful.\n"
                                "update effectuer."), QMessageBox::Cancel);


    else

        QMessageBox::critical(nullptr, QObject::tr("nope"),
                    QObject::tr("recherche failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}




void MainWindow::on_pushButton_PDF_clicked()
{
    int i=0;int j=0;

   int id =ui->le_id->text().toInt();

    QString id_string=QString::number(id);

           QString destination =ui->le_nom->text();

            QString temps =ui->le_prenom->text();


            QPdfWriter pdf("C:/Users/elyes/Desktop/test.pdf");

            QPainter painter (&pdf);

            painter.setPen(Qt::blue);

           //  painter.drawTabel

            painter.drawText(i,j,"id:="+id_string);

            painter.drawText(i+100,j+100,"destination:="+destination);

            painter.drawText(i+100,j+200,"temps:="+temps);

}


void MainWindow::on_pushButton_tri_clicked()
{
    ui->tab_gestion_de_vole_3->setModel(V.tri());
}





void MainWindow::on_pushButton_4_clicked()
{
    selectedDate = QDate::currentDate();
    fontSize = 10;

    QWidget *centralWidget = new QWidget;
//! [0]

//! [1]
    QLabel *dateLabel = new QLabel(tr("Date:"));
    QComboBox *monthCombo = new QComboBox;

    for (int month = 1; month <= 12; ++month)
        monthCombo->addItem(QLocale::system().monthName(month));

    QDateTimeEdit *yearEdit = new QDateTimeEdit;
    yearEdit->setDisplayFormat("yyyy");
    yearEdit->setDateRange(QDate(1753, 1, 1), QDate(8000, 1, 1));
//! [1]

    monthCombo->setCurrentIndex(selectedDate.month() - 1);
    yearEdit->setDate(selectedDate);

//! [2]
    QLabel *fontSizeLabel = new QLabel(tr("Font size:"));
    QSpinBox *fontSizeSpinBox = new QSpinBox;
    fontSizeSpinBox->setRange(1, 64);

    editor = new QTextBrowser;
    insertCalendar();
//! [2]

//! [3]
    connect(monthCombo, QOverload<int>::of(&QComboBox::activated),
            this, &MainWindow::setMonth);
    connect(yearEdit, &QDateTimeEdit::dateChanged,
            this, &MainWindow::setYear);
    connect(fontSizeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &MainWindow::setFontSize);
//! [3]

    fontSizeSpinBox->setValue(10);

//! [4]
    QHBoxLayout *controlsLayout = new QHBoxLayout;
    controlsLayout->addWidget(dateLabel);
    controlsLayout->addWidget(monthCombo);
    controlsLayout->addWidget(yearEdit);
    controlsLayout->addSpacing(24);
    controlsLayout->addWidget(fontSizeLabel);
    controlsLayout->addWidget(fontSizeSpinBox);
    controlsLayout->addStretch(1);

    QVBoxLayout *centralLayout = new QVBoxLayout;
    centralLayout->addLayout(controlsLayout);
    centralLayout->addWidget(editor, 1);
    centralWidget->setLayout(centralLayout);

    setCentralWidget(centralWidget);

}
void MainWindow::insertCalendar()
{
    editor->clear();
    QTextCursor cursor = editor->textCursor();
    cursor.beginEditBlock();

    QDate date(selectedDate.year(), selectedDate.month(), 1);
//! [5]

//! [6]
    QTextTableFormat tableFormat;
    tableFormat.setAlignment(Qt::AlignHCenter);
    tableFormat.setBackground(QColor("#e0e0e0"));
    tableFormat.setCellPadding(2);
    tableFormat.setCellSpacing(4);
//! [6] //! [7]
    QVector<QTextLength> constraints;
    constraints << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14);
    tableFormat.setColumnWidthConstraints(constraints);
//! [7]

//! [8]
    QTextTable *table = cursor.insertTable(1, 7, tableFormat);
//! [8]

//! [9]
    QTextFrame *frame = cursor.currentFrame();
    QTextFrameFormat frameFormat = frame->frameFormat();
    frameFormat.setBorder(1);
    frame->setFrameFormat(frameFormat);
//! [9]

//! [10]
    QTextCharFormat format = cursor.charFormat();
    format.setFontPointSize(fontSize);

    QTextCharFormat boldFormat = format;
    boldFormat.setFontWeight(QFont::Bold);

    QTextCharFormat highlightedFormat = boldFormat;
    highlightedFormat.setBackground(Qt::yellow);
//! [10]

//! [11]
    for (int weekDay = 1; weekDay <= 7; ++weekDay) {
        QTextTableCell cell = table->cellAt(0, weekDay-1);
//! [11] //! [12]
        QTextCursor cellCursor = cell.firstCursorPosition();
        cellCursor.insertText(QLocale::system().dayName(weekDay), boldFormat);
    }
//! [12]

//! [13]
    table->insertRows(table->rows(), 1);
//! [13]

    while (date.month() == selectedDate.month()) {
        int weekDay = date.dayOfWeek();
        QTextTableCell cell = table->cellAt(table->rows()-1, weekDay-1);
        QTextCursor cellCursor = cell.firstCursorPosition();

        if (date == QDate::currentDate())
            cellCursor.insertText(QString("%1").arg(date.day()), highlightedFormat);
        else
            cellCursor.insertText(QString("%1").arg(date.day()), format);

        date = date.addDays(1);
        if (weekDay == 7 && date.month() == selectedDate.month())
            table->insertRows(table->rows(), 1);
    }

    cursor.endEditBlock();
//! [14]
    setWindowTitle(tr("Calendar for %1 %2"
        ).arg(QLocale::system().monthName(selectedDate.month())
        ).arg(selectedDate.year()));
}
//! [14]

//! [15]
void MainWindow::setFontSize(int size)
{
    fontSize = size;
    insertCalendar();
}
//! [15]

//! [16]
void MainWindow::setMonth(int month)
{
    selectedDate = QDate(selectedDate.year(), month + 1, selectedDate.day());
    insertCalendar();
}
//! [16]

//! [17]
void MainWindow::setYear(QDate date)
{
    selectedDate = QDate(date.year(), selectedDate.month(), selectedDate.day());
    insertCalendar();
}
//! [17]




void MainWindow::arduino_init()
{
    serial->setPortName(portname);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
}



void MainWindow::on_pushButton_6_clicked()
{
    if(serial->isWritable()){
        serial->write("1");
        qDebug()<<"allumer";
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    if(serial->isWritable()){
        serial->write("2");
        qDebug()<<"!!!!";
    }
}

//integration farah
void MainWindow::on_pb_ajouter_voyageur_clicked()
{
    int cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom1->text();
    QString prenom=ui->le_prenom1->text();
    ui->tab_voyageur->setModel(v.afficher0());
    voyageur v(cin,nom,prenom);


    bool test=v.ajouter1();
     ui->tab_voyageur->setModel(v.afficher0());
    if(test)
        QMessageBox::information(nullptr,QObject::tr("ajout"),
                                QObject::tr("ajout successful.\n"
                                            "click Cancel to exit."),QMessageBox::Cancel );
    else
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                QObject::tr("ajout failed.\n"
                                            "click Cancel to exit."),QMessageBox::Cancel );
    //QMessageBox msgBox;
}


void MainWindow::on_pb_modifier_voyageur_clicked()
{
    voyageur v;
        v.setcin(ui->le_cin->text().toInt());
        bool test=v.supprimer1(v.getcin());
        if(!test){
            QMessageBox::critical(nullptr, QObject::tr("nope"),
                        QObject::tr("update failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


        ui->tab_voyageur->setModel(v.afficher0());
        }
        else
        {   int cin=ui->le_cin->text().toInt();
            QString nom=ui->le_nom1->text();
            QString prenom=ui->le_prenom1->text();
      voyageur
              v(cin , nom, prenom);
      bool test1=v.ajouter1();

      if(test1)


          QMessageBox::information(nullptr, QObject::tr("ok"),
                      QObject::tr("update successful.\n"
                                  "update effectuer."), QMessageBox::Cancel);


      else

          QMessageBox::critical(nullptr, QObject::tr("nope"),
                      QObject::tr("connection failed.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    }
}




void MainWindow::on_pb_supprimer1_clicked()
{
    voyageur v1;
        v1.setcin(ui->le_id_supp1->text().toInt());
        bool test=v1.supprimer1(v1.getcin());
        QMessageBox msgBox;
        if(test)
           { msgBox.setText("suppression avec succes");
        ui->tab_voyageur->setModel(v.afficher0());
        }
        else
            msgBox.setText("Echec de suppression");
        msgBox.exec();
}


void MainWindow::on_pb_tri_clicked()
{
    ui->tab_voyageur_2->setModel(v1.tri1());
}


void MainWindow::on_chercher_cin_clicked()
{
    v1.setcin(ui->line_cin->text().toInt());
    bool test=v1.rechercher1(v1.getcin());
    ui->tab_gestion_de_vole_2->setModel(v1.afficher2());
    if(test)
        QMessageBox::information(nullptr,QObject::tr("recherche"),
                                QObject::tr("recherche successful.\n"
                                            "click Cancel to exit."),QMessageBox::Cancel );
    else
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                QObject::tr("recherche failed.\n"
                                            "click Cancel to exit."),QMessageBox::Cancel );
}


void MainWindow::on_btn_imp_clicked()
{
    int i=0;int j=0;

   int id =ui->le_cin->text().toInt();

    QString cin_string=QString::number(id);

           QString nom =ui->le_nom1->text();

            QString prenom =ui->le_prenom1->text();


            QPdfWriter pdf("C:/Users/elyes/Desktop/test.pdf");

            QPainter painter (&pdf);

            painter.setPen(Qt::blue);

           //  painter.drawTabel

            painter.drawText(i,j,"cin:="+cin_string);

            painter.drawText(i+100,j+100,"nom:="+nom);

            painter.drawText(i+100,j+200,"prenom:="+prenom);
}


void MainWindow::on_pushButton_afficher_voyageur_clicked()
{
    ui->tab_voyageur->setModel(v1.afficher0());
    bool test=v1.afficher0();
    if(test)
        QMessageBox::information(nullptr, QObject::tr("refesh"),
                    QObject::tr("refresh successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("refresh failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::choix_pie()
{

    QSqlQueryModel * model= new QSqlQueryModel();

           model->setQuery("select * from gestion_de_vole where id < 10 ");
           float salaire=model->rowCount();
           model->setQuery("select * from gestion_de_vole where id  between 10 and 2000 ");
           float salaire1=model->rowCount();
           model->setQuery("select * from gestion_de_vole where id>2000 ");
           float salaire2=model->rowCount();
           float total=salaire+salaire1+salaire2;
           QString a = QString("nombre de vole -100  "+QString::number((salaire*100)/total,'f',2)+"%" );
           QString b = QString("nombre de vole -1000 "+QString::number((salaire1*100)/total,'f',2)+"%" );
           QString c = QString(" nombre de vole +1000 "+QString::number((salaire2*100)/total,'f',2)+"%" );
           QPieSeries *series = new QPieSeries();
           series->append(a,salaire);
           series->append(b,salaire1);
           series->append(c,salaire2);
           if (salaire!= 0)
           {
               QPieSlice *slice = series->slices().at(0);
               slice->setLabelVisible();
               slice->setPen(QPen());
           }
           if ( salaire1!=0)
           {
                    // Add label, explode and define brush for 2nd slice
                    QPieSlice *slice1 = series->slices().at(1);
                    //slice1->setExploded();
                    slice1->setLabelVisible();
           }
           if(salaire2!=0)
           {
                    // Add labels to rest of slices
                    QPieSlice *slice2 = series->slices().at(2);
                    //slice1->setExploded();
                    slice2->setLabelVisible();
           }
                   // Create the chart widget
                   QChart *chart = new QChart();
                   // Add data to chart with title and hide legend
                   chart->addSeries(series);
                   chart->setTitle("Pourcentage Par numero :Nombre Des numero "+ QString::number(total));
                   chart->legend()->hide();
                   // Used to display the chart
                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
                   chart->setAnimationOptions(QChart::SeriesAnimations);
                   chartView->resize(1000,500);
                   chartView->show();
   }





void MainWindow::on_pushButton_5_clicked()
{
    MainWindow s;
    s.choix_pie();
    s.show();
}

void MainWindow::choix_pie1()
{

    QSqlQueryModel * model= new QSqlQueryModel();

           model->setQuery("select * from voyageur where cin < 10 ");
           float salaire=model->rowCount();
           model->setQuery("select * from voyageur where cin  between 10 and 2000 ");
           float salaire1=model->rowCount();
           model->setQuery("select * from voyageur where cin >2000 ");
           float salaire2=model->rowCount();
           float total=salaire+salaire1+salaire2;
           QString a = QString("nombre de voyageur -10  "+QString::number((salaire*100)/total,'f',2)+"%" );
           QString b = QString("nombre de voyageur -50 "+QString::number((salaire1*100)/total,'f',2)+"%" );
           QString c = QString(" nombre de voyageur -100 "+QString::number((salaire2*100)/total,'f',2)+"%" );
           QPieSeries *series = new QPieSeries();
           series->append(a,salaire);
           series->append(b,salaire1);
           series->append(c,salaire2);
           if (salaire!= 0)
           {
               QPieSlice *slice = series->slices().at(0);
               slice->setLabelVisible();
               slice->setPen(QPen());
           }
           if ( salaire1!=0)
           {
                    // Add label, explode and define brush for 2nd slice
                    QPieSlice *slice1 = series->slices().at(1);
                    //slice1->setExploded();
                    slice1->setLabelVisible();
           }
           if(salaire2!=0)
           {
                    // Add labels to rest of slices
                    QPieSlice *slice2 = series->slices().at(2);
                    //slice1->setExploded();
                    slice2->setLabelVisible();
           }
                   // Create the chart widget
                   QChart *chart = new QChart();
                   // Add data to chart with title and hide legend
                   chart->addSeries(series);
                   chart->setTitle("Pourcentage Par numero :Nombre Des numero "+ QString::number(total));
                   chart->legend()->hide();
                   // Used to display the chart
                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
                   chart->setAnimationOptions(QChart::SeriesAnimations);
                   chartView->resize(1000,500);
                   chartView->show();
   }


void MainWindow::on_pushButton_stat_voyageur_clicked()
{
    MainWindow s;
    s.choix_pie1();
    s.show();
}




void MainWindow::on_pb_ajouter2_clicked()
{
    int id=ui->lineEdit->text().toInt();
        QString nom=ui->lineEdit_2->text();
         QString type=ui->lineEdit_3->text();
        ui->tab_avion->setModel(a.afficher00());
       avion a (id,nom,type);


        bool test=a.ajouter2();
         ui->tab_avion->setModel(a.afficher00());
        if(test)
            QMessageBox::information(nullptr,QObject::tr("ajout"),
                                    QObject::tr("ajout successful.\n"
                                                "click Cancel to exit."),QMessageBox::Cancel );
        else
            QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                    QObject::tr("ajout failed.\n"
                                                "click Cancel to exit."),QMessageBox::Cancel );
        //QMessageBox msgBox;
}


void MainWindow::on_pushButton_afficher_avion_clicked()
{
    ui->tab_avion->setModel(a.afficher00());
        bool test=a.afficher00();
        if(test)
            QMessageBox::information(nullptr, QObject::tr("refesh"),
                        QObject::tr("refresh successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("refresh failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_supprimer_avion_clicked()
{
    avion a;
        a.setid(ui->lineEdit_ID->text().toInt());
        bool test=a.supprimer2(a.getid());
        QMessageBox msgBox;
        if(test)
           { msgBox.setText("suppression avec succes");
        ui->tab_avion->setModel(a.afficher00());
        }
        else
            msgBox.setText("Echec de suppression");
        msgBox.exec();

}


void MainWindow::on_pushButton_rechercher_avion_clicked()
{
    avion a;
            a.setid(ui->lineEdit_ID_2->text().toInt());
            bool test=a.recherche2(a.getid());
            ui->tab_gestion_de_vole_2->setModel(a.afficher22());


            if(test)


                QMessageBox::information(nullptr, QObject::tr("ok"),
                            QObject::tr("recherche successful.\n"
                                        "update effectuer."), QMessageBox::Cancel);


            else

                QMessageBox::critical(nullptr, QObject::tr("nope"),
                            QObject::tr("recherche failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_Tri_avion_clicked()
{
    ui->tab_avion_2->setModel(a.tri2());
}


void MainWindow::on_pushButton_PDF_avion_clicked()
{
    int i=0;int j=0;

       int id =ui->lineEdit->text().toInt();

        QString id_string=QString::number(id);

               QString nom =ui->lineEdit_2->text();

                QString type =ui->lineEdit_3->text();

                QPdfWriter pdf("C:/Users/elyes/Desktop/test.pdf");

                QPainter painter (&pdf);

                painter.setPen(Qt::blue);

                painter.drawText(i,j,"id:="+id_string);

                painter.drawText(i+1000,j+1000,"nom:="+nom);

                painter.drawText(i+1000,j+2000,"type:="+type);
}


void MainWindow::on_pushButton_Update_avion_clicked()
{
    avion a1;
        a1.setid(ui->lineEdit->text().toInt());
        bool test=a1.supprimer2(a1.getid());
        if(!test){
            QMessageBox::critical(nullptr, QObject::tr("nope"),
                        QObject::tr("update failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


        ui->tab_avion->setModel(a1.afficher00());
        }
        else
        {   int id=ui->lineEdit->text().toInt();
            QString nom=ui->lineEdit_2->text();
            QString type=ui->lineEdit_3->text();
       avion    a1(id , nom,type );
      bool test1=a1.ajouter2();

      if(test1)


          QMessageBox::information(nullptr, QObject::tr("ok"),
                      QObject::tr("update successful.\n"
                                  "update effectuer."), QMessageBox::Cancel);


      else

          QMessageBox::critical(nullptr, QObject::tr("nope"),
                      QObject::tr("connection failed.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::choix_pie2()
{

    QSqlQueryModel * model= new QSqlQueryModel();

           model->setQuery("select * from AVION where id < 10 ");
           float salaire=model->rowCount();
           model->setQuery("select * from AVION where id  between 10 and 2000 ");
           float salaire1=model->rowCount();
           model->setQuery("select * from AVION where id >2000 ");
           float salaire2=model->rowCount();
           float total=salaire+salaire1+salaire2;
           QString a = QString("nombre d'avion -10  "+QString::number((salaire*100)/total,'f',2)+"%" );
           QString b = QString("nombre d'avion -100 "+QString::number((salaire1*100)/total,'f',2)+"%" );
           QString c = QString(" nombre d'avion -2000 "+QString::number((salaire2*100)/total,'f',2)+"%" );
           QPieSeries *series = new QPieSeries();
           series->append(a,salaire);
           series->append(b,salaire1);
           series->append(c,salaire2);
           if (salaire!= 0)
           {
               QPieSlice *slice = series->slices().at(0);
               slice->setLabelVisible();
               slice->setPen(QPen());
           }
           if ( salaire1!=0)
           {
                    // Add label, explode and define brush for 2nd slice
                    QPieSlice *slice1 = series->slices().at(1);
                    //slice1->setExploded();
                    slice1->setLabelVisible();
           }
           if(salaire2!=0)
           {
                    // Add labels to rest of slices
                    QPieSlice *slice2 = series->slices().at(2);
                    //slice1->setExploded();
                    slice2->setLabelVisible();
           }
                   // Create the chart widget
                   QChart *chart = new QChart();
                   // Add data to chart with title and hide legend
                   chart->addSeries(series);
                   chart->setTitle("Pourcentage Par numero :Nombre Des numero "+ QString::number(total));
                   chart->legend()->hide();
                   // Used to display the chart
                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
                   chart->setAnimationOptions(QChart::SeriesAnimations);
                   chartView->resize(1000,500);
                   chartView->show();
   }


void MainWindow::on_pushButton_stat_avion_clicked()
{
    MainWindow s;
    s.choix_pie2();
    s.show();
}


void MainWindow::on_pushButton_10_clicked()
{
    int id=ui->lineEdit_ID->text().toInt();
    QString nom=ui->lineEdit_Nom->text();
    QString prenom=ui->lineEdit_Prenom->text();

    etudiant E(id,nom,prenom);

    bool test=E.ajouter();

    if(test)
    {
        ui->tableView->setModel(etmp.afficher());

        QMessageBox::information(nullptr, QObject::tr("OK"),QObject::tr("Ajout effectué\n"
                                                                        "Click Cancel to exit."),QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),QObject::tr("Ajout non effectué\n"
                                                                        "Click Cancel to exit."),QMessageBox::Cancel);
}



void MainWindow::on_pushButton_11_clicked()
{
    int id =ui->lineEdit_IDS->text().toInt();
    bool test=etmp.supprimer(id);
    if(test)
    {
        ui->tableView->setModel(etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),QObject::tr("Supression effectué\n"
                                                                        "Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),QObject::tr("Supression non effectué\n"
                                                                        "Click Cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_12_clicked()
{
    QSqlQuery query;
    int id2=ui->lineEdit_ID_2->text().toInt();
    int id3=ui->lineEdit_ID_3->text().toInt();
    QString nom=ui->lineEdit_Nom_2->text();
    QString prenom=ui->lineEdit_Prenom_2->text();


    etudiant E(id2,nom,prenom);

   bool test=etmp.supprimer(id3);
   bool test2=E.ajouter();
    if(test && test2)
    {

        ui->tableView->setModel(etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),QObject::tr("Modification effectué\n"
                                                                        "Click Cancel to exit."),QMessageBox::Cancel);
     }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),QObject::tr("Modification non effectué\n"
                                                                        "Click Cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_13_clicked()
{
    QSqlQuery query;
    int id4=ui->lineEdit_ID_4->text().toInt();
    ui->tableView_3->setModel(etmp.afficher2(id4));
}

void MainWindow::on_pushButton_14_clicked()
{
    QSqlQuery query;
    ui->tableView_3->setModel(etmp.affichercroi());
}

void MainWindow::on_pushButton_15_clicked()
{
    QSqlQuery query;
    ui->tableView_3->setModel(etmp.afficherdecroi());
}

void MainWindow::on_pushButton_16_clicked()
{
    camera *c = new camera();
    c ->show();
}

void MainWindow::on_pushButton_17_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tableView);

    //colums to export
    obj.addField(0, "ID", "number");
    obj.addField(1, "NOM", "varchar(20)");
    obj.addField(2, "PRENOM", "varchar(20)");


    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}


void MainWindow::on_pushButton_18_clicked()
{
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tableView->model()->rowCount();
                const int columnCount =ui->tableView->model()->columnCount();


                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("eleve")
                        <<  "</head>\n"
                        "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                            "<h1>Liste des Evenements</h1>"

                            "<table border=1 cellspacing=0 cellpadding=2>\n";

                // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableView->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableView->isColumnHidden(column)) {
                                   QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";



        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);


        //QTextDocument document;
        //document.setHtml(html);
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("test.pdf");
        document->print(&printer);
}


void MainWindow::on_pushButton_19_clicked()
{
    stat_combo *s = new stat_combo();

  s->setWindowTitle("statistique ComboBox");
  s->choix_pie();
  s->show();
}

void MainWindow::on_pushButton_20_clicked()
{
    stat_combo *s = new stat_combo();

  s->setWindowTitle("statistique ComboBox");
  s->choix_bar();
  s->show();
}

void MainWindow::on_pushButton_22_clicked()
{



            QPdfWriter pdf("C:/Users/elyes/Desktop/test.pdf");

               QPainter painter(&pdf);
               int i = 4000;
                      painter.setPen(Qt::darkCyan);
                      painter.setFont(QFont("Time New Roman", 25));
                      painter.drawText(3000,1400,"HISTORIQUE");
                      painter.setPen(Qt::black);
                      painter.setFont(QFont("Time New Roman", 15));
                      painter.drawRect(100,100,9400,2500);
                      painter.drawRect(100,3000,9400,500);
                      painter.setFont(QFont("Time New Roman", 9));
                      painter.drawText(400,3300,"NOM");


                      painter.drawRect(100,3000,9400,9000);

                      QSqlQuery query;
                      query.prepare("select * from voyageur");
                      query.exec();
                      while (query.next())
                      {

                          painter.drawText(1350,i,query.value(1).toString());




                         i = i + 350;
                      }
                      QMessageBox::information(this, QObject::tr("PDF Saved Successfuly!"),
                      QObject::tr("PDF Saved Successfuly!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
        }



void MainWindow::on_pushButton_QR_clicked()
{
    //  int tabeq=ui->tableView_2->currentIndex().row();

        /*QVariant id=ui->tableView_2->model()->data(ui->tableView_2->model()->index(0,0)); lghalta hne asmaani khela
        qInfo() << "aa "<<endl;
        QString idc=id.toString();*/
       QString code=ui->CINQR->text();
        QSqlQuery qry;
        qry.prepare("select * from voyageur where cin = :cin; ");
       qry.bindValue(":cin",code);
        qry.exec();


         QString nom,prenom,ad_mail,num_tlf,adresse;//attributs
         QString idc;


       while(qry.next()){

            idc=qry.value(0).toString();
            nom=qry.value(1).toString();
            prenom=qry.value(2).toString();
            ad_mail=qry.value(3).toString();
            num_tlf=qry.value(4).toString();
            adresse=qry.value(5).toString();




        }
        idc=QString(idc);

       //QString text = idc ;
               idc="cin:\t" +idc+ " Nom:\t" +nom+ " Prenom:\t" +prenom+" ad_mail:\t" +ad_mail+ " num_tlf:\t" +num_tlf ;
        qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(idc.toUtf8().constData(), qrcodegen::QrCode::Ecc::HIGH);

        // Read the black & white pixels
        QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
        for (int y = 0; y < qr.getSize(); y++) {
            for (int x = 0; x < qr.getSize(); x++) {
                int color = qr.getModule(x, y);  // 0 for white, 1 for black

                // You need to modify this part
                if(color==0)
                    im.setPixel(x, y,qRgb(254, 254, 254));
                else
                    im.setPixel(x, y,qRgb(0, 0, 0));
            }
        }
        im=im.scaled(200,200);
                  ui->qrcodeLabel->setPixmap(QPixmap::fromImage(im));
}

