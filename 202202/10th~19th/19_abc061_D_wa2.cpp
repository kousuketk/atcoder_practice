#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
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

// スコアにマイナスを付けて、ベルマンフォード.ネガティブサイクル検出時はinf
int main() {
  int N, M; cin >> N >> M;
  vector<vector<Edge>> G(N);
  rep(i,M) {
    int a, b; cin >> a >> b;
    a--, b--;
    ll c; cin >> c;
    G[a].push_back({b, c*(-1)});
  }
  vector<ll> dist(N, INF);
  dist[0] = 0;
  bool updated;
  rep(itr,N) {
    updated = false;
    rep(i,N) {
      if(dist[i] == INF) continue;
      for(Edge &e : G[i]) {
        if(dist[e.to] > (dist[i] + e.cost)) {
          dist[e.to] = dist[i] + e.cost;
          updated = true;
        }
      }
      if(!updated) break;
    }
  }
  ll ans = dist[N-1] * (-1);
  vector<bool> negative(N, false);
  rep(itr,N*2) {
    rep(i,N) {
      for(Edge &e : G[i]) {
        if(dist[i] == INF) continue;
        if(dist[e.to] > (dist[i] + e.cost)) {
          dist[e.to] = dist[i] + e.cost;
          negative[e.to] = true;
        }
        if(negative[i]) negative[e.to] = true;
      }
    }
  }
  if(negative[N-1]) cout << "inf" << endl;
  else cout << ans << endl;
  return 0;
}

// これだと、頂点1から到達できる負の閉路は存在するが、どの負の閉路も頂点Nへと至らない時にも検出されてしまう
// 別解候補：負の閉路の検出をトポロジカルソートで、その後はそのまま最大スコアを出す