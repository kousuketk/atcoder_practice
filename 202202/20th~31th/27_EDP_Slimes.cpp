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
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

ll dp[410][410];
int N;
vector<ll> vec;
vector<ll> S;
// 範囲(l,r)で、払うコストの最小値
ll dfs(int l, int r) {
  if(dp[l][r] != -1) return dp[l][r];
  if(r-l == 1) return dp[l][r] = vec[l] + vec[r];
  if(r-l == 0) return dp[l][r] = 0;  // 要素が1つのときは、何もせず。和は累積和で取る
  // どこで区切るかを全探索で見つけていく
  ll res = INF;
  for(int i = l; i < r; i++) {
    res = min(res, dfs(l, i) + (S[i+1] - S[l]) + dfs(i+1, r) + (S[r+1] - S[i+1]));  // 累積和取る
  }
  return dp[l][r] = res;
}

int main() {
  cin >> N;
  vec.resize(N);
  S.resize(N+1);
  rep(i,N) cin >> vec[i];
  rep(i,N) S[i+1] = S[i] + vec[i];
  rep(i,410) rep(j,410) dp[i][j] = -1;
  ll ans = dfs(0, N-1);
  cout << ans << endl;
}