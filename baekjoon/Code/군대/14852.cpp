#include <iostream>
#define LEFT 1000000007

using namespace std;

int cache1[4];
int cache2[4];

int solve(int n)
{
    if(n==1 || n==2)
        return cache1[n];

    for(int i =3; i<=n; i++)
    {
        cache1[i%4] = 2*cache2[(i-1)%4] + cache1[(i-1)%4] + 2;
        cache1[i%4]%=LEFT;
        cache2[i%4]=cache2[(i-1)%4]+cache1[i%4];
        cache2[i%4]%=LEFT;
    }

    return cache1[n%4];
}

int main()
{
    int n;
    cin >> n;
    cache1[1]=2;
    cache1[2]=7;
    cache2[1]=2;
    cache2[2]=9;
    cout << solve(n) << endl;

    return 0;
}