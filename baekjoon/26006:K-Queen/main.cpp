#include <iostream>
#include <vector>
#include "chess.h"


using namespace std;

int main()
{
    string input1;

    while(cin)
    {
        int size, queen_num;

        cin >> size >> queen_num;
        chess Chess(size);

        int q_x, q_y;


        cin >> q_x >> q_y;

        Chess.king_input(q_x-1, q_y-1);

        for(int i =0; i< queen_num; i++)
        {
            cin >> q_x >> q_y;
            Chess.queen_input(q_x-1, q_y-1);
        }

        Chess.answer();
    }

    return 0;




}
