#include "seriallink.h"

seriallink::seriallink(QObject *parent)
    : QObject{parent}
{
_serial.setPortName("comb") ;
_serial.setBaudRate(QSerialPort::Baud9600);
_serial
}
