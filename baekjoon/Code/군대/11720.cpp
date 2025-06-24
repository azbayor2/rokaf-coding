#include <iostream>

using namespace std;

int main()
{
    char c;
    int ans = 0;
    int n;

    cin >> n;

    for(int i =0;  i<n ;i++)
    {
        cin >> c;
        ans+=(int)(c-'0');
    }

    cout << ans << "\n";

    return 0;
}