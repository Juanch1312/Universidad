#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <Cstring>

class Producto
{
    private:
        int Clave;
        char NomProd[64];
        double Precio;
    public:
        Producto();
        Producto(int, char[], double);
        double getPrecio();
        char* getNomProd();
        int getClave();
        char* getArgumString(char * );
        int WriteProductFile(std::ostream &);
        int ReadProductFile(std::istream &, Producto &);
        int operator == (Producto);
        int operator != (Producto);
        int operator > (Producto);
        int operator < (Producto);
        void operator = (Producto);
        friend std::istream &operator>> (std::istream &, Producto &);
        friend std::ostream &operator<< (std::ostream &,Producto &);
};

Producto::Producto()
{ }

Producto::Producto(int Cla, char NomP[], double Pre)
{
    Clave= Cla;
    strcpy(NomProd, NomP);
    Precio= Pre;
}

double Producto::getPrecio()
{
    return Precio;
}

int Producto::getClave()
{
    return Clave;
}

char* Producto::getNomProd()
{
    return NomProd;
}

char* Producto::getArgumString(char * buffer)
{
    std::stringstream s,r;
    char cPrecio[15], cClave[15];
    s<<Clave; s>>cClave;
    strcpy(buffer,cClave);
    strcat(buffer, "|");
    strcat(buffer,NomProd);
    strcat(buffer, "|");
    r<<Precio; r>>cPrecio;
    strcat(buffer,cPrecio);
    strcat(buffer, "|");
    return buffer;
}

int Producto::WriteProductFile(std::ostream &stream)
{
    const int MaxBufferSize = 200;
    std::stringstream s,r;
    char cPrecio[15], cClave[15];
    char buffer [MaxBufferSize]; // create buffer of fixed size
    s<<Clave; s>>cClave;
    strcpy(buffer, (char *) &cClave); strcat(buffer, "|") ;
    strcat(buffer, NomProd); strcat(buffer,"|");
    r<<Precio; r>>cPrecio;
    strcat(buffer, (char *) &cPrecio); strcat(buffer,"|");
    short length=strlen(buffer);
    stream.write((char*)&length,sizeof(length)); // write length
    stream.write((char*)&buffer, length);
    return 0;
}

int Producto::ReadProductFile(std::istream &stream, Producto &p)
{
    char clength[15], cPrecio[15], cClave[15];
    stream.getline(clength, 30, '#');
    stream.getline(cClave, 30, '|');
    Clave=atoi(cClave);
    stream.getline(p.NomProd, 64, '|');
    stream.getline(cPrecio, 30, '|');
    Precio=atof(cPrecio);
    return 0;
}

int Producto::operator == (Producto Prod)
{
    int Resp=0;
    if (Clave == Prod.Clave)
        Resp= 1;
    return Resp;
}

int Producto::operator != (Producto Prod)
{
    int Resp=0;
    if (Clave != Prod.Clave)
        Resp= 1;
    return Resp;
}

int Producto::operator > (Producto Prod)
{
    int Resp=0;
    if (Clave > Prod.Clave)
        Resp= 1;
    return Resp;
}

int Producto::operator < (Producto Prod)
{
    int Resp=0;
    if (Clave < Prod.Clave)
        Resp= 1;
    return Resp;
}

void Producto::operator = (Producto Prod)
{
    Clave= Prod.Clave;
    strcpy(NomProd, Prod.NomProd);
    Precio= Prod.Precio;
}

std::istream &operator>> (std::istream &Lee, Producto &ObjProd)
{
    std::cout<<"\n\nIngrese clave del producto: ";
    Lee>> ObjProd.Clave;
    std::cout<<"\n\nIngrese nombre del producto: ";
    Lee>> ObjProd.NomProd;
    std::cout<<"\n\nIngrese precio: ";
    Lee>> ObjProd.Precio;
    return Lee;
}

std::ostream &operator<< (std::ostream &Escribe, Producto &ObjProd)
{
    Escribe<<"\n\nDatos del producto\n";
    Escribe<<"\nClave: "<<ObjProd.Clave;
    Escribe<<"\nNombre: "<<ObjProd.NomProd;
    Escribe<<"\nPrecio: "<<ObjProd.Precio<<"\n";
    return Escribe;
}


#endif // PRODUCTO_H_INCLUDED
