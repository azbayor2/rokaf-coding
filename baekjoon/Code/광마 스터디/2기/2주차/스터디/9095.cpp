#include <iostream>

using namespace std;

int arr[11];



int dfs(int cur)
{
    if(cur<0) return 0;
    if(cur<=1) return 1;

    
    int &p = arr[cur];
    if(p!=0) return p;
    
    return p=dfs(cur-1) + dfs(cur-2) + dfs(cur-3);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, a;
    cin >> n;
    
    for(int i =0; i<n; i++)
    {
        cin >> a;
        cout << dfs(a) << "\n";
    }
    
    return 0;
}