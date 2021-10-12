#include "Poligono.h"


/*********************************************************************
* Comment
*********************************************************************/
void Poligono::SetLado(double lado)
{
  this->lado=lado;
}
/*********************************************************************
* Comment
*********************************************************************/
double Poligono::getLado()
{
  return this->lado;
}
/*********************************************************************
* Comment
*********************************************************************/
void Poligono::SetNumeroLados(double nl)
{
  this->numerolados=nl;
}
/*********************************************************************
* Comment
*********************************************************************/
double Poligono::getNumeroLados()
{
  return this->numerolados;
}
/*********************************************************************
* Comment
*********************************************************************/
void Poligono::SetApotema(double a)
{
  this->apotema=a;
}
/*********************************************************************
* Comment
*********************************************************************/
double Poligono::GetApotema()
{
  return this->apotema;
}
void Poligono::setPerimetro(){
  this->perimetro=this->lado*this->numerolados;
}
double Poligono::GetPerimetro(){
  return this->perimetro;
}
void Poligono::CalcularArea(){
  this->area=((this->perimetro)*(this->apotema)/2);
}

double Poligono::GetArea(){
  return this->area;
}
