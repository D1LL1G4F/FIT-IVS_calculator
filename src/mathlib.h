#ifndef MATHLIB_H
#define MATHLIB_H
/**
 * @file mathlib.h
 * @brief Simple mathematics library
 */
/**
 * @brief Addition
 * @param First operand
 * @param Second operand
 * @return Sum of operands, a + b
 */
double sum(double a, double b);
/**
 * @brief Subtraction
 * @param First operand
 * @param Second operand
 * @return B subtracted from A , a - b
 */
double sub(double a, double b);
/**
 * @brief Multiplication
 * @param First operand
 * @param Second operand
 * @return A times B, a * b
 */
double mul(double a, double b);
/**
 * @brief Division
 * @pre Second operand mustn't be zero
 * @param First operand
 * @param Second operand
 * @return A divided by B, a / b
 */
double div(double divident, double divisor);
/**
 * @brief Square root
 * @param Operand
 * @return Approximate value of square root of operand
 * @pre Operand must be a positive number
 */
double sqroot(double radicand);
/**
 * @brief Factorial
 * @param Operand
 * @return Factorial of operand, num!
 * @pre Operand must be positive number
 */
double fact(double num);
/**
 * @brief Power function
 *
 *      Calculates value of variable to the power of constant, value^constant
 * @param Base
 * @param Exponent
 * @return Base to the power of exponent, base ^ exponent
 */
double pwr(double variable, double constant);
/**
 * @brief Cosine function
 * @param Operand
 * @pre Operand must be in degrees
 * @return cosine of operand
 */
double cosx(double x);
/**
 * @brief Sine function
 * @param Operand
 * @pre Operand must be in degrees
 * @return sine of operand
 */
double sinx(double x);





#endif // MATHLIB_H
