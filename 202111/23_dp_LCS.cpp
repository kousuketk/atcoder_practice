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
  int size_s = s.size();
  int size_t = t.size();
  int cnt = 0;
  rep(i,size_s) {
    rep(j,size_t) {
      dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
      if(s[i] == t[j]) {
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
      }
    }
  }
  int i = size_s;
  int j = size_t;
  string ans;
  while(i > 0 && j > 0) {
    if(dp[i][j] == dp[i-1][j]) i--;
    else if(dp[i][j] == dp[i][j-1]) j--;
    else {
      ans = s[i-1] + ans;
      i--, j--;
    }
  }
  cout << ans << endl;
}