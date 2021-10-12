#include "Celcius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"
#include "Menu.h"

#include <iostream>

using namespace std;

Celcius myCel;
Fahrenheit myFah;
Kelvin myKel;
Menu myMenu;

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
        cout<<"Inserte la temperatura en Celcius: "<<endl;
        cin>>n1;
        comprobar=validacionunica(n1);
        if(comprobar==1){
          n3 = atof(n1);
          myCel.SetTemperatura(n3);
          cout<<"El valor en Fahrenheit es: "<<myCel.getFahrenheit()<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 2:{
        cout<<"Inserte la temperatura en Fahrenheit: "<<endl;
        cin>>n1;
        comprobar=validacionunica(n1);
        if(comprobar==1){
          n3 = atof(n1);
          myFah.SetTemperatura(n3);
          cout<<"El valor en Celcius es: "<<myFah.getCelcius()<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 3:{
        cout<<"Inserte la temperatura en Celcius: "<<endl;
        cin>>n1;
        comprobar=validacionunica(n1);
        if(comprobar==1){
          n3 = atof(n1);
          myCel.SetTemperatura(n3);
          cout<<"El valor en Kelvin es: "<<myCel.getKelvin()<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 4:{
        cout<<"Inserte la temperatura en Kelvin: "<<endl;
        cin>>n1;
        comprobar=validacionunica(n1);
        if(comprobar==1){
          n3 = atof(n1);
          myKel.SetTemperatura(n3);
          cout<<"El valor en Celcius es: "<<myKel.getCelcius()<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 5:{
        cout<<"Saliendo..."<<endl;
      }break;
      default:{
        cout<<"Opcion invalida..."<<endl;
        system("pause");
      }break;
  }
}while(opc1!=5);
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
