#include <iostream>
#include <vector>

using namespace std;

vector<int> child[51];
int del_node;
int N;
int Root;

int dfs(int cur)
{
    if(cur==del_node) return 0;

    if(child[cur].size()==0)
        return 1;

    if(child[cur].size()==1)
    {
        for(int next: child[cur])
        {
            if(next==del_node)
                return 1;
        }
    }

    int ret = 0;

    for(int next: child[cur])
        if(next!=del_node)
            ret+=dfs(next);

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    int n;
    for(int i =0; i<N; i++)
    {
        cin >> n;
        if(n==-1){
            Root = i;
            continue;
        }

        child[n].push_back(i);
    }

    cin >> del_node;

    cout << dfs(Root) << "\n";

    return 0;
}
