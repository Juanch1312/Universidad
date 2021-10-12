#include <iostream>
#include <cstdlib>

using namespace std;

int *suma (int*,int*);
int *Sustraccion (int*,int*);
int *Multiplicacion (int*,int*);
int *Divicion (int*,int*);


int n1=0,n2=0,*ptr1,*ptr2;

int main (){
  int opc=0;
  do{
    system("cls");
    cout<<"Que operacion desea realizar"<<endl;
    cout<<"1)Adicion"<<endl;
    cout<<"2)Sustraccion"<<endl;
    cout<<"3)Multiplicacion"<<endl;
    cout<<"4)Divicion"<<endl;
    cout<<"5)Salir"<<endl;
    cin>>opc;
    switch(opc){
      case 1:{
        cout<<"Inserte el numero 1"<<endl;
        cin>>n1;
        cout<<"Inserte el numero 2"<<endl;
        cin>>n2;
        ptr1=&n1;
        ptr2=&n2;
        cout<<"La suma es: "<<*suma(ptr1,ptr2)<<endl;
        system("pause");
      }break;
      case 2:{
        cout<<"Inserte el numero 1"<<endl;
        cin>>n1;
        cout<<"Inserte el numero 2"<<endl;
        cin>>n2;
        ptr1=&n1;
        ptr2=&n2;
        cout<<"La resta es: "<<*Sustraccion(ptr1,ptr2)<<endl;
        system("pause");
      }break;
      case 3:{
        cout<<"Inserte el numero 1"<<endl;
        cin>>n1;
        cout<<"Inserte el numero 2"<<endl;
        cin>>n2;
        ptr1=&n1;
        ptr2=&n2;
        cout<<"EL resultado de la Multiplicacion es: "<<*Multiplicacion(ptr1,ptr2)<<endl;
        system("pause");
      }break;
      case 4:{
        cout<<"Inserte el numero 1"<<endl;
        cin>>n1;
        cout<<"Inserte el numero 2"<<endl;
        cin>>n2;
        ptr1=&n1;
        ptr2=&n2;
        cout<<"EL resultado de la Divicion es: "<<*Divicion(ptr1,ptr2)<<endl;
        system("pause");
      }break;
      case 5:{
        cout<<"Saliendo del programa..."<<endl;
      }
      default:{
        cout<<"Opcion invalida eliga otra"<<endl;
        system("pause");
      }
    }
  }while (opc !=5);
  system("pause>>cls");
  return 0;
}

int *suma (int *n1,int *n2){
  int *r =(int*)malloc(sizeof(int));
  *r = (*n1)+(*n2);
  return r;
}

int *Sustraccion (int *n1, int *n2){
  int *r =(int*)malloc(sizeof(int));
  *r = (*n1)-(*n2);
  return r;
}

int *Multiplicacion (int *n1, int*n2){
  int *r =(int*)malloc(sizeof(int));
  *r = (*n1)*(*n2);
  return r;
}

int *Divicion (int *n1, int*n2){
  int *r =(int*)malloc(sizeof(int));
  *r = (*n1)/(*n2);
  return r;
}
