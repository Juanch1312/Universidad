#ifndef YUAN_H
# define YUAN_H
#include "Moneda.h"

class Yuan:public Moneda{

public:
  double getYuanPeso();
};

double Yuan::getYuanPeso()
{
  return (GetValue()*2.66);
}
#endif
