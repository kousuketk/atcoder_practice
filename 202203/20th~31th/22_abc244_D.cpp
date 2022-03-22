#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 998244353;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

ll dp[2010][2010][2];
int main() {
  int N, M, K, S, T, X; cin >> N >> M >> K >> S >> T >> X;
  S--, T--, X--;
  Graph G(N);
  rep(i,M) {
    int u, v; cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dp[0][S][0] = 1;
  for(int i = 1; i <= K; i++) {
    for(int j = 0; j < N; j++) {  // i-1番目に点jにいて、jからの遷移先を考える
      if(dp[i-1][j][0] == 0 && dp[i-1][j][1] == 0) continue;
      for(int nv : G[j]) {
        if(nv == X) {
          dp[i][nv][0] = (dp[i][nv][0] + dp[i-1][j][1]) % MOD;
          dp[i][nv][1] = (dp[i][nv][1] + dp[i-1][j][0]) % MOD;
        } else {
          dp[i][nv][0] = (dp[i][nv][0] + dp[i-1][j][0]) % MOD;
          dp[i][nv][1] = (dp[i][nv][1] + dp[i-1][j][1]) % MOD;
        }
      }
    }
  }
  ll ans = dp[K][T][0];
  cout << ans << endl;
}