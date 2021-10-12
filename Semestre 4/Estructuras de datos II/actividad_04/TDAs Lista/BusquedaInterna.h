#ifndef BUSQUEDAINTERNA_H_INCLUDED
 #define BUSQUEDAINTERNA_H_INCLUDED

 #include "Arreglos.h"

 template <class T>
 class Busqueda
 {
  public:
   virtual int Busca(Arreglo<T>, T)= 0;
   };


   template <class T>
   class SecuencialDesord: public Busqueda<T>
   {
   public:
   int Busca (Arreglo<T>, T);
  };


 template <class T>
 int SecuencialDesord<T>::Busca(Arreglo<T> Arre, T Dato)
 {
 int Indice= 0, Posic = -1;
 while (Indice < Arre.RegresaTam() && Dato != Arre.RegresaValor(Indice))
 Indice++;
 if (Indice < Arre.RegresaTam())
 Posic= Indice;
 return Posic;
 }

 template <class T>
 class SecuencialOrdenado: public Busqueda<T>
 {
 public:
 int Busca (Arreglo<T>, T);
 };

 template <class T>
 int SecuencialOrdenado<T>::Busca(Arreglo<T> Arre, T Dato)
 {
 int Indice= 0, Posic;
 while (Indice<Arre.RegresaTam() && Dato>Arre.RegresaValor(Indice)){
 Indice++;
 }

 if (Indice == Arre.RegresaTam() || Dato< Arre.RegresaValor(Indice))
 Posic= -(Indice + 1);
 else
 Posic= Indice;
 return Posic;
 }


 template <class T>
 class Binaria: public Busqueda<T>
 {
 public:
 int Busca (Arreglo<T>, T);
 };

 template <class T>
 int Binaria<T>::Busca(Arreglo<T> Arre, T Dato)
 {
 int Izq= 0, Der= Arre.RegresaTam(), Cen, Posic;
 Cen= (Izq + Der) / 2;
 while (Izq <= Der && Dato != Arre.RegresaValor(Cen))
 {
 if (Dato < Arre.RegresaValor(Cen))
 Der= Cen -1;
 else
 Izq= Cen + 1;
 Cen= (Izq + Der) / 2;
 }
 if (Izq <= Der)
 Posic= Cen;
 else
 Posic= -(Izq + 1);
 return Posic;
 }

 #endif // BUSQUEDAINTERNA_H_INCLUDED
