#ifndef MENU_H
# define MENU_H

#include <iostream>

using namespace std;

class Menu{
private:
  int opc ;

public:
  int *GetOpc();
  void GetMenu();
};

#endif