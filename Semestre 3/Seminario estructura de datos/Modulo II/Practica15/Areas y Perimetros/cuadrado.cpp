#include "Cuadrado.h"


/*********************************************************************
* Comment
*********************************************************************/
void Cuadrado::setLado(double lado)
{
  this->lado=lado;
}
/*********************************************************************
* Comment
*********************************************************************/
double Cuadrado::getLado()
{
  return this->lado=(this->lado*this->lado);
}

void Cuadrado::setPerimetro(){
  this->perimetro=(this->lado)*4;
}

double Cuadrado::GetPerimetro(){
  return this->perimetro;
}
