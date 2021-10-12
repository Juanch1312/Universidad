#include <iostream>
#include <cstdlib>

using namespace std;

void Binario(int*);

int matrix1[50],matrix2[50],x=0,y=0;

int main(){
  do{
    system("cls");
    int num=0,*ptr;
    for(x=0;x<50;x++){
        matrix1[x]=0;
        matrix2[x]=0;
    }
    cout<<endl;
    cout << "Introduce algun numero: ";
    cin >> num;
    ptr=&num;
    Binario(ptr);
    cout<<endl;
    system("pause");
  }while(y!=1);
    return 0;
}

void Binario(int* numero){
    int a=0,b=0;
    int*r=(int*)malloc(sizeof(int));
    *r=*numero;
    do{
        matrix1[a]=*r%2;
        *r=*r/2;
        a=a+1;
    }while(*r!=0);
    b=a;
    for(x=0;x<=a;x++){
        matrix2[x]=matrix1[b];
        b=b-1;
    }
    for(x=0;x<=a;x++){
        cout << matrix2[x];
    }
}
