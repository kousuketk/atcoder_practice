#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

ll dp[100100][2]; // i番目までの良い式の値, j=0:最後が+, j=1:最後が-

int main() {
  int N; cin >> N;
  vector<ll> vec(N);
  rep(i,N) cin >> vec[i];
  dp[0][0] = vec[0];
  for(int i = 1; i < N; i++) {
    if(i == 1) {
      dp[i][0] = (dp[i-1][0]+vec[i]) % MOD;
    } else {
      // プラスの時
      dp[i][0] = (((dp[i-1][0]+vec[i]) % MOD) + ((dp[i-1][1]+vec[i]) % MOD)) % MOD;
    }
    // マイナスの時
    dp[i][1] = (dp[i-1][0] - vec[i]) % MOD;
    // if(dp[i][1] < 0) dp[i][1] += MOD;
  }
  // dp[N][0], dp[N][1]
  cout << (dp[N-1][0] + dp[N-1][1]) % MOD << endl;
}