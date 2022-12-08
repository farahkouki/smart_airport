#ifndef SERIALLINK_H
#define SERIALLINK_H

#include <QObject>
#include<QSerialPort>

class seriallink : public QObject
{
    Q_OBJECT
public:
    explicit seriallink(QObject *parent = nullptr);
    void openconection();
    void closeconection();
    void write(const char*messageToWrite);
    bool isopen();
    bool iswrite();
private slots:
    void newdata();



signals:
    private:
   QSerialPort _serial;



};

#endif // SERIALLINK_H
