#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{    
    int n, x;
    int arr[1000001];
    cin >> n;
    
    for(int i =0; i<n; i++)
    {
        cin >> x;
        arr[i]=x;
    }
    
    sort(arr, &arr[n]);
    
    for(int i =0; i<n; i++)
        cout << arr[i] << endl;
    
    return 0;
}