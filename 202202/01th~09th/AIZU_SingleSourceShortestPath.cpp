#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<ll,int>;
using T = tuple<int,int,int>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};
struct Edge {
  ll cost;
  int v;
};
using Graph = vector<vector<Edge>>;

int main() {
  int N, E; cin  >> N >> E;
  int start; cin >> start;
  Graph G(N);
  rep(i,E) {
    int s, t; cin >> s >> t;
    ll d; cin >> d;
    G[s].push_back({d, t});
  }
  vector<ll> dist(N, INF);
  priority_queue<P, vector<P>, greater<P>> q; 
  dist[start] = 0;
  for(Edge& e : G[start]) {
    dist[e.v] = e.cost;
    q.push({e.cost, e.v});
  }
  while(!q.empty()) {
    P tmp = q.top(); q.pop();
    ll cost = tmp.first;
    int v = tmp.second;
    if(dist[v] != cost) continue;
    for(Edge& e : G[v]) {
      if(dist[e.v] <= cost + e.cost) continue;
      dist[e.v] = cost + e.cost;
      q.emplace(cost + e.cost, e.v);
    }
  }
  rep(i,N) {
    if(dist[i] != INF) cout << dist[i] << endl;
    else cout << "INF" << endl;
  }
  return 0;
}

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja