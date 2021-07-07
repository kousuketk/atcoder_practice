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

ll dp[410][410][410];

int main() {
  int N, M; cin >> N >> M;
  // 初期化
  rep(k,410) {
    rep(i,410) {
      rep(j,410) {
        if(i == j) dp[k][i][j] = 0;
        else dp[k][i][j] = INF;
      }
    }
  }
  // データを入れる
  rep(i,M) {
    int a, b, cost; cin >> a >> b >> cost;
    rep(k,410) {
      dp[k][a-1][b-1] = cost;
    }
  }
  // dp計算
  rep(k,N) {
    rep(i,N) {
      rep(j,N) {
        //結果をk+1に格納
        dp[k+1][i][j] = min(dp[k][i][j], dp[k][i][k] + dp[k][k][j]);
      }
    }
  }
  // 0, INF以外のものを合計する
  ll ans = 0;
  rep(k,N) {
    rep(i,N) {
      rep(j,N) {
        if(dp[k+1][i][j] == INF) continue;
        ans += dp[k+1][i][j];
      }
    }
  }
  cout << ans << endl;
}