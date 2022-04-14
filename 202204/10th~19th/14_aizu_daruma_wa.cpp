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

int dp[310][310];  // 区間[l, r]において、取り除くことのできる最大個数

int rec(int l, int r, vector<int> &vec) {
  if(dp[l][r] != -1) return dp[l][r];
  if(l >= r) return 0;
  // O(N)で全ての区間を見ていく
  int res = 0;
  for(int i = l; i < r; i++) {
    if(abs(vec[i]-vec[i+1]) <= 1) res = max(res, rec(l, i-1, vec) + rec(i+2, r, vec) + 2);
    else res = max(res, rec(l, i-1, vec) + rec(i+2, r, vec));
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

// 隣をみて再帰していくのではなく、区間を見て再帰していく
// if (abs(w[l] - w[r-1]) <= 1 && rec(l + 1, r - 1) == r - l - 2)