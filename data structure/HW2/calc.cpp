#include "calc.h"

token::token(double t)
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

double token::getnum()
{
    return num;
}

char token::getoper()
{
    return oper;
}