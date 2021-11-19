#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;

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

int main() {
  int V, E, Q; cin >> V >> E;
  Graph g(V), buff;
  for(int i = 0; i < E; i++) {
    int a, b; cin >> a >> b;
    g[a].emplace_back(b);
  }
  StronglyConnectedComponents scc(g);
  scc.build(buff);
  cin >> Q;
  while(Q--) {
    int a, b; cin >> a >> b;
    puts(scc[a] == scc[b] ? "1" : "0");
  }
}