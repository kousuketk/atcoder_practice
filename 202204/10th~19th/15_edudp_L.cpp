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
vector<ll> vec;
ll dp[3005][3005];
ll rec(int l, int r, int i) {
  if(l > r) return 0;  // recでr-1にするときに-1になってしまわないよう、先に判断
  if(dp[l][r] != INF) return dp[l][r];
  ll res;
  if(i % 2 == 0) {
    res = -INF;
    res = max(res, rec(l+1, r, i+1) + vec[l]);
    res = max(res, rec(l, r-1, i+1) + vec[r]);
  } else {
    res = INF;
    res = min(res, rec(l+1, r, i+1) - vec[l]);
    res = min(res, rec(l, r-1, i+1) - vec[r]);
  }
  return dp[l][r] = res;
}

int main() {
  cin >> N;
  vec.resize(N);
  rep(i,N) cin >> vec[i];
  rep(i,3005) rep(j,3005) dp[i][j] = INF;
  ll ans = rec(0, N-1, 0);
  // ll ans = rec(0, 0, 2);
  cout << ans << endl;
  return 0;
}