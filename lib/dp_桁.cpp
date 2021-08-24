include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = n; i >= 0; --i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int MOD = 1e9 + 7;
int D;
string N;
ll dp[10005][2][105];

int main() {
  cin >> D >> N;
  int n = N.size();
  dp[0][0][0] = 1;
  rep(i, n) {
    rep(j, D) {
      // i桁目まででNより小さいならi+1桁目は何でも良い
      rep(k, 10) {
        dp[i + 1][1][(j + k) % D] += dp[i][1][j];
        dp[i + 1][1][(j + k) % D] %= MOD;
      }
      int ni = (N[i] - '0');
      // i桁目までNと同じで、i+1桁目はNより小さい数の時
      rep(k, ni) {
        dp[i + 1][1][(j + k) % D] += dp[i][0][j];
        dp[i + 1][1][(j + k) % D] %= MOD;
      }
      //  i桁目までNと同じで、i+1桁目もNと同じ数の時
      dp[i + 1][0][(j + ni) % D] = dp[i][0][j];
    }
  }
  cout << dp[n][0][0] + dp[n][1][0] - 1 << endl;
  return 0;
}

// https://algo-logic.info/digit-dp/