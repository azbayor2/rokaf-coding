#include <iostream>

using namespace std;

int tree[400001];
bool lazy[400001];
int N, M;

void init()
{
    cin >> N >> M;
    return;
}

void add_lazy(int start, int end, int node)
{
    tree[node] = (end-start+1)-tree[node];
    if(start==end)
        return;
    lazy[node*2+1] = (lazy[node*2+1] ? 0:1) ; lazy[node*2+2] = (lazy[node*2+2] ? 0:1);
    return;
}

void refresh_lazy(int start, int end, int node)
{
    if(lazy[node]==0)
        return;
    tree[node] = (end-start+1)-tree[node];
    lazy[node] = 0;
    if(start==end)
        return;
    lazy[node*2+1] = (lazy[node*2+1] ? 0:1) ; lazy[node*2+2] = (lazy[node*2+2] ? 0:1);
    return;
}

void refresh_tree(int start, int end, int node, int s, int e)
{
    refresh_lazy(start, end, node);
    if(start>e || end<s)
        return;
    if(start>=s && end <=e)
    {
        add_lazy(start, end, node);
        return;
    }

    int mid = (start+end)/2;
    refresh_tree(start, mid, node*2+1, s, e);
    refresh_tree(mid+1, end, node*2+2, s, e);
    tree[node] = tree[node*2+1]+tree[node*2+2];
    return;
}

int find_tree(int start, int end, int node, int s, int e)
{
    refresh_lazy(start, end, node);
    if(start>e || end<s)
        return 0;
    if(start>=s && end<=e)
        return tree[node];
    int mid = (start+end)/2;
    return find_tree(start, mid, node*2+1, s, e) +
            find_tree(mid+1, end, node*2+2, s, e);
}

void solve()
{
    init();
    int a, b,c;
    for(int i =0; i<M; i++)
    {
        cin >> a >> b >> c;
        if(a==0)
            refresh_tree(1, N, 0, b, c);

        else
            cout << find_tree(1, N, 0, b, c) << "\n";
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}