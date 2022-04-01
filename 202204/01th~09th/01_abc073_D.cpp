#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const ll INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

// ワーシャルフロイドで前計算して、順列の全探索で最短距離を出す
ll cost[210][210];  //i→jの最短コスト
int main() {
  int N, M, R; cin >> N >> M >> R;
  vector<int> vec(R);
  rep(i,R) cin >> vec[i], vec[i]--;
  rep(i,210) rep(j,210) {
    if(i == j) cost[i][j] = 0;
    else cost[i][j] = INF;
  }
  rep(i,M) {
    int a, b; cin >> a >> b;
    ll c; cin >> c;
    a--, b--;
    cost[a][b] = c;
    cost[b][a] = c;
  }
  rep(k,N) {
    rep(i,N) {
      rep(j,N) {
        cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
      }
    }
  }
  // 順列の全探索で最短距離を出す
  ll ans = INF;
  sort(ALL(vec));
  do {
    ll tmp = 0;
    rep(i,R-1) {
      int from = vec[i];
      int to = vec[i+1];
      tmp += cost[from][to];
    }
    ans = min(ans, tmp);
  } while(next_permutation(ALL(vec)));
  cout << ans << endl;
  return 0;
}