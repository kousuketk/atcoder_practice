#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 100100100;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int V, M;
int dist[15][15];
int dp[(1<<15)][15][15];  // 最後はスタート・ゴールの場所
int rec(int bit, int v, int s) {
  if(dp[bit][v][s] != -1) return dp[bit][v][s];
  if(bit == (1<<v)) return dist[s][v];
  int res = INF;
  int prev_bit = bit & ~(1<<v);
  // vの手前のノードとしてuを全探索
  for(int u = 0; u < V; u++) {
    if(!(prev_bit & (1<<u))) continue;
    if(dist[u][v] == INF) continue;
    res = min(res, rec(prev_bit, u, s) + dist[u][v]);
  }
  return dp[bit][v][s] = res;
}

int main() {
  cin >> V >> M;
  rep(i,15) rep(j,15) dist[i][j] = INF;
  rep(i,M) {
    int s, t, d; cin >> s >> t >> d;
    dist[s][t] = d;
  }
  for(int bit = 0; bit < (1<<V); bit++) {
    rep(j,V) rep(k,V) {
      dp[bit][j][k] = -1;
    }
  }
  int res = INF;
  rep(i,V) {
    res = min(res, rec((1<<V)-1, i, i));
  }
  if(res == INF) cout << -1 << endl;
  else cout << res << endl;
  return 0;
}

// dp[(1<<15)][15][15]は、別にdp[(1<<15)][15]で良かった。
// →どの頂点で出発・終了しても答えは同じだから、0頂点からの出発だけ見ればok