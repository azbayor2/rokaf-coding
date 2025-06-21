#include <iostream>
#include <queue>
#include <vector>
#define INF 400000000
using namespace std;

vector<int> path[801];
int dist[801][801];

int cache[801][801];

void init()
{
    for(int i =0; i<=800; i++)
    {
        for(int j =0; j<=800; j++)
            cache[i][j] = INF;
    }
}

void solve(int start)
{
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0,start));

    cache[start][start] = 0;

    while(q.size()!=0)
    {
        int cur = q.top().second;
        int cur_dist = -q.top().first;
        q.pop();

        if(cur_dist>cache[start][cur])
            continue;

        for(int i =0; i<path[cur].size(); i++)
        {
            int next = path[cur][i];
            int next_dist = cur_dist + dist[cur][next];

            if(next_dist<cache[start][next])
            {
                cache[start][next] = next_dist;
                q.push(make_pair(-next_dist, next));
            }
        }

    }
}


int main()
{
    int X, Y;
    cin >> X >> Y;
    int input1, input2, input3;

    init();

    for(int i =0; i<Y; i++)
    {
        cin >> input1 >> input2 >> input3;
        dist[input1][input2] = input3;
        dist[input2][input1] = input3;
        path[input1].push_back(input2);
        path[input2].push_back(input1);
    }

    int must1, must2;
    cin >> must1 >> must2;

    solve(1);
    solve(X);
    solve(must1);

    int ans1, ans2, l1, l2, l3, l4, l5;

    l1 = cache[1][must1];
    l2 = cache[1][must2];
    l3 = cache[must1][must2];
    l4 = cache[X][must2];
    l5 = cache[X][must1];

    if(((l1==INF || l4==INF) && (l2==INF || l5==INF)) || l3==INF)
    {
        cout << -1 << "\n";
        return 0;
    }

    ans1 = l1 + l3 + l4;
    ans2 = l2 + l3 + l5;

    if(ans1>ans2)
        ans1 = ans2;

    cout << ans1 << "\n";

    return 0;

}