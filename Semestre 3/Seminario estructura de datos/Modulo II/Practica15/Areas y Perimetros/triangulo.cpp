#include "Triangulo.h"
/*********************************************************************
* Comment
*********************************************************************/
void Triangulo::SetBase(double base)
{
  this->base=base;
}
/*********************************************************************
* Comment
*********************************************************************/
double Triangulo::GetBase()
{
  return this->base;
}
/*********************************************************************
* Comment
*********************************************************************/
void Triangulo::SetAltura(double Altura)
{
  this->altura=Altura;
}
/*********************************************************************
* Comment
*********************************************************************/
double Triangulo::GetAltura()
{
  return this->altura;
}
/*********************************************************************
* Comment
*********************************************************************/
void Triangulo::CalcularArea()
{
  this->area=(this->base*this->altura)/2;
}
/*********************************************************************
* Comment
*********************************************************************/
double Triangulo::getArea()
{
  return this->area;
}


void Triangulo::setPerimetro(){
  this->perimetro=(this->base)*3;
}

double Triangulo::GetPerimetro(){
  return this->perimetro;
}
