#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

// 1~Nまでの整数をK個に分割する
int main() {
  int N, K; cin >> N >> K;
  int dp[1010][100010];  // NのK分割の総数
  for(int i = 0; i <= N; i++) {
    for(int j = 1; j <= K; j++) {
      if(i-j >= 0) {
        dp[i][j] = dp[i][j-1] + dp[i-j][j];
      } else {
        dp[i][j] = dp[i][j-1];
      }
    }
  }
  cout << dp[N][K] << endl;
}