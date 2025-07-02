#include <iostream>

using namespace std;

bool arr[129][129];  //보드
int N;
int blue, white;

bool checkcolor(int x, int y, int size)   //현재 탐색하는 부분이 모두 같은 색상인지 확인
{
    bool t = arr[y][x];
    
    for(int xx=x; xx<x+size; xx++)
        for(int yy=y; yy<y+size; yy++)
            if(t!=arr[yy][xx]) return 0;   //다른 색상이면 false 반환

    if(t==0) white++;   //흰색이면 흰색 개수 증가
    else blue++;       //파랑색이면 파랑색 개수 증가
    return 1;         //같은 색상이므로 true 반환
}

void get_ans(int x, int y, int size)
{
    
    if(checkcolor(x,y,size)) return;  //같은 색상이면 return
    
    if(size==1) return;

    int temp = size/2;

    get_ans(x, y, temp); get_ans(x+temp, y, temp); get_ans(x, y+temp, temp); get_ans(x+temp, y+temp, temp);  //현재 탐색 부분을 4등분

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j =0; j<N; j++)
            cin >> arr[i][j];

    get_ans(0,0,N);  //답 구하기
    
    cout << white << "\n" << blue;

    return 0;
}