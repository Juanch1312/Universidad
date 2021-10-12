#ifndef FAHRENHEIT_H
# define FAHRENHEIT_H
#include "Grados.h"

class Fahrenheit:public Grados{
public:
  double getCelcius();
};
/*********************************************************************
* Comment
*********************************************************************/
double Fahrenheit::getCelcius()
{
  return (GetTemperatura()-32)*5/9;
}
#endif
