#include <iostream>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include "Menu.h"
#include "Songs.h"

using namespace std;

#ifndef LIST_H
# define LIST_H

#include <iostream>

template <class T>
class List{
private:
  class Node{
    T data;
    Node* prev;
    Node* next;

  public:
    Node();
    Node(const T&);

    T getData() const;
    Node* getPrev() const;
    Node* getNext() const;

    void setData(const T&);
    void setPrev(Node*);
    void setNext(Node*);
  };

  Node* anchor;

  void copyAll(const List<T>&);

  bool isValidPos(Node*) const;

public:
  typedef Node* Position;
  class Exception : public std::exception{
      private:
          std::string msg;

      public:
          explicit Exception(const char* message) : msg(message) {}
          explicit Exception(const std::string&message) : msg(message) {}
          virtual ~Exception() throw () {}
          virtual const char* what() const throw () {
              return msg.c_str();
              }
    };

    List();
    List(const List<T>&);

    ~List();

    bool isEmpty()const;

    void InsertData(Node*,const T&);

    void deleteData(Node*);


    Node* getFirstPos()const;
    Node* getLastPos()const;
    Node* getPrevPos(Node*)const;
    Node* getNextPos(Node*)const;

    Node* findData(const T&)const;

    T retrieve(Node*)const;

    std::string ToString()const;
    std::string ToStringReverse()const;
    std::string ToStringAll()const;

    void deleteAll();

    List<T>& operator = (const List<T>&);


};


template <class T>
List<T>::Node::Node() : prev(nullptr),next(nullptr){}

template <class T>
List<T>::Node::Node(const T& e) : data(e),prev(nullptr),next(nullptr) {}

template <class T>
T List<T>::Node::getData()const{
  return data;
}

template <class T>
typename List<T>::Node* List<T>::Node::getPrev()const{
  return prev;
}

template <class T>
typename List<T>::Node* List<T>::Node::getNext()const{
  return next;
}

template <class T>
void List<T>::Node::setData(const T& e){
  data=e;
}

template <class T>
void List<T>::Node::setPrev(Node* p){
  prev = p;
}

template <class T>
void List<T>::Node::setNext(Node* p){
  next = p;
}

template <class T>
void List<T>::copyAll(const List<T>& l){
  if(l.isEmpty()){
    return;
  }

  Node* aux(l.anchor);
  Node* last(nullptr);
  Node* newNode;

  do{
    if((newNode = new Node(aux->getData()))=nullptr){
      throw Exception("Memory not available");
    }

    if(last == nullptr){
      anchor = newNode;
    }
    else{
      newNode->setPrev(last);
      last->setNext(newNode);
    }
    last = newNode;

    aux = aux->getNext();
  }while(aux!=l.anchor);

  anchor->setPrev(last);

  last->setNext(anchor);
}

template <class T>
bool List<T>::isValidPos(Node* p) const{
  if(!isEmpty()){
    Node* aux(anchor);

    do{
      if(aux == p){
        return true;
      }

      aux = aux->getNext();
    }while(aux!=anchor);
  }
  return false;
}

template <class T>
List<T>::List() : anchor(nullptr){}

template <class T>
List<T>::List(const List<T>& l) : anchor(nullptr){
  copyAll();
}

template <class T>
List<T>::~List(){
  deleteAll();
}

template <class T>
bool List<T>::isEmpty() const{
  return anchor == nullptr;
}

template <class T>
void List<T>::InsertData(Node* p, const T& e){
  if(p != nullptr and !isValidPos(p)){
    throw Exception("Invalid Position, InsertData");
  }
  Node* aux(new Node(e));

  if(aux == nullptr){
    throw Exception("Memory no available");
  }
  if(p==nullptr){
    if(anchor == nullptr){
      aux->setPrev(aux);
      aux->setNext(aux);
    }
    else{
      aux->setPrev(anchor->getPrev());
      aux->setNext(anchor);

      anchor->getPrev()->setNext(aux);
      anchor->setPrev(aux);
    }

    anchor = aux;
  }
  else{
    aux->setPrev(p);
    aux->setNext(p->getNext());

    p->getNext()->setPrev(aux);
    p->setNext(aux);
  }
}

template <class T>
void List<T>::deleteData(Node* p){
  if(!isValidPos(p)){
    throw Exception("Invalid Position, deleteData");
  }

  p->getPrev()->setNext(p->getNext());

  p->getNext()->setPrev(p->getPrev());

  if(p==anchor){
    if(p->getNext()== p){
      anchor = nullptr;
    }
    else{
      anchor = anchor->getNext();
    }
  }
  delete p;
}

template <class T>
typename List<T>::Node* List<T>::getFirstPos()const{
  return anchor;
}

template <class T>
typename List<T>::Node* List<T>::getLastPos()const{
  if(isEmpty()){
    return nullptr;
  }
  return anchor->getPrev();
}

