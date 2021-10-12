#ifndef QUEUE_H
# define QUEUE_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

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

template <class P>
class Queue{
  class Nodo{
  private:
    P data;
    Nodo *sig;
  public:
    Nodo();
    Nodo(const P&);
    Nodo* getNext()const;
    P getInf()const;

    void SetData(const P&);
    void setNext(Nodo*);
  };
  Nodo* Base;
  Nodo* Fondo;

public:
  Queue();
  ~Queue();
  P dequeuque();
  void enqueue(const P& data);
  string toString() const;
  string toStringU(Nodo* aux) const;
  bool isEmpty() const;

  string getFirstPos() const;
  string getLastPos() const;

  string findData(const P&) const;

};
template <class P>
Queue<P>::Queue() : Base (nullptr), Fondo(nullptr){}

template <class P>
Queue<P>::~Queue()
{
    Nodo* reco= Base;
    Nodo* Del;
    while(reco!=NULL)
    {
        Del =reco;
        reco = reco->getNext();
        delete Del;
    }

}

template <class P>
P Queue<P>::dequeuque()
{
  if(!isEmpty())
  {
      P informacion = Base->getInf();
      Nodo* bor =Base;


      if(Base==Fondo)
      {
          Base= nullptr;
          Fondo= nullptr;
      }
      else
      {
          Base = Base->getNext();
      }
      delete bor;
      return informacion;
  }
  else{
    throw Exception("Queue is empty, Enqueue");
  }
}

template <class P>
void Queue<P>::enqueue(const P& data)
{
  Nodo *nuevo;
  nuevo= new Nodo();

  nuevo->SetData(data);
  nuevo->getNext();

  if(isEmpty())
  {
          Base=nuevo;
          Fondo=nuevo;
  }
  else
  {
      Fondo->setNext(nuevo);
      Fondo= nuevo;
  }
}

template <class P>
string Queue<P>::toString() const
{
    Nodo *reco(Base);
    string result;

    while (reco != nullptr)
    {
        result+= reco->getInf().toString() + "\n" ;
        reco = reco->getNext();
    }
    return result;
}

template <class P>
bool Queue<P>::isEmpty()const
{
    return Base == nullptr;
}


template <class P>
Queue<P>::Nodo::Nodo() : sig(nullptr){}

template <class P>
Queue<P>::Nodo::Nodo(const P& e) : data(e),sig(nullptr){}

template <class P>
typename Queue<P>::Nodo* Queue<P>::Nodo::getNext() const
{
    return sig;
}

template <class P>
P Queue<P>::Nodo::getInf() const
{
    return data;
}

template <class P>
void Queue<P>::Nodo::SetData(const P& pos)
{
    data =pos;
}

template <class P>
void Queue<P>::Nodo::setNext(Nodo* next)
{
    sig = next;
}


template <class P>
string Queue<P>::getFirstPos() const{
  string resp="The Schedule Is Empty";
  if(isEmpty()){
    return resp;
  }
    return toStringU(Base);
}

template <class P>
string Queue<P>::getLastPos() const{
    string resp="The Schedule Is Empty";
    if(isEmpty()){
      return resp;
  }

    Nodo* aux(Fondo);

    while(aux->getNext() != nullptr){
        aux = aux->getNext();
    }

    return toStringU(aux);
}



template <class P>
string Queue<P>::toStringU(Nodo* aux) const
{
    Nodo *reco(aux);
    string result;
    result+= reco->getInf().toString() + "\n" ;
    return result;
}



template <class P>
string Queue<P>::findData(const P& e)const{
    Nodo* aux(Base);

    while(aux != nullptr and aux->getInf() != e){
        aux = aux->getNext();
    }

    return toStringU(aux);
}



#endif
