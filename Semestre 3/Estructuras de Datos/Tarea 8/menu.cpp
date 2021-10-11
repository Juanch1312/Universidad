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
  cout<<"|\t4)Sort Data\t\t  |"<<endl;
  cout<<"___________________________________"<<endl;
  cout<<"|\t5)Exit\t\t\t  |"<<endl;
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
  cout<<"|\t1)By Song name\t  |"<<endl;
  cout<<"___________________________________"<<endl;
  cout<<"|\t2)By Author\t  |"<<endl;
  cout<<"___________________________________"<<endl;
  cout<<"|\t3)Exit\t\t\t  |"<<endl;
  cout<<"___________________________________"<<endl;
  cin>>opc;
}

void Menu::GetSortOption(){
  cout<<"___________________________________"<<endl;
  cout<<"|\t1)Sort Data Bubble\t  |"<<endl;
  cout<<"___________________________________"<<endl;
  cout<<"|\t2)Sort Data Insert\t  |"<<endl;
  cout<<"___________________________________"<<endl;
  cout<<"|\t3)Sort Data Select\t  |"<<endl;
  cout<<"___________________________________"<<endl;
  cout<<"|\t4)Sort Data Shell\t  |"<<endl;
  cout<<"___________________________________"<<endl;
  cout<<"|\t5)Exit\t\t\t  |"<<endl;
  cout<<"___________________________________"<<endl;
  cin>>opc;
}
