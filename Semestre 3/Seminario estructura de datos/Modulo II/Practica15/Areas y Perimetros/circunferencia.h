#ifndef CIRCUNFERENCIA_H
# define CIRCUNFERENCIA_H
#include <iostream>

class Circunferencia{
private:
  float pi=3.141592;
  double radio;
  double perimetro;
  double area;

public:
  void setRadio(double);
  double getRadio();
  void setPerimetro();
  double GetPerimetro();
  void CalcularArea();
  double GetArea();
};

#endif
