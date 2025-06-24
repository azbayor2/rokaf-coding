#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int classroom[21][21];
int student_like[401][3];
queue<int> q;

int mvx[4]={1,0,-1,0};
int mvy[4]={0,1,0,-1};
struct coord
{
    int x;
    int y;
    int like;
    int empty;
};

bool how(coord &c1, coord &c2)
{
    if(c1.like<c2.like)
        return false;

    else if(c1.like>c2.like)
        return true;

    else if(c1.empty<c2.empty)
        return false;

    else if(c1.empty>c2.empty)
        return true;
    else if(c1.y<c2.y)
        return true;
    else if(c1.y>c2.y)
        return false;
    else if(c1.x<c2.x)
        return true;
    else
        return false;
}

int solve(int size)
{
    int student;
    int temp1, temp2;
    vector<coord> v;

    for(int i =0; i<size*size; i++)
    {
        student=q.front();
        q.pop();

        for(int j =1; j<=size; j++)
            for(int k =1; k<=size; k++)//각 좌표 검사
            {
                temp1=0;
                temp2=0;
                if(classroom[j][k]!=0) //자리가 배정 되어 있으면 넘어가기
                    continue;

                int tx, ty;  //사방 좌표 저장
                for(int l=0; l<4; l++)
                {
                    tx=k+mvx[l];
                    ty=j+mvy[l];

                    if(tx<1 || tx>size || ty<1 || ty>size) //좌표 값 밖이면
                        continue;

                    int stu=classroom[ty][tx];
                    if(stu==0)  //빈칸이면
                        temp2++;
                    
                    else
                    {
                        for(int m=0; m<4; m++)//좋아하는 학생이 있으면
                        {
                            if(stu==student_like[student][m])
                            {
                                temp1++;
                                break;
                            }
                        }
                    }
                    
                }  

                v.push_back({k,j,temp1, temp2});
            }

        sort(v.begin(), v.end(), how);
        classroom[v[0].y][v[0].x]=student;
        v.clear();
    }

    for(int i=1; i<=size; i++)
    {
        for(int j =1; j<=size; j++)
            cout << classroom[i][j] << " ";
        cout << endl;
    }

    return 0;
}

int main()
{
    int size;
    cin >> size;

    int student, like;
    for(int i =0; i<size*size; i++)
    {
        cin >> student;
        for(int j=0; j<4; i++)
        {
            cin >> like;
            student_like[student][j]=like;
        }
        q.push(student);
    }

    cout << solve(size) << endl;

}