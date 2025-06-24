#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int board[101][101];
int N, M;
int cheese_count=0;

int mvx[4] = {1,0,-1,0};
int mvy[4] = {0,1,0,-1};

map<int, bool> loc[101];


int solve()
{
    int count = 1;
    queue<pair<int, int>> q;
    queue<pair<int, int>> del;
    
    while(cheese_count!=0)
    {
        count++;
        q.push(make_pair(1,1));
        board[1][1] = count;
        while(q.size()!=0)   //공기와 안 구분
        {
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            q.pop();

            for(int i =0; i<4; i++)
            {
                int next_x = cur_x+mvx[i];
                int next_y = cur_y+mvy[i];
                
                if(next_x<1 || next_x>M || next_y<1 || next_y>N ||
                board[next_y][next_x]==count || board[next_y][next_x]==1)
                    continue;
                    
                board[next_y][next_x] = count;
                q.push(make_pair(next_x, next_y));
                
            }
        }
        
        cout << 1<< endl;
        
        for(int i =1; i<=N; i++)
        {
            for(int j=1; j<=M; j++)
            {
                if(loc[i].find(j)==loc[i].end())
                    continue;
                int air = 0;
                    
                for(int k=0; k<4; k++)
                {
                    int next_x = j+mvx[k];
                    int next_y = i+mvy[k];
                    if(board[next_y][next_x]==count)
                        air++;
                }
                
                if(air>=2)
                    del.push(make_pair(j, i));
                    
            }
        }
        
        while(del.size()!=0)
        {
            board[del.front().second][del.front().first] = count;
            del.pop();
            cheese_count--;
        }
        
    }
    
    return count-1;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    int input;
    
    for(int i =1; i<=N; i++)
        for(int j =1; j<=M; j++)
        {
            cin >> input;
            board[i][j] = input;
            
            if(input==1)
            {
                loc[i][j] = 1;
                cheese_count++;
            }
        }
        
    cout << solve() << "\n";
    
    return 0;
}
