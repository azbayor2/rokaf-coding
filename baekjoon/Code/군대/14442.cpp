#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

using namespace std;

int cache[1000][1000][11];
vector<string> board;
int move_x[4] = {1, 0,-1,0};
int move_y[4] = {0,-1,0,1};

struct coord{
    int x;
    int y;
    int left;
    int dir;
};

queue<coord> save;

void init()
{
    for(int i =0; i<1000; i++)
        for(int j=0; j<1000; j++)
            for(int k =0; k<11; k++)
                cache[i][j][k]=-1;

    return;
}

int solve(int x, int y, int n)
{
    save.push({0,0,n,RIGHT});
    cache[0][0][n] = 1;
    
    int a, b, left, dir;
    int ans=-1;
    coord temp;

    while(save.size()>0)
    {
        temp = save.front();
        //cout << save.size() << endl;
        save.pop();
        dir = (temp.dir+2)%4;

        if(temp.x==x-1 && temp.y==y-1)
        {
            //cout << "test" << endl;
            return cache[temp.y][temp.x][temp.left];
        }
        for(int i =0; i<4; i++)
        {
            //if (i==dir)
              //  continue;

            a=temp.x + move_x[i];
            b=temp.y + move_y[i];
            left=temp.left;

            if(a>=0 && b>=0 && a<x && b<y)
            {
                //cout << "tt\n";
                if(board[b][a]=='1' && left>0 && cache[b][a][left-1]==-1)
                {
                    save.push({a,b,left-1, i});
                    cache[b][a][left-1]=cache[temp.y][temp.x][left]+1;
                    //cout << "x\n";
                }

                else if(board[b][a]=='0' && cache[b][a][left]==-1)
                {
                    save.push({a,b,left,i});
                    cache[b][a][left]=cache[temp.y][temp.x][left]+1;
                  //  cout << "y \n";
                }
            }
            
            //cout << "t \n";
        }
    }

    return ans;
}


int main()
{
    int x,y, left;
    string temp;
    cin >> y >> x >> left;
    for(int i =0; i<y; i++)
    {
        cin >> temp;
        board.push_back(temp);
    }
    
    

    init();
    cout << solve(x,y, left) << endl;

    return 0;
}

