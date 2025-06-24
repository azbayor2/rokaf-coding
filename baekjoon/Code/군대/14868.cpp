#include <iostream>
#include <queue>

using namespace std;

int world[2000][2000];
int save[100000];

int move_x[4] = {1,0,-1,0};
int move_y[4] = {0,-1,0,1};

struct civil
{
    int x;
    int y;
    int n;
};

queue<civil> q;

void init()
{
    for(int i =0; i<100000; i++)
    {
        save[i]=i;
    }

    for(int i =0; i<2000; i++)
        for(int j=0; j<2000; j++)
            world[i][j]=-1;

    return;
}

int find(int n)  //찾기 및 설정
{
    if(save[n]==n)
        return n;

    return find(save[n]);
}

void set(int x, int y) //설정
{
    int temp;
    x=find(x);
    y=find(y);

    if(x>y)
    {
        temp =x;
        x=y;
        y=temp;
    }

    save[y]=find(x);

    return;
}

int solve(int size, int city)
{
    int h=0;
    int time=0;

    for(h =0; h<city; h++) //찾기 및 새로고침
    { 
        if(find(h)!=0)
            break;      
	}

    if(h==city)
        return time;
    
   
    int x,y,n, temp, tx, ty;
    civil c;
    int z;

    while(1)
    {
        z=q.size();
        for(int i =0; i<z; i++)
        {
            c=q.front();
            q.pop();
            
            for(int j =0; j<4; j++) // 4방향으로 움직임
            {
                x=c.x+move_x[j];
                y=c.y+move_y[j];
                n= find(c.n);

                if(x>=0 && x<size && y>=0 && y<size) //범위 안에 있을 때
                {
                    if(world[y][x]==-1) //위치가 빈곳일 때
                    {
                        q.push({x,y,c.n});
                        world[y][x]=c.n;
                    }

                    for(int l=0; l<4; l++)
                    {
                        tx=x+move_x[l];
                        ty=y+move_y[l];

                        if(tx>=0 && tx<size && ty>=0 && ty<size)
                        {
                            if(world[ty][tx]!=-1)
                                set(world[ty][tx], c.n);
                        }  
                    }
                }
            }
        }

        time++;

        for(h =0; h<city; h++) //찾기 및 새로고침
        {
            if(find(h)!=0)
                break;
        }  

        if(h==city)
            return time;

    }  

    return 0;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    init();

    int size, n;
    cin >> size >> n;
    int x, y;
    int t_x, t_y;

    for(int i =0; i<n; i++)
    {
        cin >> x >> y;
        x-=1;
        y-=1;

        for(int j=0; j<4; j++)
        {
            t_x = x+move_x[j];
            t_y = y+move_y[j];

            if(t_x>=0 && t_x<size && t_y>=0 && t_y<size)        
            {

                if(world[t_y][t_x]!=-1)
                {
                    set(world[t_y][t_x], i);
                }
            }
        }

        q.push({x,y,i});
        world[y][x]=i;
    }

    cout << solve(size, n) << "\n";

    return 0;
}