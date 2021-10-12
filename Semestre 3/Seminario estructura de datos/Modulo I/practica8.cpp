#include <iostream>
#include <cstdlib>

using namespace std;

int *ptr,numero;
int *factorial (int*);

int main (){
  system ("cls");
  cout<<"Ingrese un numero"<<endl;
  cin>>numero;
  ptr=&numero;
  cout<<"El factorial de: "<<numero<<" es: "<<*factorial(ptr);
  system("pause>>cls");
  return 0;
}

int *factorial (int*ptr){
  int *r=(int*)malloc(sizeof(int));
  *r=*ptr;
  for(int i=1;i<*ptr;i++){
    *r=(*r)*(i);
  }
  return r;
}
