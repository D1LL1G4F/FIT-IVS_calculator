#include "calcinterface.h"
#include <QDebug>
#include <QVariant>
#include "mathlib.h"

CalcInterface::CalcInterface(QObject *parent) : QObject(parent)
{
    output = "0"; // set default output
    pointFlag = false; // set default pointFlag
}

void CalcInterface::number_pressed(int number)
{
    qDebug() << "Pressed Number: " << number; // console info

    if (output.count() == 13) { // output restricted on 13 characters
        return;
    }

    if (output == QVariant("0")) // in case there is only zero replace it
    {
        output = QString::number(number);
    }
    else { // else append
        output.append(QString::number(number));
    }

}

void CalcInterface::equal_pressed()
{
    qDebug() << "Pressed equal ";
}

void CalcInterface::point_pressed()
{
    qDebug() << "Pressed decimal point ";

    if (output.count() == 13) { // output restricted on 13 characters
        return;
    }

    if (pointFlag == true) { // prevents more points per number
        return;
    }

    output.append(QString("."));
    pointFlag = true;
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
    output = "0";
    pointFlag = false;
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

/*
 * Is called whenever some button is clicked and sends Qstring output
 * to screen of calculator
 */
void CalcInterface::display(QObject *scrn)
{
    scrn->setProperty("text",QVariant(output)); // sends output to screen of calculator
}
