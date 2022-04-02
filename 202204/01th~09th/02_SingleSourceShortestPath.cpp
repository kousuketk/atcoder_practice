#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<P>>;  // to, costを格納
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int main() {
  int V, E, r; cin >> V >> E >> r;
  priority_queue<P, vector<P>, greater<P>> que;
  vector<int> dist(V, INF);
  Graph G(V);
  rep(i,E) {
    int s, t, d; cin >> s >> t >> d;
    G[s].push_back(P(t, d));
  }
  dist[r] = 0;
  que.push(P(0, r));
  while(!que.empty()) {
    P p = que.top(); que.pop();
    int cost = p.first;
    int to = p.second;
    if(dist[to] != cost) continue;
    for(P tmp : G[to]) {
      int nv = tmp.first;
      int cost = tmp.second;
      if(dist[nv] <= dist[to] + cost) continue;
      dist[nv] = dist[to] + cost;
      que.push(P(cost, nv));
    }
  }
  rep(i,V) {
    if(dist[i] != INF) cout << dist[i] << endl;
    else cout << "INF" << endl;
  }
  return 0;
}