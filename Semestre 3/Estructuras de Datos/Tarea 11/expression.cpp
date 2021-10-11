#include "expression.h"

void Expression::setChar(const char & c) {
    character=c;
}

char Expression::getChar() {
    return character;
}

int Expression::getComp(char x, char y) {
    int prec1, prec2;
    switch(x){
    case '+':
        prec1=1;
        break;
    case '-':
        prec1=2;
        break;
    case '*':
        prec1=3;
        break;
    case '/':
        prec1=4;
        break;
    case '^':
        prec1=5;
        break;
    default:
        ;
    }
    switch(y){
    case '+':
        prec2=1;
        break;
    case '-':
        prec2=2;
        break;
    case '*':
        prec2=3;
        break;
    case '/':
        prec2=4;
        break;
    case '^':
        prec2=5;
        break;
    default:
        ;
    }
    return prec1-prec2;
}

bool Expression::getOperator(char character) {
    if(character == '+' || character == '-' || character == '*' ||character == '/'||character=='^') {
        return true;
    }
    return false;
}

bool Expression::getOp(char character) {
    if (!getOperator(character) && character != '(' && character != ')') {
        return true;
    }
    return false;
}
