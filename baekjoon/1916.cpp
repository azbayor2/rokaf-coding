#include <iostream>
#include <vector>
#include <map>
#include <queue>
#define INF 2000000000

using namespace std;

map<int, int> m[1001];
int cache[1001];
vector<int> road[1001];

void init()
{
    for(int i =0; i<1001; i++)
    {
        cache[i] = INF;
    }

    return;
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

        if(cur_dist>cache[cur])
            continue;
        
        for(int i =0; i<road[cur].size(); i++)
        {
            int next = road[cur][i];
            int next_dist = cur_dist + m[cur][next];

            if(next_dist<cache[next])
            {
                q.push(make_pair(-next_dist, next));
                cache[next] = next_dist;
            }
        }
    }

    return;
}


int main()
{
    init();
    int city, num_road;
    cin >> city >> num_road;

    int start, end, time;

    for(int i=0; i<num_road; i++)
    {
        cin >> start >> end >> time;
        if(m[start].find(end)==m[start].end())
        {
            m[start][end] = time;
            road[start].push_back(end);
        }

        else
        {
            if(m[start][end] > time)
            {
                m[start][end] = time;
            }

        }
    }

    cin >> start >> end;

    solve(start);

    cout << cache[end] << "\n";

    return 0;
}
