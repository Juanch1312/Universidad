#ifndef MENU_H_INCLUIDED
#define MENU_H_INCLUIDED

#include <iostream>
#include "Collectproducts.h"
using namespace std;

class Menu{
private:
  int opc;
public:
  int getOption();
  void ShowMenu();
};

#endif
