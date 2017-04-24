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
    displayWidth = 8; // set default width of displlay to 8 characters
}


void CalcInterface::number_pressed(int number)
{
    qDebug() << "Pressed Number: " << number; // console info

    if (output.count() == displayWidth + 3) { // output restricted on 11 characters
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
        output = QString::number(tempSum, 'g', displayWidth);
    }else
    if (plusFlag) {
        tempSum += output.toDouble(); // sums temporary sum with output number
        output = QString::number(tempSum, 'g', displayWidth); // coverts tempSum to Qtring on 9dec presition
    }else
    if (minusFlag) {
        tempSum -= output.toDouble(); // subs temporary sum with output number
        output = QString::number(tempSum, 'g', displayWidth); // coverts tempSum to Qtring on 9dec presition
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
    wfnFlag = false; // set negative waiting for number
}

void CalcInterface::point_pressed()
{
    qDebug() << "Pressed decimal point ";

    if (output.count() == displayWidth + 3) { // output restricted on 11 characters
        return;
    }

    if (pointFlag) { // prevents more points per number
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
        output = QString::number(tempSum, 'g', displayWidth);
        divFlag = false;
        tempFactor = 0;
        set_flags(1);
        return;
    }else
    if (plusFlag) {
        tempSum += output.toDouble(); // sums temporary sum with output number
        output = QString::number(tempSum, 'g', displayWidth); // coverts tempSum to Qtring on 9dec presition
        set_flags(1);
        return;
    }else
    if (minusFlag) {
        tempSum -= output.toDouble(); // subs temporary sum with output number
        output = QString::number(tempSum, 'g', displayWidth); // coverts tempSum to Qtring on 9dec presition
        set_flags(1);
        return;
    }

    tempSum += output.toDouble(); // sums temporary sum (0) with output number
    set_flags(1);

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
        output = QString::number(tempSum, 'g', displayWidth);
        divFlag = false;
        tempFactor = 0;
        set_flags(2);
        return;
    }else
    if (plusFlag) {
        tempSum += output.toDouble(); // sums temporary sum with output number
        output = QString::number(tempSum, 'g', displayWidth); // coverts tempSum to Qtring on 9dec presition
        set_flags(2);
        return;
    }else
    if (minusFlag) {
        tempSum -= output.toDouble(); // subs temporary sum with output number
        output = QString::number(tempSum, 'g', displayWidth); // coverts tempSum to Qtring on 9dec presition
        set_flags(2);
        return;
    }
    qDebug() << "Debug";
    tempSum += output.toDouble(); // sums temporary sum (0) with output number
    set_flags(2);
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
        output = QString::number(tempFactor, 'g', displayWidth); // coverts tempFactor to Qtring on 9dec presition
        set_flags(3);
        return;
    }else
    if (divFlag) {
        tempFactor = div(tempFactor, output.toDouble());
        output = QString::number(tempFactor, 'g', displayWidth); // coverts tempFactor to Qtring on 9dec presition
        set_flags(3);
        return;
    }

    tempFactor = output.toDouble();
    set_flags(3);
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
        set_flags(4);
        output = QString::number(tempFactor, 'g', displayWidth);
        return;
    }else
    if (mulFlag){
        tempFactor = mul(tempFactor, output.toDouble());
        set_flags(4);
        output = QString::number(tempFactor, 'g', displayWidth);
        return;
    }

    tempFactor = output.toDouble();
    set_flags(4);
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

    if (output.toDouble() < 0){
        delete_pressed();
        output = QString("Math Error");
        wfnFlag = true;
        return;
    }


    output = QString::number( sqroot(output.toDouble()), 'g', displayWidth );

}

void CalcInterface::fact_pressed()
{
    qDebug() << "Pressed fact ";
    if (wfnFlag){
        return;
    }

    if (output.toDouble() < 0){
        delete_pressed();
        output = QString("Math Error");
        wfnFlag = true;
        return;
    }

    output = QString::number( fact(output.toDouble()), 'g', displayWidth );

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
    output = QString::number( pwr(output.toDouble(), 2), 'g', displayWidth );
}

void CalcInterface::sin_pressed()
{
    qDebug() << "Pressed sin ";
    if (wfnFlag){
        return;
    }
    
    double temp = sinx(output.toDouble());
    if (fabs(temp) < 0.00000000001) {
        temp = 0.0;
    }
    
    output = QString::number(temp, 'g', displayWidth);
}

void CalcInterface::cos_pressed()
{
    qDebug() << "Pressed cos ";
    if (wfnFlag){
        return;
    }
    
    double temp = cosx(output.toDouble());
    if (fabs(temp) < 0.00000000001) {
        temp = 0.0;
    }
    
    output = QString::number(temp, 'g', displayWidth);
}

/*
 * Is called whenever some button is clicked and sends Qstring output
 * to screen of calculator
 */
void CalcInterface::display(QObject *scrn)
{
    scrn->setProperty("text",QVariant(output)); // sends output to screen of calculator
}

/*
 *  Sets flags for plus, minus, mul, div based on option
 */
void CalcInterface::set_flags(int option)
{
    switch (option) {
    case 1: { // plus
        plusFlag = true;
        minusFlag = false;
        wfnFlag = true; // activates waiting for number
        pointFlag = false; // resets point flag
        break;
    }
    case 2: { // minus
        plusFlag = false;
        minusFlag = true;
        wfnFlag = true; // activates waiting for number
        pointFlag = false; // resets point flag
        break;
    }
    case 3: { // multiply
        mulFlag = true;
        divFlag = false;
        wfnFlag = true; // activates waiting for number
        pointFlag = false; // resets point flag
        break;
    }
    case 4: { // divide
        mulFlag = false;
        divFlag = true;
        wfnFlag = true; // activates waiting for number
        pointFlag = false; // resets point flag
        break;
    }
    default:
        break;
    }
}

