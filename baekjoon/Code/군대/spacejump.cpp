#include <iostream>

using namespace std;

int solve(int x)
{
    int t=1;
    int cache[(1<<16)-1]; 

    while(1)
    {
        cache[t]=t*t;
        if(cache[t] > x)
            break;

        t++;
    }

    t--;

    x-=cache[t];

    if(x<=t)
        return 2*t;

    return 2*t+1;


}


int main()
{
    int t, x, y;
    cin >> t;

    for(int i =0; i<t; i++)
    {
        cin >> x >> y;
        cout << solve(y-x);
    }

    return 0;
}