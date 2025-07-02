#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int input[1000001];  //입력 값 저장
int sorted[1000001];  //입력 값 정렬용도
int N;
map<int, int> m;   //정답 저장 용도

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i =0; i<N ;i++)
    {
        cin >> input[i];
        sorted[i] = input[i];
    }

    sort(sorted, sorted+N);  //정렬

    int count = 0; //작은 수의 개수

    for(int i =0; i<N; i++)
    {
        if(m.find(sorted[i])!=m.end()) continue;   //작은수부터 그 수보다 작은 수의 개수를 저장한다
        m[sorted[i]] = count++;   //저장하면 현재 수보다 큰 수를 위해 +1을 한다
    }

    for(int i =0; i<N; i++)
        cout << m[input[i]] << " ";   // 답을 출력한다.

    return 0;
}