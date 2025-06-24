#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    vector<long long> ans;
    long long t;
    int x;

    cin >> x;

    for(int i =0; i<x; i++)
    {
        cin >> t;
        ans.push_back(t);
    }

    sort(ans.begin(), ans.end());

    long long u = ans[0];
    long long j = ans[x-1];


    cout << u*j << endl;


    return 0;
}