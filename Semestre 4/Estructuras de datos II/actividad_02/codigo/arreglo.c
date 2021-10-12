#include<stdio.h>

void identificador();


void main() {
    int op;
    while(op!=6)
    {   printf("MENU\n");
        printf("1.- Suma de filas de una matriz\n");
        printf("2.- Suma de matrices\n");
        printf("3.- Identificar una letra\n");
        printf("4.- Numeros repetidos\n");
        printf("5.- Ordenar numero\n");
        printf("6.- Salir\n");
        printf("Indica la opcion: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1: identificador();break;
            case 2: identificador();break;
            case 3: identificador();break;
            case 4: identificador();break;
            case 5: identificador();break;
            case 6: break;
        }
    }
}


//------------------------definicion de funciones----------------------------------
void identificador(){
    int x=4, y=5, i,j;
    char  matriz[4][5], copia[4][5], letra, letra_modificada;
    fflush(stdin);
    for (i = 0; i < x; i++) {
            for (j = 0; j < y; j++){
                printf("ingresar numero en posicion %d %d: ", i, j);
                scanf("%c", &matriz[i][j]);
                fflush(stdin);
            }
    }
     for (i = 0; i < x; i++) {
            for (j = 0; j < y; j++){
                copia[i][j]=matriz[i][j];
            }
    }

    printf("ingresa la letra que quieras modificar");
    scanf("%c", &letra);
    fflush(stdin);
    printf("ingresa la letra por la que quieras modificar");
    scanf("%c", &letra_modificada);
    fflush(stdin);

    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++){
                if(copia[i][j]==letra){
                    copia[i][j]=letra_modificada;
                }
        }
    }

    printf("Su matriz original es: \n");
    for (i = 0; i < x; i++) {
            for (j = 0; j < y; j++){
                printf("%c: \t", matriz[i][j]);
            }
             printf("\n");
    }
    printf("Su matriz modificada es: \n");
    for (i = 0; i < x; i++) {
            for (j = 0; j < y; j++){
                printf("%c: \t", copia[i][j]);
            }
             printf("\n");
    }
}
