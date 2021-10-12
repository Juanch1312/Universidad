#include <iostream>


#include <cstdlib>
#include <string.h>


using namespace std;

template<typename T>
class Nodo{
public:
    Nodo();
    Nodo(T,T);
    ~Nodo();
    Nodo *next;
    T id;
    T nombre;
    void print();
};
template<typename T>
Nodo<T>::Nodo()
{   id= NULL;
    nombre=NULL;
    next=NULL;
}

template<typename T>
Nodo<T>::Nodo(T id_,T nombre_ )
{
    id=id_;
    nombre=nombre_;
    next=NULL;
}
template<typename T>
void Nodo<T>::print()
{
    cout<<"Id:"<<id<<endl;
    cout<<"Nombre:"<<nombre<<endl;

}
template<typename T>
Nodo<T>::~Nodo(){}

template<class T>

class List
{
private:
    Nodo<T> *ptrHead;
    int number_nodo;
public:
        List();
        ~List();

        void add_head(T,T);
        void add_end(T,T);
        void add_sort(T,T);
        void delete_position(int);
        void print();
        void Search(T);
        string buscar_pos(int);
        void invertir();
        void buscar_nom(T);
        void Eliminar_Todo();
        void Ordenar();
        void Modificar(int);
};
template<typename T>
List<T>::List()
{
    number_nodo=0;
    ptrHead=NULL;
}
 template<typename T>
 List<T>::~List(){}

//Insertar al inicio
template<typename T>
void List<T>::add_head(T id_,T nombre_)
{
    Nodo<T> *new_nodo=new Nodo<T>(id_,nombre_);
    Nodo<T> *temp = ptrHead;
    if(!ptrHead){
        ptrHead=new_nodo;
    }
    else{
        new_nodo->next=ptrHead;
        ptrHead= new_nodo;
        while(temp){
            temp=temp->next;
        }
    }
    number_nodo++;
}

template <typename T>
void List<T>::add_sort(T id_,T nombre_)
{
    Nodo<T> *new_nodo= new Nodo<T> (id_,nombre_);
    Nodo<T> *temp=ptrHead;
    if (!ptrHead){
        ptrHead=new_nodo;
    }
    else{
            if(ptrHead->id==id_){
                new_nodo->next=ptrHead;
                ptrHead=new_nodo;
            }
            else{
                while(temp->next!=NULL){
                    temp= temp->next;
                }
                new_nodo->next=temp->next;
                temp->next=new_nodo;
            }
    }
    number_nodo++;
}
template<typename T>
void List<T>::delete_position(int pos)
{
    Nodo<T>*temp=ptrHead;
    Nodo<T>*temp1=temp->next;
    if(pos<1||pos>number_nodo){
        cout<<"Fuera de rango\n";
    }
    else if(pos==1){
        ptrHead=temp->next;
        delete temp;
        number_nodo--;
    }
    else{
        for(int i=2;i<=pos;i++){
            if(i==pos){
                Nodo<T>*aux_nodo=temp1;
                temp->next=temp1->next;
                delete aux_nodo;
                number_nodo--;
            }
            temp=temp->next;
            temp1=temp1->next;
        }
    }
}


template<typename T>
void List<T>::print()
{
 Nodo<T> *temp=ptrHead;
    if(!ptrHead){
        cout<<"La Agenda esta vacia\n";
 }
    else{
        while(temp){
            temp->print();
            cout<<"\n\n";
                temp=temp->next;
        }
    }
}

template<typename T>
void List<T>::Search(T id_)
{
    Nodo<T> *temp=ptrHead;
    int count1=1,count2=0;
    while(temp){
        if(temp->id==id_){
            cout<<"Encontrado en la posicion:"<<count1<<endl;
            count2++;
        }
        temp=temp->next;
        count1++;
    }
    if(count2==0){
        cout<<"No existe el dato\n";
    }
    cout<<"\n\n";
}

template<typename T>
string List<T>::buscar_pos(int pos)
{
    Nodo<T> *temp=ptrHead;
    string result;
    int count2=0;
    while(temp){
        if(count2==pos){
          result += temp->id;
          result += " | ";
          result += temp->nombre;
          return result;
          }
        temp=temp->next;
        count2++;
    }
    result = "Dato no encontrado";
    return result;
}

template<typename T>
void List<T>::buscar_nom(T id_)
{
    Nodo<T> *temp=ptrHead;
    int count1=1,count2=0;
    while(temp){
        if(temp->nombre==id_){
            cout<<"Encontrado en la posicion:"<<count1<<endl;
            count2++;
        }
        temp=temp->next;
        count1++;
    }
    if(count2==0){
        cout<<"No existe el dato\n";
    }
    cout<<"\n\n";
}
template<typename T>
void List<T>::Eliminar_Todo()
{
    if(ptrHead==NULL)
        cout<<"La agenda esta vacia\n";
    else{
        Nodo<T>* aux1=ptrHead;
        Nodo<T>* aux2=aux1;
        while(aux1==NULL){
            delete aux1;
            aux1=aux2->next;
            aux2=aux2->next;


        }
        ptrHead=NULL;
        number_nodo=0;
        cout<<"Se eliminaron los datos\n";
    }
}


