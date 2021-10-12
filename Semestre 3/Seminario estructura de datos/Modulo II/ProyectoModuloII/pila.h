#ifndef PILA_H
# define PILA_H

#include<iostream>
#include <cctype>
#include<stdlib.h>
#include<windows.h>
using namespace std;

class pila{
	private: int datos[20];
	int tope,last;
	public:

		pila();
		void push(int);
		void pop();
		int  vacia();
		int llena();
		void mostrar_tope();
		void mostrar_pila();
		void gotoxy(int,int);


};

pila::pila(){
	 tope=-1;
}
void pila::push(int n){
	if(llena()==0){
		tope ++;
	     datos[tope]=n;
	}
}
void pila::pop(){
	if(vacia()==0){
		datos[tope ]= 0;
		tope --;
	}

}
void pila::mostrar_tope(){
	if(vacia()==0){
		system("cls");
		cout<<"El tope es:  "<<datos[tope ]<<endl;
		system("pause");
	}
}

void pila::mostrar_pila(){
		if(vacia()==0){
			gotoxy(14,12);	printf("%c%c%c%c%c\n",201,205,205,205,187);
			for(int i=tope;i>=0;i--){
				gotoxy(14,13);printf("%c   %c",186,186);
				gotoxy(15,13);printf(" %i %c",datos[i]+1,186);
				gotoxy(14,14); printf("%c%c%c%c%c\n",200,205,205,205,188);
			}
		}
		else{
			gotoxy(14,12);	printf("%c%c%c%c%c\n",201,205,205,205,187);
			gotoxy(14,13);	printf("%c   %c",186,186);
			gotoxy(14,14);	 printf("%c%c%c%c%c\n",200,205,205,205,188);
		}
	}

int  pila::vacia(){
	if(tope==-1){
		return 1;
	} else{
		return 0;
	}
}
int  pila::llena(){
	if(tope==19){
		system("cls");
		cout<<"LA PILA ESTA LLENA "<<endl;
		system("pause");
	     return 1;

	}
	else{
			return 0;
	}
}

void pila:: gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
#endif
