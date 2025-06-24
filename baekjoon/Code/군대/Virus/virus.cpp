#include "virus.h"


using namespace std;

puzzle::puzzle(int size)
{
    room_size = size;
    
    int temp;
    cin >> temp;

    num_active_virus = temp;
    num_total_virus = 0;

    for(int i =0; i<size*size; i++)
    {
        cin >> temp;
        
        if(temp == 0)
            room.push_back(EMPTY);

        else if(temp == 1)
            room.push_back(WALL);

        else if(temp == 2)
        {
            room.push_back(INACTIVE_VIRUS);
            num_total_virus++;
            virus_loc.push_back(i);
        }

        else
            break;
    }

    //cout <<"test1 complete" << endl;



}


void puzzle::solve()
{

    int total_calc_num = tgamma(num_total_virus +1) / tgamma(num_active_virus +1) / tgamma(num_total_virus - num_active_virus+1); //총 계산 횟수
    vector<int> temp;      //계산할 때 활성 바이러스 위치 저장
    vector<int> loc_loc;     //바이러스 위치의 위치 저장

    for(int i =0; i<num_active_virus; i++)   //처음 바이러스 경우의 수 저장하기
    {
        temp.push_back(virus_loc[i]);
        loc_loc.push_back(i);

    }

    cout <<"test2 complete" << endl;

    vector<int> init;  //기본 베이스
    vector<int> init_temp;   //실제 사용 벡터


    int t1;

    for(int y=0; y<room_size; y++)
        for(int x=0; x<room_size; x++)
        {
            t1 = output(x, y, room);

            if(t1 == EMPTY)
                init.push_back(0);

            else if(t1==INACTIVE_VIRUS)
                init.push_back(0);

            else if(t1 == WALL)
                init.push_back(WALL);

        }

     cout <<"test3 complete" << endl;

    int temp_cursor;
    int temp_cursor_offset = 0;
    int min_time;     //저장 시간
    int cal_time;     //계산 결과값

    for(int i =0; i<total_calc_num-1 ; i++)        //바이러스 조합 개수 만큼 for문
    {
        init_temp = init;
        
        for(int x=0; x<num_active_virus; x++)       //활성 바이러스로 바꿈
        {
            init_temp[temp[x]] = ACTIVE_VIRUS;
        }

        cal_time = calculate(init_temp);     //연산하기 

        cout <<"test x complete" << endl;    

        if(i=0)
        {
            min_time = cal_time;
        }

        

        else
            if(min_time > cal_time && cal_time != -1)
                min_time = cal_time;


        temp_cursor = num_active_virus -1;  //커서 설정

        while(1)
        {
            if(loc_loc[temp_cursor] < num_total_virus - temp_cursor_offset)
            {
                loc_loc[temp_cursor]++;

                while(++temp_cursor<num_active_virus)
                {
                    loc_loc[temp_cursor] = loc_loc[temp_cursor-1];
                }

                break;
            }

            else
            {
                if(loc_loc[0] == num_total_virus - num_active_virus)
                    break;

                temp_cursor--;
                temp_cursor_offset++;
            }
        }
    }

     cout <<"test4 complete" << endl;

    for(int x =0; x<num_active_virus; x++)
    {
        temp[x] = virus_loc[loc_loc[x]];

    }

    temp_cursor_offset = 0;
    temp_cursor = num_active_virus-1;






}


int puzzle::calculate(vector<int> &ptr)
{


    int count = 0;
    int temp_num, x_t, y_t;
    int count_zero = 0;

    for(int y=0; y<room_size; y++)   {        //검산
                for(int x=0; x<room_size; x++)
                {
                    cout << output(x,y,ptr) << " ";
                }

                cout << endl;

    }

    while(1)
    {

        for(int i =0; i<room_size*room_size; i++)
        {
            x_t = i%room_size;
            y_t = i/room_size;

            temp_num = output(x_t, y_t, ptr);
            
            if(count = 0)
            {
                if(temp_num == ACTIVE_VIRUS)
                {
                    input(x_t+1, y_t, 1, ptr);
                    input(x_t-1, y_t, 1, ptr);
                    input(x_t, y_t+1, 1, ptr);
                    input(x_t, y_t-1, 1, ptr);

                }

            }

            else if(temp_num == count)
            {

                input(x_t+1, y_t, count+1, ptr);
                input(x_t-1, y_t, count+1, ptr);
                input(x_t, y_t+1, count+1, ptr);
                input(x_t, y_t-1, count+1, ptr);

            }

    
        }

        count++;

        for(int y=0; y<room_size; y++)            //검산
                for(int x=0; x<room_size; x++)
                {
                    if(output(x,y,ptr) == 0)
                        count_zero++;
                }

        if(count_zero == 0)
            return count;

        else if(count >= room_size*2 -1)
            return -1;
        

       // cout << count_zero <<endl;
        
        count_zero ==0;


    }

}

void puzzle::input(int x_t, int y_t, int i, vector<int> &ptr)
{
    
    if(x_t>=room_size || x_t<0)
        return;

    if(y_t>=room_size || y_t<0)
        return;

    if(ptr[y_t*room_size + x_t] != 0)
        return;
    
    ptr[y_t*room_size + x_t] = i;
}


int puzzle::output(int x_t, int y_t, vector<int> &ptr)
{
    return ptr[y_t*room_size + x_t];
}