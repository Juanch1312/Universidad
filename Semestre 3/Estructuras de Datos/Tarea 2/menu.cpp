#include "Menu.h"


/*********************************************************************
* Comment
*********************************************************************/
int Menu::getOption()
{
  return opc;
}
/*********************************************************************
* Comment
*********************************************************************/
void Menu::ShowMenu()
{
  cout<<"1) Add new product "<<endl;
  cout<<"2) Sell one product "<<endl;
  cout<<"3) Add existence"<<endl;
  cout<<"4) Show the products"<<endl;
  cout<<"5) Exit "<<endl;
  cin>>opc;

}
