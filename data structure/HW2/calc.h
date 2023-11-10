#include <iostream>
#include <cmath>
#include <stack>
#include <queue>

#define PLUS '+'
#define MINUS '-'
#define MULT '*'
#define DIVIDE '/'
#define REMAIN '%'
#define POWER '^'
#define OPEN '('
#define CLOSE ')'


class token
{

    public:
    token(double t);
    token(char t);
    bool get();
    char getoper();
    double getnum();

    private:
    bool isdigit;
    double num;
    char oper;
};