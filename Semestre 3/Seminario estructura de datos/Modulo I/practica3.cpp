#include <iostream>
#include <cstdlib>
using namespace std;

int *ptr;
int numero;

int main (){
  system("cls");
  cout<<"Ingrese un numero"<<endl;
  cin>>numero;
  ptr=&numero;
  cout<<*ptr<<endl;
  cout<<ptr<<endl;
  system ("pause>>cls");
  return 0;
}
