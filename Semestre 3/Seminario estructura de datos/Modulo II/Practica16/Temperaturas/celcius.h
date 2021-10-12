#ifndef CELCIUS_H
# define CELCIUS_H
#include "Grados.h"

class Celcius:public Grados{
public:
  double getKelvin();
  double getFahrenheit();
};
/*********************************************************************
* Comment
*********************************************************************/
double Celcius::getKelvin()
{
  return (GetTemperatura()+273.15);
}
/*********************************************************************
* Comment
*********************************************************************/
double Celcius::getFahrenheit()
{
  return (GetTemperatura()*9/5)+32;
}

#endif
