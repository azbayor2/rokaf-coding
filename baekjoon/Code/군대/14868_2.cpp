#include <iostream>
#include <queue>

using namespace std;

int world[2000][2000];
int save[100001];

int move_x[4] = {1,0,-1,0};
int move_y[4] = {0,-1,0,1};

int city_num;

struct civil
{
    int x;
    int y;
    int n;
};

queue<civil> q;

void init()
{
    for(int i =0; i<=100000; i++)
    {
        save[i]=i;
    }

    return;
}

int find(int n)  //찾기 및 설정
{
    if(save[n]==n)
        return n;

    return save[n]= find(save[n]);
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
    if(x==y)
        return;

    save[y]=find(x);
    city_num--;


    return;
}

int solve(int size, int city)
{
    int time=0;   
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

            if(world[c.y][c.x]==-1)
                world[c.y][c.x] = c.n;
            
            for(int j =0; j<4; j++) // 4방향으로 움직임
            {
                x=c.x+move_x[j];
                y=c.y+move_y[j];
                n= c.n;

                if(x>=0 && x<size && y>=0 && y<size) //범위 안에 있을 때
                {
                    if(world[y][x]==-1) //위치가 빈곳일 때
                    {
                        q.push({x,y,c.n});
                    }

                    else if(world[y][x]!=-1)
                        set(world[y][x], n);
                }
            }
        }

        if(city_num==1)
            return time;
        
        time++;
        


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

    city_num = n;

    for(int i =0; i<n; i++)
    {
        cin >> x >> y;
        x-=1;
        y-=1;

        q.push({x,y,i+1});
    }

    cout << solve(size, n) << "\n";

    return 0;
}