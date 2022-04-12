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

struct StoronglyConnectedComponents {
  Graph g, rg, grp;
  vector<int> compo;
  int N;

  StoronglyConnectedComponents(Graph inpG) {
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
    // 縮めたグラフを構築する
    ret.resize(group);
    for(int v = 0; v < N; v++) {
      for(int nv : g[v]) {
        int s = compo[v], t = compo[nv];
        if(s != t) ret[s].push_back(t);
      }
    }
  }
  // compo[i]：iはgroupに属する
  // grp[i]：i番目のgroupはvを持つ(隣接リスト)
  void build_grp() {
    int grp_siz = grp.size();
    rep(v,N) {
      int group = compo[v];
      grp[group].push_back(v);
    }
  }
};

int main() {
  int V, E; cin >> V >> E;
  Graph G(V);
  rep(i,E) {
    int s, t; cin >> s >> t;
    G[s].push_back(t);
  }
  StoronglyConnectedComponents scc(G);
  Graph buff;
  scc.build(buff);
  int Q; cin >> Q;
  rep(i,Q) {
    int u, v; cin >> u >> v;
    if(scc.compo[u] == scc.compo[v]) cout << 1 << endl;
    else cout << 0 << endl;
  }
}