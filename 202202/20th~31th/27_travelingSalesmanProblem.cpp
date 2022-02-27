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
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int N;
int dist[21][21];
int dp[(1<<20) + 1][21];  // 集合sをたどって、最後の頂点がjのときの最短経路(jは出発地点and到着地点, ちなみにハミルトングラフを求めているから出発地点はどこでもok)

int rec(int bit, int v, int start) {
  if(dp[bit][v] != -1) return dp[bit][v];
  if(bit == (1<<v)) return dp[bit][v] = dist[start][v];  // 最後の時
  int res = INF;
  int prev_bit = bit & ~(1<<v);
  // vの手前のノードを全探索
  for(int u = 0; u < N; u++) {
    if(!(prev_bit & (1<<u))) continue;
    if(dist[u][v] == INF) continue;
    res = min(res, rec(prev_bit, u, start) + dist[u][v]);
  }
  return dp[bit][v] = res;
}

int main() {
  cin >> N;
  int E; cin >> E;
  rep(i,21) rep(j,21) dist[i][j] = INF;
  rep(i,E) {
    int s, t, d; cin >> s >> t >> d;
    dist[s][t] = d;
  }
  for(int bit = 0; bit < (1<<N); bit++) for(int v = 0; v < N; v++) dp[bit][v] = -1;
  // 最短経路を求める(今回はハミルトングラフを求めればいいので、任意の頂点1箇所から出発すればいい)
  int res = INF;
  res = min(res, rec((1<<N)-1, 0, 0));
  if(res == INF) cout << -1 << endl;
  else cout << res << endl;
  return 0;
}