#include <iostream>
#include <vector>
using namespace std;

int cache[30][30];

int solve(int x, int y)
{
    int &t = cache[x][y];
    if(t!=-1)
        return t;

    int ans=0;
    for(int i =0; i<y-x+1; i++)
        ans+=solve(x-1,x-1+i);

    t=ans;

    return t;

}


int main()
{
    for(int i =1; i<30; i++)
        for(int j=1; j<30; j++)
        {
            if(i==j)
                cache[i][j] = 1;

            else if(i==1)
                cache[i][j]=j;

            else
                cache[i][j] = -1;
                
        }
    
    int x, n,m;
    cin >> x;
    vector<int> t;
    
    for(int i=0; i<x; i++)
    {
        cin >> n >> m;
        t.push_back(solve(n,m));
    }

    for(int w:t)
        cout << w << endl;

    return 0;
}