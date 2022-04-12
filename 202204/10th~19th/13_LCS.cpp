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

int dp[3010][3010];
int main() {
  string s, t; cin >> s >> t;
  int s_siz = s.size();
  int t_siz = t.size();
  rep(i,s_siz) {
    rep(j,t_siz) {
      if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
      else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
    }
  }
  int len = dp[s_siz][t_siz];
  string ans = "";
  int i = s_siz, j = t_siz;
  while(len > 0) {
    if(dp[i][j] == dp[i-1][j]) i--;  // (i-1, j) → (i, j)と更新されていた時
    else if(dp[i][j] == dp[i][j-1]) j--;  // (i, j-1) → (i, j)と更新されていた時
    else ans += s[i-1], i--, j--, len--;  // 更新された時
  }
  reverse(ALL(ans));
  cout << ans << endl;
  return 0;
}