#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

queue<pair<ll, ll>> q;

ll N, M;
ll ans=-1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    
    q.push(make_pair(N, 1));
    
    while(q.size()!=0)
    {
        pair<ll,ll> p = q.front();
        q.pop();
        
        if(p.first==M){
            ans=p.second;
            break;
        }
        
        ll a1 = p.first*2;
        if(a1<=M)
            q.push(make_pair(a1, p.second+1));
            
        ll a2 = p.first*10+1;
        
        if(a2<=M)
            q.push(make_pair(a2, p.second+1));
    }
    
    
    cout << ans << "\n";
    
    return 0;
}