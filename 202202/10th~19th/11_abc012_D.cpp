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
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

// ワーシャルフロイドで全頂点対最短経路を出して、i番目の街(dp[i][j])から出る最大値をそれぞれ求め、その最小値を求める
int main() {
  int N, M; cin >> N >> M;
  vector<vector<int>> dp(N, vector<int>(N));
  rep(i,N) rep(j,N) if(i != j) dp[i][j] = INF;
  rep(i,M) {
    int a, b, t; cin >> a >> b >> t;
    a--, b--;
    dp[a][b] = t;
    dp[b][a] = t;
  }
  rep(k,N) {
    rep(i,N) {
      rep(j,N) {
        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
      }
    }
  }
  int ans = INF;
  rep(i,N) {
    int tmp = 0;
    rep(j,N) {
      tmp = max(tmp, dp[i][j]);
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}

// →O(V^3)