//2026

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int mvx[4] = {1,0,-1,0};
int mvy[4] = {0,1, 0,-1};
int cache[1000][1000][2];

vector<string> board;

struct coords{
    int x;
    int y;
    int left_num;
    int len;
};

int solve(int max_x, int max_y, int max_break)
{
    queue<coords> q;
    q.push({0,0,max_break,1});
    int cur_x, cur_y, left_break, next_x, next_y, curlen;
    char t;
    coords c;

    while(q.size()!=0)
    {
       c = q.front();
        q.pop();

        cur_x = c.x;
        cur_y = c.y;
        left_break = c.left_num;
        curlen = c.len;

        if(cur_x == max_x-1 && cur_y == max_y-1)
            return curlen;

        if(curlen>=max_x*max_y)
            continue;

        for(int i =0; i<4; i++)
        {
            next_x = cur_x+mvx[i];
            next_y = cur_y+mvy[i];
            if(next_x<0 || next_x>=max_x || next_y<0 || next_y>=max_y)
                continue;

            if(cache[next_y][next_x][left_break]!=0)
                continue;

            t = board[next_y][next_x];
            if(t == '0')
            {
                q.push({next_x, next_y, left_break,curlen+1});
                cache[next_y][next_x][left_break] = curlen+1;
            }

            else if(t == '1')
            {
                if(left_break==0)   
                    continue;

                q.push({next_x, next_y, left_break-1, curlen+1});
                cache[next_y][next_x][left_break-1] = curlen+1;
            }
        }
    }

    return -1;
}


int main()
{

    int x, y;
    string s;
    cin >> y >> x;

    for(int i =0; i<y; i++)
    {
        cin >> s;
        board.push_back(s);
    }

    cout << solve(x, y, 1) << "\n";
}