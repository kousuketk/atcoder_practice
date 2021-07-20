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

ll dp[70][2];

int main() {
  int N; cin >> N;
  vector<string> vec(N);
  rep(i,N) cin >> vec[i];
  // 初期条件
  dp[0][0] = 1;
  dp[0][1] = 1;
  for(int i = 0; i < N; i++) {
    if(vec[i] == "AND") {
      dp[i+1][0] = dp[i][1] + dp[i][0]*2;
      dp[i+1][1] = dp[i][1];
    } else {
      dp[i+1][0] = dp[i][0];
      dp[i+1][1] = dp[i][1]*2 + dp[i][0];
    }
  }
  cout << dp[N][1] << endl;
}