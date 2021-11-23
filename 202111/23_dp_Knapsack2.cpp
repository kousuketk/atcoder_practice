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

ll dp[110][100110]; // dp[i][j]：i番目までで、価値jの最小の重さの総和
int main() {
  int N, W; cin >> N >> W;
  rep(i,N+1) rep(j,100110) dp[i][j] = INF;
  rep(i,N+1) dp[i][0] = 0;
  rep(i,N) {
    ll w, v; cin >> w >> v;
    rep(j,100110) {
      dp[i+1][j] = dp[i][j];
      if(j-v >= 0) dp[i+1][j] = min(dp[i+1][j], dp[i][j-v]+w);
    }
  }
  int ans = 0;
  rep(j,100110) {
    if(dp[N][j] <= W) ans = j;
  }
  cout << ans << endl;
}