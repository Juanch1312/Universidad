#ifndef CUADRADO_H
# define CUADRADO_H
#include "Figuras.h"

class Cuadrado: public Figuras{
private:
  double area;
public:
  void Calcular();
  double getArea();
};
/*********************************************************************
* Comment
*********************************************************************/
void Cuadrado::Calcular()
{
  this->area=GetBase()*GetBase();
}
/*********************************************************************
* Comment
*********************************************************************/
double Cuadrado::getArea()
{
  return this->area;
}

#endif
