#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long solve(long long start, long long end)
{
    vector<long long> cache(end-start+1);   //get space to save the answer
    for(long long i =0; i<cache.size(); i++)
        cache[i]=-1;

    long long temp = sqrt(end);
    long long powernum;
    long long temp2; 
    for(long long i =2; i<=temp; i++)
    {
        powernum = (long long)i*i;
        if(start%powernum==0)
            temp2=start;

        else
        {
            temp2 = start/powernum;
            temp2=(temp2+1)*powernum;
        }

        for(long long j=temp2; j<=end; j+=powernum)
            cache[j-start]=0;
    }

    long long count = 0;
    for(int i =0; i<cache.size(); i++)
        if(cache[i]==-1)
            count++;

    return count;
}

int main()
{
    long long x, y;
    cin >> x >> y;
    cout << solve(x,y);

    return 0;
}