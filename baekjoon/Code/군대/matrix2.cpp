#include <iostream>
#include <vector>
#include <string>

using namespace std;

void change(vector<bool> &t, int n, int m, int x)
{
    int loc;
    for(int i=n; i<=n+2; i++)
        for(int j=m; j<=m+2; j++)
        {
            loc=x*n+m;
            t[loc]=t[loc]^1;
        }
}

int solve(vector<bool> &t, int n, int m)
{
    int count = 0;
    int loc;
    for(int i =0 ; i<=n-3; i++)
    {
        for(int j =0; j<=m-3; j++)
        {
            loc=i*m+j;
            if(t[loc]==1)
            {
                change(t, i, j, m);
                count++;
            }

        }

        if(t[i*m+m-2]==1 || t[i*m+m-1]==1)
            return -1
        
    }

    for(loc = (n-2)*m; loc<n*m; loc++)
    {
        if(t[loc]==1)
            return -1
    }
}

int main()
{
    int n ,m;
    cin >> n >> m;

    string t1, t2, temp;
    vector<bool> t3;

    for(int i =0; i<n; i++)
    {
        cin >> temp;
        t1.push_back(temp);
    }

    for(int i =0; i<n; i++)
    {
        cin >> temp;
        t2.push_back(temp);
    }

    for(int i =0; i<n*m; i++)
    {
        t3.push_back(!(t1[i]==t2[i]))
    }

    cout << solve(t3, n, m) << endl;

    return 0;
    
}