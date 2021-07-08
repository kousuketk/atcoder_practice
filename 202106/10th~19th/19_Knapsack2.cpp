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
  int N, W;
  cin >> N >> W;
  vector<int> weight(N);
  vector<int> val(N);
  rep(i,N) {
    cin >> weight[i];
    cin >> val[i];
  }
  ll dp[110][100100];
  rep(i,110)rep(j,100100) dp[i][j] = INF;
  dp[0][0] = 0;
  for(int i = 1; i <= N; i++) {
    for(int v = 0; v < 100100; v++) {
      if(v-val[i-1] >= 0) dp[i][v] = min(dp[i-1][v-val[i-1]]+weight[i-1], dp[i-1][v]);
      else dp[i][v] = dp[i-1][v];
    }
  }
  int ans = 0;
  rep(i,110)rep(j,100100) {
    if(dp[i][j] <= W) {
      ans = max(ans, j);
    }
  }
  cout << ans << endl;
}