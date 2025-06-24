#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int arr[200001];

void init()
{
    for(int i=0; i<200001; i++)
        arr[i]=-1;

    return;
}


int solve(int x, int y)
{
    q.push(x);
    int temp;
    arr[temp]=0;

    while(1)
    {
        temp=q.front();

        if(temp==y)
        {
            return arr[temp];
        }

        if(temp>y)
        {
            if(arr[temp-1]!=-1)
            {
                arr[temp-1]=arr[temp]+1;
                q.push(temp-1);

            }

            continue;
        }

        if(arr[temp-1]!=-1)
        {
            arr[temp-1]=arr[temp]+1;
            q.push(temp-1);
        }

        if(arr[temp+1]!=-1)
        {
            arr[temp+1]=arr[temp]+1;
            q.push(temp+1);
        }

        if(arr[2*temp]!=-1)
        {
            arr[2*temp]=arr[temp];
            q.push(2*temp);
        }


    }

    return -1;
}


int main()
{
    int x, y;
    cin >> x>> y;

    init();

    cout << solve(x,y) << endl;

    return 0;
}