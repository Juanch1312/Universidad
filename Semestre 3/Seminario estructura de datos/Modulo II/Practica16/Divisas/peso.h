#ifndef PESO_H
# define PESO_H
#include "Moneda.h"

class Peso:public Moneda{
public:
  double getPesoDolar();
  double getPesoEuro();
  double getPesoYen();
  double getPesoYuan();
};
/*********************************************************************
* Comment
*********************************************************************/
double Peso::getPesoDolar()
{
  return (GetValue()*0.054);
}
/*********************************************************************
* Comment
*********************************************************************/
double Peso::getPesoEuro()
{
  return (GetValue()*0.05);
}
/*********************************************************************
* Comment
*********************************************************************/
double Peso::getPesoYen()
{
  return(GetValue()*5.93);
}
/*********************************************************************
* Comment
*********************************************************************/
double Peso::getPesoYuan()
{
  return (GetValue()*0.38);
}
#endif
