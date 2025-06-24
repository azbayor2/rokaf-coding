#include <iostream>


using namespace std;


int bottle(int n, int k)
{
    
    int x=0;
    while(1)
    {
        int t = 1<<x;
        if(t>=n)
            break;

        x++;
    }

    if(k==1 || n==(1<<x))
    {
        return (1<<x) - n;
    }

    x--;
    
    return bottle(n-(1<<x), k-1);
}


int main() 
{

    int n, k;


    cin >> n >> k;

    if(n<1 || k<1 || n>10000000 || k>1000)
    {
        cout << -1 <<endl;
        return -1;
    }

    cout << bottle(n,k)<<endl;

    return 0;

    



}