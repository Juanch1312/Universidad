#include <iostream>
#include <stdlib.h>
using namespace std;
struct Object
{
    int number;
    struct Object *left, *right;
};
typedef struct Object *Node;

Node CreateNode(int x)
{
    Node newNode = new( Object);
    newNode->number = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void add(Node &ptr, int x)
{
    if(ptr==NULL)
        {
        ptr = CreateNode(x);
        }
    else if(x < ptr->number)
        add(ptr->left, x);
    else if(x > ptr->number)
        add(ptr->right, x);
}
void show(Node ptr, int n)
{
    if(ptr==NULL)
        return;
    show(ptr->right, n+1);
    for(int i=0; i<n; i++)
        cout<<" ";
    cout<< ptr->number <<endl;
    show(ptr->left, n+1);
}

void PreOrden(Node ptr){
  if(ptr != NULL){
    std::cout << ptr->number << ", ";
    PreOrden(ptr->left);
    PreOrden(ptr->right);
  }
  else{
    return;
  }
}

void EnOrden(Node ptr){
  if(ptr != NULL){
    EnOrden(ptr->left);
    std::cout << ptr->number << ", ";
    EnOrden(ptr->right);
  }
  else{
    return;
  }
}

void PostOrden(Node ptr){
  if(ptr != NULL){
    PostOrden(ptr->left);
    PostOrden(ptr->right);
    std::cout << ptr->number << ", ";
  }
  else{
    return;
  }
}

int validacionunica(char n[100]){
  if(isdigit(n[0])=='-'||n[0]=='.'){
    if(isdigit(n[1])){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    if(isdigit(n[0])){
      return 1;
    }
    else{
      return 0;
    }
  }
}


int main(int argc, char** argv)
{
  int number, input;
  do{
    system("cls");
    Node ptr = NULL;
    char x[100],y[100];
    std::cout << "-------------------------------Arbol-----------------------------"<< endl;
    std::cout << " Inserte un total de nodos: " << std::endl;
    std::cin >> x;
    if(validacionunica(x)==1){
      number = atoi(x);
    std::cout << std::endl;
    for(int i=0; i<number; i++)
        {
        cout << " ingrese numero: " << i+1 << ": ";
        cin >> y;
        if(validacionunica(y)==1){
          input = atoi(y);
        add( ptr, input);
        }
        else{
          std::cout<<"Entrada de datos erroneo"<<std::endl;
          system("pause");
          i--;
        }
        }
    std::cout << "Nodos en el arbol: "<<std::endl;
    show( ptr, 0);
    std::cout<<"PreOrden: "<<std::endl;
    PreOrden(ptr);
    std::cout<<endl<<"EnOrden: "<<std::endl;
    EnOrden(ptr);
    std::cout<<endl<<"PostOrden: "<<std::endl;
    PostOrden(ptr);
    system("pause");
    }
    else{
      std::cout<<"Entrada de datos incorrecta"<<std::endl;
      system("pause");
    }
  }while(number !=0);

    system("pause");
    return 0;
}
