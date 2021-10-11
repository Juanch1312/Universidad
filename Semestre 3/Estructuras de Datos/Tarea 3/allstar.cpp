#include "Menu.h"
#include "songs.h"
#include "list.h"
#include <iostream>
List myrank;
Menu mymenu;
int main(){
  do{
    system("cls");
    myrank.print();
    mymenu.GetMenu();
    switch(mymenu.GetOption()){
      case 1:{
        system("cls");
        myrank.print();
        char name[50];
        char aut[50];
        char inter[50];
        int rank;
        int pos;
        fflush(stdin);
        cout<<"___________________________________"<<endl;
        cout<<"Insert the Name of the song"<<endl;
        cout<<endl<<endl;
        cin.getline(name,50,'\n');
        cout<<"___________________________________"<<endl;
        cout<<"Insert the Author"<<endl;
        cout<<endl<<endl;
        cin.getline(aut,50,'\n');
        cout<<"___________________________________"<<endl;
        cout<<"Insert the Interpreter"<<endl;
        cout<<endl<<endl;
        cin.getline(inter,50,'\n');
        cout<<"___________________________________"<<endl;
        cout<<"Insert the ranking posicion"<<endl;
        cout<<endl<<endl;
        cin>>rank;
        cout<<"___________________________________"<<endl;
        cout<<"Insert the posicion"<<endl;
        cout<<endl<<endl;
        cin>>pos;
        cout<<"___________________________________"<<endl;
        myrank.insertData(pos,name,aut,inter,rank);
      }break;
      case 2:{
        system("cls");
        myrank.print();
        int pos;
        cout<<"Insert the posicion of the song"<<endl;
        cin>>pos;
        myrank.deleteData(pos);
        cout<<"The song has been deleted"<<endl;
        system("pause");
      }
      case 3:{
        cout<<"Leaving..."<<endl;
      }break;
      default:{
        cout<<"Don't exist that option"<<endl;
      }break;
    }
  }while(mymenu.GetOption()!=3);
}
