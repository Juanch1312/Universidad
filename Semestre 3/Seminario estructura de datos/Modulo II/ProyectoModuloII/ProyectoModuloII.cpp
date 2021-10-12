#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include "pila.h"
#include "cola.h"

cola myColaR;
cola myColaD;
cola myColaS;
cola myColaC;
pila myPila;

int cont2=0,ant=50,aux4=1;

using namespace std;

void gotoxy(int x ,int y){
  HANDLE hcon;
  hcon=GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y = y;
  SetConsoleCursorPosition(hcon,dwPos);
}

void ocultarCursor(){
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cci;
  cci.dwSize=50;
  cci.bVisible = FALSE;
  SetConsoleCursorInfo(hcon,&cci);
}
void movimientoHastaTicket(){
  for(int x=0;x<15;x++){
    gotoxy(0+x,15);printf("    %c",254);
    gotoxy(0+x,16);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(0+x,17);cout<<"    |"<<endl;
    }else{
      gotoxy(0+x,17);cout<<"    /\\ "<<endl;
    }
    Sleep(100);
  }
}

void movimientoHastaDeposito(){
  for(int x=0;x<15;x++){
    gotoxy(15+x,15);printf("    %c",254);
    gotoxy(15+x,16);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(15+x,17);cout<<"    | "<<endl;
    }else{
      gotoxy(15+x,17);cout<<"    /\\ "<<endl;
    }
    Sleep(100);
  }
  for(int x=0;x<15;x++){
    gotoxy(30,15-x);printf("    %c",254);
    gotoxy(30,16-x);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(30,17-x);cout<<"    | "<<endl;
      gotoxy(30,18-x);cout<<"         "<<endl;
    }else{
      gotoxy(30,17-x);cout<<"    /\\ "<<endl;
      gotoxy(30,18-x);cout<<"         "<<endl;
    }
    Sleep(100);
  }
  if(cont2==0){
    for(int x=0;x<ant;x++){
      gotoxy(30+x,1);printf("    %c",254);
      gotoxy(30+x,2);cout<<"   /|\\"<<endl;
      if(x%2==0){
        gotoxy(30+x,3);cout<<"    | "<<endl;
      }else{
        gotoxy(30+x,3);cout<<"    /\\ "<<endl;
      }
      Sleep(100);
    }
    cont2++;
  }
  else{
    for(int x=0;x<ant-cont2-aux4-2;x++){
      gotoxy(30+x,1);printf("    %c",254);
      gotoxy(30+x,2);cout<<"   /|\\"<<endl;
      if(x%2==0){
        gotoxy(30+x,3);cout<<"    |"<<endl;
      }else{
        gotoxy(30+x,3);cout<<"    /\\ "<<endl;
      }
      Sleep(100);
    }
  ant=50;
  ant=ant-cont2-(aux4+2);
  aux4++;
  cont2++;
  }
}
int ant2=50,cont3=0,aux3=1;
void movimientoHastaRetiro(){
  for(int x=0;x<15;x++){
    gotoxy(15+x,15);printf("    %c",254);
    gotoxy(15+x,16);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(15+x,17);cout<<"    |"<<endl;
    }else{
      gotoxy(15+x,17);cout<<"    /\\ "<<endl;
    }
    Sleep(100);
  }
  for(int x=0;x<7;x++){
    gotoxy(30,15-x);printf("    %c",254);
    gotoxy(30,16-x);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(30,17-x);cout<<"    |"<<endl;
      gotoxy(30,18-x);cout<<"      "<<endl;
    }else{
      gotoxy(30,17-x);cout<<"    /\\ "<<endl;
      gotoxy(30,18-x);cout<<"         "<<endl;
    }
    Sleep(100);
  }
  if(cont3==0){
    for(int x=0;x<ant2;x++){
      gotoxy(30+x,9);printf("    %c",254);
      gotoxy(30+x,10);cout<<"   /|\\"<<endl;
      gotoxy(30,18-x);cout<<"        "<<endl;
      if(x%2==0){
        gotoxy(30+x,11);cout<<"    | "<<endl;
      }else{
        gotoxy(30+x,11);cout<<"    /\\ "<<endl;
        gotoxy(30,18-x);cout<<"        "<<endl;
      }
      Sleep(100);
    }
    cont3++;
  }
  else{
    for(int x=0;x<ant2-cont3-aux3-2;x++){
      gotoxy(30+x,9);printf("    %c",254);
      gotoxy(30+x,10);cout<<"   /|\\"<<endl;
      if(x%2==0){
        gotoxy(30+x,11);cout<<"    |"<<endl;
      }else{
        gotoxy(30+x,11);cout<<"    /\\ "<<endl;
      }
      Sleep(100);
    }
  ant2=50;
  ant2=ant2-cont3-(aux3+2);
  cont3++;
  aux3++;
  }
}
int ant3=50,cont4=0,aux2=1;
void movimientoHastaCambio(){
  for(int x=0;x<15;x++){
    gotoxy(15+x,15);printf("    %c",254);
    gotoxy(15+x,16);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(15+x,17);cout<<"    |"<<endl;
    }else{
      gotoxy(15+x,17);cout<<"    /\\ "<<endl;
    }
    Sleep(100);
  }
  for(int x=0;x<7;x++){
    gotoxy(30,14+x);cout<<"         "<<endl;
    gotoxy(30,15+x);printf("    %c ",254);
    gotoxy(30,16+x);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(30,17+x);cout<<"    |"<<endl;
    }else{
      gotoxy(30,17+x);cout<<"    /\\ "<<endl;
    }
    Sleep(100);
  }
  if(cont4==0){
    for(int x=0;x<ant3;x++){
      gotoxy(30+x,21);printf("    %c",254);
      gotoxy(30+x,22);cout<<"   /|\\"<<endl;
      if(x%2==0){
        gotoxy(30+x,23);cout<<"    | "<<endl;
      }else{
        gotoxy(30+x,23);cout<<"    /\\ "<<endl;
      }
      Sleep(100);
    }
    cont4++;
  }
  else{
    for(int x=0;x<ant3-cont4-aux2-2;x++){
      gotoxy(30+x,21);printf("    %c",254);
      gotoxy(30+x,22);cout<<"   /|\\"<<endl;
      if(x%2==0){
        gotoxy(30+x,23);cout<<"    |"<<endl;
      }else{
        gotoxy(30+x,23);cout<<"    /\\ "<<endl;
      }
      Sleep(100);
    }
  ant3=50;
  ant3=ant3-cont4-(aux2+2);
  cont4++;
  aux2++;
  }
}
int ant4=50,cont5=0,aux=1;
void movimientoHastaServicio(){
  int x=0;
  for(x=0;x<15;x++){
    gotoxy(15+x,15);printf("    %c",254);
    gotoxy(15+x,16);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(15+x,17);cout<<"    |"<<endl;
    }else{
      gotoxy(15+x,17);cout<<"    /\\ "<<endl;
    }
    Sleep(100);
  }
  for(x=0;x<15;x++){
    gotoxy(30,14+x);cout<<"         "<<endl;
    gotoxy(30,15+x);printf("    %c ",254);
    gotoxy(30,16+x);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(30,17+x);cout<<"    |"<<endl;
    }else{
      gotoxy(30,17+x);cout<<"    /\\ "<<endl;
    }
    Sleep(100);
  }
  if(cont5==0){
    for(x=0;x<ant4;x++){
      gotoxy(30+x,29);printf("    %c",254);
      gotoxy(30+x,30);cout<<"   /|\\"<<endl;
      if(x%2==0){
        gotoxy(30+x,31);cout<<"    | "<<endl;
      }else{
        gotoxy(30+x,31);cout<<"    /\\ "<<endl;
      }
      Sleep(100);
    }
    cont5++;
  }
  else{
    for(x=0;x<ant4-cont5-aux-2;x++){
      gotoxy(30+x,29);printf("    %c",254);
      gotoxy(30+x,30);cout<<"   /|\\"<<endl;
      if(x%2==0){
        gotoxy(30+x,31);cout<<"    |"<<endl;
      }else{
        gotoxy(30+x,31);cout<<"    /\\ "<<endl;
      }
      Sleep(100);
    }
  ant4=50;

  ant4=ant4-cont5-(aux+2);
  cont5++;
  aux++;
  }
}

