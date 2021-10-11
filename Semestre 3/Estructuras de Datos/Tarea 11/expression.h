#ifndef EXPRESSION_H_INCLUDED
#define EXPRESSION_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>

class Expression {
private:
    char character;

public:
    void setChar(const char &);
    char getChar();
    int getComp(char , char);
    bool getOperator(char);
    bool getOp(char);

};

#endif // EXPRESSION_H_INCLUDED
