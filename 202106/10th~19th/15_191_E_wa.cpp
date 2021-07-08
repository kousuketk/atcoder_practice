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
  for(int i = 0; i < 1; i++) {
    vector<ll> dist(n, INF);
    priority_queue<P, vector<P>, greater<P>> q;
    // i番目の頂点から探索する, (0, 頂点)はqueueに入れるが、distはINF
    q.push({0,i});
    while(!q.empty()) {
      P tmp = q.top(); q.pop();
      ll cost = tmp.first;
      int v = tmp.second;
      if(v != i && dist[v] != cost) continue;
      for(Edge& e : G[v]) {
        if(v != i && dist[e.to] <= dist[v] + e.cost) continue;
        if(v == i) dist[e.to] = e.cost;
        else dist[e.to] = dist[v] + e.cost;
        q.emplace(e.cost, e.to);
      }
    }
    if(dist[i] == INF) cout << "-1" << endl;
    else cout << dist[i] << endl;
  }
}