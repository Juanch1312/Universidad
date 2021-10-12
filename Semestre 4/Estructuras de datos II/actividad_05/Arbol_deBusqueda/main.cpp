#include <iostream>
#include "ArbolBinBus.h"
#include "Producto.h"
//#include "WriteTreeFile.cpp"
using namespace std;
int static recorrido = 0;
bool band = false;

void getString(int);
void getStringName(int, char*);

ArbolBinBus<Producto> Inventario;
NodoArbol<Producto> *Ap1, *Ap2;

int Menu()
{
    int Opcion;
    system("cls");
    do {
        cout<<"\n\n\n\tOpciones de trabajo:\n";
        cout<<"\t1.Ingresar nuevo producto.\n";
        cout<<"\t2.Dar de baja un producto.\n";
        cout<<"\t3.Reporte de todos los productos ordenados por clave.\n";
        cout<<"\t4.Buscar un producto por clave.\n";
        cout<<"\t5.Escribir en disco forma 1.\n";
        cout<<"\t6.Escribir en disco forma 2.\n";
        cout<<"\t7.Traer todos los datos del archivo.\n";
        cout<<"\t8.Traer un dato especifico del archivo.\n";
        cout<<"\t9.Terminar el proceso" << "\n\n";
        cout<<"\tIngrese opci�n seleccionada: ";
        cin>>Opcion;
    } while (Opcion <1 || Opcion > 9);
    return Opcion;
}

int main()
{
    Producto Prod, auxiliar;
    int Opc, Cla;
    char aux[10] = "";
    do {
        Opc= Menu();
        switch (Opc)
        {
            case 1:{
                    cin>>Prod;
                    Ap1= Inventario.RegresaRaiz();
                    Inventario.InsertaNodoSinRep(Ap1, Prod);
                    break;
            }
            case 2:{
                    cout<<"\n\nIngrese la clave del producto a eliminar:";
                    cin>>Cla;
                    Producto Prod(Cla,aux, 0);
                    Ap1= Inventario.RegresaRaiz();
                    Inventario.EliminaNodo(Ap1, Prod);
                    break;
            }
            case 3:{
                    Ap1= Inventario.RegresaRaiz();
                    cout<<"\n\n\n-------------------------\n\n";
                    cout<<"PRODUCTOS EN INVENTARIO\n\n";
                    cout<<"------------------------------\n\n";
                    Inventario.Inorden(Ap1);
                    break;
            }
            case 4: {
                    cout<<"\n\nIngrese la clave del producto a buscar:";
                    cin>>Cla;
                    Producto Prod(Cla, aux, 0);
                    Ap1= Inventario.RegresaRaiz();
                    Ap2= Inventario.Busqueda(Ap1, Prod);
                    if (Ap2)
                    {
                        cout<<"\n\n\nExiste un producto registrado con esa clave.\n";
                        auxiliar=Ap2->RegresaInfo();
                        cout<<auxiliar;
                    }
                    else
                        cout<<"\n\nNo se ha registrado ning�n producto con esa clave. \n";
                    break;
            }
            case 5:{
                    cout<<"\n\n\n-------------------------\n\n";
                    cout<<"Escritura en archivo preorden\n\n";
                    cout<<"------------------------------\n\n";
                    ofstream myfile("filename.txt", ios::out);
                    Inventario.WriteFile(myfile);
                    myfile.close();
                    break;
            }
            case 6:{
                    cout<<"\n\n\n-------------------------\n\n";
                    cout<<"Escritura en archivo preorden\n\n";
                    cout<<"------------------------------\n\n";
                    Ap1= Inventario.RegresaRaiz();
                    ofstream myfile("filename.txt", ios::out);
                    Inventario.WritePreordenFile(myfile,Ap1 );
                    myfile.close();
                    break;
            }
            case 7: {
              if(!band){
                getString(recorrido);
                std::cout << "Datos traidos del disco" << '\n';
                band = true;
              }
              else{
                std::cout << "Los datos ya fueron insertados." << '\n';
              }
              break;
            }
            case 8:{
              fflush(stdin);
              std::cout << "Ingrese nombre a buscar" << '\n';
              char name[10] = "";
              std::cin.getline (name,10);
              getStringName(recorrido, name);
              std::cout << "Dato traido del disco" << '\n';
              break;
            }
            case 9:{
              std::cout << "SALIENDO.." << '\n';
              break;
            }
        }
        system("pause");
    } while (Opc >=1 && Opc< 9);
    return 0;
}

void getString(int recorrido)
{
  char buffer[2000] = "";
  char lectura[2] = "";
  char id[2] = "";
  char nombre[10] = "";
  char precio[10] = "";

  int i = recorrido;
  int delimitadores = 0;
  int recor = 0, recor2 = 0, recor3 = 0;

  ifstream o("filename.txt");
  if(!o.good()){
    std::cout << "error al abrir el archivo" << '\n';
  }
  else{
    o.getline(buffer, 2000);
  }
  while (true) {
    if(buffer[i] == '#') { lectura[i] = '\0'; break; }
    lectura[i] = buffer[i];
    i++;
  }
  i++;
  while (true) {
    if(buffer[i] == '|'){ delimitadores++; }
    if(buffer[i] != '#' && buffer[i] != '|'){
      if(delimitadores == 0){ id[recor] = buffer[i]; recor++;}
      if(delimitadores == 1){ nombre[recor2] = buffer[i]; recor2++;}
      if(delimitadores == 2){ precio[recor3] = buffer[i]; recor3++;}
      if(delimitadores == 3){
        id[recor+1] = '\0';
        nombre[recor2+1] = '\0';
        precio[recor3+1] = '\0';
        break;
      }
    }
    i++;
  }
  recorrido = i;
  int pro_id = atoi(id);
  double pro_precio = atof(precio);
  Producto pro(pro_id, nombre, pro_precio);
  Inventario.InsertaNodoSinRep(Inventario.RegresaRaiz(), pro);
  if(buffer[recorrido] != '\0'){
    o.close();
    getString(recorrido);
  }
}




void getStringName(int recorrido, char* producto)
{
  char buffer[2000] = "";
  char lectura[2] = "";
  char id[2] = "";
  char nombre[10] = "";
  char precio[10] = "";

  int i = recorrido;
  int delimitadores = 0;
  int recor = 0, recor2 = 0, recor3 = 0;

  ifstream o("filename.txt");
  if(!o.good()){
    std::cout << "error al abrir el archivo" << '\n';
  }
  else{
    o.getline(buffer, 2000);
  }
  while (true) {
    if(buffer[i] == '#') { lectura[i] = '\0'; break; }
    lectura[i] = buffer[i];
    i++;
  }
  i++;
  while (true) {
    if(buffer[i] == '|'){ delimitadores++; }
    if(buffer[i] != '#' && buffer[i] != '|'){
      if(delimitadores == 0){ id[recor] = buffer[i]; recor++;}
      if(delimitadores == 1){ nombre[recor2] = buffer[i]; recor2++;}
      if(delimitadores == 2){ precio[recor3] = buffer[i]; recor3++;}
      if(delimitadores == 3){
        id[recor+1] = '\0';
        nombre[recor2+1] = '\0';
        precio[recor3+1] = '\0';
        break;
      }
    }
    i++;
  }
  recorrido = i;
  if(strcmp(producto, nombre) == 0){
    o.close();
    int pro_id = atoi(id);
    double pro_precio = atof(precio);
    Producto pro(pro_id, nombre, pro_precio);
    Inventario.InsertaNodoSinRep(Inventario.RegresaRaiz(), pro);
  }
  else{
    getStringName(recorrido, producto);
  }
}
