#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>> n;
    string x;
    int t;
    queue<int> save;
    int last;

    for(int i =0; i<n; i++)
    {
        cin >> x;
        {
            if(x== "push")
            {
                cin >> t;
                save.push(t);
                last=t;
            }

            else if(x=="pop")
            {
                if(save.size()==0)
                {
                    cout << -1 << "\n";
                    continue;
                }
                save.pop();
                if(save.size()==0)
                    last=NULL;
                
            }

            else if(x=="size")
            {
                cout << save.size() << "\n";
            }

            else if(x=="emtpy")
            {
                cout << !(save.size()) << "\n";
            }

            else if(x=="front")
            {
                if(save.size()==0)
                {
                    cout << -1 << "\n";
                    continue;
                }

                cout << save.front() << "\n";
            }

            else if(x=="back")
            {
                if(save.size()==0)
                {
                    cout << -1 << "\n";
                    continue;
                }

                cout << last << "\n";
            }
        }
    }

    return 0;
}