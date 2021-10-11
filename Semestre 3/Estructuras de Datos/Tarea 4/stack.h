#ifndef PILA_H
# define PILA_H
#include <iostream>

template <class T, int ARRAYSIZE = 1024>
class Stack{
    private:
        T data[ARRAYSIZE];
        int top;

        void copyAll(const Stack&);

    public:
        class Exception : public std::exception {
                private:
                    std::string msg;

                public:
                    explicit Exception(const char* message) : msg(message) {}

                    explicit Exception(const std::string& message) : msg(message) {}

                    virtual ~Exception() throw () { }

                    virtual const char* what() const throw () {
                        return msg.c_str();
                        }
                };
        Stack();
        Stack(const Stack&);

        bool isEmpty();
        bool isFull();

        void push(const T&);

        T pop();

        T getTop();

        Stack& operator = (const Stack&);
};

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack(){
    top=-1;
}

template <class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::copyAll(const Stack &s){
    int i(0);
    while(i<=s.top){
        this->data[i]=s.data[i];
        i++;
    }
    this->top=s.top;
}

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack(const Stack& s){
    copyAll(s);
}

template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isEmpty(){
    return top==-1;
}

template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isFull(){
    return top==ARRAYSIZE-1;
}

template <class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::push(const T& e){
    if(isFull()){
        throw Exception("Desbordamiento de datos, push.");
    }
    data[++top]=e;
}

template <class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::pop(){
    if(isEmpty()){
        throw Exception("Insuficiencia de datos, pop");
    }
    return data[top--];
}

template <class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::getTop(){
    if(isEmpty()){
        throw Exception("Insuficiencia de datos, getTop");
    }
    return data[top];
}

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>& Stack<T, ARRAYSIZE>::operator=(const Stack& s){
    copyAll(s);
}

#endif
