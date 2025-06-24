#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    char temp;
    vector<string> save;
    string t="";
    stack<char> s;

    for(int i=0; i<n; i++)
    {
        while((temp=cin.get()) != '\n')
        {
            if(temp == ' ')
            {
                while(s.size()>0)
                {
                    t+=s.top();
                    s.pop();
                }

                t+=" ";
            }

            else if(temp !=' ')
            {
                s.push(temp);
            }
        }

        while(s.size()>0)
        {
            t+=s.top();
            s.pop();
        }

        save.push_back(t);
        t="";
    }

    for(string x: save)
    {
        cout << x << endl;
    }

    return 0;
}