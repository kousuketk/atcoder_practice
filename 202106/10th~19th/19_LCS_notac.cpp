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
  string s, t;
  cin >> s >> t;
  int dp[3100][3100];
  for(int i = 1; i <= (int)s.size(); i++) {
    for(int j = 1; j <= (int)t.size(); j++) {
      if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  // 復元の仕方が間違っている
  string ans = "";
  int p = 0;
  for(int i = 0; i < (int)s.size(); i++) {
    for(int j = 0; j < (int)t.size(); j++) {
      if(dp[i+1][j+1] > p) {
        ans += s[i];
        p++;
      }
    }
  }
  cout << ans << endl;
}