#include <iostream>
#include <cstdlib>

using namespace std;

int *ptr;
int vec[]={10,5,4,3,17};
int *BuscarNumero(int*);
int main (){
  system("cls");
  ptr= &vec[0];
  cout<<"El numero mayor es: "<<*BuscarNumero(ptr);
  system("pause>>cls");
  return 0;
}

int *BuscarNumero(int *ptr){
  int *res=(int*)malloc(sizeof(int));
  int mayor=0;
  for (int i=0;i<5;i++){
    if (*(ptr+i)>mayor){
      mayor= *(ptr+i);
    }
    res=&mayor;
  }
  return res;

}
