#include "mathlib.h"
#define PI 3.14159265

double sum(double a, double b)
{
    return a+b;
}

double sub(double a, double b)
{
    return a-b;
}

double mul(double a, double b)
{
    return a*b;
}

double div(double divident, double divisor)
{
    return divident/divisor;
}

double sqroot(double radicand)
{
  double x=radicand;
  double y = 1;
  double e = 0.000001; //e urcuje presnost
  while(x - y > e)
	{
		x = (x + y)/2;
		y = n/x;
	}
  return x;
}

double fact(double num)
{
  int factorial = 1;
  for ( int i=1; i<=num; i++ )
  {
	  factorial = factorial*i;
  }
  return factorial;
}

double pwr(double variable, double constant)
{
    //TODO...
}

double cosx(double x)
{
    //TODO...
}

double sinx(double x)
{
    //TODO...
}