void Banco(){
  for(int y=0;y<80;y++){
    gotoxy(88,0+y);printf("%c",186);
  }
  //Cajero 1
  gotoxy(88,1);printf("%c%c%c%c%c",201,205,205,205,187);
  gotoxy(88,2);	printf("%c %c %c",186,220,186);
  gotoxy(88,3);printf("%c%c%c%c%c",200,205,205,205,188);
  //Cajero 2
  gotoxy(88,9);printf("%c%c%c%c%c",201,205,205,205,187);
  gotoxy(88,10);	printf("%c %c %c",186,220,186);
  gotoxy(88,11);printf("%c%c%c%c%c",200,205,205,205,188);
  //Cajero 3
  gotoxy(88,19);printf("%c%c%c%c%c",201,205,205,205,187);
  gotoxy(88,20);	printf("%c %c %c",186,220,186);
  gotoxy(88,21);printf("%c%c%c%c%c",200,205,205,205,188);
  //Cajero 4
  gotoxy(88,28);printf("%c%c%c%c%c",201,205,205,205,187);
  gotoxy(88,29);	printf("%c %c %c",186,220,186);
  gotoxy(88,30);printf("%c%c%c%c%c",200,205,205,205,188);
  //Salida
  gotoxy(88,13);cout<<"EXIT"<<endl;
  gotoxy(88,14);printf("%c%c ",219,219);
  gotoxy(88,15);printf("%c%c ",219,219);
  gotoxy(88,16);printf("%c%c ",219,219);
  //Letreros
  gotoxy(93,2);cout<<"Caja 1";
  gotoxy(93,10);cout<<"Caja 2";
  gotoxy(93,20);cout<<"Caja 3";
  gotoxy(93,29);cout<<"Servicio a cliente";
  //PISO Y TECHO INICIO
  for(int x=0;x<30;x++){
    gotoxy(0+x,12);printf("%c",196);
    gotoxy(0+x,18);printf("%c",196);
  }
  gotoxy(13,11);cout<<"Ticket #";
  //PAREDES
  for(int x=0;x<14;x++){
    gotoxy(29,18+x);printf("|");
    gotoxy(29,11-x);printf("|");
  }
  //PAREDES LADO DER PARTE MEDIA
  for(int x=0;x<8;x++){
    gotoxy(40,12+x);printf("|");
  }
  //PAREDES LADO DER PARTE BAJA
  for(int x=0;x<4;x++){
    gotoxy(40,4+x);printf("|");
    gotoxy(40,24+x);printf("|");
  }
  //ESQUINAS
  gotoxy(29,32);printf("%c",192);
  gotoxy(29,18);printf("%c",191);
  gotoxy(29,12);printf("%c",217);
  gotoxy(40,28);printf("%c",192);
  gotoxy(40,7);printf("%c",192);
  gotoxy(40,19);printf("%c",192);
  gotoxy(40,4);printf("%c",218);
  gotoxy(40,24);printf("%c",218);
  gotoxy(40,12);printf("%c",218);
  //PISO INFERIOR
  for(int x=0;x<51;x++){
    gotoxy(30+x,32);printf("%c",196);
  }
  //PISOS SUPERIORES
  for(int x=0;x<38;x++){
    gotoxy(41+x,19);printf("%c",196);
    gotoxy(41+x,12);printf("%c",196);
    gotoxy(41+x,7);printf("%c",196);
    gotoxy(41+x,4);printf("%c",196);
    gotoxy(41+x,24);printf("%c",196);
    gotoxy(41+x,28);printf("%c",196);
  }
}

