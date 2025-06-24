#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[51];
int arr[51];
bool visited[51];
int cn[51];
int N;
bool is_prime[2001];
vector<int> ans;
int selected;

void erathos()
{
    for(int i =2; i<=2000; i++)
        is_prime[i] = 1;

    for(int i =2; i<=2000; i++)
    {
        if(!is_prime[i]) continue;
        int cur = i*2;
        while(cur<=2000)
        {
            is_prime[cur] = 0;
            cur+=i;
        }
    }
    return;
}

void init()
{
    cin >> N;
    for(int i =0; i<N; i++)
        cin >> arr[i];
    erathos();
    for(int i =0; i<N; i++)
        for(int j =0; j<N; j++)
            if((i!=j) && is_prime[arr[i]+arr[j]]) v[i].push_back(j);
}

void reset_cn()
{
    for(int i =0; i<50; i++)
        cn[i] = -1;
    return;
}

void reset_visited()
{
    for(int i =0; i<50; i++)
        visited[i] = 0;
    return;
}

bool dfs(int cur)
{
    for(int next: v[cur])
    {
        if(visited[next]) continue;
        if(next == selected || next ==0) continue;
        visited[next] = 1;
        visited[cur] = 1;
        if(cn[next]==-1 || dfs(cn[next]))
        {
            cn[next] = cur;
            cn[cur] = next;
            return true;
        }
    }

    return false;
}

void solve()
{
    init();
    for(int i: v[0])
    {
        selected = i;
        reset_cn();
        cn[0] = selected; cn[selected] = 0;
        bool finished = 1;
        for(int j =1; j<N; j++)
        {
            if(cn[j]!=-1) continue;
            reset_visited();
            visited[0] = 1; visited[selected] = 1;
            if(!dfs(j))
            {
                finished=0;
                break;
            }
        }
        if(finished) ans.push_back(selected);
    }

    sort(ans.begin(), ans.end());

    if(ans.size()==0)
        cout << -1;

    else
        for(int cur: ans)
            cout << arr[cur] << " ";
    cout << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}