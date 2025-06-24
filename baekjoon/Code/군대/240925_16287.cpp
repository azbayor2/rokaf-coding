#include <iostream>
#include <algorithm>

using namespace std;
int arr[5001];
bool is_in[800001];
int N, M;

void init()
{
    cin >> N >> M;
    for(int i =0; i<M; i++)
        cin >> arr[i];

    sort(arr, arr+M);
}

void solve()
{
    for(int i =0; i<M; i++)
    {
        for(int j=0; j<i; j++)
        {
            int cur = N - (arr[i] + arr[j]);
            if(cur<=0)
                continue;

            is_in[cur] =1;
        }

        for(int j = i+2; j<M; j++)
        {
            int cur_c = arr[i+1]+arr[j];
            if(is_in[cur_c]==1)
            {
                cout << "YES" << "\n";
                return;
            }
        }
    }

    cout << "NO" << "\n";
    return;
}

int main()
{
    init();
    solve();
    return 0;
}