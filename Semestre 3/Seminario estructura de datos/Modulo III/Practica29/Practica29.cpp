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
  int cont=0;
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
  int findData(int);
  void DelLast();
  void printreverse();
  void DeleteFirst();
  void DeleteSecond();
  void DeleteLast();
  void DeleteMayor();

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
    cont++;
  }
  else{
    while(ptrList->ptrNext && ptrList->ptrNext->value <= v)ptrnext();
    ptrNew = new Node<TIPO>(v,ptrList->ptrNext,ptrList);
    ptrList->ptrNext = ptrNew;
    if(ptrNew -> ptrNext) ptrNew->ptrPrev->ptrPrev = ptrNew;
    cont++;
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

template<class TIPO>
int List<TIPO>::findData(int val){
  if(!Empty()){
    Node<TIPO> *ptrNode;
    int cont=0;
    bool band=true;
    First();
    ptrNode = ptrList;

    do{
      cont++;
      if(ptrNode->value == val){
        band = false;
        return cont;
      }
      else{
        ptrNode = ptrNode -> ptrNext;
      }
    }while(band == true && ptrNode->ptrNext != NULL);
  }
  return -1;
}

template<class TIPO>
void List<TIPO>::DelLast(){
  Node<TIPO> *ptrNode;
  Last();
  ptrNode = ptrList;
  ptrList = ptrList->ptrPrev;
  ptrList->ptrNext = NULL;
  delete ptrNode;
}

template<class TIPO>
void List<TIPO>::printreverse(){
  Node<TIPO> *ptrNode;
  Last();
  ptrNode = ptrList;
  while(ptrNode){
    cout<<ptrNode->value<<"->";
    ptrNode = ptrNode->ptrPrev;
  }
  cout<<endl;
}

template<class TIPO>
void List<TIPO>::DeleteFirst(){
  Node<TIPO> *ptrNode;
  First();
  ptrNode = ptrList;
  ptrList=ptrList->ptrNext;
  ptrList->ptrPrev = NULL;

  delete ptrNode;
}

template<class TIPO>
void List<TIPO>::DeleteSecond(){
  Node<TIPO> *ptrNode;
  Node<TIPO> *ptrNode2;
  First();
  ptrNode = ptrList->ptrNext;
  ptrNode2 = ptrNode->ptrNext;
  ptrNode2->ptrPrev = ptrList;
  ptrList->ptrNext = ptrNode2;

  delete ptrNode;

}

template<class TIPO>
void List<TIPO>::DeleteLast(){
  Node<TIPO> *ptrNode;
  Last();
  ptrNode = ptrList;
  ptrList=ptrList->ptrPrev;
  ptrList->ptrNext = NULL;

  delete ptrNode;
}

template<class TIPO>
void List<TIPO>::DeleteMayor(){
  First();
  Node<TIPO> *aux=ptrList;
    Node<TIPO> *newNode=NULL;

    while (aux!=nullptr)
        {
        if(aux > newNode)
            {
            newNode= aux;

            }
        aux=aux->ptrNext;
        }

    if(newNode->ptrPrev != nullptr)
        {
        newNode->ptrPrev->ptrNext = newNode->ptrNext;
        }
    if(newNode->ptrNext != nullptr)
        {
        newNode->ptrNext->ptrPrev = newNode->ptrPrev;
        }
    if(newNode==ptrList)
        {
        ptrList=ptrList->ptrNext;
        }
    delete newNode;
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


int main(){
  List<int> list;
  int opcv,value2;
  char value[100];
  do{
    system("cls");
    char opc[1000];
    cout<<"___________________________________"<<endl;
    cout<<"|\t1)Insert\t\t  |"<<endl;
    cout<<"___________________________________"<<endl;
    cout<<"|\t2)Delete\t          |"<<endl;
    cout<<"___________________________________"<<endl;
    cout<<"|\t3)Delete Last\t          |"<<endl;
    cout<<"___________________________________"<<endl;
    cout<<"|\t4)Find Data\t          |"<<endl;
    cout<<"___________________________________"<<endl;
    cout<<"|\t5)First\t\t          |"<<endl;
    cout<<"___________________________________"<<endl;
    cout<<"|\t6)Last\t\t          |"<<endl;
    cout<<"___________________________________"<<endl;
    cout<<"|\t7)Invert\t          |"<<endl;
    cout<<"___________________________________"<<endl;
    cout<<"|\t8)Delete First\t          |"<<endl;
    cout<<"___________________________________"<<endl;
    cout<<"|\t9)Delete Second\t          |"<<endl;
    cout<<"___________________________________"<<endl;
    cout<<"|\t10)Delete Mayor\t          |"<<endl;
    cout<<"___________________________________"<<endl;
    cout<<"|\t11)Exit\t\t\t  |"<<endl;
    cout<<"___________________________________"<<endl;
    cin>>opc;
    opcv = atoi(opc);
    switch(opcv){
      case 1:{
        cout<<"Insert the value"<<endl;
        cin>>value;
        if(validacionunica(value)==1){
          value2 = atoi(value);
          list.Add(value2);
          cout<<endl<<endl;
          list.print();
          system("pause");
        }
        else{
          cout<<endl<<endl;
          cout<<"Invalid value"<<endl;
          system("pause");
        }
      }break;
      case 2:{
        cout<<"Insert the value"<<endl;
        cin>>value;
        if(validacionunica(value)==1){
          value2 = atoi(value);
          list.remove(value2);
          cout<<endl<<endl;
          list.print();
          system("pause");
        }
        else{
          cout<<endl<<endl;
          cout<<"Invalid value"<<endl;
          system("pause");
        }
      }break;
      case 3:{
        list.DelLast();
        list.print();
        system("pause");
      }break;
      case 4:{
        int pos;
        cout<<"Insert the value"<<endl;
        cin>>value;
        if(validacionunica(value)==1){
          value2 = atoi(value);
          pos = list.findData(value2);
          if(pos != -1){
            cout<<"Data found, position: "<<pos<<endl;
            list.print();
            system("pause");
          }
          else{
            cout<<"Data not found"<<endl;
            system("pause");
          }
        }
        else{
          cout<<endl<<endl;
          cout<<"Invalid value"<<endl;
          system("pause");
        }
      }break;
      case 5:{
        list.First();
        cout<<"First Node: "<<list.CurrentValue()<<endl;
        system("pause");
      }break;
      case 6:{
        list.Last();
        cout<<"Last Node: "<<list.CurrentValue()<<endl;
        system("pause");
      }break;
      case 7:{
        list.printreverse();
        system("pause");
      }break;
      case 8:{
        list.DeleteFirst();
        list.print();
        system("pause");
      }break;
      case 9:{
        list.DeleteSecond();
        list.print();
        system("pause");
      }break;
      case 10:{
        list.DeleteMayor();
        list.print();
        system("pause");
      }break;
      case 11:{
        cout<<"Leaving..."<<endl;
      }break;
      default:{
        cout<<"Invalid Option"<<endl;
        system("pause");
      }break;
    }
}while(opcv!=11);
  return 0;
}
