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

ll dp[10010][2][110];
int main() {
  int D; cin >> D;
  string N; cin >> N;
  int n = N.size();
  dp[0][0][0] = 1;
  rep(i,n) {
    rep(j,D) {
      rep(k,10) {  // i桁目でsmallerならi+1桁目もsmaller
        dp[i+1][1][(j+k) % D] += dp[i][1][j];
        dp[i+1][1][(j+k) % D] %= MOD;
      }
      int ni = (N[i] - '0');
      rep(k,ni) {  // i桁目でsmallerでなく(Nと同じ)、i+1桁目からsmaller
        dp[i+1][1][(j+k) % D] += dp[i][0][j];
        dp[i+1][1][(j+k) % D] %= MOD;
      }
      dp[i+1][0][(j+ni) % D] = dp[i][0][j];  // i桁目もsmallerでなく(Nと同じ)、i+1桁目もsmallerでない(Nと同じ)
    }
  }
  ll ans = dp[n][0][0] + dp[n][1][0] - 1;
  cout << ans << endl;
}