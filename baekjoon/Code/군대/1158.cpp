#include <iostream>
#include <string>
using namespace std;

bool used[5001];

int main()
{
    int x, y;
    int temp=0;
    int count=0;
    cin >> x >> y;
    cout << "<";
    for(int i =0; i<x; i++)
    {
        if(i!=0)
            cout << ", ";
        
        while(count<3)
        {
            temp+=1;
            if(temp>x)
                temp%=x;

            if(!used[temp])
                count++;
        }

        count=0;
        cout<< temp;
        used[temp]=1;
    }    

    cout << ">";

    return 0;
}