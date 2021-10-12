#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

double *Potencia (double*,double*);
double *ptr,*ptr2,numero,potencia;

int main (){
  system("cls");
  cout<<"Inserte el numero a potenciar"<<endl;
  cin>>numero;
  cout<<"Inserte la potencia"<<endl;
  cin>>potencia;
  ptr=&numero;
  ptr2=&potencia;
  cout<<"La potencia del numero: "<<numero<<" es "<<*Potencia(ptr,ptr2)<<endl;
  system ("pause>>cls");
  return 0;
}

double *Potencia (double*ptr,double*ptr2){
  double *r=(double*)malloc(sizeof(double));
  *r=*ptr;
  *r=*ptr2;
  *r=pow(*ptr,*ptr2);
  return r;
}
