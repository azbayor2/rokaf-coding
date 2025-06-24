#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    vector<int> t;
    cin >> n;
    for(int i =0; i<n; i++)
    {
        cin >> x;
        t.push_back(x);
    }


    for(int i =1; i<n; i++)
    {
        for(int j =i; j>0; j--)
        {
            if(t[j]>t[j-1])
                break;
            
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
        cout << y << endl;
    }

    return 0;
}