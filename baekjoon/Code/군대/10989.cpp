#include <iostream>

using namespace std;

int ans[10001];

int main()
{
    int n;
    scanf("%d",&n);


    /*for(int i =0; i<=10000; i++)
        ans[i]=0;
                */

    int input;

    for(int i =0; i<n; i++)
    {
        scanf("%d",&input);
        ans[input]++;
    }

    for(int i =0; i<=10000; i++)
    {
        for(int j =0; j<ans[i]; j++)
            printf("%d\n", i);
    }


    return 0;
}