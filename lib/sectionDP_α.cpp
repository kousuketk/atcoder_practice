#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const ll INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int N;
vector<ll> vec;
ll dp[3100][3100]; // 余裕のあるdpを取る、たまにreする. 今回だとdp[3000][3000]はre. 実行時にそれ以外のdpをたどることもあるらしい.

ll rec(int l, int r, int turn) {
  if(dp[l][r] != -1) return dp[l][r];
  if(l > r) return 0;

  ll res = 0;
  if(turn == 1) {
    res = -INF;
    // 先頭, 末尾を取り除いて最大化
    res = max(rec(l+1, r, turn*(-1)) + vec[l], rec(l, r-1, turn*(-1)) + vec[r]);
  } else {
    res = INF;
    // 先頭, 末尾を取り除いて最小化
    res = min(rec(l+1, r, turn*(-1)) - vec[l], rec(l, r-1, turn*(-1)) - vec[r]);
  }
  return dp[l][r] = res;
}

int main() {
  cin >> N;
  vec.resize(N);
  rep(i,N) {
    cin >> vec[i];
  }
  rep(i,3000) rep(j,3000) dp[i][j] = -1;
  cout << rec(0, N-1, 1);
  return 0;
}

// ↓だるま問題のac(https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611&lang=ja)
// int dp[310][310];  // l, rにおいて取り除ける最大個数
// // l, rにおいて、取り除ける最大の個数を返す
// int solve(int l, int r, vector<int>& vec) {
//   if(dp[l][r] != -1) return dp[l][r];
//   if(r-l == 1 && abs(vec[r]-vec[l]) <= 1) return dp[l][r] = 2;  // 2つ取り除ける
//   if(r-l <= 1) return dp[l][r] = 0; // 取り除けない
//   // その間が全て取り除ける時
//   int res = 0;
//   if(abs(vec[r]-vec[l]) <= 1 && solve(l+1, r-1, vec) == r-l-1) {  // (r-1)-(l+1)+1
//     res = max(res, r-l+1);
//   }
//   // 全探索で取り除いていく
//   for(int i = l; i < r; i++) {
//     res = max(res, solve(l, i, vec) + solve(i+1, r, vec));  // i=lから探索していかないと(i=l+1とかにしちゃうのはだめ)、最初の要素を単独で取り除いたりできない
//   }
//   return dp[l][r] = res;
// }

// int main() {
//   while(true) {
//     int N; cin >> N;
//     if(N == 0) break;
//     vector<int> vec(N);
//     rep(i,N) cin >> vec[i];
//     rep(i,310) rep(j,310) dp[i][j] = -1;
//     int ans = solve(0, N-1, vec);
//     cout << ans << endl;
//   }
// }