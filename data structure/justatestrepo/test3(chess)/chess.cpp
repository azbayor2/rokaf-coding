#include "chess.h"


using namespace std;

/* 
    클래스 정의
*/


chessboard::chessboard(int size)    //크키를 받아서 체스판 생성
{
    board = new int[size*size + 1];
    chess_SIZE = size;
    for(int i =0; i<size*size ; i++)
        board[i] = UNSPECIFIED;
}

int chessboard::putqueen(chess input)    //여왕 대입 함수
{
    int x, y;

    x = input.returnx();
    y= input.returny();

   if(board[x+y*chess_SIZE]==UNSPECIFIED)
   {
        board[x+y*chess_SIZE] = SET_QUEEN;
   }

   else if(board[x+y*chess_SIZE] == NOT_ALLOWED)     //대입이 안될 경우 그냥 반환
   {
        return NOT_ALLOWED;
   }

    
    for(int i =0; i<chess_SIZE; i++)
    {
        if(i != x){
            board[i+y*chess_SIZE] = NOT_ALLOWED;   //x축으로 파견 안되는 위치 표기
        }

        if(i != y){
            board[x+i*chess_SIZE] = NOT_ALLOWED;   //y축으로 파견 안되는 위치 표기
        }
    }

    int cursorx, cursory;
    cursorx = x;
    cursory = y;

    while(1)        
    {
        if(cursorx==0 || cursory ==0)
            break;

        cursorx--;
        cursory--;

    }

    while(1)    //y=x 기울기 처리
    {
        if(cursorx != x)
        {
            board[cursorx + cursory*chess_SIZE] = NOT_ALLOWED;
        }
        
        if(cursorx ==chess_SIZE-1 || cursory==chess_SIZE-1)
            break;

        cursorx++;
        cursory++;
    }


    cursorx = x;
    cursory = y;

    while(1)
    {
        if(cursorx == chess_SIZE-1 || cursory ==0)
            break;

        cursorx++;
        cursory--;
    }


    while(1)    // y=-x 처리
    {
        if(cursorx != x)
        {
            board[cursorx + cursory*chess_SIZE] = NOT_ALLOWED;
        }

        if(cursorx==0 || cursory==chess_SIZE-1)
            break;
        
        cursorx--;
        cursory++;
    }

    return SET_QUEEN;

}


void chessboard::deletequeen(chess input)    //여왕 지우기 함수
{
    int x, y;

    x = input.returnx();
    y= input.returny();

    board[x+y*chess_SIZE] = UNSPECIFIED;

    for(int i =0; i<chess_SIZE; i++)
    {
        if(i != x){
            board[i+y*chess_SIZE] = UNSPECIFIED;   //x축으로 파견 안되는 위치 표기
        }

        if(i != y){
            board[x+y*chess_SIZE] = UNSPECIFIED;   //y축으로 파견 안되는 위치 표기
        }
    }

    int cursorx, cursory;
    cursorx = x;
    cursory = y;

    while(1)        
    {
        if(cursorx==0 || cursory ==0)
            break;

        cursorx--;
        cursory--;

    }

    while(1)    //y=x 기울기 처리
    {
        board[cursorx + cursory*chess_SIZE] = UNSPECIFIED;
        
        if(cursorx ==chess_SIZE-1 || cursory==0)
            break;

        cursorx++;
        cursory++;
    }


    cursorx = x;
    cursory = y;

    while(1)
    {
        if(cursorx == chess_SIZE-1 || cursory ==0)
            break;

        cursorx++;
        cursory--;
    }


    while(1)    // y=-x 처리
    {
        board[cursorx + cursory*chess_SIZE] = UNSPECIFIED;

        if(cursorx==0 || cursory==chess_SIZE-1)
            break;
        
        cursorx--;
        cursory++;
    }

    return;
}

void chessboard::reset()            //체스판 초기화 함수
{
    for(int i = 0; i<chess_SIZE*chess_SIZE ; i++)
    {
        board[i] = UNSPECIFIED;
    }
}


///////////////////////////////////////////////////////
/*

    기타 함수 정의

*/


int solve(int size)    //문제 푸는 알고리즘
{
    chessboard checkmate(size);   //체스판 생성
    stack<chess> queen_loc;   //여왕 위치 저장
    int solution = 0;
    chess * chess_ptr = NULL;
    

    for(int x=0; x<size ; x++)
    {
        chess_ptr = new chess(x,0);
        
        checkmate.putqueen(*chess_ptr);
        queen_loc.push(*chess_ptr);

        int cursory=1;   //y좌표
        int count = 0;    //실패 횟수 카운트
        int cursorx = 0;   //x 위치(커서)


        while(1)
        {
    

            if(checkmate.putqueen(chess(cursorx,cursory))!= NOT_ALLOWED)   //성공했을 때 
            {
                queen_loc.push(chess(cursorx, cursory));

                if(queen_loc.size() == size)   //size 개수 만큼 여왕을 채웠을 때
                {
                    solution++;
                    checkmate.reset();
                    queen_loc.empty();
                    cout << solution << endl; 
                    break;
                }

                cursory++;
                count = 0;
                continue;
            }

            else            //실패했을 때
            {
                count++;
                cursorx++;
            }
        

            if(count ==size)     //현재 행에 대한 모든 원소가 실패했을 떄
            {
                
                cursory--;  //이전으로 돌아가기
                chess * temp = &queen_loc.top();
                checkmate.deletequeen(*temp);   //이전 행의 여왕 지우기
                count = 0;    //실패 횟수 리셋
                cursorx=temp->returnx()+1;   //x좌표 +1 로 재설정
                queen_loc.pop();
    

                continue;

            }


        }


    }

    return solution;

}