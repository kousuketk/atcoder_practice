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
struct PrimalDual {
  struct Edge {
    int to;
    int cap;
    int cost;
    int rev;
  };
  int V;
  vector<vector<Edge>> G;
  vector<int> dist;
  vector<int> prevv;
  vector<int> preve;
  PrimalDual(int inputV) : G(inputV), dist(inputV), prevv(inputV), preve(inputV) {
    V = inputV;
  }
  void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back(Edge{to, cap, cost, (int)G[to].size()});
    G[to].push_back(Edge{from, 0, -cost, (int)G[from].size()-1});
  }
  int min_cost_flow(int s, int t, int f) {
    int res = 0;
    while(f > 0) {
      fill(ALL(dist), INF);
      dist[s] = 0;
      bool update = true;
      while(update) {
        update = false;
        rep(v,V) {
          if(dist[v] == INF) continue;  // 負の辺のときにINFから更新しないように(更新されてしまうと、到達できない頂点なのにINFより短くなってしまう)
          for(int i = 0; i < (int)G[v].size(); i++) {
            Edge &e = G[v][i];
            if(e.cap <= 0 || dist[e.to] <= dist[v] + e.cost) continue;
            dist[e.to] = dist[v] + e.cost;
            prevv[e.to] = v;
            preve[e.to] = i;
            update = true;
          }
        }
      }
      if(dist[t] == INF) return -1;
      int d = f;
      for(int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);
      f -= d;
      res += d*dist[t];  // 最短距離に対する流れたf(フロー)分だけ、コストがかかる
      for(int v = t; v != s; v = prevv[v]) {
        Edge &e = G[prevv[v]][preve[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
    }
    return res;
  }
};

int main() {
  int V, E, F; cin >> V >> E >> F;
  PrimalDual g(V);
  rep(i,E) {
    int u, v, c, d; cin >> u >> v >> c >> d;
    g.add_edge(u, v, c, d);
  }
  int ans = g.min_cost_flow(0, V-1, F);
  cout << ans << endl;
}