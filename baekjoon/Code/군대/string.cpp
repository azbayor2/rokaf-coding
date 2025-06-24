#include <iostream>
#include <string>

using namespace std;

string solve(vector<string> &t, int n)
{
    string ans = t[0];
    for(int i =0; i<ans.size(); i++)
    {
        for(int j=1; j<n; j++)
        {
            if(ans[i]!=t[j][i])
            {
                ans[i]='?';
                break;
            }
        }
    }

    return ans;
}


int main()
{
    int n;
    cin >> n;

    vector<string> t;
    string temp;
    for(int i =0; i<n; i++)
    {
        cin >> temp;
        t.push_back(temp);
    }

    cout << solve(t, n) << endl;
}