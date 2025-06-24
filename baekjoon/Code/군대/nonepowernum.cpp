#include <iostream>
#include <vector>

using namespace std;

long long solve(long long start, long long end)
{
    long long last = 1;
    vector<long long> cache;
    while(1)
    {
        long long temp = (long long)last*last;
        cache.push_back(temp);
        if(end-temp <=last*2)
            break;

        last++;

    }
    long long count =0;
    for(long long i =start; i<=end ; i++)
    {
        for(long long loc =1; loc<cache.size(); loc++)
        {
            if(i%cache[loc] ==0)
            {
                count++;
                break;
            }
        }
    }

    	return (long long)end-start+1-count;
}
    

int main()
{
    long long x, y;
    cin >> x >> y;
    cout << solve(x,y);

    return 0;
}
    