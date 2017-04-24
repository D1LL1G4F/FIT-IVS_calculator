/**
 * @class CalcInterface
 * @brief Provides logic for calculator
 * This class implements "_pressed" function for every button.
 * "_pressed" functions are called whenever their corresponding button is pressed.
 *
 */
#ifndef CALCINTERFACE_H
#define CALCINTERFACE_H

#include <QObject>
#include <QDebug>
#include <QString>

class CalcInterface : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Set default values to variables
     */
    explicit CalcInterface(QObject *parent = 0);
    /**
     * @brief Registers number presses
     * Reads number presses if current number is shorter than displayWidth variable
     * @param number Specific number 0-9
     */
    Q_INVOKABLE void number_pressed(int number);
    /**
     * @brief Writes result of calculation to the display
     */
    Q_INVOKABLE void equal_pressed();
    /**
     * @brief adds decimal point to the number
     * @pre Number mustn't contain decimal point already.
     */
    Q_INVOKABLE void point_pressed();
    /**
     * @brief Add number stored in output to tempSum
     */
    Q_INVOKABLE void plus_pressed();
    /**
     * @brief Subtract the number stored in output from tempSum
     */
    Q_INVOKABLE void minus_pressed();
    /**
     * @brief Multiplies tempFact with number stored in output
     */
    Q_INVOKABLE void multiply_pressed();
    /**
     * @brief Divides tempFact with number stored in output
     */
    Q_INVOKABLE void divide_pressed();
    /**
     * @brief Restart all variables to default values
     */
    Q_INVOKABLE void delete_pressed();
    /**
     * @brief Calculates square root of number stored in output and displays it
     */
    Q_INVOKABLE void sqrt_pressed();
    /**
     * @brief Calculates factorial of number stored in output and displays it
     */
    Q_INVOKABLE void fact_pressed();
    /**
     * @brief Calculates power operation with variable exponent
     */
    Q_INVOKABLE void exp_pressed();
    /**
     * @brief Calculates value of number stored in output squared and displays it
     */
    Q_INVOKABLE void sec_exp_pressed();
    /**
     * @brief Calculates sine of value stored in output in degrees and displays it
     */
    Q_INVOKABLE void sin_pressed();
    /**
     * @brief Calculates cosine of value stored in output in degrees and displays it
     */
    Q_INVOKABLE void cos_pressed();
    /**
     * @brief Print the output on the display
     * @param scrn Pointer to the display - text object
     */
    Q_INVOKABLE void display(QObject *scrn);

signals:

public slots:

private:

    QString output; ///< string printed onto the display
    int displayWidth; ///< Maximum length of displayed string in characters
    double tempSum; ///< stores value of sum so far
    double tempFactor; ///< stores value of factor so far
    double tempBase; ///< stores base for power with variable exponent
    bool pointFlag; ///< indicates presence of decimal point
    bool plusFlag; ///< indicates presence of plus operator
    bool minusFlag; ///< indicates presence of minus operator
    bool divFlag; ///< indicates presence of divide operator
    bool mulFlag; ///< indicates presence of multiply operator
    bool powFlag; ///< indicates presence of power operator
    bool wfnFlag; ///< indicates if there is waiting for number
    void set_flags(int option);

};

#endif // CALCINTERFACE_H
