#include <iostream>
#include <string>
#include <stack>

using namespace std;

string solve(string input)
{
    int cur=0;
    string ans;
    stack<char> s;
    while(cur<input.size())
    {
        if(input[cur]>= 'A' && input[cur] <='Z')
        {
            ans+=input[cur];
            cur++;
            continue;
        }

        else if(input[cur]=='*' || input[cur]=='/')
        {
            while(s.size()!=0)
            {
                ans+=s.top();
                s.pop();
            }
            s.push(input[cur]);
            cur++;
            continue;
        }

        else if(input[cur]=='+' || input[cur]=='-')
        {
            if(s.size()==0 || s.top()=='+' || s.top() == '-')
            {
                while(s.size()!=0)
                {
                    ans+=s.top();
                    s.pop();
                }
                s.push(input[cur]);
                cur++;
                continue;
            }

            else if(s.top()=='*' || s.top() == '/')
            {
                while(s.size()!=0)
                {
                    ans+=s.top();
                    s.pop();
                }

                s.push(input[cur]);
                cur++;
                continue;
            }
        }

        else if(input[cur] == '(')
        {
            int count =1;
            string temp;
            cur++;
            while(1)
            {
                if(input[cur]=='(')
                {
                    count++;
                    temp+=input[cur];
                }

                else if(input[cur]==')')
                {
                    count--;

                    if(count ==0)
                    {
                        cur++;
                        break;
                    }

                    temp+=input[cur];
                }

                else
                {
                    temp+=input[cur];
                }
                cur++;
            }

            ans+=solve(temp);
        }
    }
    

    while(s.size()!=0)
    {
        ans+=s.top();
        s.pop();
    }

    return ans;
}




int main()
{
    string input;
    cin >> input;

    cout << solve(input) << "\n";

    return 0;
}