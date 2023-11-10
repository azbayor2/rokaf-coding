#include "calc.h"


using namespace std;


/*
    원리:
        1. infix notation 을 postfix notation으로 바꾼다.
          - 이때 우선순위 고려
          - (), ^, * / %, + - 순으로 우선순위 우위를 가짐.

        2. postfix notion을 읽혀 계산함.

*/


void calculate()
{
    char temp;    //입력 저장 용
    double num;    //입력한 것이 숫자일 때 사용
    stack<char> oper;  //순서를 고려하여 postfix로 바꾸기 위해 연산자 저장용으로 사용
    stack<double> tempnum;    // "" (단, 이는 연산자가 아닌 숫자 저장)
    queue<token> t1; // postfix notation에서 숫자와 기호 저장 용도
    token *t;     //queue에 있는 값에 접근을 위한 포인터


    while(temp = cin.get())
    {
        switch(temp)

        {
            case OPEN:    // '('   
                oper.push(temp);    //우선순위가 제일 높으므로 oper에 저장.
                break;

            case CLOSE:         //괄호 안의 수식의 우선순위를 가장 높게 처리.
                while(oper.top()!=OPEN)
                {
                    t1.push(token(oper.top()));
                    oper.pop();
        
                }
                oper.pop();
                break;

            case POWER:    //두번째로 우선순위가 높음.
                oper.push(temp);
                break;

            case MULT: case DIVIDE: case REMAIN:   //세번째로 우선순위가 높음, stack에 우선순위가 높은 것과 낮은것 구분해서 처리.
                if(oper.size() ==0 || oper.top() == PLUS || oper.top() || MINUS || oper.top() == OPEN    //stack안의 연산자보다 우선순위가 높을 때 
                    || oper.top() == CLOSE)
                {
                    oper.push(temp);
                    break;
                }

                else
                {
                    while(oper.size() != 0 &&( oper.top() == POWER || oper.top() == MULT || oper.top() == DIVIDE
                            || oper.top() == REMAIN))     //stack안의 우선순위가 낮을 때
                    {
                        t1.push(token(oper.top()));
                        oper.pop();
        
                    }

                    oper.push(temp);
                    break;
                }

            case PLUS: case MINUS:   //우선순위가 가장 낮음.
                if(oper.size() == 0 || oper.top() == OPEN || oper.top() == CLOSE)
                {
                    oper.push(temp);
                    break;
                }

                while(oper.size() != 0 && (oper.top() == PLUS || oper.top() == MINUS || oper.top() == MULT   //stack안의 연산자보다 우선순위가 낮을 시.
                || oper.top() == DIVIDE || oper.top() == REMAIN || oper.top() == POWER))
                {
                    t1.push(token(oper.top()));
                    oper.pop();

                }

                oper.push(temp);
                break;


            case '\n':    //엔터 처리: stack 안에 있는 연산자를 저장 순서 역순으로 postfix notation 에 적용
                while(oper.size() >0)
                {
                    t1.push(token(oper.top()));
                    oper.pop();
                }
                break;

            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':  //양수 처리.
                cin.putback(temp);
                cin >> num;
                
                t1.push(token(num));
                break;

        }

        if(temp == '\n')    //엔터가 들어올 시 while 문 탈출
            break;


    }


    while(t1.size()>0)  //안에 토큰이 1개 이상일 때
    {
        t = &t1.front();     //t1안에 있는 토큰의 주소 반환.
        t1.pop();
        if(t->get() == true)   //토큰이 숫자일 때
        {
            tempnum.push(t->getnum());

        }

        else if(t->get() == false)  //토큰이 연산자일 때 계산 처리.
        {
            double right = tempnum.top();
            tempnum.pop();
            double left = tempnum.top();
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
                    left = (int)left%(int)right;
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

    while(input = cin.get())    //cin 사용 이유: 엔터(\n) 키도 토큰화 하기 때문
    {
        if(input == 'E')         //종결조건
        {
            cin.putback(input);
            string temp;
            cin >> temp;
            if(temp == "EOI")
                return 0;
        }

        else
        {
            cin.putback(input);   //그 외
            calculate();
        }
    }


    return 0;
}