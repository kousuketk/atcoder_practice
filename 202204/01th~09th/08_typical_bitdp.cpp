#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
// const int INF = 1001001001;
const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int N;
ll dist[14][14];
ll dp[(1<<13) + 1][14];
ll rec(int bit, int v) {
  if(dp[bit][v] != -1) return dp[bit][v];
  if(bit == (1<<v)) return dist[0][v];  // 出発は頂点0から頂点v
  ll res = INF;
  int prev_bit = bit & ~(1<<v);
  // vの手前のノードとしてuを全探索
  for(int u = 0; u < N; u++) {
    if(!(prev_bit & (1<<u))) continue;
    res = min(res, rec(prev_bit, u) + dist[u][v]);
  }
  return dp[bit][v] = res;
}

int main() {
  cin >> N;
  rep(i,N) {
    rep(j,N) {
      cin >> dist[i][j];
    }
  }
  for(int bit = 0; bit < (1<<N); bit++) {
    for(int v = 0; v < N; v++) {
      dp[bit][v] = -1;
    }
  }
  ll res = INF;
  res = min(res, rec((1<<N)-1, 0));
  cout << res << endl;
  return 0;
}