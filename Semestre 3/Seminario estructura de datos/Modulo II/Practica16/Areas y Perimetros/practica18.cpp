#include "Menu.h"
#include "Figuras.h"
#include "Triangulo.h"
#include "Cuadrado.h"
#include "Rectangulo.h"
#include "Poligono.h"
#include "Circunferencia.h"
#include <iostream>

using namespace std;

Triangulo myTri;
Cuadrado myCu;
Rectangulo myRec;
Menu myMenu;
Poligono myPoli;
Circunferencia MyCir;

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
            myTri.SetBase(n3);
            myTri.SetAltura(n4);
            myTri.CalcularPerimetro();
            myTri.CalcularArea();
            cout<<"El area del triangulo es: "<<myTri.GetArea()<<endl;
            cout<<"El perimetro del triangulo es: "<<myTri.GetPerimetro()<<endl;
            system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
    }break;
    case 2:{
      system("cls");
      cout<<"\tCuadrado\t"<<endl;
      cout<<endl<<endl;
      cout<<"Inserte el largo: "<<endl;
      cin>>n1;
      comprobar=validacionunica(n1);
      if(comprobar==1){
          n3=atof(n1);
          myCu.SetBase(n3);
          myCu.CalcularPerimetro();
          myCu.CalcularArea();
          cout<<"El area del Cuadrado es: "<<myCu.getArea()<<endl;
          cout<<"El perimetro del Cuadrado es: "<<myCu.getPerimetro()<<endl;
          system("pause");
      }
      else{
        cout<<"Dato/s invalido/s"<<endl;
        system("pause");
      }
    }break;
      case 3:{
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
            myRec.SetBase(n3);
            myRec.SetAltura(n4);
            myRec.CalcularPerimetro();
            myRec.CalcularArea();
            cout<<"El area del Rectangulo es: "<<myRec.getArea()<<endl;
            cout<<"El perimetro del Rectangulo es: "<<myRec.getPerimetro()<<endl;
            system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 4:{
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
            myPoli.SetNumeroLados(n3);
            cout<<"Inserte la apotema"<<endl;
            cin>>n1;
            cout<<"Inserte el largo de los lados"<<endl;
            cin>>n2;
            comprobar=validacion(n1,n2);
            if(comprobar==1){
              n3=atof(n1);
              n4=atof(n2);
              myPoli.SetApotema(n3);
              myPoli.SetBase(n4);
              myPoli.CalcularPerimetro();
              myPoli.CalcularArea();
              cout<<"El area del Poligono es: "<<myPoli.GetArea()<<endl;
              cout<<"El perimetro del Poligono: "<<myPoli.GetPerimetro()<<endl;
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
        system("cls");
        cout<<"Inserte el radio"<<endl;
        cin>>n1;
        comprobar=validacionunica(n1);
        if(comprobar==1){
          n3=atof(n1);
          MyCir.SetRadio(n3);
          MyCir.CalcularPerimetro();
          MyCir.CalcularArea();
          cout<<"El area de la Circunferencia es: "<<MyCir.GetArea()<<endl;
          cout<<"El perimetro de la Circunferencia es: "<<MyCir.GetPerimetro()<<endl;
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
