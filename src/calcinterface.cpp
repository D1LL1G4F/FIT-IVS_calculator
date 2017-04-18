#include "calcinterface.h"
#include <QDebug>
#include <QVariant>
#include "mathlib.h"

CalcInterface::CalcInterface(QObject *parent) : QObject(parent)
{
    output = "0"; // set default output
    tempSum = 0.0; // set default sum so far
    tempFactor = 0.0; // set default factor so far
    tempBase = 0.0; // set default base
    pointFlag = false; // set default pointFlag
    plusFlag = false; // set default plus operator
    minusFlag = false; // set default minus operator
    divFlag = false; // set default division operator
    mulFlag = false; // set default multiply operator
    powFlag = false; // set default power operator
    wfnFlag = false; // set defualt waiting for number indicator
}

void CalcInterface::number_pressed(int number)
{
    qDebug() << "Pressed Number: " << number; // console info

    if (output.count() == 11) { // output restricted on 11 characters
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
    if (powFlag){
        output = QString::number( pwr(tempBase, output.toDouble()) );
        powFlag = false;
    }
    if (divFlag || mulFlag){
        if (divFlag){
            if (minusFlag){
                tempSum -= div(tempFactor, output.toDouble());
            }else
                tempSum += div(tempFactor, output.toDouble());
        }else
        if (mulFlag){
            if (minusFlag){
                tempSum -= mul(tempFactor, output.toDouble());
            }else
                tempSum += mul(tempFactor, output.toDouble());
        }
        output = QString::number(tempSum, 'g', 11);
    }else
    if (plusFlag) {
        tempSum += output.toDouble(); // sums temporary sum with output number
        output = QString::number(tempSum, 'g', 11); // coverts tempSum to Qtring on 13dec presition
    }else
    if (minusFlag) {
        tempSum -= output.toDouble(); // subs temporary sum with output number
        output = QString::number(tempSum, 'g', 11); // coverts tempSum to Qtring on 13dec presition
    }
    tempSum = 0.0;
    tempFactor = 0.0; // set default factor so far
    tempBase = 0.0; // set default base
    pointFlag = false; // set default pointFlag
    plusFlag = true; // set default plus operator
    minusFlag = false; // set default minus operator
    divFlag = false; // set default division operator
    mulFlag = false; // set default multiply operator
    powFlag = false; // set default power operator
    wfnFlag = false;
}

void CalcInterface::point_pressed()
{
    qDebug() << "Pressed decimal point ";

    if (output.count() == 11) { // output restricted on 13 characters
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
    if (wfnFlag){
        return;
    }
    if (powFlag){
        output = QString::number( pwr(tempBase, output.toDouble()) );
        powFlag = false;
    }
    if (divFlag || mulFlag){
        if (divFlag){
            if (minusFlag){
                tempSum -= div(tempFactor, output.toDouble());
            }else
                tempSum += div(tempFactor, output.toDouble());
        }else
        if (mulFlag){
            if (minusFlag){
                tempSum -= mul(tempFactor, output.toDouble());
            }else
                tempSum += mul(tempFactor, output.toDouble());
        }
        output = QString::number(tempSum, 'g', 9);
        divFlag = false;
        tempFactor = 0;
        plusFlag = true;
        minusFlag = false;
        wfnFlag = true;
        return;
    }else
    if (plusFlag) {
        tempSum += output.toDouble(); // sums temporary sum with output number
        output = QString::number(tempSum, 'g', 9); // coverts tempSum to Qtring on 13dec presition
        plusFlag = true;
        minusFlag = false;
        wfnFlag = true; // activates waiting for number
        pointFlag = false; // resets point flag
        return;
    }else
    if (minusFlag) {
        tempSum -= output.toDouble(); // subs temporary sum with output number
        output = QString::number(tempSum, 'g', 9); // coverts tempSum to Qtring on 13dec presition
        plusFlag = true;
        minusFlag = false;
        wfnFlag = true;  // activates waiting for number
        pointFlag = false; // resets point flag
        return;
    }

    tempSum += output.toDouble(); // sums temporary sum (0) with output number
    plusFlag = true;
    minusFlag = false;
    wfnFlag = true; // activates waiting for number
    pointFlag = false; // resets point flag

}

void CalcInterface::minus_pressed()
{
    qDebug() << "Pressed minus ";
    pointFlag = false;
    if (wfnFlag){ //Waiting for number. Do nothing.
        return;
    }
    if (powFlag){
        output = QString::number( pwr(tempBase, output.toDouble()) );
        powFlag = false;
    }
    if (divFlag || mulFlag){
        if (divFlag){
            if (minusFlag){
                tempSum -= div(tempFactor, output.toDouble());
            }else
                tempSum += div(tempFactor, output.toDouble());
        }else
        if (mulFlag){
            if (minusFlag){
                tempSum -= mul(tempFactor, output.toDouble());
            }else
                tempSum += mul(tempFactor, output.toDouble());
        }
        output = QString::number(tempSum, 'g', 9);
        divFlag = false;
        tempFactor = 0;
        plusFlag = false;
        minusFlag = true;
        wfnFlag = true;
        return;
    }else
    if (plusFlag) {
        tempSum += output.toDouble(); // sums temporary sum with output number
        output = QString::number(tempSum, 'g', 9); // coverts tempSum to Qtring on 13dec presition
        plusFlag = false;
        minusFlag = true;
        wfnFlag = true; // activates waiting for number
        return;
    }else
    if (minusFlag) {
        tempSum -= output.toDouble(); // subs temporary sum with output number
        output = QString::number(tempSum, 'g', 9); // coverts tempSum to Qtring on 13dec presition
        plusFlag = false;
        minusFlag = true;
        wfnFlag = true;  // activates waiting for number
        return;
    }
    qDebug() << "Debug";
    tempSum += output.toDouble(); // sums temporary sum (0) with output number
    plusFlag = false;
    minusFlag = true;
    wfnFlag = true; // activates waiting for number
}

void CalcInterface::multiply_pressed()
{
    qDebug() << "Pressed multiply ";
    if(wfnFlag){
        return;
    }
    if (powFlag){
        output = QString::number( pwr(tempBase, output.toDouble()) );
        powFlag = false;
    }
    if (mulFlag) {
        tempFactor = mul(tempFactor, output.toDouble());
        output = QString::number(tempFactor, 'g', 9); // coverts tempFactor to Qtring on 13dec presition
        mulFlag = true;
        divFlag = false;
        wfnFlag = true; // activates waiting for number
        pointFlag = false; // resets point flag
        return;
    }else
    if (divFlag) {
        tempFactor = div(tempFactor, output.toDouble());
        output = QString::number(tempFactor, 'g', 9); // coverts tempFactor to Qtring on 13dec presition
        mulFlag = true;
        divFlag = false;
        wfnFlag = true; // activates waiting for number
        pointFlag = false; // resets point flag
        return;
    }

    tempFactor += output.toDouble();
    mulFlag = true;
    divFlag = false;
    wfnFlag = true; // activates waiting for number
    pointFlag = false; // resets point flag
}

void CalcInterface::divide_pressed()
{
    qDebug() << "Pressed divide ";
    if (wfnFlag){ // Waiting for number, do nothing.
        return;
    }
    if (powFlag){
        output = QString::number( pwr(tempBase, output.toDouble()) );
        powFlag = false;
    }
    if (divFlag){
        tempFactor = div(tempFactor, output.toDouble());
        divFlag = true;
        mulFlag = false;
        wfnFlag = true;
        pointFlag = false;
        output = QString::number(tempFactor, 'g', 9);
        return;
    }else
    if (mulFlag){
        tempFactor = mul(tempFactor, output.toDouble());
        divFlag = true;
        mulFlag = false;
        wfnFlag = true;
        pointFlag = false;
        output = QString::number(tempFactor, 'g', 9);
        return;
    }

    tempFactor = output.toDouble();
    divFlag = true;
    mulFlag = false;
    wfnFlag = true;
    pointFlag = false;
}

void CalcInterface::delete_pressed()
{
    qDebug() << "Pressed delete "; // console info

    output = "0"; // set default output
    tempSum = 0.0; // set default sum so far
    tempFactor = 0.0; // set default factor so far
    tempBase = 0.0; // set default base
    pointFlag = false; // set default pointFlag
    plusFlag = false; // set default plus operator
    minusFlag = false; // set default minus operator
    divFlag = false; // set default division operator
    mulFlag = false; // set default multiply operator
    powFlag = false; // set default power operator
}

void CalcInterface::sqrt_pressed()
{
    qDebug() << "Pressed sqrt ";
    if(wfnFlag){
        return;
    }
    output = QString::number( sqroot(output.toDouble()), 'g', 9 );
}

void CalcInterface::fact_pressed()
{
    qDebug() << "Pressed fact ";
    if (wfnFlag){
        return;
    }
    output = QString::number( fact(output.toDouble()), 'g', 9 );
}

void CalcInterface::exp_pressed()
{
    qDebug() << "Pressed exp ";
    if (wfnFlag){
        return;
    }
    tempBase = output.toDouble();
    powFlag = true;
    wfnFlag = true;
}

void CalcInterface::sec_exp_pressed()
{
    qDebug() << "Pressed second exp ";
        if (wfnFlag){
        return;
    }
    output = QString::number( pwr(output.toDouble(), 2), 'g', 9 );
}

void CalcInterface::sin_pressed()
{
    qDebug() << "Pressed sin ";
    if (wfnFlag){
        return;
    }
    output = QString::number(sinx(output.toDouble()), 'g', 9);
}

void CalcInterface::cos_pressed()
{
    qDebug() << "Pressed cos ";
    if (wfnFlag){
        return;
    }
    output = QString::number(cosx(output.toDouble()), 'g', 9);
}

/*
 * Is called whenever some button is clicked and sends Qstring output
 * to screen of calculator
 */
void CalcInterface::display(QObject *scrn)
{
    scrn->setProperty("text",QVariant(output)); // sends output to screen of calculator
}
