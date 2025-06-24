#include <iostream>
#include <vector>

using namespace std;

vector<int> cost[1001];
int cache[1001][3];

int solve(int cur, int before, int max)
{
    if(cur==max)
        return 0;
    
    int &p = cache[cur][before];
    if(p!=0)
        return p;

    int least = 10000001;
    int ans;

    for(int i =0; i<3; i++)
    {
        if(i==before)
            continue;

        ans = cost[cur][i] + solve(cur+1, i, max);
        if(ans<least)
            least = ans;
    }

    return p = least;
}

int main()
{
    int num;
    cin >> num;
    int temp;

    for(int i =0; i<num; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin >> temp;
            cost[i].push_back(temp);
        }
    }

    int n=10000000;
    int ans;

    for(int i =0; i<3; i++)
    {
        ans = cost[0][i]+solve(1,i,num);
        if(n>ans)
            n=ans;
    }

    cout << n << "\n";

    return 0;
}