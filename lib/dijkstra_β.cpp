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
  int to, t, k;
};

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  x--; y--;
  vector<vector<Edge>> g(n);
  rep(i,m) {
    int a, b, t, k;
    cin >> a >> b >> t >> k;
    a--; b--;
    g[a].push_back({b,t,k});
    g[b].push_back({a,t,k});
  }
  const ll INF = 1e18;
  vector<ll> dist(n, INF);
  priority_queue<P, vector<P>, greater<P>> q;
  dist[x] = 0;
  q.push({0,x});
  while(!q.empty()) {
    P tmp = q.top(); q.pop();
    ll x2 = tmp.first;
    int v2 = tmp.second;
    if(dist[v2] != x2) continue;
    for(Edge& e : g[v2]) {
      ll nx = (x2+e.k-1)/e.k*e.k + e.t;
      if(dist[e.to] <= nx) continue;
      dist[e.to] = nx;
      q.emplace(nx, e.to);
    }
  }
  ll ans = dist[y];
  if(ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}

// https://atcoder.jp/contests/abc192/tasks/abc192_e