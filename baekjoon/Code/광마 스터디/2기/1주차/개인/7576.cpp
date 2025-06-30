#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[1001][1001];
int move_x[4] = {0,1,0,-1};
int move_y[4] = {1,0,-1,0};
int total, riped;

queue<pair<pair<int, int>, int>> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> M >> N;
    for(int i =0; i<N; i++)
        for(int j =0; j<M; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j]!=-1)
                total++;

            if(arr[i][j]==1){
                q.push(make_pair(make_pair(j,i), 0));
                riped++;
            }
        }
        
    int ans = 0;

    while(q.size()!=0)
    {
        ans = q.front().second;
        int x = q.front().first.first;
        int y = q.front().first.second;
        q.pop();

        for(int i =0; i<4; i++)
        {
            int next_x = x+move_x[i];
            int next_y = y+move_y[i];

            if(next_x<0 || next_x>=M || next_y<0 || next_y>=N)
                continue;

            if(arr[next_y][next_x]==1 || arr[next_y][next_x]==-1) continue;

            arr[next_y][next_x]=1;
            riped++;
            q.push(make_pair(make_pair(next_x, next_y), ans+1));
        }
    }


    cout << (total==riped ? ans : -1) << "\n";

    return 0;
}

