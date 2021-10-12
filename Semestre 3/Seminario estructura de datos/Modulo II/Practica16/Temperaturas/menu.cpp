#include "Menu.h"

/*********************************************************************
* Comment
*********************************************************************/
char * Menu::GetOpc()
{
  return opc;
}
/*********************************************************************
* Comment
*********************************************************************/
void Menu::GetMenu()
{
  cout<<"1)Celcius - Fahrenheit"<<endl;
  cout<<"2)Fahrenheit - Celcius"<<endl;
  cout<<"3)Celcius - Kelvin"<<endl;
  cout<<"4)Kelvin - Celcius"<<endl;
  cout<<"5)Salir"<<endl;
  cin>>opc;
}
