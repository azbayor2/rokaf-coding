#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool func(string a, string b)
{
    if(a.size()<b.size())
        return true;

    else if(a.size()>b.size())
        return false;

    else if(a.size()==b.size())
    {
        int cursor=0;
        while(cursor<=a.size())
        {
            if(a[cursor]<b[cursor])
                return true;

            else if(a[cursor]>b[cursor])
                return false;

            else if(a[cursor]==b[cursor])
                cursor++;

        }
    }

    return false;

}

int main()
{
    int n;
    cin >> n;

    vector<string> save;
    vector<string> ans;
    string temp;

    for(int i =0; i<n; i++)
    {
        cin >> temp;
        save.push_back(temp);
    }

    sort(save.begin(), save.end(), func);
    ans.push_back(save[0]);
    int cursor=0;

    for(int i =1; i<n; i++)
    {
        if(ans[cursor]!=save[i])
        {
            ans.push_back(save[i]);
            cursor++;
        }
    }

    for(string x:ans)
        cout << x << "\n";

    return 0;
}