#ifndef TRIANGULO_H
# define TRIANGULO_H

#include <iostream>
#include <cstdio>
using namespace std;

class Triangulo{
private:
  double base;
  double altura;
  double area;
  double perimetro;
public:
  void SetBase(double);
  double GetBase();
  void SetAltura(double);
  double GetAltura();
  void CalcularArea();
  double getArea();
  void setPerimetro();
  double GetPerimetro();
};

#endif
