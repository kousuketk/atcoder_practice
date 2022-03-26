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

vector<bool> seen, finished, seen_rev;
int pos = -1;
set<int> cycle;
Graph G, Grev;

void dfs_rev(int v) {
  seen_rev[v] = true;
  cycle.insert(v);
  for(auto nv : Grev[v]) {
    if(seen_rev[nv]) continue;
    dfs_rev(nv);
  }
}

void dfs(int v) {
  seen[v] = true;
  for (auto nv : G[v]) {
    if (finished[nv]) continue;

    if (seen[nv] && !finished[nv]) {
      pos = nv;
      // サイクル検出時に逆辺をたどっていく
      if(!seen_rev[nv]) dfs_rev(nv);
      return;
    }
    dfs(nv);
    if (pos != -1) return;
  }
  finished[v] = true;
}

// 全部の頂点についてサイクル検出
int main() {
  int N, M; cin >> N >> M;
  G.resize(N);
  Grev.reserve(N);
  rep(i,M) {
    int u, v; cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    Grev[v].push_back(u);
  }
  seen.assign(N, false), finished.assign(N, false), seen_rev.assign(N, false);
  rep(i,N) {
    if(seen[i]) continue;
    pos = -1;
    dfs(i);
  }
  int ans = 0;
  for(auto itr = cycle.begin(); itr != cycle.end(); itr++) {
    ans++;
  }
  cout << ans << endl;
}