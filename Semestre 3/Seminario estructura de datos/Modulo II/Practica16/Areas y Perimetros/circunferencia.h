#ifndef CIRCUNFERENCIA_H
# define CIRCUNFERENCIA_H
#include "Figuras.h"
#include <math.h>

class Circunferencia:public Figuras{
private:
  float pi=3.141592;
  double radio;
  double perimetro;
  double area;
public:
  void SetRadio(double);
  void CalcularPerimetro();
  void CalcularArea();

  double GetArea();
  double GetPerimetro();
};
/*********************************************************************
* Comment
*********************************************************************/
void Circunferencia::SetRadio(double r)
{
  this->radio = r;
}
/*********************************************************************
* Comment
*********************************************************************/
void Circunferencia::CalcularPerimetro()
{
  this->perimetro=((this->pi*this->radio)*2);
}
/*********************************************************************
* Comment
*********************************************************************/
void Circunferencia::CalcularArea()
{
  this->area=pow((this->pi*this->radio),2);
}
/*********************************************************************
* Comment
*********************************************************************/
double Circunferencia::GetArea()
{
  return this->area;
}
/*********************************************************************
* Comment
*********************************************************************/
double Circunferencia::GetPerimetro()
{
  return this->perimetro;
}
#endif
