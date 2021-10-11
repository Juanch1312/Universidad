#include "Collectproducts.h"
using namespace std;
/*********************************************************************
* Comment
*********************************************************************/
void Collectproducts::Initial()
{
  last=0;
}
/*********************************************************************
* Comment
*********************************************************************/
int Collectproducts::getLast()
{
  return last;
}
/*********************************************************************
* Comment
*********************************************************************/
void Collectproducts::Update(const char* c,const char* n,const float& w, const int& d,const int& m,const int& y,const float& p,const float& mp,const int&e)
{
  collection[last].setBarcode(c);
  collection[last].setName(n);
  collection[last].setWeight(w);
  collection[last].setDate(d,m,y);
  collection[last].setPrice(p);
  collection[last].setMPrice(mp);
  collection[last].setExistence(e);
  last++;
}
/*********************************************************************
* Comment
*********************************************************************/
void Collectproducts::Sell(const int& ActEx, const int& pos)
{
  collection[pos].setExistence(ActEx);
}
/*********************************************************************
* Comment
*********************************************************************/
int Collectproducts::ValideExistence(const char*c)
{
  char BarCode[13];
  bool valide=true;
  for(int i=0;i<last;i++){
    strcpy(BarCode,collection[i].getBarcode());
    for(int j=0;j<13;j++){
      if(BarCode[j]!=c[j]){
        valide = false;
      }
    }
    if (valide == true){
      return i;
    }
  }
  return -1;
}
/*********************************************************************
* Comment
*********************************************************************/
void Collectproducts::ShowTheCollection()
{
  Fecha date2;
  char barcode[13];
  char name[60];
  for(int i=0;i<last;i++){
    strcpy(barcode,collection[i].getBarcode());
    strcpy(name,collection[i].getName());
    date2= collection[i].getDate();
    cout<<"Product"<<i+1<<endl;
    cout<<"Barcode: ";
    for(int j=0;j<13;j++){
      cout<<barcode[j];
    }
    cout<<endl;
    cout<<"Name: ";
    for(int x=0;x<strlen(name);x++){
      cout<<name[x];
    }
    cout<<endl;
    cout<<"Weight: "<<collection[i].getWeight()<<endl;
    cout<<"Price: "<<collection[i].getPrice()<<endl;
    cout<<"Retail price: "<<collection[i].getMPrice()<<endl;
    cout<<"Existence: "<<collection[i].getExistence()<<endl;
    cout<<"Date: "<<date2.getDay()<<"-"<<date2.getMonth()<<"-"<<date2.getYear()<<endl;
  }
}
/*********************************************************************
* Comment
*********************************************************************/
int Collectproducts::MoreExistancie(const int& ActEX,const int& pos)
{
  int Exis,valid;
  Exis=collection[pos].getExistence();
  valid=Exis-ActEX;
  if(valid<0){
    return 0;
  }
  else{
    collection[pos].setExistence(valid);
    return 1;
  }
}
