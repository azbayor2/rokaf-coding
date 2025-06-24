#include <iostream>
#include <map>
#include <vector>

using namespace std;

int arr[51];
int truth_table[51];

int find(int a)
{
    if(arr[a]==a)
        return a;

    return arr[a] = find(arr[a]);
}

void mate(int a, int b)
{
    if(find(a)<find(b))
    {
        arr[find(b)] = find(a);
    }

    else if(find(a)>find(b))
    {
        arr[find(a)] = find(b);
    }

    return;
}


void init()
{
    for(int i =1; i<=50; i++)
        arr[i]=i;
}

int main()
{
    int people, party;
    cin >> people >> party;
    vector<int> v[party];

    int p1;
    int input;
    cin >> input;
    for(int i =0; i<input; i++)
    {
        cin >> p1;
        bool truth_table[p1]=1;
    }

    for(int i =0; i<party; i++)
    {
        cin >> input;
        for(int j =0; j<input; j++)
        {
            cin >> p1;
            v[i].push_back(p1);
        }

        for(int j =0; j<v[i].size()-1; j++)
        {
            mate(v[i][j], v[i][j+1]);
        }
    }

    int count =0; 

    for(int i =0; i<party; i++)
    {
        if(truth_table[findfr(v[i][0])]==0)
            count++;
    }

    cout << count << endl;
    return 0;
    
}