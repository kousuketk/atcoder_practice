#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;

int dp[100100][3];

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  vector<int> C(N);
  rep(i,N) cin >> A[i] >> B[i] >> C[i];
  dp[0][0] = A[0];
  dp[0][1] = B[0];
  dp[0][2] = C[0];
  for(int i = 1; i < N; i++) {
    dp[i][0] = max(dp[i-1][1]+A[i], dp[i-1][2]+A[i]);
    dp[i][1] = max(dp[i-1][0]+B[i], dp[i-1][2]+B[i]);
    dp[i][2] = max(dp[i-1][0]+C[i], dp[i-1][1]+C[i]);
  }
  int a = dp[N-1][0];
  int b = dp[N-1][1];
  int c = dp[N-1][2];
  cout << max({a,b,c}) << endl;
}