#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll,ll>;
using T = tuple<ll,ll,ll>;
using Graph = vector<vector<ll>>;
const ll INF = 1001001001;
void printVec(vector<ll> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

ll N;
vector<ll> vec;
ll dp[3010][3010];

ll rec(ll l, ll r) {
  if(dp[l][r] != -1) return dp[l][r];
  if(l > r) return 0;

  ll diff = N - (r-l+1);

  ll res = 0;
  if(diff % 2 == 0) {
    res = -INF;
    // 先頭, 末尾を取り除いて最大化
    res = max(res, rec(l+1, r) + vec[l]);
    res = max(res, rec(l, r-1) + vec[r]);
  } else {
    res = INF;
    // 先頭, 末尾を取り除いて最小化
    res = min(res, rec(l+1, r) - vec[l]);
    res = min(res, rec(l, r-1) - vec[r]);
  }
  return dp[l][r] = res;
}

int main() {
  cin >> N;
  // vec.resize(N);
  vec.assign(N, 0);
  rep(i,N) {
    cin >> vec[i];
  }
  rep(i,3000) rep(j,3000) dp[i][j] = -1;
  cout << rec(0, N-1) << endl;
}