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

ll cost[410][410];
int main() {
  int N, M; cin >> N >> M;
  rep(i,410) rep(j,410) {
    if(i == j) cost[i][j] = 0;
    else cost[i][j] = INF;
  }
  rep(i,M) {
    int a, b; cin >> a >> b;
    ll c; cin >> c;
    a--, b--;
    cost[a][b] = c;
  }
  ll ans = 0;
  for(int k = 0; k < N; k++) {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
        if(cost[i][j] == 0 || cost[i][j] == INF) continue;
        ans += cost[i][j];  // k=0のときはどうせ0だからカウントしなくていい
      }
    }
  }
  cout << ans << endl;
  return 0;
}