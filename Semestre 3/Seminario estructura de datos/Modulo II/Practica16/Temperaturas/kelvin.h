#ifndef KELVIN_H
# define KELVIN_H
#include "Grados.h"

class Kelvin:public Grados{
private:
  double temperatura;

public:
  double getCelcius();
};
/*********************************************************************
* Comment
*********************************************************************/
double Kelvin::getCelcius()
{
  return(GetTemperatura()-273.15);
}
#endif
