#ifndef POLIGONO_H
# define POLIGONO_H

class Poligono{
private:
  double lado;
  double numerolados;
  double apotema;
  double area;
  double perimetro;

public:
  void SetLado(double);
  double getLado();
  void SetNumeroLados(double);
  double getNumeroLados();
  void SetApotema(double);
  double GetApotema();
  void setPerimetro();
  double GetPerimetro();
  void CalcularArea();
  double GetArea();
};

#endif
