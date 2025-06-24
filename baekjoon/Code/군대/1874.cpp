#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int x;
    cin >> x;
    int t;
    vector<int> save;
    string y = "+";
    while(cin>>t)
    {
        save.push_back(t);
    }

    int current=1;
    stack<int> temp;
    temp.push(current);
    for(int i: save)
    {
        while(temp.top()<i)
        {
            current++;
            temp.push(current);
            y+='+';
        }

        if(temp.top()==i)
        {
            y+='-';
            temp.pop();

        }

        else
        {
            cout << "NO" << endl;
            return 0;
        }

    }

    cout << y << endl;
    return 0;


}