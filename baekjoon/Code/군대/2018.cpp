#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int a, b, cur=1;
    a = 1; b = 1;
    int ans = 0;
    while(a<=b && b<=N)
    {
        if(cur==N)
        {
            ans++;
            b++;
            cur+=b;
            continue;
        }

        else if(cur>N)
        {
            cur-=a;
            a++;
            continue;
        }

        else if(cur<N)
        {
            b++;
            cur+=b;
            continue;
        }
    }

    cout << ans << "\n";

    return 0;
    
}