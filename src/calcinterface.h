#ifndef CALCINTERFACE_H
#define CALCINTERFACE_H

#include <QObject>
#include <QDebug>
#include <QString>

class CalcInterface : public QObject
{
    Q_OBJECT
public:
    explicit CalcInterface(QObject *parent = 0);

    Q_INVOKABLE void number_pressed(int number);
    Q_INVOKABLE void equal_pressed();
    Q_INVOKABLE void point_pressed();
    Q_INVOKABLE void plus_pressed();
    Q_INVOKABLE void minus_pressed();
    Q_INVOKABLE void multiply_pressed();
    Q_INVOKABLE void divide_pressed();
    Q_INVOKABLE void delete_pressed();
    Q_INVOKABLE void sqrt_pressed();
    Q_INVOKABLE void fact_pressed();
    Q_INVOKABLE void exp_pressed();
    Q_INVOKABLE void sec_exp_pressed();
    Q_INVOKABLE void sin_pressed();
    Q_INVOKABLE void cos_pressed();
    Q_INVOKABLE void display(QObject *scrn);

signals:

public slots:

private:
    QString output; // string sended to screen of calculator
    double tempSum; // stores value of sum so far
    double tempFactor; // stores value of factor so far
    double tempBase; // stores base for power with variable exponent
    bool pointFlag; // indicates presence of decimal point
    bool plusFlag; // indicates presence of plus operator
    bool minusFlag; // indicates presence of minus operator
    bool divFlag; // indicates presence of divide operator
    bool mulFlag; // indicates presence of multilply operator
    bool powFlag; // indicates presence of power operator
    bool wfnFlag; // indicates if there is waiting for number

    void set_flags(int option);

};

#endif // CALCINTERFACE_H
