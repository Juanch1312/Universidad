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

bool cola_vacia(Nodo *frente){

	return (frente == NULL)? true : false;

};

void push(Nodo *&frente,Nodo *&fin,int n){

	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->value = n;
	nuevo_nodo->next = NULL;
	if(cola_vacia(frente)){

		frente = nuevo_nodo;

	}
	else{

		fin->next = nuevo_nodo;

	}
	fin = nuevo_nodo;

};



void pop(Nodo *&frente,Nodo *&fin){

	Nodo *aux = frente;
	if(frente == fin){

		frente = NULL;
		fin = NULL;

	}
	else{
		frente = frente->next;

	}

	delete aux;

};

void display(Nodo *&frente, int cont){
  Nodo *temp;
  temp = frente;
  while(temp!=NULL){
      printf("\t%c%c%c",201,205,187);cout<<endl;
      printf("\t%c%i%c",186,temp->value,186,"\n");cout<<endl;
      temp=temp->next;
      printf("\t%c%c%c",200,205,188);cout<<endl;
      if(temp==NULL){
        cout<<"\t ^ Frente"<<endl;
        cout<<"\t |";
      }
    }
    cout<<endl;
gotoxy(14,1);cout<<"<";
gotoxy(15,1);cout<<"--   Final";



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

  Nodo *frente = NULL;
  Nodo *fin = NULL;
  int value, cont=0, opc=1, cont2=0;

  do {

    switch (menu()) {

      case 1:
      cont2++;
      cont++;
      push(frente, fin, cont);
      system("CLS");
      display(frente, cont2);
      break;

      case 2:
      cont2--;
      pop(frente, fin);
      system("CLS");
      display(frente, cont2);
      break;

      case 0:
      opc=0;
      break;
      default: std::cout << "\nOpcion no disponible" << '\n';

    }

  } while(opc!=0);


};