void RetiraExit(){
  for(int x=0;x<2;x++){
    gotoxy(79+x,12+x);printf("       ");
    gotoxy(79,13+x);printf("    %c",254);
    gotoxy(79,14+x);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(79,15+x);cout<<"    |"<<endl;
    }else{
      gotoxy(79,15+x);cout<<"    /\\ "<<endl;
      gotoxy(79,16+x);cout<<"         "<<endl;
    }
    Sleep(100);
  }
  for(int x=0;x<7;x++){
    gotoxy(79+x,14);printf("    %c",254);
    gotoxy(79+x,15);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(79+x,16);cout<<"    |"<<endl;
    }else{
      gotoxy(79+x,16);cout<<"    /\\ "<<endl;
      gotoxy(79+x,16);cout<<"         "<<endl;
    }
    Sleep(100);
  }
}

void DepositoExit(){
  for(int x=0;x<10;x++){
    gotoxy(79,4+x);printf("      ");
    gotoxy(79,5+x);printf("    %c",254);
    gotoxy(79,6+x);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(79,7+x);cout<<"    |"<<endl;
    }else{
      gotoxy(79,7+x);cout<<"    /\\ "<<endl;
      gotoxy(79,8+x);cout<<"     "<<endl;
    }
    Sleep(100);
  }
  for(int x=0;x<7;x++){
    gotoxy(79+x,14);printf("    %c",254);
    gotoxy(79+x,15);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(79+x,16);cout<<"    |"<<endl;
    }else{
      gotoxy(79+x,16);cout<<"    /\\ "<<endl;
      gotoxy(79+x,16);cout<<"         "<<endl;
    }
    Sleep(100);
  }
}

