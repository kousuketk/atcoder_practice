#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int, int>;
using Graph = vector<vector<int>>;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  rep(i,N) cin >> vec.at(i);
  vector<int> dp(N, 0);
  dp[0] = 0;
  dp[1] = abs(vec[0]-vec[1]);
  for(int i = 1; i < N-1; i++) {
    dp[i+1] = min(dp[i]+abs(vec[i]-vec[i+1]), dp[i-1]+abs(vec[i-1]-vec[i+1]));
  }
  cout << dp[N-1] << endl;
}