template <class T>
typename List<T>::Node* List<T>::getPrevPos(Node* p)const{
  if(p == anchor or !isValidPos(p)){
    return nullptr;
  }

  return p->getPrev();
}

template <class T>
typename List<T>::Node* List<T>::getNextPos(Node* p)const{
  if(!isValidPos(p) or p==anchor->getPrev()){
    return nullptr;
  }

  return p->getNext();
}

template <class T>
typename List<T>::Node* List<T>::findData(const T& e)const{
  if(!isEmpty()){
    Node* aux(anchor);

    do{
      if(aux->getData()==e){
        return aux;
      }

      aux = aux->getNext();
    }while(aux != anchor);
  }
  return nullptr;
}

template <class T>
T List<T>::retrieve(Node* p)const{
  if(!isValidPos(p)){
    throw Exception("Invalid Position, retrieve");
  }

  return p->getData();
}

template <class T>
std::string List<T>::ToString()const{
  std::string result;

  if(!isEmpty()){
    Node* aux(anchor);

    do{
      result += aux->getData().ToStringNameSong() + "\n";

      aux = aux->getNext();
    }while(aux!=anchor);
  }
  return result;
}


template <class T>
std::string List<T>::ToStringReverse()const{
  std::string result;

    Node* aux=getLastPos();

    while(aux != nullptr){
      result += aux->getData().ToStringNameSong() + "\n";
      aux = getPrevPos(findData(retrieve(aux)));
    }
  return result;
}

template <class T>
std::string List<T>::ToStringAll()const{
  std::string result;

  if(!isEmpty()){
    Node* aux(anchor);

    do{
      result += aux->getData().ToStringAll() + "\n";

      aux = aux->getNext();
    }while(aux!=anchor);
  }
  return result;
}



template <class T>
void List<T>::deleteAll(){
  if(isEmpty()){
    return;
  }

  Node* mark(anchor);
  Node* aux;

  do{
    aux = anchor;

    anchor = anchor->getNext();

    delete aux;
  }while(anchor != mark);

  anchor = nullptr;
}

template <class T>
List<T>& List<T>::operator = (const List<T>& l){
  deleteAll();

  copyAll(l);

  return *this;
}

#endif


void gotoxy(int x ,int y){
  HANDLE hcon;
  hcon=GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y = y;
  SetConsoleCursorPosition(hcon,dwPos);
}


Menu mymenu;
List<Songs> mylist;
Songs mysongs;
List<Songs>::Position pos;
List<Songs>::Position aux;
List<Songs>::Position aux2;
int cont=0,len;


void PrintPlayer(){
  system("cls");
  printf("\t\t\t\t\t\t\t");
  printf("     %c",201);
  for(int x=0;x<15;x++){
    printf("%c",205);
  }
  printf("%c",187);
  printf("\n\t\t\t\t\t\t\t     %c Listening:    %c\n",186,186);
  printf("\t\t\t\t\t\t\t");
  printf("     %c",200);
  for(int x=0;x<15;x++){
    printf("%c",205);
  }
  printf("%c",188);
  cout<<endl;


  printf("\t\t\t\t\t\t");
  printf("%c",201);
  for(int x=0;x<50;x++){
    printf("%c",205);
  }
  printf("%c",187);
  cout<<endl;
  try{
    printf("\t\t\t\t\t\t%c",186);cout<<" Name: "<<mylist.retrieve(pos).GetNameSong()<<endl;
  }catch(List<Songs>::Exception ex){
    printf("  ------/NA------\n");
  }
  gotoxy(99,4);printf("%c\n",186);
  printf("\t\t\t\t\t\t");
  printf("%c",200);
  for(int x=0;x<50;x++){
    printf("%c",205);
  }
  printf("%c",188);
  cout<<endl;




  printf("\t\t\t\t\t\t");
  printf("%c",201);
  for(int x=0;x<30;x++){
    printf("%c",205);
  }
  printf("%c",187);
  cout<<endl;
  try{
    printf("\t\t\t\t\t\t%c",186);cout<<" Author: "<<mylist.retrieve(pos).GetAuthor()<<endl;
  }catch(List<Songs>::Exception ex){
    printf("  ------/NA------\n");
  }
  gotoxy(79,7);printf("%c\n",186);
  printf("\t\t\t\t\t\t");
  printf("%c",200);
  for(int x=0;x<30;x++){
    printf("%c",205);
  }
  printf("%c",188);
  cout<<endl;



  gotoxy(80,6);printf("%c",201);
  for(int x=0;x<18;x++){
    printf("%c",205);
  }
  printf("%c",187);
  gotoxy(80,7);
  try{
    printf("%c",186);cout<<" ID: "<<mylist.retrieve(pos).GetID()<<endl;
  }catch(List<Songs>::Exception ex){
    printf(" ---/NA---\n");
  }
  gotoxy(99,7);printf("%c\n",186);
  gotoxy(80,8);printf("%c",200);
  for(int x=0;x<18;x++){
    printf("%c",205);
  }
  printf("%c\n",188);




  printf("\t\t\t\t\t\t");
  printf("%c",201);
  for(int x=0;x<25;x++){
    printf("%c",205);
  }
  printf("%c\n",187);
  try{
    printf("\t\t\t\t\t\t%c",186);cout<<" Album: "<<mylist.retrieve(pos).GetAlbum()<<endl;
  }catch(List<Songs>::Exception ex){
    printf("  ---/NA---\n");
  }
  gotoxy(74,10);printf("%c\n",186);
  printf("\t\t\t\t\t\t");
  printf("%c",200);
  for(int x=0;x<25;x++){
    printf("%c",205);
  }
  printf("%c",188);



  gotoxy(75,9);printf("%c",201);
  for(int x=0;x<23;x++){
    printf("%c",205);
  }
  printf("%c",187);
  gotoxy(75,10);
  try{
    printf("%c",186);cout<<" Gender: "<<mylist.retrieve(pos).GetType()<<endl;
  }catch(List<Songs>::Exception ex){
    printf(" ---/NA---\n");
  }
  gotoxy(99,10);printf("%c",186);
  gotoxy(75,11);printf("%c",200);
  for(int x=0;x<23;x++){
    printf("%c",205);
  }
  printf("%c",188);



  gotoxy(50,15);
  for(int x=0;x<50;x++){
    printf("%c",177);
  }
}

