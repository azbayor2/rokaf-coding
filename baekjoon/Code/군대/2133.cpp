#include <iostream>

using namespace std;

int cache[31];

int solve(int n)
{
    if(n%2==1)
        return 0;

    int &p = cache[n];
    if(p!=0)
        return p;

    if(n==2)
        return p=3;

    else
    {
        p+=(3*solve(n-2) + 2);
        for(int i =4; i<=n-2; i+=2)
        {
            p+=(2*solve(n-i));
        }

        return p;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;

    return 0;
}