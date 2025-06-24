#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int lab[51][51];
int lab_time[51][51];

int mvx[4]={1,0,-1,0};
int mvy[4]={0,1,0,-1};

int least_time=2500;
int num_wall=0;
bool success=false;

vector<int> sel;

struct coord
{
    int x;
    int y;
};

vector<coord> virus_loc;
queue<coord> q;

void init()
{
    for(int i =1; i<=50; i++)
        for(int j =1; j<=50; j++)
            lab_time[i][j]=-1;
}

void solve(int size, int num_virus, int start)
{
    if(sel.size()<num_virus)
    {
        for(int i =start+1; i<virus_loc.size(); i++)
        {
            sel.push_back(i);
            solve(size, num_virus, i);
            sel.pop_back();
        }

        return;
    }


    init();

    int set_num=0;

    for(int i =0; i<sel.size(); i++)//okay
    {
        lab_time[virus_loc[sel[i]].y][virus_loc[sel[i]].x] = 0;
        
        for(int j =0; j<4; j++)
        {
            int mx = virus_loc[sel[i]].x+mvx[j];
            int my = virus_loc[sel[i]].y+mvy[j];

            if(mx>=1 && mx<=size && my>=1 && my<=size && lab[my][mx]!=1 &&
            lab_time[my][mx]==-1)
            {
                q.push({mx, my});
                lab_time[my][mx]=1;
            }
        }
    }
    

    int time = 1;
    coord tc;
    int tx, ty;

    while(q.size()!=0)
    {
        time++;
        
        int qsize = q.size();
        for(int i =0; i<qsize; i++)
        {
            tc = q.front();
            q.pop();

            for(int j=0; j<4; j++)
            {
                tx=tc.x+mvx[j];
                ty=tc.y+mvy[j];

                if(tx>=1 && tx<=size && ty>=1 && ty<=size && lab[ty][tx]!=1 &&
                lab_time[ty][tx]==-1)
                {
                    q.push({tx,ty});
                    lab_time[ty][tx]=time;
                }

            }
        }
    }

    time=0;


    for(int i=1; i<=size; i++)
        for(int j=1; j<=size; j++)
        {
            if(lab_time[i][j]!=-1)
            {
                set_num++;
                if(lab_time[i][j]>time)
                    time=lab_time[i][j];
            }
        }

    if(time<least_time && (set_num+num_wall)==size*size)
    {
        least_time=time;
        success=true;
    }

    return;

}


int main()
{
    int size, num_virus;
    cin >> size >> num_virus;

    int input;

    for(int i =1; i<=size; i++)
    {
        for(int j=1; j<=size; j++)
        {
            cin >> input;
            lab[i][j]=input;
            
            if(input==2)
                virus_loc.push_back({j,i});

            else if(input==1)
                num_wall++;
        }
    }
    

    solve(size, num_virus, -1);

    if(success==true)
        cout << least_time<< "\n";

    else
        cout << -1 << "\n";
    
    return 0;
}

