#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int N;
vector<ll> vec;
ll dp[3010][3010];
// flag 1:太郎君, -1:次郎君
ll dfs(int l, int r, int flag) {
  if(dp[l][r] != -1) return dp[l][r];
  if(l == r) {
    if(flag == 1) return dp[l][r] = vec[l];
    if(flag == -1) return dp[l][r] = -vec[l];
  }
  ll res;
  if(flag == 1) {
    res = -INF;
    res = max(res, dfs(l+1, r, flag*(-1)) + vec[l]);  // 先頭要素
    res = max(res, dfs(l, r-1, flag*(-1)) + vec[r]);  // 末尾要素
  } else {
    res = INF;
    res = min(res, dfs(l+1, r, flag*(-1)) - vec[l]);
    res = min(res, dfs(l, r-1, flag*(-1)) - vec[r]);
  }
  return dp[l][r] = res;
}

int main() {
  cin >> N;
  vec.resize(N);
  rep(i,N) cin >> vec[i];
  rep(i,3010) rep(j,3010) dp[i][j] = -1;
  ll ans = dfs(0, N-1, 1);
  cout << ans << endl;
  return 0;
}