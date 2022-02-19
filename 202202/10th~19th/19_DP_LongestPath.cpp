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
vector<bool> seen;
// トポロジカルソートを作成
void dfs(Graph &G, int v, vector<int> &topo) {
  seen[v] = true;
  for(int next_v : G[v]) {
    if(seen[next_v]) continue;
    dfs(G, next_v, topo);
  }
  topo.push_back(v);
}

// トポロジカルソートを作って、動的計画法で最長パスを求める
int main() {
  int N, M; cin >> N >> M;
  Graph G(N);
  seen.assign(N, false);
  rep(i,M) {
    int x, y; cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
  }
  vector<int> dist(N, 0);  // i番目の頂点への最長距離
  vector<int> topo;
  // 1つの連結グラフとは限らないから、全部見ていく
  rep(i,N) {
    if(seen[i]) continue;
    dfs(G, i, topo);
  }
  reverse(ALL(topo));  // 連結している部分が全部dfs終わってからリバースする
  // i頂点の連結グラフ内のトポロジカルソートが完成しているから、前からdp
  int ans = 0;
  rep(j,(int)topo.size()) {
    int v = topo[j];
    for(int next_v : G[v]) {
      dist[next_v] = max(dist[next_v], dist[v] + 1);
      ans = max(ans, dist[next_v]);
    }
  }
  cout << ans << endl;
}

// 連結している部分ごとのトポロジカルソートを作ろうとしていたが、
// 配るDPで実装するから、全部合わせたトポロジカルソートでいいんだ
// 別解として、メモ化してres = max(res, dfs(next_v) + 1)みたいに、子要素を取得していく方法もある