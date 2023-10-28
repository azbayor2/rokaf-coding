#include <iostream>
#include <vector>
#include <stack>

#define SET_QUEEN 1
#define NOT_ALLOWED 2
#define UNSPECIFIED 0
#define FINISHED 10


using namespace std;


class chess   
{
    public:
    chess(int a, int b)
    :x{a}, y{b}
    {};

    int returnx()
    {
        return x;
    };

    int returny()
    {
        return y;
    };


    private:
    int x;     //x좌표 저장
    int y;     //y좌표 저장
};

class chessboard
{
    public:
    chessboard(int size);    //크키를 받아서 체스판 생성
    ~chessboard()
    {
        delete [] board;
    }
    
    int putqueen(chess input);    //여왕 대입
    void deletequeen(chess input);
    void reset();

    private:
    int * board;    //체스판 포인터
    int chess_SIZE;
    int queennum = 0;


};



int solve(int size);

