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

int main() {
  int N, W; cin >> N >> W;
  vector<int> wei(N);
  vector<int> val(N);
  rep(i,N) cin >> wei[i] >> val[i];
  ll dp[110][100100];
  for(int i = 1; i <= N; i++) {
    for(int w = 0; w <= W; w++) {
      dp[i][w] = dp[i-1][w];
      if(w-wei[i-1] >= 0) {
        dp[i][w] = max(dp[i][w], dp[i-1][w-wei[i-1]] + val[i-1]);
      }
    }
  }
  cout << dp[N][W] << endl;
}