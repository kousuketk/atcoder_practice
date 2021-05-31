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
  int N, K;
  cin >> N >> K;
  vector<int> vec(N);
  rep(i,N) cin >> vec.at(i);
  vector<int> dp(N, INF);
  dp[0] = 0;
  dp[1] = abs(vec[0]-vec[1]);
  for(int i = 1; i < N-1; i++) {
    for(int j = 0; j <= K; j++) {
      if(i-j < 0) continue;
      dp[i+1] = min(dp[i+1], dp[i-j]+abs(vec[i-j]-vec[i+1]));
    }
  }
  cout << dp[N-1] << endl;
}