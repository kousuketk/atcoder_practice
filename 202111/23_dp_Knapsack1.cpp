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

ll dp[110][100100];
int main() {
  int N, W; cin >> N >> W;
  rep(i,N) {
    int w, v; cin >> w >> v;
    rep(j,W+1) {
      if(j > 0) dp[i+1][j] = max(dp[i][j], dp[i+1][j-1]);
      if(j-w >= 0) dp[i+1][j] = max(dp[i+1][j], dp[i][j-w] + v);
    }
  }
  ll ans = 0;
  rep(j,W+1) ans = max(ans, dp[N][j]);
  cout << ans << endl;
}