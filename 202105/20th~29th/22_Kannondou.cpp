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
  while(true) {
    int N;
    cin >> N;
    if(N == 0) break;
    vector<int> dp(N,0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < N+1; i++) {
      dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    cout << (dp[N]+3649)/3650 << endl;
  }
  return 0;
}