template<typename T>
void List<T>::Ordenar(){
  T data;
  Nodo<T> *aux = ptrHead;
  Nodo<T> *temp = aux;

  while(aux){
    temp=aux;
    while(temp->next){
      temp=temp->next;
      if(aux->nombre > temp->nombre){
        data = aux->nombre;
        aux->nombre = temp->nombre;
        temp->nombre = data;
      }
    }
    aux=aux->next;
  }
}

template<typename T>
void List<T>::invertir(){
  Nodo<T> *prev = NULL;
  Nodo<T> *next = NULL;
  Nodo<T> *temp = ptrHead;
  while(temp){
    next = temp->next;
    temp->next = prev;
    prev = temp;
    temp=next;
  }
  ptrHead=prev;
}


template<typename T>
void List<T>::Modificar(int pos)
{
    Nodo<T> *aux=ptrHead;
    if(pos<number_nodo+1&&pos>0){
      for(int i=1;i<pos;i++){
        aux=aux->next;
      }
      cout<<"Ingrese el nuevo nombre: "<<endl;
      cin.ignore();
      getline(cin,aux->nombre);
    }
    else{
      cout<<"No se encontro ningun dato"<<endl;
    }
}




int main (int argc,char *argv[])
{
    List<string> list1;
    int element,dimention,pos,dat,opc;
    string id_ ,nombre_,correo_,numero_,direccion_;
    char opc2[1000];
    do{

        cout<<"1-.Agregar contacto \n";
        cout<<"2-.Buscar contacto.\n";
        cout<<"3-.Eliminar contacto.\n";
        cout<<"4-.Buscar por posicion\n";
        cout<<"5-.Invertir\n";
        cout<<"6-.Buscar por nombre\n";
        cout<<"7-.Ordenar alfabeticamente\n";
        cout<<"8-.Imprimir datos\n";
        cout<<"9-.Modificar\n";
        cout<<"10-.Eliminar Todo\n";
        cout<<"11-.Salir..\n";
        cout<<"Seleccione un opcion\n";
         do{
		 cin.sync();
		 cin>>opc2;
     opc=atoi(opc2);

     if(opc<0 || opc>11){
       cout<<"Ingresa puros numeros"<<endl;
     }
   }while(opc<=0 || opc>=11);



   switch (opc){
     case 1:{
       system ("CLS");
       cin.sync();
       cout<<"ID \n";
       do{

         getline(cin,id_);

         if(id_<="0" || id_>="9"){
           cout<<"Ingresa puros numeros"<<endl;
         }
       }while(id_<="0"|| id_>="9");


       cout<<"Nombre \n";
       getline(cin,nombre_);


       list1.add_head(id_,nombre_);
       list1.print();
       system("pause");
       break;
     }

     case 2:{
       getline(cin,id_);
       cout<<"Busca un elemento\n";
       do{

         getline(cin,id_);
         if(id_<="0" || id_>="9"){
           cout<<"Ingresa puros numeros"<<endl;
         }
       }while(id_<="0"|| id_>="9");
       list1.Search(id_);
       system("pause");
       break;
     }
     case 3:{
       cout<<"Elimina posicion\n";
       cin>>pos;
       list1.delete_position(pos);
       list1.print();
       system("pause");
       break;
     }
     case 4:{
       int pos;
       cout<<"Inserte la posicion"<<endl;
       cin>>pos;
       cout<<list1.buscar_pos(pos);
       system("pause");
       break;
     }
     case 5:{
       list1.invertir();
       list1.print();
       system("pause");
       break;
     }
     case 6:{
       getline(cin,id_);
       cout<<"Ingresa el nombre a buscar\n";
       getline(cin,id_);
       list1.buscar_nom(id_);
       system("pause");
       break;
     }
     case 7:{
       list1.Ordenar();
       list1.print();
       system("pause");
       break;
     }
     case 8:{
       list1.print();
       system("pause");
       break;
     }
     case 9:{
       cout<<"Ingresa la posicion del dato a modificar\n";
       cin>>dat;
       list1.Modificar(dat);
       list1.print();
       system("pause");
       break;
     }
     case 10:{
       list1.Eliminar_Todo();
       break;
     }
     case 11:{
       cout<<"Saliendo..."<<endl;
     }break;
     default:{
       cout<<"\nDato incorrecto intentelo de nuevo...\n"<<endl;
       system("pause");
     }break;

   }
   cout<<endl;
   system("cls");
 }while(opc != 11);
 return 0;
}
