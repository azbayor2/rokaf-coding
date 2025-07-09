#include <iostream>
#include <vector>

using namespace std;

vector<string> board;
bool visited[27];
int ans = 0;

int move_x[4] = {0,1,0,-1};
int move_y[4] = {1,0,-1,0};

int N, M;

void dfs(int x, int y, int count)
{
    visited[board[y][x]-'A'] = 1;
    ans = max(ans, count);
    for(int i =0; i<4; i++)
    {
        int nextx = x+move_x[i];
        int nexty = y+move_y[i];
        
        if(nextx>=M || nextx<0 || nexty>=N || nexty<0)
            continue;
            
        if(visited[board[nexty][nextx]-'A']) continue;
        
        dfs(nextx, nexty, count+1);
    }
    
    visited[board[y][x]-'A'] = 0;
}

int main()
{
    cin >> N >> M;
    for(int i =0; i<N; i++)
    {
        string s;
        cin >> s;
        board.push_back(s);
    }
    
    dfs(0,0,1);
    
    cout << ans << "\n";
    
    
    return 0;
}