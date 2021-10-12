#ifndef POLIGONO_H
# define POLIGONO_H
#include "Figuras.h"

class Poligono:public Figuras{
private:
  double area;
public:
  void Calcular();
  double getArea();
};

/*********************************************************************
* Comment
*********************************************************************/
void Poligono::Calcular()
{
  this->area=((this->GetPerimetro())*(this->GetApotema())/2);
}
/*********************************************************************
* Comment
*********************************************************************/
double Poligono::getArea()
{
  return this->area;
}
#endif
