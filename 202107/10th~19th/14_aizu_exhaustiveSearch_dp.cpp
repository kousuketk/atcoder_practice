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
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

bool dp[30][2010];

int main() {
  int N, M;
  cin >> N;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  dp[0][0] = true;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= 2000; j++) {
      if(dp[i][j]) {
        dp[i+1][j] = true;
      } else {
        // vec[i]に対して見ていく. dp[i+1][j] = dp[i][j-vec[i]]
        if(j-vec[i] >= 0) dp[i+1][j] = dp[i][j-vec[i]];
      }
    }
  }
  // M回のクエリに対して、dp[N][j]を見ていく
  cin >> M;
  rep(i,M) {
    int tmp;
    cin >> tmp;
    if(dp[N][tmp]) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}