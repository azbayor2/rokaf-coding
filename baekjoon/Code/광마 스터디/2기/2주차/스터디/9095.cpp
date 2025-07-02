#include <iostream>

using namespace std;

int arr[11];   //캐시 배열

int dfs(int cur)
{
    if(cur<0) return 0;    //0보다 작으면 안되므로 0반환
    if(cur<=1) return 1;    //1, 0이면 더 이상 쪼개질 수 없으므로 1반환

    
    int &p = arr[cur];
    if(p!=0) return p;
    
    return p=dfs(cur-1) + dfs(cur-2) + dfs(cur-3);  //경우를 3개로 나누어 개수를 합해줌
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