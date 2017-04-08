#ifndef CALCINTERFACE_H
#define CALCINTERFACE_H

#include <QObject>
#include <QDebug>

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

signals:

public slots:

};

#endif // CALCINTERFACE_H