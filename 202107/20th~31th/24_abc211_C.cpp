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

ll dp[100100][10];

int main() {
  string s; cin >> s;
  int N = s.size();
  string choku = "chokudai";
  int M = choku.size();
  rep(j,M) {
    rep(i,N) {
      if(j == 0) {
        if(s[i] == choku[j]) dp[i+1][j] = (dp[i][j] + 1) % MOD;
        else dp[i+1][j] = dp[i][j] % MOD;
      } else {
        if(s[i] == choku[j]) dp[i+1][j] = (dp[i][j] + dp[i][j-1]) % MOD; 
        else dp[i+1][j] = dp[i][j] % MOD;
      }
    }
  }
  cout << dp[N][M-1] << endl;
  return 0;
}