#ifndef NODE_H
# define NODE_H

template <class T>
class Node{
private:
  T data;
  Node* next;

public:
  Node();
  Node(const T&);

  T getData()const;
  Node* getNext()const;

  void setData(const T&);
  void setNext(Node*);
};

template <class T>
Node<T>::Node::Node() : next(nullptr){}

template <class T>
Node<T>::Node::Node(const T& e) : data(e),next(nullptr) {}

template <class T>
T Node<T>::Node::getData()const{
  return data;
}

template <class T>
typename Node<T>::Node* Node<T>::Node::getNext()const{
  return next;
}

template <class T>
void Node<T>::Node::setData(const T& e){
  data=e;
}

template <class T>
void Node<T>::Node::setNext(Node* p){
  next = p;
}
#endif
