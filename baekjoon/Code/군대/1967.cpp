#include <iostream>
#include <vector>


using namespace std;

vector<pair<int,int>> v[10001];
int max_node;
int max_distance;

bool visited[10001];


void find_max(int start, int len)
{
    visited[start] = 1;

    if(len>max_distance)
    {
        max_distance=len;
        max_node=start;
    }

    for(int i =0; i<v[start].size(); i++)
    {
        int next1, next2;
        next1= v[start][i].first;
        next2= v[start][i].second;

        if(!visited[next1])
            find_max(next1, len+next2);
    }

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int num;
    cin >> num;

    int input0, input1, input2;

    for(int i =1; i<=num-1; i++)
    {
        cin >> input0; 
        cin >> input1;
        cin >> input2;
        v[input0-1].push_back(make_pair(input1-1, input2));
        v[input1-1].push_back(make_pair(input0-1, input2));
    
    }

    find_max(0,0);

    for(int i =0; i<num; i++)
        visited[i]=0;

    find_max(max_node,0);

    cout << max_distance << "\n";

    return 0;
    
}