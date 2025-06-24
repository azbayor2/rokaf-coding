#include <iostream>

using namespace std;

int main()
{
    float arr[1001];
    int N;
    float M=0;
    float ans = 0;

    cin >> N;
    
    for(int i =0; i<N; i++)
    {
        cin >> arr[i];
        M = max(M, arr[i]);
    }

    for(int i =0; i<N; i++)
    {
        arr[i] = (float)arr[i]/M*100;
        ans+=arr[i];
    }

    ans = (float)ans/N;

    cout << ans << "\n";

    return 0;
}