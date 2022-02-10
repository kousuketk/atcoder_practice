#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
// const int INF = 1001001001;
const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

ll dp[110][110];
int main() {
  int V, E; cin >> V >> E;
  rep(i,110) rep(j,110) if(i != j) dp[i][j] = INF;
  rep(i,E) {
    int s, t; cin >> s >> t;
    ll cost; cin >> cost;
    dp[s][t] = cost;
  }
  bool flag = false;
  rep(k,V) {
    rep(i,V) {
      rep(j,V) {
        if(dp[i][k] == INF || dp[k][j] == INF) continue;  // これをしないと、行けない道がある時(INF)に、負の道があるとその道を経由してINF-(負の道)で行けない道が最短経路になってしまう.
        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
      }
      if(dp[i][i] < 0) flag = true;
    }
  }
  if(flag) {
    cout << "NEGATIVE CYCLE" << endl;
  } else {
    rep(i,V) {
      rep(j,V) {
        if(dp[i][j] == INF) cout << "INF";
        else cout << dp[i][j];
        if(j != V-1) cout << " ";
      }
      cout << endl;
    }
  }
}

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja