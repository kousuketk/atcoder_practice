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

ll dist[105][105];
int main() {
  int N, M; cin >> N >> M;
  rep(i,105) rep(j,105) {
    if(i == j) dist[i][j] = 0;
    else dist[i][j] = INF;
  }
  rep(i,M) {
    int u, v; cin >> u >> v;
    ll c; cin >> c;
    dist[u][v] = c;
  }
  rep(k,N) {
    rep(i,N) {
      rep(j,N) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  ll ans = 0;
  rep(i,N) rep(j,N) ans += dist[i][j];
  cout << ans << endl;
  return 0;
}