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

int dp[3010][3010];  // (i,j)まで見た時の最大マッチ数
int main() {
  string s, t; cin >> s >> t;
  int size_s = s.size();
  int size_t = t.size();
  rep(i,size_s) {
    rep(j,size_t) {
      if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
      else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
    }
  }
  // 復元
  int len = dp[size_s][size_t];
  string ans = "";
  int i = size_s-1;
  int j = size_t-1;
  while(len > 0) {
    if(s[i] == t[j]) {
      ans = s[i] + ans;
      i--;
      j--;
      len--;
    } else if(dp[i+1][j+1] == dp[i][j+1]) {
      i--;
    } else {
      j--;
    }
  }
  // cout << len << endl;
  cout << ans << endl;
}