#include "calc.h"

using namespace std;

int main()
{
    queue<token> t1;
    t1.push(token(10));

    token *t = &t1.front();

    cout << t->getnum() << endl;

    return 0;




}