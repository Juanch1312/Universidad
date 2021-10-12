#ifndef RECTANGULO_H
# define RECTANGULO_H
#include "Figuras.h"

class Rectangulo :public Figuras{
private:
  double area;
  double perimetro;

public:
  void CalcularArea();
  void CalcularPerimetro();
  double getArea();
  double getPerimetro();
};
/*********************************************************************
* Comment
*********************************************************************/
void Rectangulo::CalcularArea()
{
  this->area=(GetAltura()*GetBase());
}
/*********************************************************************
* Comment
*********************************************************************/
void Rectangulo::CalcularPerimetro()
{
  this->perimetro=(GetBase()*2)+(GetAltura()*2);
}
/*********************************************************************
* Comment
*********************************************************************/
double Rectangulo::getArea()
{
  return this->area;
}
/*********************************************************************
* Comment
*********************************************************************/
double Rectangulo::getPerimetro()
{
  return this->perimetro;
}
#endif
