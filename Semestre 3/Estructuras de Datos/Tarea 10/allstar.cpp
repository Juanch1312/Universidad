#include "Menu.h"
#include "Songs.h"
#include "list.h"
#include <iostream>
List<Songs> myrank;
Songs mysongs;
Menu mymenu;
List<Songs>::Position pos;


int main(){
  do{
    string myStr;
    system("cls");
    cout << "Ranking:" << endl;

    cout << myrank.ToString() << endl;
    cout<<"Insert the option"<<endl;
    mymenu.GetMenu();
    switch(mymenu.GetOption()){
      case 1:{
        system("cls");
        cout << "Ranking:" << endl;
        fflush(stdin);
        cout << myrank.ToString() << endl;
        cout<<"Name song: ";
        getline(cin,myStr);
        mysongs.SetNamesong(myStr);
        cout<<"Author song: ";
        getline(cin,myStr);
        mysongs.SetAuthor(myStr);
        cout<<"Interprete song: ";
        getline(cin,myStr);
        mysongs.SetInterprete(myStr);
        cout<<"Ranking Pos song: ";
        getline(cin,myStr);
        mysongs.SetRankingPos(myStr);

        myrank.InsertData(myrank.getLastPos(),mysongs);

      }break;

      case 2:{
        system("cls");
        cout << "Ranking:" << endl;

        cout << myrank.ToString() << endl;

        string myStr;

        fflush(stdin);
        cout<<"Insert the name of the song"<<endl;
        getline(cin,myStr);
        mysongs.SetNamesong(myStr);
        pos = myrank.findData(mysongs);
        try{
          cout<<"Delete the song: "<<myrank.retrieve(pos).ToString()<<"..."<<endl;
          myrank.deleteData(pos);
          cout<<"The song has been deleted"<<endl;
        }catch(List<Songs>::Exception ex){
          cout<<"Something bad happened..."<<endl;
          cout<<ex.what()<<endl;
        }
        system("pause");
      }break;

      case 3:{
        system("cls");
        cout << "Ranking:" << endl;

        cout << myrank.ToString() << endl;
        mymenu.GetMenuNameOrAuthor();
        switch (mymenu.GetOption()) {
          case 1:{
            fflush(stdin);
            cout<<"Insert the song name"<<endl;
            getline(cin,myStr);
            mysongs.SetNamesong(myStr);
            pos = myrank.findData(mysongs);
            try{
              cout<<"Found Song"<<endl;
              cout<<"The song is: "<<myrank.retrieve(pos).ToString()<<endl<<endl;
              system("pause");
            }catch(List<Songs>::Exception ex){
              cout<<"Something bad happened..."<<endl;
              cout<<ex.what()<<endl;
              system("pause");
            }
          }break;

          case 2:{
            fflush(stdin);
            cout<<"Insert the name of the Author"<<endl;
            getline(cin,myStr);
            mysongs.SetAuthor(myStr);
            pos = myrank.findData(mysongs);
            try{
              cout<<"Found Song"<<endl;
              cout<<"The song is: "<<myrank.retrieve(pos).ToString()<<endl<<endl;
              system("pause");
            }catch(List<Songs>::Exception ex){
              cout<<"Something bad happened..."<<endl;
              cout<<ex.what()<<endl;
              system("pause");
            }
          }break;
          default:{
            cout<<"Invalid option"<<endl;
          }break;
        }
      }break;

      case 4:{
        cout<<"The first song is: "<<myrank.retrieve(myrank.getFirstPos()).ToString()<<endl;
        system("pause");
      }break;

      case 5:{
        cout<<"The last song is: "<<myrank.retrieve(myrank.getLastPos()).ToString()<<endl;
        system("pause");
      }break;

      case 6:{
        fflush(stdin);
        cout<<"Insert one name of a song"<<endl;
        getline(cin,myStr);
        mysongs.SetNamesong(myStr);
        pos = myrank.findData(mysongs);
        try{
          cout<<"Found Song"<<endl;
          cout<<"The song is: "<<myrank.retrieve(myrank.getNextPos(pos)).ToString()<<endl;
          system("pause");
        }catch(List<Songs>::Exception ex){
          cout<<"Something bad happened..."<<endl;
          cout<<ex.what()<<endl;
          system("pause");
        }
      }break;

      case 7:{
        fflush(stdin);
        cout<<"Insert one name of a song"<<endl;
        getline(cin,myStr);
        mysongs.SetNamesong(myStr);
        pos = myrank.findData(mysongs);
        try{
          cout<<"Found Song"<<endl;
          cout<<"The song is: "<<myrank.retrieve(myrank.getPrevPos(pos)).ToString()<<endl;
          system("pause");
        }catch(List<Songs>::Exception ex){
          cout<<"Something bad happened..."<<endl;
          cout<<ex.what()<<endl;
          system("pause");
        }
      }break;

      case 8:{
        cout<<"Deleting all..."<<endl;
        myrank.deleteAll();
        system("pause");
      }break;

      case 9:{
        cout<<"Leaving..."<<endl;
      }break;

    }
  }while(mymenu.GetOption()!=9);
return 0;
}
