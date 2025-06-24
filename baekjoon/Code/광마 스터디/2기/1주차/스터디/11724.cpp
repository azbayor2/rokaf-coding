#include <iostream>
#include <vector>


using namespace std;

int connected[1001];
vector<pair<int, int>> v;
int N, M;
bool visited[1001];

void init()
{
    for(int i=0;i<1001; i++)
    {
        connected[i] = i;
    }
    
    return;
}

int get_par(int a)
{
    if(connected[a]==a)
        return a;
        
    return connected[a] = get_par(connected[a]);
}

int connect_dfs(int a, int b)
{
    int aa = get_par(a);
    int bb = get_par(b);
    
    if(aa>bb)
        swap(aa,bb);
        
    connected[bb] = aa;
    
    return aa;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    init();
    
    cin >> N >> M;
    
    int a,b;
    
    for(int i =0; i<M; i++)
    {
        cin >> a >> b;
        connect_dfs(a,b);
    }
    
    for(int i =1; i<=N; i++)
    {
        get_par(i);
    }
    
    int ans=0;
    
    for(int i =1;i<=N; i++)
    {
        int temp = get_par(i);
        if(!visited[temp])
        {
            visited[temp] = 1;
            ans++;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
    
    
}