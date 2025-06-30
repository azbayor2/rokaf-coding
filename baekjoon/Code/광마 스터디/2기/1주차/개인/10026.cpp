#include <iostream>
#include <queue>

using namespace std;

string board[101];
bool visited[101][101];
bool visited2[101][101];
int ans1, ans2;
int N;
int move_x[4] = {0,1,0,-1};
int move_y[4] = {1,0,-1,0};

void bfs(int x, int y)
{
    visited[y][x] = 1;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));

    while(q.size()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        char cur = board[cur_y][cur_x];
        q.pop();
        
        for(int i =0; i<4; i++)
        {
            int next_x = cur_x+move_x[i];
            int next_y = cur_y+move_y[i];
            if(next_x<0 || next_x>=N || next_y<0 || next_y>=N) continue;

            if(visited[next_y][next_x]) continue;
            if(board[next_y][next_x]!=cur) continue;

            visited[next_y][next_x]=1;
            q.push(make_pair(next_x, next_y));
        }
    }

    ans1++;
}

void bfs2(int x, int y)
{
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited2[y][x] = 1;

    while(q.size()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        char cur = board[cur_y][cur_x]=='G'? 'R': board[cur_y][cur_x];
        q.pop();
        
        for(int i =0; i<4; i++)
        {
            int next_x = cur_x+move_x[i];
            int next_y = cur_y+move_y[i];
            if(next_x<0 || next_x>=N || next_y<0 || next_y>=N) continue;

            if(visited2[next_y][next_x]) continue;
            char next_visit = board[next_y][next_x]=='G'? 'R': board[next_y][next_x];
            
            if(cur!=next_visit) continue;

            visited2[next_y][next_x]=1;
            q.push(make_pair(next_x, next_y));
        }
    }

    ans2++;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i =0; i<N; i++)
        cin >> board[i];

    for(int i =0; i<N; i++)
    {
        for(int j =0; j<N; j++)
        {
            if(visited[i][j]==0){
                bfs(j,i);
            }

            if(visited2[i][j]==0) {
                bfs2(j,i);
            }
        }
    }

    cout << ans1 << " " << ans2;

    return 0;
}