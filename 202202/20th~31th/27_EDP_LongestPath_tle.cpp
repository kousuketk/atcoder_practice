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
Graph G_rev;
vector<int> seen;
vector<int> seen_rev;

// vから一番遠いい頂点を返す(dist, 頂点)
P dfs(int v, int dist) {
  seen[v] = dist;
  P res = P(dist, v);
  for(int nv : G[v]) {
    if(seen[nv] >= dist+1) continue;
    res = max(res, dfs(nv, dist+1));
  }
  return res;
}

// vから一番遠いい頂点の距離を返す
int dfs_rev(int v, int dist) {
  seen_rev[v] = dist;
  int res = dist;
  for(int nv : G_rev[v]) {
    if(seen_rev[nv] >= dist+1) continue;
    res = max(res, dfs_rev(nv, dist+1));
  }
  return res;
}

int main() {
  int N, M; cin >> N >> M;
  G.resize(N);
  G_rev.resize(N);
  seen.assign(N, -1);
  seen_rev.assign(N, -1);
  rep(i,M) {
    int x, y; cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    G_rev[y].push_back(x);
  }
  int ans = 0;
  rep(i,N) {
    if(seen[i] > -1 || seen_rev[i] > -1) continue;
    cout << i << endl;
    // 頂点iから一番遠い頂点から、一番遠い頂点を見つける
    P tmp = dfs(i, 0);
    ans = max(ans, dfs_rev(tmp.second, 0));  // 一番遠い頂点→tmp.second
  }
  cout << ans << endl;
  return 0;
}

// TLEしてしまう...
// dfsの”if(seen_rev[nv] >= dist+1) continue;”このあたりで、O(N+M)にならず更新されているんだと思う
// →メモ化再帰で、memo[i]:頂点iの最長経路の数