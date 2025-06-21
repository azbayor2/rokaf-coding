#include <iostream>
#include <map>

using namespace std;

map<long long , long long> cache;

long long solve(long long x, long long y, long long z)
{
    if(cache.find(y)!=cache.end())
        return cache[y];

    if(y==1)
    {
        cache[1] = x%z;
        return cache[1];
    }

    if(y%2==0)
    {
        cache[y] = (solve(x, y/2, z) * solve(x,y/2, z))%z;
        return cache[y];
    }

    else
    {
        cache[y] = (solve(x, y/2, z) * solve(x,(y/2)+1, z))%z;
        return cache[y];
    }

    return -1;
}


int main()
{
    long long x, y, z;

    cin >> x >> y >> z;
    cout << solve(x, y, z) << endl;

    return 0;

    
}

