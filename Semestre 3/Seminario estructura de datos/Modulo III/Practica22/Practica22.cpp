#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;
class Nodo{
  public:
    int value;
    Nodo* next;

};
void gotoxy(int x ,int y){
  HANDLE hcon;
  hcon=GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y = y;
  SetConsoleCursorPosition(hcon,dwPos);
}



void push(Nodo *&pila, int n){
  Nodo *temp = new Nodo();
  temp->value = n;
  temp->next = pila;
  pila = temp;

};

void pop(Nodo *&pila){
  Nodo *temp = pila;
  pila = temp->next;
  delete(temp);

};
int aux=0;
void display(Nodo *&pila, int cont){
  Nodo *temp;
  temp = pila;
    while(temp!=NULL){
      if(temp==pila){
        printf("\t%c%c%c",201,205,187);cout<<endl;
        printf("\t%c%i%c",186,temp->value,186,"\n");cout<<endl;
        temp=temp->next;
        printf("\t%c%c%c",200,205,188);
      }else{
        printf("\t%c%c%c",201,205,187);cout<<endl;
        printf("\t%c%i%c",186,temp->value,186,"\n");cout<<endl;
        temp = temp->next;
        printf("\t%c%c%c",200,205,188);

      }
      cout<<endl;
  }
  gotoxy(14,1);cout<<"<";
  gotoxy(15,1);cout<<"--   TOPE";

};



int menu(){
  int opc;
  gotoxy(1,20);cout <<"\n\n1.- Push"
           "\n2.- Pop"
           "\n0.- Salir"<<endl;
  cin>>opc;
  return opc;

};







int main(){

  Nodo *pila = NULL;
  int value, cont=0, opc=1;

  do {

    switch (menu()) {

      case 1:
      cont++;
      push(pila, cont);
      system("CLS");
      display(pila, cont);
      break;


      case 2:
      cont--;
      pop(pila);
      system("CLS");
      display(pila, cont);
      break;

      case 0:
      opc=0;

      break;

      default: std::cout << "\nOpcion no disponible" << '\n';

    }

  } while(opc!=0);





};
