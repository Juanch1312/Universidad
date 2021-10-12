#include "Rectangulo.h"

/*********************************************************************
* Comment
*********************************************************************/
void Rectangulo::setBase(double base)
{
  this->base=base;
}
/*********************************************************************
* Comment
*********************************************************************/
double Rectangulo::getBase()
{
  return this->base;
}
/*********************************************************************
* Comment
*********************************************************************/
void Rectangulo::setAltura(double altura)
{
  this->altura=altura;
}
/*********************************************************************
* Comment
*********************************************************************/
double Rectangulo::getAltura()
{
 return this->altura;
}
/*********************************************************************
* Comment
*********************************************************************/
double Rectangulo::getArea()
{
  return this->area;
}
void Rectangulo::CalcularArea(){
  this->area=(this->altura*this->altura);
}
void Rectangulo::setPerimetro(){
  this->perimetro=(this->base*2)+(this->altura*2);
}
double Rectangulo::GetPerimetro(){
  return this->perimetro;
}
