#ifndef MENU_H
# define MENU_H

#include <iostream>

using namespace std;

class Menu{
private:
  char opc[1000];

public:
  char *GetOpc();
  void GetMenu();
};

#endif
