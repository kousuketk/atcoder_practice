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

int N;
vector<ll> vec, S;
ll dp[405][405];
ll rec(int l, int r) {
  if(dp[l][r] != INF) return dp[l][r];
  if(r - l == 1) return 0;
  if(r - l == 2) return dp[l][r] = vec[l]+vec[r-1];
  ll res = INF;
  // 全ての頂点を見ていく
  for(int i = l+1; i < r; i++) {
    res = min(res, rec(l, i) + (S[i]-S[l]) + rec(i, r) + (S[r]-S[i]));
  }
  return dp[l][r] = res;
}

// 累積和とって区間DP
int main() {
  cin >> N;
  vec.resize(N);
  S.resize(N+1);
  rep(i,N) cin >> vec[i];
  rep(i,N) S[i+1] = S[i]+vec[i];
  rep(i,405) rep(j,405) dp[i][j] = INF;
  ll ans = rec(0, N);
  cout << ans << endl;
}