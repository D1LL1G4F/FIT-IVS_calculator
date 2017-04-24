#include "mathlib.h"
#include <math.h>
#define PI 3.141592653589793

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
  double y=1;
  double e=0.000000000001; //e urcuje presnost
  while(x-y>e)
	{
		x=(x+y)/2;
		y=radicand/x;
	}
  return x;
}

double fact(double num)
{
  unsigned int factorial = 1; //overflow?
  for (unsigned int i=1;i<=num;i++)
  {
	  factorial=factorial*i;
  }
  return factorial;
}

double pwr(double variable, double constant)
{
    return pow(variable,constant);
}

double cosx(double x) //x=angle
{
  double cosin;
  cosin=cos(x*PI/180.0);
  return cosin;
}

double sinx(double x) //x=angle
{
  double sinus;
  sinus=sin(x*PI/180.0);
  return sinus;
}
