#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

class Exception : public std::exception {
    private:
        std::string msg;

    public:
        explicit Exception(const char* message) : msg(message) {}

        explicit Exception(const std::string& message) : msg(message) {}

        virtual ~Exception() throw() {}

        virtual const char* what() const throw() {
            return msg.c_str();
            }
    };

template <class T, int ARRAYSIZE = 4094>
class List {

    private:
        T* data[ARRAYSIZE];
        int last;

        bool isValidPos(const int&) const;

        void copyAll(const List&);


        void swapData(T*&,T*&);

    public:
      int findDataLinear(const T&) const;
      int findDataBinary(const T&) const;
      void bubbleSortM();
      void insertSort();
      void selectSort();
      void shellSort();
      List();
      List(const List&);

      ~List();

      bool isEmpty() const;
      bool isFull() const;

      void insertData(const int&,const T&);

      void deleteData(const int&);

      int getFirstPos() const;
      int getLastPos() const;
      int getPrevPos(const int&) const;
      int getNextPos(const int&) const;
      std::string toString() const;

      int findData(const T&,const int&) const;

      T retrieve(const int&) const;

      std::string sortData(const int&);

      void deleteAll();

      List& operator = (const List&);

      void writeToDisk(const std::string&);
      void readFromDisk(const std::string&);
    };

template <class T,int ARRAYSIZE>
bool List<T,ARRAYSIZE>::isValidPos(const int& p) const {
    return p >= 0 and p <= last;
    }

template <class T, int ARRAYSIZE>
void List <T,ARRAYSIZE>::copyAll(const List& s) {

    int i(0);

    while (i<= s.last) {
        this->data[i] = s.data[i];
        i++;
        }

    this->last = s.last;
    }

template <class T, int ARRAYSIZE>
List<T,ARRAYSIZE>::List() : last(-1) {}

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List(const List& s) {
    copyAll(s);
    }

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::~List() {
    deleteAll();
    }

template <class T,int ARRAYSIZE>
bool List<T,ARRAYSIZE>::isEmpty() const {
    return last == -1;
    }

template <class T,int ARRAYSIZE>
bool List<T,ARRAYSIZE>::isFull() const {
    return last == ARRAYSIZE -1;
    }

template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::insertData(const int& p, const T& e) {

    if(isFull()) {
        throw Exception("Desbordamiento de datos... ");
        }

    if(p != -1 and !isValidPos(p)) {
        throw Exception("Posicion Invalida... ");
        }

    int i(last);

    while(i>p) {
        data[i+1] = data[i];

        i--;
        }

    data[p + 1] = new T(e);

    last++;
    }

template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::deleteData(const int& p) {

    if(!isValidPos(p)) {
        throw Exception("Posicion invalida, deleteData");
        }

    delete data[p];

    int i(p);

    while(i < last) {
        data[i] = data[i + 1];

        i++;
        }

    data[last--] = nullptr;
    }

template <class T,int ARRAYSIZE>
int List<T,ARRAYSIZE>::getFirstPos() const {

    if (isEmpty()) {
        return -1;
        }

    return 0;
    }

template <class T,int ARRAYSIZE>
int List<T,ARRAYSIZE>::getLastPos() const {
    return last;
    }

template <class T,int ARRAYSIZE>
int List<T,ARRAYSIZE>::getPrevPos(const int& p) const {

    if(p == 0 or !isValidPos(p)) {
        return -1;
        }
    return p - 1;
    }

template <class T,int ARRAYSIZE>
int List<T,ARRAYSIZE>::getNextPos(const int& p) const {

    if(p == last or !isValidPos(p)) {
        return -1;
        }
    return p + 1;
    }

template <class T,int ARRAYSIZE>
std::string List<T, ARRAYSIZE>::toString() const {

    int i(0);

    std::string result;

    while(i<=last) {

        result += data[i]->toString();
        result += "\n";

        i++;

        }

    return result;
    }


template <class T,int ARRAYSIZE>
int List<T, ARRAYSIZE>::findDataLinear(const T& e) const {

    for(int i(0) ; i <= last ; i++) {
        if(e == *data[i]) {
            return i;
            }
        }

    return -1;
    }

