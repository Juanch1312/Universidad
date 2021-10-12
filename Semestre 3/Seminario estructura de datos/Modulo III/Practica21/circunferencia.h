#ifndef CIRCUNFERENCIA_H
# define CIRCUNFERENCIA_H
#include "Figuras.h"
#include <math.h>

class Circunferencia:public Figuras{
private:
  double area;
public:
  void SetRadio(double);
  void Calcular();
  double getArea();
};
double Circunferencia::getArea()
{
    return this->area;
}
/*********************************************************************
* Comment
*********************************************************************/
void Circunferencia::Calcular()
{
  this->area=pow(this->GetBase(),2)*3.141596;
}
#endif
