#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
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
  int cost;
  int to;
};
using Graph = vector<vector<Edge>>;

// 全ての頂点からダイクストラをしていく
int main() {
  int N, M; cin >> N >> M;
  Graph G(N);
  rep(i,M) {
    int a, b, t; cin >> a >> b >> t;
    a--, b--;
    G[a].push_back({t, b});
    G[b].push_back({t, a});
  }
  int ans = INF;
  rep(i,N) {
    // それぞれダイクストラしていく
    vector<int> dist(N, INF);
    priority_queue<P, vector<P>, greater<P>> q;
    dist[i] = 0;
    q.push({0,i});
    while (!q.empty()) {
      P tmp = q.top(); q.pop();
      int cost = tmp.first;
      int v = tmp.second;
      if(dist[v] != cost) continue;
      for(Edge& e : G[v]) {
        if(dist[e.to] <= cost + e.cost) continue;
        dist[e.to] = cost + e.cost;
        q.emplace(e.cost, e.to);
      }
    }
    int max_val = 0;
    rep(i,N) max_val = max(max_val, dist[i]);
    ans = min(ans, max_val);
  }
  cout << ans << endl;
}

// 1回ごとにダイクストラの計算量がかかるO(Elog(V+E))
// →O(Vlog(V+E))
// notac...