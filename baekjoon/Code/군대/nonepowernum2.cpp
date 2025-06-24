#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

long long solve(long long start, long long end)
{
    long long final = sqrt(end);
    vector<long long> cache;
    for(long long i =1; i<=final; i++)
        cache.push_back(i*i);

    long long count = 0;
    for(long long i = start; i<=end; i++)
    {
        for(long long j = 1; j<final; j++)
        {
            if(cache[j]>(long long)i/2)
            {
                if(i==1)
                    break;
                long long t = sqrt(i);
                if(t*t==i)
                    count++;
                break;
            }

            if(i%cache[j]==0)
            {
                count++;
                break;
            }
        }

    }

    return end-start+1-count;

}


int main()
{
    long long x, y;
    cin >> x >> y;

    cout << solve(x,y);

    return 0;
}