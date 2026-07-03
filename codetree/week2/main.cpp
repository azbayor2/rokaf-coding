#include <iostream>
using namespace std;

int min_ans = 1 << 30;     // 최솟값 저장
int max_ans = -(1 << 30);  // 최댓값 저장
int N;                     // 배열의 길이
int ops[4];                // 연산자 (+,-,* 순으로)
int arr[12];               // 입력된 수열을 저장

/** cur: 현재까지 계산된 값   depth: 현재 탐색하는 깊이 */
void dfs(int cur, int depth) {
  /** 만약에 탐색이 끝났으면 정답 갱신 */
  if (depth == N) {
    min_ans = min(min_ans, cur);
    max_ans = max(max_ans, cur);
    return;
  }

  /** 다음 노드 탐색 */
  for (int i = 0; i < 3; i++) {
    /** 만약에 현재 선택한 연산자의 남은 횟수가 없으면 넘어감 */
    if (ops[i] == 0) continue;

    ops[i]--;  // 사용했으므로 1 감소
    switch (i) {
        /** 덧셈 */
      case 0: {
        dfs(cur + arr[depth], depth + 1);
        break;
      }

      /** 뺄셈 */
      case 1: {
        dfs(cur - arr[depth], depth + 1);
        break;
      }

      /** 곱셈*/
      case 2: {
        dfs(cur * arr[depth], depth + 1);
        break;
      }
    }

    /** 재귀 호출이 끝나면 사용한 연산자 원상 복구 */
    ops[i]++;
  }
}

int main() {
  /** 입력 처리 */
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  for (int i = 0; i < 3; i++) cin >> ops[i];

  dfs(arr[0], 1);

  cout << min_ans << " " << max_ans << "\n";

  return 0;
}