#include <iostream>
using namespace std;

typedef long long ll;
int N, K;
ll a,b,c,d;

ll gcd(ll l1, ll l2){
    while(l1%l2!=0){
        l1 = l1%l2;
        swap(l1, l2);
    }

    return l2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    cin >> a;
    for(int i =1; i<N; i++){
        cin >> b;
        a = a*b/gcd(a,b);
    }

    cin >> c;
    for(int i=1; i<K; i++){
        cin >> d;
        c = gcd(c,d);
    }

    // cout << a << " " << c << "\n";
    //D의 최소공배수, M의 최대공약수 구함

    if(c%a!=0){
        cout << 0 << "\n";
        return 0;
    }

    ll k = c/a;
    ll ans = 1;
    
    for(ll i = 2; i*i<=k; i++){
        if(k%i!=0) continue;
        ll count = 0;
        while(k%i==0){
            k/=i;
            count++;
        }

        ans*=(count+1);
    }
    
    if(k>1) ans*=2; // 소수가 남는 경우

    cout << ans << "\n";

    return 0;
}
