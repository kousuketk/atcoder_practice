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

double dp[3010][3010];

int main() {
  int N; cin >> N;
  // dp[i][j] i番目までで、表の個数がj個である確率
  vector<double> vec(N);
  rep(i,N) cin >> vec[i];
  dp[0][1] = vec[0];
  dp[0][0] = 1 - vec[0];
  for(int i = 1; i < N; i++) {
    for(int j = 0; j <= i+1; j++) {
      // vec[i]が表のとき, 裏のときで更新していく
      if(j == 0) {
        // j==0のときは全部裏
        dp[i][j] = dp[i-1][j]*(1-vec[i]);
      } else if(j == i+1) {
        // j==i+1のときは全部表
        dp[i][j] = dp[i-1][j-1]*vec[i];
      } else {
        dp[i][j] = dp[i-1][j-1]*vec[i] + dp[i-1][j]*(1-vec[i]);
      }
    }
  }
  // 答えは、dp[N-1][j]について、(N+1)/2~Nまでのjをたどっていく
  double ans = 0;
  for(int j = (N+1)/2; j <= N; j++) {
    ans += dp[N-1][j];
  }
  cout << fixed << setprecision(10) << ans << endl;
}