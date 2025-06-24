#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >>n;
    int temp;
    string input;
    deque<int> save;

    for(int i =0; i<n; i++)
    {
        cin >> input;
        if(input=="push_back")
        {
            cin >> temp;
            save.push_back(temp);

        }
        else if(input=="back_front")
        {
            cin>>temp;
            save.push_front(temp);
        }

        else if(input=="pop_back")
        {
            if(save.size()==0)
            {
                cout << -1 <<"\n";
                continue;
            }

            cout << save.back() << "\n";

            
        }

        else if(input=="pop_front")
        {
            if(save.size()==0)
            {
                cout << -1 <<"\n";
                continue;
            }

            cout << save.front() << "\n";
        }

        else if(input=="size")
        {
            cout<< save.size() <<"\n";
        }

        else if(input=="front")
        {
            if(save.size()==0)
            {
                cout << -1 << "\n";
                continue;
            }

            cout << save.front() << "\n";
        }

        else if(input=="back")
        {
            cout << save.back() << "\n";
        }

        else if(input=="empty")
        {
            cout << !(save.size()) << "\n";
        }

        
    }

    return 0;

}