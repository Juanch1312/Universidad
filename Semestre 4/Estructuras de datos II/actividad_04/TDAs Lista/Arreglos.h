#ifndef ARREGLOS_H_INCLUDED
 #define ARREGLOS_H_INCLUDED
 #include<iostream>
#include <fstream>
#include <utility>
using namespace std;
 #define MAX 100
 template <class T>
 class Arreglo
 {
 private:
 T Datos[MAX];
 int Tam;
 public:
 Arreglo();
 void agregar(T&,Arreglo<T>&,int i);
 void Escribe();
 void EscribeFile();
 Arreglo<T> ReadFromDisk(Arreglo<T>&);
 int RegresaTam();
 T RegresaValor(int);
 };
 template <class T>
 Arreglo<T>::Arreglo()
 {
 Tam= 0;
 }
 template <class T>
 void Arreglo<T>::agregar(T& per, Arreglo<T>& arr,int i){
   arr.Datos[i] = per;
   arr.Tam = i;
 }


 template <class T>
 void Arreglo<T>::Escribe()
 {
 int Indice;
 if (Tam > 0)
 {
 std::cout <<"\n Impresin de datos\n";
 for (Indice= 0; Indice < Tam; Indice++)
 std::cout << "\t" << Datos[Indice];
 }
 else
 std::cout << "\nNo hay elementos registrados.";
 }

 template <class T>
 void Arreglo<T>::EscribeFile()
 {
 int Indice;
 for (Indice= 0; Indice <= Tam; Indice++)
 {
   Datos[Indice].Capturar();
 }
}

template <class T>
Arreglo<T> Arreglo<T>::ReadFromDisk(Arreglo<T>& arr)
{
  Arreglo ara;
  T dato,aux;
  arr = dato.Leer(ara);
  std::cout << "Datos traidos del disco" << '\n';
  return arr;
}

 template <class T>
 int Arreglo<T>::RegresaTam()
 {
 return Tam;
 }

 template <class T>
 T Arreglo<T>::RegresaValor(int Indice)
 {
 return Datos[Indice];
 }

 #endif // ARREGLOS_H_INCLUDE