template <class T,int ARRAYSIZE>
int List<T, ARRAYSIZE>::findDataBinary(const T& e) const {

    int i(0), j(last), m;

    while(i <= j) {

        m = (i + j) / 2;

        if(e == *data[m]) {
            return m;
            }

        if(e < *data[m]) {
            j = m - 1;
            }
        else {
            i = m + 1;
            }
        }

    return -1;
    }

template <class T,int ARRAYSIZE>
T List<T,ARRAYSIZE>::retrieve(const int& p) const {
    if(!isValidPos(p)) {
        throw Exception("Poscion NO valida en RETRIEVE");
        }

    return *data[p];
    }

template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::swapData(T*& a, T*& b) {

    T* aux = a;

    a = b;
    b = aux;

    aux = nullptr;
    }

template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::bubbleSortM() {

    bool flag;

    T* Apuntador;
    int i(last),j(0);

    do {
        flag = false;
        j = 0;

        while(j < i) {

            if(*data[j] > *data[j + 1]) {

                Apuntador = data[j];
                data[j] = data[j + 1];
                data[j + 1] = Apuntador;

                flag = true;
                }

            j++;
            }

        i--;
        }
    while(flag);
    }

template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::insertSort() {

    T aux;
    int i(1),j(0);

    while (i <= last) {
        aux = *data[i];
        j = i;

        while(j > 0 and aux < *data[j - 1]) {
            *data[j] = *data[j - 1];
            j--;
            }
        if (i != j) {
            *data[j] = aux;
            }
        i++;
        }
    }

template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::selectSort() {

    int i(0), minor(i),j(i + 1);

    while(i < last) {
        minor = i;

        j = i + 1;

        while (j <= last) {
            if(*data[j] < *data[minor]) {
                minor = j;
                }

            j++;
            }

        if(minor != i) {
            swapData(data[i],data[minor]);
            }

        i++;
        }
    }

template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::shellSort() {

    ///unsigned ciuraSerie[] = {510774, 227011, 100894, 44842, 19930, 8858, 3937, 1750, 701, 301, 132, 57, 23, 10, 4, 1,0};

    float fact = (3.0/4.0);
    int gap(last * fact), i(0);

    while(gap > 0) {
        i = 0;

        while(i <= (last-gap)) {
            if(*data[i] > *data[i + gap]) {
                swapData(data[i],data[i + gap]);
                }
            i++;
            }
        gap *= fact;
        }
    }



template <class T,int ARRAYSIZE>
void List<T,ARRAYSIZE>::deleteAll() {
    for (int i(0) ; i <= last ; i++) {
        delete data[i];
        data[i] = nullptr;
        }

    last = -1;
    }

template <class T,int ARRAYSIZE>
List<T,ARRAYSIZE>& List<T,ARRAYSIZE>::operator=(const List& s) {

    copyAll(s);

    return *this;
    }

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::writeToDisk(const std::string& fileName) {
    std::ofstream myFile;

    myFile.open(fileName, myFile.trunc);

    if(!myFile.is_open()) {
        std::string message;
        message = "No se puede abrir el archivo ";
        message += fileName;
        message += " para escritura, writeToDisk.";

        throw Exception (message);
        }

    int i(0);

    while(i <= last) {
        myFile << data[i++] << std::endl;
        }

    myFile.close();
    }

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::readFromDisk(const std::string& fileName) {
    std::ifstream myFile;

    T myData;

    myFile.open(fileName);

    if(!myFile.is_open()) {
        std::string message = "No se puede abrir el archivo ";
        message += fileName;
        message += " para lectura, readFromDisk.";

        throw Exception(message);
        }

    deleteAll();

    try {
        while(myFile >> myData) {
            insertData(getLastPos(), myData);
            }
        }
    catch (Exception ex) {

        myFile.close();

        std::string message;
        message = "Error durante la lectura del archivo. " ;
        message += fileName;
        message += " : ";
        message += ex.what();
        message += ", readFromDisk";

        throw Exception (message);
        }

    myFile.close();
    }

#endif // LIST_H_INCLUDED
