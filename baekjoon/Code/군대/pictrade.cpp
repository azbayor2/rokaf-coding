#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[15][15];
int cache[15][2<<16][10];

int solve(int save, int price, int current, int people)
{
    int count = 0;
    int ans = 0;

    int &t = cache[current][save][price];
    if(t!=-1)
        return t;
    
    t=0;
    

    for(int i =0; i<people; i++)
    {
        if(i==current)
        {
            continue;
        }

        if(save&1<<i)
        {
            continue;
        }

        if(arr[current][i]<price)
        {
            continue;
        }
        
        count++;
        count +=solve(save|(1<<i), arr[current][i], i, people);
        if(t<count)
            t=count;

        count=0;   
    }

    return t;
}


int main()
{
    int n;
    cin >> n;
    for(int i =0; i<n; i++)
    {
        for(int j =0; j<n; j++)
            scanf("%1d", &arr[i][j]);
    }
    for(int i =0;i<15; i++)
        for(int j =0; j<(2<<16); j++)
            for(int k=0; k<10; k++)
                cache[i][j][k]=-1;

    cout << solve(1<<0, 0, 0, n) + 1 << endl;

}