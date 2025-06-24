#include <iostream>


using namespace std;


int solve(int N, int R, int C)
{
    int t = (1<<(N-1));

    int num = 0;
    int new_R = R;
    int new_C = C;

    if(R<t)
    {
        if(C<t)
            num = 0;

        else
        {    
            num = 1;
            new_C = C-t;
        }

    }

    else
    {
        new_R = R-t;

        if(C<t)
            num = 2;

        else
        {
            num = 3;
            new_C = C-t;
        }
    }

    if(N==1)
    {
        return num;
    }


    return (1<<(2*N-2))*num + solve(N-1, new_R, new_C);
}

int main()
{
    int n, c, r;
    cin >> n >> r >> c;

    cout << solve(n,r,c) << endl;

    return 0;

}