#include "Menu.h"
#include "Queue.h"
#include "Schedule.h"

Queue<Schedule> myQueue;
Schedule mySchedule;
Menu mymenu;

int main(){
  int opc;
  do{
    system("cls");
    printf("\t%c",201);
    for(int x=0;x<50;x++){
      printf("%c",205);
    }
    printf("%c\n",187);
    printf("\t%cID\tName    Direction  CellNumber\tE-Mail     %c\n",186,186);
    printf("\t%c",200);
    for(int x=0;x<50;x++){
      printf("%c",205);
    }
    printf("%c\n",188);
    cout<<myQueue.toString();
    cout<<"\n\n";
    mymenu.GetMenu();
    opc = atoi(mymenu.GetOpc());
    switch(opc){
      case 1:{
        system("cls");
        cout<<myQueue.toString();
        string mystr;
        fflush(stdin);
        cout<<"Type the ID:\n";
        getline(cin,mystr);
        mySchedule.setID(mystr);


        cout<<"\n\n\n";
        cout<<"Type the Name:\n";
        getline(cin,mystr);
        mySchedule.setName(mystr);


        cout<<"\n\n\n";
        cout<<"Type the Direction:\n";
        getline(cin,mystr);
        mySchedule.setDirection(mystr);


        cout<<"\n\n\n";
        cout<<"Type the CellNumber:\n";
        getline(cin,mystr);
        mySchedule.setNumber(mystr);


        cout<<"\n\n\n";
        cout<<"Type the E-Mail:\n";
        getline(cin,mystr);
        mySchedule.setMail(mystr);

        myQueue.enqueue(mySchedule);
      }break;
      case 2:{
        system("cls");
        printf("\t%c",201);
        for(int x=0;x<50;x++){
          printf("%c",205);
        }
        printf("%c\n",187);
        printf("\t%cID\tName    Direction  CellNumber\tE-Mail     %c\n",186,186);
        printf("\t%c",200);
        for(int x=0;x<50;x++){
          printf("%c",205);
        }
        printf("%c\n",188);
        cout<<myQueue.getFirstPos()<<endl;
        system("pause");
      }break;
      case 3:{
        system("cls");
        printf("\t%c",201);
        for(int x=0;x<50;x++){
          printf("%c",205);
        }
        printf("%c\n",187);
        printf("\t%cID\tName    Direction  CellNumber\tE-Mail     %c\n",186,186);
        printf("\t%c",200);
        for(int x=0;x<50;x++){
          printf("%c",205);
        }
        printf("%c\n",188);
        cout<<myQueue.getLastPos()<<endl;
        system("pause");
      }break;
      case 4:{
        system("cls");
        string id;
        fflush(stdin);
        cout<<"Type the ID: ";
        getline(cin,id);
        mySchedule.setID(id);
        cout<<"\n\n";
        printf("\t%c",201);
        for(int x=0;x<50;x++){
          printf("%c",205);
        }
        printf("%c\n",187);
        printf("\t%cID\tName    Direction  CellNumber\tE-Mail     %c\n",186,186);
        printf("\t%c",200);
        for(int x=0;x<50;x++){
          printf("%c",205);
        }
        printf("%c\n",188);
        cout<<myQueue.findData(mySchedule);
        system("pause");
      }break;
      case 5:{
        myQueue.dequeuque();
      }break;
      case 6:{
        cout<<"leaving..."<<endl;
      }break;
      default:{
        cout<<"Invalid option"<<endl;
        system("pause");
      }break;
    }
  }while(opc!=6);

  return 0;
}
