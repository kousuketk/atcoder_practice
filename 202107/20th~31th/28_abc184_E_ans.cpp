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

ll dp[2010][2010];
ll x[2010][2010];
ll y[2010][2010];
ll z[2010][2010];

int main() {
  int H, W; cin >> H >> W;
  vector<string> road(H);
  rep(i,H) cin >> road[i];
  dp[0][0] = 1;
  rep(i,H) rep(j,W) {
    if(i == 0 && j == 0) continue;
    if(road[i][j] == '#') continue;
    if(j > 0) x[i][j] = (x[i][j-1] + dp[i][j-1]) % MOD;
    if(i > 0) y[i][j] = (y[i-1][j] + dp[i-1][j]) % MOD;
    if(i > 0 && j > 0) z[i][j] = (z[i-1][j-1] + dp[i-1][j-1]) % MOD;
    dp[i][j] = (x[i][j] + y[i][j] + z[i][j]) % MOD;
  }
  cout << dp[H-1][W-1] << endl;
}