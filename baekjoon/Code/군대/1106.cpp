#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> city;

int cache[10000];


int solve(int people, int cur_people)
{
    if(people<=cur_people)
        return 0;
    
    int &t = cache[people-cur_people];
    
    if(t!=0)
        return t;
    

    int temp;

    for(int i=0; i<city.size(); i++)
    {
        temp = solve(people, cur_people+city[i].second) + city[i].first;
        if(t==0 || temp < t)
            t=temp;
    }

    return t;
}

int main()
{
    int people, n, f, s;
    cin >> people >> n;
    

    for(int i =0; i<n; i++)
    {
        cin >> f >> s;
        city.push_back(pair<int,int>(f,s));
    }


    cout << solve(people,0) << "\n";

    return 0;
}