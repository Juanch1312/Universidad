#include <iostream>
#include <cstdlib>
#include "Menu.h"
using namespace std;

template<class T>
class CircularList{
private:
  class Node{
  public:
    T data;
    Node *next;
    Node *back;
  };
  Node *ptrHead;

public:
  CircularList();
  ~CircularList();
  void Insert_First(int);
  void Insert_Last(int);
  bool Empty();
  void Print();
  int Travel();
  void Remove(int);
  void Search(int);
  void Modificar(int, int);
};

template<class T>
CircularList<T>::CircularList(){
  ptrHead = NULL;
}

template<class T>
CircularList<T>::~CircularList(){
  if(ptrHead != NULL){
    Node *temp = ptrHead->next;
    Node *temp_ptrHead;

    while(temp != ptrHead){
      temp_ptrHead = temp;
      temp = temp->next;
      delete temp_ptrHead;
    }
    delete ptrHead;
  }
}

template<class T>
void CircularList<T>::Insert_First(int number){
  Node *new_node = new Node();
  new_node->data = number;

  if(ptrHead == NULL){
    new_node->next = new_node;
    new_node->back = new_node;
    ptrHead = new_node;
  }
  else{
    Node *lastnode = ptrHead->back;
    new_node->next = ptrHead;
    new_node->back = lastnode;
    ptrHead->back = new_node;
    lastnode->next = new_node;
    ptrHead = new_node;
  }
}

template<class T>
void CircularList<T>::Insert_Last(int number){
  Node *new_node = new Node();
  new_node->data = number;

  if(ptrHead == NULL){
    new_node->next = new_node;
    new_node->back = new_node;
    ptrHead = new_node;
  }
  else{
    Node *lastnode = ptrHead->back;
    new_node->next = ptrHead;
    new_node->back = lastnode;
    ptrHead->back = new_node;
    lastnode->next = new_node;
  }
}

template<class T>
bool CircularList<T>::Empty(){
  if(ptrHead == NULL){
    return true;
  }
  else{
    return false;
  }
}

template<class T>
void CircularList<T>::Print(){
  if(!Empty()){
    Node* temp = ptrHead;
    do{
      cout<<temp->data <<"-";
      temp = temp->next;
    }while(temp != ptrHead);
    cout << "\n";
  }
}

template<class T>
int CircularList<T>::Travel(){
  int cont = 0;
  if(!Empty()){
    Node* temp = ptrHead;
    do{
      cont++;
      temp = temp->next;
    }while(temp != ptrHead);
  }
  return cont;
}

template<class T>
void CircularList<T>::Remove(int position){
  if(position <= Travel()){
    if(position == 1){
      if(Travel() == 1){
        delete ptrHead;
        ptrHead = NULL;
      }
      else{
        Node *temp_ptrHead = ptrHead;
        Node *lastnode = ptrHead->back;
        ptrHead = ptrHead->next;
        lastnode->next = ptrHead;
        ptrHead->back = lastnode;
        delete temp_ptrHead;
      }
    }
    else{
      Node *temp = ptrHead;
      for(int i=1; i<=position-1;i++){
        temp = temp->next;
        Node *temp_ptrHead = temp;
        Node *back = temp->back;
        temp = temp->next;
        back->next = temp;
        temp->back = back;
        delete temp_ptrHead;
      }
    }
  }
}

template<class T>
void CircularList<T>::Search(int position) {
    int cont = 0;
    if (!Empty()) {
        Node* temp = ptrHead;
        do {
            cont++;
            temp = temp->next;
            if (cont == position) {
                std::cout << "Data found: " << temp->data << std::endl;
                break;
            }
        } while (temp != ptrHead);
    }
}

template<class T>
void CircularList<T>::Modificar(int position, int number) {
    int cont = 0;
    if (!Empty()) {
        Node* temp = ptrHead;
        do {
            cont++;
            temp = temp->next;
            if (cont == position) {
                temp->data = number;
                break;
            }
        } while (temp != ptrHead);
    }
}





int validacionunica(char n[100]) {
    if (isdigit(n[0]) == '-' || n[0] == '.') {
        if (isdigit(n[1])) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        if (isdigit(n[0])) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

int validacion(char n[100], char n2[100]) {
    if (n[0] == '-' || n2[0] == '-' || n[0] == '.' || n2[0] == '.') {
        if (isdigit(n[1]) && isdigit(n2[1])) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        if (isdigit(n[0]) && isdigit(n2[0])) {
            return 1;
        }
        else {
            return 0;
        }

    }
}



int main()
{
    Menu mymenu;
    int opcv = 0, truenumber = 0, truenumber2 = 0;
    char number[100],number2[100];
    CircularList<int>*obj = new CircularList<int>();
    
    do {

        system("cls");
        mymenu.GetMenu();
        opcv = atoi(mymenu.GetOption());
        switch (opcv) {

        case 1: {
            std::cout << "Insert an value" << std::endl;
            std::cin >> number;
            if (validacionunica(number) == 1) {
                truenumber = atoi(number);
                obj->Insert_First(truenumber);
                std::cout << "Element insert correctly" << std::endl;
                system("pause");
            }
            else {
                std::cout << "Incorrect value" << std::endl;
                system("pause");
            }
        }break;

        case 2: {
            std::cout << "Insert an value" << std::endl;
            std::cin >> number;
            if (validacionunica(number) == 1) {
                truenumber = atoi(number);
                obj->Insert_Last(truenumber);
                std::cout << "Element insert correctly" << std::endl;
                system("pause");
            }
            else {
                std::cout << "Incorrect value" << std::endl;
                system("pause");
            }
        }break;

        case 3: {
            obj->Print();
            system("pause");
        }break;

        case 4: {
            std::cout << "Number of elements in the list: " << obj->Travel() << std::endl;
            system("pause");
        }break;

        case 5: {
            std::cout << "Insert the possition" << std::endl;
            std::cin >> number;
            if (validacionunica(number) == 1) {
                truenumber = atoi(number);
                obj->Search(truenumber);
                system("pause");
            }
            else {
                std::cout << "Incorrect value" << std::endl;
                system("pause");
            }
        }break;

        case 6: {
            std::cout << "Insert the possition" << std::endl;
            std::cin >> number;
            std::cout << "Insert the new value" << std::endl;
            std::cin >> number2;
            if (validacion(number, number2) == 1) {
                truenumber = atoi(number);
                truenumber2 = atoi(number2);
                obj->Modificar(truenumber, truenumber2);
                std::cout << "Element modify correctly" << std::endl;
                system("pause");
            }
            else {
                std::cout << "Incorrect value" << std::endl;
                system("pause");
            }
        }break;
        
        case 7: {
            std::cout << "Insert the possition" << std::endl;
            std::cin >> number;
            if (validacionunica(number) == 1) {
                truenumber = atoi(number);
                obj->Remove(truenumber);
                std::cout << "Element remove correctly" << std::endl;
                system("pause");
            }
            else {
                std::cout << "Incorrect value" << std::endl;
                system("pause");
            }
        }break;

        case 8: {
            std::cout << "Leaving..." << std::endl;
        }break;
        default: {
            cout << "Incorrect option" << endl;
            system("pause");
        }break;
        }

    } while (opcv != 8);

    delete obj;
    return 0;
}
