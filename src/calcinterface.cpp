#include "calcinterface.h"
#include <QDebug>
#include <QVariant>
#include "mathlib.h"
/**
 * @brief Set default values to variables
 */
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
/**
 * @brief Registers number presses
 * @param number
 */
void CalcInterface::number_pressed(int number)
{
    qDebug() << "Pressed Number: " << number; ///< Write to console

    if (output.count() == 13) { ///< output length is restricted to 13 characters
        return;
    }
    /**
     * if current display value is "0" or a function is waiting for number input
     * replace the current display value with the one passed to this function
     */
    if (output == QVariant("0") || wfnFlag == true)
    {
        wfnFlag = false;
        output = QString::number(number);
    }
    else { ///< Else append to the current number
        output.append(QString::number(number));
    }

}
/**
 * @brief Writes result of calculation to the display
 *
 */
void CalcInterface::equal_pressed()
{
    qDebug() << "Pressed equal "; ///< Write to console

    ///Evaluate power function before rest of calculation
    if (powFlag){
        output = QString::number( pwr(tempBase, output.toDouble()) );
        powFlag = false;
    }
    ///Division or multiplication has to be calculated before addition or subtraction
    if (divFlag || mulFlag){
        if (divFlag){
            ///calculate result of division and add or sub it from tempSum depending on plus and minus Flags
            if (minusFlag){
                tempSum -= div(tempFactor, output.toDouble());
            }else
                tempSum += div(tempFactor, output.toDouble());
        }else
        if (mulFlag){
            ///calculate result of multiplication and add or sub it from tempSum depending on plus and minus Flags
            if (minusFlag){
                tempSum -= mul(tempFactor, output.toDouble());
            }else
                tempSum += mul(tempFactor, output.toDouble());
        }
        output = QString::number(tempSum, 'g', 13);
        divFlag = false;
        tempFactor = 0;
        plusFlag = true;
        minusFlag = false;
        wfnFlag = true;
    }else
    if (plusFlag) {
        tempSum += output.toDouble(); ///< sums temporary sum with output number
        output = QString::number(tempSum, 'g', 13); ///< coverts tempSum to Qtring on 13dec presition
        plusFlag = true;
        minusFlag = false;
        wfnFlag = true; // activates waiting for number
        pointFlag = false; // resets point flag
    }else
    if (minusFlag) {
        tempSum -= output.toDouble(); ///< subs temporary sum with output number
        output = QString::number(tempSum, 'g', 13); // coverts tempSum to Qtring on 13dec presition
        plusFlag = true;
        minusFlag = false;
        wfnFlag = true;  // activates waiting for number
        pointFlag = false; // resets point flag
    }
    ///Reset flags and values so we can use result of one calculation as input into the next one
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
/// @brief adds decimal point to the number
void CalcInterface::point_pressed()
{
    qDebug() << "Pressed decimal point ";

    if (output.count() == 13) { // output restricted on 13 characters
        return;
    }

    if (pointFlag == true) { ///< prevents more points per number
        return;
    }

    output.append(QString("."));
    pointFlag = true;
}
///Add number stored in output to tempSum
void CalcInterface::plus_pressed()
{
    qDebug() << "Pressed plus ";
    ///A function is waiting for number input, operation can not be done
    if (wfnFlag){
        return;
    }
    ///Evaluate power function before rest of calculation
    if (powFlag){
        output = QString::number( pwr(tempBase, output.toDouble()) );
        powFlag = false;
    }
    ///Division or multiplication has to be calculated before addition or subtraction
    if (divFlag || mulFlag){
        ///calculate result of division and add or sub it from tempSum depending on plus and minus Flags
        if (divFlag){
            if (minusFlag){
                tempSum -= div(tempFactor, output.toDouble());
            }else
                tempSum += div(tempFactor, output.toDouble());
        }else
        ///calculate result of multiplication and add or sub it from tempSum depending on plus and minus Flags
        if (mulFlag){
            if (minusFlag){
                tempSum -= mul(tempFactor, output.toDouble());
            }else
                tempSum += mul(tempFactor, output.toDouble());
        }
        output = QString::number(tempSum, 'g', 13);
        divFlag = false;
        tempFactor = 0;
        plusFlag = true;
        minusFlag = false;
        wfnFlag = true;
        return;
    }else
    ///Add output to tempSum
    if (plusFlag) {
        tempSum += output.toDouble(); // sums temporary sum with output number
        output = QString::number(tempSum, 'g', 13); // coverts tempSum to Qtring on 13dec presition
        plusFlag = true;
        minusFlag = false;
        wfnFlag = true; // activates waiting for number
        pointFlag = false; // resets point flag
        return;
    }else
    ///Subtracts output from tempSum
    if (minusFlag) {
        tempSum -= output.toDouble(); // subs temporary sum with output number
        output = QString::number(tempSum, 'g', 13); // coverts tempSum to Qtring on 13dec presition
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
///Subtract the number stored in output from tempSum
void CalcInterface::minus_pressed()
{
    qDebug() << "Pressed minus ";
    pointFlag = false;
    ///A function is waiting for number input, operation can not be done
    if (wfnFlag){ //Waiting for number. Do nothing.
        return;
    }
    ///Evaluate power function before rest of calculation
    if (powFlag){
        output = QString::number( pwr(tempBase, output.toDouble()) );
        powFlag = false;
    }
    ///Division or multiplication has to be calculated before addition or subtraction
    if (divFlag || mulFlag){
        ///calculate result of division and add or sub it from tempSum depending on plus and minus Flags
        if (divFlag){
            if (minusFlag){
                tempSum -= div(tempFactor, output.toDouble());
            }else
                tempSum += div(tempFactor, output.toDouble());
        }else
        ///calculate result of multiplication and add or sub it from tempSum depending on plus and minus Flags
        if (mulFlag){
            if (minusFlag){
                tempSum -= mul(tempFactor, output.toDouble());
            }else
                tempSum += mul(tempFactor, output.toDouble());
        }
        output = QString::number(tempSum, 'g', 13);
        divFlag = false;
        tempFactor = 0;
        plusFlag = false;
        minusFlag = true;
        wfnFlag = true;
        return;
    }else
    ///Add output to tempSum
    if (plusFlag) {
        tempSum += output.toDouble(); // sums temporary sum with output number
        output = QString::number(tempSum, 'g', 13); // coverts tempSum to Qtring on 13dec presition
        plusFlag = false;
        minusFlag = true;
        wfnFlag = true; // activates waiting for number
        return;
    }else
    ///Subtract output from tempSum
    if (minusFlag) {
        tempSum -= output.toDouble(); // subs temporary sum with output number
        output = QString::number(tempSum, 'g', 13); // coverts tempSum to Qtring on 13dec presition
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
///Multiplies tempFact with number stored in output
void CalcInterface::multiply_pressed()
{
    qDebug() << "Pressed multiply ";
    ///A function is waiting for number input, operation can not be done
    if(wfnFlag){
        return;
    }
    ///Evaluate power function before rest of calculation
    if (powFlag){
        output = QString::number( pwr(tempBase, output.toDouble()) );
        powFlag = false;
    }
    ///Multiply tempFactor with number stored in output and save to tempFactor
    if (mulFlag) {
        tempFactor = mul(tempFactor, output.toDouble());
        output = QString::number(tempFactor, 'g', 13); // coverts tempFactor to Qtring on 13dec presition
        mulFlag = true;
        divFlag = false;
        wfnFlag = true; // activates waiting for number
        pointFlag = false; // resets point flag
        return;
    }else
    ///Divide tempFactor with number stored in output and save to tempFactor
    if (divFlag) {
        tempFactor = div(tempFactor, output.toDouble());
        output = QString::number(tempFactor, 'g', 13); // coverts tempFactor to Qtring on 13dec presition
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
///Divides tempFact with number stored in output
void CalcInterface::divide_pressed()
{
    qDebug() << "Pressed divide ";
    ///A function is waiting for number input, operation can not be done
    if (wfnFlag){ // Waiting for number, do nothing.
        return;
    }
    ///Evaluate power function before rest of calculation
    if (powFlag){
        output = QString::number( pwr(tempBase, output.toDouble()) );
        powFlag = false;
    }
    ///Divide tempFactor with number stored in output and save to tempFactor
    if (divFlag){
        tempFactor = div(tempFactor, output.toDouble());
        divFlag = true;
        mulFlag = false;
        wfnFlag = true;
        pointFlag = false;
        output = QString::number(tempFactor, 'g', 13);
        return;
    }else
    ///Multiply tempFactor with number stored in output and save to tempFactor
    if (mulFlag){
        tempFactor = mul(tempFactor, output.toDouble());
        divFlag = true;
        mulFlag = false;
        wfnFlag = true;
        pointFlag = false;
        output = QString::number(tempFactor, 'g', 13);
        return;
    }
    ///This part is executed if there was not division or multiplication immediately before
    tempFactor = output.toDouble();
    divFlag = true;
    mulFlag = false;
    wfnFlag = true;
    pointFlag = false;
}
///Restart all variables to default values
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
///Calculates square root of number stored in output and displays it
void CalcInterface::sqrt_pressed()
{
    qDebug() << "Pressed sqrt ";
    ///A function is waiting for number input, operation can not be done
    if(wfnFlag){
        return;
    }
    output = QString::number( sqroot(output.toDouble()), 'g', 13 );
}
///Calculates factorial of number stored in output and displays it
void CalcInterface::fact_pressed()
{
    qDebug() << "Pressed fact ";
    ///A function is waiting for number input, operation can not be done
    if (wfnFlag){
        return;
    }
    output = QString::number( fact(output.toDouble()), 'g', 13 );
}
///Calculates power operation with variable exponent
void CalcInterface::exp_pressed()
{
    qDebug() << "Pressed exp ";
    ///A function is waiting for number input, operation can not be done
    if (wfnFlag){
        return;
    }
    ///Base of the calculation is stored in tempBase
    tempBase = output.toDouble();
    ///powFlag is set to True
    powFlag = true;
    wfnFlag = true;
}
///Calculates value of number stored in output squared and displays it
void CalcInterface::sec_exp_pressed()
{
    qDebug() << "Pressed second exp ";
    ///A function is waiting for number input, operation can not be done
    if (wfnFlag){
        return;
    }
    output = QString::number( pwr(output.toDouble(), 2), 'g', 13 );
}
///Calculates sine of value stored in output in degrees and displays it
void CalcInterface::sin_pressed()
{
    qDebug() << "Pressed sin ";
    ///A function is waiting for number input, operation can not be done
    if (wfnFlag){
        return;
    }
    output = QString::number(sinx(output.toDouble()), 'g', 13);
}
///Calculates cosine of value stored in output in degrees and displays it
void CalcInterface::cos_pressed()
{
    qDebug() << "Pressed cos ";
    ///A function is waiting for number input, operation can not be done
    if (wfnFlag){
        return;
    }
    output = QString::number(cosx(output.toDouble()), 'g', 13);
}

/**
 * Is called whenever some button is clicked and sends Qstring output
 * to screen of calculator
 */
void CalcInterface::display(QObject *scrn)
{
    scrn->setProperty("text",QVariant(output)); ///< sends output to screen of calculator
}
