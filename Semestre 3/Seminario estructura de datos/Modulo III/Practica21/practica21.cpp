#include "Menu.h"
#include "Figuras.h"
#include "Triangulo.h"
#include "Cuadrado.h"
#include "Rectangulo.h"
#include "Poligono.h"
#include "Circunferencia.h"
#include <iostream>

using namespace std;

Figuras *ptr;
Triangulo myTri;
Cuadrado myCua;
Rectangulo myRec;
Menu myMenu;
Circunferencia MyCir;
Poligono myPoli;

int validacionunica(char n[100]);
int validacion(char n[100],char n2[100]);
char n1[100],n2[100];
int opc1;
double n3,n4;
int comprobar;
int main(){
  do{
    system("cls");
    myMenu.GetMenu();
    opc1=atoi(myMenu.GetOpc());
    switch(opc1){
      case 1:{
        ptr=&myTri;
        system("cls");
        cout<<"\tTriangulo\t"<<endl;
        cout<<endl<<endl;
        cout<<"Inserte la base: "<<endl;
        cin>>n1;
        cout<<"Inserte la altura"<<endl;
        cin>>n2;
        comprobar=validacion(n1,n2);
        if(comprobar==1){
            n3=atof(n1);
            n4=atof(n2);
            ptr->SetBase(n3);
            ptr->SetAltura(n4);
            ptr->Calcular();
            cout<<"El area del triangulo es: "<<ptr->getArea()<<endl;
            system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
    }break;
    case 2:{
      ptr=&myCua;
      system("cls");
      cout<<"\tCuadrado\t"<<endl;
      cout<<endl<<endl;
      cout<<"Inserte el largo: "<<endl;
      cin>>n1;
      comprobar=validacionunica(n1);
      if(comprobar==1){
          n3=atof(n1);
          ptr->SetBase(n3);
          ptr->Calcular();
          cout<<"El area del Cuadrado es: "<<ptr->getArea()<<endl;
          system("pause");
      }
      else{
        cout<<"Dato/s invalido/s"<<endl;
        system("pause");
      }
    }break;
    case 3:{
      ptr=&myRec;
        system("cls");
        cout<<"\tRectangulo\t"<<endl;
        cout<<endl<<endl;
        cout<<"Inserte la base: "<<endl;
        cin>>n1;
        cout<<"Inserte la altura"<<endl;
        cin>>n2;
        comprobar=validacion(n1,n2);
        if(comprobar==1){
            n3=atof(n1);
            n4=atof(n2);
            ptr->SetBase(n3);
            ptr->SetAltura(n4);
            ptr->Calcular();
            cout<<"El area del Rectangulo es: "<<ptr->getArea()<<endl;
            system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 4:{
        ptr=&myPoli;
        system("cls");
        cout<<"\tPoligonos\t"<<endl;
        cout<<endl<<endl;
        cout<<"Inserte el numero de lados: Datos comprendidos entre 5 y 10 "<<endl;
        cin>>n1;
        comprobar=validacionunica(n1);
        if(comprobar==1){
          n3=atof(n1);
          if(n3<=4||n3>=11){
            cout<<"Datos fuera del rango pedido"<<endl;
            system("pause");
          }
          else{
            ptr->SetNumeroDeLados(n3);
            cout<<"Inserte la apotema"<<endl;
            cin>>n1;
            cout<<"Inserte el largo de los lados"<<endl;
            cin>>n2;
            comprobar=validacion(n1,n2);
            if(comprobar==1){
              n3=atof(n1);
              n4=atof(n2);
              ptr->SetApotema(n3);
              ptr->SetBase(n4);
              ptr->CalcularPerimetro();
              ptr->Calcular();
              cout<<"El area del Poligono es: "<<ptr->getArea()<<endl;
              system("pause");
            }
            else{
              cout<<"Dato/s invalido/s"<<endl;
              system("pause");
            }
          }
        }
      }break;
      case 5:{
        ptr=&MyCir;
        system("cls");
        cout<<"Inserte el radio"<<endl;
        cin>>n1;
        comprobar=validacionunica(n1);
        if(comprobar==1){
          n3=atof(n1);
          ptr->SetBase(n3);
          ptr->Calcular();
          cout<<"El area de la Circunferencia es: "<<ptr->getArea()<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 6:{
        cout<<"Saliendo..."<<endl;
      }break;
      default:{
        cout<<"Opcion invalida"<<endl<<"Porfavor inserte otra opcion"<<endl;
        system("pause");
      }
  }
}while(opc1!=6);
  return 0;
}



int validacion(char n[100],char n2[100]){
  if(n[0]=='-'||n2[0]=='-'||n[0]=='.'||n2[0]=='.'){
    if(isdigit(n[1])&&isdigit(n2[1])){
    return 1;
    }
    else{
      return 0;
    }
  }
  else{
    if(isdigit(n[0])&&isdigit(n2[0])){
      return 1;
    }
    else{
      return 0;
    }

  }
}


int validacionunica(char n[100]){
  if(isdigit(n[0])=='-'||n[0]=='.'){
    if(isdigit(n[1])){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    if(isdigit(n[0])){
      return 1;
    }
    else{
      return 0;
    }
  }
}
