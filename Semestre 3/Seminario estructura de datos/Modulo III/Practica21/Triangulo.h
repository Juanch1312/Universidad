#ifndef TRIANGULO_H
# define TRIANGULO_H
#include "Figuras.h"

class Triangulo:public Figuras{
private:
  double area;
public:
  void Calcular();
  double getArea();
};
void Triangulo::Calcular(){
  this->area=(this->GetBase()*this->GetAltura())/2;
}
double Triangulo::getArea(){
  return this->area;
}


#endif
