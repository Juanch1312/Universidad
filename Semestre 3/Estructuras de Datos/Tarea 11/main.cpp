#include "stack.h"
#include "queue.h"

using namespace std;

int priority (char a);
bool isOperator(char a);

int main() {
    string infix;
    int i;
    cout << "Enter an algebraic expression: "<<endl;
    getline(cin,infix);
    string posfix;
    Stack<char> myStack;
    Queue<string> myQueue;
    for(i=0;i<infix.length();i++) {
        if(isOperator(infix[i])==true) {
            while(!myStack.isEmpty() && priority(myStack.getTop()) <= priority(infix[i])) {
                posfix+= myStack.getTop();
                myStack.pop();
            }
            myStack.push(infix[i]);
        } else if(infix[i] == '(') {
            myStack.push(infix[i]);
        } else if(infix[i] == ')') {
            while(myStack.getTop() != '(') {
                posfix +=myStack.getTop();
                myStack.pop();
            }
            myStack.pop();
        } else {
            posfix +=infix
            [i];
        }
    }
    while (!myStack.isEmpty()) {
       posfix += myStack.getTop();
        myStack.pop();
    }
    myQueue.enqueue(posfix);
    cout << endl;
    cout << endl << "Infix algebraic expression: " << endl;
    cout<<infix<<endl<<endl;
    cout << "Postfix algebraic expression: " << myQueue.dequeue() << endl;
    return 0;
}

int priority (char a) {
    int sel;
    if (a=='^')
        sel=1;
    else  if(a=='*' || a=='/')
        sel=2;
    else  if(a=='+' || a=='-')
        sel=3;
    return sel;
}

bool isOperator(char a){
    if (a=='+' || a=='-' || a=='*' || a=='/' || a=='^'){
        return true ;
    }
    else {
        return false;
    }
}
