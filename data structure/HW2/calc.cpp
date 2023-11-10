#include "calc.h"

token::token(int t)
{
    isdigit = true;
    num =t;
}

token::token(char t)
{
    isdigit = false;
    oper = t;
}

bool token::get()
{
    return isdigit;
}

int token::getnum()
{
    return num;
}

char token::getoper()
{
    return oper;
}