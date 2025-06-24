#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int x;
    cin >> x;
    vector<string> ans;
    string temp;
    int count =0;

    for(int i =0; i<x; i++)
    {
        cin >> temp;
        for(char t: temp)
        {
            if(t=='(')
                count++;

            else if(t==')')
                count--;

            if(count<0)
            {
                ans.push_back("NO");
                count=0;
                continue;
            }
        }

        if(count ==0)
        {
            ans.push_back("YES");
        }

        else
        {
            ans.push_back("NO");
        }

        count=0;
    }

    for(string t: ans)
    {
        cout << t << "\n";
    }

    return 0;
}