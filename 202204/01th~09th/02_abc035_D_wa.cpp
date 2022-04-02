#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<ll,int>;
using T = tuple<int,int,int>;
// const int INF = 1001001001;
const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};
struct Edge {
  int to;
  ll cost;
};
using Graph = vector<vector<Edge>>;  // to, cost

// 滞在する必要がある頂点は1つ。ダイクストラでそれぞれの分数出して、全頂点を調べる
int main() {
  int N, M; cin >> N >> M;
  ll T; cin >> T;
  vector<ll> A(N);
  rep(i,N) cin >> A[i];
  Graph G(N);
  Graph Grev(N);
  rep(i,M) {
    int a, b; cin >> a >> b;
    ll c; cin >> c;
    a--, b--;
    G[a].push_back({b, c});
    Grev[b].push_back({a, c});
  }
  // 行き
  vector<ll> dist(N, INF);
  priority_queue<P, vector<P>, greater<P>> que;
  dist[0] = 0;
  que.push(P(0, 0));
  while(!que.empty()) {
    P tmp = que.top(); que.pop();
    int v = tmp.second;
    ll cost = tmp.first;
    if(dist[v] != cost) continue;
    for(Edge next : G[v]) {
      int nv = next.to;
      ll ncost = next.cost;
      if(dist[nv] <= dist[v] + ncost) continue;
      dist[nv] = dist[v] + ncost;
      que.push(P(dist[nv], nv));
    }
  }
  // 帰り
  vector<ll> distRev(N, INF);
  distRev[0] = 0;
  que.push(P(0, 0));
  while(!que.empty()) {
    P tmp = que.top(); que.pop();
    int v = tmp.second;
    ll cost = tmp.first;
    if(distRev[v] != cost) continue;
    for(Edge next : Grev[v]) {
      int nv = next.to;
      ll ncost = next.cost;
      if(distRev[nv] <= distRev[v] + ncost) continue;
      distRev[nv] = distRev[v] + ncost;
      que.push(P(distRev[nv], nv));
    }
  }
  // それぞれの頂点を見ていく
  ll ans = 0;
  rep(i,N) {
    ll rest = T - dist[i] - distRev[i];
    ll tmp = rest*A[i];
    ans = max(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}