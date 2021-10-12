#ifndef COLA_H
# define COLA_H

#include<iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;

class cola{
	private:
		int inicio,fin;

	public:
	        cola();
	        int lleno();
	        int vacio();
               void llenar(int);
               void consultar_inicio();
               int consultar_final();
               void mostrar_cola();
               void eliminar();
               int dato[20]={-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2};
							 void gotoxy(int,int);

};
cola::cola(){
	fin=-1;
	inicio=0;
}
 void cola::llenar(int n){
	 if(lleno()==0){
	 	fin ++;
 		dato[fin]=n;

	 }
 }

void cola::consultar_inicio(){
	if(vacio()==0){
		int aux=0;
		cout<<dato[aux]+1;
	}
}

int cola::consultar_final(){
	if(vacio()==0){
		return dato[fin]+1;
	}
	return 0;
}
int a=0,cont=0,y=1;
void cola::mostrar_cola(){
	if(cont==0){
		y=y+3;
		if(vacio()==0){
			gotoxy(81,1);printf("%c%c%c%c%c",201,205,205,205,187);
			for(int i=a;i>=0;i--){
				if(dato[i]!=-2){
					if(i==0){
						gotoxy(81,2);	printf("%c %i %c",186,dato[i]+1,186);
						gotoxy(81,3);printf("%c%c%c%c%c",200,205,205,205,188);
						cont++;

					}
					else{
						gotoxy(81,2);printf("%c   %c",186,186);
						gotoxy(81,3);printf("%c%c%c%c%c",200,205,205,205,188);
						cont++;
					}
				}
				else{
					gotoxy(81,2);printf("%c   %c",186,186);
					gotoxy(81,3);printf("%c%c%c%c%c",200,205,205,205,188);
					cont++;
				}
			}
		}
	}
	else{
		if(vacio()==0){
			gotoxy(81,y);printf("%c%c%c%c%c",201,205,205,205,187);
			for(int i=a;i>=0;i--){
				if(dato[i]!=-2){
					if(i==0){
						gotoxy(81,y+1);	printf("%c %i %c",186,consultar_final(),186);
						gotoxy(81,y+2);printf("%c%c%c%c%c",200,205,205,205,188);
						y=y+3;

					}
					else{
						gotoxy(81,y+1);printf("%c   %c",186,186);
						gotoxy(81,y+2);printf("%c%c%c%c%c",200,205,205,205,188);
						y=y+3;
					}
				}
				else{
					gotoxy(81,y+1);printf("%c   %c",186,186);
					gotoxy(81,y+2);printf("%c%c%c%c%c",200,205,205,205,188);
					y=y+3;
				}
			}
		}
	}
}
void cola::eliminar(){
	if(vacio()==0){
		for(int i=0;i<=fin;i++){
			dato[i]=dato[i+1];
		}
		dato[fin]=-2;
		fin--;
		y-4;
		cont--;
	}
}

int cola::lleno(){
	if(fin==9){
		return 1;
	}else{
		return 0;
	}
}
int cola::vacio(){
	if(fin==-1){
		return 1;
	} else{
		return 0;
	}
}


void cola:: gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

#endif
