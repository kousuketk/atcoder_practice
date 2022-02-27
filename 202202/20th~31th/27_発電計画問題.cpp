#include <bits/stdc++.h>
using namespace std;
const int INF = 1<<29;
int T;
int g[110][110];
int dp[110];

int main() {
  int T; cin >> T;
  vector<vector<int>> vec(T, vector<int>(T));
  for(int i=0;i<T;i++) for(int j=0;j<T;j++) cin >> vec[i][j];
  for(int t = 1; t <= T+1; t++) {
    for(int i = 0; i < t; i++) {
      for(int j = i+1; j < t; j++) {
        dp[t] = max(dp[t], dp[i]+vec[i][j-1]);
      }
    }
  }
  cout << dp[T+1] << endl;
}