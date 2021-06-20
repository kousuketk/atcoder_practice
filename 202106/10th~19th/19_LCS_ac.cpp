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
  for(int i = 1; i <= s.size(); i++) {
    for(int j = 1; j <= t.size(); j++) {
      if(s[i-1] == t[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
      else dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
    }
  }
  string res = "";
  int i = (int)s.size(), j = (int)t.size();
  while(i > 0 && j > 0) {
    if(dp[i][j] == dp[i-1][j]) {
      i--;
    } else if(dp[i][j] == dp[i][j-1]) {
      j--;
    } else {
      res = s[i-1] + res;
      i--, j--;
    }
  }
  cout << res << endl;
}