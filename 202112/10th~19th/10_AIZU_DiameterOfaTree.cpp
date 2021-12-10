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

struct Edge {
  int to;
  int cost;
};

int N;
vector<vector<Edge>> G;
P bfs(int v) {  // vから一番遠いい頂点とその距離を返す
  vector<int> dist(N, -1);
  queue<int> que;
  dist[v] = 0;
  que.push(v);
  int far_ptr = v;
  int max_val = 0;
  while(!que.empty()) {
    int v = que.front();
    que.pop();

    for(Edge e : G[v]) {
      int nv = e.to, cost = e.cost;
      if(dist[nv] != -1) continue;
      dist[nv] = dist[v] + cost;
      que.push(nv);
      if(dist[nv] > max_val) {
        max_val = dist[nv];
        far_ptr = nv;
      }
    }
  }
  return P(far_ptr, max_val);
}

int main() {
  cin >> N;
  G.resize(N);
  rep(i,N-1) {
    int s, t, w; cin >> s >> t >> w;
    G[s].push_back({t, w});
    G[t].push_back({s, w});
  }
  P res1 = bfs(0);
  int nv = res1.first;
  P res2 = bfs(nv);
  int ans = res2.second;
  cout << ans << endl;
}