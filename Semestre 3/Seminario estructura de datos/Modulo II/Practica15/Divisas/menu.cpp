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
  cout<<"1)Peso - Dolar"<<endl;
  cout<<"2)Dolar - Peso"<<endl;
  cout<<"3)Peso - Euro"<<endl;
  cout<<"4)Euro - Peso"<<endl;
  cout<<"5)Peso - Yen"<<endl;
  cout<<"6)Yen - Peso"<<endl;
  cout<<"7)Peso - Yuan"<<endl;
  cout<<"8)Yuan - Peso"<<endl;
  cout<<"9)Salir"<<endl;
  cin>>opc;
}
