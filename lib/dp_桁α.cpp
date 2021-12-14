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

int dp[11][2][11];  // i桁目まで決めた時、1がj回出現する数がいくつあるか
int main() {
  string N; cin >> N;
  int n = N.size();
  dp[0][0][0] = 1;
  rep(i,n) {
    // smaller →　smaller
    rep(j,10) {
      dp[i+1][1][j] += dp[i][1][j] * 9;  // i+1桁目が1以外
      dp[i+1][1][j+1] += dp[i][1][j];  // i+1桁目が1
      int ni = (N[i] - '0');
      // not smaller → smaller
      if(ni > 1) {
        dp[i+1][1][j] += dp[i][0][j] * (ni - 1);  // i+1桁目が1以外
        dp[i+1][1][j+1] += dp[i][0][j];  // i+1桁目が1
      } else if(ni == 1) {
        dp[i+1][1][j] += dp[i][0][j];  // i+1桁目が0
      }
      // not smaller → not smaller
      if(ni == 1) dp[i+1][0][j+1] = dp[i][0][j];
      else dp[i+1][0][j] = dp[i][0][j];
    }
  }
  ll ans = 0;
  rep(j,10) ans += (dp[n][0][j] + dp[n][1][j])*j;  // 1がj回出現しているものを足していく
  cout << ans << endl;
}

// 問題：https://atcoder.jp/contests/abc029/tasks/abc029_d
// 解説：https://algo-logic.info/digit-dp/