#include <iostream>
using namespace std;

template<class TIPO>class List;

template<class TIPO>
class Node{
public:
  Node(TIPO v,Node<TIPO> *pnext = NULL, Node<TIPO> *pprev = NULL):
  value(v),ptrNext(pnext),ptrPrev(pprev){};

private:
  TIPO value;
  Node<TIPO> *ptrNext;
  Node<TIPO> *ptrPrev;

  friend class List<TIPO>;
};

template<class TIPO>
class List{
public:
  List() : ptrList(NULL) {}
  ~List();

  void Add(TIPO v);
  void remove(TIPO v);
  bool Empty(){return ptrList == NULL;}
  void print();
  void ptrnext();
  void ptrprev();
  void First();
  void Last();
  bool Current(){return ptrList != NULL;}
  TIPO CurrentValue(){return ptrList->value;}

private:
  Node<TIPO> *ptrList;
};

template<class TIPO>
List<TIPO>::~List(){
  Node<TIPO> *aux;

  First();
  while(ptrList){
    aux = ptrList = ptrList->ptrNext;
    delete aux;
  }
}

template <class TIPO>
void List<TIPO>::Add(TIPO v){
  Node<TIPO> *ptrNew;

  First();

  if(Empty() || ptrList->value > v){
    ptrNew = new Node<TIPO>(v,ptrList);
    if(!ptrList) ptrList = ptrNew;
    else ptrList->ptrPrev = ptrNew;
  }
  else{
    while(ptrList->ptrNext && ptrList->ptrNext->value <= v)ptrnext();
    ptrNew = new Node<TIPO>(v,ptrList->ptrNext,ptrList);
    ptrList->ptrNext = ptrNew;
    if(ptrNew -> ptrNext) ptrNew->ptrPrev->ptrPrev = ptrNew;
  }
}

template <class TIPO>
void List<TIPO>::remove(TIPO v){
  Node<TIPO> *ptrNode;

  ptrNode = ptrList;
  while(ptrNode && ptrNode->value < v) ptrNode = ptrNode->ptrNext;
  while(ptrNode && ptrNode->value > v) ptrNode = ptrNode->ptrPrev;

  if(!ptrNode || ptrNode->value != v){
     return;
   }

  if(ptrNode->ptrPrev){
    ptrNode->ptrPrev->ptrNext = ptrNode->ptrNext;

  }
  if(ptrNode->ptrNext){
    ptrNode->ptrNext->ptrPrev = ptrNode ->ptrPrev;
    delete ptrNode;
  }
}

template<class TIPO>
void List<TIPO>::print(){
  Node<TIPO> *ptrNode;
  First();

  ptrNode = ptrList;
  while(ptrNode){
    cout<<ptrNode->value<<"->";
    ptrNode = ptrNode->ptrNext;
  }
  cout<<endl;
}

template<class TIPO>
void List<TIPO>::ptrnext(){
  if(ptrList){
    ptrList = ptrList->ptrNext;
  }
}

template<class TIPO>
void List<TIPO>::ptrprev(){
  if(ptrList){
    ptrList = ptrList->ptrPrev;
  }
}

template<class TIPO>
void List<TIPO>::First(){
  while(ptrList && ptrList->ptrPrev){
    ptrList = ptrList->ptrPrev;
  }
}

template<class TIPO>
void List<TIPO>::Last(){
  while(ptrList && ptrList->ptrNext){
    ptrList = ptrList->ptrNext;
  }
}

int main(){
  List<int> list;
  list.Add(20);
  list.Add(30);
  list.Add(10);
  list.Add(40);
  list.print();
  list.First();
  cout<<"First Node: "<<list.CurrentValue()<<endl;

  list.Last();
  cout<<"Last Node: "<<list.CurrentValue()<<endl;
  cout<<endl<<endl;
  system("pause");
  cout<<endl<<endl;
  cout<<"Insert new nodes: 80, 85"<<endl;

  list.Add(80);
  list.Add(85);

  list.print();
  list.First();
  cout<<"First Node: "<<list.CurrentValue()<<endl;

  list.Last();
  cout<<"Last Node: "<<list.CurrentValue()<<endl;
  cout<<endl<<endl;
  system("pause");
  cout<<endl<<endl;
  cout<<"Remove Node: 40"<<endl;

  list.remove(40);
  list.print();

  return 0;
}
