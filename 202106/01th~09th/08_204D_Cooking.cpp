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
  int N;
  cin >> N;
  vector<int> vec(N);
  int sum = 0;
  rep(i,N) {
    int a; cin >> a;
    vec[i] = a;
    sum += a;
  }
  bool dp[110][100100];
  dp[0][0] = true;
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= sum; j++) {
      dp[i][j] = dp[i-1][j];
      if(j >= vec[i-1] && dp[i-1][j-vec[i-1]]) {
        dp[i][j] = true;
      }
    }
  }
  int ans = INF;
  for(int j = 0; j <= sum; j++) {
    int another = INF;
    if(dp[N][j]) {
      another = sum - j;
    }
    int max_time = max(j, another);
    ans = min(ans, max_time);
  }
  cout << ans << endl;
}