#include <iostream>
#include <vector>



using namespace std;

int solve(vector<int> & t, int n)
{
    int count1=0;
    int count2=0;
    float temp1, temp2;

    if(n>=1)
    {
        temp1 = t[n]-t[n-1];
        count1++;

        for(int i =n-2; i>=0; i--)
        {
            temp2=(float)(t[n]-t[i])/(n-i);
            if(temp2<temp1)
            {
                count1++;
                temp1=temp2;
            }
        }
    }


    if(n<=t.size()-2)
    {
        temp1 = t[n+1]-t[n];
        count2++;

        for(int i =n+2; i<t.size(); i++)
        {
            temp2=(float)(t[i]-t[n])/(i-n);
            if(temp2>temp1)
            {
                count2++;
                temp1=temp2;
            }
        }
    }

    return count1+count2;
}

int main()
{
    vector<int> m;
    
    int n;
    int temp;
    int temp2;
    cin >> n;
    for(int i =0; i<n; i++)
    {
        cin >> temp;
        m.push_back(temp);
    
    }
    temp = 0;

    for(int i =0; i<n; i++)
    {
        temp2 = solve(m, i);
        if(temp<temp2)
            temp = temp2;
    }

    cout << temp2 << endl;
    
}


