#include <iostream>
#include <cstring>

using namespace std;

char nombre[50];
int main(){
  system ("cls");
  cout<<"Ingrese un nombre"<<endl;
  cin>>nombre;
  if(strcmp(nombre,"jose")==0){
    cout<<"Hola Jose"<<endl;
  }
  else{
    cout<<"Identifiquese";
  }
  system("pause>>cls");
  return 0;
}
