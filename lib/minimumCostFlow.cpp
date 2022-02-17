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
  PrimalDual(int inputV) : G(inputV), dist(inputV), prevv(inputV), preve(inputV) { V = inputV; }

  void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back(Edge{to, cap, cost, (int)G[to].size()});
    G[to].push_back(Edge{from, 0, -cost, (int)G[from].size()-1});
  }

  int min_cost_flow(int s, int t, int f) {
    int res = 0;  // 最小費用流(流量fのフローを流すための最小コスト)
    while(f > 0) {
      // ベルマンフォードでs-t間の最短経路を求める
      fill(ALL(dist), INF);
      dist[s] = 0;
      bool update = true;
      while(update) {
        update = false;
        rep(v,V) {
          if(dist[v] == INF) continue;
          for(int i = 0; i < (int)G[v].size(); i++) {  // ダイクストラみたいに更新できるものがあれば更新していくが負の辺を考慮して前辺たどる
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
      for(int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);  // 最短経路には流せるだけf(フロー)を流す
      f -= d;
      res += d*dist[t];  // 流れたf(フロー)分だけ、コストがかかる
      for(int v = t; v != s; v = prevv[v]) {  // 選んだ辺を消去して、逆辺を張っていく
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

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=ja
// 計算量は、最悪F回のベルマンフォードをすることになるから、O(F|V||E|)となる.
// ポテンシャルを使ってダイクストラもできる. その時の計算量はO(F|E|log|V|)