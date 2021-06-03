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
  int N, A, K;
  cin >> N >> A >> K;
  vector<int> a(N);
  rep(i,N) cin >> a[i];
  int dp[110][10100];
  rep(i,110)rep(j,10100) dp[i][j] = INF;
  dp[0][0] = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= A; j++) {
      if(j >= a[i-1]) {
        dp[i][j] = min(dp[i-1][j-a[i-1]]+1, dp[i-1][j]);
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  if(dp[N][A] <= K) cout << "YES" << endl;
  else cout << "NO" << endl;
}