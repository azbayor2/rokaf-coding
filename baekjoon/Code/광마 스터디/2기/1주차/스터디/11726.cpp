#include <iostream>

using namespace std;

short cache[1001];

short solve(short n)
{
    short &p = cache[n];
    if(p!=0)
        return p;

    if(n<=2 && n>=1)
        return p=n;
    
    return p= (short)(solve(n-1)+solve(n-2))%10007;
}

int main()
{
    short n;
    cin >> n;
    cout << solve(n) << endl;

    return 0;
}