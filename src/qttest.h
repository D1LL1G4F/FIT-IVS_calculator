#ifndef test_H
#define test_H

#include <QTest>

class Test: public QObject
{
    Q_OBJECT

private slots:
    void Sum();
    void Sub();
    void Mul();
    void Div();
    void Sqroot();
    void Fact();
    void Pwr();
    void Cosx();
    void Sinx();
};


#endif // test_H