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
      result += aux->getData().ToString() + "\n";

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
