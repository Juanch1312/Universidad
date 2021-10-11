#include "Menu.h"
#include "Songs.h"
#include "list.h"
#include <iostream>
List<Songs> myrank;
Songs mysongs;
Menu mymenu;
int main(){
  do{
    string myStr;
    int position;
    system("cls");
    cout << "Ranking:" << endl;

    cout << myrank.toString() << endl;
    cout<<"Insert the option"<<endl;
    mymenu.GetMenu();
    switch(mymenu.GetOption()){
      case 1:{
        system("cls");
        cout << "Ranking:" << endl;
        fflush(stdin);
        cout << myrank.toString() << endl;
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

        myrank.insertData(myrank.getLastPos(),mysongs);

      }break;
      case 2:{
        system("cls");
        cout << "Ranking:" << endl;

        cout << myrank.toString() << endl;

        int pos;
        cout<<"Insert the posicion of the song"<<endl;
        cin>>pos;
        myrank.deleteData(pos);
        cout<<"The song has been deleted"<<endl;
        system("pause");
      }break;
      case 3:{
        system("cls");
        cout << "Ranking:" << endl;

        cout << myrank.toString() << endl;
        mymenu.GetMenuFind();
        switch(mymenu.GetOption()){
          case 1:{
            system("cls");
            cout << "Ranking:" << endl;

            cout << myrank.toString() << endl;
            mymenu.GetMenuNameOrAuthor();
            switch(mymenu.GetOption()){
              case 1:{
                fflush(stdin);
                cout<<"Name of the song: ";
                getline(cin,myStr);
                mysongs.SetNamesong(myStr);

                position=myrank.findDataLinear(mysongs);
                if (position==-1)
                {
                    cout<<"The element with the name " <<myStr<<" isnt in the list "<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"The Element with the name " <<myStr<<" is in the position "<<position<<endl;
                    system("pause");
                }
              }break;
              case 2:{
                fflush(stdin);
                cout<<"Author of the song: ";
                getline(cin,myStr);
                mysongs.SetAuthor(myStr);
                position=myrank.findDataLinear(mysongs);
                if (position==-1)
                {
                    cout<<"The element with the name " <<myStr<<" isnt in the list "<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"The Element with the name " <<myStr<<" is in the position "<<position<<endl;
                    system("pause");
                }
              }break;
              case 3:{
                system("cls");
                cout<<"Leaving Option"<<endl;
              }break;
              default:{
                system("cls");
                cout<<"Invalid Option"<<endl;
              }break;
            }
          }break;
          case 2:{
            system("cls");
            cout << "Ranking:" << endl;

            cout << myrank.toString() << endl;
            mymenu.GetMenuNameOrAuthor();
            switch(mymenu.GetOption()){
              case 1:{
                fflush(stdin);
                cout<<"Name of the song: ";
                getline(cin,myStr);
                mysongs.SetNamesong(myStr);

                position=myrank.findDataBinary(mysongs);
                if (position==-1)
                {
                    cout<<"The element with the name " <<myStr<<" isnt in the list "<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"The Element with the name " <<myStr<<" is in the position "<<position<<endl;
                    system("pause");
                }
              }break;
              case 2:{
                fflush(stdin);
                cout<<"Author of the song: ";
                getline(cin,myStr);
                mysongs.SetAuthor(myStr);
                position=myrank.findDataBinary(mysongs);
                if (position==-1)
                {
                    cout<<"The element with the name " <<myStr<<" isnt in the list "<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"The Element with the name " <<myStr<<" is in the position "<<position<<endl;
                    system("pause");
                }
              }break;
              case 3:{
                system("cls");
                cout<<"Leaving Option"<<endl;
              }break;
              default:{
                system("cls");
                cout<<"Invalid Option"<<endl;
              }break;
            }
          }break;
          case 3:{
            system("cls");
            cout<<"Leaving Option"<<endl;
          }
          default:{
            system("cls");
            cout<<"Invalid Option"<<endl;
          }
        }
      }break;
      case 4:{
        system("cls");
        cout<<"Leaving the program"<<endl;
      }break;
      default:{
        system("cls");
        cout<<"Invalid Option"<<endl;
      }break;
    }

  }while(mymenu.GetOption()!=4);


return 0;
}
