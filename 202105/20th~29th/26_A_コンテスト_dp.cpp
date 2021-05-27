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
  cout << "";
  for (auto itr = vec.begin(); itr != vec.end(); itr++) {
    cout << *itr << " "; 
  }
  cout << endl;
}

int dp[110][10100];

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  int max_count = 0;
  rep(i,N) {
    int a;
    cin >> a;
    vec.at(i) = a;
    max_count += a;
  }
  for(int j = 0; j < 10100; j++) {
    dp[0][j] = 0;
  }
  dp[0][0] = 1;
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j < 10100; j++) {
      dp[i][j] = dp[i-1][j];
      if(j-vec[i-1] >= 0 && dp[i-1][j-vec[i-1]] == 1) {
        dp[i][j] = 1;
      }
    }
  }
  int ans = 0;
  for(int j = 0; j <= max_count; j++) {
    cout << dp[N][j] << endl;
    ans += dp[N][j];
  }
  cout << ans << endl;
}