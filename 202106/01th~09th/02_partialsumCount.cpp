#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int N, A;
  cin >> N >> A;
  vector<int> a(N);
  rep(i,N) cin >> a[i];
  int dp[110][10100];
  dp[0][0] = 1;
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= A; j++) {
      dp[i][j] = dp[i-1][j];
      if(j >= a[i-1] && dp[i-1][j-a[i-1]]) {
        // cout << i << " " << j << " " << dp[i][j] << " " << dp[i-1][j-a[i-1]] << endl;
        dp[i][j] += dp[i-1][j-a[i-1]];
      }
    }
  }
  cout << dp[N][A] << endl;
}