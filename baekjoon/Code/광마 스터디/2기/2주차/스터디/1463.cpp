#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];  //캐시 배열

int dfs(int cur)  //현재 위치에서 1로 가는 최소 횟수를 구함
{
    int &p = arr[cur];  
    if(p!=0) return p;    //만약 cur 값의 답이 있으면 반환
    
    if(cur==1)      //1이면 이미 도착했으므로 0반환
        return 0;
    

    p = 10000000;   //n은 10^6 이므로 최악의 경우가 10^6을 넘지 않는다.

    if(cur%2==0) p = min(p, dfs(cur/2)+1);  //2로 나누어 질 때 최솟값 갱신
    if(cur%3==0) p = min(p, dfs(cur/3)+1);   //3으로 나누어 질 때 최솟값 갱신
    p = min(p, dfs(cur-1)+1);   //-1 했을 때 최솟값 갱신

    return p;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;

    cout << dfs(N) << "\n";

    return 0;
}