#ifndef YEN_H
# define YEN_H
#include "Moneda.h"

class Yen:public Moneda{

public:
  double getYenPeso();
};
/*********************************************************************
* Comment
*********************************************************************/
double Yen::getYenPeso()
{
  return (GetValue()*0.17);
}

#endif
