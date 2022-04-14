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

int dp[310][310];  // 区間[l,r]において、取り除くことのできる最大個数
int rec(int l, int r, vector<int> &vec) {
  if(dp[l][r] != -1) return dp[l][r];
  if(l >= r) return 0;
  if(l+1 == r) {
    if(abs(vec[l]-vec[r]) <= 1) return 2;
    else return 0;
  }
  int res = 0;
  // 全部取り除ける時
  if(abs(vec[l]-vec[r]) <= 1 && rec(l+1, r-1, vec) == (r-1)-(l+1)+1) res = max(res, r-l+1);
  // 1つずつ見ていく
  for(int i = l; i < r; i++) {
    res = max(res, rec(l, i, vec) + rec(i+1, r, vec));
  }
  return dp[l][r] = res;
}

int main() {
  vector<int> ans;
  while(true) {
    int N; cin >> N;
    if(N == 0) break;
    rep(i,310) rep(j,310) dp[i][j] = -1;
    vector<int> vec(N);
    rep(i,N) cin >> vec[i];
    int val = rec(0, N-1, vec);
    ans.push_back(val);
  }
  for(int val : ans) cout << val << endl;
  return 0;
}