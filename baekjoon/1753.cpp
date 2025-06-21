#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define INF 3000001

using namespace std;

vector<int> path[20001];
map<int, int> dist[20001];

int cache[20001];

void init()
{
    for(int i =0; i<20001; i++)
        cache[i] = INF;
}

void solve(int start)
{
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0,start));
    cache[start] = 0;

    while(q.size()!=0)
    {
        int cur = q.top().second;
        int cur_dist = -q.top().first;

        q.pop();

        for(int i =0; i<path[cur].size(); i++)
        {
            int next = path[cur][i];
            int next_dist = cur_dist + dist[cur][next];

            if(next_dist<cache[next])
            {
                cache[next] = next_dist;
                q.push(make_pair(-next_dist, next));
            }
        }
    }
}

int main()
{
    int X, Y, start;
    cin >> X >> Y;
    cin >> start;
    int from, to, len;

    init();

    for(int i =0; i<Y; i++)
    {
        cin >> from >> to >> len;
        if(dist[from].find(to)==dist[from].end())
        {
            dist[from][to] = len;
            path[from].push_back(to);
        }

        else
        {
            if(dist[from][to] > len)
                dist[from][to] = len;
        }
    }

    solve(start);
    int ans;

    for(int i =1; i<=X; i++)
    {
        ans = cache[i];
        if(ans != INF)
            cout << ans << "\n";

        else
            cout << "INF" << "\n";
    }

    return 0;
}
