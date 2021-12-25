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

ll dp[100100][10];
int main() {
  int N; cin >> N;
  string S; cin >> S;
  dp[0][0] = 1;
  rep(i,N) {
    rep(j,8) dp[i+1][j] = dp[i][j];
    if(S[i] == 'a') dp[i+1][1] = (dp[i+1][1] + dp[i][0]) % MOD;
    else if(S[i] == 't') dp[i+1][2] = (dp[i+1][2] + dp[i][1]) % MOD;
    else if(S[i] == 'c') dp[i+1][3] = (dp[i+1][3] + dp[i][2]) % MOD;
    else if(S[i] == 'o') dp[i+1][4] = (dp[i+1][4] + dp[i][3]) % MOD;
    else if(S[i] == 'd') dp[i+1][5] = (dp[i+1][5] + dp[i][4]) % MOD;
    else if(S[i] == 'e') dp[i+1][6] = (dp[i+1][6] + dp[i][5]) % MOD;
    else if(S[i] == 'r') dp[i+1][7] = (dp[i+1][7] + dp[i][6]) % MOD;
  }
  ll ans = dp[N][7];
  cout << ans << endl;
}