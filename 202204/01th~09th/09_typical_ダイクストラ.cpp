#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<ll,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<P>>;
// const int INF = 1001001001;
const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int main() {
  int N, M; cin >> N >> M;
  Graph G(N);
  rep(i,M) {
    int u, v; cin >> u >> v;
    ll c; cin >> c;
    G[u].push_back(P(c, v));
  }
  vector<ll> dist(N, INF);
  priority_queue<P, vector<P>, greater<P>> que;
  int start = 0;
  dist[start] = 0;
  que.push(P(0, start));
  while(!que.empty()) {
    P pa = que.top(); que.pop();
    ll c = pa.first;
    int v = pa.second;
    if(dist[v] != c) continue;
    for(P next : G[v]) {
      ll next_c = next.first;
      int next_v = next.second;
      if(dist[next_v] <= dist[v] + next_c) continue;
      dist[next_v] = dist[v] + next_c;
      que.push(P(dist[next_v], next_v));
    }
  }
  cout << dist[N-1] << endl;
  return 0;
}