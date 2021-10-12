#ifndef POLIGONO_H
# define POLIGONO_H
#include "Figuras.h"

class Poligono:public Figuras{
private:
  double numerolados;
  double apotema;
  double area;
  double perimetro;

public:
  void SetNumeroLados(double);
  void SetApotema(double);
  void CalcularArea();
  void CalcularPerimetro();
  double GetArea();
  double GetPerimetro();
  double GetApotema();
};
/*********************************************************************
* Comment
*********************************************************************/
void Poligono::SetNumeroLados(double nl)
{
  this->numerolados = nl;
}
/*********************************************************************
* Comment
*********************************************************************/
void Poligono::SetApotema(double apo)
{
  this->apotema=apo;
}
/*********************************************************************
* Comment
*********************************************************************/
void Poligono::CalcularArea()
{
  this->area=((this->perimetro)*(this->apotema)/2);
}
/*********************************************************************
* Comment
*********************************************************************/
void Poligono::CalcularPerimetro()
{
  this->perimetro=GetBase()*this->numerolados;
}
/*********************************************************************
* Comment
*********************************************************************/
double Poligono::GetArea()
{
  return this->area;
}
/*********************************************************************
* Comment
*********************************************************************/
double Poligono::GetPerimetro()
{
  return this->perimetro;
}
/*********************************************************************
* Comment
*********************************************************************/
double Poligono::GetApotema()
{
  return this->apotema;
}
#endif
