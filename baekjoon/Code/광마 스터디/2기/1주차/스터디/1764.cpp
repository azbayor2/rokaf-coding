#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
string s;
vector<string> ss;

map<string,pair<bool,bool>> m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for(int i =0; i<N; i++)
    {
        cin >> s;
        m[s].first = 1;
    }
    
    for(int i=0; i<M; i++)
    {
        cin >> s;
        m[s].second=1;
    }
    
    for(auto p: m)
    {
        if(p.second.first==1 && p.second.second==1)
        {
            ss.push_back(p.first);
        }
    }
    
    sort(ss.begin(), ss.end());
    
    cout << ss.size() << "\n";
    
    for(string sss: ss)
    {
        cout << sss << "\n";
    }
    
    return 0;
    
}