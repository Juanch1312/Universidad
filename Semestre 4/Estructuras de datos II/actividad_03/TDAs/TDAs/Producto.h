#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#pragma warning(disable : 4996)
#include <iostream>
#include <sstream>
#include <fstream>
#include <Cstring>
#include "Lista.h"
using namespace std;
class Producto
{
private:
    int Clave;
    char NomProd[64];
    double Precio;
public:
    Producto();
    Producto(int,const char[], double);
    double RegresaPrecio();
    void Capturar();
    Producto Leer();
    int operator == (Producto);
    int operator != (Producto);
    int operator > (Producto);
    int operator < (Producto);
    friend istream& operator>> (istream&, Producto&);
    friend ostream& operator<< (ostream&, Producto&);
};

Producto::Producto()
{ }

Producto::Producto(int Cla,const char NomP[], double Pre)
{
    Clave = Cla;
    strcpy(NomProd, NomP);
    Precio = Pre;
}

double Producto::RegresaPrecio()
{
    return Precio;
}

void Producto::Capturar()
{
    int a=0, b=0, c=0;
    char converc[20];
    stringstream ss;

    ofstream o("archivo.bin", ios::app);
    if (!o.good()) {
        cout << "error al abrir archivo" << endl;
    }
    else {

        ss << strlen((char*)&Clave);
        ss >> converc;
        o.write((char*)&converc, sizeof(int));
        o.write((char*)&Clave, c);

        a = strlen(NomProd);
        o.write((char*)&a, sizeof(int));
        o.write((char*)&NomProd, a);

        ss << strlen((char*)&converc);
        ss >> converc;
        o.write((char*)&b, sizeof(int));
        o.write((char*)&converc, b);

    }
    o.close();
}

Producto Producto::Leer()
{
    int a=0, b=0, c=0;
    Producto n;
    char converc[20];
    stringstream ss;
    ifstream o("archivo.bin");
    if (!o.good()) {
        cout << "error al abrir archivo" << endl;
    }
    else{
      ss << strlen((char*)&Clave);
      ss >> converc;
      o.read((char*)&c, sizeof(int));
      o.read((char*)&Clave, c);

      a = strlen(NomProd);
      o.read((char*)&a, sizeof(int));
      o.read((char*)&NomProd, a);


      o.read((char*)&b, sizeof(int));
      o.read((char*)&converc, b);
      double d = atof(converc)+9;
      Producto pro(Clave-3,NomProd,d);
      return pro;
    }
    o.close();
    return n;
}


int Producto::operator == (Producto Prod)
{
    int Resp = 0;
    if (Clave == Prod.Clave)
        Resp = 1;
    return Resp;
}

int Producto::operator != (Producto Prod)
{
    int Resp = 0;
    if (Clave != Prod.Clave)
        Resp = 1;
    return Resp;
}

int Producto::operator > (Producto Prod)
{
    int Resp = 0;
    if (Clave > Prod.Clave)
        Resp = 1;
    return Resp;
}

int Producto::operator < (Producto Prod)
{
    int Resp = 0;
    if (Clave < Prod.Clave)
        Resp = 1;
    return Resp;
}
istream& operator>> (istream& Lee, Producto& ObjProd)
{
    cout << "\n\nIngrese clave del producto: ";
    Lee >> ObjProd.Clave;
    cout << "\n\nIngrese nombre del producto: ";
    Lee >> ObjProd.NomProd;
    cout << "\n\nIngrese precio: ";
    Lee >> ObjProd.Precio;
    return Lee;
}

ostream& operator<< (ostream& Escribe, Producto& ObjProd)
{
    Escribe << "\n\nDatos del producto\n";
    Escribe << "\nClave: " << ObjProd.Clave;
    Escribe << "\nNombre: " << ObjProd.NomProd;
    Escribe << "\nPrecio: " << ObjProd.Precio << "\n";
    return Escribe;
}


#endif // PRODUCTO_H_INCLUDED
