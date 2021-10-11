 #include "Dates.h"
 #include "Matrix.h"
Matrix Matrix1;
Dates Dates1;
int main(){
  int opc=0;
  do{
    system("cls");
    cout<<"Select one opction"<<endl;
    cout<<"1)Size and ranges of Primitive Data types"<<endl;
    cout<<"2)Example of use of structured data type"<<endl;
    cout<<"3)Exit"<<endl;
    cin>>opc;
    switch(opc){
      case 1:{
        Dates1.CHAR();
        Dates1.UCHAR();
        Dates1.SING();
        Dates1.UING();
        Dates1.LINT();
        Dates1.ULINT();
        Dates1.FLOAT();
        Dates1.DFLOAT();
      }
      break;
      case 2:{
        Matrix1.ALLINONE();
      }
      break;
      case 3:{
        cout<<"Leaving the program..."<<endl;
      }
      break;
      default:{
        cout<<"This option dont exist"<<endl;
        system("pause");
      }
    }
  }while(opc!=3);
  return 0;
}

/*********************************************************************
* CHARACTER
*********************************************************************/
void Dates::CHAR()
{
  variablesize = sizeof(char)*8;
  cout<<"________________________________________________________________________________________________________________________"<<endl;
  cout<<"Data type \t Bits \t\t\t\t Minimum value \t\t\t Maximum value "<<endl;
  cout<<"________________________________________________________________________________________________________________________"<<endl;
  cout<<"CHARACTER \t The size of bits are: "<<variablesize <<"\t The minimum value are: "<<CHAR_MIN<<"\t The maximum value are: "<<CHAR_MAX<<endl;
}
/*********************************************************************
* UNSIGNED CHAR
*********************************************************************/
void Dates::UCHAR()
{
  variablesize = sizeof(unsigned char)*8;
  cout<<"________________________________________________________________________________________________________________________"<<endl;
  cout<<"UNSIGNED CHAR \t The size of bits are: "<<variablesize<<"\t The minimum value are: "<<CHAR_MIN+128<<"\t The maximum value are: "<<UCHAR_MAX<<endl;
}
/*********************************************************************
* SHORT INT
*********************************************************************/
void Dates::SING()
{
  cout<<"________________________________________________________________________________________________________________________"<<endl;
  variablesize = sizeof(short)*8;
  cout<<"SHORT INT \t The size of bits are: "<<variablesize<<"\t The minimum value are: "<<SHRT_MIN<<"\t The maximum value are: "<<SHRT_MAX<<endl;
}
/*********************************************************************
* UNSIGNED INT
*********************************************************************/
void Dates::UING()
{
  variablesize = sizeof(unsigned short)*8;
  cout<<"________________________________________________________________________________________________________________________"<<endl;
  cout<<"USHORT INT \t The size of bits are: "<<variablesize<<"\t The minimum value are: "<<SHRT_MIN+32768<<"\t The maximum value are: "<<USHRT_MAX<<endl;
}
/*********************************************************************
* LONG INT
*********************************************************************/
void Dates::LINT()
{
  variablesize = sizeof(long int)*8;
  cout<<"________________________________________________________________________________________________________________________"<<endl;
  cout<<"LONG INT \t The size of bits are: "<<variablesize<<"\t The minimum value are: "<<LONG_MIN<<"\t The maximum value are: "<<LONG_MAX<<endl;
}
/*********************************************************************
* UNSIGNED LONG INT
*********************************************************************/
void Dates::ULINT()
{
  variablesize = sizeof(unsigned long int)*8;
  cout<<"________________________________________________________________________________________________________________________"<<endl;
  cout<<"ULONG INT \t The size of bits are: "<<variablesize<<"\t The minimum value are: "<<LONG_MIN+2147483648<<"\t The maximum value are: "<<ULONG_MAX<<endl;
}
/*********************************************************************
* FLOAT
*********************************************************************/
void Dates::FLOAT()
{
  variablesize = sizeof(float)*8;
  cout<<"________________________________________________________________________________________________________________________"<<endl;
  cout<<"FLOAT \t\t The size of bits are: "<<variablesize<<"\t The minimum value are: "<<FLT_MIN<<"\t The maximum value are: "<<FLT_MAX<<endl;
}
/*********************************************************************
* DOUBLE FLOAT
*********************************************************************/
void Dates::DFLOAT()
{
  variablesize = sizeof(double)*8;
cout<<"________________________________________________________________________________________________________________________"<<endl;
  cout<<"DOUBLE FLOAT \t The size of bits are: "<<variablesize<<"\t The minimum value are: "<<DBL_MIN<<"\t The maximum value are: "<<DBL_MAX<<endl;
  cout<<"________________________________________________________________________________________________________________________"<<endl;
  system("pause");
}


