#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> save(100);
    int x = 50;
    int temp;
    while(1)
    {
        if(temp==0)
            break;
        temp=x%10;
        save.push_back(temp);
        temp/=10;
    }

    x=49;

    while(1)
    {
        for(int i =0; i<ans.size(); i++)
            ans[i]*=x
    }

    for(int i =0; i<ans.size(); i++)
    {
        if(ans[i]>=10)
        {
            temp = ans[i]-(ans[i]%10);
            ans[i]%=10;
            ans[i+1]+=temp;
        }
    }
}