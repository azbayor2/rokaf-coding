#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool been[26];
vector<string> board;
int max_num = 0;

int mvx[4] = {1,0,-1,0};
int mvy[4] = {0,1,0,-1};

void solve(int count, int x, int y)
{
    if(max_num<count)
        max_num = count;

    for(int i =0; i<4; i++)
    {
        int new_x = x + mvx[i];
        int new_y = y + mvy[i];

        if(new_x<0 || new_x>=board[0].size() || new_y<0 || new_y>=board.size())
            continue;

        char t = board[new_y][new_x];
        if(been[(int)t-'A'] == 1)
            continue;
        
        been[(int)t-'A'] = 1;
        solve(count+1, new_x, new_y);
        been[(int)t-'A'] = 0;
        
    }

    return;
}

int main()
{

    int Y, X;
    cin >> Y >> X;
    string input;

    for(int i =0; i<Y; i++)
    {
        cin >> input;
        board.push_back(input);
    }

    been[board[0][0] - 'A'] = 1;
    solve(1, 0, 0);

    cout << max_num << "\n";

    return 0;
}