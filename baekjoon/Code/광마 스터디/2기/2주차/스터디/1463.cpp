#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];

int dfs(int cur)
{
    int &p = arr[cur];
    if(p!=0) return p;
    
    if(cur==1)
        return 0;
    

    int a1 = 100000000;
    int a2 = 100000000;
    int a3 = 100000000;

    if(cur%2==0) a1 = min(a1, dfs(cur/2)+1);
    if(cur%3==0) a2 = min(a2, dfs(cur/3)+1);
    a3 = min(a3, dfs(cur-1)+1);

    return p=min(a1,min(a2, a3));
}


int main()
{
    int N;
    cin >> N;

    cout << dfs(N) << "\n";

    return 0;
}