#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Contactos {
  int id;
  char nombre [30];
  char direccion [30];
} ct[10];


void Alta (void);
int Buscar (int);
void Editar (int);
void Remover (int);
void Listar (void);
void Mostrar (int);
void BuscarN (char*);

int index = 0;

int main (){
  int opc=0,id=0,opc2=0;
  char Nombre[50];
  do{
    system("cls");
    cout <<"Menu"<<endl;
    cout <<"1)Alta"<<endl;
    cout <<"2)Buscar"<<endl;
    cout <<"3)Editar"<<endl;
    cout <<"4)Remover"<<endl;
    cout <<"5)Listar"<<endl;
    cout <<"6)Salir"<<endl;
    cout <<"Seleccione una opcion"<<endl;
    cin>>opc;
    switch (opc) {
      case 1: Alta();break;
      case 2:{
        system("cls");
        cout<<"Inserte la opcion que descee: "<<endl;
        cout<<"1)Busqueda por nombre"<<endl;
        cout<<"2)Busqueda por ID"<<endl;
        cin>>opc2;
        switch (opc2){
          case 1:{
            cout<<"Inserte el nombre"<<endl;
            cin>>Nombre;
            BuscarN(Nombre);
          }break;
          case 2:{
            cout<<"Inserte el ID"<<endl;
            cin>>id;
            Mostrar(Buscar(id));
          }
        }
        }break;
      case 3:{
        system("cls");
        cout <<"Ingrese el id a modificar"<<endl;
        cin>>id;
        Editar(Buscar(id));
        cout<<"Cambios realizados con exito"<<endl;
      }break;
      case 4:{
        system("cls");
        cout << "Ingrese el ID del registro a eliminar: ";
        cin >> id;
        Remover(Buscar(id));
        break;
      }
      case 5:{
        Listar();
        system("pause");
      }
      case 6:{
        system("cls");
        cout<<"Saliendo del programa"<<endl;
      }
    }
  }while (opc != 6);
  system ("PAUSE>>cls");
  return 0;
}

void Alta (){
  cout <<"Ingrese id"<<endl;
  cin>>ct[index].id;
  cout <<"Ingrese el nombre"<<endl;
  cin>>ct[index].nombre;
  cout <<"Ingrese direccion"<<endl;
  cin>>ct[index].direccion;
  index++;
}

int Buscar (int id){
  int x=0,ban=0,pos=0;
  while (x<10 && ban==0) {
    if (id == ct[x].id){
      ban=1;
      pos=x;
    }
    x++;
  }
  return pos;
}

void BuscarN(char* name){
  int i=0,ban=0,pos=0;
  for (i=index;i>=0;i--){
    if (strcmp(name,ct[i].nombre)==0){
      ban=1;
      cout <<"id: "<<ct[i].id<<endl;
      cout <<"Nombre: "<<ct[i].nombre<<endl;
      cout <<"Direccion: "<<ct[i].direccion<<endl;
    }
    else{
      if(i==0){
        cout<<"El Nombre no se encuentra en la lista"<<endl;
        cout<<"Intente de nuevo"<<endl;
      }
    }
    }
    system("PAUSE");
}

void Mostrar (int pos){
  cout <<"id: "<<ct[pos].id<<endl;
  cout <<"Nombre: "<<ct[pos].nombre<<endl;
  cout <<"Direccion: "<<ct[pos].direccion<<endl;
  system("PAUSE");
}

void Editar (int pos){
  cout<<"Ingrese el nuevo nombre: "<<endl;
  cin>>ct[pos].nombre;
  cout<<"Ingrese la nueva direccion: "<<endl;
  cin>>ct[pos].direccion;
}

void Remover(int pos){
  if(index>0){
      for(index=index;pos<index;pos++){
          ct[pos]=ct[pos+1];
        }
    index--;
  }
  else{
    cout << "Aun no hay datos en ningun registro" <<endl;
  }
}

void Listar (){
  int i;
  for (i=0;i<index;i++){
    cout <<"id: "<<ct[i].id<<endl;
    cout <<"Nombre: "<<ct[i].nombre<<endl;
    cout <<"Direccion: "<<ct[i].direccion<<endl;
  }
}
