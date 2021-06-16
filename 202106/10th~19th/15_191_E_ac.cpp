#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

struct Edge {
  int to;
  ll cost;
};

int main() {
  int n, m; cin >> n >> m;
  vector<vector<Edge>> G(n);
  for(int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    a--; b--;
    G[a].push_back({b, c});
  }
  for(int i = 0; i < n; i++) {
    vector<ll> dist(n, INF);
    priority_queue<P, vector<P>, greater<P>> q;
    // i番目の頂点から探索する, (0, 頂点)はqueueに入れるが、distはINF
    for(Edge& e : G[i]) {
      if(dist[e.to] <= e.cost) continue;
      dist[e.to] = e.cost;
      q.emplace(e.cost, e.to);
    };
    while(!q.empty()) {
      P tmp = q.top(); q.pop();
      ll cost = tmp.first;
      int v = tmp.second;
      if(dist[v] != cost) continue;
      for(Edge& e : G[v]) {
        if(dist[e.to] <= cost + e.cost) continue;
        dist[e.to] = cost + e.cost;
        q.emplace(cost + e.cost, e.to);
      }
    }
    if(dist[i] == INF) cout << "-1" << endl;
    else cout << dist[i] << endl;
  }
}