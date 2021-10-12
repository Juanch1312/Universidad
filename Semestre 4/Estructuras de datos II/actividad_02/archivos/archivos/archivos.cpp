#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "globales.h"
#include <iostream>


int main()
{
    //Creacion de variables
    datos lista;
    FILE* pf;
    elemento* cabecera = NULL, * final = NULL;
    elemento* q;
    datos aux;
    int opcion, dato;

    //Apertura del archivo
    pf = fopen("datos", "rb");
    if (pf != NULL) //Comprobar si existe informacion dentro del archivo
    {

        std::cout << "\n\t Trayendo datos del disco...." << std::endl;
        fread(&aux, tam_reg, 1, pf);
        while (!feof(pf) && !ferror(pf))
        {
            lista.IntroducirListaNueva(&cabecera, &final, aux.getDato());
            fread(&aux, tam_reg, 1, pf);
        }
        std::cout<< "\n\t Datos traidos del disco....\n\n";
        fclose(pf);
    }
    while (1)
    {
        opcion = lista.Menu();
        switch (opcion)
        {
        case 1: //Añadir
            std::cout << "\n\t Anadir dato: ";
            std::cin >> dato;
            lista.Anadir(&cabecera, dato);
            break;
        case 2: //Borrar
            std::cout << "\n\t Borrar dato: ";
            std::cin >> dato;
            lista.Borrar(&cabecera, dato);
            break;
        case 3: //Buscar
            std::cout << "\n\t Buscar dato: ";
            std::cin >> dato;
            q = lista.Buscar(cabecera, dato);
            if (q) //Existe el dato
                std::cout << "\n\t Dato encontrado!!";
            else //No existe
                std::cout << "\n\t Lista vacia\n";
            break;
        case 4: //Listar
            lista.Visualizar(cabecera);
            break;
        case 5: //Guardar datos, cerrar archivo y salir
            std::cout << "\n\t Iniciada la copia de datos al disco...";
            lista.GrabarEnDisco(cabecera, pf);
            std::cout << "\n\t Datos copiados al disco \n\n";
            exit(0);
            break;
        }
        std::cout << "\nPulse una tecla para continuar";

        system("pause>>cls");
    }
    return 0;
}