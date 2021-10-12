#include <iostream>
#include <cstdlib>

using namespace std;

int *ptr;
int vec[]={1,2,3,4,5,6,7,8,9,10,11};
void NumerosPrimos(int*);
int main (){
  system("cls");
  ptr= &vec[0];
  cout<<"Los numeros primos de la lista son: "<<endl;
  NumerosPrimos(ptr);
  system("pause>>cls");
  return 0;
}

void NumerosPrimos(int *ptr){
  int aux1;
  for(int i=0;i<11;i++){
    aux1=*(ptr+i);
    if(aux1%2!=0 ||aux1==2){
      if(aux1/aux1==1){
        cout<<aux1<<endl;
      }
    }
  }
}
