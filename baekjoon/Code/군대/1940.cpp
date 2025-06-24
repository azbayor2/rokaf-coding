#include <iostream>
#include <algorithm>

using namespace std;

int arr[15001];
int N, M;

int main()
{
    cin >> N >> M;
    int s = 0, e = N-1;
    int cur = 0;
    
    for(int i =0; i<N; i++)
        cin >> arr[i];
    sort(arr, arr+N);
    
    int ans = 0;

    while(s<e)
    {
        cur = arr[s] + arr[e];
        if(cur==M)
        {
            ans++;
            e--;
            continue;
        }

        else if(cur>M)
        {
            e--;
            continue;
        }

        else if(cur<M)
        {
            s++;
            continue;
        }
    }

    cout << ans << "\n";

    return 0;
}