#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll,int>;
using T = tuple<int,int,int>;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

struct Edge {
  int to;
  int cost;
};
using Graph = vector<vector<Edge>>;
const ll INF = 1e18;

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  x--; y--;
  vector<vector<Edge>> g(n);
  rep(i,m) {
    int a, b, cost;
    cin >> a >> b >> cost;
    a--; b--;
    g[a].push_back({b, cost});
    g[b].push_back({a, cost});
  }
  vector<ll> dist(n, INF);
  priority_queue<P, vector<P>, greater<P>> q;
  // 探索開始点(x)は0であり、queに入れる
  dist[x] = 0;
  q.push({0,x});
  // while文でqueがなくなるまで探索する
  while(!q.empty()) {
    P tmp = q.top(); q.pop();
    ll cost = tmp.first;
    int v = tmp.second;
    // もっと短い距離が更新されていたらcontinue(最短距離でなければ無視)
    if(dist[v] != cost) continue;
    for(Edge& e : g[v]) {
      // 短い距離を更新できたらqueに追加する
      if(dist[e.to] >= dist[v] + e.cost) continue;
      dist[e.to] = e.cost;
      q.emplace(e.cost, e.to);
    }
  }
  cout << dist[y] << endl;
}