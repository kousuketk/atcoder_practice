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
struct Scc {
  Graph g, rg, grp;
  vector<int> compo;
  int N;
  Scc(Graph inpG) {
    N = inpG.size();
    g.resize(N);
    rg.resize(N);
    compo.resize(N, -1);
    for(int v = 0; v < N; v++) {
      for(int nv : inpG[v]) {
        g[v].push_back(nv);
        rg[nv].push_back(v);
      }
    }
  }
  void dfs(int v, vector<bool> &used, vector<int> &order) {
    if(used[v]) return;
    used[v] = true;
    for(int nv : g[v]) dfs(nv, used, order);
    order.push_back(v);
  }
  void rdfs(int v, int group) {
    if(compo[v] != -1) return;
    compo[v] = group;
    for(int nv : rg[v]) rdfs(nv, group);
  }
  void build(Graph &ret) {
    vector<int> order(N);
    vector<bool> used(N);
    for(int v = 0; v < N; v++) dfs(v, used, order);
    reverse(ALL(order));
    int group = 0;
    for(int v : order) {
      if(compo[v] != -1) continue;
      rdfs(v, group);
      group++;
    }
    grp.resize(group);
    // グラフを縮める
    ret.resize(group);
    for(int v = 0; v < N; v++) {
      for(int nv : g[v]) {
        int s = compo[v], t = compo[nv];
        if(s != t) ret[s].push_back(t);
      }
    }
    // grpを作成
    rep(v,N) {
      int groupNum = compo[v];
      grp[groupNum].push_back(v);
    }
  }
};

// sccのグループの後ろから見ていく(もしサイズが1だったら、つながるグループを見ていく)
int main() {
  int N, M; cin >> N >> M;
  Graph G(N);
  rep(i,M) {
    int u, v; cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
  }
  Scc scc(G);
  Graph buff;
  scc.build(buff);
  int siz = buff.size();  // groupのサイズ(何個の連結成分で別れているか)
  vector<int> dp(siz);
  int ans = 0;
  for(int i = siz-1; i >= 0; i--) {
    if((int)scc.grp[i].size() > 1) {
      dp[i] = (int)scc.grp[i].size();
    } else {
      int v = scc.grp[i][0];
      for(int nv : G[v]) {
        int ngrp = scc.compo[nv];
        if(dp[ngrp] > 0) dp[i] = 1;
      }
    }
    ans += dp[i];
  }
  cout << ans << endl;
  return 0;
}