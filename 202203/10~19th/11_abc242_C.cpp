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

ll dp[1000010][11];
int main() {
  int N; cin >> N;
  for(int j = 1; j <= 9; j++) dp[0][j] = 1;
  for(int i = 1; i < N; i++) {
    for(int j = 1; j <= 9; j++) {
      dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
      if(j == 0) dp[i][j] = (dp[i][j] + dp[i-1][1]) % MOD;
      else if(j == 9) dp[i][j] = (dp[i][j] + dp[i-1][8]) % MOD;
      else dp[i][j] = ((dp[i][j] + dp[i-1][j+1]) + dp[i-1][j-1]) % MOD;
    }
  }
  ll ans = 0;
  for(int j = 1; j <= 9; j++) ans = (ans + dp[N-1][j]) % MOD;
  cout << ans << endl;
  return 0;
}