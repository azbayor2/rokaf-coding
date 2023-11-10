#include "calc.h"


using namespace std;


void calculate()
{
    char temp;
    int num;
    stack<char> oper;
    stack<int> tempnum;
    queue<token> t1;
    token *t;


    while(temp = cin.get())
    {
        switch(temp)

        {
            case OPEN:
                oper.push(temp);
                break;

            case CLOSE:
                while(oper.top()!=OPEN)
                {
                    t1.push(token(oper.top()));
                    oper.pop();
        
                }
                oper.pop();
                break;

            case POWER:
                oper.push(temp);
                break;

            case MULT: case DIVIDE: case REMAIN:
                if(oper.size() ==0 || oper.top() == PLUS || oper.top() || MINUS || oper.top() == OPEN
                    || oper.top() == CLOSE)
                {
                    oper.push(temp);
                    break;
                }

                else
                {
                    while(oper.size() != 0 &&( oper.top() == POWER || oper.top() == MULT || oper.top() == DIVIDE
                            || oper.top() == REMAIN))
                    {
                        t1.push(token(oper.top()));
                        oper.pop();
        
                    }

                    oper.push(temp);
                    break;
                }

            case PLUS: case MINUS:
                if(oper.size() == 0 || oper.top() == OPEN || oper.top() == CLOSE)
                {
                    oper.push(temp);
                    break;
                }

                while(oper.size() != 0 && (oper.top() == PLUS || oper.top() == MINUS || oper.top() == MULT
                || oper.top() == DIVIDE || oper.top() == REMAIN || oper.top() == POWER))
                {
                    t1.push(token(oper.top()));
                    oper.pop();

                }

                oper.push(temp);
                break;


            case '\n':
                while(oper.size() >0)
                {
                    t1.push(token(oper.top()));
                    oper.pop();
                }
                break;

            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                cin.putback(temp);
                cin >> num;
                
                t1.push(token(num));
                break;

        }

        if(temp == '\n')
            break;


    }


    while(t1.size()>0)
    {
        t = &t1.front();
        t1.pop();
        if(t->get() == true)
        {
            tempnum.push(t->getnum());

        }

        else if(t->get() == false)
        {
            int right = tempnum.top();
            tempnum.pop();
            int left = tempnum.top();
            tempnum.pop();

            switch(t->getoper())
            {
                case PLUS:
                   left+=right;
                   break;
                    
                case MINUS:
                    left-=right;
                    break;
                        
                case MULT:
                    left*=right;
                    break;
                        

                case DIVIDE:
                    if(right == 0){
                        cout << "error" << endl;
                        return;
                    }

                    else
                    left /= right;
                    break;

                case REMAIN:
                    left%=right;
                    break;

                case POWER:
                    left = pow(left, right);
                    break;


            }

            tempnum.push(left);
        }
    }        

    if(tempnum.size() ==1)
        cout << tempnum.top() << endl;

    else
    {
        cout << "error" << endl;
        return;
    }
}

int main()
{
    char input;

    while(input = cin.get())
    {
        if(input == 'E')
        {
            cin.putback(input);
            string temp;
            cin >> temp;
            if(temp == "EOI")
                return 0;
        }

        else
        {
            cin.putback(input);
            calculate();
        }
    }


    return 0;
}