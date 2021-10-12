#include <stdio.h>
#include <iostream>
#pragma warning(disable : 4996) //Evitar error que lanza Visual Studio al trabajar con archivos.

#ifndef GLOBALES_H_INCLUDED
#define GLOBALES_H_INCLUDED

#define listavacia (cabecera == NULL)
typedef class datos elemento;

//Creacion de la clase datos
class datos
{
public:
	datos();
	~datos();

	int getDato();

	elemento* NuevoElemento();
	void Error();
	int Menu();
	void Anadir(elemento**, int);
	void Borrar(elemento**, int);
	elemento* Buscar(elemento*, int);
	void Visualizar(elemento*);
	void IntroducirListaNueva(elemento**, elemento**, int);
	void GrabarEnDisco(elemento*, FILE*);

private:
	int dato;
	elemento* siguiente;
};

int tam_reg = sizeof(elemento);

datos::datos() //Inicializar atributos
{
	this->dato = 0;
	this->siguiente = NULL;
}

datos::~datos(){ } 

inline int datos::getDato() //Metodo obtener dato
{
	return this->dato;
}

inline elemento* datos::NuevoElemento()
{
	return ((elemento*)malloc(sizeof(elemento))); //Reservar memoria que necesita el tipo elemento
}

inline void datos::Error() //No existe mas memoria disponible
{
	perror("Error: insuficiente espacio de memoria.\n");
	exit(1);
}

inline int datos::Menu() //Desplegar menu
{
	int op;

	do
	{
		std::cout << "\n\n\t ***** Menu de operaciones ***** \n ";
		std::cout << "\n\t 1. Anadir un elemento\n";
		std::cout << "\n\t 2. Borrar un elemento\n";
		std::cout << "\n\t 3. Buscar un elemento\n";
		std::cout << "\n\t 4. Visualizar la lista\n";
		std::cout << "\n\t 5. Salir\n";
		std::cout << "\n\n\t Su opcion (1 - 5): ";
		std::cin >> op;
	} while (op < 1 || op > 5);
	return (op);
}

inline void datos::Anadir(elemento** cab, int dato)
{
	elemento* cabecera = *cab;
	elemento* actual = cabecera, * anterior = cabecera, * q;
	if (listavacia) //Comprobar si lista esta vacia
	{
		cabecera = NuevoElemento();
		cabecera->dato = dato;
		cabecera->siguiente = NULL;
		*cab = cabecera;
		return;
	}

	//Recorre y encuentra posicion de insercion en orden de asencion
	while (actual != NULL && dato > actual->dato)
	{
		anterior = actual;
		actual = actual->siguiente;
	}

	q = NuevoElemento();
	if (anterior == actual)
	{
		q->dato = dato;
		q->siguiente = cabecera;
		cabecera = q;
	}

	else
	{
		q->dato = dato;
		q->siguiente = actual;
		anterior->siguiente = q;
	}
	*cab = cabecera;
}

inline void datos::Borrar(elemento** cab, int dato)
{
	elemento* cabecera = *cab;
	elemento* actual = cabecera, * anterior = cabecera;
	if (listavacia) //Comprobar si la lista esta vacia
	{
		std::cout << "\tLista Vacia\n";
		return;
	}

	while (actual != NULL && dato != actual->dato) //Recorrer lista
	{
		anterior = actual;
		actual = actual->siguiente;
	}

	//Comprobar que actual y anterior apunten al dato correcto
	if (actual == NULL)
		return;

	if (anterior == actual)
		cabecera = cabecera->siguiente;
	else
		anterior->siguiente = actual->siguiente;

	free(actual);
	*cab = cabecera;
}

inline elemento* datos::Buscar(elemento* cabecera, int dato) //Buscar dato
{
	elemento* actual = cabecera;
	while (actual != NULL && dato != actual->dato) //Recorrida de lista para encontrar el dato
		actual = actual->siguiente;
	return (actual); //Devuelte puntero donde se encuentra el dato
}

inline void datos::Visualizar(elemento* cabecera) //Imprimir lista
{
	elemento* actual = cabecera;
	if (listavacia)
		std::cout<<"\tLista  Vacia\n";
	else
	{
		while (actual != NULL)
		{
			std::cout << "        -->" << actual->dato;
			actual = actual->siguiente;
		}
		std::cout << " NULL" << std::endl;
	}
}

inline void datos::IntroducirListaNueva(elemento** p, elemento** f, int dato)
{
	elemento* pc, * fc, * q;
	pc = *p; //Asigna cabecera
	fc = *f; //Asigna final
	q = NuevoElemento();
	q->dato = dato;
	q->siguiente = NULL;
	if (fc == NULL) //Comprobar si se llego al fin de los datos
		pc = fc = q;
	else
	{
		fc->siguiente = q;
		fc = fc->siguiente;
	}
	*p = pc;
	*f = fc;
}

inline void datos::GrabarEnDisco(elemento* cab, FILE* puntero_fich)
{
	elemento* aux;
	puntero_fich = fopen("datos", "wb");
	rewind(puntero_fich);
	aux = cab;

	if (aux == NULL)
	{
		std::cout<<"\n\t LISTA VACIA!!!";
		return;
	}

	while (aux != NULL) //Recorrer lista hasta que apunte a nulo
	{
		fwrite(aux, tam_reg, 1, puntero_fich);
		aux = aux->siguiente;
	}

	fclose(puntero_fich);
}



#endif // !GLOBALES_H_INCLUDED
