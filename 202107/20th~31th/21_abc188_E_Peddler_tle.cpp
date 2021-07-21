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

Graph G;
vector<int> vec;
vector<bool> seen;

// (金を売った価格)-(金を買った価格)の最大値
// →(今の頂点の価格)-(行きがけの今までのminの価格)の最大値
int dfs(int v, int min_val, int root) {
  int res;
  if(v == root) res = -INF;
  else res = vec[v] - min_val;

  seen[v] = true;
  int val = min(min_val, vec[v]);

  for(auto next_v : G[v]) {
    res = max(res, dfs(next_v, val, root));
  }

  return res;
}

int main() {
  int N, M; cin >> N >> M;
  vec.resize(N);
  rep(i,N) cin >> vec[i];
  G.resize(N);
  rep(i,M) {
    int x, y; cin >> x >> y;
    x--; y--;
    G[x].push_back(y);
  }

  seen.assign(N, false);
  int ans = -INF;
  rep(i,N) {
    if(!seen[i]) ans = max(ans, dfs(i, vec[i], i));
  }
  cout << ans << endl;
  // cout << dfs(first, vec[first], first) << endl;
}

// メモ化してないからTLEしてる