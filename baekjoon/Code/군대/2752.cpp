#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int x;
    vector<int> t;
    
    for(int i =0; i<3; i++)
    {
        cin >> x;
        t.push_back(x);
    }

    for(int i =1; i<3; i++)
    {
        for(int j=i; j>0; j--)
        {
            if(t[j]<t[j-1])
            {
                x=t[j];
                t[j]=t[j-1];
                t[j-1]=x;
            }
        }
    }

    for(int y:t)
    {
        cout << y << " ";
    }

    cout << endl;

    return 0;

}