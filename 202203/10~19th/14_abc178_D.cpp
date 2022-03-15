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

ll dp[2010];
int main() {
  int N; cin >> N;
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = 0;
  dp[3] = 1;
  for(int i = 4; i <= N; i++) {
    dp[i] = (dp[i-1] + dp[i-3]) % MOD;
  }
  cout << dp[N] << endl;
  return 0;
}