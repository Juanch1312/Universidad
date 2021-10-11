#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <exception>
#include <string>
#include <iostream>
#include <fstream> ///f es file(archivo)


class Exception : public std::exception{
    private:
        std::string msg;

    public:
        explicit Exception(const char* message) : msg(message) {}
        explicit Exception(const std::string&message) : msg(message) {}
        virtual ~Exception() throw () {}
        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };

template <class T, int ARRAYSIZE = 100000>
class List{
private:
    T data[ARRAYSIZE];
    int last;

    bool isValidPos(const int&p);

    void copyAll(const List&);

    void swapData(T&,T&);

    void sortDataMerge(const int&, const int&);
    void sortDataQuick(const int&, const int&);

public:
    List();

    bool isEmpty();
    bool isFull();

    void insertData(const int&, const T&);
    void deleteData(const int&);

    int getFirstPos();
    int getLastPos();
    int getNextPos(const int&);
    int getPrevPos(const int&);

    int findDataLinear(const T&);
    int findDataBinary (const T&);

    void sortDataBubble();
    void sortDataInsert();
    void sortDataSelect();
    void sortDataShell();
    void sortDataMerge();
    void sortDataQuick();

    T retrieve(const int&);

    //void print();

    std::string toString();

    void deleteAll();

    List& operator = (const List&);

    void writeToDisk(const std::string&);
    void readFromDisk(const std::string&);

};

using namespace std;

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::swapData(T& a, T& b)
{
    T aux(a);
    a=b;
    b=aux;
}



template <class T, int ARRAYSIZE>
bool List<T,ARRAYSIZE>::isValidPos(const int&p)
{
    return p >= 0 and p <= last;
}

template <class T, int ARRAYSIZE>
List<T,ARRAYSIZE>::List() : last(-1){}

template <class T, int ARRAYSIZE>
bool List<T,ARRAYSIZE>::isEmpty()
{
    return last == -1;
}

template <class T, int ARRAYSIZE>
bool List<T,ARRAYSIZE>::isFull()
{
    return last == ARRAYSIZE - 1;
}

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::insertData(const int&p, const T&e)
{
    if(isFull()){
        throw Exception("Desbordamiento de datos, insertData");
    }

    if(p != -1 && !isValidPos(p)){
        throw Exception("Posicion invalida, insertData");
    }
    int i(last);
    while(i > p){
        data[i+1] = data[i];
        i--;
    }
    data[p+1] = e;
    last++;

}

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::deleteData(const int&p)
{
    if(!isValidPos(p)){
        throw Exception("Posicion invalida, deleteData");
    }
    int i(p);
    while(i < last){
        data[i] = data[i+1];
        i++;
    }
    last--;
}

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::getFirstPos()
{
    if(isEmpty()){
        return -1;
    }
    return 0;
}

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::getLastPos()
{
    return last;
}

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::getNextPos(const int&p)
{
    if(p == last or !isValidPos(p)){
        return -1;
    }
    return p + 1;
}

template< class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::findDataLinear(const T& e)
{
    int i(0);

    while(i<=last)
    {
        if(data[i]==e)
        {
            return i;
        }
        i++;
    }
    return -1;
}
template< class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::findDataBinary(const T& e)
{
    int i(0),j(last),m;

    while(i<=j)
    {
        m = (i+j)/2;

        if(data[m]==e)
        {
            return m;
        }
        if(e < data[m]) ///student se le agrego const por el data[m]
        {
            j= m - 1;
        }
        else
        {
            i= m + 1;
        }
    }

    return -1;
}

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::getPrevPos(const int&p)
{
    if(p == 0 or !isValidPos(p)){
        return -1;
    }
    return p - 1;
}

template <class T, int ARRAYSIZE>
T List<T,ARRAYSIZE>::retrieve(const int&p)
{
    if(!isValidPos(p)){
        throw Exception("posicion invalida, retrieve");
    }
    return data[p];
}

template <class T, int ARRAYSIZE>
std::string List<T,ARRAYSIZE>::toString()
{
    std::string result;
    int i(0);
    while(i <= last){
        result +=  data[i].toString() + "\n";
        i++;
    }
    return result;
}

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::deleteAll()
{
    last = -1;
}

template< class T, int ARRAYSIZE>
List<T,ARRAYSIZE>& List<T,ARRAYSIZE>::operator=(const List&q) {
    copyAll(q);
    return *this;
    }

