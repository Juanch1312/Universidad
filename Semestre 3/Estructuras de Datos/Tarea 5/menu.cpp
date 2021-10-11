#include "Menu.h"

/*********************************************************************
* Comment
*********************************************************************/
int Menu::GetOption()
{
  return opc;
}
/*********************************************************************
* Comment
*********************************************************************/
void Menu::GetMenu()
{
  cout<<"___________________________________"<<endl;
  cout<<"|\t1)Insert new song\t  |"<<endl;
  cout<<"___________________________________"<<endl;
  cout<<"|\t2)Delete song\t          |"<<endl;
  cout<<"___________________________________"<<endl;
  cout<<"|\t3)Find Data\t          |"<<endl;
  cout<<"___________________________________"<<endl;
  cout<<"|\t4)Exit\t\t\t  |"<<endl;
  cout<<"___________________________________"<<endl;
  cin>>opc;
}
void Menu::GetMenuFind(){
  cout<<"___________________________________"<<endl;
  cout<<"|\t1)Linear\t          |"<<endl;
  cout<<"___________________________________"<<endl;
  cout<<"|\t2)Binary\t          |"<<endl;
  cout<<"___________________________________"<<endl;
  cout<<"|\t3)Exit\t\t\t  |"<<endl;
  cout<<"___________________________________"<<endl;
  cin>>opc;
}

void Menu::GetMenuNameOrAuthor(){
  cout<<"___________________________________"<<endl;
  cout<<"|\t1)Find by Song name\t  |"<<endl;
  cout<<"___________________________________"<<endl;
  cout<<"|\t2)Find by Author\t  |"<<endl;
  cout<<"___________________________________"<<endl;
  cout<<"|\t3)Exit\t\t\t  |"<<endl;
  cout<<"___________________________________"<<endl;
  cin>>opc;
}