void Matrix::ALLINONE(){
  int sizeofmatrix,i,x,z;
  float aux=0;
  float r;
  srand(time(NULL));
  do{
    cout<<"Introduce the size of the matrix (MIN 3-MAX 10)"<<endl;
    cin>>sizeofmatrix;
    if(sizeofmatrix>=3&&sizeofmatrix<=10){
      matrix1[10][10] = matrix1[sizeofmatrix][sizeofmatrix];
      matrix2[10][10] = matrix2[sizeofmatrix][sizeofmatrix];
      for(i=0;i<sizeofmatrix;i++){
        for(x=0;x<sizeofmatrix;x++){
          z = rand()%(2);
          if(z==0){
            r = rand() %(1000,-1000) / -10.0;
            matrix1[i][x]=r;
          }
          else{
           r = rand() %(1000,-1000) / 10.0;
          matrix1[i][x]=r;
        }
        }
      }
      for(i=0;i<sizeofmatrix;i++){
        for(x=0;x<sizeofmatrix;x++){
          z = rand()%(2);
          if(z==0){
            r = rand() %(1000,-1000) / -10.0;
            matrix2[i][x]=r;
          }
          else{
           r = rand() %(1000,-1000) / 10.0;
          matrix2[i][x]=r;
        }
        }
      }
      //show the matrix 1
      cout<<"The first matrix"<<endl;
      for(i=0;i<sizeofmatrix;i++){
        for(x=0;x<sizeofmatrix;x++){
          cout<<"["<<matrix1[i][x]<<"]\t";
        }
        cout<<endl;
      }
      cout<<endl;
      //show the matrix 2
      cout<<"The second matrix"<<endl;
      for(i=0;i<sizeofmatrix;i++){
        for(x=0;x<sizeofmatrix;x++){
          cout<<"["<<matrix2[i][x]<<"]\t";
        }
        cout<<endl;
      }
      cout<<endl;
      //show the add
      cout<<"The add of the matrix 1 and matrix 2"<<endl;
      for(i=0;i<sizeofmatrix;i++){
        for(x=0;x<sizeofmatrix;x++){
          cout<<"["<<matrix2[i][x]+matrix1[i][x]<<"]\t";
        }
        cout<<endl;
      }
      cout<<endl;
      cout<<"The multiplication of the matrix 1 and the matrix 2"<<endl;
      for (i=0;i<sizeofmatrix;i++){
        for(int a=0;a<sizeofmatrix;a++){
          aux=0;
          for(x=0;x<sizeofmatrix;x++){
            aux+=matrix1[i][x]*matrix2[x][a];
            matrix3[i][a]=aux;
          }
        }
      }
      for(i=0;i<sizeofmatrix;i++){
        for(x=0;x<sizeofmatrix;x++){
          cout<<"["<<matrix3[i][x]<<"]    ";
        }
        cout<<endl;
      }

    }
    else{
      cout << "the size is not in the limits" << endl;
    }
    system("pause");
}while(sizeofmatrix<3&&sizeofmatrix>10);
}
