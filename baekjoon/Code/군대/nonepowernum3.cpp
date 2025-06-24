#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

long long solve(long long x, long long y)
{
    long long end = sqrt(y);
    vector<long long> cache(end+1);  //-1 equals uninitialized
    for(long long i=0; i<=end; i++)
        cache[i] = -1;

    vector<long long> cache2;

    cache[0] = 0;
    cache[1]=0;
    cache[2] = 4;

    for(long long i =2; i<=end; i++)
    {
        if(cache[i]!=0) //	if i is PRIME NUM
        {
            cache[i]=i*i; //save power of prime num
            cache2.push_back(cache[i]);
        }

        for(long long j = i+1; j<=end; j+=i)
        {
            cache[j]=0;
        }



    }

    long long count = 0;

    for(long long i = x; i<=y; i++)
    {
        for(long long j=0; j<cache2.size(); j++)
        {
            if(i%cache2[j]==0)
            {
                count++;
                break;
            }
        }
    }
    
    return (long long)y-x+1-count;
    
}

int main()
{
    long long x, y;
    cin >> x >> y;
    cout << solve(x,y);

    return 0;
}