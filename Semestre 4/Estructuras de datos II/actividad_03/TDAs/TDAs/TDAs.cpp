#include <Windows.h>
#include <iostream>
 #include "Producto.h"
 #include "Lista.h"
 using namespace std;

 int Menu()
 {
	 int Opc;
	 cout << "\n\nBienvenido al sistema de registro de productos.\n\n";
	 cout << "\n(1) Registrar un nuevo producto.\n";
	 cout << "\n(2) Dar de baja un producto.\n";
	 cout << "\n(3) Verificar si un producto ya fue registrado.\n";
	 cout << "\n(4) Imprimir la lista de productos registrados.\n";
	 cout << "\n(5) Salir.\n";
	 cout << "\n\nIngrese opcin de trabajo:\n";
	 cin >> Opc;
	 return Opc;
	 }

 int main()
 {

	 ifstream file("archivo.bin");
	 Lista<Producto> ListaProds;
	 Producto ObjProd;
	 NodoLista<Producto> * Apunt;
	 int Opc, Res, Clave;

	 if (file) {
		 ListaProds.readFromDisk();
	 }


	 Opc = Menu();
	 while (Opc >= 1 && Opc <= 4)
		 {
		 switch (Opc)
			{
			 case 1: {
				 cout << "\n\nIngrese datos del producto a registrar:\n";
				 cin >> ObjProd;
				 ListaProds.InsertaOrdenCrec(ObjProd);
				 break;
			 }
			 case 2: {
				 cout << "\n\nIngrese la clave del producto a eliminar:\n";
				 cin >> Clave;
				 Producto Produc(Clave, "", 0);
				 Res = ListaProds.EliminaUnNodo(Produc);
				 switch (Res)
				 {
					 case 1: cout << "\n\nEl producto ya fue eliminado.\n";
							  break;
					 case 0: cout << "\n\nEse producto no se encuentra registrado.\n";
							  break;
					 case -1: cout << "\n\nNo hay productos registrados.\n";
							   break;
				 }
				 break;
				 }
			 case 3:
			 {
				 cout << "\n\nIngrese la clave del producto a buscar:\n";
				 cin >> Clave;
				 Producto Produc(Clave, "", 0);
				 Apunt = ListaProds.BuscaOrdenada(Produc);
				 if (!Apunt)
					 cout << "\n\nEse producto no e s t registrado.\n\n";
				 else
				 {
					 cout << "\n\nEse producto e s t registrado.\n";
					 ListaProds.ImprimeUnNodo(Apunt);
				 }
				 break;
			 }
			 case 4:ListaProds.ImprimeRecursivo(ListaProds.RegresaPrimero());
					  break;
		 }
		Opc = Menu();
		}
	ListaProds.EscribeFile();
	return 0;
}
