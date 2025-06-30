#include <iostream>

using namespace std;

bool arr[129][129];
int N;

int blue, white;

bool checkcolor(int x, int y, int size)
{
    bool t = arr[y][x];
    
    for(int xx=x; xx<x+size; xx++)
        for(int yy=y; yy<y+size; yy++)
        {
            if(t!=arr[yy][xx]) return 0;
        }

    return 1;
}

int dfs(int x, int y, int size)
{
    if(size==1)
        return arr[y][x];

    if(checkcolor) return 1;

    int temp = size/2;

    return dfs(x, y, temp) + dfs(x+temp, y, temp) + dfs(x, y+temp, temp) + dfs(x+temp, y+temp, temp);
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j =0; j<N; j++)
            cin >> arr[i][j];

    cout << dfs(0,0,N) << "\n";

    return 0;
}