template< class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::writeToDisk(const std::string& fileName)
{
    ofstream myFile; ///esto representa un archivo en el disco

    myFile.open(fileName,myFile.trunc);/// ios_base::trunc ,trunc quita loq que hay en el archivo y sobrescribe

    if(!myFile.is_open()){ ///si mi archivo no esta abierto
        string message;
        message="No se pudo abrir archivo ";
        message+=fileName;
        message+=" para escritura, writeToDisk";

        throw Exception(message);
    }

    int i(0);

    while(i<=last){
        myFile << data[i]<<endl; ///usamos el operador de flujo

        i++;
    }
    myFile.close(); ///cerrar archivo, siepre cerrar archivo
}

template< class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::readFromDisk(const std::string& fileName){
   ifstream myFile;
    T myData;

    myFile.open(fileName);

    if(!myFile.is_open()){
        string message;
        message = "No se pudo abrir el archivo ";
        message += fileName;
        message += " para lectura, readFromDisk";

        throw Exception(message);
    }

    deleteAll();


    try{
        while(myFile >> myData){
            insertData(getLastPos(),myData);
        }
    } catch(Exception ex){
            myFile.close();

            string message("Error durante la lecutra del archivo ");
            message += fileName;
            message += " : ";
            message += ex.what();
            message += ", readFromDisk";
            throw Exception(message);
    }


    myFile.close();
}

template< class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataBubble() ///Burbuja mejorada
{
    int i(last), j;
    bool flag;

    do{
        flag= false;
        j=0;
        while(j<i)
        {
            if(data[j]>data[j+1])
            {
                swapData(data[j],data[j+1]); ///intercambio

                flag= true;
            }

            j++;
        }

        i--;
    }while(flag);
}

template< class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataInsert() ///Insert
{
       int i(1),j;
       T aux;

       while(i<= last)
       {
           aux = data[i];

           j=i;
           while(j > 0 and aux < data[j-1])
           {
               data[j]= data[j-1];

               j--;
           }

           if(i!=j){
            data[j]= aux;
           }
           i++;
       }
}
template< class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataSelect() ///Select
{
       int i(0),j,m;

       while(i<last){
         m=i;
         j=i+1;
         while(j<=last){
           if(data[j]<data[m]){
             m=j;
           }

           j++;
         }
         if(i!=m){
           swapData(data[i],data[m]);
         }
         i++;
       }
}



template< class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataShell() ///Shell
{
       float factor(1.0/2.0);
       int dif((last+1)*factor), i,j;

       while(dif>0){
         i = dif;
         while(i<=last){
           j=i;
           while(j>=dif and data[j-dif]>data[j]){
             swapData(data[j-dif],data[j]);

             j-=dif;
           }

           i++;
         }

         dif*=factor;
       }
}



template< class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataMerge(){
    sortDataMerge(0,last);
}

template< class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataMerge(const int& leftEdge, const int& rigthEdge){

        if(leftEdge >= rigthEdge){ ///criterio
            return;
        }

        ///Divide y venceras
        int m((leftEdge + rigthEdge)/2);

        sortDataMerge(leftEdge,m);
        sortDataMerge(m +1, rigthEdge);

        ///copia
        static T temp[ARRAYSIZE]; ///solo hace una copia

        for(int z(leftEdge); z<= rigthEdge; temp[z] = data[z], z++);

        ///intercalacion

        int i(leftEdge), j(m+1), x(leftEdge);

        while (i<= m and j<= rigthEdge)
        {
            while(i<=m and temp[i]<= temp[j])
            {
                data[x++]= temp[i++];
            }

            if(i <= m)
            {
                while (j <= rigthEdge and temp[j]<= temp[i])
                {
                    data[x++]= temp[j++];
                }
            }
        }

        while(i<=m)
            {
                data[x++]= temp[i++];
            }

        while (j <= rigthEdge)
            {
                data[x++]= temp[j++];
            }

        }

template< class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataQuick(){

    sortDataQuick(0,last);
}

template< class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataQuick(const int& leftEdge, const int& rigthEdge){

    if(leftEdge >= rigthEdge) ///Criterio de paro
    {
        return;
    }

    int i(leftEdge), j(rigthEdge);

    while(i<j)
    {
        while (i<j and data[i]<= data[rigthEdge])
        {
            i++;
        }

        while(i<j and data[j]>= data[rigthEdge] )
        {
            j--;
        }

        if(i!= j)
        {
            swapData(data[i], data[j]);
        }
    }

    if(i != rigthEdge)
    {
        swapData(data[i], data[rigthEdge]);
    }

    ///Divide y venceras
    sortDataQuick(leftEdge, i-1);
    sortDataQuick(i+1, rigthEdge);
}



#endif // LIST_H_INCLUDED
