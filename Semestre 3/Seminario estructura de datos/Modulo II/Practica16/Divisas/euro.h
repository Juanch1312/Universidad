#ifndef EURO_H
# define EURO_H
#include "Moneda.h"

class Euro:public Moneda{

public:
  double getEuroPeso();
};
/*********************************************************************
* Comment
*********************************************************************/
double Euro::getEuroPeso()
{
  return (GetValue()*20.1);
}

#endif
