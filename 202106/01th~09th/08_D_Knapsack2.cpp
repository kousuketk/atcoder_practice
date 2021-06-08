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

int main() {
  int N, W; cin >> N >> W;
  vector<int> wei(N);
  vector<int> val(N);
  rep(i,N) cin >> wei[i] >> val[i];
  ll dp[110][1000000];
  // 価値vにできないものはINF
  rep(i,N+1)rep(v,1000000) dp[i][v] = INF;
  dp[0][0] = 0;
  for(int i = 1; i <= N; i++) {
    for(int v = 0; v <= 1000000; v++) {
      if(dp[i-1][v] != INF) dp[i][v] = dp[i-1][v];
      if(v-val[i-1] >= 0 && dp[i-1][v-val[i-1]] != INF) {
        dp[i][v] = min(dp[i][v], dp[i-1][v-val[i-1]] + wei[i-1]);
        // min取らなくてもいける気がする
      }
    }
  }
  int ans = 0;
  rep(v,1000000) {
    if(dp[N][v] <= W) {
      ans = max(ans, v);
    }
  }
  cout << ans << endl;
}