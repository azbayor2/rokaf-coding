#include <iostream>

using namespace std;

int seg_tree[800001];
int input[100001];
int N, M;
int MAX = 1000000001;


void init_tree(int start, int end, int node)  //구간 별로 최솟값 저장
{
    if(start==end)
    {
        seg_tree[node] = input[start];
        return;
    }
    
    int mid = (start+end)/2;
    init_tree(start, mid, node*2);
    init_tree(mid+1, end, node*2+1);
    
    seg_tree[node] = min(seg_tree[node*2], seg_tree[node*2+1]);
    
    return;
}

int find_ans(int start, int end, int a, int b, int node)   //최솟값 찾기
{
    if(start>=a && end<=b)   //현재 탐색 범위가 a, b 안에 있으면 저장된 최솟값 반환
        return seg_tree[node];
        
    if(end<a || start>b)
        return MAX;
        
    int mid = (start+end)/2;
    
    return min(find_ans(start, mid, a, b, node*2), find_ans(mid+1, end, a, b, node*2+1));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b;
    
    cin >> N >> M;
    
    for(int i =1; i<=N; i++)
        cin >> input[i];
        
    init_tree(1,N,1);
    
    for(int i =0; i<M; i++)
    {
        cin >> a >> b;
        cout << find_ans(1, N, a, b, 1) << "\n";
    }
    
    return 0;
}


