#ifndef QUEUE_H
# define QUEUE_H
#include <iostream>
#include <string>
template <class T, int ARRAYSIZE =1024>
class Queue {
private:
  T data[ARRAYSIZE];
  int frontPos;
  int EndPos;

  void copyAll(const Queue&);
public:
  class QueueException : public std::exception {
  private:
    std::string msg;

  public:
    explicit QueueException(const char* message) : msg(message) { }

    explicit QueueException(const std::string& message) : msg(message) { }

    virtual ~QueueException() throw () { }

    virtual const char* what() const throw (){
      return msg.c_str();
    }
  };

  Queue();
  Queue(const Queue&);

  bool isEmpty();
  bool isFull();

  void enqueue(const T&);

  T dequeue();

  T getFront();

  Queue& operator = (const Queue&);

};



//Implementacion

/*********************************************************************
* Comment
*********************************************************************/
template <class T,int ARRAYSIZE>
void Queue<T,ARRAYSIZE>::copyAll(const Queue&)
{
  ///Pendiente
}
/*********************************************************************
* Comment
*********************************************************************/
template <class T,int ARRAYSIZE>
Queue<T,ARRAYSIZE>::Queue() : frontPos(0), EndPos(ARRAYSIZE-1)
{
  //Empty
}
/*********************************************************************
* Comment
*********************************************************************/
template <class T,int ARRAYSIZE>
Queue<T,ARRAYSIZE>::Queue(const Queue& q)
{
  copyAll(q);
}
/*********************************************************************
* Comment
*********************************************************************/
template <class T,int ARRAYSIZE>
bool Queue<T,ARRAYSIZE>::isEmpty()
{
  return frontPos == EndPos+1 or(frontPos == 0 and EndPos == ARRAYSIZE - 1);
}
/*********************************************************************
* Comment
*********************************************************************/
template <class T,int ARRAYSIZE>
bool Queue<T,ARRAYSIZE>::isFull()
{
return frontPos == EndPos +2
or (frontPos == 0 and EndPos == ARRAYSIZE - 2)
or (frontPos == 1 and EndPos == ARRAYSIZE - 1);

}
/*********************************************************************
* Comment
*********************************************************************/
template <class T,int ARRAYSIZE>
void Queue<T,ARRAYSIZE>::enqueue(const T&e)
{
  if(isFull()){
    throw QueueException("Desbordamiento de datos, enqueue");
  }

  data[EndPos = ++EndPos == ARRAYSIZE ? 0 : EndPos] = e;
}
/*********************************************************************
* Comment
*********************************************************************/
template <class T,int ARRAYSIZE>
T Queue<T,ARRAYSIZE>::dequeue()
{
    if(isEmpty()){
      throw QueueException("Insuficiencia de datos, dequeue");
    }
    T result(data[frontPos]);
    frontPos++;
    if(frontPos == ARRAYSIZE){
      frontPos = 0;
    }
    return result;
}
/*********************************************************************
* Comment
*********************************************************************/
template <class T,int ARRAYSIZE>
T Queue<T,ARRAYSIZE>::getFront()
{
  if(isEmpty()){
    throw QueueException("Iinsuficiencia de datos, getFront");
  }

  return data[frontPos];
}
template <class T,int ARRAYSIZE>
Queue<T,ARRAYSIZE>&Queue<T,ARRAYSIZE>::operator = (const Queue& q)
{
  copyAll(q);
  return *this;
}



#endif