void CambioExit(){
  for(int x=0;x<4;x++){
    gotoxy(79,16-x);printf("      ");
    gotoxy(79,17-x);printf("    %c",254);
    gotoxy(79,18-x);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(79,19-x);cout<<"    | "<<endl;
      gotoxy(79,19-x);cout<<"      "<<endl;
    }else{
      gotoxy(79,19-x);cout<<"    /\\  "<<endl;
      gotoxy(79,21-x);cout<<"         "<<endl;
    }
    Sleep(100);
  }
  for(int x=0;x<7;x++){
    gotoxy(79+x,14);printf("    %c",254);
    gotoxy(79+x,15);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(79+x,16);cout<<"    | "<<endl;
    }else{
      gotoxy(79+x,16);cout<<"    /\\ "<<endl;
      gotoxy(79+x,17);cout<<"         "<<endl;
    }
    Sleep(100);
  }
}

void ServicioExit(){
  for(int x=0;x<12;x++){
    gotoxy(79,24-x);printf("      ");
    gotoxy(79,25-x);printf("    %c",254);
    gotoxy(79,26-x);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(79,27-x);cout<<"    | "<<endl;
      gotoxy(79,28-x);cout<<"      "<<endl;
    }else{
      gotoxy(79,27-x);cout<<"    /\\  "<<endl;
      gotoxy(79,28-x);cout<<"         "<<endl;
    }
    Sleep(100);
  }
  for(int x=0;x<7;x++){
    gotoxy(79+x,14);printf("    %c",254);
    gotoxy(79+x,15);cout<<"   /|\\"<<endl;
    if(x%2==0){
      gotoxy(79+x,16);cout<<"    | "<<endl;
    }else{
      gotoxy(79+x,16);cout<<"    /\\ "<<endl;
      gotoxy(79+x,17);cout<<"         "<<endl;
    }
    Sleep(100);
  }
}
int b=79,con;
void EliminarDeposito(){
  con=cont2*3;
  b-=con;
  for(int i=cont2;i>=1;i--){
    if(i==1 || i==2){
      gotoxy(b+4,1);cout<<"     ";
      gotoxy(b+4,2);cout<<"     ";
      gotoxy(b+4,3);cout<<"     ";
      myColaD.eliminar();
      DepositoExit();
      Sleep(250);
      Banco();
      b=b+3;
  }
  else{
    gotoxy(b,1);cout<<"     ";
    gotoxy(b,2);cout<<"     ";
    gotoxy(b,3);cout<<"     ";
    myColaD.eliminar();
    DepositoExit();
    Sleep(250);
    Banco();
    b=b+3;
  }
}
}
int c=79,con2;
void EliminarRetiro(){
  con2=cont3*3;
  c-=con2;
  for(int i=cont3;i>=1;i--){
    if(i==1 || i==2){
      gotoxy(c+4,9);cout<<"     ";
      gotoxy(c+4,10);cout<<"     ";
      gotoxy(c+4,11);cout<<"     ";
      myColaR.eliminar();
      RetiraExit();
      Sleep(250);
      Banco();
      c=c+3;
  }
  else{
    gotoxy(c,9);cout<<"     ";
    gotoxy(c,10);cout<<"     ";
    gotoxy(c,11);cout<<"     ";
    myColaR.eliminar();
    RetiraExit();
    Sleep(250);
    Banco();
    c=c+3;
  }
}
}
int d=79,con3;
void EliminarCaja3(){
  con3=cont4*3;
  d-=con3;
  for(int i=cont4;i>=1;i--){
    if(i==1 || i==2){
      gotoxy(d+4,21);cout<<"      ";
      gotoxy(d+4,22);cout<<"      ";
      gotoxy(d+4,23);cout<<"      ";
      myColaC.eliminar();
      CambioExit();
      Sleep(250);
      Banco();
      d=d+3;
  }
  else{
    gotoxy(d,21);cout<<"     ";
    gotoxy(d,22);cout<<"     ";
    gotoxy(d,23);cout<<"     ";
    myColaC.eliminar();
    CambioExit();
    Sleep(250);
    Banco();
    d=d+3;
  }
}
}
int e=79,con4;
void EliminarServicio(){
  con4=cont5*3;
  e-=con4;
  for(int i=cont5;i>=1;i--){
    if(i==1 || i==2){
      gotoxy(e+4,29);cout<<"     ";
      gotoxy(e+4,30);cout<<"     ";
      gotoxy(e+4,31);cout<<"     ";
      myColaS.eliminar();
      ServicioExit();
      Sleep(250);
      Banco();
      e=e+3;
  }
  else{
    gotoxy(e,29);cout<<"     ";
    gotoxy(e,30);cout<<"     ";
    gotoxy(e,31);cout<<"     ";
    myColaR.eliminar();
    ServicioExit();
    Sleep(250);
    Banco();
    e=e+3;
  }
}
}


