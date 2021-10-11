#include "Menu.h"


void newproduct();
void sellproduct();
void morexistence();
Menu menu1;
Collectproducts collect;

int main(){
  int opc;
  collect.Initial();
  do{
    system("cls");
    menu1.ShowMenu();
    opc=menu1.getOption();
    switch(opc){
      case 1:{
        newproduct();
      }break;
      case 2:{
        sellproduct();
      }break;
      case 3:{
        morexistence();
      }break;
      case 4:{
        collect.ShowTheCollection();
      }break;
      case 5:{
        cout<<"Leaving..."<<endl;
      }break;
      default:{
        cout<<"Don´t exist that option"<<endl;
      }
    }
    system("pause>>cls");
  }while(opc!=5);
  return 0;
}

void newproduct(){
  char Barcode[13];
  char name[60];
  float w,r,mp,p;
  int d,m,y,e;
  cout<<"Type the code of the product "<<endl;
  cin>>Barcode;
  fflush(stdin);
  cout<<"Type the name of the product "<<endl;
  cin>>name;
  cout<<"Type the weight"<<endl;
  cin>>w;
  cout<<"Type the day"<<endl;
  cin>>d;
  cout<<"Type the month"<<endl;
  cin>>m;
  cout<<"Type the Year"<<endl;
  cin>>y;
  cout<<"Type the wholesale Price"<<endl;
  cin>>mp;
  cout<<"Type the existence"<<endl;
  cin>>e;
  collect.Update(Barcode,name,w,d,m,y,p,mp,e);
}

void sellproduct(){
  int leftover;
  float NewExis;
  char Code[13];
  int comprobe;
  cout<<"Type the product code"<<endl;
  cin>>Code;
  fflush(stdin);
  comprobe=collect.ValideExistence(Code);
  if (comprobe==-1){
    cout<<"This code is incorrecto"<<endl;
  }
  else{
    system("cls");
    cout<<"Type the quantity of the product to sale "<<endl;
    cin>>NewExis;
    comprobe=collect.MoreExistancie(NewExis,comprobe);
    if(!leftover){
      cout<<"You exceeded the amount of existence"<<endl;
    }
    else{
      cout<<"Sale complete"<<endl;
    }
  }
  system("pause");
}


void morexistence(){
  float MoreEx;
  char Code[13];
  int comprobe;
  cout<<"Type the code of the product"<<endl;
  cin>>Code;
  fflush(stdin);
  comprobe=collect.ValideExistence(Code);
  if(comprobe==-1){
    cout<<"Don´t exist that code"<<endl;
  }
  else{
    cout<<"Type the existence to add"<<endl;
    cin>>MoreEx;
    collect.MoreExistancie(MoreEx,comprobe);
    cout<<"Successful"<<endl;
  }
}