int main(){
  int opcv;
  string myStr;
  do{
    if(cont == 1){
      pos = mylist.getFirstPos();
      }
    PrintPlayer();
    cout<<"\n\n\n\n";
    gotoxy(0,0);
    mymenu.GetMenu();
    opcv = atoi(mymenu.GetOption());
    switch(opcv){
      case 1:{
        fflush(stdin);
        cout<<"Name song: ";
        getline(cin,myStr);
        mysongs.SetNamesong(myStr);
        cout<<"Author song: ";
        getline(cin,myStr);
        mysongs.SetAuthor(myStr);
        cout<<"Album song: ";
        getline(cin,myStr);
        mysongs.SetAlbum(myStr);
        cout<<"ID song: ";
        getline(cin,myStr);
        mysongs.SetID(myStr);
        cout<<"Gender: ";
        getline(cin,myStr);
        mysongs.SetType(myStr);

        mylist.InsertData(mylist.getLastPos(),mysongs);
        cout<<"Song added!"<<endl;
        cont++;
        system("pause");
      }break;
      case 2:{
        pos = mylist.getNextPos(pos);
        }break;
      case 3:{
        pos = mylist.getPrevPos(pos);
      }break;
      case 4:{
        cout<<mylist.ToString()<<endl;
        system("pause");
      }break;
      case 5:{
        cout<<mylist.ToStringReverse();
        system("pause");
      }break;
      case 6:{
        fflush(stdin);
        cout<<"Song name to edit: ";
        getline(cin,myStr);
        mysongs.SetNamesong(myStr);
        cout<<"Song Author to edit: ";
        getline(cin,myStr);
        mysongs.SetAuthor(myStr);
        cout<<"Song Album to edit: ";
        getline(cin,myStr);
        mysongs.SetAlbum(myStr);
        cout<<"Song ID to edit: ";
        getline(cin,myStr);
        mysongs.SetID(myStr);
        cout<<"Gender to edit: ";
        getline(cin,myStr);
        mysongs.SetType(myStr);

        aux = mylist.findData(mysongs);
        aux2 = mylist.getPrevPos(mylist.findData(mysongs));
        mylist.deleteData(aux);
        system("cls");
        PrintPlayer();
        gotoxy(0,0);
        fflush(stdin);
        cout<<"New Name song: ";
        getline(cin,myStr);
        mysongs.SetNamesong(myStr);
        cout<<"New Author song: ";
        getline(cin,myStr);
        mysongs.SetAuthor(myStr);
        cout<<"New Album song: ";
        getline(cin,myStr);
        mysongs.SetAlbum(myStr);
        cout<<"New ID song: ";
        getline(cin,myStr);
        mysongs.SetID(myStr);
        cout<<"New Gender: ";
        getline(cin,myStr);
        mysongs.SetType(myStr);
        mylist.InsertData(aux2,mysongs);
      }break;
      case 7:{
        mylist.deleteData(mylist.getFirstPos());
      }break;
      case 8:{
        mylist.deleteData(mylist.getLastPos());
      }break;
      case 9:{
        gotoxy(70,14);printf("time: 2:20");
        gotoxy(50,15);
        for(int x=0;x<50;x++){
          Sleep(100);
          printf("%c",219);
        }
      }break;
      case 10:{
        cout<<"Leaving..."<<endl;
      }break;
    }
}while(opcv!=10);
  return 0;
}
