#include <iostream>

using namespace std;

typedef long long ll;

ll n, k;
ll mod = 1000000007;
ll fact[4000001];

void init()
{
    fact[0] = 1; fact[1] = 1;
    for(int i =2; i<=4000000; i++)
        fact[i] = (fact[i-1]*i)%mod;
}

ll power(ll bottom, ll top)
{
    if(top==1) return bottom;
    
    ll ret = power(bottom, top/2)%mod;
    ret = (ret*ret)%mod;
    return (top%2) ? (bottom*ret)%mod: ret; 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    cin >> n >> k;
    ll top = fact[n];
    ll bottom_t = (fact[k]*fact[n-k])%mod;
    ll bottom = power(bottom_t, mod-2);
    
    cout << (top*bottom)%mod << "\n";
    
    return 0;
}