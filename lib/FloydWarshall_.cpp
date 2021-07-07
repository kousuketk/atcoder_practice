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

ll dp[110][110];

int main() {
  int N, M; cin >> N >> M;
  rep(i,110) {
    rep(j,110) {
      if(i == j) dp[i][j] = 0;
      else dp[i][j] = INF;
    }
  }
  rep(i,M) {
    int a, b, cost; cin >> a >> b >> cost;
    dp[a][b] = cost;
  }
  for(int k = 0; k < N; k++) {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        if(i == j && dp[i][j] < 0) {
          cout << "NEGATIVE CYCLE" << endl;
          return 0;
        }
      }
    }
  }
  rep(i,N) {
    rep(j,N) {
      if(dp[i][j] == INF) cout << "INF ";
      else cout << dp[i][j] << " ";
    }
    cout << endl;
  }
}
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja