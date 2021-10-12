#ifndef RECTANGULO_H
# define RECTANGULO_H

class Rectangulo{
private:
  double base;
  double altura;
  double area;
  double rectangulo;
  double perimetro;
public:
  void setBase(double);
  double getBase();
  void setAltura(double);
  double getAltura();
  double getArea();
  void CalcularArea();
  void setPerimetro();
  double GetPerimetro();
};

#endif