void Logo(){
  gotoxy(3,19);cout<<"J";
  gotoxy(3,20);cout<<"H";
  gotoxy(3,21);cout<<"O";
  gotoxy(3,22);cout<<"N";
  gotoxy(3,23);cout<<"N";
  gotoxy(3,24);cout<<"Y";
  gotoxy(3,25);cout<<"B";
  gotoxy(3,26);cout<<"A";
  gotoxy(3,27);cout<<"N";
  gotoxy(3,28);cout<<"K";
}



int x=0;
int main(){
  int cont=0;
    ocultarCursor();
    srand(time(NULL));
    Banco();
    Logo();
    myPila.mostrar_pila();
    do{
      myPila.push(x);
      myPila.mostrar_pila();
      movimientoHastaTicket();
      Sleep(500);
      int z;
      z=(rand()%4);
    switch (z) {
      case 0:{
        gotoxy(1,1);cout<<"Se realizara un deposito";
        movimientoHastaDeposito();
        myColaD.llenar(x);
        gotoxy(90,0);myColaD.consultar_inicio();
        gotoxy(1,1);cout<<"                           ";
        x++;
      }break;
      case 1:{
      gotoxy(1,1);cout<<"Se realizara un Retiro";
      myColaR.llenar(x);
      gotoxy(90,8);myColaR.consultar_inicio();
      movimientoHastaRetiro();
      gotoxy(1,1);cout<<"                           ";
      x++;
      }break;
      case 2:{
      gotoxy(1,1);cout<<"Se realizara un Cambio de cheque";
        movimientoHastaCambio();
        myColaC.llenar(x);
        gotoxy(90,18);myColaC.consultar_inicio();
        gotoxy(1,1);cout<<"                                ";
        x++;
      }break;
      case 3:{
      gotoxy(1,1);cout<<"Se realizara un Servicio a cliente";
        movimientoHastaServicio();
        myColaS.llenar(x);
        gotoxy(90,27);myColaS.consultar_inicio();
        gotoxy(1,1);cout<<"                                      ";
        x++;
      }
    }
    myPila.pop();
    cont++;
  }while(cont!=20);
  if(cont3!=0){
      EliminarRetiro();
  }
  if(cont4!=0){
    EliminarCaja3();
  }
  if(cont2!=0){
    EliminarDeposito();
  }
  if(cont5!=0){
      EliminarServicio();
  }
  return 0;
}
