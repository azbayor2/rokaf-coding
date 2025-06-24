#include "chess.h"

void chess::queen_input(int x_t, int y_t)
{
    this->chess_check(x_t, y_t, QUEEN);

    for(int i =0; i<chess_size; i++)
    {
        int temp_status = this->chess_status(i, y_t);

        if(temp_status == QUEEN  || temp_status == QUEEN_ATTACK)
            continue;

        else
            this->chess_check(i, y_t, QUEEN_ATTACK);
    }


    for(int i =0; i<chess_size; i++)
    {
        int temp_status = this->chess_status(x_t, i);

        if(temp_status == QUEEN || temp_status == QUEEN_ATTACK)
            continue;

        else
            this->chess_check(x_t, i, QUEEN_ATTACK);
    }


    int cursor_x = x_t;
    int cursor_y = y_t;


    //y=x 방향

    if(x_t >= y_t)
    {
        cursor_x -= cursor_y;
        cursor_y = 0;

        for(cursor_x; cursor_x<chess_size; cursor_x++)
        {
            if(chess_status(cursor_x, cursor_y) == EMPTY)
                chess_check(cursor_x, cursor_y, QUEEN_ATTACK);
            cursor_y++;
        }
    }

    else
    {
        cursor_y -= cursor_x;
        cursor_x = 0;

        for(cursor_y; cursor_y<chess_size; cursor_y++)
        {
             if(chess_status(cursor_x, cursor_y) == EMPTY)
                chess_check(cursor_x, cursor_y, QUEEN_ATTACK);

            chess_check(cursor_x, cursor_y, QUEEN_ATTACK);
            cursor_x++;
        }


    }


    //y=-x 방향

    cursor_x = x_t;
    cursor_y = y_t;



    while(1)
    {
        if(cursor_y == 0 || cursor_x == chess_size-1)
            break;

        cursor_y--;
        cursor_x++;
    }

    int temp_status_2;
    
    while(1)
    {
        temp_status_2 = chess_status(cursor_x, cursor_y);
        if(temp_status_2 == EMPTY)
        {
            chess_check(cursor_x, cursor_y, QUEEN_ATTACK);

        }

        cursor_x--;
        cursor_y++;

        if(cursor_x < 0 || cursor_y>=chess_size)
            break;
        
    }
    




    //this->refresh();


}



void chess::king_input(int x_t, int y_t)
{
    if(king == false)
    {
        king_x = x_t;
        king_y = y_t;
        king = true;
    }

    else{
        cout << "king already exists, returning" << endl;
        return;
    }

    //this->refresh();

    return;
}

void chess::answer()
{
    int king_status = chess_status(king_x, king_y);
    int num_danger =0;

    int temp_y_1 = king_y - 1;
    int temp_y_2 = king_y;
    int temp_y_3 = king_y + 1;

    int temp_x = king_x-1;
    
    for(int i = 0 ; i<3 ; i++)
    {
        if(temp_y_1 < 0)
        {
            num_danger++;
        }

        else if(temp_x + i < 0 || temp_x + i >= chess_size)
        {
            num_danger++;
        }

        else if(chess_status(temp_x+i, temp_y_1) == QUEEN)
        {
            num_danger++;
        }

        else if(chess_status(temp_x+i, temp_y_1) == QUEEN_ATTACK)
        {
            num_danger++;
        }

        else
        {
            continue;
        }


    }



        for(int i = 0 ; i<3 ; i++)
    {
        
        if(temp_x + i < 0 || temp_x + i >= chess_size)
        {
            num_danger++;
        }

        else if(chess_status(temp_x+i, temp_y_2) == QUEEN)
        {
            num_danger++;
        }

        else if(chess_status(temp_x+i, temp_y_2) == QUEEN_ATTACK)
        {
            num_danger++;
        }

        else
        {
            continue;
        }


    }



        for(int i = 0 ; i<3 ; i++)
    {
        if(temp_y_3 >= chess_size)
        {
            num_danger++;
        }

        else if(temp_x + i < 0 || temp_x + i >= chess_size)
        {
            num_danger++;
        }

        else if(chess_status(temp_x+i, temp_y_3) == QUEEN)
        {
            num_danger++;
        }

        else if(chess_status(temp_x+i, temp_y_3) == QUEEN_ATTACK)
        {
            num_danger++;
        }

        else
        {
            continue;
        }


    }

    for(int i = 0; i<chess_size ; i++)
    {
        for(int j= 0;j<chess_size;j++)
        {
            cout << chess_status(j,i) << " ";
        }

        cout << endl;
    }

    cout << endl;


    if(king_status == QUEEN_ATTACK)
    {
        if(num_danger == 9)
        {
            cout << "CHECKMATE" << endl;
            return;

        }

        if(num_danger <9)
        {
            cout << "CHECK" << endl;
            return;
        }
    }

    if(king_status == EMPTY)
    {
        if(num_danger == 8)
        {
            cout << "STALEMATE" << endl;
            return;

        }

        else
        {
            cout << "NONE" << endl;
            return;
        }
    }


    cout << "error" << endl;
    

}

void chess::chess_check(int x_t, int y_t, int status)
{
    (*save)[y_t*chess_size + x_t] = status;
    return;
}

int chess::chess_status(int x_t, int y_t)
{
    return (*save)[y_t*chess_size + x_t];
}


void chess::refresh()
{
   /* if(king==false)
    {
        cout << "no king exists, returning" << endl;
        return;
    }

    int temp_y_1 = king_y -1;
    int temp_y_2 = king_y;
    int temp_y_3 = king_y + 1;

    int temp_x = king_x -1;

    

    for(int i =0; i< 3; i++)
    {
        if(temp_y_1<0)
            continue;

        if(temp_x+i <0 || temp_x+i >= chess_size)
        {
            continue;
        }

        if(chess_status(temp_x+i, temp_y_1) == QUEEN_ATTACK)
        {
            chess_check(temp_x+i, temp_y_1, KING_DANGER);
        }

    }

     for(int i =0; i< 3; i++)
    {
        if(temp_x+i <0 || temp_x+i >= chess_size)
        {
            continue;
        }

        if(chess_status(temp_x+i, temp_y_2) == QUEEN_ATTACK)
        {
            chess_check(temp_x+i, temp_y_2, KING_DANGER);
        }

    }

     for(int i =0; i< 3; i++)
    {
        if(temp_y_1>=chess_size)
            continue;

        if(temp_x+i <0 || temp_x+i >= chess_size)
        {
            continue;
        }

        if(chess_status(temp_x, temp_y_3) == QUEEN_ATTACK)
        {
            chess_check(temp_x, temp_y_3, KING_DANGER);
        }

    }

    
   */

    return;


}
