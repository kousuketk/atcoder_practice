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

int dp[310][310];  // l, rにおいて取り除ける最大個数
// l, rにおいて、取り除ける最大の個数を返す
int solve(int l, int r, vector<int>& vec) {
  if(dp[l][r] != -1) return dp[l][r];
  if(r-l == 1 && abs(vec[r]-vec[l]) <= 1) return dp[l][r] = 2;  // 2つ取り除ける
  if(r-l <= 1) return dp[l][r] = 0; // 取り除けない
  // その間が全て取り除ける時
  int res = 0;
  if(abs(vec[r]-vec[l]) <= 1 && solve(l+1, r-1, vec) == r-l-1) {  // (r-1)-(l+1)+1
    res = max(res, r-l+1);
  }
  // 全探索で取り除いていく
  for(int i = l; i < r; i++) {
    res = max(res, solve(l, i, vec) + solve(i+1, r, vec));  // i=lから探索していかないと(i=l+1とかにしちゃうのはだめ)、最初の要素を単独で取り除いたりできない
  }
  return dp[l][r] = res;
}

int main() {
  while(true) {
    int N; cin >> N;
    if(N == 0) break;
    vector<int> vec(N);
    rep(i,N) cin >> vec[i];
    rep(i,310) rep(j,310) dp[i][j] = -1;
    int ans = solve(0, N-1, vec);
    cout << ans << endl;
  }
}