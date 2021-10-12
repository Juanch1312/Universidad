#include "Menu.h"


/*********************************************************************
* Comment
*********************************************************************/
char *Menu::GetOpc()
{
  return opc;
}
/*********************************************************************
* Comment
*********************************************************************/
void Menu::GetMenu()
{
  cout<<"1)TRIANGULO"<<endl;
  cout<<"2)Cuadrado"<<endl;
  cout<<"3)Rectangulo"<<endl;
  cout<<"4)Poligono"<<endl;
  cout<<"5)Circunferencia"<<endl;
  cout<<"6)Salir"<<endl;
  cin>>opc;
}
