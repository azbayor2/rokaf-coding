#include <iostream>
using namespace std;

typedef long long ll;

ll a, d, T, l, m, k;

ll sum(ll N){
    if(N==0) return 0;

    ll ret = a*N;
    ret+=(N*(N-1))/2*d;

    return ret;
}

ll gcd(ll left, ll right){
    if(right==0) return left;
    while(left%right!=0){
        left = left%right;
        swap(left, right);
    }

    return right;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> a >> d >> T;

    for(int i =0; i<T; i++){
        cin >> l >> m >> k;

        switch(l){
            case 1:{
                cout << sum(k) - sum(m-1) << "\n";
                break;
            }

            case 2: {
                cout << (m==k? a+(m-1)*d : gcd(a+(m-1)*d, d)) << "\n";
                break;
            }
        }
    }

    return 0;
}

