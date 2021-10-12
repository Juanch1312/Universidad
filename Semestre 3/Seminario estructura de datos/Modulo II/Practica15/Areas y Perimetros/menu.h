#ifndef MENU_H
# define MENU_H

#include "Circunferencia.h"
#include "Cuadrado.h"
#include "Poligono.h"
#include "Rectangulo.h"
#include "triangulo.h"
#include <string.h>
class Menu{
private:
  char opc[1000];

public:
  char *GetOpc();
  void GetMenu();
};

#endif
