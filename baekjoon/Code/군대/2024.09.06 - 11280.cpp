#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int group[20001];
bool grouped[20001];
int loc;
stack<int> s;
vector<int> path[20001];
int N, M;

int conv(int x)
{
    if(x>0)
        return x*2;
    return (-x)*2-1;
}

int scc(int x)
{
    group[x] = ++loc;
    int parent = group[x];
    s.push(x);

    for(int next: path[x])
    {
        if(group[next]==0)
            parent = min(parent, scc(next));
        else if(grouped[next]==0)
            parent = min(parent, group[next]);
    }

    grouped[x]=1;

    if(parent!=group[x]){
        return parent;
    }

    while(s.size()!=0)
    {
        group[s.top()]=parent;
        if(s.top()==x)
        {
            s.pop();
            break;
        }
        s.pop();
    }
    return parent;
}

int main()
{
    cin >> N >> M;
    int a, b;
    for(int i =0; i<M; i++)
    {
        cin >> a >> b;
        path[conv(-a)].push_back(conv(b));
        path[conv(-b)].push_back(conv(a));
    }

    for(int i =1; i<=2*N; i++)
    {
        if(grouped[i]==1)
            continue;
        scc(i);
    }

    for(int i =1; i<=N; i++)
    {
        if(group[i*2-1]==group[i*2])
        {
            cout << 0 << "\n";
            return 0;
        }
    }
    cout << 1 << "\n";

    return 0;

}