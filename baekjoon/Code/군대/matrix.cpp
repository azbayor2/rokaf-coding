#include <iostream>
#include <vector>
#include <string>

using namespace std;

void change(vector<vector<bool>> &t, int i , int j)
{
    for(int x=i; x<=i+2; i++)
        for(int y=j; y<= j+2; j++)
        {
            t[x][y]=t[x][y]^1;
        }

    return;
}


int solve(vector<vector<bool>> & t, int n, int m)
{
    int count = 0;
    
    for(int i =0; i<n-2 ; i++)
    {
        for(int j =0; j<m-2; j++)
        {
            if(t[i][j]==1)
            {
                change(t,i,j);
                count++;
            }

            if(j==m-3)
            {
                if(t[i][j+1]==1 || t[i][j+2]==1)
                    return -1;
            }

        }

        if(i==n-3)
        {
            for(int x=i+1; x<n; x++)
                for(int y=0; y<m; y++)
                {
                    if(t[x][y]==1)
                        return -1;
                }
        }

    }

    return count;
}

int main()
{
    int n, m;
    string temp;
    cin >> n >> m;
    vector<string> t1(n);
    vector<string> t2(n);
    vector<<vector<bool>> t3(n);

    
    for(int i =0; i<n; i++)
    {
        cin >> temp;
        t1[i]=temp;

    }

    for(int i =0; i<n; i++)
    {
        cin >> temp;
        t2[i]=temp;
    }

    for(int i =0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(t1[i][j]==t2[i][j])
                t3[i].push_back(0);

            else
                t3[i].push_back(1);
        }

    
    cout << solve(t3, n, m) <<endl;
    
    return 0;
}
