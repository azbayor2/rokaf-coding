#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

priority_queue<pair<ll, pair<int, int>>> q;  //우선순위 큐, {-거리, {점, k}} 를 저장
vector<pair<int, ll>> arr[10001]; // arr[a]에 {점, 그 점까지 거리} 를 저장
ll dist[21][10001];   //갱신한 거리  (dist[k][a]는 점 1부터 a까지 포장을 k번했을 때 최소거리)
int N, M, K;
ll MAX = 100000000000;  
ll ans = MAX;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    fill(dist[0], dist[21], MAX);  //거리 배열을 최댓값으로 초기화
    
    cin >> N >> M >> K;
    int a, b, c;
    
    for(int i =0; i<M; i++)
    {
        cin >> a >> b >> c;
        arr[a].push_back(make_pair(b, c));
        arr[b].push_back(make_pair(a, c));
    }
    
    q.push({0, {1, K}});  //초기값 넣기
    
    for(int i = 0; i<=K; i++)   //첫번째 점의 거리는 0으로 저장
        dist[i][1] = 0;
        
    while(q.size()!=0)
    {
        pair<ll, pair<int, int>> qcur = q.top();  //현재 방문하는 점
        q.pop();
        
        ll curdist = -qcur.first;  //현재 방문하는 점까지의 거리
        int cur = qcur.second.first;    //현재 방문하는 점
        int k = qcur.second.second;   //남아있는 포장 횟수
        
        if(cur==N) continue;   //현재 방문한 점이 N, 즉 목표 점일 때
        
        if(curdist>dist[k][cur]) continue;  //현재 방문한 점까지의 거리가 배열에 저장된것보다 길면
        
        for(pair<int, ll> nextp: arr[cur])  //인접한 점들을 모두 탐색
        {
            ll nextdist = curdist + nextp.second;  //다음 점까지 거리
            
            if(nextdist<dist[k][nextp.first])  //배열에 저장된 거리보다 더 짧으면
            {
                dist[k][nextp.first] = nextdist;
                q.push({-nextdist, {nextp.first, k}});  //다음 점 정보 우선순위 큐에 저장
            }
            
            if(k==0) continue;   //남아있는 압축횟수가 0일 때
            
            if(curdist<dist[k-1][nextp.first])  //다음점까지의 경로를 포장했을때 (거리를 0으로 처리)
            {
                dist[k-1][nextp.first] = curdist;
                q.push({-curdist, {nextp.first, k-1}});  //다음 점 정보 우선순위 큐에 저장
            }
        }
    }
    
    for(int i =0; i<=K; i++)
        ans = min(ans, dist[i][N]);  //1에서 N까지 포장을 고려한 최단거리 저장
        
    cout << ans << "\n";
    
    return 0;
}