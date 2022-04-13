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

// 個数制限付き部分和
int dp[505][10005];  // i番目まで見た時、jにするのに必要なi番目の最小個数
int main() {
  int N, M; cin >> N >> M;
  vector<P> vec(N);
  rep(i,N) cin >> vec[i].first >> vec[i].second;
  rep(i,505) rep(j,10005) dp[i][j] = INF;
  dp[0][0] = 0;
  rep(i,N) {
    rep(j,M+1) {
      int a = vec[i].first;
      int b = vec[i].second;
      if(dp[i][j] != INF) dp[i+1][j] = 0;
      if(j-a>=0 && dp[i+1][j-a] < b) dp[i+1][j] = min(dp[i+1][j], dp[i+1][j-a]+1);  // i番目の数字で見ていく
    }
  }
  int cnt = dp[N][M];
  if(cnt == INF) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}