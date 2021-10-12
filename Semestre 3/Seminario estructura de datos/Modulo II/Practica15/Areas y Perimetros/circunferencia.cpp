#include "Circunferencia.h"
#include <math.h>

/*********************************************************************
* Comment
*********************************************************************/
void Circunferencia::setRadio(double r)
{
  this->radio=r;
}
/*********************************************************************
* Comment
*********************************************************************/
double Circunferencia::getRadio()
{
  return radio;
}
void Circunferencia::setPerimetro(){
  this->perimetro=((this->pi*this->radio)*2);
}
double Circunferencia::GetPerimetro(){
  return this->perimetro;
}
void Circunferencia::CalcularArea(){
  this->area=pow((this->pi*this->radio),2);
}
double Circunferencia::GetArea(){
  return this->area;
}
