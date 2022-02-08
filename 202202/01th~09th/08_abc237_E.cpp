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

// 素直に最大値を求めるのではなく(ベルマンフォードだったらイケる)、
// 楽しくなさの最小値をダイクストラ(最短経路問題)で求める.
// コストが負になってしまわないように、コストを調節して求めれば良い
int main() {
  int N, M; cin >> N >> M;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  vector<vector<Edge>> G(N);
  rep(i,M) {
    int a, b; cin >> a >> b;
    a--, b--;
    int cost_from_a = max(vec[b]-vec[a], 0);
    int cost_from_b = max(vec[a]-vec[b], 0);
    G[a].push_back({b, cost_from_a});
    G[b].push_back({a, cost_from_b});
  }
  vector<int> dist(N);
  rep(i,N) dist[i] = INF;
  priority_queue<P, vector<P>, greater<P>> que;
  dist[0] = 0;
  // 初期値(0から伸びる辺)→ダイクストラ
  for(Edge& e : G[0]) {
    dist[e.to] = e.cost;
    que.emplace(e.cost, e.to);
  }
  while(!que.empty()) {
    P tmp = que.top(); que.pop();
    int cost = tmp.first;
    int v = tmp.second;
    if(dist[v] != cost) continue;
    for(Edge& e : G[v]) {
      if(dist[e.to] <= cost + e.cost) continue;
      dist[e.to] = cost + e.cost;
      que.emplace(cost + e.cost, e.to);
    }
  }
  // 最後に各頂点についてdistを見ていって、-(dist[i]) + (vec[0]-vec[i])の最大値を求める
  int ans = 0;
  rep(i,N) {
    int result = (vec[0]-vec[i]) - (dist[i]);
    ans = max(ans, result);
  }
  cout << ans << endl;
}