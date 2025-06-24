#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool func(string a, string b)
{
    if(a.size()<b.size())
        return true;

    else if(a.size()>b.size())
        return false;

    else if(a.size()==b.size())
    {
        int x=0, y=0;
        int cursor=0;

        while(cursor<a.size())
        {
            if(a[cursor]>='0' && a[cursor]<='9')
                x+=((int)a[cursor]-48);

            if(b[cursor]>='0' && b[cursor]<='9')
                y+=((int)b[cursor]-48);

        }

        if(x<y)
            return true;
        else if(x>y)
            return false;

        else if(x==y)
        {
            cursor=0;
            while(cursor<a.size())
            {
                if(a[cursor]<b[cursor])
                    return true;
                else if(a[cursor]>b[cursor])
                    return false;
                else if(a[cursor]==b[cursor])
                    cursor++;
            }
        }
    }

    return false;
}


int main()
{
    int n;
    scanf("%d", &n);

    string temp;
    vector<string> ans;

    for(int i =0; i<n; i++)
    {
        scanf("%s",temp);
        ans.push_back(temp);
    }

    sort(ans.begin(), ans.end(), func);

    for(string x: ans)
        printf("%s\n", x);


    return 0;
}