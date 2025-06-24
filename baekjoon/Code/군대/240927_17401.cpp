#include <iostream>

using namespace std;
typedef long long ll;

int T, N, D;
ll input[101][21][21];
ll leftt[21][21];  //calculate leftover
ll cycle[21][21];  //calculate a single cycle
ll calc_cycle[21][21];   //calculate multiple cycle
ll mod = 1000000007;

void init()
{
    cin >> T >> N >> D;
    int a, b, c, d;
    for(int i=0;i<T; i++)
    {
        cin >> a;
        for(int j=0; j<a; j++)
        {
            cin >> b >> c >> d;
            input[i][b][c] = d;
        }
    }
    return;
}

void get_cycle()
{
    int left_num = D%T;
    ll temp_arr[21][21];
    for(int i =1; i<=N; i++)
        cycle[i][i] = 1;

    for(int i =0; i<T; i++)
    {
        if(left_num==i)
        {
            for(int j=1; j<=N; j++)
                for(int k=1; k<=N; k++)
                    leftt[j][k] = cycle[j][k];
        }

        for(int j =1; j<=N; j++)
            for(int k=1; k<=N; k++)
            {
                ll calc = 0;
                for(int l=1; l<=N; l++)
                    calc+=(cycle[l][k]*input[i][j][l])%mod;
                temp_arr[j][j] = calc%mod;
            }
        for(int j =1; j<=N; j++)
            for(int k=1; k<=N; k++)
                cycle[j][k] = temp_arr[j][k];
    }

    

    return;
}

void calc(int n)
{
    if(n==1)
    {
        for(int i =1; i<=N; i++)
            for(int j =1; j<=N; j++)
                calc_cycle[i][j] = cycle[i][j];
        return;
    }
    calc(n/2);
    ll temp_arr[21][21];
    for(int i =1; i<=N; i++)
        for(int j =1; j<=N; j++)
        {
            ll ret = 0;
            for(int l=1; l<=N; l++)
                ret+=(calc_cycle[l][j]*calc_cycle[i][l])%mod;
            temp_arr[i][j] = ret%mod;
        }
    if(n%2==1)
    {
        for(int i =1; i<=N; i++)
            for(int j =1; j<=N; j++)
            {
                ll ret = 0;
                for(int l=1; l<=N; l++)
                    ret+=(temp_arr[l][j]*cycle[i][l])%mod;
                calc_cycle[i][j] = ret%mod;
            }
    }

    else
    {
        for(int i =1; i<=N; i++)
            for(int j =1; j<=N; j++)
                calc_cycle[i][j] = temp_arr[i][j];
    }

    return;
}

void solve()
{
    get_cycle();
    int count = D/T;
    calc(count);
    for(int i =1; i<=N; i++){
        for(int j =1; j<=N; j++)
        {
            ll ret = 0;
            for(int k=1; k<=N; k++)
                ret+=calc_cycle[k][j]*leftt[i][k];
            ret%=mod;
            cout << ret << " ";
        }
        cout << "\n";
    }

    cout << cycle[1][1] << leftt[1][1] << endl;

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    solve();
    return 0;
}