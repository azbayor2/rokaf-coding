#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int arr[1000001];
int arr_sort[1000001];
int N;
map<int, int> m;
queue<int> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i =0; i<N; i++){
        cin >> arr[i];
        arr_sort[i] = arr[i];
    }

    sort(arr_sort+N, arr_sort);

    for(int i =0; i<N; i++)
    {
        if(q.size()==0) {
            q.push(arr_sort[i]);
            continue;
        }

        if(q.front()==arr_sort[i]) continue;
        q.push(arr_sort[i]);
    }

    while(q.size()!=0)
    {
        m[q.front()] = q.size()-1;
        q.pop();
    }

    for(int i =0; i<N; i++)
    {
        cout << m[arr[i]] << " ";
    }

    return 0;

    
}