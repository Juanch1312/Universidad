#include "stack.h"
#include "queue.h"
#include <string.h>

using namespace std;

void postfix(char* p);
bool preference(char a, char b);

Stack<char> myStack;
Queue<string> myInfix;
Queue<string> myPostfix;

int main(){
    char expression[]="";
    cout << "Enter an algebraic expression: "<<endl;
    fflush(stdin);
    gets(expression);
    cout << endl << "Infix algebraic expression: " << endl;
    cout<<expression<<endl;
    cout << "Postfix algebraic expression: "<<endl;
    postfix(expression);
    myInfix.enqueue(expression);
    myPostfix.enqueue(expression);
    return 0;
}

void postfix(char* p){
    char PostFix[50];
    for(int i=0;i<strlen(p); i++){
        if(p[i]>=48 && p[i]<=57){
            cout << p[i];
            PostFix[i]=p[i];
            }
        else {
            if(myStack.isEmpty()==true){
                myStack.push(p[i]);
                }
            else {
                if(preference(myStack.getTop(),p[i])==true) {
                    myStack.push(p[i]);
                    }
                else {
                    while(myStack.isEmpty()==false && preference(myStack.getTop(),p[i])==false) {
                        cout << myStack.pop();
                        }
                    myStack.push(p[i]);
                    }
                }
            }
            myPostfix.enqueue(PostFix);
        }
    while(myStack.isEmpty()==false) {
        cout << myStack.pop();
        }
    cout << endl;
}

bool preference(char a, char b) {
    int p1, p2;
    switch(a) {
        case '^':
            p1=2;
            break;
        case '*':
        case '/':
            p1=1;
            break;
        case '+':
        case '-':
            p1=0;
            break;
        default:
            //Nothing
            ;
        }
    switch(b) {
        case '^':
            p2=2;
            break;
        case '*':
        case '/':
            p2=1;
            break;
        case '+':
        case '-':
            p2=0;
            break;
        default:
            //Nothing
            ;
        }
    if(p2>p1) {
        return true;
        }
    else {
        return false;
        }
}
