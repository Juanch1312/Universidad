#ifndef TRIANGULO_H
# define TRIANGULO_H
#include "Figuras.h"

class Triangulo:public Figuras{
private:
  double area;
  double perimetro;
public:
  void CalcularArea();
  double GetArea();
  void CalcularPerimetro();
  double GetPerimetro();
};
/*********************************************************************
* Comment
*********************************************************************/
void Triangulo::CalcularArea()
{
  this->area=(this->GetBase()*this->GetAltura()/2);
}
/*********************************************************************
* Comment
*********************************************************************/
double Triangulo::GetArea()
{
  return this->area;
}

/*********************************************************************
* Comment
*********************************************************************/
void Triangulo::CalcularPerimetro()
{
  this->perimetro=(this->GetBase()*3);
}
/*********************************************************************
* Comment
*********************************************************************/
double Triangulo::GetPerimetro()
{
  return this->perimetro;
}
#endif
