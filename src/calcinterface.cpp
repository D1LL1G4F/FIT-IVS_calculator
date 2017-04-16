#include "calcinterface.h"
#include <QDebug>
#include <QVariant>
#include "mathlib.h"

CalcInterface::CalcInterface(QObject *parent) : QObject(parent)
{
    output = "0"; // set default output
    tempSum = 0.0; // set default sum so far
    tempFactor = 0.0; // set default factor so far
    pointFlag = false; // set default pointFlag
    plusFlag = false; // set default plus operator
    minusFlag = false; // set default minus operator
    divFlag = false; // set default division operator
    mulFlag = false; // set default multiply operator
    powFLag = false; // set default power operator
    wfnFlag = false; // set defualt waiting for number indicator
}

void CalcInterface::number_pressed(int number)
{
    qDebug() << "Pressed Number: " << number; // console info

    if (output.count() == 13) { // output restricted on 13 characters
        return;
    }

    if (output == QVariant("0") || wfnFlag == true) // in case there is only zero or smthng waits for number replace it
    {
        wfnFlag = false;
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
    /*
     * BUG!!! after pressing plus operand point_pressed doesn't work... :(
     */
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

    if (plusFlag) {
        tempSum += output.toDouble(); // sums temporary sum with output number
        output = QString::number(tempSum, 'g', 13); // coverts tempSum to Qtring on 13dec presition
        plusFlag = true;
        minusFlag = false;
        wfnFlag = true; // activates waiting for number
        return;
    }

    if (minusFlag) {
        tempSum -= output.toDouble(); // subs temporary sum with output number
        output = QString::number(tempSum, 'g', 13); // coverts tempSum to Qtring on 13dec presition
        plusFlag = true;
        minusFlag = false;
        wfnFlag = true;  // activates waiting for number
        return;
    }

    tempSum += output.toDouble(); // sums temporary sum (0) with output number
    plusFlag = true;
    minusFlag = false;
    output = "0";
    wfnFlag = true; // activates waiting for number

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
    qDebug() << "Pressed delete "; // console info

    output = "0"; // set default output
    tempSum = 0.0; // set default sum so far
    tempFactor = 0.0; // set default factor so far
    pointFlag = false; // set default pointFlag
    plusFlag = false; // set default plus operator
    minusFlag = false; // set default minus operator
    divFlag = false; // set default division operator
    mulFlag = false; // set default multiply operator
    powFLag = false; // set default power operator
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
