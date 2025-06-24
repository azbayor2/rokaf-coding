#include <iostream>
#include <math.h>

using namespace std;


long long solve(unsigned long long x)
{
    long long count =0;
    
    long long temp = (long long)sqrt(x);
    if(x==temp*temp)
        return -1;

    long long mult=1;

    while(1)
    {
        temp = x- mult*mult;
        if(temp<2*mult)
            break;
        if(temp%(2*mult)==0)
            count++;

        mult++;
    }
    long long temp2, temp3;
    temp = x/2;
    temp = (long long)sqrt(temp);
    for(long long i =1; i<=temp; i++)
    {
        temp2 = x-i*i;
        temp3 = (long long)sqrt(temp2);
        if(temp2==temp3*temp3)
            count++;
    }

    return count;


}


int main()
{
    unsigned long long x;
    cin >> x;

    cout << solve(x) <<endl;

    return 0;



    
}