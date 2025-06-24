#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;

vector<ll> v;
map<ll,ll> m;
bool not_prime[1000001];
ll N;

void init()
{
    not_prime[0] = 1; not_prime[1] = 1;
    for(int i =2; i<=1000000; i++)
    {
        if(not_prime[i]==1)
            continue;
        int next =i*2;
        while(next<=1000000)
        {
            not_prime[next]=1;
            next+=i;
        }
    }

    return;
}
void get_prime(ll x)
{
    if(x<=1000000)
    {
        if(not_prime[x]==0)
        {
            if(m.find(x)==m.end())
            {
                m[x] = 1;
                v.push_back(x);
            }
            else
                m[x]++;
            return;
        }
    }

    ll b = (ll)sqrt(x);
    for(int i =2; i<=b; i++)
    {
        if(x%i==0)
        {
            if(m.find(i)==m.end())
            {    
                m[i]=1;
                v.push_back(i);
            }
            else
                m[i]++;

            get_prime(x/i);
            return;
        }
    }
    
    if(m.find(x)==m.end())
    {
        m[x]=1;
        v.push_back(x);
    }
    else
        m[x]++;
    
    return;
}

ll GCD(ll n, ll power)
{
    ll ret=1;
    for(ll i=1; i<power; i++)
        ret*=n;
    return ret*n - ret;
}

int main()
{
    init();
    cin >> N;
    get_prime(N);
    ll ans =1;
    for(ll i: v)
        ans*=GCD(i, m[i]);
    if(N==1)
        ans=1;

    cout << ans << "\n";

    return 0;
}

