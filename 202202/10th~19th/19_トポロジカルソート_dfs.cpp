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

Graph G;
vector<int> ans;
vector<bool> seen;
void dfs(int v) {
  seen[v] = true;
  for(int next_v : G[v]) {
    if(seen[next_v]) continue;
    dfs(next_v);
  }
  ans.push_back(v);  // 末尾からdfsが終わっていき、push_baskされていく
}

int main() {
  int V, E; cin >> V >> E;
  G.resize(V);
  seen.assign(V, false);
  rep(i,E) {
    int s, t; cin >> s >> t;
    G[s].push_back(t);
  }
  rep(i,V) {
    if(seen[i]) continue;
    dfs(i);
  }
  reverse(ALL(ans));
  rep(i,V) cout << ans[i] << endl;
  return 0;
}

// トポロジカルソート