#ifndef CUADRADO_H
# define CUADRADO_H
#include "Figuras.h"

class Cuadrado: public Figuras{
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
void Cuadrado::CalcularArea()
{
  this->area=GetBase()*GetBase();
}
/*********************************************************************
* Comment
*********************************************************************/
void Cuadrado::CalcularPerimetro()
{
  this->perimetro=GetBase()*4;
}
/*********************************************************************
* Comment
*********************************************************************/
double Cuadrado::getArea()
{
  return this->area;
}
double Cuadrado::getPerimetro(){
  return this->perimetro;
}

#endif
