#include "calcinterface.h"
#include <QDebug>


CalcInterface::CalcInterface(QObject *parent) : QObject(parent)
{

}

void CalcInterface::number_pressed(int number)
{
    qDebug() << "Pressed Number: " << number;
}

void CalcInterface::equal_pressed()
{
    qDebug() << "Pressed equal ";
}

void CalcInterface::point_pressed()
{
    qDebug() << "Pressed decimal point ";
}

void CalcInterface::plus_pressed()
{
    qDebug() << "Pressed plus ";
}

void CalcInterface::minus_pressed()
{
    qDebug() << "Pressed minus ";
}

void CalcInterface::multiply_pressed()
{
    qDebug() << "Pressed multiply ";
}

void CalcInterface::divide_pressed()
{
    qDebug() << "Pressed divide ";
}

void CalcInterface::delete_pressed()
{
    qDebug() << "Pressed delete ";
}

void CalcInterface::sqrt_pressed()
{
    qDebug() << "Pressed sqrt ";
}

void CalcInterface::fact_pressed()
{
    qDebug() << "Pressed fact ";
}

void CalcInterface::exp_pressed()
{
    qDebug() << "Pressed exp ";
}

void CalcInterface::sec_exp_pressed()
{
    qDebug() << "Pressed second exp ";
}

void CalcInterface::sin_pressed()
{
    qDebug() << "Pressed sin ";
}

void CalcInterface::cos_pressed()
{
    qDebug() << "Pressed cos ";
}
