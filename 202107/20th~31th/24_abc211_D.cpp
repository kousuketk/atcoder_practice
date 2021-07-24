#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int N, M; cin >> N >> M;
  Graph G(N);
  rep(i,M) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  // 根を0としてbfs(深さ優先探索)
  vector<int> dist(N, -1);
  queue<int> que;
  dist[0] = 0;
  que.push(0);
  while(!que.empty()) {
    int v = que.front(); que.pop();
    for(int nv : G[v]) {
      if(dist[nv] != -1) continue;
      dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }
  // 到達不可能な時
  if(dist[N-1] == -1) {
    cout << "0" << endl;
    return 0;
  }
  // 到達可能な時、その最短経路数を数える
  // ll ans = 0;
  // 再度bfsをする
  vector<int> dist2(N, -1);
  vector<bool> is_pushed(N, false);
  dist2[0] = 0;
  ll dp[500100]; // i番目の都市への最短経路数
  dp[0] = 1;
  que.push(0);
  is_pushed[0] = true;
  while(!que.empty()) {
    int v = que.front(); que.pop();
    for(int nv : G[v]) {
      // if(nv == N-1 && dist2[v]+1 == dist[N-1]) ans = (ans+1) % MOD;
      if(dist2[nv] != -1 && dist2[nv] < dist2[v] + 1) continue;
      dist2[nv] = dist2[v] + 1;
      dp[nv] = (dp[nv] + dp[v]) % MOD;
      if(is_pushed[nv]) continue;
      que.push(nv);
      is_pushed[nv] = true;
    }
  }
  cout << dp[N-1] << endl;
}