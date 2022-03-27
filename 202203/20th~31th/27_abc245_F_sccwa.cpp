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

// scc[i]：i番目の頂点は、どの成分に属するか？
struct StronglyConnectedComponents {
  Graph g, ng, rg;          // normal-graphとreversed-graph
  vector<int> compo, order, used;  // compo…頂点がどの成分に属しているか、order…帰りがけ順で何番目か

  StronglyConnectedComponents(Graph g) {
    this->g = g;
    ng.resize(g.size());
    rg.resize(g.size());
    compo.resize(g.size(), -1);
    used.resize(g.size());
    for (int i = 0; i < (int)g.size(); i++) {
      for (auto t : g[i]) {
        ng[i].emplace_back((int)t);
        rg[(int)t].emplace_back(i);  // 逆辺
      }
    }
  }

  // []で聞かれたときは成分番号を返す
  int operator[](int k) { return compo[k]; }

  void dfs(int now) {
    if (used[now]) return;
    used[now] = true;
    for (auto to : ng[now]) dfs(to);
    order.emplace_back(now);
  }

  void rdfs(int now, int count) {
    // used代わりに結果を入れていく
    if (compo[now] != -1) return;
    compo[now] = count;
    for (auto to : rg[now]) rdfs(to, count);
  }

  void build(Graph &ret) {
    // 普通にDFS、辺の向きを変えてもう一度DFS
    for (int i = 0; i < (int)ng.size(); i++) dfs(i);
    reverse(order.begin(), order.end());
    int group = 0;
    for (auto i : order) if (compo[i] == -1) rdfs(i, group), group++;

    // 縮めたグラフを構築する
    ret.resize(group);
    for (int i = 0; i < (int)g.size(); i++) {  // 全ての辺について
      for (auto &to : g[i]) {
        int s = compo[i], t = compo[to];
        if (s != t) ret[s].emplace_back(t);
      }
    }
  }
};

// 頂点数が2以上の強連結成分に到達できる頂点はいくつあるか？
int main() {
  int N, M; cin >> N >> M;
  Graph G(N), buff;
  rep(i,M) {
    int u, v; cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
  }
  StronglyConnectedComponents scc(G);
  scc.build(buff);
  int cnt_group = 0;
  rep(i,N) cnt_group = max(cnt_group, scc[i]);
  Graph groupG(cnt_group+1);
  rep(i,N) {
    int group = scc[i];
    groupG[group].push_back(i);
  }
  int ans = 0;
  for(int i = cnt_group; i >= 0; i--) {
    if((int)groupG[i].size() > 1) {
      ans += (int)groupG[i].size();
    } else {
      bool flag = false;
      for(int nv : G[groupG[i][0]]) {
        if(groupG[nv].size() > 1) flag = true;
      }
      if(flag) ans++;
    }
  }
  cout << ans << endl;
}