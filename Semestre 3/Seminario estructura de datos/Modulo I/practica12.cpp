#include <iostream>
#include <cstdlib>

using namespace std;

int *ptr;
int vec[]={1,2,3,4,5,6,7,8,9,10};
void NumerosPrimos(int*);
int main (){
  system("cls");
  ptr= &vec[0];
  cout<<"Los multiplos de 2 son: "<<endl;
  NumerosPrimos(ptr);
  system("pause>>cls");
  return 0;
}

void NumerosPrimos(int *ptr){
  int guarda;
  for(int i=0;i<9;i++){
    if(*(ptr+i)%2==0){
      guarda=*(ptr+i);
      cout<<guarda<<endl;
    }
  }
}
