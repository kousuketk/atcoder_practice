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
const ll MOD = 998244353;

ll dp[55][3000];  // i番目まで見た時、総和がjである総数
int main() {
  int N, M, K; cin >> N >> M >> K;
  rep(i,55) rep(j,3000) dp[i][j] = 0;
  dp[0][0] = 1;
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= K; j++) {
      for(int k = 1; k <= M; k++) {
        if(j+k <= K) dp[i][j+k] = (dp[i][j+k] + dp[i-1][j]) % MOD;
      }
    }
  }
  ll ans = 0;
  for(int j = 1; j <= K; j++) {
    ans = (ans + dp[N][j]) % MOD;
  }
  cout << ans << endl;
  return 0;
}