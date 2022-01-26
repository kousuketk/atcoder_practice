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

ll dp[17];

int main() {
  string s; cin >> s;
  int N = s.size();
  dp[0] = 0;
  rep(i,16) {
    dp[i+1] = pow(10, i) + dp[i];
  }
  bool flag = false;
  ll ans = 0;
  int cnt = 0;
  rep(i,N) {
    if(!flag) {
      if(s[i] > '1') {
        // 110000~
        if(cnt > 0) {
          ll base = pow(10, N-i) - 1;
          ans += (stoll(s) - base)*cnt;  // 21
          ans += dp[N-i]*(cnt+1);  // 21→22
          // cout << dp[N-i]*(cnt+1) - dp[N-i-1] << endl;
        } else {
          ans += dp[N-i];
        }
        flag = true;
      } else if(s[i] == '0') {
        ll base = pow(10, N-i) - 1;
        ans += (stoll(s) - base)*cnt;
        flag = true;
      } else { // 1
        if(i == 0) {
          cnt++;
          continue;
        }
        if(i == N-1) ans += cnt + cnt+1 + dp[N-i];
        else ans += pow(10, N-i-1);
        cnt++;
      }
    } else {
      ans += dp[N-i];
    }
  }
  cout << ans << endl;
}