#include "Menu.h"
#include "Cuadrado.h"
#include "Circunferencia.h"
#include "Poligono.h"
#include "Rectangulo.h"
#include "Triangulo.h"
#include <cctype>

Cuadrado mycuadro;
Circunferencia MyCir;
Poligono myPoli;
Rectangulo myRec;
Triangulo mytri;
Menu myMenu;

int validacionunica(char n[100]);
int validacion(char n[100],char n2[100]);
using namespace std;
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
            mytri.SetBase(n3);
            mytri.SetAltura(n4);
            mytri.setPerimetro();
            mytri.CalcularArea();
            cout<<"El area del triangulo es: "<<mytri.getArea()<<endl;
            cout<<"El perimetro del triangulo es: "<<mytri.GetPerimetro()<<endl;
            system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
    }break;
    case 2:{
      system("cls");
      cout<<"<\tCuadrado\t"<<endl;
      cout<<endl<<endl;
      cout<<"Inserte el lado: "<<endl;
      cin>>n1;
      comprobar=validacionunica(n1);
      if(comprobar==1){
        n3=atof(n1);
        mycuadro.setLado(n3);
        mycuadro.setPerimetro();
        cout<<"El area del cuadrado es: "<<mycuadro.getLado()<<endl;
        cout<<"El perimetro del cuadrado es: "<<mycuadro.GetPerimetro()<<endl;
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
        myRec.setBase(n3);
        myRec.setAltura(n4);
        myRec.CalcularArea();
        myRec.setPerimetro();
        cout<<"El area del Rectangulo es: "<<myRec.getArea()<<endl;
        cout<<"El perimetro del rectangulo es: "<<myRec.GetPerimetro()<<endl;
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
            myPoli.SetLado(n4);
            myPoli.setPerimetro();
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
        MyCir.setRadio(n3);
        MyCir.setPerimetro();
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
      cout<<"Opcion invalida"<<endl;
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
