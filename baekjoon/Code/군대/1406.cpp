#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string x;
    cin >> x;
    int num;
    cin >> num;
    char input;
    stack<char> temp;

    for(int i=0; i<num; i++)
    {
        cin >> input;
        
        switch(input)
        {
            case 'L':
            {
                temp.push(x[x.size()-1]);
                x.erase(x.end()-1);
                break;
            }

            case 'D':
            {
                if(temp.size()==0)
                    break;
                x+=temp.top();
                temp.pop();
                break;
            }

            case 'B':
            {
                if(x.size()==0)
                    break;
                x.erase(x.end()-1);
                break;
            }

            case 'P':
            {
                cin >> input;
                x+=input;
                break;
            }
        }


    }

    if(temp.size()!=0)
        while(temp.size()!=0)
        {
            x+=temp.top();
            temp.pop();
        }

    cout << x << endl;

    return 0;
}