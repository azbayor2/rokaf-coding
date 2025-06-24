#include <iostream>
#include <map>
#define MAX 1000000007

using namespace std;

map<long long, long long> cache;

long long solve(long long input)
{
    if(input==0)
        return cache[0];

    else if(input==1)
        return cache[1];

    else if(input==2)
        return cache[2];

    
    if(cache.find(input)!=cache.end())
        return cache[input];

    if(input%2 == 0)
    {
        long long n1= (long long)solve((long long)input/2)%MAX;
        long long n2 = (long long)solve((long long)(input/2)-1)%MAX;

        long long ans = (long long)(n1+2*n2)%MAX;
        ans = (long long)(ans*n1)%MAX;

        return cache[input] = ans;
        
    }

    else
    {
        long long n1 = (long long)solve((long long)(input+1)/2)%MAX;
        long long n2 = (long long)solve((long long)(input-1)/2)%MAX;

        n1*=n1;
        n1%=MAX;

        n2*=n2;
        n2%=MAX;

        long long ans = (long long)(n1+n2)%MAX;

        return cache[input]= ans;
    }

    
}


int main()
{
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 1;

    long long input;
    cin >> input;

    cout << solve(input) << endl;
}
