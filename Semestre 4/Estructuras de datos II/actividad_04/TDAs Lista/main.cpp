#include <iostream>
 #include <fstream>
 #include "BusquedaInterna.h"
 #include "Persona.h"
 #include "Arreglos.h"

 using namespace std;

 int main()
{
  ifstream file("archivo.txt");
//  SecuencialDesord<Persona> Buscador;
  Binaria<Persona> Buscador;
  Persona per;
  Arreglo<Persona> Asistentes;
  int Resp,opc,aux=0;
  char Nom[64], nac[3]={""};
  if (file) {
    Asistentes = Asistentes.ReadFromDisk(Asistentes);
    }
  do {
    std::cout << "\nIngrese opcion\n1)Añadir\n2)Buscar\n3)Salir" << '\n';
    cin>>opc;
    switch (opc) {
      case 1:{
        cin>>per;
        Asistentes.agregar(per,Asistentes,aux);
        aux++;
      }break;

      case 2:{
        cout<<"\nIngresa el nombre de la persona a buscar: ";
        cin>>Nom;
        Persona Alguien(0,Nom,nac);
        Resp= Buscador.Busca(Asistentes, Alguien);
        if (Resp >= 0){
          Alguien=Asistentes.RegresaValor(Resp);
          cout<<Alguien;
        }
        else cout<<"\n\nNO se encontr a la persona\n\n";
      }break;

      case 3:{
        std::cout << "Saliendo..." << '\n';
        break;
      }break;

      default:{
        std::cout << "Opcion invalida" << '\n';
      }break;
    }
  } while(opc!=3);

  Asistentes.EscribeFile();
  file.close();
  return 0;

 }
