#include <iostream>
#include <vector>

using namespace std;

int cache[501][501];

vector<int> t[501];

void init()
{
    for(int i =0; i<501; i++)
        for(int j=0; j<501; j++)
            cache[i][j] = -1;
}

int solve(int x, int y, int end)
{
    if(y>end)
        return 0;
    
    int &p = cache[y][x];

    if(p!=-1)
        return p;

    int ans1 = solve(x,y+1, end);
    int ans2 = solve(x+1, y+1, end);

    if(ans1<ans2)
        ans1 = ans2;

    return p = t[y][x] + ans1;
}

int main()
{
    init();
    int size;
    cin >> size;
    int num;
    for(int i=0; i<size; i++)
        for(int j=0; j<=i; j++)
        {
            cin >> num;
            t[i].push_back(num);
        }

    cout << solve(0,0,size-1) << "\n";
    
}