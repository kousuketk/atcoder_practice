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

ll dp[1000010][2][2];
int main() {
  ll H, W, K; cin >> H >> W >> K;
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  if(x1 == x2 && y1 == y2) dp[0][1][1] = 1;
  else if(x1 == x2) dp[0][1][0] = 1;
  else if(y1 == y2) dp[0][0][1] = 1;
  else dp[0][0][0] = 1;
  rep(k,K) {
    // Hに対して
    dp[k+1][0][0] = (dp[k+1][0][0] + dp[k][0][0] * (H-2) % MOD) % MOD;
    dp[k+1][0][0] = (dp[k+1][0][0] + dp[k][1][0] * (H-1) % MOD) % MOD;
    dp[k+1][0][1] = (dp[k+1][0][1] + dp[k][1][1] * (H-1) % MOD) % MOD;
    dp[k+1][0][1] = (dp[k+1][0][1] + dp[k][0][1] * (H-2) % MOD) % MOD;
    dp[k+1][1][0] = (dp[k+1][1][0] + dp[k][0][0]) % MOD;
    dp[k+1][1][1] = (dp[k+1][1][1] + dp[k][0][1]) % MOD;
    // Wに対して
    dp[k+1][0][0] = (dp[k+1][0][0] + dp[k][0][0] * (W-2) % MOD) % MOD;
    dp[k+1][0][0] = (dp[k+1][0][0] + dp[k][0][1] * (W-1) % MOD) % MOD;
    dp[k+1][1][0] = (dp[k+1][1][0] + dp[k][1][1] * (W-1) % MOD) % MOD;
    dp[k+1][1][0] = (dp[k+1][1][0] + dp[k][1][0] * (W-2) % MOD) % MOD;
    dp[k+1][0][1] = (dp[k+1][0][1] + dp[k][0][0]) % MOD;
    dp[k+1][1][1] = (dp[k+1][1][1] + dp[k][1][0]) % MOD;
  }
  ll ans = dp[K][1][1];
  cout << ans << endl;
}