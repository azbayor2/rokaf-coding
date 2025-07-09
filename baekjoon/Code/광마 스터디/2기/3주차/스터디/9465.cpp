#include <iostream>

using namespace std;

int T, N;
int arr[2][100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    
    for(int i =0; i<T; i++)
    {
        cin >> N;
        
        for(int j=0; j<2; j++)
            for(int k=1; k<=N; k++)
                cin >> arr[j][k];
                
        int cache[2][100001] = {0,};
        
        cache[0][1] = arr[0][1];
        cache[1][1] = arr[1][1];
        
        for(int k =2; k<=N; k++)
            for(int j =0; j<2; j++)
                cache[j][k] = max(arr[j][k]+cache[(j+1)%2][k-2], arr[j][k]+cache[(j+1)%2][k-1]);
                
        cout << max(cache[0][N], cache[1][N]) << "\n";
    }
    
    return 0;
}