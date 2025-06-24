#include "virus.h"


int main()
{
    int temp;
    while(cin >> temp)
    {
            if(temp!=0)
            {
                puzzle Puzzle(temp);
                Puzzle.solve();
                return 0;

            }

            else
                break;

    }

    return 0;

}