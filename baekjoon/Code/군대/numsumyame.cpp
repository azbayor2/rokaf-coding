#include <iostream>
#include <math.h>

using namespace std;

int ans[10];
int notans[10];

void solve(int n, int *ans)
{
    if(n<=0)
        return;
    
    int temp=1;
    int length=0;
    while(1)
    {
        if(n/temp < 10)
            break;
        length++;
        temp*=10;
    }
    int zero=0; int natural=0;
    
    for(int i =0; i<length; i++)
    {
        temp= 9*(int)pow(10,i-1)*i;
        zero+=temp;
        temp+=(int)pow(10,i);
        natural+=temp;
    }

    ans[0]+=zero;
    for(int i =1; i<10; i++)
        ans[i]=natural;

    int start = pow(10,length);
    int end = n;

    for(int i =0; i<=length; i++)
    {
        temp = ((end/10) - (start/10))*(int)pow(10,i);
        for(int j=0; j<10; j++)
            ans[j]+=temp;
        
        temp = (int)pow(10,i);
        for(int j=start%10; j<(end)%10; j++)
            ans[j]+=temp;
        
        temp = n%((int)pow(10,i));

        ans[end%10] += (temp+1);

        end/=10;
        start/=10;


    }

    
}





void init()
{
    for(int i =0; i<10; i++)
    {
        ans[i]=0;
        notans[i]=0;
    }

    

    return;
}


int main()
{
    init();
    int start, end;
    cin >> start >> end;

    if(start==0)
        ans[0]+=1;
    solve(start-1, notans);
    solve(end, ans);

    for(int i =0; i<10; i++)
        ans[i]-=notans[i];

    for(int x:ans)
        cout << x << " ";
    

    return 0;
}