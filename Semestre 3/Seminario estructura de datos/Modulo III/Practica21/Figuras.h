#ifndef FIGURAS_H
# define FIGURAS_H
#include <iostream>
#include <cstdlib>

class Figuras{
private:
  double base;
  double altura;
  double numerolados;
  double perimetro;
  double apotema;
public:
  void SetBase(double);
  void SetAltura(double);
  double GetBase();
  double GetAltura();

  void SetApotema(double);
  double GetApotema();
  void CalcularPerimetro();
  void SetNumeroDeLados(double);
  void SetPerimetro();
  double GetPerimetro();

  virtual void Calcular()=0;
  virtual double getArea()=0;
};
/*********************************************************************
* Comment
*********************************************************************/
void Figuras::SetBase(double base)
{
  this->base=base;
}
/*********************************************************************
* Comment
*********************************************************************/
void Figuras::SetAltura(double altura)
{
  this->altura = altura;
}
/*********************************************************************
* Comment
*********************************************************************/
double Figuras::GetBase()
{
  return this->base;
}
/*********************************************************************
* Comment
*********************************************************************/
double Figuras::GetAltura()
{
  return this->altura;
}
void Figuras::SetNumeroDeLados(double n){
  this->numerolados=n;
}

void Figuras::CalcularPerimetro(){
  this->perimetro=GetBase()*this->numerolados;
}
double Figuras::GetPerimetro(){
  return this->perimetro;
}

void Figuras::SetApotema(double apo){
  this->apotema=apo;
}

double Figuras::GetApotema(){
  return this->apotema;
}


#endif
