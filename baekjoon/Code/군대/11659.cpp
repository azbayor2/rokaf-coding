#include <iostream>

using namespace std;

int arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, M, a, b;
    cin >> N >> M;
    int temp;

    for(int i =1; i<=N; i++)
    {
        cin >> temp;
        arr[i]=arr[i-1]+temp;
    }

    for(int i =0; i<M; i++)
    {
        cin >> a >> b;
        cout << arr[b]-arr[a-1] << "\n";
    }

    return 0;
}