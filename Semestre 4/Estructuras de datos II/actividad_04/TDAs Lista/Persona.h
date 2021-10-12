#ifndef PERSONA_H_INCLUDED
 #define PERSONA_H_INCLUDED
 #include <iostream>
 #include <fstream>
 #include <Cstring>
 #include <stdlib.h>
 #include <cstdlib>
 #include <utility>
 #include "Arreglos.h"
 using namespace std;
 class Persona
 {
 private:
   int AnioNac;
   char NomPers[64], LugNac[64];
 public:
   Persona();
   Persona(int, char[], char[]);
   void Capturar();
   Arreglo<Persona> Leer(Arreglo<Persona>&);
   int operator != (Persona);
   int operator > (Persona);
   int operator < (Persona);
   friend std::istream &operator >> (std::istream &, Persona &);
   friend std::ostream &operator << (std::ostream &, Persona &);
 };


 Persona::Persona()
 {}

   Persona::Persona(int ANac, char NomP[], char LugN[])
   {
     AnioNac= ANac;
     strcpy(NomPers, NomP);
     strcpy(LugNac, LugN);
   }

   void Persona::Capturar()
   {
     int a,b,c;
     ofstream o("archivo.txt", ios::app);
     if(!o.good()){
       cout<<"error al abrir archivo"<<endl;
     }
     else{
       a=strlen(NomPers);
       b=strlen(LugNac);
       c=strlen((char *)&AnioNac);
       o.write((char *)&a, sizeof(int));
       o.write((char *)&NomPers, a);
       o.write((char *)&b, sizeof(int));
       o.write((char *)&LugNac, b);
       o.write((char *)&c, sizeof(int));
       o.write((char *)&AnioNac, c);

     }
     o.close();
   }

   Arreglo<Persona> Persona::Leer(Arreglo<Persona>& arr)
   {
     int a, b, c,i,j=0;
     ifstream o("archivo.txt");
     if(!o.good()){
       cout<<"error al abrir archivo"<<endl;
     }
     while(!o.eof()){
       fflush(stdin);
       a=strlen(NomPers);
       b=strlen(LugNac);
       c=strlen((char *)&AnioNac);
       o.read((char *)&a, sizeof(int));
       o.read((char *)&NomPers, a);
       NomPers[a] = '\0';
       o.read((char *)&b, sizeof(int));
       o.read((char *)&LugNac, b);
       LugNac[b] = '\0';
       o.read((char *)&c, sizeof(int));
       o.read((char *)&AnioNac, c);
       i = AnioNac;
       Persona per(i,NomPers,LugNac);
       arr.agregar(per,arr,j);
       j++;
       if(o.eof()){
         o.close();
         return arr;
       }
   }
   o.close();
 }



   int Persona::operator != (Persona Pers)
   {
     int Resp=0;
     if (strcmp(NomPers, Pers.NomPers) != 0)
     Resp= 1;
     return Resp;
   }


   int Persona::operator > (Persona Pers)
   {
     int Resp=0;
     if (strcmp(NomPers, Pers.NomPers) > 0)
     Resp= 1;
     return Resp;
   }

   int Persona::operator < (Persona Pers)
   {
     int Resp=0;
     if (strcmp(NomPers, Pers.NomPers) < 0)
      Resp= 1;
     return Resp;
   }

   std::istream &operator >> (std::istream &Lee, Persona &ObjPers)
   {
     std::cout <<"\n\nIngrese nombre de la Persona: ";
     Lee>> ObjPers.NomPers;
     std::cout <<"\n\nIngrese a o de nacimiento: ";
     Lee>> ObjPers.AnioNac;
     std::cout <<"\n\nIngrese lugar de nacimiento: ";
     Lee>> ObjPers.LugNac;
     return Lee;
   }
   std::ostream &operator << (std::ostream &Escribe, Persona &ObjPers)
   {
     Escribe<<"\n\nDatos de la Persona\n";
     Escribe<<"\nNombre: "<<ObjPers.NomPers;
     Escribe<<"\nLugar de nacimiento: "<<ObjPers.LugNac;
     Escribe<<"\n A o de nacimiento: "<<ObjPers.AnioNac;
     return Escribe;
   }


 #endif // PERSONA_H_INCLUDED
