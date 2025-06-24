#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string temp, ans;
    char t;
    stack<char> save;
    bool is_open=0;

    while((t=cin.get())!='\n')
    {
        if(t=='<')
        {
            is_open=1;
            while(save.size()!=0)
            {
                ans+=save.top();
                save.pop();
            }
            ans+=t;
            continue;
        }

        if(is_open==0 && t!=' ')
        {
            save.push(t);
            continue;
        }

        if(is_open==0 && t==' ')
        {
            while(save.size()!=0)
            {
                ans+=save.top();
                save.pop();
            }

            ans+=' ';
            continue;
        }

        if(is_open==1)
        {
            ans+=t;
            if(t=='>')
                is_open=0;
            continue;
        }
        
    }

    while(save.size()!=0)
    {
        ans+=save.top();
        save.pop();
    }

    cout << ans << "\n";

    return 0;

}