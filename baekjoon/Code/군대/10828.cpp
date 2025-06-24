#include <iostream>
#include <string>
#define POP 1
#define PUSH 2
#define TOP 3
#define SIZE 4
#define EMPTY 5


int arr[10000];
int arr_size;

using namespace std;

void init()
{
    for(int i=0; i<10000; i++)
        arr[i]=-1;

    arr_size=0;
    return;
}

int solve(int func, int n)
{
    switch(func)
    {
        case POP:
        {
            if(arr_size ==0)
                return -1;
            
            arr_size--;
            return arr[arr_size];
            
        }

        case EMPTY:
        {
            if(arr_size==0)
                return 1;
            return 0;
            
        }

        case PUSH:
        {
            arr[arr_size]=n;
            arr_size++;
            return 0;
        }

        case SIZE:
        {
            return arr_size;
        }

        case TOP:
        {
            if(arr_size==0)
                return -1;
            return arr[arr_size-1];
        }

    }

    return -1;
}

int main()
{
    int count;
    cin >> count;
    string x;
    char temp[10];
    int n;
    init();

    for(int i =0; i<count; i++)
    {
        scanf("%s", temp);
        x=temp;
        if(x=="PUSH")
        {
            cin >> n;
            solve(PUSH, n);
        }

        else if(x=="POP")
        {
            cout << solve(POP, 0); 
        }

        else if(x=="EMPTY")
        {
            cout << solve(EMPTY, 0);
        }

        else if(x=="SIZE")
        {
            cout << solve(SIZE,0);
        }

        else if(x=="TOP")
        {
            cout << solve(TOP,0);
        }
    }

    return 0;
}