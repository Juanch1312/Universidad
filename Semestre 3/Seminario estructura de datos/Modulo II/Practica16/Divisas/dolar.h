#ifndef DOLAR_H
# define DOLAR_H
#include "Moneda.h"

class Dolar:public Moneda{
public:
  double getDolarPeso();
};
/*********************************************************************
* Comment
*********************************************************************/
double Dolar::getDolarPeso()
{
  return (GetValue()*18.55);
}

#endif
