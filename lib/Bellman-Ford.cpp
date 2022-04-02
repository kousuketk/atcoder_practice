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
  int s;
  int t;
  int cost;
};

int main() {
  int V, E, r; cin >> V >> E >> r;
  vector<Edge> vec(E);
  rep(i,E) {
    int s, t, d; cin >> s >> t >> d;
    vec[i] = Edge{s, t, d};
  }
  vector<int> dist(V, INF);
  dist[r] = 0;
  for(int i = 0; i < V; i++) {
    for(int j = 0; j < E; j++) {
      Edge tmp = vec[j];
      if(dist[tmp.s] == INF) continue;  // INFのときも更新すると、(tmp.costが負のとき)たどり着かない頂点がINFでなくなる可能性がある
      if(dist[tmp.t] <= dist[tmp.s] + tmp.cost) continue;
      dist[tmp.t] = dist[tmp.s] + tmp.cost;
      if(i == V-1) {  // V-1回以内の更新で終了すれば負の閉路は存在しない. V回まで更新が続けば負の閉路が存在する
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
      }
    }
  }
  rep(i,V) {
    if(dist[i] == INF) cout << "INF" << endl;
    else cout << dist[i] << endl;
  }
}

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja