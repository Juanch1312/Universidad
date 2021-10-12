#include "Peso.h"
#include "Dolar.h"
#include "Euro.h"
#include "Yen.h"
#include "Yuan.h"
#include "Menu.h"

#include <iostream>
#include <cctype>

using namespace std;

Menu myMenu;
Peso myPeso;
Dolar myDolar;
Euro myEuro;
Yen myYen;
Yuan myYuan;

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
        cout<<"Inserte la cantidad de Pesos a convertir"<<endl;
        cin>>n1;
        comprobar=validacionunica(n1);
        if(comprobar == 1){
          n3 = atof(n1);
          myPeso.setValue(n3);
          cout<<"La cantidad de dolar/es son: $"<<myPeso.getPesoDolar()<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 2:{
        cout<<"Inserte la cantidad de Dolares a convertir"<<endl;
        cin>>n1;
        comprobar=validacionunica(n1);
        if(comprobar == 1){
          n3 = atof(n1);
          myDolar.setValue(n3);
          cout<<"La cantidad de peso/s son: $"<<myDolar.getDolarPeso()<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }

      }break;
      case 3:{
        cout<<"Inserte la cantidad de Pesos a convertir"<<endl;
        cin>>n1;
        comprobar=validacionunica(n1);
        if(comprobar == 1){
          n3 = atof(n1);
          myPeso.setValue(n3);
          cout<<"La cantidad de Euro/s son: $"<<myPeso.getPesoEuro()<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 4:{
        cout<<"Inserte la cantidad de Euro/s a convertir"<<endl;
        cin>>n1;
        comprobar=validacionunica(n1);
        if(comprobar == 1){
          n3 = atof(n1);
          myEuro.setValue(n3);
          cout<<"La cantidad de peso/s son: $"<<myEuro.getEuroPeso()<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 5:{
        cout<<"Inserte la cantidad de Peso/s a convertir"<<endl;
        cin>>n1;
        comprobar=validacionunica(n1);
        if(comprobar == 1){
          n3 = atof(n1);
          myPeso.setValue(n3);
          cout<<"La cantidad de yen/es son: $"<<myPeso.getPesoYen()<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 6:{
        cout<<"Inserte la cantidad de Yen/es a convertir"<<endl;
        cin>>n1;
        comprobar=validacionunica(n1);
        if(comprobar == 1){
          n3 = atof(n1);
          myYen.setValue(n3);
          cout<<"La cantidad de peso/s son: $"<<myYen.getYenPeso()<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 7:{
        cout<<"Inserte la cantidad de Peso/s a convertir"<<endl;
        cin>>n1;
        comprobar=validacionunica(n1);
        if(comprobar == 1){
          n3 = atof(n1);
          myPeso.setValue(n3);
          cout<<"La cantidad de Yuan/es son: $"<<myPeso.getPesoYuan()<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 8:{
        cout<<"Inserte la cantidad de Yuan/es a convertir"<<endl;
        cin>>n1;
        comprobar=validacionunica(n1);
        if(comprobar == 1){
          n3 = atof(n1);
          myYuan.setValue(n3);
          cout<<"La cantidad de peso/s son: $"<<myYuan.getYuanPeso()<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 9:{
        cout<<"Saliendo..."<<endl;
      }break;
      default:{
        cout<<"Opcion insertada incorrecta"<<endl;
        system("pause");
      }break;
  }
}while(opc1!=9);
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
