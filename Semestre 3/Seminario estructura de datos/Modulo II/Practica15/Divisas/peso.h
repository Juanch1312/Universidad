#ifndef PESO_H
# define PESO_H

class Peso{
private:
  double value;

public:
  void setValue(double);

  double getPesoDolar();
  double getPesoEuro();
  double getPesoYen();
  double getPesoYuan();
};
#endif
