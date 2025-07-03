#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> q1, q2;  // q1은 이제까지 받은 것의 절반만 저장
int N;                      //q2는 q1에 없는 값을 저장 (작은순으로 나열)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a;
    
    cin >> N;
    for(int i =0; i<N; i++)
    {
        cin >> a;
        if(q2.size() && -q2.top()<a)  //새로 들어온 값 a가 q2에 있는 수 중 가장 작은값보다 크면
        {
            q2.push(-a);   //a를 q2에 넣고, q2의 가장 작은 값은 a에 저장
            a = -q2.top();
            q2.pop();
        }
        
        q1.push(a);
        
        while(q1.size()>(i/2)+1)  //q1의 크기가 이제까지 넣은 개수 t에 대해 (t-1)/2+1보다 클때
		    {                         //다른 말로 q1의 top 값이 중간 이상일 때
            q2.push(-q1.top());   //그 값을 빼서 q2에 저장
            q1.pop();     
        }
        
        cout << q1.top() << "\n";   //중간 값 출력
    }
    
    return 0;
    
}