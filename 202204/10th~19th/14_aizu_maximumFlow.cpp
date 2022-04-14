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
struct MaximumFlow {
  struct Edge {
    int to;
    int cap;
    int rev;
  };
  vector<vector<Edge>> G;
  vector<bool> used;
  MaximumFlow(int V) : G(V), used(V) {}
  void add_edge(int from, int to, int cap) {
    G[from].push_back((Edge){to, cap, (int)G[to].size()});
    G[to].push_back((Edge){from, 0, (int)G[from].size()-1});
  }
  int dfs(int v, int t, int f) {
    if(v == t) return f;
    used[v] = true;
    for(Edge& e : G[v]) {
      if(used[e.to] || e.cap <= 0) continue;
      int d = dfs(e.to, t, min(f, e.cap));
      if(d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
    return 0;
  }
  int max_flow(int s, int t) {
    int flow = 0;
    while(true) {
      fill(ALL(used), false);
      int f = dfs(s, t, INF);
      if(f == 0) return flow;
      flow += f;
    }
  }
};

int main() {
  int V, E; cin >> V >> E;
  MaximumFlow g(V);
  rep(i,E) {
    int u, v, c; cin >> u >> v >> c;
    g.add_edge(u, v, c);
  }
  int ans = g.max_flow(0, V-1);
  cout << ans << endl;
}