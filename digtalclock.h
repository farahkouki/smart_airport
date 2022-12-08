#ifndef DIGTALCLOCK_H
#define DIGTALCLOCK_H



#include <QLCDNumber>

//! [0]
class DigitalClock : public QLCDNumber
{
    Q_OBJECT

public:
    DigitalClock(QWidget *parent = nullptr);

private slots:
    void showTime();
};
#endif // DIGTALCLOCK_H
