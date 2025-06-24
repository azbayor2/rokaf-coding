#include <iostream>

using namespace std;

long cache[100000][11];
long ans[10];

void init()
{
    for(int i=0; i<100000; i++)
    {    cache[i][10]=-1;

        for(int j = 0; j<10; j++)
            cache[i][j]=0;
    }

    for(int i=0; i<10; i++)
    {
        cache[i][i]=1;
        cache[i][10]=1;
    }
    

    for(int i =0; i<10; i++)
        ans[i]=0;
}

void solve(long n)
{
    if(n<100000&&cache[n][10]!=-1)
    {
        for(int i =0; i<10; i++)
            ans[i]+=cache[n][i];

        return;
    }


    if(n<100000)
    {
        cache[n][n%10]+=1;
        ans[n%10]+=1;
        solve(n/10);
        cache[n][10]=1;
        for(int i =0; i<10; i++)
            cache[n][i]+=cache[n/10][i];
        return;

    }

    else
    {
        solve(n%10);
        solve(n/10);
        return;
    }


    return;

}

int main()
{
    long x;
    cin >> x;
    
    init();
    for(int i=1; i<=x; i++)
        solve(i);

    for(int i =0; i<10; i++)
        cout << ans[i] << " ";

    return 0;
}