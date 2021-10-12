#ifndef FIGURAS_H
# define FIGURAS_H

class Figuras{
private:
  double base;
  double altura;
public:
  void SetBase(double);
  void SetAltura(double);
  double GetBase();
  double GetAltura();
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
#endif
