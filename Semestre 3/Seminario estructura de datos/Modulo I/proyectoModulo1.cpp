#include <iostream>
#include <cstdio>
#include <math.h>
#include <cctype>
#include <string.h>

using namespace std;


int validacionunica(char n[100]);
int validacion(char n[100],char n2[100]);
int validaBin(char n[200]);
int validaOctal(char chain1[200]);
int validaHexa(char chain1[200]);
float *suma (float *n1,float *n2);
float *Sustraccion (float *n1, float *n2);
float *Multiplicacion (float *n1, float*n2);
float *Divicion (float *n1, float*n2);
int *Potencia (int*ptr,int*ptr2);
int *factorial (int*ptr);
void Raiz(int*ptr);
float *Porcentaje(float *n,float *n2);
void Binario(int* numero);
int *BinADec(float *ptr1);
int *DecAHex(int *Ptr);
int *OctADec(int *Ptr);
int *DecAOct(int *Ptr);
int HexADec(char n[100]);


string hexa="";
char hexadecimal[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

int validacion(char *);
char numero1[100],numero2[100];
int *ptr1,*ptr2;
float *ptr3,*ptr4;
bool comprobar;
int a,b;
int main(){
  char opc[1000];
  int opci;
  do{
  system("cls");
    cout<<"Eliga una opcion"<<endl;
    cout<<"1)Suma"<<endl;
    cout<<"2)Resta"<<endl;
    cout<<"3)Multiplicacion"<<endl;
    cout<<"4)Division"<<endl;
    cout<<"5)Potencia"<<endl;//todas
    cout<<"6)Factorial"<<endl;
    cout<<"7)Porcentaje"<<endl;//1
    cout<<"8)Raiz"<<endl;//2
    cout<<"9)DEC-BIN"<<endl;
    cout<<"10)BIN-DEC"<<endl;
    cout<<"11)DEC-OCT"<<endl;
    cout<<"12)OCT-DEC"<<endl;
    cout<<"13)DEC-HEX"<<endl;
    cout<<"14)HEX-DEC"<<endl;
    cout<<"15)SALIR"<<endl;
    cin>>opc;
    opci=atoi(opc);
    switch(opci){
      case 1:{
        cout<<"Inserte el primer digito"<<endl;
        cin>>numero1;
        cout<<"Inserte el segundo digito"<<endl;
        cin>>numero2;
        comprobar=validacion(numero1,numero2);
        if(comprobar == 1){
          float n=atof(numero1);
          float m=atof(numero2);
          ptr3=&n;
          ptr4=&m;
          cout<<"El resultado de la suma es: "<<*suma(ptr3,ptr4)<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }

      }break;
      case 2:{
        cout<<"Inserte el primer digito"<<endl;
        cin>>numero1;
        cout<<"Inserte el segundo digito"<<endl;
        cin>>numero2;
        comprobar=validacion(numero1,numero2);
        if(comprobar == 1){
          float n=atof(numero1);
          float m=atof(numero2);
          ptr3=&n;
          ptr4=&m;
          cout<<"El resultado de la Sustraccion es: "<<*Sustraccion(ptr3,ptr4)<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 3:{
        cout << "Inserte el primer digito" << endl;
        cin>>numero1;
        cout<<"Inserte el segundo digito"<<endl;
        cin>>numero2;
        comprobar=validacion(numero1,numero2);
        if(comprobar == 1){
          float n=atof(numero1);
          float m=atof(numero2);
          ptr3=&n;
          ptr4=&m;
          cout<<"El resultado de la Multiplicacion es: "<<*Multiplicacion(ptr3,ptr4)<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 4:{
        cout<<"Inserte el primer digito"<<endl;
        cin>>numero1;
        cout<<"Inserte el segundo digito"<<endl;
        cin>>numero2;
        comprobar=validacion(numero1,numero2);
        if(comprobar == 1){
          float n=atof(numero1);
          float m=atof(numero2);
          ptr3=&n;
          ptr4=&m;
          cout<<"El resultado de la Divicion es: "<<*Divicion(ptr3,ptr4)<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 5:{
        cout<<"Inserte el primer digito"<<endl;
        cin>>numero1;
        cout<<"Inserte el segundo digito"<<endl;
        cin>>numero2;
        comprobar=validacion(numero1,numero2);
        if(comprobar == 1){
          a=atoi(numero1);
          b=atoi(numero2);
          ptr1=&a;
          ptr2=&b;
          cout<<"El resultado de la Potencia es: "<<*Potencia(ptr1,ptr2)<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 6:{
        cout<<"Inserte el digito"<<endl;
        cin>>numero1;
        comprobar=validacionunica(numero1);
        if(comprobar == 1){
          a=atoi(numero1);
          ptr1=&a;
          ptr2=&b;
          cout<<"El resultado de la factorial es: "<<*factorial(ptr1)<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
        }
      }break;
      case 7:{
        cout<<"Inserte el primer digito"<<endl;
        cin>>numero1;
        cout<<"Inserte el segundo digito"<<endl;
        cin>>numero2;
        comprobar=validacion(numero1,numero2);
        if(comprobar == 1){
          float n=atof(numero1);
          float m=atof(numero2);
          ptr3=&n;
          ptr4=&m;
          cout<<"El resultado de la Porcentaje es: "<<*Porcentaje(ptr3,ptr4)<<endl;
          system("pause");
        }
        else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
      }
    }break;
    case 8:{
      cout<<"Inserte el primer digito"<<endl;
      cin>>numero1;
      comprobar=validacionunica(numero1);
      if(comprobar == 1){
        a=atoi(numero1);
        ptr1=&a;
        cout<<"El resultado de la Raiz es: ";
        Raiz(ptr1);
        cout<<endl;
        system("pause");
      }
      else{
        cout<<"Dato/s invalido/s"<<endl;
        system("pause");
      }
    }break;
    case 9:{
      cout<<"Inserte el decimal a convertir"<<endl;
      cin>>numero1;
      comprobar=validacionunica(numero1);
      if(comprobar == 1){
        a=atoi(numero1);
        ptr1=&a;
        cout<<"El binario del numero es: ";
        Binario(ptr1);
        cout<<endl;
        system("pause");
      }
      else{
        cout<<"Dato/s invalido/s"<<endl;
        system("pause");
      }
    }break;
    case 10:{
      float b;
      cout<<"Inserte el decimal a convertir"<<endl;
      cin>>numero1;
      comprobar=validaBin(numero1);
      if(comprobar==0){
                b=atoi(numero1);
                ptr3=&b;
                *BinADec(ptr3);
                system("pause");
            }
            else{
              cout<<"Dato/s invalido/s"<<endl;
              system("pause");
            }
    }break;
    case 11:{
      cout<<"Inserte el decimal a convertir"<<endl;
      cin>>numero1;
      comprobar=validacionunica(numero1);
      if(comprobar==1){
                a=atoi(numero1);
                ptr1=&a;
                *DecAOct(ptr1);
                system("pause");
            }
      else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
      }
    }break;
    case 12:{
      cout<<"Inserte el decimal a convertir"<<endl;
      cin>>numero1;
      comprobar=validaOctal(numero1);
      if(comprobar==0){
                a=atoi(numero1);
                ptr1=&a;
                *OctADec(ptr1);
                system("pause");
      }
      else{
          cout<<"Dato/s invalido/s"<<endl;
          system("pause");
      }
    }break;
    case 13:{
      cout<<"Inserte el decimal a convertir"<<endl;
      cin>>numero1;
      comprobar=validacionunica(numero1);
      if(comprobar==1){
                a=atoi(numero1);
                ptr1=&a;
                *DecAHex(ptr1);
                system("PAUSE");
            }
      else{
        cout<<"Dato/s invalido/s"<<endl;
        system("pause");
      }
    }break;
    case 14:{
      cout<<"Inserte el decimal a convertir"<<endl;
      cin>>numero1;
      comprobar=validaHexa(numero1);
      if(comprobar==0){
        HexADec(numero1);
        system("pause");
      }
      else{
        cout<<"Dato/s invalido/s"<<endl;
        system("pause");
      }
    }break;
    case 15:{
      cout<<"Saliendo..."<<endl;
    }break;
      default:{
        cout<<"Dato invalido"<<endl;
        system("pause");
      }
    }
  }while(opci!=15);
  return 0;
}


int validacion(char n[100],char n2[100]){
  if(n[0]=='-'||n2[0]=='-'||n[0]=='.'||n2[0]=='.'){
    if(isdigit(n[1])&&isdigit(n2[1])){
    return 1;
    }
    else{
      return 0;
    }
  }
  else{
    if(isdigit(n[0])&&isdigit(n2[0])){
      return 1;
    }
    else{
      return 0;
    }

  }
}


int validacionunica(char n[100]){
  if(isdigit(n[0])=='-'){
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


int validaBin(char chain1[200]){
    int ban;
    for(int i=0;i<=(signed)strlen(chain1);i++){
        int z=(char)chain1[i];
        if(isdigit(z)<48&&z>49){
            ban=-1;
        }
    }
    if(ban==-1){
        return -1;
    }
    else{
        return 0;
    }
  }



int validaOctal(char numero[200]){
      int ban;
      for(int i=0;i<=(signed)strlen(numero);i++){
          int z=(char)numero[i];
          if(isdigit(z)<48&&z>55){
              ban=-1;
          }
      }
      if(ban==-1){
          return -1;
      }
      else{
          return 0;
      }
  }

  int validaHexa(char numero[100]){
      int ban=0,i;
      if(numero[0]=='\0'){
          ban=-1;
      }
      for(i=0;i<strlen(numero);i++){
          if((numero[i]<'0'||numero[i]>'9')&&(numero[i]<'A'||numero[i]>'F')){
              ban=-1;
          }
      }
      if(ban==-1){
          return -1;
      }
      else{
          return 0;
      }
  }


float *suma (float *n1,float *n2){
  float *r =(float*)malloc(sizeof(float));
  *r = (*n1)+(*n2);
  return r;
}

float *Sustraccion (float *n1, float *n2){
  float *r =(float*)malloc(sizeof(float));
  *r = (*n1)-(*n2);
  return r;
}

float *Multiplicacion (float *n1, float*n2){
  float *r =(float*)malloc(sizeof(float));
  *r = (*n1)*(*n2);
  return r;
}

float *Divicion (float *n1, float*n2){
  float *r =(float*)malloc(sizeof(float));
  *r = (*n1)/(*n2);
  return r;
}

int *Potencia (int*ptr,int*ptr2){
  int *r=(int*)malloc(sizeof(int));
  *r=*ptr;
  *r=*ptr2;
  *r=pow(*ptr,*ptr2);
  return r;
}


int *factorial (int*ptr){
  int *r=(int*)malloc(sizeof(int));
  *r=*ptr;
  for(int i=1;i<*ptr;i++){
    *r=(*r)*(i);
  }
  return r;
}

float *Porcentaje(float *n,float *n2){
  float *r=(float*)malloc(sizeof(float));
  *r=((*n)*(*n2)/100);
  return r;
}

void Raiz(int *ptr){
  int *r=(int*)malloc(sizeof(int));
  *r=sqrt(*ptr);
  cout<<*r;
}

void Binario(int* numero){
      int matrix1[50],matrix2[50];
    int a=0,b=0;
    for(int x=0;x<50;x++){
        matrix1[x]=0;
        matrix2[x]=0;
      }
    int*r=(int*)malloc(sizeof(int));
    *r=*numero;
    do{
        matrix1[a]=*r%2;
        *r=*r/2;
        a=a+1;
    }while(*r!=0);
    b=a;
    for(int x=0;x<=a;x++){
        matrix2[x]=matrix1[b];
        b=b-1;
    }
    for(int x=0;x<=a;x++){
        cout << matrix2[x];
    }
}

int *BinADec(float *ptr1){
    int exp,dig;
    float dec;
    float *r=(float*)malloc(sizeof(float));
    *r=*ptr1;
    while(((int)(*r/10))!=0){
        dig=(int)*r%10;
        dec=dec+dig*pow(2.0,exp);
        exp++;
        *r=(int)(*r/10);
   }
   dec=dec+(*r)*pow(2.0,exp);
   cout << "El valor en decimal es: " << (int)dec << endl;
   return 0;
}

int *DecAOct(int *Ptr){
    int base=1,suma=0,res;
    int *r=(int*)malloc(sizeof(int));
    *r=*Ptr;
        do{
            res=(*r)%8;
            (*r)=(*r)/8;
            suma=suma+res*base;
            base=base*10;
        }while((*r)>0);
    cout << "El valor en octal es: " << suma << endl;
    return 0;
}

int *OctADec(int *Ptr){
    int dec=0,i=0,rem;
    int *r=(int*)malloc(sizeof(int));
    *r=*Ptr;
    while(*r!=0){
        rem=*r%10;
        *r/=10;
        dec+=rem*pow(8,i);
        ++i;
    }
    cout << "El valor en decimal es: " << dec << endl;
    return 0;
}

int *DecAHex(int *Ptr){
    int res;
    int *r=(int*)malloc(sizeof(int));
    *r=*Ptr;
    while((*r)>0){
        res=(*r)%16;
        hexa=hexadecimal[res]+hexa;
        (*r)=(*r)/16;
    }
    cout << "El valor en hexadecimal es: " << hexa << endl;
    return 0;
}

int HexADec(char num[100]){
  int decimal,j,p,digito;
    decimal=0;
    p=1;
    for(j=strlen(num)-1; j>=0; j--)
    {
        num[j]=num[j];
        digito = num[j]-(num[j]<='9'?48:55);
        decimal=decimal+digito*p;
        p=p*16;
    }
    cout<<"El decimal es: "<<decimal<<endl;
  return 0;
}
