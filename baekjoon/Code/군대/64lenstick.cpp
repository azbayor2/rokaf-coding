#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n==64)
    {
        cout << 1<<endl;
        return 0;
    }
    int s = 64;
    int count =0;
    while(1)
    {
        if(s/2<=n)
        {
            n-=s/2;
            s=s/2;
            count++;
        }
        else
        {
            s=s/2;
        }

        if(n==0)
            break;

    }

    cout << count << endl;
    
}