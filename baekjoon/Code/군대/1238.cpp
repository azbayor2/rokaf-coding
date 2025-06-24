#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000001;

using namespace std;

int dist[2][1001];
int dirto[1001][1001];
vector<int> wayto[1001];
vector<int> wayfrom[1001];

void init()
{
    for(int i =0; i<=1000; i++)
    {
        dist[0][i]=INF;
        dist[1][i]=INF;
    }

    return;
}

void solve(int start)
{
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0,start));
    dist[0][start] = 0;
    dist[1][start] = 0;

    while(q.size()!=0)
    {
        int cur_len = -q.top().first;
        int cur = q.top().second;
        q.pop();

        if(cur_len>dist[0][cur])
            continue;

        for(int i =0; i<wayto[cur].size(); i++)
        {
            int next = wayto[cur][i];
            int next_len = cur_len+dirto[cur][next];

            if(next_len<dist[0][next])
            {
                dist[0][next] = next_len;
                q.push(make_pair(-next_len, next));
            }
        
        }
    }

    q.push(make_pair(0, start));

    while(q.size()!=0)
    {
        int cur = q.top().second;
        int cur_len = -q.top().first;
        q.pop();

        if(cur_len>dist[1][cur])
            continue;

        for(int i =0; i< wayfrom[cur].size(); i++)
        {
            int bef = wayfrom[cur][i];
            int bef_len = cur_len + dirto[bef][cur];

            if(bef_len<dist[1][bef])
            {
                dist[1][bef] = bef_len;
                q.push(make_pair(-bef_len, bef));
            }
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int N, M , X;
    cin >> N >> M >> X;
    int input1, input2, input3;

    for(int i =0; i<M; i++)
    {
        cin >> input1 >> input2 >> input3;
        dirto[input1][input2] = input3;
        wayto[input1].push_back(input2);
        wayfrom[input2].push_back(input1);
    }

    solve(X);
    

    vector<int> sum;

    for(int i =1; i<=N; i++)
    {
        sum.push_back(dist[0][i]+dist[1][i]);
    }

    sort(sum.begin(), sum.end());

    cout << sum[sum.size()-1] << "\n";

    return 0;
}   