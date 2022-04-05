#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Pg = pair<int, ll>;
using Graph = vector<vector<Pg>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

using Pque = pair<ll, int>;

void calc_dist(Graph &G, vector<ll> &dist, int i) {
  dist[i] = 0;
  priority_queue<Pque, vector<Pque>, greater<Pque>> que;
  que.push(Pque(0, i));
  while(!que.empty()) {
    Pque tmp = que.top(); que.pop();
    ll cost = tmp.first;
    int v = tmp.second;
    if(dist[v] != cost) continue;
    for(Pg e : G[v]) {
      int next_v = e.first;
      ll next_cost = e.second;
      if(dist[next_v] <= dist[v] + next_cost) continue;
      dist[next_v] = dist[v] + next_cost;
      que.push(Pque(dist[next_v], next_v));
    }
  }
  return;
}

// 全ての頂点への最短経路を出して、それぞれの頂点に行って帰ってくることを考えれば良い
int main() {
  int N, M; cin >> N >> M;
  ll T; cin >> T;
  vector<ll> vec(N);
  rep(i,N) cin >> vec[i];
  Graph G(N);
  Graph Grev(N);
  rep(i,M) {
    int a, b; cin >> a >> b;
    ll c; cin >> c;
    a--, b--;
    G[a].push_back(Pg(b, c));
    Grev[b].push_back(Pg(a, c));
  }
  vector<ll> dist(N, INF);
  vector<ll> distRev(N, INF);
  calc_dist(G, dist, 0);
  calc_dist(Grev, distRev, 0);
  ll ans = 0;
  rep(i,N) {
    ll time = T-(dist[i]+distRev[i]);
    if(time <= 0) continue;
    ans = max(ans, time*vec[i]);
  }
  cout << ans << endl;
  return 0;
}