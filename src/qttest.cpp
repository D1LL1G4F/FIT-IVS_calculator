#include <QtTest>
#include <stdexcept>
#include "mathlib.h"
#include "test.h"


void  Test::Sum() 
{
    //test for sum
    QCOMPARE(mathlib::sum(8,5),13.0);
    QCOMPARE(mathlib::sum(4,0),4.0);
    QCOMPARE(mathlib::sum(0,4),4.0);
    QCOMPARE(mathlib::sum(3.2,11.5),14.7);
    QCOMPARE(mathlib::sum(-5,1),-4.0);
    QCOMPARE(mathlib::sum(1,-5),-4.0);
    QCOMPARE(mathlib::sum(-18,-12),-30.0);
    QCOMPARE(mathlib::sum(-3.2,-11.5),-14.7);
    QCOMPARE(mathlib::sum(84637,17659),102296.0);
    QCOMPARE(mathlib::sum(-84637,-17659),-102296.0);

}

void Test::Sub() 
{
    //test for sub
    QCOMPARE(mathlib::sub(5,2),3.0);
    QCOMPARE(mathlib::sub(4,0),4.0);
    QCOMPARE(mathlib::sub(0,4),-4.0);
    QCOMPARE(mathlib::sub(3.6,3.2),0.4);
    QCOMPARE(mathlib::sub(3.6,-3.2),6.8);
    QCOMPARE(mathlib::sub(-3.6,3.2),-6.8);
    QCOMPARE(mathlib::sub(-3.6,-3.2),-0.4);
    QCOMPARE(mathlib::sub(56789,17631),39158);
    QCOMPARE(mathlib::sub(56789,-17631),74420);
    QCOMPARE(mathlib::sub(-56789,17631),-74420);
    QCOMPARE(mathlib::sub(-56789,-17631),-39158);

}

void Test::Mul() 
{
    //test for mul
    QCOMPARE(mathlib::mul(5,5),25.0);
    QCOMPARE(mathlib::mul(0,5),0.0);
    QCOMPARE(mathlib::mul(5,0),0.0);
    QCOMPARE(mathlib::mul(1695,525),889875.0);
    QCOMPARE(mathlib::mul(5.2,3.9),20.28);
    QCOMPARE(mathlib::mul(5,-5),-25.0);
    QCOMPARE(mathlib::mul(-5,5),-25.0);
    QCOMPARE(mathlib::mul(-5,-5),25.0);
    QCOMPARE(mathlib::mul(-1695,525),-889875.0);
    QCOMPARE(mathlib::mul(1695,-525),-889875.0);
    QCOMPARE(mathlib::mul(-1695,-525),889875.0);
}
void Test::Div() 
{
    //test for div
    QCOMPARE(mathlib::div(0,5),0.0);
    QCOMPARE(mathlib::div(15,3),5.0);
    QCOMPARE(mathlib::div(15,4),3.75);
    QCOMPARE(mathlib::div(889875,1695),525.0);
    QCOMPARE(mathlib::div(20.28,5.2),3.9);
    QCOMPARE(mathlib::div(15,-3),-5.0);
    QCOMPARE(mathlib::div(-15,4),-3.75);
    QCOMPARE(mathlib::div(-889875,-1695),525.0);
    QCOMPARE(mathlib::div(2,4),0.5);
    //QCOMPARE(mathlib::div(5,0),error);
}
void Test::Sqroot() 
{
    //test for sqroot
    QCOMPARE(mathlib::sqroot(4),2.0);
    QCOMPARE(mathlib::sqroot(17.64),4.2);
    QCOMPARE(mathlib::sqroot(1),1.0);
    QCOMPARE(mathlib::sqroot(0),0.0);
    QCOMPARE(mathlib::sqroot(276676),526.0);
    //QCOMPARE(mathlib::sqroot(-5),error);
}
void Test::Fact() 
{
    //test for fact
    QCOMPARE(mathlib::fact(0),1);
    QCOMPARE(mathlib::fact(1),1);
    QCOMPARE(mathlib::fact(5),120);
    QCOMPARE(mathlib::fact(11),39916800);
    //QCOMPARE(mathlib::fact(-5),error);
}
void Test::Pwr() 
{
    //test for pwr
    QCOMPARE(mathlib::pwr(2,2),4.0);
    QCOMPARE(mathlib::pwr(16,3),4096.0);
    QCOMPARE(mathlib::pwr(1,15),1.0);
    QCOMPARE(mathlib::pwr(5,0),1);
    QCOMPARE(mathlib::pwr(5,1),5);
    QCOMPARE(mathlib::pwr(-5,2),25);
    QCOMPARE(mathlib::pwr(-5,3),-125);
    QCOMPARE(mathlib::pwr(2,-2),0.25);
}
void Test::Cosx() 
{
    //test for cosx
    QCOMPARE(mathlib::cosx(0),1);
    QCOMPARE(mathlib::cosx(60),0.5);
    QCOMPARE(mathlib::cosx(90),0.0);
    QCOMPARE(mathlib::cosx(180),-1.0);
    QCOMPARE(mathlib::cosx(240),-0.5);
    QCOMPARE(mathlib::cosx(270),0.0);
    QCOMPARE(mathlib::cosx(360),1.0);
    QCOMPARE(mathlib::cosx(420),0.5);
    QCOMPARE(mathlib::cosx(720),1.0);
}
void Test::Sinx() 
{
    //test for sinx
    QCOMPARE(mathlib::sinx(0),0.0);
    QCOMPARE(mathlib::sinx(30),0.5);
    QCOMPARE(mathlib::sinx(90),1.0);
    QCOMPARE(mathlib::sinx(180),0.0);
    QCOMPARE(mathlib::sinx(270),-1.0);
    QCOMPARE(mathlib::sinx(330),-0.5);
    QCOMPARE(mathlib::sinx(360),0.0);
    QCOMPARE(mathlib::sinx(390),0.5);
    QCOMPARE(mathlib::sinx(720),0.0);


}