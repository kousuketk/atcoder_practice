#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> vec(M);
  vector<int> dp(N);
  dp[0] = 1;
  dp[1] = 1;
  for(int i = 0; i < M; i++) {
    int a;
    cin >> a;
    if(a == 1) dp[1] = 0;
    vec[i] = a;
  }
  if(M == 0) {
    for(int i = 2; i < N+1; i++) {
      dp[i] = (dp[i-1]+dp[i-2]) % 1000000007;
    }
    cout << dp[N] << endl;
    return 0;
  }

  for(int i = 2; i < N+1; i++) {
    auto result = find(vec.begin(), vec.end(), i);
    if(result != vec.end()) {
      dp[i] = -1;
      continue;
    }
    if(dp[i-1] == -1 && dp[i-2] == -1) {
      cout << 0 << endl;
      return 0;
    } else if(dp[i-1] == -1) {
      dp[i] = dp[i-2];
    } else if(dp[i-2] == -1) {
      dp[i] = dp[i-1];
    } else {
      dp[i] = (dp[i-1]+dp[i-2]) % 1000000007;
    }
  }
  cout << dp[N] << endl;
  return 0;
}