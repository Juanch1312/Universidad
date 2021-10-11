#include "List.h"

Songs mylista;
/*********************************************************************
* Comment
*********************************************************************/
bool List::isValidPos(const int& p)
{
  return  p>=0 && p<=last;
}
/*********************************************************************
* Comment
*********************************************************************/
void List::initialize()
{
  last =-1;
}
/*********************************************************************
* Comment
*********************************************************************/
bool List::isEmpty()
{
  return last==-1;
}
/*********************************************************************
* Comment
*********************************************************************/
bool List::isFull()
{
  return last==49;
}
/*********************************************************************
* Comment
*********************************************************************/
void List::insertData(const int& p,const char* Name,const char* Aut,const char* Int,const int& ran)
{
  if(isFull()){
    throw ListException("Desbordamiento de datos, insertData");
  }
  if(p!=-1 && !isValidPos(p)){
    throw ListException("Posicion Invalida, insertData");
  }
  int i(last);
  while(i>p){
    ranking[i+1]=ranking[i];
    i--;
  }
  ranking[p].SetNamesong(Name);
  ranking[p].SetAuthor(Aut);
  ranking[p].SetInterprete(Int);
  ranking[p].SetRankingPos(ran);

  last++;
}
/*********************************************************************
* Comment
*********************************************************************/
void List::deleteData(const int&p)
{
  if(!isValidPos(p)){
    throw ListException("Posicion Invalida, deleteData");
  }
  int i(p);
  while(i<last){
    ranking[i]=ranking[i+1];
    i++;
  }
  last--;
}
/*********************************************************************
* Comment
*********************************************************************/
int List::getFirstPos()
{
  if(isEmpty()){
    return -1;
  }
  return 0;
}
/*********************************************************************
* Comment
*********************************************************************/
int List::getlastPos()
{
  return last;
}
/*********************************************************************
* Comment
*********************************************************************/
int List::getPrevPos(const int&p)
{
  if(p==0 || !isValidPos(p)){
    return -1;
  }
  return p-1;
}
/*********************************************************************
* Comment
*********************************************************************/
int List::getNextPos(const int&p)
{
  if(p==last || !isValidPos(p)){
    return -1;
  }
  return p+1;
}
/*********************************************************************
* Comment
*********************************************************************/
int List::retrieve(const int&p)
{
  if(!isValidPos(p)){
    throw ListException("Posicion Invalida, retrieve");
  }
  return p;
}
/*********************************************************************
* Comment
*********************************************************************/
void List::print()
{
  int i=0;
  while(i<=last){
    cout<<"Posicion:\t\t    "<<i+1<<endl;
    cout<<"Song Name:\t\t ";
    cout<<ranking[i].GetNameSong()<<endl;
    cout<<"Author:\t\t\t ";
    cout<<ranking[i].GetAuthor()<<endl;
    cout<<"Interpreter:\t\t ";
    cout<<ranking[i].GetInterprete()<<endl;
    cout<<"Ranking Posicion:\t ";
    cout<<ranking[i].GetRankingPos()<<endl;
    cout<<endl<<endl;
    i++;
  }
}
/*********************************************************************
* Comment
*********************************************************************/
void List::deleteAll()
{
  last=-1;
}
