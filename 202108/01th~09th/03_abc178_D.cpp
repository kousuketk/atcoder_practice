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

ll dp[2020];

int main() {
  int N; cin >> N;
  if(N <= 2) {
    cout << 0 << endl;
    return 0;
  }
  dp[0] = 1;
  rep(i,N+1) {
    if(i == 0) continue;
    rep(j,i-2) {
      dp[i] = (dp[i] + dp[j]) % MOD;
    }
  }
  cout << dp[N] << endl;
}