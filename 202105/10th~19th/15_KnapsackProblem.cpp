#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
  int N, W;
  cin >> N >> W;
  vector<vector<int>> vec(N, vector<int>(2));
  rep(i,N)rep(j,2) cin >> vec.at(i).at(j);
  vector<int> dp(10000, 0);

  for(int i = 0; i < N; i++) {
    int tmp_val = vec.at(i).at(0);
    int tmp_weight = vec.at(i).at(1);
    for(int j = 0; j < W; j++) {
      dp[W-j+tmp_weight] = max(dp[W-j+tmp_weight], dp[j] + tmp_val);
    }
  }
  cout << dp.at(W-1) << endl;
}