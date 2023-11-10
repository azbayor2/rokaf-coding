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
    token(int t);
    token(char t);
    bool get();
    char getoper();
    int getnum();

    private:
    bool isdigit;
    int num;
    char oper;
};