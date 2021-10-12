#ifndef ARBOLBINBUS_H_INCLUDED
#define ARBOLBINBUS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string.h>
#include "Producto.h"
template <class T>
class ArbolBinBus;

template <class T>
class NodoArbol
{
    private:
        T Info;
        NodoArbol<T> *HijoIzq;
        NodoArbol<T> *HijoDer;
    public:
        NodoArbol();
        T RegresaInfo();
        void ActualizaInfo(T);
        friend class ArbolBinBus<T>;
};

template <class T>
NodoArbol<T>::NodoArbol()
{
    HijoIzq= NULL;
    HijoDer= NULL;
}

template <class T>
T NodoArbol<T>::RegresaInfo()
{
    return Info ;
}

template <class T>
void NodoArbol<T>::ActualizaInfo(T Dato)
{
    Info= Dato ;
}

template <class T>
class ArbolBinBus
{
    private:
        NodoArbol<T> *Raiz;
        char* SavePreorden ( NodoArbol<T> *, char *);
    public:
        ArbolBinBus ();
        NodoArbol<T> *RegresaRaiz();
        void Preorden (NodoArbol<T> *);
        int WriteFile(std::ostream &);
        void WritePreordenFile(std::ostream &, NodoArbol<T> * );
        void Inorden (NodoArbol<T> *);
        void Postorden (NodoArbol<T> *);
        NodoArbol<T> * Busqueda (NodoArbol<T> *, T);
        void InsertaNodoSinRep (NodoArbol<T> *, T);
        void EliminaNodo (NodoArbol<T> *, T);
};

template <class T>
ArbolBinBus<T>::ArbolBinBus()
{
    Raiz= NULL;
}

template <class T>
NodoArbol<T> *ArbolBinBus<T>::RegresaRaiz()
{
    return Raiz;
}

template <class T>
void ArbolBinBus<T>::Preorden (NodoArbol<T> *Apunt)
{
    if (Apunt)
    {
        std::cout<< Apunt->Info << " ";
        Preorden(Apunt->HijoIzq);
        Preorden(Apunt->HijoDer);
    }
}

template <class T>
void ArbolBinBus<T>::WritePreordenFile(std::ostream &stream, NodoArbol<T> *Apunt )
{
    if (Apunt)
    {
        Apunt->Info.WriteProductFile(stream);
        WritePreordenFile(stream, Apunt->HijoIzq);
        WritePreordenFile(stream, Apunt->HijoDer);
    }
}

template <class T>
char* ArbolBinBus<T>::SavePreorden(NodoArbol<T> *Apunt, char * buffer)
{
    if (Apunt)
    {
        std::stringstream s;
        char clenght[100]="", ProducInf[150]="";
        s<<strlen(Apunt->Info.getArgumString(ProducInf)); s>>clenght;
        strcat(buffer, clenght);
        strcat(buffer, "#");
        strcat(buffer,Apunt->Info.getArgumString(ProducInf));
        SavePreorden(Apunt->HijoIzq,buffer);
        SavePreorden(Apunt->HijoDer,buffer);
    }
    return buffer;
}

template <class T>
int ArbolBinBus<T>::WriteFile(std::ostream &stream)
{
    char buffer[2000]="";
    strcpy(buffer,SavePreorden(Raiz, buffer));
    stream.write(buffer, strlen(buffer));
    return 0;
}

template <class T>
void ArbolBinBus<T>::Inorden (NodoArbol<T> *Apunt)
{
    if (Apunt)
    {
        Inorden(Apunt->HijoIzq);
        std::cout<< Apunt->Info << " ";
        Inorden(Apunt->HijoDer);
    }
}

template <class T>
void ArbolBinBus<T>::Postorden (NodoArbol<T> *Apunt)
{
    if (Apunt)
    {
        Postorden(Apunt->HijoIzq);
        Postorden(Apunt->HijoDer);
        std::cout<< Apunt->Info << " ";
    }
}

template <class T>
NodoArbol<T> * ArbolBinBus<T>::Busqueda (NodoArbol<T> *Apunt, T Dato)
{
    if (Apunt)
        if (Dato < Apunt->Info)
            return Busqueda(Apunt->HijoIzq, Dato);
        else
            if (Dato > Apunt->Info)
                return Busqueda(Apunt->HijoDer, Dato);
            else
                return Apunt;
    else
    return NULL;
}


template <class T>
void ArbolBinBus<T>::InsertaNodoSinRep(NodoArbol<T> *Apunt, T Dato)
{
    NodoArbol<T> *ApAux;
    if (Apunt)
    {
        if (Dato < Apunt->Info)
        {
            InsertaNodoSinRep(Apunt->HijoIzq, Dato);
            Apunt->HijoIzq= Raiz;
        }
        else
            if (Dato > Apunt->Info)
            {
                InsertaNodoSinRep(Apunt->HijoDer, Dato);
                Apunt->HijoDer= Raiz;
            }
        Raiz= Apunt;
    }
    else
    {
        ApAux= new NodoArbol<T>();
        ApAux->Info= Dato;
        Raiz= ApAux;
    }
}

template <class T>
void ArbolBinBus<T>::EliminaNodo(NodoArbol<T> *Apunt, T Dato)
{
    if (Apunt)
    {
        if (Dato < Apunt->Info)
        {
            EliminaNodo(Apunt->HijoIzq, Dato);
            Apunt->HijoIzq= Raiz;
        }
        else
            if (Dato > Apunt->Info)
            {
                EliminaNodo(Apunt->HijoDer, Dato);
                Apunt->HijoDer= Raiz;
            }
            else
            {
                NodoArbol<T> *ApAux1,*ApAux2,*ApAux3;
                ApAux3= Apunt;
                if (!ApAux3->HijoDer)
                    if (!ApAux3->HijoIzq)
                        Apunt= NULL;
                    else
                        Apunt= ApAux3->HijoIzq;
                else
                    if (!ApAux3->HijoIzq)
                        Apunt= ApAux3->HijoDer;
                    else
                    {
                        ApAux1= ApAux3->HijoIzq;
                        ApAux2= ApAux3;
                        while (ApAux1->HijoDer)
                        {
                            ApAux2= ApAux1;
                            ApAux1= ApAux1->HijoDer;
                        }
                        ApAux3->Info= ApAux1->Info;
                        if (ApAux3 == ApAux2)
                            ApAux3->HijoIzq= NULL;
                        else
                            if (!ApAux1->HijoIzq)
                                ApAux2->HijoDer= NULL;
                            else
                                ApAux2->HijoDer= ApAux1->HijoIzq;
                        ApAux3= ApAux1;
                    }
                delete(ApAux3);
            }
    Raiz= Apunt;
    }
}

#endif // ARBOLBINBUS_H_INCLUDED
