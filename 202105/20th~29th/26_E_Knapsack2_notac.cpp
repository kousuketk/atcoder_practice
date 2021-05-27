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

int dp[110][1000100]; // dp[N][val]
int visited[110][1000100]; // dp[N][val]

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> wei(N);
  vector<int> val(N);
  int max_val = 0;
  rep(i,N) {
    int a, b;
    cin >> a >> b;
    wei[i] = a;
    val[i] = b;
    max_val += b;
  }
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= max_val; j++) {
      dp[i][j] = INF;
    }
  }
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= max_val; j++) {
      if(j == val[i-1]) {
        dp[i][j] = min(dp[i][j], wei[i-1]);
      }
      if(dp[i-1][j] != INF) {
        dp[i][j] = dp[i-1][j];
        dp[i][j+val[i-1]] = dp[i][j] + wei[i-1];
      }
    }
  }
  int ans = 0;
  for(int j = 0; j <= max_val; j++) {
    cout << j << " " << dp[N][j] << endl;
    if(dp[N][j] <= W) ans = max(ans, j);
  }
  cout << ans << endl;
  return 0;
}