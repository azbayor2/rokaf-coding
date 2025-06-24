#include <iostream>

using namespace std;

int cache[1001];

int solve(int n)
{
    int &p = cache[n];
    if(p!=0)
        return p;

    if(n==1)
        return p=1;

    if(n==2)
        return p=2;

    
    return p= (solve(n-1)+solve(n-2))%10007;
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;

    return 0;
}