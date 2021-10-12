#ifndef RECTANGULO_H
# define RECTANGULO_H
#include "Figuras.h"

class Rectangulo :public Figuras{
private:
  double area;
  double perimetro;

public:
  void Calcular();
  double getArea();
};
/*********************************************************************
* Comment
*********************************************************************/
void Rectangulo::Calcular()
{
  this->area=(GetAltura()*GetBase());
}
/*********************************************************************
* Comment
*********************************************************************/
double Rectangulo::getArea()
{
  return this->area;
}
#endif
