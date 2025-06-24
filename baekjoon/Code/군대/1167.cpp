#include <iostream>
#include <vector>


using namespace std;

vector<vector<pair<int,int>>> v;
int max_node;
int max_distance;

bool visited[100001];


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
        if(visited[v[start][i].first]==0)
            find_max(v[start][i].first, len+v[start][i].second+len);
    }

    visited[start] = 0;
}


int main()
{
    int num;
    cin >> num;
    vector<pair<int, int>> temp;

    int input1, input2;

    init();

    for(int i =1; i<=num; i++)
    {
        while(1)
        {
            cin >> input1;
            if(input1==-1)
                break;

            cin >> input2;

            temp.push_back(make_pair(input1-1, input2));
        }

        
    }

    find_max(0,0);

    find_max(max_node,0);

    cout << max_distance << endl;

    return 0;
    
}