#ifndef LIST_H
# define LIST_H

#include <exception>
#include <string>
#include "node.h"


template <class T>
class List{
private:
  Node<T>* anchor;

  void CopyAll(const List<T>&);

  bool isValidPos(Node<T>*) const;

public:
  typedef Node<T>* Position;
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

  void InsertData(Node<T>*,const T&);

  void deleteData(Node<T>*);

  Node<T>* getFirstPos()const;
  Node<T>* getLastPos()const;
  Node<T>* getPrevPos(Node<T>*)const;
  Node<T>* getNextPos(Node<T>*)const;

  Node<T>* findData(const T&)const;

  T retrieve(Node<T>*)const;

  std::string ToString()const;

  void deleteAll();

  List<T>& operator = (const List<T>&);
};

///Lista
template <class T>
void List<T>::CopyAll(const List<T>& l){
  Node<T>* aux(l.anchor);
  Node<T>* last(nullptr);
  Node<T>* newNode;

  while(aux != nullptr){
    //InsertData(getLastPos(), aux->getData()); ///Marranada

    newNode = new Node<T>(aux->getData());
    if(newNode == nullptr){
      throw Exception("No memory available, CopyAll");
    }
      if(last = nullptr){
        anchor = newNode;
      }
      else{
        last->setNext(newNode);
      }

      last = newNode;

      aux = aux->getNext();
  }
}

template <class T>
bool List<T>::isValidPos(Node<T>* p)const{
  Node<T>* aux(anchor);

  while(aux != nullptr){
    if(aux == p){
      return true;
    }
    aux = aux->getNext();
  }
  return false;
}

template <class T>
List<T>::List() : anchor(nullptr){}

template <class T>
List<T>::List(const List<T>& l): anchor(nullptr){
  CopyAll(l);
}

template <class T>
List<T>::~List(){
  deleteAll();
}


template <class T>
bool List<T>::isEmpty()const{
  return anchor == nullptr;
}

template <class T>
void List<T>::InsertData(Node<T>* p, const T& e){
  if(p != nullptr and !isValidPos(p)){
    throw Exception("Invalid Position, InsertData");
  }
  Node<T>* aux(new Node<T>(e));

  if(aux== nullptr){
    throw Exception("No memory available, InsertData");
  }

  if(p == nullptr){
    aux->setNext(anchor);
    anchor = aux;
  }
  else{
    aux->setNext(p->getNext());
    p->setNext(aux);
  }
}


template <class T>
void List<T>::deleteData(Node<T>* p){
  if(!isValidPos(p)){
    throw Exception("Invalid Position, deleteData");
  }
  if(p==anchor){ ///Elimina El primero
    anchor = anchor->getNext();
  }
  else{ ///Eliminar cualesquiera
    getPrevPos(p)->setNext(p->getNext());
  }
  delete p;
}

template <class T>
Node<T>* List<T>::getFirstPos()const{
  return anchor;
}

template <class T>
Node<T>* List<T>::getLastPos()const{
  if(isEmpty()){
    return nullptr;
  }

  Node<T>* aux(anchor);

  while(aux->getNext()!=nullptr){
    aux=aux->getNext();
  }

  return aux;
}

template <class T>
Node<T>* List<T>::getPrevPos(Node<T>* p)const{
  if(p== anchor){
    return nullptr;
  }

  Node<T>* aux(anchor);

  while(aux!= nullptr && aux->getNext() != p){
    aux = aux->getNext();
  }

  return aux;
}

template <class T>
Node<T>* List<T>::getNextPos(Node<T>* p)const{
  if(!isValidPos(p)){
    return nullptr;
  }
  return p->getNext();
}


template <class T>
Node<T>* List<T>::findData(const T& e)const{
  Node<T>* aux(anchor);

  while(aux != nullptr and aux->getData() != e){
    aux = aux->getNext();
  }

  return aux;
}

template <class T>
T List<T>::retrieve(Node<T>* p)const{
  if(!isValidPos(p)){
    throw Exception("Invalid Position, retrieve");
  }

  return p->getData();
}

template <class T>
std::string List<T>::ToString()const{
  Node<T>* aux(anchor);
  std::string result;

  while(aux != nullptr){
    result +=aux->getData().ToString()+"\n";

    aux = aux->getNext();
  }

  return result;
}

template <class T>
void List<T>::deleteAll(){
  Node<T>* aux;

  while(anchor != nullptr){
    aux = anchor;
    anchor = anchor->getNext();

    delete aux;
  }
}

template <class T>
List<T>& List<T>::operator = (const List<T>& l){

  deleteAll();

  CopyAll(l);

  return *this;
}

#endif
